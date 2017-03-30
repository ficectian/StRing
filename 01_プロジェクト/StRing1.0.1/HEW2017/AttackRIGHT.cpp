#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  AttackRIGHT_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player画面変数：横：５；縦：１２
	
	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_ATTACKRIGHT, "rt+");
	for (int i = 0; i < ATTACK_HEIGHT_HEIGHT; i++){
		for (int j = 0; j < ATTACK_HEIGHT_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			LOCATE(Pt_yoko+2 + (2 * yoko) + ATTACK_HEIGHT_WIDTH * 2 + 2, Pt_tate + tate);
			//１６の時背景色を表示
			if (Attack_Out[tate][yoko] != 16){
				COLOR(Attack_Out[tate][yoko], Attack_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

void  AttackRIGHT_W_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_ATTACKRIGHT, "rt+");
	for (int i = 0; i < ATTACK_HEIGHT_HEIGHT; i++){
		for (int j = 0; j < ATTACK_HEIGHT_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			LOCATE(Pt_yoko + 2 + (2 * yoko) + ATTACK_HEIGHT_WIDTH * 2 + 2, Pt_tate + tate);
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
void  AttackCLRIGHT_Display(int Pt_tate, int Pt_yoko, const char   *SCENE){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player画面変数：横：５；縦：１２
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
	fp = fopen(FILENAME_ATTACKRIGHT, "rt+");
	for (int i = 0; i < ATTACK_HEIGHT_HEIGHT; i++){
		for (int j = 0; j < ATTACK_HEIGHT_WIDTH; j++){
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
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			//LOCATE(Pt_yoko + (2 * yoko) - ATTACK_HEIGHT_WIDTH * 2, Pt_tate + tate);

			LOCATE(Pt_yoko + 2 + (2 * yoko) + PLAYER_WIDTH * 2, Pt_tate + tate);

			//１６の時背景色を表示
			if (Attack_Out[tate][yoko] != 16){
				if (Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH] == 16){
					COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
					printf("　");
				}
				if (Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH] == 0){
					COLOR(L_BLACK, L_BLACK);
					printf("　");
				}
				else{
					COLOR(Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH], Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH]);
					printf("　");
				}
			}
		}
	}


}