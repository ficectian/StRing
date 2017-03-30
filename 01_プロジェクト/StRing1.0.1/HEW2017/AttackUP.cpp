#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player��ʕ\���֐��i�\�ʁj��`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j
//=========================================================
void  AttackUP_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q

	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKUP, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate -1- ATTACK_WIDTH_HEIGHT+1 + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				COLOR(Attack_Out[tate][yoko], Attack_Out[tate][yoko]);
				printf("�@");
			}
		}

	}
}

void  AttackUP_W_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q

	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKUP, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate - 1 - ATTACK_WIDTH_HEIGHT + 1 + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				COLOR(15, 15);
				printf("�@");
			}
		}

	}
}

//=========================================================
//	Player��ʍ폜�֐���`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j�G
//	�����Fint�F *Scene�i�w�i��ʁj
//=========================================================
void  AttackCLUP_Display(int Pt_tate, int Pt_yoko,  const char   *SCENE){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int Pix_YOKO;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO =( (Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	//Player��ʃf�[�^��ǂݍ���
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
	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH), Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				if (Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)] == 16){
					COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
					printf("�@");
				}
				if (Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
					//Scene[Pt_tate + tate][Pt_yoko + yoko]
					COLOR(L_BLACK, L_BLACK);
					printf("�@");
				}
				else{
					COLOR(Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)], Scene[Pt_tate - 1 - (ATTACK_WIDTH_HEIGHT - 1) + tate][Pix_YOKO + yoko - ((ATTACK_WIDTH_WIDTH - PLAYER_WIDTH) / 2)]);
					printf("�@");
				}
			}
		}
	}


}