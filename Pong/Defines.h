#pragma once

enum class Origins
{
	// T M B
	// L C R
	TL, TC, TR, ML, MC, MR, BL, BC, BR, CUSTOM,
};

enum class Sides
{
	NONE = -1, LEFT, RIGHT, COUNT
};

enum class SceneIds
{
	NONE = -1,
	SCENE_Pong,
	COUNT,
};

enum class PlayerReadyState
{
	NONE = -1,
	READY,
	NOT_READY,
};