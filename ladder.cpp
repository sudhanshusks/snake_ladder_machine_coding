class Ladder{
    private:
        int start;
        int end;
    public:
        Ladder(int start, int end){
            start= start;
            end= end;
        }
        int get_start(){
            return start;
        }
        int get_end(){
            return end;
        }
};