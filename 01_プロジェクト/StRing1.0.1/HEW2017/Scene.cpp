#include "CScreen.h"
#include "Player.h"

//=========================================================
//	�w�i��ʕ\���֐���`
//	�����Fint�F *Scene�i�w�i��ʁj
//=========================================================
void Scene_Disp(int *Scene){
	for (int tate = 0; tate < WINDOWS_HEIGHT; tate++){
		for (int yoko = 0; yoko < WINDOWS_WIDTH; yoko++){
			LOCATE(2 * yoko, tate);
	
			if (*(Scene + WINDOWS_WIDTH	 * tate + yoko) == 16){
				COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
				printf("�@");
			}

			if (*(Scene + WINDOWS_WIDTH	 * tate + yoko) == 0){
				COLOR(L_BLACK, L_BLACK);
				printf("�@");
			}
			else{
				COLOR(*(Scene + WINDOWS_WIDTH	 * tate + yoko), *(Scene + WINDOWS_WIDTH	 * tate + yoko));
				printf("�@");
			}
		}
	}
}