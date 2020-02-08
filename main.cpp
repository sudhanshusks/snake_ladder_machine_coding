#include "game.cpp"

#include<iostream>
#include<fstream>

int main(){
    Game g1= Game(100);
    int s, l, p;
    // std::ifstream infile("input.txt");
    // std::string line;
    // while(std::getline(infile, line)){
    // }
    std::cin>>s;
    g1.num_snakes= s;
    for(int i=0; i<s; i++){
        int head, tail;
        std::cin>>head>>tail;
        g1.add_snakes(head, tail);
    }
    std::cin>>l;
    g1.num_ladders= l;
    for(int i=0; i<l; i++){
        int start, end;
        std::cin>>start>>end;
        g1.add_ladder(start, end);
    }
    std::cin>>p;
    g1.num_players= p;
    for(int i=0; i<p; i++){
        std::string name;
        std::cin>>name;
        g1.add_players(name);
    }
    g1.play_game();
    return 0;
}