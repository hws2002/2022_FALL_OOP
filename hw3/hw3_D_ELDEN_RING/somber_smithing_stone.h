#include "smithing_stone.h"

class SomberSmithingStone : public SmithingStone{
    public :
    // SomberSmithingStone();
    SomberSmithingStone(int level);
    ~SomberSmithingStone();
    // NormalSmithingStone & operator=(NormalSmithingStone&& other);
    void add_stone(int amount);
    void substract_stone();
    bool should_destroy();
};
