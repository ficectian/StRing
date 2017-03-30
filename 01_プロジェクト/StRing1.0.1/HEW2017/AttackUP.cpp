#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  AttackUP_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_ATTACKUP, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate -1- ATTACK_WIDTH_HEIGHT+1 + tate);
			//１６の時背景色を表示
			if (Attack_Out[tate][yoko] != 16){
				COLOR(Attack_Out[tate][yoko], Attack_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

void  AttackUP_W_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_ATTACKUP, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate - 1 - ATTACK_WIDTH_HEIGHT + 1 + tate);
			//１６の時背景色を表示
			if (Attack_Out[tate][yoko] != 16){
				COLOR(15, 15);
				printf("　");
			}
		}

	}
}

//=========================================================
//	Player画面削除関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）；
//	引数：int： *Scene（背景画面）
//=========================================================
void  AttackCLUP_Display(int Pt_tate, int Pt_yoko,  const char   *SCENE){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player画面変数：横：５；縦：１２
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int Pix_YOKO;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO =( (Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_ATTACKUP, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	FILE *fp2;
	fp2 = fopen(SCENE, "rt+");
	for (int i = 0; i < WINDOWS_HEIGHT; i++){
		for (int j = 0; j < WINDOWS_WIDTH; j++){
			fscanf_s(fp2, "%d,", &Scene[i][j]);
		}
	}
	fclose(fp2);
	//Player画面データを表示
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH), Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate);
			//１６の時背景色を表示
			if (Attack_Out[tate][yoko] != 16){
				if (Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)] == 16){
					COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
					printf("　");
				}
				if (Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
					//Scene[Pt_tate + tate][Pt_yoko + yoko]
					COLOR(L_BLACK, L_BLACK);
					printf("　");
				}
				else{
					COLOR(Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)], Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)]);
					printf("　");
				}
			}
		}
	}


}