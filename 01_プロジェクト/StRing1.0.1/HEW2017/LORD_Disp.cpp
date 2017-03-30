#include "CScreen.h"
#include "Player.h"


//=========================================================
//	LORD画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  LORDp_Display(int Pt_tate, int Pt_yoko){
	int play_Out[LORD_HEIGHT][LORD_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_LORDFRONTSIDE, "rt+");
	for (int i = 0; i < LORD_HEIGHT; i++){
		for (int j = 0; j < LORD_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
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
//	LORD画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  LORDb_Display(int Pt_tate, int Pt_yoko){
	int play_Out[LORD_HEIGHT][LORD_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_LORDBACKSIDE, "rt+");
	for (int i = 0; i < LORD_HEIGHT; i++){
		for (int j = 0; j < LORD_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
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
//	LORD画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void LORDl_Display(int Pt_tate, int Pt_yoko){
	int play_Out[LORD_HEIGHT][LORD_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_LORDLEFTSIDE, "rt+");
	for (int i = 0; i < LORD_HEIGHT; i++){
		for (int j = 0; j < LORD_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
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
//	LORD画面表示関数（面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  LORDr_Display(int Pt_tate, int Pt_yoko){
	int play_Out[LORD_HEIGHT][LORD_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_LORDRIGHTSIDE, "rt+");
	for (int i = 0; i < LORD_HEIGHT; i++){
		for (int j = 0; j < LORD_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
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
void  LORDCL_Display(int MON_TATE, int MON_YOKO, const char   *SCENE){
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

	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
			LOCATE(MON_YOKO + (2 * yoko), MON_TATE + tate);
			//LOCATE((Pt_yoko/2 + yoko - ATTACK_HEIGHT_WIDTH)*2, Pt_tate + tate);
			//１６の時背景色を表示
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 16){
				COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
				printf("　");
			}
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
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
int*	LORD_MOVE(int MON_TATE, int MON_YOKO, const char   *SCENE, int SIWITCH){
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

	LORDCL_Display(MON_TATE, MON_YOKO, SCENE);

	while (END == 0)
	{

		switch (SIWITCH)
		{
		case 0://W
			MON_TATE -= LORD_STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < LORD_WIDTH*2; Jub_Width++){
				if (Scene[MON_TATE][Pix_YOKO + Jub_Width] == 0){
					MON_TATE += LORD_STRIDE_HEIGHT;
					SIWITCH = 1;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDb_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 1://D
			MON_YOKO += LORD_STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2);
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2);
			}
			for (int Jub_Height = 0; Jub_Height < LORD_HEIGHT; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO + 2] == 0){
					MON_YOKO -= LORD_STRIDE_WIDTH;
					SIWITCH = 2;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDr_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 2://S
			MON_TATE += LORD_STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < LORD_WIDTH*2; Jub_Width++){
				if (Scene[MON_TATE + 2][Pix_YOKO + Jub_Width] == 0){
					MON_TATE -= LORD_STRIDE_HEIGHT;
					SIWITCH = 3;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDp_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 3://A
			MON_YOKO -= LORD_STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2);
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2);
			}
			for (int Jub_Height = 0; Jub_Height < LORD_HEIGHT; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO] == 0){
					MON_YOKO += LORD_STRIDE_WIDTH;
					SIWITCH = 0;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDl_Display(MON_TATE, MON_YOKO);
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

void LORD_HP(int HP){
	for (int i=0; i < 10; i++){
		LOCATE(11 + i * 22, 78);
		COLOR(0, 0);
		printf("　　　　　　　　　　　");
		LOCATE(11 + i * 22, 79);
		COLOR(0, 0);
		printf("　　　　　　　　　　　");
	}
	if (HP <= 10){
		for (int i = 0; i < HP; i++){
			LOCATE(11 + i * 22, 78);
			COLOR(12, 12);
			printf("　　　　　　　　　　　");
			LOCATE(11 + i * 22, 79);
			printf("　　　　　　　　　　　");
		}
	}
	else if (HP <= 20)
	{
		for (int i = 0; i < 10; i++){
			LOCATE(11 + i * 22, 78);
			COLOR(12, 12);
			printf("　　　　　　　　　　　");
			LOCATE(11 + i * 22, 79);
			printf("　　　　　　　　　　　");
		}
		for (int i = 0; i < (HP-10); i++){
			LOCATE(11 + i * 22, 78);
			COLOR(14, 14);
			printf("　　　　　　　　　　　");
			LOCATE(11 + i * 22, 79);
			printf("　　　　　　　　　　　");
		}
	}
	else{
		for (int i = 0; i < 10; i++){
			LOCATE(11 + i * 22, 78);
			COLOR(14, 14);
			printf("　　　　　　　　　　　");
			LOCATE(11 + i * 22, 79);
			printf("　　　　　　　　　　　");
		}
		for (int i = 0; i < (HP - 20); i++){
			LOCATE(11 + i * 22, 78);
			COLOR(10, 10);
			printf("　　　　　　　　　　　");
			LOCATE(11 + i * 22, 79);
			printf("　　　　　　　　　　　");
		}
	}

}

void	LordMissShow(int Lord_x, int Lord_y, const char *SCENE){
	int play_Out[LORD_HEIGHT][LORD_WIDTH]; //Player画面変数：横：7；縦：7

	FILE *fp;
	fp = fopen(FILENAME_LORDFRONTSIDE, "rt+");
	for (int i = 0; i < LORD_HEIGHT; i++){
		for (int j = 0; j < LORD_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player画面データを表示
	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
			LOCATE(Lord_x + (2 * yoko), Lord_y + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(15, 15);
				printf("　");
			}
		}
	}
	WAIT(80);

	for (int tate = 0; tate < LORD_HEIGHT; tate++){
		for (int yoko = 0; yoko < LORD_WIDTH; yoko++){
			LOCATE(Lord_x + (2 * yoko), Lord_y + tate);
			//１６の時背景色を表示

			if (play_Out[tate][yoko] != 16){
				COLOR(15,15);
				printf("　");
			}
		}

	}

	WAIT(80);
	LORDCL_Display(Lord_y, Lord_x, SCENE);
}