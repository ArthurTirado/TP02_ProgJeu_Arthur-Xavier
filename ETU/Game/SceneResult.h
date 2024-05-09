#pragma once

struct TitleSceneResult
{
  int dummy;
};

struct LeaderboardSceneResult {
	int dummy;
};


union SceneResult
{
  TitleSceneResult titleSceneResult;
  LeaderboardSceneResult leaderboardSceneResult;
};