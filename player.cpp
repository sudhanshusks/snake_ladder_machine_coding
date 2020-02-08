#include<string>

class Player{
    private:
        std::string name;
        int position;
        bool game_won;
    public:
        Player(std::string name){
            this->name= name;
            this->position= 0;
            this->game_won= false;
        }
        std::string get_name(){
            return name;
        }
        int get_position(){
            return position;
        }
        void set_position(int position){
            this->position= position;
            return;
        }
        bool get_game_won(){
            return game_won;
        }
        void set_game_won(bool game_won){
            this->game_won= game_won;
            return;
        }
};