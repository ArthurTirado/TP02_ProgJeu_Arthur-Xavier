#include "stdafx.h"
#include "GameScene.h"

#include "game.h"

const int GameScene::NB_HP_BONUSES = 5;
const int GameScene::NB_WEAPON_BONUSES = 3;
const int GameScene::NB_BULLETS_PLAYER = 150;
const int GameScene::NB_BULLETS_ENEMIES = 100;
const int GameScene::NB_ENEMIES = 50;


GameScene::GameScene()
	: Scene(SceneType::GAME_SCENE)
{

}

GameScene::~GameScene()
{
}

SceneType GameScene::update()
{
	return SceneType();
}

void GameScene::draw(sf::RenderWindow& window) const
{
	window.draw(background);

	for (const PlayerBullet& b : playerBullets) {
		b.draw(window);
	}

	for (const EnemyBullet& b : enemyBullets) {
		b.draw(window);
	}

	for (const HealthBonus& hb : healthBonuses) {
		hb.draw(window);
	}

	for (const WeaponBonus& wb : gunBonuses) {
		wb.draw(window);
	}
	player.draw(window);
	canon.draw(window);
	boss.draw(window);
	hud.draw(window);
}

bool GameScene::init()
{
	// Bonus HP
	for (int i = 0; i < NB_HP_BONUSES; i++) {
		HealthBonus newBonus;
		newBonus.init(contentManager);
		healthBonuses.push_back(newBonus);
	}

	// Bonus arme
	for (int i = 0; i < NB_WEAPON_BONUSES; i++) {
		WeaponBonus newBonus;
		newBonus.init(contentManager);
		gunBonuses.push_back(newBonus);
	}

	// Balles joueur
	for (int i = 0; i < NB_BULLETS_PLAYER; i++)
	{
		PlayerBullet newBullet;
		newBullet.init(contentManager);
		playerBullets.push_back(newBullet);
	}

	//Balles ennemis
	for (int i = 0; i < NB_BULLETS_ENEMIES; i++)
	{
		EnemyBullet newBullet;
		newBullet.init(contentManager);
		enemyBullets.push_back(newBullet);
	}
}

bool GameScene::uninit()
{
	return false;
}

bool GameScene::handleEvents(sf::RenderWindow& window)
{
	return true;
}
