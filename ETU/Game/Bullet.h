#pragma once
#include "GameObject.h"
#include "ContentManager.h"
class Bullet :
    public GameObject
{
public:
    static const float BULLET_SPEED;
    static const int BULLET_TEXTURE_ROTATION;
public:
    Bullet(const sf::Vector2f& initialPosition = sf::Vector2f(0, 0), const sf::Vector2f& initialThrust = sf::Vector2f(0, 0));
    Bullet(const Bullet& src);
    virtual bool init(const ContentManager& contentManager) override;
    virtual void activate(float posX, float posY);
    void draw(sf::RenderWindow& window) const;
    bool update(float elapsedTime);
protected:
    Bullet& operator=(const Bullet& rhs);
    sf::Sound sound;
    sf::Sprite sprite;
private:
};

