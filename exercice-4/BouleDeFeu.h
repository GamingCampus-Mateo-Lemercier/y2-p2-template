#pragma once
#include "Vector2.h"
#include "Projectile.hpp"


class BouleDeFeu : public Projectile<float>
{

public:
    BouleDeFeu( const Vector2& position, const Vector2& direction, float speed, float damage, float radius );

    void OnImpact() override;

protected:
    float m_radius;

};
