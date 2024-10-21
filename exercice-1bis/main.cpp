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
    std::cout << inventory << std::endl;
    inventory.SortByName();
    std::cout << inventory << std::endl;
    inventory.SortByNameReverse();
    std::cout << inventory << std::endl;
    inventory.SortByWeight();
    std::cout << inventory << std::endl;
    inventory.SortByWeightReverse();
    std::cout << inventory << std::endl;
    inventory.PrintItem( "Wooden Pickaxe" );
    return 0;
}