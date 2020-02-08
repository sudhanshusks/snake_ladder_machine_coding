#include "dice.cpp"
#include "board.cpp"
#include "ladder.cpp"
#include "player.cpp"
#include "snake.cpp"

#include<unordered_map>
#include<vector>
#include<iostream>

class Game{
    public:
        int num_players;
        int num_snakes;
        int num_ladders;
    private:
        Board board;
        Dice dice;
        std::vector<Player> players;
        std::unordered_map<int, int> snakes;
        std::unordered_map<int, int> ladders;
    public:
        Game(int board_size){
            board= Board(board_size, 1);
            dice= Dice(1, 6);
        }
        // void set_num_players(int num_players){
        //     num_players= num_players;
        //     return;
        // }
        // void set_num_snakes(int num_snakes){
        //     num_snakes= num_snakes;
        //     return;
        // }
        // void set_num_ladders(int num_ladders){
        //     num_ladders= num_ladders;
        //     return;
        // }
        void add_players(std::string name){
            Player p= Player(name);
            players.push_back(p);
            return;
        }
        void add_snakes(int head, int tail){
            // Snake s= Snake(head, tail);
            // snakes.push_back(s);
            snakes.insert({head, tail});
            return;
        }
        void add_ladder(int start, int end){
            // Ladder l= Ladder(start, end);
            // ladders.push_back(l);
            ladders.insert({start, end});
            return;
        }
        void play_game(){
            int num_player_won= 0;
            while(num_player_won < num_players-1){
                for(int i=0; i<num_players; i++){
                    if(players[i].get_game_won() == true) continue;
                    int dice_value= dice.get_roll_value();
                    int player_current_position= players[i].get_position();
                    int player_next_position= player_current_position + dice_value;
                    if(player_next_position > board.get_end()){
                        std::cout<<players[i].get_name()<<" rolled a "<<dice_value<<
                        " and moved from "<<player_current_position<<" to "<<
                        player_current_position<<std::endl;
                        continue;
                    }
                    while(snakes.find(player_next_position) != snakes.end()){
                        player_next_position= snakes[player_next_position];
                        while(ladders.find(player_next_position) != ladders.end()){
                            if(snakes.find(player_next_position) == snakes.end()){
                                player_next_position= ladders[player_next_position];
                            }
                        }
                    }
                    std::cout<<players[i].get_name()<<" rolled a "<<dice_value<<
                    " and moved from "<<player_current_position<<" to "<<
                    player_next_position<<std::endl;
                    players[i].set_position(player_next_position);
                    if(player_next_position == board.get_end()){
                        std::cout<<players[i].get_name()<<" wins the game"<<std::endl;
                        num_player_won++;
                        players[i].set_game_won(true);
                        if(num_player_won == num_players-1) break;
                        else continue;
                    }
                }
            }
            return;
        }
};