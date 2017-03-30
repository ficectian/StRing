#include "CScreen.h"
#include "Player.h"

//=========================================================
//�G�n�[�g����֐���`
//	�����Fint�FPt_tate�iPlayer�c�j�Gint�FPt_yoko�iPlayer���j
//	�����Fint�FMON_TATE�i�G�c�j�Gint�FMON_YOKO�i�G���j;int:HP�iPlayer�̗͒l�j
//	�����Fconst char  *�FSCENE�i�w�i�̈ʒu�j�G int�FMon_SIDE�i�G�����j
//	�Ԓl�Fint*�iPlayer�c�GPlayer���G�G�����GPlayer�̗͒l�j
//=========================================================
int * Monster_Injured(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int HP,int Mon_SIDE, const char   *SCENE){
	int Jub_For = 0;
	static int Rut[4];
	for (int x = 0; x < PLAYER_HEIGHT; x++){
		for (int y = 0; y < (PLAYER_WIDTH * 2); y++){
			for (int n = 0; n < (MONSTER_WIDTH * 2); n++){
				for (int m = 0; m < MONSTER_HEIGHT; m++)
				{
					if (Pt_tate + x == Mon_tate + m && Pt_yoko + y == Mon_yoko + n){
						int INJ_Sound = OPENWAVE(FILENAME_MONSTERATTACK);
						PLAYWAVE(INJ_Sound, 0);
						HP -= 1;
						HP_CL();
						HP_Disp(HP);
						if (Pt_yoko < Mon_yoko){
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 1;
							Pt_yoko -= 2;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 1;
							Pt_yoko -= 2;
							Player_Display(Pt_tate, Pt_yoko);
							Monsters_Display(Mon_tate, Mon_yoko);
						}
						else
						{
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 1;
							Pt_yoko += 2;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 1;
							Pt_yoko += 2;
							Player_Display(Pt_tate, Pt_yoko);
							Monsters_Display(Mon_tate, Mon_yoko);
						}
						STOPWAVE(INJ_Sound);
						CLOSEWAVE(INJ_Sound);
						Jub_For = 1;
						Mon_SIDE = rand() % 4;
						break;
					}
					if (Jub_For == 1){ break; }
				}
				if (Jub_For == 1){ break; }
			}
			if (Jub_For == 1){ break; }
		}
	}

	*Rut = Pt_tate;
	*(Rut + 1) = Pt_yoko;
	*(Rut + 2) = Mon_SIDE;
	*(Rut + 3) = HP;
	return Rut;
}


//=========================================================
//BOSS�n�[�g����֐���`
//	�����Fint�FPt_tate�iPlayer�c�j�Gint�FPt_yoko�iPlayer���j
//	�����Fint�FMON_TATE�i�G�c�j�Gint�FMON_YOKO�i�G���j;int:HP�iPlayer�̗͒l�j
//	�����Fconst char  *�FSCENE�i�w�i�̈ʒu�j�G int�FMon_SIDE�i�G�����j
//	�Ԓl�Fint*�iPlayer�c�GPlayer���G�G�����GPlayer�̗͒l�j
//=========================================================
int * BOSS_Injured(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int HP, int Mon_SIDE, const char   *SCENE){
	int Jub_For = 0;
	static int Rut[4];
	for (int x = 0; x < PLAYER_HEIGHT; x++){
		for (int y = 0; y < (PLAYER_WIDTH * 2); y++){
			for (int n = 0; n < (BOSS_WIDTH * 2); n++){
				for (int m = 0; m < BOSS_HEIGHT; m++)
				{
					if (Pt_tate + x == Mon_tate + m && Pt_yoko + y == Mon_yoko + n){
						int INJ_Sound = OPENWAVE(FILENAME_MONSTERATTACK);
						PLAYWAVE(INJ_Sound, 0);
						HP -= 1;
						HP_CL();
						HP_Disp(HP);
						if (Pt_yoko < Mon_yoko){
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 2;
							Pt_yoko -= 4;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 2;
							Pt_yoko -= 4;
							Player_Display(Pt_tate, Pt_yoko);
							BOSSp_Display(Mon_tate, Mon_yoko);
						}
						else
						{
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 2;
							Pt_yoko += 4;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 2;
							Pt_yoko += 4;
							Player_Display(Pt_tate, Pt_yoko);
							BOSSp_Display(Mon_tate, Mon_yoko);

						}
						STOPWAVE(INJ_Sound);
						CLOSEWAVE(INJ_Sound);
						Jub_For = 1;
						Mon_SIDE = rand() % 4;
						break;
					}
					if (Jub_For == 1){ break; }
				}
				if (Jub_For == 1){ break; }
			}
			if (Jub_For == 1){ break; }
		}
	}

	*Rut = Pt_tate;
	*(Rut + 1) = Pt_yoko;
	*(Rut + 2) = Mon_SIDE;
	*(Rut + 3) = HP;
	return Rut;
}


//=========================================================
//LORD�n�[�g����֐���`
//	�����Fint�FPt_tate�iPlayer�c�j�Gint�FPt_yoko�iPlayer���j
//	�����Fint�FMON_TATE�i�G�c�j�Gint�FMON_YOKO�i�G���j;int:HP�iPlayer�̗͒l�j
//	�����Fconst char  *�FSCENE�i�w�i�̈ʒu�j�G int�FMon_SIDE�i�G�����j
//	�Ԓl�Fint*�iPlayer�c�GPlayer���G�G�����GPlayer�̗͒l�j
//=========================================================
int * LORD_Injured(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int HP, int Mon_SIDE, const char   *SCENE){
	int Jub_For = 0;
	static int Rut[4];
	for (int x = 0; x < PLAYER_HEIGHT; x++){
		for (int y = 0; y < (PLAYER_WIDTH * 2); y++){
			for (int n = 0; n < (LORD_WIDTH * 2); n++){
				for (int m = 0; m < LORD_HEIGHT; m++)
				{
					if (Pt_tate + x == Mon_tate + m && Pt_yoko + y == Mon_yoko + n){
						int INJ_Sound = OPENWAVE(FILENAME_MONSTERATTACK);
						PLAYWAVE(INJ_Sound, 0);
						HP -= 1;
						HP_CL();
						HP_Disp(HP);
						if (Pt_yoko < Mon_yoko){
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 1;
							Pt_yoko -= 6;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 1;
							Pt_yoko -= 6;
							Player_Display(Pt_tate, Pt_yoko);
							LORDp_Display(Mon_tate, Mon_yoko);
						}
						else
						{
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate += 1;
							Pt_yoko += 6;
							Player_Display(Pt_tate, Pt_yoko);
							WAIT(100);
							PlayerCL_Display(Pt_tate, Pt_yoko, SCENE);
							Pt_tate -= 1;
							Pt_yoko += 6;
							Player_Display(Pt_tate, Pt_yoko);
							LORDp_Display(Mon_tate, Mon_yoko);
						}
						STOPWAVE(INJ_Sound);
						CLOSEWAVE(INJ_Sound);
						Jub_For = 1;
						break;
					}
					if (Jub_For == 1){ break; }
				}
				if (Jub_For == 1){ break; }
			}
			if (Jub_For == 1){ break; }
		}
	}

	*Rut = Pt_tate;
	*(Rut + 1) = Pt_yoko;
	*(Rut + 2) = Mon_SIDE;
	*(Rut + 3) = HP;
	return Rut;
}
