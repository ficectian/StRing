#include "CScreen.h"
#include "Player.h"

int*	MonsterOutOfRange(int Mon_X, int Mon_Y,int Mon_SIDE, int Left_X, int Right_X, int Up_y, int Down_y, const char  * SCENE){
	static int Return[3];

	if (Mon_Y <= Up_y){
		MonstersCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y += 4;
		Mon_SIDE = rand() % 4;
		Monsters_Display(Mon_Y, Mon_X);

	}
	if (Mon_Y+MONSTER_HEIGHT >= Down_y){
		MonstersCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y -= 4;
		Mon_SIDE = rand() % 4;
		Monsters_Display(Mon_Y, Mon_X);
	}
	if (Mon_X <= Left_X){
		MonstersCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X += 6;
		Mon_SIDE = rand() % 4;
		Monsters_Display(Mon_Y, Mon_X);
	}
	if (Mon_X+MONSTER_WIDTH*2 >= Right_X){
		MonstersCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X -= 6;
		Mon_SIDE = rand() % 4;
		Monsters_Display(Mon_Y, Mon_X);
	}
	*Return = Mon_X;
	*(Return + 1) = Mon_Y;
	*(Return + 2) = Mon_SIDE;

	return Return;
}

int*	BossOutOfRange(int Mon_X, int Mon_Y, int Mon_SIDE, int Left_X, int Right_X, int Up_y, int Down_y, const char  * SCENE){
	static int Return[3];

	if (Mon_Y <= Up_y){
		BOSSCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y += 4;
		Mon_SIDE = rand() % 4;
		BOSSp_Display(Mon_Y, Mon_X);

	}
	if (Mon_Y + BOSS_HEIGHT >= Down_y){
		BOSSCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y -= 4;
		Mon_SIDE = rand() % 4;
		BOSSb_Display(Mon_Y, Mon_X);
	}
	if (Mon_X <= Left_X){
		BOSSCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X += 6;
		Mon_SIDE = rand() % 4;
		BOSSl_Display(Mon_Y, Mon_X);
	}
	if (Mon_X + BOSS_WIDTH*2 >= Right_X){
		BOSSCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X -= 6;
		Mon_SIDE = rand() % 4;
		BOSSr_Display(Mon_Y, Mon_X);
	}
	*Return = Mon_X;
	*(Return + 1) = Mon_Y;
	*(Return + 2) = Mon_SIDE;

	return Return;
}

int*	LordOutOfRange(int Mon_X, int Mon_Y, int Mon_SIDE, int Left_X, int Right_X, int Up_y, int Down_y, const char  * SCENE){
	static int Return[3];

	if (Mon_Y <= Up_y){
		LORDCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y += LORD_STRIDE_HEIGHT;
		Mon_SIDE = rand() % 4;
		LORDp_Display(Mon_Y, Mon_X);

	}
	if ((Mon_Y + LORD_HEIGHT) >= Down_y){
		LORDCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_Y -= LORD_STRIDE_HEIGHT;
		Mon_SIDE = rand() % 4;
		LORDb_Display(Mon_Y, Mon_X);
	}
	if (Mon_X <= Left_X){
		LORDCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X += LORD_STRIDE_WIDTH;
		Mon_SIDE = rand() % 4;
		LORDl_Display(Mon_Y, Mon_X);
	}
	if (Mon_X + LORD_WIDTH*2 >= Right_X){
		LORDCL_Display(Mon_Y, Mon_X, SCENE);
		Mon_X -= LORD_STRIDE_WIDTH;
		Mon_SIDE = rand() % 4;
		LORDr_Display(Mon_Y, Mon_X);
	}
	*Return = Mon_X;
	*(Return + 1) = Mon_Y;
	*(Return + 2) = Mon_SIDE;

	return Return;
}