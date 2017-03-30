#include "CScreen.h"
#include "Player.h"
#include	"main.h"
//============================================================
//	グローバル変数宣言
//============================================================
/*
float FPS = 60.0f;									//FPS変数確保し60を設定
float WAIT_TIME = FPS / 1000.0f;

//PLAYER player = { 10, 10 };							//PLAYER構造体変数player確保

HANDLE consoleHandle1;								//コンソールハンドル１
HANDLE consoleHandle2;								//コンソールハンドル２

CONSOLE_CURSOR_INFO CursorInfo;						//コンソール・カーソル情報変数確保
CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;				//コンソール・スクリーン・バッファ情報変数確保

bool Swap = false;									//コンソールの繰り替え情報
*/
void main(){
	int				switch_on;																//プログラムのモード
	const char   *	SCENE;																	//背景の場所
	int				Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];									//背景本体（MAIN）
	int				Back_Save = Play_Title;													//セーブポイント
	int				JUB_MOD;																//ゲーム循環回数
	int				Scene_No;																//ゲームマップの番号
	int				Background;																//ゲーム背景音楽
	int				END_JUB = 0;
	int				MOD_END = 0;
	int				Monster_Have = 0;
	int				LEFT_X;
	int				RIGHT_X;
	int				UP_Y;
	int				DOWN_Y;
	int				LORD_Miss = 0;
	int				LordMissTime = 0;
	int				JubInMissTime = 0;
	int				PixelXInMissTime = 0;
	int				LordHpInMissTime;
	Player		player[1];
	obstacle	Obstacle[2];
	Monster	MONSTER[2];
	Monster	Boss;
	int *P;
	int *Pt;
	int Monster_No;
	int Boss_No;
	player[0].HP = 6;
	system("mode con cols=240 lines=80");			//ゲームウィンドウズサイズ設定
	system("title StRing");
	

	KEYCLEAR();                         // キーボードを初期化する 
	switch_on = Play_Title;
	//switch_on = Player_Scene7;
	SCENE = 0;
	srand((unsigned)time(0));

	while (switch_on != END)
	{
		switch (switch_on){
		case Play_Title:
			Background = OPENMIDI(FILENAME_OPENMUS);
			PLAYMIDI(Background);

			Title();
			STOPMIDI(Background);
			CLOSEMIDI(Background);
			switch_on = Player_Scene1;
			break;
		case Player_Scene1:
			Scene_No = 1;
			player[0].TATE = 22;
			player[0].YOKO = 76;
			player[0].SIDE = SIDE_DOWN;
			LEFT_X = 36 * 2;
			RIGHT_X = 113 * 2;
			UP_Y = 16;
			DOWN_Y = 73;
			SCENE = FILENAME_SCENE1;
			Background = OPENMIDI(FILENAME_NOMMUS);
			FILE *fp;
			fp = fopen(FILENAME_SCENE1, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp);
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			PLAYMIDI(Background);
			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);
			switch_on = Player_Game;
			break;

		case Player_Scene2:
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			Scene_No = 2;
			player[0].TATE = 73 - PLAYER_HEIGHT;
			player[0].YOKO = 204;
			LEFT_X = 8 * 2;
			RIGHT_X = 112 * 2;
			UP_Y = 9;
			DOWN_Y = 73;
			Obstacle[0].HP = 2;
			Obstacle[0].tate = 50;
			Obstacle[0].yoko = 110;
			Obstacle[1].HP = 2;
			Obstacle[1].tate = 22;
			Obstacle[1].yoko = 110;
			SCENE = FILENAME_SCENE2;
			FILE *fp2;
			fp2 = fopen(FILENAME_SCENE2, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp2, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp2);

			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);
			switch_on = Player_Game;
			Obstacle_Display(Obstacle[0].tate, Obstacle[0].yoko);
			Obstacle_Display(Obstacle[1].tate, Obstacle[1].yoko);

			break;

		case Player_Scene3:
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			Back_Save = Player_Scene3;
			Scene_No = 3;
			
			player[0].TATE = 31;
			player[0].YOKO = 15;
			player[0].HP = 6;
			MONSTER[0].yoko = 40;
			MONSTER[0].tate = 40;
			MONSTER[0].HP = 3;
			MONSTER[0].SIDE = 1;
			MONSTER[1].yoko = 200;
			MONSTER[1].tate = 25;
			MONSTER[1].HP = 3;
			MONSTER[1].SIDE = 3;
			LEFT_X = 3 * 2;
			RIGHT_X = 117 * 2;
			UP_Y = 8;
			DOWN_Y = 77;
			Boss.tate = 35;
			Boss.yoko = 151;
			Boss.HP = 8;
			Boss.SIDE = 0;

			SCENE = FILENAME_SCENE3;
			Background = OPENMIDI(FILENAME_ATTMUS);
			FILE *fp3;
			fp3 = fopen(FILENAME_SCENE3, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp3, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp3);
			PLAYMIDI(Background, 1);
			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);
			HP_Disp(player[0].HP);
			switch_on = Player_Game;
			

			break;

		case Player_Scene4:
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			Scene_No = 4;
			MOD_END = 0;
			player[0].TATE = 73 - PLAYER_HEIGHT;
			player[0].YOKO = 204;
			player[0].HP += 3;
			if (player[0].HP > 6){ player[0].HP = 6; }
			END_JUB = 0;
			LEFT_X = 6 * 2;
			RIGHT_X = 115 * 2;
			UP_Y = 7;
			DOWN_Y = 75;
			
			//Boss_No = 2;
			Monster	MONSTER_3[6];
			Monster	Boss_3[2];

			
			//Background = OPENMIDI(FILENAME_ATTMUS);
			//PLAYMIDI(Background);
			SCENE = FILENAME_SCENE4;

			fp3 = fopen(FILENAME_SCENE4, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp3, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp3);
			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);

			Monster_No = rand() % 5 + 1;
			if (Monster_No < 4){
				Boss_No = rand() % 2 + 1;
			}
			else{
				Boss_No = 0;
			}
			for (int i =0 ; i < Monster_No; i++){
				
				int WHILE_JUB = 1;
				int Pix_YOKO;

				while (WHILE_JUB == 1)
				{
					WHILE_JUB = 0;
					MONSTER_3[i].yoko = rand() % (player[0].YOKO - 20) + 12;
					MONSTER_3[i].tate = rand() % (player[0].TATE - 8) + 6;
					MONSTER_3[i].SIDE = rand() % 4;
					MONSTER_3[i].HP = 3;

					if (MONSTER_3[i].yoko % 2 != 0){
						Pix_YOKO = ((MONSTER_3[i].yoko + 1) / 2);
					}
					else
					{
						Pix_YOKO = (MONSTER_3[i].yoko / 2);
					}

					for (int Jub_Height = 0; Jub_Height < 3; Jub_Height++){
						for (int Jub_Width = 0; Jub_Width < 3; Jub_Width++){
							if (Scene[MONSTER_3[i].tate][Pix_YOKO + Jub_Width] == 0)
							{
								WHILE_JUB = 1;
								break;
							}
						}
					}
					
				}
				
			}

			if (Boss_No > 0){

				for (int i = 0; i < Boss_No; i++){
					int WHILE_JUB = 1;
					int Pix_YOKO;
					while (WHILE_JUB == 1)
					{
						WHILE_JUB = 0;
						Boss_3[i].yoko = rand() % (player[0].YOKO - 20) + 12;
						Boss_3[i].tate = rand() % (player[0].TATE - 8) + 6;
						Boss_3[i].SIDE = rand() % 4;
						Boss_3[i].HP = 6;
						if (Boss_3[i].yoko % 2 != 0){
							Pix_YOKO = ((Boss_3[i].yoko + 1) / 2);
						}
						else
						{
							Pix_YOKO = (Boss_3[i].yoko / 2);
						}
						for (int Jub_Height = 0; Jub_Height < BOSS_HEIGHT; Jub_Height++){
							for (int Jub_Width = 0; Jub_Width < BOSS_WIDTH; Jub_Width++){
								if (Scene[Boss_3[i].tate][Pix_YOKO + Jub_Width] == 0)
								{
									WHILE_JUB = 1;
									break;
								}
								if (WHILE_JUB == 1){ break; }
							}
						}
					}
				}
			}

			
			
			HP_Disp(player[0].HP);
			switch_on = Player_Game;


			break;

		case Player_Scene5:
				SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
				Scene_No = 5;
				MOD_END = 0;
				player[0].TATE = 31;
				player[0].YOKO = 110*2;
				player[0].HP += 3;
				if (player[0].HP > 6){ player[0].HP = 6; }
				END_JUB = 0;
				LEFT_X = 6 * 2;
				RIGHT_X = 116 * 2;
				UP_Y = 7;
				DOWN_Y = 75;
				Monster_No = rand() % 4 + 5;
				
				//Boss_No = 2;
				Monster	MONSTER_5[16];


				//Background = OPENMIDI(FILENAME_ATTMUS);
				//PLAYMIDI(Background);
				SCENE = FILENAME_SCENE5;

				fp3 = fopen(FILENAME_SCENE5, "rt+");
				for (int i = 0; i < WINDOWS_HEIGHT; i++){
					for (int j = 0; j < WINDOWS_WIDTH; j++){
						fscanf_s(fp3, "%d,", &Scene[i][j]);
					}
				}
				fclose(fp3);
				Scene_Disp(*Scene);
				Player_Display(player[0].TATE, player[0].YOKO);

				for (int i = 0; i < Monster_No; i++){

					int WHILE_JUB = 1;
					int Pix_YOKO;

					while (WHILE_JUB == 1)
					{
						WHILE_JUB = 0;
						MONSTER_5[i].yoko = rand() % (player[0].YOKO - 30) + 12;
						MONSTER_5[i].tate = rand() % 64 + 6;
						MONSTER_5[i].SIDE = rand() % 4;
						MONSTER_5[i].HP = 3;

						if (MONSTER_5[i].yoko % 2 != 0){
							Pix_YOKO = ((MONSTER_5[i].yoko + 1) / 2);
						}
						else
						{
							Pix_YOKO = (MONSTER_5[i].yoko / 2);
						}

						for (int Jub_Height = 0; Jub_Height < 3; Jub_Height++){
							for (int Jub_Width = 0; Jub_Width < 3; Jub_Width++){
								if (Scene[MONSTER_5[i].tate][Pix_YOKO + Jub_Width] == 0)
								{
									WHILE_JUB = 1;
									break;
								}
							}
						}

					}

				}

				

				HP_Disp(player[0].HP);
				switch_on = Player_Game;


				break;

		case Player_Scene6:
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			Scene_No = 6;
			MOD_END = 0;
			player[0].TATE = 31;
			player[0].YOKO = 110 * 2;
			player[0].HP += 3;
			if (player[0].HP > 6){ player[0].HP = 6; }
			END_JUB = 0;
			LEFT_X = 6 * 2;
			RIGHT_X = 115 * 2;
			UP_Y = 7;
			DOWN_Y = 75;
			Boss_No = rand() % 3 + 3;

			Monster	Boss_6[8];

			SCENE = FILENAME_SCENE6;

			fp3 = fopen(FILENAME_SCENE6, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp3, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp3);
			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);

			for (int i = 0; i < Boss_No; i++){
				int WHILE_JUB = 1;
				int Pix_YOKO;
				while (WHILE_JUB == 1)
				{
					WHILE_JUB = 0;
					Boss_6[i].yoko = rand() % (player[0].YOKO - 30) + 12;
					Boss_6[i].tate = rand() % 63 + 6;
					Boss_6[i].SIDE = rand() % 4;
					Boss_6[i].HP = 6;
					if (Boss_6[i].yoko % 2 != 0){
						Pix_YOKO = ((Boss_6[i].yoko + 1) / 2);
					}
					else
					{
						Pix_YOKO = (Boss_6[i].yoko / 2);
					}
					for (int Jub_Height = 0; Jub_Height < BOSS_HEIGHT; Jub_Height++){
						for (int Jub_Width = 0; Jub_Width < BOSS_WIDTH; Jub_Width++){
							if (Scene[Boss_6[i].tate][Pix_YOKO + Jub_Width] == 0)
							{
								WHILE_JUB = 1;
								break;
							}
							if (WHILE_JUB == 1){ break; }
						}
					}
				}
			}



			HP_Disp(player[0].HP);
			switch_on = Player_Game;


			break;

		case Player_Scene7:
			SCREENCLS(BACKGROUND_COLOR, BACKGROUND_COLOR);
			Back_Save = Player_Scene7;
			Scene_No = 7;
			MOD_END = 0;
			player[0].TATE = 77-PLAYER_HEIGHT;
			player[0].YOKO = 56 * 2;
			player[0].HP = 6;
			//if (player[0].HP > 6){ player[0].HP = 6; }
			END_JUB = 0;
			LEFT_X = 3 * 2;
			RIGHT_X = 118 * 2;
			UP_Y = 8;
			DOWN_Y = 75;
			Monster	LORD;
			LORD.yoko = 77 * 2;
			LORD.tate = 35;
			LORD.HP = 30;
			LORD.SIDE = 2;
			Monster MONSTER_7[4];
			Monster BOSS_7[3];
			Background = OPENMIDI(FILENAME_BOSSMUS);
			PLAYMIDI(Background, 1);
			SCENE = FILENAME_SCENE7;

			fp3 = fopen(FILENAME_SCENE7, "rt+");
			for (int i = 0; i < WINDOWS_HEIGHT; i++){
				for (int j = 0; j < WINDOWS_WIDTH; j++){
					fscanf_s(fp3, "%d,", &Scene[i][j]);
				}
			}
			fclose(fp3);
			Scene_Disp(*Scene);
			Player_Display(player[0].TATE, player[0].YOKO);
			HP_Disp(player[0].HP);
			LORD_HP(LORD.HP);
			switch_on = Player_Game;


			break;
		case Player_Game:
			srand((unsigned)time(0));
			//SIWITCH = rand() % 4;
			JUB_MOD = 0;
			rewind(stdin);						//キーボード入力クリア
			
			while (MOD_END == 0){
				JUB_MOD += 1;
				if (JUB_MOD > 32767){ JUB_MOD = 0; }
				
				
				


				if (Scene_No == 1){
					//終わり判定
					if (player[0].TATE + PLAYER_HEIGHT > DOWN_Y){
						switch_on = Player_Scene2;
						break;
					}
					/*if (((player[0].TATE - END_TATE) >= 0 && (player[0].TATE - END_TATE) <= END_HEIGHT) || ((END_TATE - player[0].TATE) >= 0 && (END_TATE - player[0].TATE) <= END_HEIGHT)){
						if (((player[0].YOKO - END_YOKO) >= 0 && (player[0].YOKO - END_YOKO) <= END_WIDTH) || ((END_YOKO - player[0].YOKO) >= 0 && (END_YOKO - player[0].YOKO) <= END_WIDTH)){
							switch_on = Player_Scene2;
							break;
						}
					}*/
				}

				else if (Scene_No == 2){
					for (int i = 0; i < 2; i++){
						if (Obstacle[i].HP > 0){
							Pt = Obstacle_Obs(player[0].TATE, player[0].YOKO, Obstacle[i].tate, Obstacle[i].yoko, player[0].SIDE, SCENE);
							player[0].TATE = *Pt;
							player[0].YOKO = *(Pt + 1);
						}
					}

					//終わり判定
					if (player[0].YOKO < LEFT_X){
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						switch_on = Player_Scene3;
						break;
					}
					/*if (((player[0].TATE - END_TATE) >= 0 && (player[0].TATE - END_TATE) <= END_HEIGHT) || ((END_TATE - player[0].TATE) >= 0 && (END_TATE - player[0].TATE) <= END_HEIGHT)){
						if (((player[0].YOKO - END_YOKO) >= 0 && (player[0].YOKO - END_YOKO) <= END_WIDTH) || ((END_YOKO - player[0].YOKO) >= 0 && (END_YOKO - player[0].YOKO) <= END_WIDTH)){
							STOPMIDI(Background);
							CLOSEMIDI(Background);
							switch_on = Player_Scene3;
							break;
						}
					}*/
				}

				else if (Scene_No == 3){
					if (MONSTER[0].HP > 0){
						if (JUB_MOD % 3 == 0){
							P = Monster_MOVE(MONSTER[0].tate, MONSTER[0].yoko, SCENE, player[0].SIDE);
							MONSTER[0].tate = *P;
							MONSTER[0].yoko = *(P + 1);
							MONSTER[0].SIDE = *(P + 2);
						}
						if (JUB_MOD % 50 == 0){
							MONSTER[0].SIDE = rand() % 4;
						}
						P = Monster_Injured(player[0].TATE, player[0].YOKO, MONSTER[0].tate, MONSTER[0].yoko, player[0].HP, MONSTER[0].SIDE, SCENE);
						player[0].TATE = *P;
						player[0].YOKO = *(P + 1);
						MONSTER[0].SIDE = *(P + 2);
						player[0].HP = *(P + 3);
					}
					if (MONSTER[1].HP > 0){
						if (JUB_MOD % 3 == 0){
							P = Monster_MOVE(MONSTER[1].tate, MONSTER[1].yoko, SCENE, MONSTER[1].SIDE);
							MONSTER[1].tate = *P;
							MONSTER[1].yoko = *(P + 1);
							MONSTER[1].SIDE = *(P + 2);
						}
						if (JUB_MOD % 50 == 0){
							MONSTER[1].SIDE = rand() % 4;
						}
						P = Monster_Injured(player[0].TATE, player[0].YOKO, MONSTER[1].tate, MONSTER[1].yoko, player[0].HP, MONSTER[1].SIDE, SCENE);
						player[0].TATE = *P;
						player[0].YOKO = *(P + 1);
						MONSTER[1].SIDE = *(P + 2);
						player[0].HP = *(P + 3);
					}
					if (Boss.HP > 0){
						if (JUB_MOD % 3 == 0){
							P = BOSS_MOVE(Boss.tate, Boss.yoko, SCENE, Boss.SIDE);
							Boss.tate = *P;
							Boss.yoko = *(P + 1);
							Boss.SIDE = *(P + 2);
						}
						P = BOSS_Injured(player[0].TATE, player[0].YOKO, Boss.tate, Boss.yoko, player[0].HP, Boss.SIDE, SCENE);
						player[0].TATE = *P;
						player[0].YOKO = *(P + 1);
						Boss.SIDE = *(P + 2);
						player[0].HP = *(P + 3);

						if (JUB_MOD % 10 == 0){
							Boss.SIDE = BOSS_Side(player[0].TATE, player[0].YOKO, Boss.tate, Boss.yoko, Boss.SIDE);
						}
					}
					if (player[0].HP <= 0){
						switch_on = GameOver;
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						break;
					}
					if (Boss.HP <= 0 && MONSTER[0].HP <= 0 && MONSTER[1].HP <= 0){
						END_JUB = 1;
						
						//break;
					}
					//終わり判定
					if (END_JUB != 0){
						if (player[0].TATE + PLAYER_HEIGHT > DOWN_Y){
							switch_on = Player_Scene4;
							MOD_END = 1;
							break;
						}
					}
				}//no=3

				else if (Scene_No == 4){
					for (int i = 0; i < Monster_No; i++){
						if (MONSTER_3[i].HP > 0){
							if (JUB_MOD % 3 == 0){
								P = Monster_MOVE(MONSTER_3[i].tate, MONSTER_3[i].yoko, SCENE, MONSTER_3[i].SIDE);
								MONSTER_3[i].tate = *P;
								MONSTER_3[i].yoko = *(P + 1);
								MONSTER_3[i].SIDE = *(P + 2);
								P = MonsterOutOfRange(MONSTER_3[i].yoko, MONSTER_3[i].tate, MONSTER_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
								MONSTER_3[i].yoko = *P;
								MONSTER_3[i].tate = *(P + 1);
								MONSTER_3[i].SIDE = *(P + 2);
							}//if
							if (JUB_MOD % 50 == 0){
								MONSTER_3[i].SIDE = rand() % 4;
							}//if
							P = Monster_Injured(player[0].TATE, player[0].YOKO, MONSTER_3[i].tate, MONSTER_3[i].yoko, player[0].HP, MONSTER_3[i].SIDE, SCENE);
							player[0].TATE = *P;
							player[0].YOKO = *(P + 1);
							MONSTER_3[i].SIDE = *(P + 2);
							player[0].HP = *(P + 3);
							P = MonsterOutOfRange(MONSTER_3[i].yoko, MONSTER_3[i].tate, MONSTER_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
							MONSTER_3[i].yoko = *P;
							MONSTER_3[i].tate = *(P + 1);
							MONSTER_3[i].SIDE = *(P + 2);
						}//if
					}//for


					if (Boss_No > 0){
						for (int i = 0; i < Boss_No; i++){
							if (Boss_3[i].HP > 0){
								if (JUB_MOD % 3 == 0){
									P = BOSS_MOVE(Boss_3[i].tate, Boss_3[i].yoko, SCENE, Boss_3[i].SIDE);
									Boss_3[i].tate = *P;
									Boss_3[i].yoko = *(P + 1);
									Boss_3[i].SIDE = *(P + 2);
									if (Boss_3[i].HP > 0){
										P = BossOutOfRange(Boss_3[i].yoko, Boss_3[i].tate, Boss_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										Boss_3[i].yoko = *P;
										Boss_3[i].tate = *(P + 1);
										Boss_3[i].SIDE = *(P + 2);
									}
								}//if
								P = BOSS_Injured(player[0].TATE, player[0].YOKO, Boss_3[i].tate, Boss_3[i].yoko, player[0].HP, Boss_3[i].SIDE, SCENE);
								player[0].TATE = *P;
								player[0].YOKO = *(P + 1);
								Boss_3[i].SIDE = *(P + 2);
								player[0].HP = *(P + 3);
								if (Boss_3[i].HP > 0){
									P = BossOutOfRange(Boss_3[i].yoko, Boss_3[i].tate, Boss_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									Boss_3[i].yoko = *P;
									Boss_3[i].tate = *(P + 1);
									Boss_3[i].SIDE = *(P + 2);
								}
								if (JUB_MOD % 10 == 0){
									Boss_3[i].SIDE = BOSS_Side(player[0].TATE, player[0].YOKO, Boss_3[i].tate, Boss_3[i].yoko, Boss_3[i].SIDE);
								}//if
							}//if
						}//for
					}//if


					if (player[0].HP <= 0){
						switch_on = GameOver;
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						break;
					}//if

					if (END_JUB == 0){
						END_JUB = 1;
						for (int i = 0; i < Monster_No; i++){
							if (MONSTER_3[i].HP > 0){
								END_JUB = 0;
								break;
							}//if
						}//for
						if (Boss_No > 0){
							for (int i = 0; i < Boss_No; i++){
								if (Boss_3[i].HP > 0){
									END_JUB = 0;
									break;
								}//if
							}//for
						}//if

					}//end_jub==0
					//終わり判定
					if (END_JUB != 0){
						
						if (player[0].YOKO < LEFT_X){		
							switch_on = Player_Scene5;
							MOD_END = 1;
							break;
						}
					}
				}//==4

				else if (Scene_No == 5){
					for (int i = 0; i < Monster_No; i++){
						if (MONSTER_5[i].HP > 0){
							if (JUB_MOD % 3 == 0){
								P = Monster_MOVE(MONSTER_5[i].tate, MONSTER_5[i].yoko, SCENE, MONSTER_5[i].SIDE);
								MONSTER_5[i].tate = *P;
								MONSTER_5[i].yoko = *(P + 1);
								MONSTER_5[i].SIDE = *(P + 2);
								P = MonsterOutOfRange(MONSTER_5[i].yoko, MONSTER_5[i].tate, MONSTER_5[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
								MONSTER_5[i].yoko = *P;
								MONSTER_5[i].tate = *(P + 1);
								MONSTER_5[i].SIDE = *(P + 2);
							}//if
							if (JUB_MOD % 50 == 0){
								MONSTER_5[i].SIDE = rand() % 4;
							}//if
							P = Monster_Injured(player[0].TATE, player[0].YOKO, MONSTER_5[i].tate, MONSTER_5[i].yoko, player[0].HP, MONSTER_5[i].SIDE, SCENE);
							player[0].TATE = *P;
							player[0].YOKO = *(P + 1);
							MONSTER_5[i].SIDE = *(P + 2);
							player[0].HP = *(P + 3);
							P = MonsterOutOfRange(MONSTER_5[i].yoko, MONSTER_5[i].tate, MONSTER_5[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
							MONSTER_5[i].yoko = *P;
							MONSTER_5[i].tate = *(P + 1);
							MONSTER_5[i].SIDE = *(P + 2);
						}//if
					}//for


				

					if (player[0].HP <= 0){
						switch_on = GameOver;
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						break;
					}//if

					if (END_JUB == 0){
						END_JUB = 1;
						for (int i = 0; i < Monster_No; i++){
							if (MONSTER_5[i].HP > 0){
								END_JUB = 0;
								break;
							}//if
						}//for
						
					}//end_jub==0
					//終わり判定
					if (END_JUB != 0){

						if (player[0].YOKO < LEFT_X){
							//STOPMIDI(Background);
							//CLOSEMIDI(Background);
							switch_on = Player_Scene6;
							MOD_END = 1;
							break;
						}
					}
				}//==5
			
				else if (Scene_No == 6){
					


					
						for (int i = 0; i < Boss_No; i++){
							if (Boss_6[i].HP > 0){
								if (JUB_MOD % 3 == 0){
									P = BOSS_MOVE(Boss_6[i].tate, Boss_6[i].yoko, SCENE, Boss_6[i].SIDE);
									Boss_6[i].tate = *P;
									Boss_6[i].yoko = *(P + 1);
									Boss_6[i].SIDE = *(P + 2);
									if (Boss_6[i].HP > 0){
										P = BossOutOfRange(Boss_6[i].yoko, Boss_6[i].tate, Boss_6[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										Boss_6[i].yoko = *P;
										Boss_6[i].tate = *(P + 1);
										Boss_6[i].SIDE = *(P + 2);
									}
								}//if
								P = BOSS_Injured(player[0].TATE, player[0].YOKO, Boss_6[i].tate, Boss_6[i].yoko, player[0].HP, Boss_6[i].SIDE, SCENE);
								player[0].TATE = *P;
								player[0].YOKO = *(P + 1);
								Boss_6[i].SIDE = *(P + 2);
								player[0].HP = *(P + 3);
								if (Boss_6[i].HP > 0){
									P = BossOutOfRange(Boss_6[i].yoko, Boss_6[i].tate, Boss_6[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									Boss_6[i].yoko = *P;
									Boss_6[i].tate = *(P + 1);
									Boss_6[i].SIDE = *(P + 2);
								}
								if (JUB_MOD % 10 == 0){
									Boss_6[i].SIDE = BOSS_Side(player[0].TATE, player[0].YOKO, Boss_6[i].tate, Boss_6[i].yoko, Boss_6[i].SIDE);
								}//if
							}//if
						}//for
				


					if (player[0].HP <= 0){
						switch_on = GameOver;
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						break;
					}//if

					if (END_JUB == 0){
						END_JUB = 1;
						for (int i = 0; i < Boss_No; i++){
								if (Boss_6[i].HP > 0){
									END_JUB = 0;
									break;
								}//if
							}//for
					}//end_jub==0
					//終わり判定
					if (END_JUB != 0){
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						if (player[0].TATE+PLAYER_HEIGHT > DOWN_Y){
							
							switch_on = Player_Scene7;
							MOD_END = 1;
							break;
						}
					}
				}//==6
				else if (Scene_No == 7){
					if (LORD_Miss == 0){
						if (JUB_MOD % 4 == 0){
							P = LORD_MOVE(LORD.tate, LORD.yoko, SCENE, LORD.SIDE);
							LORD.tate = *P;
							LORD.yoko = *(P + 1);
							LORD.SIDE = *(P + 2);
							if (LORD.HP > 0){
								P = LordOutOfRange(LORD.yoko, LORD.tate, LORD.SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
								LORD.yoko = *P;
								LORD.tate = *(P + 1);
								LORD.SIDE = *(P + 2);
							}
						}

						P = LORD_Injured(player[0].TATE, player[0].YOKO, LORD.tate, LORD.yoko, player[0].HP, LORD.SIDE, SCENE);
						player[0].TATE = *P;
						player[0].YOKO = *(P + 1);
						LORD.SIDE = *(P + 2);
						player[0].HP = *(P + 3);

						if (JUB_MOD % 10 == 0){
							LORD.SIDE = BOSS_Side(player[0].TATE, player[0].YOKO, LORD.tate, LORD.yoko, LORD.SIDE);
						}
						if (JUB_MOD % 25 == 0){
							if (Monster_Have == 0){
								Monster_No = rand() % 3 + 2;
								if (Monster_No < 3){
									Boss_No = rand() % 2;
								}
								else
								{
									Boss_No = 0;
								}
								for (int i = 0; i < Monster_No; i++){

									int WHILE_JUB = 1;
									int Pix_YOKO;

									while (WHILE_JUB == 1)
									{
										WHILE_JUB = 0;
										MONSTER_7[i].yoko = rand() % 208 + 12;
										MONSTER_7[i].tate = rand() % 64 + 6;
										MONSTER_7[i].SIDE = rand() % 4;
										MONSTER_7[i].HP = 3;

										if (MONSTER_7[i].yoko % 2 != 0){
											Pix_YOKO = ((MONSTER_7[i].yoko + 1) / 2);
										}
										else
										{
											Pix_YOKO = (MONSTER_7[i].yoko / 2);
										}

										for (int Jub_Height = 0; Jub_Height < 3; Jub_Height++){
											for (int Jub_Width = 0; Jub_Width < 3; Jub_Width++){
												if (Scene[MONSTER_7[i].tate][Pix_YOKO + Jub_Width] == 0)
												{
													WHILE_JUB = 1;
													break;
												}
											}
										}

									}
									for (int y = 0; y < 3; y++){
										for (int j = 0; j < MONSTER_WIDTH; j++){
											LOCATE(MONSTER_7[i].yoko + (j * 2), MONSTER_7[i].tate + y);
											COLOR(15, 15);
											printf("　");
										}
									}
									WAIT(100);
									for (int y = 0; y < MONSTER_HEIGHT; y++){
										for (int j = 0; j < MONSTER_WIDTH; j++){
											LOCATE(MONSTER_7[i].yoko + (j * 2), MONSTER_7[i].tate + y);
											COLOR(12, 12);
											printf("　");
										}
									}
									WAIT(100);
									for (int y = 0; y < MONSTER_HEIGHT; y++){
										for (int j = 0; j < MONSTER_WIDTH; j++){
											LOCATE(MONSTER_7[i].yoko + (j * 2), MONSTER_7[i].tate + y);
											COLOR(15, 15);
											printf("　");
										}
									}
									WAIT(150);
									MonstersCL_Display(MONSTER_7[i].tate, MONSTER_7[i].yoko, SCENE);




								}

								if (Boss_No > 0){

									for (int i = 0; i < Boss_No; i++){
										int WHILE_JUB = 1;
										int Pix_YOKO;
										while (WHILE_JUB == 1)
										{
											WHILE_JUB = 0;
											BOSS_7[i].yoko = rand() % 220 + 12;
											BOSS_7[i].tate = rand() % 70 + 6;
											BOSS_7[i].SIDE = rand() % 4;
											BOSS_7[i].HP = 6;
											if (BOSS_7[i].yoko % 2 != 0){
												Pix_YOKO = ((BOSS_7[i].yoko + 1) / 2);
											}
											else
											{
												Pix_YOKO = (BOSS_7[i].yoko / 2);
											}
											for (int Jub_Height = 0; Jub_Height < BOSS_HEIGHT; Jub_Height++){
												for (int Jub_Width = 0; Jub_Width < BOSS_WIDTH; Jub_Width++){
													if (Scene[BOSS_7[i].tate][Pix_YOKO + Jub_Width] == 0)
													{
														WHILE_JUB = 1;
														break;
													}
													if (WHILE_JUB == 1){ break; }
												}
											}
										}
										for (int y = 0; y < BOSS_HEIGHT; y++){
											for (int j = 0; j < BOSS_WIDTH; j++){
												LOCATE(BOSS_7[i].yoko + (j * 2), BOSS_7[i].tate + y);
												COLOR(15, 15);
												printf("　");
											}
										}
										WAIT(100);
										for (int y = 0; y < BOSS_HEIGHT; y++){
											for (int j = 0; j < BOSS_WIDTH; j++){
												LOCATE(BOSS_7[i].yoko + (j * 2), BOSS_7[i].tate + y);
												COLOR(12, 12);
												printf("　");
											}
										}
										WAIT(100);
										for (int y = 0; y < BOSS_HEIGHT; y++){
											for (int j = 0; j < BOSS_WIDTH; j++){
												LOCATE(BOSS_7[i].yoko + (j * 2), BOSS_7[i].tate + y);
												COLOR(15, 15);
												printf("　");
											}
										}
										WAIT(150);
										BOSSCL_Display(BOSS_7[i].tate, BOSS_7[i].yoko, SCENE);
									}
								}
								Monster_Have = 1;
							}//HAVE0
						}//JUB25
					}//Lord Not Miss
					

					if (JUB_MOD % 40 == 0){
						LordMissShow(LORD.yoko, LORD.tate,SCENE);
						LORD_Miss = 1;
						LordMissTime = 1;
						LordHpInMissTime = LORD.HP;
					}//JUB40

					if (LORD_Miss != 0){
						if (LordMissTime != 0){
							LordMissTime += 1;
						}
						if (LordMissTime >= 12){
							while (JubInMissTime == 0)
							{
								JubInMissTime = 1;
								LORD.yoko = rand() % (166- LORD_WIDTH) + 34;
								LORD.tate = rand() % (70 - LORD_HEIGHT) + 6;
								LORD.SIDE = rand() % 4;
								LORD.HP = 6;
								if (LORD.yoko % 2 != 0){
									PixelXInMissTime = ((LORD.yoko + 1) / 2);
								}
								else
								{
									PixelXInMissTime = (LORD.yoko / 2);
								}
								for (int Jub_Height = 0; Jub_Height < LORD_HEIGHT; Jub_Height++){
									for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
										if (Scene[LORD.tate][PixelXInMissTime + Jub_Width] == 0)
										{
											JubInMissTime = 0;
											break;
										}
										if (JubInMissTime == 0){ break; }
									}
								}
							}
							LordMissShow(LORD.yoko, LORD.tate, SCENE);
						}
						if (LordMissTime >= 15){
							JubInMissTime = 0;
							LORD_Miss = 0;
							LordMissTime = 0;
							LORD.HP = LordHpInMissTime;
						}

					}

					if (Monster_Have != 0){
							for (int i = 0; i < Monster_No; i++){
								if (MONSTER_7[i].HP > 0){
									if (JUB_MOD % 3 == 0){
										P = Monster_MOVE(MONSTER_7[i].tate, MONSTER_7[i].yoko, SCENE, MONSTER_7[i].SIDE);
										MONSTER_7[i].tate = *P;
										MONSTER_7[i].yoko = *(P + 1);
										MONSTER_7[i].SIDE = *(P + 2);
										P = MonsterOutOfRange(MONSTER_7[i].yoko, MONSTER_7[i].tate, MONSTER_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										MONSTER_7[i].yoko = *P;
										MONSTER_7[i].tate = *(P + 1);
										MONSTER_7[i].SIDE = *(P + 2);
									}//if
									if (JUB_MOD % 50 == 0){
										MONSTER_7[i].SIDE = rand() % 4;
									}//if
									P = Monster_Injured(player[0].TATE, player[0].YOKO, MONSTER_7[i].tate, MONSTER_7[i].yoko, player[0].HP, MONSTER_7[i].SIDE, SCENE);
									player[0].TATE = *P;
									player[0].YOKO = *(P + 1);
									MONSTER_7[i].SIDE = *(P + 2);
									player[0].HP = *(P + 3);
									P = MonsterOutOfRange(MONSTER_7[i].yoko, MONSTER_7[i].tate, MONSTER_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									MONSTER_7[i].yoko = *P;
									MONSTER_7[i].tate = *(P + 1);
									MONSTER_7[i].SIDE = *(P + 2);
								}//if
							}//for


							if (Boss_No > 0){
								for (int i = 0; i < Boss_No; i++){
									if (BOSS_7[i].HP > 0){
										if (JUB_MOD % 3 == 0){
											P = BOSS_MOVE(BOSS_7[i].tate, BOSS_7[i].yoko, SCENE, BOSS_7[i].SIDE);
											BOSS_7[i].tate = *P;
											BOSS_7[i].yoko = *(P + 1);
											BOSS_7[i].SIDE = *(P + 2);
											if (BOSS_7[i].HP > 0){
												P = BossOutOfRange(BOSS_7[i].yoko, BOSS_7[i].tate, BOSS_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
												BOSS_7[i].yoko = *P;
												BOSS_7[i].tate = *(P + 1);
												BOSS_7[i].SIDE = *(P + 2);
											}
										}//if
										P = BOSS_Injured(player[0].TATE, player[0].YOKO, BOSS_7[i].tate, BOSS_7[i].yoko, player[0].HP, BOSS_7[i].SIDE, SCENE);
										player[0].TATE = *P;
										player[0].YOKO = *(P + 1);
										BOSS_7[i].SIDE = *(P + 2);
										player[0].HP = *(P + 3);
										if (BOSS_7[i].HP > 0){
											P = BossOutOfRange(BOSS_7[i].yoko, BOSS_7[i].tate, BOSS_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
											BOSS_7[i].yoko = *P;
											BOSS_7[i].tate = *(P + 1);
											BOSS_7[i].SIDE = *(P + 2);
										}
										if (JUB_MOD % 10 == 0){
											BOSS_7[i].SIDE = BOSS_Side(player[0].TATE, player[0].YOKO, BOSS_7[i].tate, BOSS_7[i].yoko, BOSS_7[i].SIDE);
										}//if
									}//if
								}//for
							}//if
						
							
								Monster_Have = 0;
								for (int i = 0; i < Monster_No; i++){
									if (MONSTER_7[i].HP > 0){
										Monster_Have = 1;
										break;
									}//if
								}//for
								if (Boss_No > 0){
									for (int i = 0; i < Boss_No; i++){
										if (BOSS_7[i].HP > 0){
											Monster_Have = 1;
											break;
										}//if
									}//for
								}//if

						
					}//hav!=0
				
					if (player[0].HP <= 0){
						Monster_Have = 0;
						LORD_Miss = 0;
						switch_on = GameOver;
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						break;
					}//if
					
					if (LORD.HP <= 0){
						STOPMIDI(Background);
						CLOSEMIDI(Background);
						switch_on = ENDing;
						MOD_END = 1;
						break;
					}
				}//==7


				WAIT(10);
				//キーボード操作より、移動を判断する
				if (INP(PK_UP) || INP(PK_W) || GPUP()){
					player[0].SIDE = SIDE_UP;
					player[0].TATE = Player_UPMove(player[0].TATE, player[0].YOKO, SCENE);
				}//↑又はWの時、上へ移動する

				if (INP(PK_DOWN) || INP(PK_S) || GPDOWN()){
					player[0].SIDE = SIDE_DOWN;
					player[0].TATE = Player_DOWNMove(player[0].TATE, player[0].YOKO, SCENE);
				}//↓又はSの時、下へ移動する

				if (INP(PK_RIGHT) || INP(PK_D) || GPRIGHT()){
					player[0].SIDE = SIDE_RIGHT;
					player[0].YOKO = Player_RIGHTMove(player[0].TATE, player[0].YOKO, SCENE);
				}//→又はDの時、右へ移動する

				if (INP(PK_LEFT) || INP(PK_A) || GPLEFT()){
					player[0].SIDE = SIDE_LEFT;
					player[0].YOKO = Player_LEFTMove(player[0].TATE, player[0].YOKO, SCENE);
				}//←又はAの時、左へ移動する

				if (INP(PK_SP) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){
					Player_Attack(player[0].TATE, player[0].YOKO, SCENE, player[0].SIDE);
					if (Scene_No == 2){
						for (int i = 0; i < 2; i++){
							if (Obstacle[i].HP > 0){ Obstacle[i].HP = Obstacle_Att(player[0].TATE, player[0].YOKO, Obstacle[i].tate, Obstacle[i].yoko, player[0].SIDE, Obstacle[i].HP, SCENE); }
						}
					}
					if (Scene_No == 3){
						for (int i = 0; i < 2; i++){
							if (MONSTER[i].HP > 0){
								P = Monster_Att(player[0].TATE, player[0].YOKO, MONSTER[i].tate, MONSTER[i].yoko, player[0].SIDE, MONSTER[i].HP, SCENE);
								MONSTER[i].tate = *P;
								MONSTER[i].yoko = *(P + 1);
								MONSTER[i].HP = *(P + 2);
								if (MONSTER[i].HP > 0){
									P = MonsterOutOfRange(MONSTER[i].yoko, MONSTER[i].tate, MONSTER[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									MONSTER[i].yoko = *P;
									MONSTER[i].tate = *(P + 1);
									MONSTER[i].SIDE = *(P + 2);
								}

							}

						}
						if (Boss.HP > 0){
							P = BOSS_Att(player[0].TATE, player[0].YOKO, Boss.tate, Boss.yoko, player[0].SIDE, Boss.HP, SCENE);
							Boss.tate = *P;
							Boss.yoko = *(P + 1);
							Boss.HP = *(P + 2);
							if (Boss.HP > 0){
								P = BossOutOfRange(Boss.yoko, Boss.tate, Boss.SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
								Boss.yoko = *P;
								Boss.tate = *(P + 1);
								Boss.SIDE = *(P + 2);
							}
						}
					}

					if (Scene_No == 4){
						for (int i = 0; i < Monster_No; i++){
							if (MONSTER_3[i].HP > 0){
								P = Monster_Att(player[0].TATE, player[0].YOKO, MONSTER_3[i].tate, MONSTER_3[i].yoko, player[0].SIDE, MONSTER_3[i].HP, SCENE);
								MONSTER_3[i].tate = *P;
								MONSTER_3[i].yoko = *(P + 1);
								MONSTER_3[i].HP = *(P + 2);
								if (MONSTER_3[i].HP > 0){
									P = MonsterOutOfRange(MONSTER_3[i].yoko, MONSTER_3[i].tate, MONSTER_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									MONSTER_3[i].yoko = *P;
									MONSTER_3[i].tate = *(P + 1);
									MONSTER_3[i].SIDE = *(P + 2);
								}
							}

						}
						if (Boss_No > 0){
							for (int i = 0; i < Boss_No; i++){
								if (Boss_3[i].HP > 0){
									P = BOSS_Att(player[0].TATE, player[0].YOKO, Boss_3[i].tate, Boss_3[i].yoko, player[0].SIDE, Boss_3[i].HP, SCENE);
									Boss_3[i].tate = *P;
									Boss_3[i].yoko = *(P + 1);
									Boss_3[i].HP = *(P + 2);
									if (Boss_3[i].HP > 0){
										P = BossOutOfRange(Boss_3[i].yoko, Boss_3[i].tate, Boss_3[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										Boss_3[i].yoko = *P;
										Boss_3[i].tate = *(P + 1);
										Boss_3[i].SIDE = *(P + 2);
									}
								}
							}
						}

					}//==4

					if (Scene_No == 5){
						for (int i = 0; i < Monster_No; i++){
							if (MONSTER_5[i].HP > 0){
								P = Monster_Att(player[0].TATE, player[0].YOKO, MONSTER_5[i].tate, MONSTER_5[i].yoko, player[0].SIDE, MONSTER_5[i].HP, SCENE);
								MONSTER_5[i].tate = *P;
								MONSTER_5[i].yoko = *(P + 1);
								MONSTER_5[i].HP = *(P + 2);
								if (MONSTER_5[i].HP > 0){
									P = MonsterOutOfRange(MONSTER_5[i].yoko, MONSTER_5[i].tate, MONSTER_5[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									MONSTER_5[i].yoko = *P;
									MONSTER_5[i].tate = *(P + 1);
									MONSTER_5[i].SIDE = *(P + 2);
								}
							}

						}
					}//==5

					if (Scene_No == 6){

						if (Boss_No > 0){
							for (int i = 0; i < Boss_No; i++){
								if (Boss_6[i].HP > 0){
									P = BOSS_Att(player[0].TATE, player[0].YOKO, Boss_6[i].tate, Boss_6[i].yoko, player[0].SIDE, Boss_6[i].HP, SCENE);
									Boss_6[i].tate = *P;
									Boss_6[i].yoko = *(P + 1);
									Boss_6[i].HP = *(P + 2);
									if (Boss_6[i].HP > 0){
										P = BossOutOfRange(Boss_6[i].yoko, Boss_6[i].tate, Boss_6[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										Boss_6[i].yoko = *P;
										Boss_6[i].tate = *(P + 1);
										Boss_6[i].SIDE = *(P + 2);
									}
								}
							}
						}

					}//==6

					if (Scene_No == 7){
						if (LORD_Miss == 0){
							if (LORD.HP > 0){
								P = LORD_Att(player[0].TATE, player[0].YOKO, LORD.tate, LORD.yoko, player[0].SIDE, LORD.HP, SCENE);
								LORD.tate = *P;
								LORD.yoko = *(P + 1);
								LORD.HP = *(P + 2);
								if (LORD.HP > 0){
									P = LordOutOfRange(LORD.yoko, LORD.tate, LORD.SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
									LORD.yoko = *P;
									LORD.tate = *(P + 1);
									LORD.SIDE = *(P + 2);
								}
							}
						}

						if (Monster_Have != 0){
							for (int i = 0; i < Monster_No; i++){
								if (MONSTER_7[i].HP > 0){
									P = Monster_Att(player[0].TATE, player[0].YOKO, MONSTER_7[i].tate, MONSTER_7[i].yoko, player[0].SIDE, MONSTER_7[i].HP, SCENE);
									MONSTER_7[i].tate = *P;
									MONSTER_7[i].yoko = *(P + 1);
									MONSTER_7[i].HP = *(P + 2);
									if (MONSTER_7[i].HP > 0){
										P = MonsterOutOfRange(MONSTER_7[i].yoko, MONSTER_7[i].tate, MONSTER_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
										MONSTER_7[i].yoko = *P;
										MONSTER_7[i].tate = *(P + 1);
										MONSTER_7[i].SIDE = *(P + 2);
									}
								}

							}
							if (Boss_No > 0){
								for (int i = 0; i < Boss_No; i++){
									if (BOSS_7[i].HP > 0){
										P = BOSS_Att(player[0].TATE, player[0].YOKO, BOSS_7[i].tate, BOSS_7[i].yoko, player[0].SIDE, BOSS_7[i].HP, SCENE);
										BOSS_7[i].tate = *P;
										BOSS_7[i].yoko = *(P + 1);
										BOSS_7[i].HP = *(P + 2);
										if (BOSS_7[i].HP > 0){
											P = BossOutOfRange(BOSS_7[i].yoko, BOSS_7[i].tate, BOSS_7[i].SIDE, LEFT_X, RIGHT_X, UP_Y, DOWN_Y, SCENE);
											BOSS_7[i].yoko = *P;
											BOSS_7[i].tate = *(P + 1);
											BOSS_7[i].SIDE = *(P + 2);
										}
									}
								}
							}
						}//have!=0
					}//==7
				}//ATT

				else
				{
					WAIT(60);
				}
			}//while
			break;
			case GameOver:
				Background = OPENMIDI(FILENAME_OVERMUS);
				PLAYMIDI(Background);
				Game_Over();
				

			
				STOPMIDI(Background);
				CLOSEMIDI(Background);
				switch_on = Back_Save;
				break;
			case ENDing:
				Background = OPENMIDI(FILENAME_WINMUS);
				PLAYMIDI(Background,0);
				Game_Win();

				switch_on = END;
				STOPMIDI(Background);
				CLOSEMIDI(Background);
				break;
		}//switch

	}//while
	
	//return ;


}

