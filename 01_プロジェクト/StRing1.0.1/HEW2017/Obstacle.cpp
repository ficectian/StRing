#include "CScreen.h"
#include "Player.h"



//=========================================================
//	障害物表示関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  Obstacle_Display(int Pt_tate, int Pt_yoko){
	int Obstacle_Out[OBSTACLE_HEIGHT][OBSTACLE_WIDTH];		//Player画面変数：横：6；縦：6

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_OBSTACLE, "rt+");
	for (int i = 0; i < OBSTACLE_HEIGHT; i++){
		for (int j = 0; j < OBSTACLE_WIDTH; j++){
			fscanf_s(fp, "%d,", &Obstacle_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < OBSTACLE_HEIGHT; tate++){
		for (int yoko = 0; yoko < OBSTACLE_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (Obstacle_Out[tate][yoko] != 16){
				COLOR(Obstacle_Out[tate][yoko], Obstacle_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

//=========================================================
//	障害物表示関数（赤）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  ObstacleR_Display(int Pt_tate, int Pt_yoko){
	int Obstacle_Out[OBSTACLE_HEIGHT][OBSTACLE_WIDTH];		//Player画面変数：横：6；縦：6

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_OBSTACLER, "rt+");
	for (int i = 0; i < OBSTACLE_HEIGHT; i++){
		for (int j = 0; j < OBSTACLE_WIDTH; j++){
			fscanf_s(fp, "%d,", &Obstacle_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < OBSTACLE_HEIGHT; tate++){
		for (int yoko = 0; yoko < OBSTACLE_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (Obstacle_Out[tate][yoko] != 16){
				COLOR(Obstacle_Out[tate][yoko], Obstacle_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

int*  Obstacle_Obs(int Pt_tate, int Pt_yoko, int Obstacle_tate, int Obstacle_yoko, int Jub_Side, const char   *SCENE ){
	static int R[2];

	if (((Pt_tate - Obstacle_tate) >= 0 && (Pt_tate - Obstacle_tate) <= 7) || ((Obstacle_tate - Pt_tate) >= 0 && (Obstacle_tate - Pt_tate) <= 7)){
		if (((Pt_yoko - Obstacle_yoko) >= 0 && (Pt_yoko - Obstacle_yoko) <= 14) || ((Obstacle_yoko - Pt_yoko) >= 0 && (Obstacle_yoko - Pt_yoko) <= 14)){

			switch (Jub_Side)
			{
			case SIDE_UP:
				PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
				Pt_yoko += STRIDE_HEIGHT;
				PlayerB_Display(Pt_tate, Pt_yoko);
				break;
			case SIDE_DOWN:
				PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
				Pt_yoko -= STRIDE_HEIGHT;
				Player_Display(Pt_tate, Pt_yoko);
				break;
			case SIDE_LEFT:
				PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
				Pt_yoko += STRIDE_WIDTH;
				PlayerL_Display(Pt_tate, Pt_yoko);
				break;
			case SIDE_RIGHT:
				PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
				Pt_yoko -= STRIDE_WIDTH;
				PlayerR_Display(Pt_tate, Pt_yoko);
				break;
			default:
				break;
			}
			Obstacle_Display(Obstacle_tate, Obstacle_yoko);

		}
	}
	*R = Pt_tate;
	*(R + 1) = Pt_yoko;
	return R;
}

int  Obstacle_Att(int Pt_tate, int Pt_yoko, int Obstacle_tate, int Obstacle_yoko, int Jub_Side, int HP,const char   *SCENE){
	//static int R[3];
	int ATT_YOKO;
	switch (Jub_Side)
	{
	case SIDE_LEFT:
		ATT_YOKO = Pt_yoko - (ATTACK_HEIGHT_WIDTH * 2);
		break;
	case SIDE_RIGHT:
		ATT_YOKO = Pt_yoko + (PLAYER_WIDTH * 2);
		break;
	default:
		break;
	}
	for (int atate = 0; atate < 7; atate++){
		for (int ayoko = 0; ayoko < 14; ayoko++){
			for (int btate = 0; btate < 12; btate++){
				for (int byoko = 0; byoko < (ATTACK_HEIGHT_WIDTH * 2); byoko++){
					if ((ATT_YOKO + byoko) == (Obstacle_yoko + ayoko) && (Pt_tate + btate) == (Obstacle_tate + atate)){

						ObstacleR_Display(Obstacle_tate, Obstacle_yoko);
						HP--;
						WAIT(200);
						if (HP>0){
							Obstacle_Display(Obstacle_tate, Obstacle_yoko);
						}
						else
						{
							int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
							PLAYWAVE(DEAD_Sound, 0);
							for (int tate = 0; tate < OBSTACLE_HEIGHT; tate++){
								for (int yoko = 0; yoko < OBSTACLE_WIDTH; yoko++){
									LOCATE(Obstacle_yoko + (2 * yoko), Obstacle_tate + tate);
									COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
									printf("　");
								}
							}
							STOPWAVE(DEAD_Sound);
							CLOSEWAVE(DEAD_Sound);
						}
						return HP;
					}
				}
			}
		}
	}



	return HP;
}
	
