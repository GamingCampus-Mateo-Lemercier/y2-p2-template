#pragma once
#include <string>


class Item
{
public:
    explicit Item( const std::string& name, float weight );
    ~Item();

protected:
    std::string m_name;
    float m_weight;
};
