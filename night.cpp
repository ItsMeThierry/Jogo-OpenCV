#include "night.h"
#include <iostream>


SDL_Texture *bedroomTex, *bathroomTex, *corridorTex, *guiTex, *fernandoTex, *tapioTex, *manoelTex;
Mix_Music *respiraAud, *saiAud, *comemoraAud; 
bool entering;

Night::Night(){
}

Night::~Night(){
    cout << "Deletando night" << endl;
}

Night::Night(SDL_Renderer *renderer){
    this->renderer = renderer;

    cenario = new Object(848, 480, 0, 0, 11);
    button = new Object(280, 50, 258, 0, 0);
    control = new Object(258, 258, 0, 0, 0);
    lilBox = new Object(16, 16, 258, 50, 0);
    num1 = new Object(24, 33, 538, 0, 7);
    num2 = new Object(24, 33, 538, 0, 7);
    amTxt = new Object(52, 33, 298, 50, 0);
    winTxt = new Object(281, 38, 258, 220, 0);

    fernandoMiguel = new Object(484, 1162, 0, 0, 0);
    tapio = new Object(792, 1229, 0, 0, 0);
    paralisia = new Object(720, 1277, 250, 0, 0);
    
    button->setPos(284, 420);
    control->setPos(570, 162);
    lilBox->setPos(574, 166);
    num1->setPos(20, 20);
    num2->setPos(44, 20);
    amTxt->setPos(86, 20);
    winTxt->setPos(282, 221);

    fernandoMiguel->setSize(242, 581);
    fernandoMiguel->setPos(282, 80);
    tapio->setPos(28, 80);
    paralisia->setPos(80, 0);

    bedroomTex = nullptr;
    bathroomTex = nullptr;
    corridorTex = nullptr;
    guiTex = nullptr;
    fernandoTex = nullptr;
    tapioTex = nullptr;
    manoelTex = nullptr;

    respiraAud = nullptr;
    saiAud = nullptr;
    comemoraAud = nullptr;

    esposito = Enemy();
    popo = Enemy();
    manoel = Enemy();
}

void Night::start(){
    pos = 0;
    closing = false;
    moving = false;
    entering = false;
    attacking = false;
    lDoor = false;
    rDoor = false;
    lLight = false;
    rLight = false;
    win = true;
    cameraDir = 0;
    c = 0;

    start_time = clock();
    seconds = 0;

    num1->getTexture()->changeToFrame(1);
    num2->getTexture()->changeToFrame(2);

    bedroomTex = TextureManager::loadTexture("resources/images/bedroom.png", renderer);
    bathroomTex = TextureManager::loadTexture("resources/images/bathroom.png", renderer);
    corridorTex = TextureManager::loadTexture("resources/images/corridor.png", renderer);
    guiTex = TextureManager::loadTexture("resources/images/GUI.png", renderer);
    fernandoTex = TextureManager::loadTexture("resources/images/fernando_miguel.png", renderer);
    tapioTex = TextureManager::loadTexture("resources/images/tapio.png", renderer);
    manoelTex = TextureManager::loadTexture("resources/images/paralisia_do_sono.png", renderer);

    respiraAud = Mix_LoadMUS("resources/Breath.ogg");
    comemoraAud = Mix_LoadMUS("resources/CROWd_SMALL_CHIL_EC049202.ogg");
    saiAud = Mix_LoadMUS("resources/Carpetrun1b.ogg");
}

