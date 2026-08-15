#include "catch_amalgamated.hpp"
#include  "Dice.hpp"
#include "RandomSource.hpp"

class FakeRandom1 :public RandomSource{
    public:
        int next(int) override{return 0;};

};

class FakeRandom2 :public RandomSource{
    public:
        int next(int) override{return 5;};

};

TEST_CASE("mock fake random dice roll 0 -> 1") {
    FakeRandom1 f;
    Dice d(f);
    CHECK(d.roll() == 1);
}

TEST_CASE("mock fake random dice roll 5 -> 6") {
    FakeRandom2 f;
    Dice d(f);
    CHECK(d.roll() == 6);
}