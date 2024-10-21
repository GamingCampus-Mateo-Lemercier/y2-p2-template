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

    void AddItem( Item* pItem );
    void RemoveItem( const char* name );

    void PrintItem( const char* name );

protected:
    [[nodiscard]] std::vector<Item*>::iterator FindItem( const char* name );

protected:
    std::vector<Item*> m_items;
};
