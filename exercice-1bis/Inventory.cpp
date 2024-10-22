#include "Inventory.h"
#include <algorithm>
#include <iostream>
#include "Item.h"



std::ostream& operator<<( std::ostream& os, const Inventory& inventory )
{
    os << "Inventory (totalWeight = " << inventory.m_totalWeight << "):\n";
    for ( const Item* pItem: inventory.m_items )
        os << *pItem;
    return os;
}




Inventory::Inventory():
    m_items(),
    m_totalWeight( 0.0f )
{}

Inventory::~Inventory() = default;



void Inventory::AddItem( Item* const pItem )
{
    m_items.push_back( pItem );
    m_totalWeight += pItem->m_weight;
}

void Inventory::RemoveItem( const char* const name )
{
    const auto it = FindItem( name );
    const Item* const pItem = *it;
    m_totalWeight -= pItem->m_weight;
    m_items.erase( it );
    delete pItem;
}



void Inventory::SortByName()
{
    std::sort( m_items.begin(), m_items.end(), []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->m_name < pItem2->m_name; } );
}

void Inventory::SortByNameReverse()
{
    std::sort( m_items.begin(), m_items.end(), []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->m_name > pItem2->m_name; } );
}

void Inventory::SortByWeight()
{
    std::sort( m_items.begin(), m_items.end(), []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->m_weight < pItem2->m_weight; } );
}

void Inventory::SortByWeightReverse()
{
    std::sort( m_items.begin(), m_items.end(), []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->m_weight > pItem2->m_weight; } );
}



void Inventory::PrintItem( const char* const name )
{
    const Item* const pItem = *FindItem( name );
    std::cout << "name = " << pItem->m_name << " and weight = " << pItem->m_weight << "kg\n"; 
}





std::vector<Item*>::iterator Inventory::FindItem( const char* const name ) // toAsk why can't I return iterator&
{
    return std::find_if( m_items.begin(), m_items.end(), [ name ]( const Item* const pItem ){ return pItem->m_name == name; } );
}

