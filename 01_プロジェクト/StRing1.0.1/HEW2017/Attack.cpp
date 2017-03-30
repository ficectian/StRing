#include "CScreen.h"
#include "Player.h"



//=========================================================
//	Player��ʕ\���֐��i�\�ʁj��`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j
//=========================================================
void  Attack_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q


	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKDOWN, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko)-6, Pt_tate+1 + PLAYER_HEIGHT - 1 + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				COLOR(Attack_Out[tate][yoko], Attack_Out[tate][yoko]);
				printf("�@");
			}
		}

	}
}

void  Attack_W_Display(int Pt_tate, int Pt_yoko){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q

	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKDOWN, "rt+");
	for (int i = 0; i < ATTACK_WIDTH_HEIGHT; i++){
		for (int j = 0; j < ATTACK_WIDTH_WIDTH; j++){
			fscanf_s(fp, "%d,", &Attack_Out[i][j]);
		}
	}
	fclose(fp);

	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < ATTACK_WIDTH_HEIGHT; tate++){
		for (int yoko = 0; yoko < ATTACK_WIDTH_WIDTH; yoko++){
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate+1 + PLAYER_HEIGHT - 1 + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				COLOR(15,15);
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
void  AttackCL_Display(int Pt_tate, int Pt_yoko, const char   *SCENE){
	int Attack_Out[ATTACK_WIDTH_HEIGHT][ATTACK_WIDTH_WIDTH];		//Player��ʕϐ��F���F�T�G�c�F�P�Q
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int Pix_YOKO;
	if (Pt_yoko % 2 != 0){
		Pix_YOKO = ((Pt_yoko + 1) / 2);
	}
	else
	{
		Pix_YOKO = (Pt_yoko / 2);
	}
	//Player��ʃf�[�^��ǂݍ���
	FILE *fp;
	fp = fopen(FILENAME_ATTACKDOWN, "rt+");
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
			//LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate - ATTACK_WIDTH_HEIGHT + 1 + tate);
			LOCATE(Pt_yoko + (2 * yoko) - 6, Pt_tate+1 + PLAYER_HEIGHT - 1 + tate);
			//�P�U�̎��w�i�F��\��
			if (Attack_Out[tate][yoko] != 16){
				if (Scene[Pt_tate + 1 + PLAYER_HEIGHT - 1 + tate][Pix_YOKO + yoko - 3] == 16){
					COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
					printf("�@");
				}
				if (Scene[Pt_tate + 1 + PLAYER_HEIGHT - 1 + tate][Pix_YOKO + yoko - 3] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
					//Scene[Pt_tate + tate][Pt_yoko + yoko]
					COLOR(L_BLACK, L_BLACK);
					printf("�@");
				}
				else{
					COLOR(Scene[Pt_tate + 1 + PLAYER_HEIGHT - 1 + tate][Pix_YOKO + yoko - 3], Scene[Pt_tate + 1 + PLAYER_HEIGHT - 1 + tate][Pix_YOKO + yoko - 3]);
					printf("�@");
				}
			}
		}
	}
}

void  Player_Attack(int Pt_tate, int Pt_yoko, const char   *SCENE, int Jub_Side){

	int Attack_Sound = OPENWAVE(FILENAME_ATTACK_SOUND);
	PLAYWAVE(Attack_Sound, 0);

	switch (Jub_Side)
	{
	case SIDE_UP:
		AttackUP_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackUP_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackUP_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackUP_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackUP_Display(Pt_tate, Pt_yoko);
		WAIT(70);
		AttackCLUP_Display(Pt_tate, Pt_yoko, SCENE);
		break;
	case SIDE_DOWN:
		Attack_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		Attack_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		Attack_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		Attack_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		Attack_Display(Pt_tate, Pt_yoko);
		WAIT(70);
		AttackCL_Display(Pt_tate, Pt_yoko, SCENE);
		break;
	case SIDE_LEFT:
		AttackLEFT_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackLEFT_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackLEFT_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackLEFT_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackLEFT_Display(Pt_tate, Pt_yoko);
		WAIT(70);
		AttackCLLEFT_Display(Pt_tate, Pt_yoko, SCENE);
		break;
	case SIDE_RIGHT:
		AttackRIGHT_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackRIGHT_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackRIGHT_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackRIGHT_W_Display(Pt_tate, Pt_yoko);
		WAIT(20);
		AttackRIGHT_Display(Pt_tate, Pt_yoko);
		WAIT(70);
		AttackCLRIGHT_Display(Pt_tate, Pt_yoko, SCENE);
		break;
	default:
		break;
	}

	STOPWAVE(Attack_Sound);

	CLOSEWAVE(Attack_Sound);

}