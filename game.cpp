#include "game.h"
#include "webcamManager.h"
#include "textureManager.h"
#include "night.h"
#include "gameOver.h"
#include <iostream>

int x, y;
Uint32 anterior;
Night* night;
GameOver* gameOver;

void Game::init(bool fullscream){
    int flags = 0;
    menu = 0;
    anterior = 0;
    x = 0;
    y = 0;

    if(fullscream){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    webcam = new WebcamManager();

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 && webcam->init() == 0){
        std::cout << "Inicializando...\n";

        window = SDL_CreateWindow("Cinco Noites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 848, 477, SDL_WINDOW_SHOWN);

        if(window){
            cout << "Abrindo janela...\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            cout << "Renderizando janela...\n";
        }

        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)){
            cout << "Iniciando mixer...\n";
        }

        night = new Night(renderer);
        night->start();

        gameOver = nullptr;

        running = true;
    } else{
        running = false;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == anterior){
            continue;
        }

        switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                //cout << "Mouse down" << endl;
                if(menu == 0){
                    if(!night->isAttacking() && !night->isMoving() && !night->cameraIsMoving){
                        if(event.button.button == SDL_BUTTON_LEFT){
                            night->detectClick(event.button.x, event.button.y);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONUP:
                //cout << "Mouse up" << endl;
                if(menu == 0){
                    if(!night->isAttacking() && !night->isMoving() && !night->cameraIsMoving){
                        if(event.button.button == SDL_BUTTON_LEFT){
                            night->detectHold(event.button.x, event.button.y);
                        }
                    }
                }
                break;
            case SDL_KEYDOWN:
                //cout << "Key down" << endl;
                if(menu == 0){
                    if(!night->isAttacking() && !night->isMoving() && !night->cameraIsMoving && !night->isClosing() && night->getPos() != 0){
                        if(event.key.keysym.sym == SDLK_SPACE){
                            if(night->cenario->getTexture()->getFramePos() == 0){
                                night->turnLight(true);
                            }
                        }
                    }
                }
                break;
            case SDL_KEYUP:
                if(menu == 0){ 
                    if(!night->isAttacking() && !night->isMoving() && !night->cameraIsMoving && !night->isClosing() && night->getPos() != 0 && night->isLight()){
                        if(event.key.keysym.sym == SDLK_SPACE){
                            night->turnLight(false);
                        }
                    }
                }
                break;
            default:
                break;
        }

        anterior = event.type;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    switch(menu){
        case 0:
            night->render();
            break;
        case 1:
            gameOver->render();
            break;
        default:
            break;
    }
    SDL_RenderPresent(renderer);
}

int Game::update(){
    switch(menu){
        case 0:
            if(night->seconds != 360){
                night->update();
            }

            if(!night->isLosing()){
                menu = 1;
                SDL_RenderClear(renderer);
                night->close();
                gameOver = new GameOver(renderer);
                gameOver->start();
                delete night;
                return 0;
            }

            if(night->isMoving() || night->cameraIsMoving || night->isClosing() || night->isLight() || night->isAttacking()){
                return 0;
            }

            webcam->capture >> webcam->frame;
    
            if(webcam->frame.empty()){
                return -1;
            }

            webcam->detectFace(&x, &y);
    
            if(x >= 0 && y >= 0){

                night->lilBox->setPos(574+x, 166+y);

                switch(night->getPos()){
                    case 0:
                        if(x > 180 && night->cenario->getTexture()->getFramePos() == 0){
                            night->cameraIsMoving = true;
                            night->cameraDir = 1;
                        } else if(x < 100 && night->cenario->getTexture()->getFramePos() == 10){
                            night->cameraIsMoving = true;
                            night->cameraDir = -1;
                        }
                        break;
                    case 1:
                        if(x < 80 && night->cenario->getTexture()->getFramePos() == 0){
                            night->cameraIsMoving = true;
                            night->cameraDir = 1;
                        } else if(x >= 80 && night->cenario->getTexture()->getFramePos() == 13){
                            night->cameraIsMoving = true;
                            night->cameraDir = -1;
                        }
                        break;
                    case 2:
                        if(x < 80 && night->cenario->getTexture()->getFramePos() == 0){
                            night->cameraIsMoving = true;
                            night->cameraDir = 1;
                        } else if(x >= 80 && night->cenario->getTexture()->getFramePos() == 9){
                            night->cameraIsMoving = true;
                            night->cameraDir = -1;
                        }
                        break;
                    default:
                        break;
                }
            }

            break;
        case 1:
            gameOver->update();
            break;
        default:
            break;
    }

    return 0;
}

void Game::close(){
    SDL_DestroyWindow(window);
    switch(menu){
        case 0:
            night->close();
            break;
        case 1:
            gameOver->close();
            break;
        default:
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    delete webcam;
    std::cout << "Fechando o jogo...\n";
}

bool Game::isRunning(){
    return running;
}