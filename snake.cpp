class Snake{
    private:
        int head;
        int tail;
    public:
        Snake(int head, int tail){
            head= head;
            tail= tail;
        }
        int get_head(){
            return head;
        }
        int get_tail(){
            return tail;
        }
};