void Night::update(){
    if(attacking && !moving){
        if(c == 30){
            win = false;
        }else{
            c++;
        }
    } else{
        clock_t current_time = clock();
        int elapsed_ticks = static_cast<int>(current_time - start_time);
        int elapsed_seconds = elapsed_ticks / CLOCKS_PER_SEC;

        if (elapsed_seconds > seconds){
            seconds = elapsed_seconds;
            //cout << "Tempo decorrido: " << seconds << " segundos" << endl;

            switch(seconds){
                case 15:
                    //esposito.changeLevel(20);
                    popo.changeLevel(20);
                    manoel.changeLevel(10);
                    break;
                case 60:
                    num1->getTexture()->changeToFrame(0);
                    num2->getTexture()->changeToFrame(1);
                    //popo.changeLevel(10);
                    break;
                case 120:
                    num2->getTexture()->changeToFrame(2);
                    //esposito.changeLevel(10);
                    //popo.changeLevel(5);
                    //manoel.changeLevel(10);
                    break;
                case 180:
                    num2->getTexture()->changeToFrame(3);
                    //esposito.changeLevel(15);
                    //popo.changeLevel(15);
                    //manoel.changeLevel(15);
                    break;
                case 240:
                    num2->getTexture()->changeToFrame(4);
                    //esposito.changeLevel(15);
                    //popo.changeLevel(15);
                    //manoel.changeLevel(15);
                    break;
                case 300:
                    num2->getTexture()->changeToFrame(5);
                    //esposito.changeLevel(20);
                    //popo.changeLevel(20);
                    //manoel.changeLevel(20);
                    break;
                case 360:
                    num2->getTexture()->changeToFrame(6);
                    cout << "Ganhou" << endl;
                    Mix_PlayMusic(comemoraAud, 1);
                    return;
                default:
                    break;
            }

            if(popo.getLevel() != 0){
                if(lDoor && popo.getStage() >= 0 && cenario->getTexture()->getFramePos() == 14){
                    cout << "Tapio está retornando" << endl;
                    popo.goBack();
                }
            }

            if(seconds % 5 == 0){
                if(esposito.getLevel() != 0){
                    if(esposito.getStage() == 2 && rDoor && cenario->getTexture()->getFramePos() == 16){
                        cout << "Esposito foi defendido" << endl;
                        Mix_PlayMusic(saiAud, 1);
                        esposito.resetStage();
                    } else if(esposito.tryMove() && !rLight){
                        esposito.move();
                        cout << "Esposito moveu para casa " << esposito.getStage() << endl;

                        if(esposito.getStage() == 3){
                            attacking = true;
                            esposito.attack();
                            c = 0;
                        }
                    }
                }

                if(popo.getLevel() != 0 && popo.tryMove() && !lLight){
                    popo.move();
                    cout << "Tapio está no estágio " << popo.getStage() << endl;

                    if(popo.getStage() == 10){
                        attacking = true;
                        popo.attack();
                        c = 0;
                    }
                }

                if(manoel.getLevel() != 0 && manoel.tryMove()){
                    if(!(manoel.getStage() > 0 && lLight) && !(manoel.getStage() < 0 && rLight)){
                        if(manoel.getStage() == 0){
                            manoel.chooseDir();
                        }

                        if(manoel.getDir() == 1){
                            manoel.move();
                        } else{
                            manoel.goBack();
                        }
                        cout << "Manoel Gomes está no estágio " << manoel.getStage() << endl;

                        if(manoel.getStage() == 3 || manoel.getStage() == -3){
                            if(hide){
                                cout << "Manoel voltou pra toca" << endl;
                                Mix_PlayMusic(saiAud, 1);
                                manoel.resetStage();
                            }else{
                                attacking = true;
                                manoel.attack();
                                c = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if(cameraIsMoving){
        c += cameraDir;
        //cout << "Frame: " << c << endl;
        cenario->getTexture()->changeToFrame(c);

        int maxFrames = 0;

        switch(pos){
            case 0:
                maxFrames = 10;
                break;
            case 1:
                maxFrames = 13;
                break;
            case 2:
                maxFrames = 9;
                break;
            default:
                break;
        }

        if(c == maxFrames || c == 0){
            cameraDir = 0;
            cameraIsMoving = false;

            if(pos == 1 || pos == 2){
                if(c == maxFrames){
                    //cout << "Se escondendo" << endl;
                    hide = true;
                } else{
                    //cout << "Saindo da toca" << endl;
                    hide = false;
                }
            }
        }
    }

    if(moving){
        //cout << "Frame: " << c << endl;

        switch(pos){
            case 0:
                if(entering){
                    if(c > 0){
                        cenario->getTexture()->changeToFrame(c--);
                    } else if(c == 0){
                        //cout << "Chegando no quarto" << endl;
                        moving = false;
                        cenario->getTexture()->changeAnim(0);

                        if(cameraDir == 1){
                            cenario->getTexture()->changeToFrame(10);
                            c = 10;
                        } else if(cameraDir == -1){
                            cenario->getTexture()->changeToFrame(0);
                        }

                        cameraDir = 0;
                    }
                } else{
                    if(c < 8){
                        cenario->getTexture()->changeToFrame(c++);
                    } else if(c == 8){
                        entering = true;
                        pos = cenario->getTexture()->getAnim();
                        c = 0;
                        cenario->getTexture()->changeAnim(0);
                    }
                }
                break;
            case 1:
                if(entering){
                    if(c < 13){
                        cenario->getTexture()->changeToFrame(c++);
                    } else if(c == 13){
                        moving = false;
                        c = 0;
                        cenario->getTexture()->changeAnim(1);
                        cenario->getTexture()->changeToFrame(0);
                    }
                } else{
                    if(c > 0){
                        cenario->getTexture()->changeToFrame(c--);
                    } else if(c == 0){
                        cenario->getTexture()->changeAnim(pos);
                        cenario->getTexture()->changeToFrame(8);
                        entering = true;
                        pos = 0;
                        c = 7;
                        cameraDir = -1;
                    }
                }
                break;
            case 2:
                if(entering){
                    if(c < 13){
                        cenario->getTexture()->changeToFrame(c++);
                    } else if(c == 13){
                        moving = false;
                        c = 0;
                        cenario->getTexture()->changeAnim(1);
                        cenario->getTexture()->changeToFrame(0);
                        
                        if(esposito.getStage() == 2){
                            cout << "Toca um sinal" << endl;
                            Mix_PlayMusic(respiraAud, 1);
                        }
                    }
                } else{
                    if(c > 0){
                        cenario->getTexture()->changeToFrame(c--);
                    } else if(c == 0){
                        cenario->getTexture()->changeAnim(pos);
                        cenario->getTexture()->changeToFrame(8);
                        entering = true;
                        pos = 0;
                        c = 7;
                        cameraDir = 1;
                    }
                }
                break;
            default:
                break;
        }
    }

    if(closing){
        switch(pos){
            case 1:
                if(lDoor){
                    if(c < 14){
                        cenario->getTexture()->changeToFrame(c++);
                    } else if(c == 14){
                        cenario->getTexture()->changeToFrame(14);
                    }
                } else{
                    if(c > 0){
                        cenario->getTexture()->changeToFrame(c--);
                    } else if(c == 0){
                        cenario->getTexture()->changeToFrame(0);
                        cenario->getTexture()->changeAnim(1);
                        closing = false;
                    }
                }
                break;
            case 2:
                if(rDoor){
                    if(c < 16){
                        cenario->getTexture()->changeToFrame(c++);
                    } else if(c == 16){
                        cenario->getTexture()->changeToFrame(16);
                    }
                } else{
                    if(c > 0){
                        cenario->getTexture()->changeToFrame(c--);
                    } else if(c == 0){
                        cenario->getTexture()->changeToFrame(0);
                        cenario->getTexture()->changeAnim(1);
                        closing = false;
                    }
                }
            default:
                break;
        }
    }
}

void Night::render(){
    switch(pos){
        case 0:
            SDL_RenderCopy(renderer, bedroomTex, cenario->getTexture()->getSrcR(), cenario->getDestR());
            break;
        case 1:
            SDL_RenderCopy(renderer, bathroomTex, cenario->getTexture()->getSrcR(), cenario->getDestR());
            
            if(!moving && cenario->getTexture()->getFramePos() == 0){
                SDL_RenderCopy(renderer, guiTex, button->getTexture()->getSrcR(), button->getDestR());
            }
            break;
        case 2:
            SDL_RenderCopy(renderer, corridorTex, cenario->getTexture()->getSrcR(), cenario->getDestR());

            if(!moving && cenario->getTexture()->getFramePos() == 0){
                SDL_RenderCopy(renderer, guiTex, button->getTexture()->getSrcR(), button->getDestR());
            }
        default:
            break;
    }

    SDL_RenderCopy(renderer, guiTex, control->getTexture()->getSrcR(), control->getDestR());
    SDL_RenderCopy(renderer, guiTex, lilBox->getTexture()->getSrcR(), lilBox->getDestR());

    if(!attacking){
        SDL_RenderCopy(renderer, guiTex, num1->getTexture()->getSrcR(), num1->getDestR());
        SDL_RenderCopy(renderer, guiTex, num2->getTexture()->getSrcR(), num2->getDestR());
        SDL_RenderCopy(renderer, guiTex, amTxt->getTexture()->getSrcR(), amTxt->getDestR());
    } else{
        if(esposito.isAttacking()){
            SDL_RenderCopy(renderer, fernandoTex, fernandoMiguel->getTexture()->getSrcR(), fernandoMiguel->getDestR());
        } else if(popo.isAttacking()){
            SDL_RenderCopy(renderer, tapioTex, tapio->getTexture()->getSrcR(), tapio->getDestR());
        } else if(manoel.isAttacking()){
            SDL_RenderCopy(renderer, manoelTex, paralisia->getTexture()->getSrcR(), paralisia->getDestR());
        }
    }

    if(seconds == 360){
        SDL_RenderCopy(renderer, guiTex, winTxt->getTexture()->getSrcR(), winTxt->getDestR());
    }
    
}

void Night::detectClick(int x, int y){
    //cout << "X: " << x << " Y: " << y << endl; 
    switch(pos){
        case 0:
            if(cenario->getTexture()->getFramePos() == 0){
                //cout << "Movendo até o banheiro" << endl;
                moving = true;
                entering = false;
                c = 0;
                cenario->getTexture()->changeAnim(1);
            } else if(cenario->getTexture()->getFramePos() == 10){
                moving = true;
                entering = false;
                c = 0;
                cenario->getTexture()->changeAnim(2);
            }
            break;
        case 1:
            if(cenario->getTexture()->getFramePos() == 0){
                if(x >= button->getDestR()->x && x <= button->getDestR()->x+button->getDestR()->w && y >= button->getDestR()->y && y <= button->getDestR()->y+button->getDestR()->h){
                    //cout << "Saindo do banheiro" << endl;
                    moving = true;
                    entering = false;
                    c = 13;
                    cenario->getTexture()->changeToFrame(13);
                    cenario->getTexture()->changeAnim(0);
                } else{
                    //cout << "Fechando porta" << endl;
                    closing = true;
                    lDoor = true;
                    c = 0;
                    cenario->getTexture()->changeAnim(2);
                }
            }
            break;
        case 2:
            if(cenario->getTexture()->getFramePos() == 0){
                if(x >= button->getDestR()->x && x <= button->getDestR()->x+button->getDestR()->w && y >= button->getDestR()->y && y <= button->getDestR()->y+button->getDestR()->h){
                    //cout << "Saindo do corredor" << endl;
                    moving = true;
                    entering = false;
                    c = 13;
                    cenario->getTexture()->changeToFrame(13);
                    cenario->getTexture()->changeAnim(0);
                } else{
                    //cout << "Fechando porta" << endl;
                    closing = true;
                    rDoor = true;
                    c = 0;
                    cenario->getTexture()->changeAnim(2);
                }
            }
            break;
        default:
            break;
    }
}

void Night::detectHold(int x, int y){
    switch(pos){
        case 1:
            if(closing){
                //cout << "Soltando porta" << endl;
                lDoor = false;
            }
            break;
        case 2:
            if(closing){
                //cout << "Soltando porta" << endl;
                rDoor = false;
            }
        default:
            break;
    }
}

void Night::turnLight(bool isOn){
    switch(pos){
        case 1:
            if(isOn){
                cenario->getTexture()->changeAnim(0);
                if(popo.getLevel() != 0){
                    if(popo.getStage() >= 5){
                        if(manoel.getStage() == 2){
                            cenario->getTexture()->changeToFrame(18);
                        } else{
                            cenario->getTexture()->changeToFrame(16);
                        }
                    } else{
                        if(manoel.getStage() == 2){
                            cenario->getTexture()->changeToFrame(17);
                        } else{
                            cenario->getTexture()->changeToFrame(15);
                        }
                    }
                }
                else{
                    if(manoel.getStage() == 2){
                        cenario->getTexture()->changeToFrame(19);
                    } else{
                        cenario->getTexture()->changeToFrame(14);
                    }
                }
                lLight = true;
            } else{
                cenario->getTexture()->changeAnim(1);
                cenario->getTexture()->changeToFrame(0);
                lLight = false;
            }
            break;
        case 2:
            if(isOn){
                cenario->getTexture()->changeAnim(0);
                if(esposito.getStage() != 0){
                    switch(esposito.getStage()){
                        case 1:
                            cenario->getTexture()->changeToFrame(15);
                            break;
                        case 2:
                            attacking = true;
                            esposito.attack();
                            c = 0;
                            break;
                        default:
                            break;
                    }
                } else{
                    cenario->getTexture()->changeToFrame(14);
                }

                if(manoel.getStage() == -2){
                    cenario->getTexture()->changeToFrame(16);
                }

                rLight = true;
            } else{
                cenario->getTexture()->changeAnim(1);
                cenario->getTexture()->changeToFrame(0);
                if(esposito.getStage() == 1){
                    esposito.resetStage();
                }
                rLight = false;
            }
            break;
        default:
            break;
    }
}

void Night::close(){
    SDL_DestroyTexture(bedroomTex);
    SDL_DestroyTexture(bathroomTex);
    SDL_DestroyTexture(corridorTex);
    SDL_DestroyTexture(guiTex);

    Mix_FreeMusic(comemoraAud);
    Mix_FreeMusic(saiAud);
    Mix_FreeMusic(respiraAud);
    Mix_CloseAudio();
}

bool Night::isClosing(){
    return closing;
}

bool Night::isMoving(){
    return moving;
}

bool Night::isLosing(){
    return win;
}

bool Night::isAttacking(){
    return attacking;
}

bool Night::isLight(){
    return (lLight || rLight);
}

int Night::getPos(){
    return pos;
}