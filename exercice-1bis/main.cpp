#include <iostream>
#include "Item.h"
#include "Inventory.h"

int main()
{
    Inventory inventory;
    inventory.AddItem( new Item("Wooden Pickaxe", 2.25f) );
    inventory.AddItem( new Item("Stone Pickaxe", 8.1f) );
    inventory.AddItem( new Item("Gold Pickaxe", 58.03f) );
    inventory.AddItem( new Item("Iron Pickaxe", 23.62f) );
    inventory.AddItem( new Item("Diamond Pickaxe", 10.62f) );
    inventory.AddItem( new Item("Netherite Pickaxe", 262.16f) );
    std::cout << "Base " << inventory << std::endl;
    inventory.Sort( []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->GetName() < pItem2->GetName(); } );
    std::cout << "Sorted by Name " << inventory << std::endl;
    inventory.Sort( []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->GetName() > pItem2->GetName(); } );
    std::cout << "Sorted by Name Reversed " << inventory << std::endl;
    inventory.Sort( []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->GetWeight() < pItem2->GetWeight(); } );
    std::cout << "Sorted by Weight " << inventory << std::endl;
    inventory.Sort( []( const Item* const pItem1, const Item* const pItem2 ){ return pItem1->GetWeight() > pItem2->GetWeight(); } );
    std::cout << "Sorted by Weight Reversed " << inventory << std::endl;
    inventory.FilterItems( []( const Item* const pItem ){ return pItem->GetWeight() > 10.0f; } );
    std::cout << "Filtered by Weight above 10kg " << inventory << std::endl;
    inventory.FilterItems( []( const Item* const pItem ){ return pItem->GetWeight() < 50.0f; } );
    std::cout << "Filtered again by Weight below 50kg " << inventory << std::endl;
    std::cout << "Number of matching items : " << inventory.GetNumberOfMatchingItems() << '\n' << std::endl;
    inventory.ClearFilters();
    std::cout << "Filters removed " << inventory << std::endl;
    std::cout << "Number of Items with \'o\' as second letter : " << inventory.GetNumberOfMatchingItems( []( const Item* const pItem){ return pItem->GetName()[1] == 'o'; }) << '\n' << std::endl;
    return 0;
}