#include "Item.h"



std::ostream& operator<<( std::ostream& os, const Item& item )
{
    os << "- " << item.m_name << ": " << item.m_weight << "kg\n";
    return os;
}



Item::Item( const std::string& name, const float weight ):
    m_name( name ),
    m_weight( weight ),
    m_visible( true )
{}

Item::~Item() = default;



const std::string& Item::GetName() const
{
    return m_name;
}

float Item::GetWeight() const
{
    return m_weight;
}
