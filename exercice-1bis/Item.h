#pragma once
#include <ostream>
#include <string>
#include "Inventory.h"


class Item
{
friend class Inventory;
friend std::ostream& operator<<( std::ostream& os, const Inventory& inventory );
friend std::ostream& operator<<( std::ostream& os, const Item& item );

public:
    explicit Item( const std::string& name, float weight );
    ~Item();

    [[nodiscard]] const std::string& GetName() const;
    [[nodiscard]] float GetWeight() const;

protected:
    std::string m_name;
    float m_weight;
    bool m_visible;
};
