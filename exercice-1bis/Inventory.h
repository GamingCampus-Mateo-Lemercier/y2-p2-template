#pragma once
#include <ostream>
#include <vector>

class Item;


class Inventory
{
friend std::ostream& operator<<( std::ostream& os, const Inventory& inventory );

public:
    Inventory();
    ~Inventory();

protected:
    std::vector<Item*> m_items;
};
