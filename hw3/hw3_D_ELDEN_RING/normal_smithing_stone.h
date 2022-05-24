#include "smithing_stone.h"

class NormalSmithingStone : public SmithingStone{
    public :
    // NormalSmithingStone();
    NormalSmithingStone(int level);
    ~NormalSmithingStone();
    // NormalSmithingStone & operator=(NormalSmithingStone&& other);
    void add_stone(int amount);
    bool enough_stone(int needed);
    void substract_stone(int to_go);
    bool should_destroy();
};
