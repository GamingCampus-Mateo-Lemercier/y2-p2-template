#include "Inventory.h"
#include <iostream>
#include "Item.h"



std::ostream& operator<<( std::ostream& os, const Inventory& inventory )
{
    os << "Inventory:\n";
    for ( const Item* pItem: inventory.m_items )
        os << "name = \"" << pItem->m_name << "\" and weight = " << pItem->m_weight << "kg\n";
    return os;
}




Inventory::Inventory():
    m_items(),
{}

Inventory::~Inventory() = default;
