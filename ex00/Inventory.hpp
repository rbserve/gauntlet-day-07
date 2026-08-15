#pragma once

#include <string>

class Inventory {
public:
    bool has(const std::string& item) const;
    int  count() const;
};