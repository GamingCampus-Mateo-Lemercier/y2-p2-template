#pragma once
#include "Vector2.h"
#include "Projectile.hpp"


class Fleche : public Projectile<int>
{

public:
    explicit Fleche( const Vector2& position, const Vector2& direction, float speed, int damage );

    void OnImpact() override;

};
