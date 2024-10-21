#pragma once
#include <ostream>
#include <string>
#include "Inventory.h"


class Item
{
friend class Inventory;
friend std::ostream& operator<<( std::ostream& os, const Inventory& inventory );

public:
    explicit Item( const std::string& name, float weight );
    ~Item();

protected:
    std::string m_name;
    float m_weight;
};
