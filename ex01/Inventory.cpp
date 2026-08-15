#include "Inventory.hpp"
#include <iostream>

void Inventory::add(const std::string& item){
    m_items.push_back(item);
};

void Inventory::remove(const std::string& item){
    for (auto it = m_items.begin(); it != m_items.end();){
        if (*it == item){
            m_items.erase(it);
            break;
        }else ++it;
    }
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