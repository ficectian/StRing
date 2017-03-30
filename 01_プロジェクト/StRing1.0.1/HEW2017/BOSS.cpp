#include "CScreen.h"
#include "Player.h"


//=========================================================
//	Player画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  BOSSp_Display(int Pt_tate, int Pt_yoko){
	int play_Out[BOSS_HEIGHT][BOSS_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_BOSSFRONTSIDE, "rt+");
	for (int i = 0; i < BOSS_HEIGHT; i++){
		for (int j = 0; j < BOSS_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

//=========================================================
//	BOSS画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  BOSSb_Display(int Pt_tate, int Pt_yoko){
	int play_Out[BOSS_HEIGHT][BOSS_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_BOSSBACKSIDE, "rt+");
	for (int i = 0; i < BOSS_HEIGHT; i++){
		for (int j = 0; j < BOSS_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

//=========================================================
//	BOSS画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  BOSSl_Display(int Pt_tate, int Pt_yoko){
	int play_Out[BOSS_HEIGHT][BOSS_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_BOSSLEFTSIDE, "rt+");
	for (int i = 0; i < BOSS_HEIGHT; i++){
		for (int j = 0; j < BOSS_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}

//=========================================================
//	BOSS画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  BOSSr_Display(int Pt_tate, int Pt_yoko){
	int play_Out[BOSS_HEIGHT][BOSS_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_BOSSRIGHTSIDE, "rt+");
	for (int i = 0; i < BOSS_HEIGHT; i++){
		for (int j = 0; j < BOSS_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("　");
			}
		}

	}
}


//= == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
//	Player画面削除関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）；
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
void  BOSSCL_Display(int MON_TATE, int MON_YOKO, const char   *SCENE){
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int Pix_YOKO;

	FILE *fp2;
	fp2 = fopen(SCENE, "rt+");
	for (int i = 0; i < WINDOWS_HEIGHT; i++){
		for (int j = 0; j < WINDOWS_WIDTH; j++){
			fscanf_s(fp2, "%d,", &Scene[i][j]);
		}
	}
	fclose(fp2);

	if (MON_YOKO % 2 != 0){
		Pix_YOKO = ((MON_YOKO + 1) / 2);
	}
	else
	{
		Pix_YOKO = (MON_YOKO / 2);
	}

	for (int tate = 0; tate < BOSS_HEIGHT; tate++){
		for (int yoko = 0; yoko < BOSS_WIDTH; yoko++){
			LOCATE(MON_YOKO + (2 * yoko), MON_TATE + tate);
			//LOCATE((Pt_yoko/2 + yoko - ATTACK_HEIGHT_WIDTH)*2, Pt_tate + tate);
			//１６の時背景色を表示
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 16){
				COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
				printf("　");
			}
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
				//Scene[Pt_tate + tate][Pt_yoko + yoko]
				COLOR(L_BLACK, L_BLACK);
				printf("　");
			}
			else{
				COLOR(Scene[MON_TATE + tate][Pix_YOKO + yoko], Scene[MON_TATE + tate][Pix_YOKO + yoko]);
				printf("　");
			}
		}
	}


}

//=========================================================
//	Player画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
int*	BOSS_MOVE(int MON_TATE, int MON_YOKO, const char   *SCENE, int SIWITCH){
	int Pix_YOKO;
	static int R[3];
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int END = 0;
	int JUB_END = 0;
	if (MON_YOKO % 2 != 0){
		Pix_YOKO = ((MON_YOKO + 1) / 2);
	}
	else
	{
		Pix_YOKO = (MON_YOKO / 2);
	}


	FILE *fp2;
	fp2 = fopen(SCENE, "rt+");
	for (int i = 0; i < WINDOWS_HEIGHT; i++){
		for (int j = 0; j < WINDOWS_WIDTH; j++){
			fscanf_s(fp2, "%d,", &Scene[i][j]);
		}
	}
	fclose(fp2);

	BOSSCL_Display(MON_TATE, MON_YOKO, SCENE);

	while (END == 0)
	{

		switch (SIWITCH)
		{
		case 0://W
			MON_TATE -= STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < BOSS_WIDTH; Jub_Width++){
				if (Scene[MON_TATE][Pix_YOKO + Jub_Width] == 0){
					MON_TATE += STRIDE_HEIGHT;
					SIWITCH = 1;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				BOSSb_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 1://D
			MON_YOKO += STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2)-1;
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2)-1;
			}
			for (int Jub_Height = 0; Jub_Height < BOSS_HEIGHT; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO + 2] == 0){
					MON_YOKO -= STRIDE_WIDTH;
					SIWITCH = 2;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				BOSSr_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 2://S
			MON_TATE += STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < BOSS_WIDTH; Jub_Width++){
				if (Scene[MON_TATE + 2][Pix_YOKO + Jub_Width] == 0){
					MON_TATE -= STRIDE_HEIGHT;
					SIWITCH = 3;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				BOSSp_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 3://A
			MON_YOKO -= STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2);
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2);
			}
			for (int Jub_Height = 0; Jub_Height < BOSS_HEIGHT; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO] == 0){
					MON_YOKO += STRIDE_WIDTH;
					SIWITCH = 0;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				BOSSl_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		default:
			break;
		}
		//if (END = 1){ break; }

	}

	*R = MON_TATE;
	*(R + 1) = MON_YOKO;
	*(R + 2) = SIWITCH;
	return R;
}

int	BOSS_Side(int pt_tate, int pt_yoko, int MonTATE,int MonYOKO, int Side){
	int P;
	P = rand() % 2;
	if (pt_tate >= MonTATE && pt_yoko >= MonYOKO){
		switch (P)
		{
		case 0:
			Side = 1;
			break;
		case 1:
			Side = 2;
			break;
		default:
			break;
		}
	}
	else if (pt_tate >= MonTATE && pt_yoko < MonYOKO)
	{
		switch (P)
		{
		case 0:
			Side = 3;
			break;
		case 1:
			Side = 2;
			break;
		default:
			break;
		}
	}
	else if (pt_tate < MonTATE && pt_yoko < MonYOKO)
	{
		switch (P)
		{
		case 0:
			Side = 3;
			break;
		case 1:
			Side = 0;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (P)
		{
		case 0:
			Side = 1;
			break;
		case 1:
			Side = 0;
			break;
		default:
			break;
		}
	}
	return Side;
}