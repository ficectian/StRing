#include "CScreen.h"
#include "Player.h"

int* LORD_Play(int pt_tate, int pt_yoko, int MonTATE, int MonYOKO, int SIDE,int JUB_MOD, const char   *SCENE,int Pl_HP){
	int *P;
	int *P2;
	static int R[6];
	int JUB_END = 0;
	int Pix_YOKO;
	int Scene[WINDOWS_HEIGHT][WINDOWS_WIDTH];
	if (MonYOKO % 2 != 0){
		Pix_YOKO = ((MonYOKO + 1) / 2);
	}
	else
	{
		Pix_YOKO = (MonYOKO / 2);
	}
	FILE *fp;
	fp = fopen(SCENE, "rt+");
	for (int i = 0; i < WINDOWS_HEIGHT; i++){
		for (int j = 0; j < WINDOWS_WIDTH; j++){
			fscanf_s(fp, "%d,", &Scene[i][j]);
		}
	}
	fclose(fp);

	if (JUB_MOD % 3 == 0){
		P = LORD_MOVE(MonTATE, MonYOKO, SCENE, SIDE);
		MonTATE = *P;
		MonYOKO = *(P + 1);
		SIDE = *(P + 2);
	}

	P2 = LORD_Injured(pt_tate, pt_yoko, MonTATE, MonYOKO, Pl_HP, SIDE, SCENE);
	pt_tate = *P2;
	pt_yoko = *(P2 + 1);
	SIDE = *(P2 + 2);
	Pl_HP = *(P2 + 3);

	if (JUB_MOD % 10 == 0){
		SIDE = BOSS_Side(pt_tate, pt_yoko, MonTATE, MonYOKO, SIDE);
	}
	/*
	if (JUB_MOD % 30 == 0){
		switch (SIDE)
		{
		case 0:
			LORDCL_Display(MonTATE, MonYOKO, SCENE);
			MonTATE -= STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
				if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
					MonTATE += STRIDE_HEIGHT;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDb_Display(MonTATE, MonYOKO);
				WAIT(150);
				LORDCL_Display;
				MonTATE -= STRIDE_HEIGHT;
				for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
					if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
						MonTATE += STRIDE_HEIGHT;
						JUB_END = 1;
						break;
					}
				}
				if (JUB_END != 1){
					LORDb_Display(MonTATE, MonYOKO);
					WAIT(150);
					LORDCL_Display;
					MonTATE -= STRIDE_HEIGHT;
					for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
						if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
							MonTATE += STRIDE_HEIGHT;
							JUB_END = 1;
							break;
						}
					}
					if (JUB_END != 1){
						LORDb_Display(MonTATE, MonYOKO);
					}
				}
			}
			else
			{
				JUB_END = 0;
			}
			break;
		case 2:
			LORDCL_Display(MonTATE, MonYOKO, SCENE);
			MonTATE += STRIDE_HEIGHT;
			for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
				if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
					MonTATE -= STRIDE_HEIGHT;
					JUB_END = 1;
					break;
				}
			}
			if (JUB_END != 1){
				LORDp_Display(MonTATE, MonYOKO);
				WAIT(150);
				LORDCL_Display;
				MonTATE += STRIDE_HEIGHT;
				for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
					if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
						MonTATE -= STRIDE_HEIGHT;
						JUB_END = 1;
						break;
					}
				}
				if (JUB_END != 1){
					LORDp_Display(MonTATE, MonYOKO);
					WAIT(150);
					LORDCL_Display;
					MonTATE += STRIDE_HEIGHT;
					for (int Jub_Width = 0; Jub_Width < LORD_WIDTH; Jub_Width++){
						if (Scene[MonTATE][Pix_YOKO + Jub_Width] == 0){
							MonTATE -= STRIDE_HEIGHT;
							JUB_END = 1;
							break;
						}
					}
					if (JUB_END != 1){
						LORDp_Display(MonTATE, MonYOKO);
					}
				}
			}
			else
			{
				JUB_END = 0;
			}
			break;

		default:
			break;
		}
	}
	*/
	*R = pt_tate;
	*(R + 1) = pt_yoko;
	*(R + 2) = MonTATE;
	*(R + 3) = MonYOKO;
	*(R + 4) = SIDE;
	*(R + 5) = Pl_HP;

	return R;
}

