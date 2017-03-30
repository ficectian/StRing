#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player��ʕ\���֐��i�\�ʁj��`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j
//=========================================================
void  AttackRIGHT_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q
	
	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKRIGHT, "rt+");
	for (int i = 0; i < ATTACK_HEIGHT_HEIGHT; i++){
		for (int j = 0; j < ATTACK_HEIGHT_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			LOCATE(Pt_yoko+2 + (2 * yoko) + ATTACK_HEIGHT_WIDTH * 2 + 2, Pt_tate + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				COLOR(Attack_Out[tate][yoko], Attack_Out[tate][yoko]);
				printf("�@");
			}
		}

	}
}

void  AttackRIGHT_W_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q

	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKRIGHT, "rt+");
	for (int i = 0; i < ATTACK_HEIGHT_HEIGHT; i++){
		for (int j = 0; j < ATTACK_HEIGHT_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			LOCATE(Pt_yoko + 2 + (2 * yoko) + ATTACK_HEIGHT_WIDTH * 2 + 2, Pt_tate + tate);
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
void  AttackCLRIGHT_Display(int Pt_tate, int Pt_yoko, const char   *SCENE){
	int Attack_Out[ATTACK_HEIGHT_HEIGHT][ATTACK_HEIGHT_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q
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
	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_HEIGHT_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_HEIGHT_WIDTH; yoko++){
			//LOCATE(Pt_yoko + (2 * yoko) - ATTACK_HEIGHT_WIDTH * 2, Pt_tate + tate);

			LOCATE(Pt_yoko + 2 + (2 * yoko) + PLAYER_WIDTH * 2, Pt_tate + tate);

			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				if (Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH] == 16){
					COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
					printf("�@");
				}
				if (Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH] == 0){
					COLOR(L_BLACK, L_BLACK);
					printf("�@");
				}
				else{
					COLOR(Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH], Scene[Pt_tate + tate][Pix_YOKO + 1 + yoko + PLAYER_WIDTH]);
					printf("�@");
				}
			}
		}
	}


}