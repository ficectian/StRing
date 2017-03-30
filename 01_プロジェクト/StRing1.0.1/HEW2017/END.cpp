#include "CScreen.h"
#include "Player.h"


void Game_Over(){
	int GO_DIS[OVER_HEIGHT][OVER_WIDTH];
	int Pt_TATE = WINDOWS_HEIGHT - OVER_HEIGHT;
	FILE *fp;
	fp = fopen(FILENAME_OVER, "rt+");
	for (int i = 0; i < OVER_HEIGHT; i++){
		for (int j = 0; j < OVER_WIDTH; j++){
			fscanf_s(fp, "%d,", &GO_DIS[i][j]);
		}
	}
	fclose(fp);
	SCREENCLS(L_BLACK, L_BLACK);

	while (Pt_TATE >= (WINDOWS_HEIGHT - OVER_HEIGHT)/2)
	{
		for (int tate = 0; tate < OVER_HEIGHT; tate++){
			for (int yoko = 0; yoko < OVER_WIDTH; yoko++){
				LOCATE((WINDOWS_WIDTH - OVER_WIDTH) + (2 * yoko), Pt_TATE +4+ tate);
				COLOR(0, 0);
					printf("　");
			}
		}
		for (int tate = 0; tate < OVER_HEIGHT; tate++){
			for (int yoko = 0; yoko < OVER_WIDTH; yoko++){
				LOCATE((WINDOWS_WIDTH - OVER_WIDTH) + (2 * yoko), Pt_TATE + tate);
				if (GO_DIS[tate][yoko] != 16){
					COLOR(GO_DIS[tate][yoko], GO_DIS[tate][yoko]);
					printf("　");
				}
			}
		}
		WAIT(200);
		Pt_TATE -= 4;
	}
	rewind(stdin);						//キーボード入力クリア
	while (true)
	{
		if (INP(PK_SP) || INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){
			break;
		}
	}
}


void Game_Win(){
	int WIN_DIS[WIN_HEIGHT][WIN_WIDTH];
	int Pt_TATE = (WINDOWS_HEIGHT - WIN_HEIGHT)/2;
	FILE *fp;
	fp = fopen(FILENAME_WIN, "rt+");
	for (int i = 0; i < WIN_HEIGHT; i++){
		for (int j = 0; j < WIN_WIDTH; j++){
			fscanf_s(fp, "%d,", &WIN_DIS[i][j]);
		}
	}
	fclose(fp);
	SCREENCLS(L_BLACK, L_BLACK);

	for (int tate = 0; tate < WIN_HEIGHT; tate++){
		for (int yoko = 0; yoko < WIN_WIDTH; yoko++){
			LOCATE((WINDOWS_WIDTH - WIN_WIDTH) + (2 * yoko), Pt_TATE + tate);
				if (WIN_DIS[tate][yoko] != 16){
					COLOR(WIN_DIS[tate][yoko], WIN_DIS[tate][yoko]);
					printf("　");
				}
			}
		}

	rewind(stdin);						//キーボード入力クリア
	WAIT(1000);
	while (true)
	{
		if ( INP(PK_ENTER) || GPBTN1() || GPBTN2() || GPBTN3() || GPBTN4()){
			break;
		}
	}
}