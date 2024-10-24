#include "Inventory.h"
#include <algorithm>
#include <iostream>
#include "Item.h"



std::ostream& operator<<( std::ostream& os, const Inventory& inventory )
{
    os << "Inventory (totalWeight = " << inventory.m_totalWeight << "):\n";
    for ( const Item* pItem: inventory.m_items )
        if ( pItem->m_visible )
            os << *pItem;
    return os;
}



Inventory::Inventory():
    m_items(),
    m_totalWeight( 0.0f ),
    m_maxWeight( 100.0f )
{}

Inventory::~Inventory() = default;



void Inventory::AddItem( Item* const pItem )
{
    m_totalWeight += pItem->m_weight;
    if ( m_totalWeight >= m_maxWeight )
    {
        m_totalWeight -= pItem->m_weight;
        return;
    }
    m_items.push_back( pItem );
}

void Inventory::RemoveItem( const char* const name )
{
    const auto it = FindItem( name );
    const Item* const pItem = *it;
    m_totalWeight -= pItem->m_weight;
    m_items.erase( it );
    delete pItem;
}



void Inventory::Sort( const std::function<bool( const Item* pItem1, const Item* pItem2 )>& filter )
{
    std::sort( m_items.begin(), m_items.end(), filter );
}



int Inventory::GetNumberOfMatchingItems() const
{
    int result = 0;
    for ( const Item* const pItem: m_items )
        if ( pItem->m_visible )
            result++;
    return result;
}

int Inventory::GetNumberOfMatchingItems( const std::function<bool( const Item* pItem )>& filter ) const
{
    int result = 0;
    for ( const Item* const pItem: m_items )
        if ( filter( pItem ) )
            result++;
    return result;
}

void Inventory::FilterItems( const std::function<bool( const Item* pItem )>& filter )
{
    for ( Item* const pItem: m_items )
        if ( filter( pItem ) == false )
            pItem->m_visible = false;
}

void Inventory::ClearFilters()
{
    for ( Item* const pItem: m_items )
        pItem->m_visible = true;
}



float Inventory::GetTotalWeight() const
{
    return m_totalWeight; 
}

float Inventory::GetAverageWeight() const
{
    return m_totalWeight / static_cast<float>(m_items.size());
}



void Inventory::PrintItem( const char* const name )
{
    const Item* const pItem = *FindItem( name );
    std::cout << *pItem << std::endl; 
}



std::vector<Item*>::iterator Inventory::FindItem( const char* const name ) // toAsk why can't I return iterator&
{
    return std::find_if( m_items.begin(), m_items.end(), [ name ]( const Item* const pItem ){ return pItem->m_name == name; } );
}

