#pragma once

#include <string>
#include <vector>

class Inventory {
public:
    bool has(const std::string& item) const;
    int  count() const;
private:
    std::vector<std::string> m_items;
};