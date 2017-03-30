#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player画面表示関数（表面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  Player_Display(int Pt_tate, int Pt_yoko){
	int play_Out[PLAYER_HEIGHT][PLAYER_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_PLAYERFRONTSIDE, "rt+");
	for (int i = 0; i < PLAYER_HEIGHT; i++){
		for (int j = 0; j < PLAYER_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < PLAYER_HEIGHT; tate++){
		for (int yoko = 0; yoko < PLAYER_WIDTH; yoko++){
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
//	Player画面表示関数（裏面）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  PlayerB_Display(int Pt_tate, int Pt_yoko){
	int play_Out[PLAYER_HEIGHT][PLAYER_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_PLAYERBACKSIDE, "rt+");
	for (int i = 0; i < PLAYER_HEIGHT; i++){
		for (int j = 0; j < PLAYER_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < PLAYER_HEIGHT; tate++){
		for (int yoko = 0; yoko < PLAYER_WIDTH; yoko++){
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
//	Player画面表示関数（右側）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  PlayerR_Display(int Pt_tate, int Pt_yoko){
	int play_Out[PLAYER_HEIGHT][PLAYER_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_PLAYERRIGHTSIDE, "rt+");
	for (int i = 0; i < PLAYER_HEIGHT; i++){
		for (int j = 0; j < PLAYER_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < PLAYER_HEIGHT; tate++){
		for (int yoko = 0; yoko < PLAYER_WIDTH; yoko++){
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
//	Player画面表示関数（左側）定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//=========================================================
void  PlayerL_Display(int Pt_tate, int Pt_yoko){
	int play_Out[PLAYER_HEIGHT][PLAYER_WIDTH];		//Player画面変数：横：５；縦：１２

	//Player画面データを読み込む
	FILE *fp;
	fp = fopen(FILENAME_PLAYERLEFTSIDE, "rt+");
	for (int i = 0; i < PLAYER_HEIGHT; i++){
		for (int j = 0; j < PLAYER_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);

	//Player画面データを表示
	for (int tate = 0; tate < PLAYER_HEIGHT; tate++){
		for (int yoko = 0; yoko < PLAYER_WIDTH; yoko++){
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
//	Player画面削除関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）；
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
void  PlayerCL_Display(int Pt_tate, int Pt_yoko, const char   *SCENE){
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

	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	for (int tate = 0; tate < PLAYER_HEIGHT; tate++){
		for (int yoko = 0; yoko < PLAYER_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);

			if (Scene[Pt_tate + tate][Pix_YOKO + yoko] == 16){
				COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
				printf("　");
			}

			if (Scene[Pt_tate + tate][Pix_YOKO + yoko] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
				//Scene[Pt_tate + tate][Pt_yoko + yoko]
				COLOR(L_BLACK, L_BLACK);
				printf("　");
			}

			else{
				COLOR(Scene[Pt_tate + tate][Pix_YOKO + yoko], Scene[Pt_tate + tate][Pix_YOKO + yoko]);
				printf("　");
			}
		}
	}

}

//=========================================================
//	Player上移動関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
int  Player_UPMove(int Pt_tate, int Pt_yoko, const char  *SCENE){
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


	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	//小ジャンプ
	Pt_tate += 1;
	PlayerB_Display(Pt_tate, Pt_yoko);
	WAIT(30);
	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	Pt_tate -= 1;

	Pt_tate -= STRIDE_HEIGHT;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	for (int Jub_Width = 0; Jub_Width < PLAYER_WIDTH; Jub_Width++){
		if (Scene[Pt_tate + HEAD_HEIGHT][Pix_YOKO + Jub_Width] == 0){ Pt_tate += STRIDE_HEIGHT; break; }
	}
	PlayerB_Display(Pt_tate, Pt_yoko);
	//WAIT(30);
	return Pt_tate;
}

//=========================================================
//	Player下移動関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
int  Player_DOWNMove(int Pt_tate, int Pt_yoko, const char  *SCENE){
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

	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	//小ジャンプ
	Pt_tate -= 1;
	Player_Display(Pt_tate, Pt_yoko);
	WAIT(30);
	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);

	Pt_tate += 1;

	Pt_tate += STRIDE_HEIGHT;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	for (int Jub_Width = 0; Jub_Width < PLAYER_WIDTH; Jub_Width++){
		if (Scene[Pt_tate + (PLAYER_HEIGHT - 1)][Pix_YOKO + Jub_Width] == 0){ Pt_tate -= STRIDE_HEIGHT; break; }
	}
	Player_Display(Pt_tate, Pt_yoko);
	//WAIT(30);
	return Pt_tate;
}

//=========================================================
//	Playe左移動関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
int  Player_LEFTMove(int Pt_tate, int Pt_yoko, const char  *SCENE){
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

	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	//小ジャンプ
	Pt_tate -= 1;
	PlayerL_Display(Pt_tate, Pt_yoko);
	WAIT(30);
	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	Pt_tate += 1;

	Pt_yoko -= STRIDE_WIDTH;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	for (int Jub_Height = 0; Jub_Height < (PLAYER_HEIGHT - HEAD_HEIGHT); Jub_Height++){
		if (Scene[Pt_tate + HEAD_HEIGHT + Jub_Height][Pix_YOKO] == 0){ Pt_yoko += STRIDE_WIDTH; break; }
	}
	PlayerL_Display(Pt_tate, Pt_yoko);
	//WAIT(30);
	return Pt_yoko;
}

//=========================================================
//	Playe右移動関数定義
//	引数：int：Pt_tate（画面始める縦）；int：Pt_yoko（画面始める横）
//	引数：const char： SCENE（背景画面の場所）
//=========================================================
int  Player_RIGHTMove(int Pt_tate, int Pt_yoko, const char  *SCENE){
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

	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	//小ジャンプ
	Pt_tate -= 1;
	PlayerR_Display(Pt_tate, Pt_yoko);
	WAIT(30);
	PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
	Pt_tate += 1;

	Pt_yoko += STRIDE_WIDTH;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	for (int Jub_Height = 0; Jub_Height < (PLAYER_HEIGHT - HEAD_HEIGHT); Jub_Height++){
		if (Scene[Pt_tate + HEAD_HEIGHT + Jub_Height][Pix_YOKO + (PLAYER_WIDTH - 1)] == 0){ Pt_yoko -= STRIDE_WIDTH; break; }

	}
	PlayerR_Display(Pt_tate, Pt_yoko);
	//WAIT(30);
	return Pt_yoko;
}