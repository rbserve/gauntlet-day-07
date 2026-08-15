// tests.cpp: no main(), no #define. catch_amalgamated.cpp supplies the runner
#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

TEST_CASE("a new inventory starts empty") {
    Inventory inv;
    REQUIRE(inv.count() == 0);       // REQUIRE aborts the case; the line below is meaningless if this fails
    CHECK_FALSE(inv.has("potion"));  // CHECK reports and continues
}

//1 assertion
TEST_CASE("adding an item raise the count") { 
    Inventory inv;
    inv.add(std::string("potion"));
    REQUIRE(inv.count() == 1);
}

//2 assertions
TEST_CASE("has() finds added item and rejects missing one") {
    Inventory inv;
    inv.add(std::string("potion"));
    REQUIRE(inv.has(std::string("potion")));
    CHECK_FALSE(inv.has(std::string("sword")));
}

//2 assertions
TEST_CASE("removing an item drops the count and has() stops finding it") {
    Inventory inv;
    std::string potion = "potion";
    inv.add(potion);
    inv.remove(potion);
    REQUIRE(inv.count() == 0);
    CHECK_FALSE(inv.has(potion));
}