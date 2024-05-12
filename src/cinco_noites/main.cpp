#include "game.h"

//g++ -c src/clubPenguin/*.cpp src/clubPenguin/objects/*.cpp src/clubPenguin/places/*.cpp -I"C:\Users\thier\OneDrive\Documentos\Programacao\CP\libs\SFML-2.6.1\include" 
//g++ *.o -o main -L"C:\Users\thier\OneDrive\Documentos\Programacao\CP\libs\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
//.\main

int main(){

    Game game;

    while(game.running()){
        game.update();
        game.render();
    }
    
    return 0;
}