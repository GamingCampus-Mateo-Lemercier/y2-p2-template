#pragma once
#include <functional>
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

    void SortByName();
    void SortByNameReverse();
    void SortByWeight();
    void SortByWeightReverse();

    [[nodiscard]] int GetNumberOfMatchingItems( const std::function<bool( const Item* pItem )>& filter ) const;
    void FilterItems( const std::function<bool( const Item* pItem )>& filter );
    void ClearFilters();

    [[nodiscard]] float GetTotalWeight() const;
    [[nodiscard]] float GetAverageWeight() const;

    void PrintItem( const char* name );

protected:
    [[nodiscard]] std::vector<Item*>::iterator FindItem( const char* name );

protected:
    std::vector<Item*> m_items;
    float m_totalWeight;
    float m_maxWeight;
};
