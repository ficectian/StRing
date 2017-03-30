#include "CScreen.h"
#include "Player.h"

//=========================================================
//�G�ړ��֐���`
//	�����Fint�FMON_TATE�i��ʎn�߂�c�j�Gint�FMON_YOKO�i��ʎn�߂鉡�j
//	�����Fconst char  *�FSCENE�i�w�i�̈ʒu�j�G int�FSIWITCH�i�����j
//	�Ԓl�Fint*�i��ʎn�߂�c�G��ʎn�߂鉡�G�����j
//=========================================================
int*	Monster_MOVE(int MON_TATE, int MON_YOKO, const char   *SCENE, int SIWITCH){
	int Pix_YOKO;
	static int R[3];
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	int END = 0;
	int JUB_END = 0;
	if (MON_YOKO % 2 != 0){
		Pix_YOKO = ((MON_YOKO + 1) / 2) ;
	}
	else
	{
		Pix_YOKO = (MON_YOKO / 2) ;
	}
	
	
	FILE *fp2;
	fp2 = fopen(SCENE, "rt+");
	for (int i = 0; i < WINDOWS_HEIGHT; i++){
		for (int j = 0; j < WINDOWS_WIDTH; j++){
			fscanf_s(fp2, "%d,", &Scene[i][j]);
		}
	}
	fclose(fp2);

	MonstersCL_Display(MON_TATE, MON_YOKO, SCENE);

	while (END == 0)
	{
		
		switch (SIWITCH)
		{
		case 0://W
			MON_TATE -= STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < 3; Jub_Width++){
				if (Scene[MON_TATE][Pix_YOKO + Jub_Width] == 0){
					MON_TATE += STRIDE_HEIGHT;
					SIWITCH = 1;
					JUB_END = 1;
					break; }
			}
			if (JUB_END != 1){
				Monsters_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 1://D
			MON_YOKO += STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2) ;
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2);
			}
			for (int Jub_Height = 0; Jub_Height < 3; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO + 2] == 0){
					MON_YOKO -= STRIDE_WIDTH;
					SIWITCH = 2;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				Monsters_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;

		case 2://S
			MON_TATE += STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < 3; Jub_Width++){
				if (Scene[MON_TATE+2][Pix_YOKO + Jub_Width] == 0){
					MON_TATE -= STRIDE_HEIGHT;
					SIWITCH = 3;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				Monsters_Display(MON_TATE, MON_YOKO);
				END = 1;
			}
			else
			{
				JUB_END = 0;
			}
			break;
	
		case 3://A
			MON_YOKO -= STRIDE_WIDTH;
			if (MON_YOKO % 2 != 0){
				Pix_YOKO = ((MON_YOKO + 1) / 2) ;
			}
			else
			{
				Pix_YOKO = (MON_YOKO / 2) ;
			}
			for (int Jub_Height = 0; Jub_Height < 3; Jub_Height++){
				if (Scene[MON_TATE + Jub_Height][Pix_YOKO] == 0){
					MON_YOKO += STRIDE_WIDTH;
					SIWITCH = 0;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				Monsters_Display(MON_TATE, MON_YOKO);
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


//=========================================================
//	�G��ʕ\���֐���`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j
//=========================================================
void  Monsters_Display(int Pt_tate, int Pt_yoko){
	int play_Out[MONSTER_HEIGHT][MONSTER_WIDTH]; //Player��ʕϐ��F���F3�G�c�F3

	FILE *fp;
	fp = fopen(FILENAME_MONSTER, "rt+");
	for (int i = 0; i < MONSTER_HEIGHT; i++){
		for (int j = 0; j < MONSTER_WIDTH; j++){
			fscanf_s(fp, "%d,", &play_Out[i][j]);
		}
	}
	fclose(fp);
	//Player��ʃf�[�^��\��
	for (int tate = 0; tate < 3; tate++){
		for (int yoko = 0; yoko < 3; yoko++){
			LOCATE(Pt_yoko + (2 * yoko), Pt_tate + tate);
			//�P�U�̎��w�i�F��\��

			if (play_Out[tate][yoko] != 16){
				COLOR(play_Out[tate][yoko], play_Out[tate][yoko]);
				printf("�@");
			}
		}

	}
}

//= == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
//	�G��ʍ폜�֐���`
//	�����Fint�FPt_tate�i��ʎn�߂�c�j�Gint�FPt_yoko�i��ʎn�߂鉡�j�G
//	�����Fconst char�F SCENE�i�w�i��ʂ̏ꏊ�j
//=========================================================
void  MonstersCL_Display(int MON_TATE, int MON_YOKO, const char   *SCENE){
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
		Pix_YOKO = (MON_YOKO / 2) ;
	}

	for (int tate = 0; tate < 3; tate++){
		for (int yoko = 0; yoko < 3; yoko++){
			LOCATE(MON_YOKO + (2 * yoko), MON_TATE + tate);
			//LOCATE((Pt_yoko/2 + yoko - ATTACK_HEIGHT_WIDTH)*2, Pt_tate + tate);
			//�P�U�̎��w�i�F��\��
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 16){
				COLOR(BACKGROUND_COLOR, BACKGROUND_COLOR);
				printf("�@");
			}
			if (Scene[MON_TATE + tate][Pix_YOKO + yoko] == 0){		//Scene + WINDOWS_WIDTH	 * (Pt_tate + tate) + (Pt_yoko + yoko)
				//Scene[Pt_tate + tate][Pt_yoko + yoko]
				COLOR(L_BLACK, L_BLACK);
				printf("�@");
			}
			else{
				COLOR(Scene[MON_TATE + tate][Pix_YOKO + yoko], Scene[MON_TATE + tate][Pix_YOKO + yoko]);
				printf("�@");
			}
		}
	}
	

}

