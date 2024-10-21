#include "Inventory.h"
#include <algorithm>
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



void Inventory::AddItem( Item* const pItem )
{
    m_items.push_back( pItem );
}

void Inventory::RemoveItem( const char* name )
{
    m_items.erase( FindItem( name ) );
}



void Inventory::PrintItem( const char* name )
{
    const Item* const pItem = *FindItem( name );
    std::cout << "name = " << pItem->m_name << " and weight = " << pItem->m_weight << "kg\n"; 
}





std::vector<Item*>::iterator Inventory::FindItem( const char* name ) // toAsk why can't I return iterator&
{
    return std::find_if( m_items.begin(), m_items.end(), [ name ]( const Item* const pItem ){ return pItem->m_name == name; } );
}

