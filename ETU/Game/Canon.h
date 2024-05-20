#pragma once
#include "GameObject.h"
class Canon :
    public GameObject
{
public:
    static const int CANON_HP;
public:
    Canon();
    virtual bool init(const ContentManager& contentManager) override;

    bool update(float deltaT, const Inputs& inputs);
private:
    void stayInbounds();
    int canonHP;
};

