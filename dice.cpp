#include<time.h>
#include<stdlib.h>

class Dice{
    private:
        int smallest_value;
        int largest_value;
        int roll_value;
    public:
        Dice(int smallest_value= 1, int largest_value= 6){
            this->smallest_value= smallest_value;
            this->largest_value= largest_value;
            // using current time as seed for random number generation
            srand(time(NULL));
        }

        int get_smallest_value(){
            return smallest_value;
        }
        int get_largest_value(){
            return largest_value;
        }
        int get_roll_value(){
            int random_number= rand();
            roll_value= (random_number%this->largest_value) + this->smallest_value; 
            return roll_value;
        }
};