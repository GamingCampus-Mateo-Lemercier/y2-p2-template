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
    inventory.SortByName();
    std::cout << "Sorted by Name " << inventory << std::endl;
    inventory.SortByNameReverse();
    std::cout << "Sorted by Name Reversed " << inventory << std::endl;
    inventory.SortByWeight();
    std::cout << "Sorted by Weight " << inventory << std::endl;
    inventory.SortByWeightReverse();
    std::cout << "Sorted by Weight Reversed " << inventory << std::endl;
    inventory.FilterItems( []( const Item* const pItem ){ return pItem->GetWeight() > 10.0f; } );
    std::cout << "Filtered by Weight above 10kg " << inventory << std::endl;
    inventory.ClearFilters();
    std::cout << "Filters removed " << inventory << std::endl;
    return 0;
}