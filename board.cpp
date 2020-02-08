class Board{
    private:
        int size;
        int start;
        int end;
    public:
        Board(int size=100, int start=1){
            size= size;
            start= start;
            end= start+size-1;
        }
        int get_size(){
            return size;
        }
        int get_start(){
            return start;
        }
        int get_end(){
            return end;
        }
};