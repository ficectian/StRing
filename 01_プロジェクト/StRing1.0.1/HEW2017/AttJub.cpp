#include "CScreen.h"
#include "Player.h"

//=========================================================
//ATT敵 判定関数定義
//	引数：int：Pt_tate（Player縦）；int：Pt_yoko（Player横）
//	引数：int：Mon_tate（敵縦）；int：Mon_yoko（敵横）;int：Jub_Side(Player方向）
//	引数：int：HP（敵体力値）；const char  *：SCENE（背景の位置）
//	返値：int*（敵縦；敵横；敵体力値）
//=========================================================
int*  Monster_Att(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int Jub_Side, int HP, const char   *SCENE){
	static int Rut[3];
	int ATT_YOKO;
	int ATT_TATE;
	switch (Jub_Side)
	{
	case SIDE_LEFT:
		ATT_YOKO = Pt_yoko -2- (ATTACK_HEIGHT_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x=0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (MONSTER_WIDTH * 2); m++){
					for (int n = 0; n < MONSTER_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							MonstersCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko -= 4;
							HP -= 1;
							if (HP > 0){ 
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								Monsters_Display(Mon_tate, Mon_yoko); 
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								MonsterDead_Disp(Mon_tate, Mon_yoko, SCENE);
							}
							
						}
					}
				}
			}
		}
		break;
	case SIDE_RIGHT:
		ATT_YOKO = Pt_yoko +2+ (PLAYER_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x = 0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (MONSTER_WIDTH * 2); m++){
					for (int n = 0; n < MONSTER_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							MonstersCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko += 4;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								Monsters_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								MonsterDead_Disp(Mon_tate, Mon_yoko, SCENE);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_UP:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate - ATTACK_WIDTH_HEIGHT;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (MONSTER_WIDTH * 2); m++){
					for (int n = 0; n < MONSTER_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							MonstersCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate -= 2;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								Monsters_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								MonsterDead_Disp(Mon_tate, Mon_yoko, SCENE);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_DOWN:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate  + PLAYER_HEIGHT ;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (MONSTER_WIDTH * 2); m++){
					for (int n = 0; n < MONSTER_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							MonstersCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate += 2;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								Monsters_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								MonsterDead_Disp(Mon_tate, Mon_yoko, SCENE);
							}
						}
					}
				}
			}
		}
		break;
		break;
	default:
		break;
	}
	
	*Rut = Mon_tate;
	*(Rut + 1) = Mon_yoko;
	*(Rut + 2) = HP;
	return Rut;


}


//=========================================================
//ATTBOSS 判定関数定義
//	引数：int：Pt_tate（Player縦）；int：Pt_yoko（Player横）
//	引数：int：Mon_tate（敵縦）；int：Mon_yoko（敵横）;int：Jub_Side(Player方向）
//	引数：int：HP（敵体力値）；const char  *：SCENE（背景の位置）
//	返値：int*（敵縦；敵横；敵体力値）
//=========================================================
int*  BOSS_Att(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int Jub_Side, int HP, const char   *SCENE){
	static int Rut[3];
	int ATT_YOKO;
	int ATT_TATE;
	switch (Jub_Side)
	{
	case SIDE_LEFT:
		ATT_YOKO = Pt_yoko -2- (ATTACK_HEIGHT_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x = 0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (BOSS_WIDTH * 2); m++){
					for (int n = 0; n < BOSS_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							BOSSCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko -= 4;
							HP -= 1;
							
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								BOSSr_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								BossDead_Disp(Mon_tate, Mon_yoko, SCENE);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_RIGHT:
		ATT_YOKO = Pt_yoko +2+ (PLAYER_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x = 0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (BOSS_WIDTH * 2); m++){
					for (int n = 0; n < BOSS_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							BOSSCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko += 4;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								BOSSl_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								BossDead_Disp(Mon_tate, Mon_yoko, SCENE);

							}
						}
					}
				}
			}
		}
		break;
	case SIDE_UP:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate-1 - ATTACK_WIDTH_HEIGHT + 1;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (BOSS_WIDTH * 2); m++){
					for (int n = 0; n < BOSS_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							BOSSCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate -= 2;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								BOSSb_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								BossDead_Disp(Mon_tate, Mon_yoko, SCENE);

							}
						}
					}
				}
			}
		}
		break;
	case SIDE_DOWN:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate+1 + PLAYER_HEIGHT - 1;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (BOSS_WIDTH * 2); m++){
					for (int n = 0; n < BOSS_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							
							BOSSCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate += 2;
							HP -= 1;
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								BOSSp_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								BossDead_Disp(Mon_tate, Mon_yoko, SCENE);

							}
						}
					}
				}
			}
		}
		break;
		break;
	default:
		break;
	}

	*Rut = Mon_tate;
	*(Rut + 1) = Mon_yoko;
	*(Rut + 2) = HP;
	return Rut;


}


