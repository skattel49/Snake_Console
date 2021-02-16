#include <vector>
#include <utility>

enum DIR{UP, DOWN, LEFT, RIGHT, NONE};

class Snake{
    private:
        std::pair<int, int> head;
        std::vector<std::pair<int, int>> tail;
        DIR prev;
    public:
        Snake();
        void update(DIR x);
        void addTail();
        friend class Board;
        friend class Fruit;
};