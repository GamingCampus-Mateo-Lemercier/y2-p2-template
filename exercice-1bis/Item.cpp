#include "Item.h"


Item::Item( const std::string& name, const float weight ):
    m_name( name ),
    m_weight( weight )
{}

Item::~Item() = default;