//=========================================================
//ATTLORD判定関数定義
//	引数：int：Pt_tate（Player縦）；int：Pt_yoko（Player横）
//	引数：int：Mon_tate（敵縦）；int：Mon_yoko（敵横）;int：Jub_Side(Player方向）
//	引数：int：HP（敵体力値）；const char  *：SCENE（背景の位置）
//	返値：int*（敵縦；敵横；敵体力値）
//=========================================================
int*  LORD_Att(int Pt_tate, int Pt_yoko, int Mon_tate, int Mon_yoko, int Jub_Side, int HP, const char   *SCENE){
	static int Rut[3];
	int ATT_YOKO;
	int ATT_TATE;
	switch (Jub_Side)
	{
	case SIDE_LEFT:
		ATT_YOKO = Pt_yoko-2 - (ATTACK_HEIGHT_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x = 0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (LORD_WIDTH * 2); m++){
					for (int n = 0; n < LORD_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){

							LORDCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko -= 4;
							HP -= 1;
							LORD_HP(HP);
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								LORDr_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
								PLAYWAVE(DEAD_Sound, 0);
								STOPWAVE(DEAD_Sound);
								CLOSEWAVE(DEAD_Sound);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_RIGHT:
		ATT_YOKO = Pt_yoko +2+ (PLAYER_WIDTH * 2);
		ATT_TATE = Pt_tate;
		for (int x = 0; x < (ATTACK_HEIGHT_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_HEIGHT_HEIGHT; y++){
				for (int m = 0; m < (LORD_WIDTH * 2); m++){
					for (int n = 0; n < LORD_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){

							LORDCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_yoko += 4;
							HP -= 1;
							LORD_HP(HP);
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								LORDl_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
								PLAYWAVE(DEAD_Sound, 0);
								STOPWAVE(DEAD_Sound);
								CLOSEWAVE(DEAD_Sound);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_UP:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate - 1 - ATTACK_WIDTH_HEIGHT + 1;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (LORD_WIDTH * 2); m++){
					for (int n = 0; n < LORD_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){
							LORDCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate -= 2;
							HP -= 1;
							LORD_HP(HP);
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								LORDb_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
								PLAYWAVE(DEAD_Sound, 0);
								STOPWAVE(DEAD_Sound);
								CLOSEWAVE(DEAD_Sound);
							}
						}
					}
				}
			}
		}
		break;
	case SIDE_DOWN:
		ATT_YOKO = Pt_yoko - (ATTACK_WIDTH_WIDTH - PLAYER_WIDTH);
		ATT_TATE = Pt_tate + 1 + PLAYER_HEIGHT - 1;
		for (int x = 0; x < (ATTACK_WIDTH_WIDTH * 2); x++){
			for (int y = 0; y < ATTACK_WIDTH_HEIGHT; y++){
				for (int m = 0; m < (LORD_WIDTH * 2); m++){
					for (int n = 0; n < LORD_HEIGHT; n++){
						if (((ATT_YOKO + x) == (Mon_yoko + m)) && ((ATT_TATE + y) == (Mon_tate + n))){

							LORDCL_Display(Mon_tate, Mon_yoko, SCENE);
							Mon_tate += 2;
							HP -= 1;
							LORD_HP(HP);
							if (HP > 0){
								int ATT_Sound = OPENWAVE(FILENAME_PLAYERATTACK);
								PLAYWAVE(ATT_Sound, 0);
								LORDp_Display(Mon_tate, Mon_yoko);
								STOPWAVE(ATT_Sound);
								CLOSEWAVE(ATT_Sound);
							}
							else
							{
								int DEAD_Sound = OPENWAVE(FILENAME_DEAD_SOUND);
								PLAYWAVE(DEAD_Sound, 0);
								STOPWAVE(DEAD_Sound);
								CLOSEWAVE(DEAD_Sound);
							}
						}
					}
				}
			}
		}
		break;
		break;
	default:
		break;
	}
	*Rut = Mon_tate;
	*(Rut + 1) = Mon_yoko;
	*(Rut + 2) = HP;
	return Rut;


}