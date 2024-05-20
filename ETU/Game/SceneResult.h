#pragma once

struct TitleSceneResult
{
};

struct LeaderboardSceneResult 
{
};

struct GameSceneResult {
};


union SceneResult
{
	int score;
  TitleSceneResult titleSceneResult;
  GameSceneResult gameSceneResult;
  LeaderboardSceneResult leaderboardSceneResult;
};