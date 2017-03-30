#include "CScreen.h"
#include "Player.h"


void MonsterDead_Disp(int MonTate, int MonYoko, const char   *SCENE){
	int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
	PLAYWAVE(DEAD_Sound, 0);
	
	MonstersCL_Display(MonTate, MonYoko, SCENE);
	
	for (int i = 0; i < MONSTER_HEIGHT; i++){
		LOCATE(MonYoko + 2, MonTate + i);
		COLOR(10, 10);
		printf("　");
	}
	WAIT(80);
	MonstersCL_Display(MonTate, MonYoko, SCENE);
	LOCATE(MonYoko, MonTate);
	COLOR(10, 10);
	printf("　");
	LOCATE(MonYoko + 4, MonTate);
	COLOR(10, 10);
	printf("　");
	LOCATE(MonYoko, MonTate+2);
	COLOR(10, 10);
	printf("　");
	LOCATE(MonYoko + 4, MonTate+2);
	COLOR(10, 10);
	printf("　");
	WAIT(120);
	MonstersCL_Display(MonTate, MonYoko, SCENE);
	STOPWAVE(DEAD_Sound);
	CLOSEWAVE(DEAD_Sound);
}


void	BossDead_Disp(int MonTate, int MonYoko, const char   *SCENE){
	int play_Out[BOSS_HEIGHT][BOSS_WIDTH]; //Player画面変数：横：7；縦：7
	int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
	PLAYWAVE(DEAD_Sound, 0);

	BOSSCL_Display(MonTate, MonYoko, SCENE);

	for (int i = 0; i < BOSS_HEIGHT; i++){
		LOCATE(MonYoko + 4, MonTate + i);
		COLOR(10, 10);
		printf("　");
		LOCATE(MonYoko + 6, MonTate + i);
		COLOR(10, 10);
		printf("　");
		LOCATE(MonYoko + 8, MonTate + i);
		COLOR(10, 10);
		printf("　");
	}
	WAIT(80);
	BOSSCL_Display(MonTate, MonYoko, SCENE);

	FILE *fp;
	fp = fopen(FILENAME_BOSSDEAD, "rt+");
	for (int i = 0; i < BOSS_HEIGHT; i++){
		for (int j = 0; j < BOSS_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(MonYoko + (2 * yoko), MonTate + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("　");
			}
		}

	}
	WAIT(120);
	BOSSCL_Display(MonTate, MonYoko, SCENE);
	STOPWAVE(DEAD_Sound);
	CLOSEWAVE(DEAD_Sound);
}