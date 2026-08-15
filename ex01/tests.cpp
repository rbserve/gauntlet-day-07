// tests.cpp: no main(), no #define. catch_amalgamated.cpp supplies the runner
#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

struct InventoryFixture {
    Inventory inv;
    InventoryFixture() { inv.add("potion"); inv.add("sword"); }
};


//1 assertion
TEST_CASE_METHOD(InventoryFixture, "adding an item raise the count") { 
    REQUIRE(inv.count() == 2);
}

//2 assertions
TEST_CASE_METHOD(InventoryFixture, "has() finds added item and rejects missing one") {
    REQUIRE(inv.has(std::string("potion")));
    CHECK_FALSE(inv.has(std::string("elixir")));
}

//2 assertions
TEST_CASE_METHOD(InventoryFixture, "removing an item drops the count") {
    std::string potion = "potion";
    inv.remove(potion);
    REQUIRE(inv.count() == 1);
    CHECK_FALSE(inv.has(potion));
}

//2 assertions
TEST_CASE_METHOD(InventoryFixture, "removing a missing item is a no-op") {

    std::string potion = "potion";
    std::string elixir = "elixir";

    inv.add(potion);
    inv.remove(elixir);

    REQUIRE(inv.count() == 1);
    REQUIRE(inv.has(potion));
}