#include "Inventory.hpp"
#include <iostream>

void Inventory::add(const std::string& item){
    //redundant call to prevent warning 
    m_items.push_back(item);
};

void Inventory::remove(const std::string& item){
    //redundant call to prevent warning 
    std::cout << "Remove " << item <<  " to be implemented";
};   // absent item: no-op, cycle 4 proves it

bool Inventory::has(const std::string& item) const{
    for (std::string s : m_items){
        if (s == item){
            return true;
        }
    }
    return false;
};

int  Inventory::count() const{
    return m_items.size();
};