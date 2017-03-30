#include "CScreen.h"
#include "Player.h"


//=========================================================
//	Title()関数のプロトタイプ宣言
//=========================================================
void Title(){
	int LOGO_DATA[TITLE_HEIGHT][TITLE_WIDTH];
	int Ent_Bar[ENTER_HEIGHT][ENTER_WIDTH];
	int JUB = 0;
	FILE *fp;
	fp = fopen(FILENAME_TITLE, "rt+");
	for (int i = 0; i < TITLE_HEIGHT; i++){
		for (int j = 0; j < TITLE_WIDTH; j++){
			fscanf_s(fp, "%d,", &LOGO_DATA[i][j]);
		}
	}
	fclose(fp);

	fp = fopen(FILENAME_ENTER, "rt+");
	for (int i = 0; i < ENTER_HEIGHT; i++){
		for (int j = 0; j < ENTER_WIDTH; j++){
			fscanf_s(fp, "%d,", &Ent_Bar[i][j]);
		}
	}
	fclose(fp);
	
	SCREENCLS(L_BLACK, L_BLACK);

	for (int tate = 0; tate < TITLE_HEIGHT; tate++){
		for (int yoko = 0; yoko < TITLE_WIDTH; yoko++){
			LOCATE((WINDOWS_WIDTH - TITLE_WIDTH) + (2 * yoko), 20 + tate);
			if (LOGO_DATA[tate][yoko] != 16){
				COLOR(LOGO_DATA[tate][yoko], LOGO_DATA[tate][yoko]);
				printf("　");
			}
		}
		if (tate < 13){ WAIT(100); }
		//else if (tate = 13){ WAIT(500); }
		
	}
	
	

	while (JUB<3){
		rewind(stdin);						//キーボード入力クリア
		if (INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){ break; }

		for (int tate = 0; tate < ENTER_HEIGHT; tate++){
			for (int yoko = 0; yoko < ENTER_WIDTH; yoko++){
				LOCATE((WINDOWS_WIDTH - ENTER_WIDTH) + (2 * yoko), 60 + tate);
				COLOR(0, 0);
					printf("　");
				
			}
		}
		rewind(stdin);						//キーボード入力クリア
		if (INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){ break; }
		//getchar();								//何か押されるまで待つ
		WAIT(500);
	
		for (int tate = 0; tate < ENTER_HEIGHT; tate++){
			for (int yoko = 0; yoko < ENTER_WIDTH; yoko++){
				LOCATE((WINDOWS_WIDTH - ENTER_WIDTH) + (2 * yoko), 60 + tate);
				if (Ent_Bar[tate][yoko] != 16){
					COLOR(Ent_Bar[tate][yoko], Ent_Bar[tate][yoko]);
					printf("　");
				}
			}
		}
		rewind(stdin);						//キーボード入力クリア
		if (INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){ break; }
		//getchar();								//何か押されるまで待つ
		WAIT(500);
		JUB++;
	}
	rewind(stdin);						//キーボード入力クリア
	while (true)
	{
		if (INP(PK_SP) || INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){
			break;
		}
	}
	
	//getchar();								//何か押されるまで待つ
}
