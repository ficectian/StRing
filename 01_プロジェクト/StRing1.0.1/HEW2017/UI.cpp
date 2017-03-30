#include "CScreen.h"
#include "Player.h"

//=========================================================
//	Player体力表示関数（表面）定義
//	引数：int：HP（Player体力値）
//=========================================================
void	HP_Disp(int HP){
	int hp_Disp[HP_HEIGHT][HP_WIDTH];
	int hp1_Disp[HP_HEIGHT][HP_WIDTH];

	FILE *fp;
	fp = fopen(FILENAME_HP, "rt+");
	for (int i = 0; i < HP_HEIGHT; i++){
		for (int j = 0; j < HP_WIDTH; j++){
			fscanf_s(fp, "%d,", &hp_Disp[i][j]);
		}
	}
	fclose(fp);
	fp = fopen(FILENAME_HP_1, "rt+");
	for (int i = 0; i < HP_HEIGHT; i++){
		for (int j = 0; j < HP_WIDTH; j++){
			fscanf_s(fp, "%d,", &hp1_Disp[i][j]);
		}
	}
	fclose(fp);
	if (HP >= 1){
		//Player画面データを表示
		for (int tate = 0; tate < HP_HEIGHT; tate++){for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(5 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp1_Disp[tate][yoko], hp1_Disp[tate][yoko]);
					printf("　");
				}
			}}
	}
	if (HP >= 2){
		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(5 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp_Disp[tate][yoko], hp_Disp[tate][yoko]);
					printf("　");
				}
			}
		}
	}
	if (HP >= 3){
		//Player画面データを表示
		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(17 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp1_Disp[tate][yoko], hp1_Disp[tate][yoko]);
					printf("　");
				}
			}
		}
	}
	if (HP >= 4){
		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(17 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp_Disp[tate][yoko], hp_Disp[tate][yoko]);
					printf("　");
				}
			}
		}
	}
	if (HP >= 5){
		//Player画面データを表示
		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(29 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp1_Disp[tate][yoko], hp1_Disp[tate][yoko]);
					printf("　");
				}
			}
		}
	}
	
	
	if (HP >= 6){
		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(29 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				if (hp1_Disp[tate][yoko] != 16){
					COLOR(hp_Disp[tate][yoko], hp_Disp[tate][yoko]);
					printf("　");
				}
			}
		}
	}


}


void	HP_CL(){


		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(5 + (2 * yoko), 2 + tate);
					COLOR(0, 0);
					printf("　");
			}
		}
	

		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(17 + (2 * yoko), 2 + tate);
				COLOR(0, 0);
				printf("　");
			}
		}

		for (int tate = 0; tate < HP_HEIGHT; tate++){
			for (int yoko = 0; yoko < HP_WIDTH; yoko++){
				LOCATE(29 + (2 * yoko), 2 + tate);
				//１６の時背景色を表示
				COLOR(0, 0);
				printf("　");
			}
		}

}