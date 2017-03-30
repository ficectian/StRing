#define				_CRT_SECURE_NO_WARNINGS
#include			<stdio.h>			//�W�����o�͊֐����܂�
#include			<stdlib.h>			//�W�����C�u�����[�֐����܂�
#include			<string.h>			//������֐�
#include			<time.h>			//���Ԋ֐����܂�

#define		FILENAME_TITLE					"./DATA/Title.csv"						//LOGO�̉摜
#define		TITLE_HEIGHT					20										//LOGO�̃T�C�Y�i�c�j
#define		TITLE_WIDTH						72										//LOGO�̃T�C�Y�i���j

#define		FILENAME_ENTER					"./DATA/Enter.csv"						//Enter�{�^���̉摜
#define		ENTER_HEIGHT					7										//Enter�{�^���̃T�C�Y�i�c�j
#define		ENTER_WIDTH						34										//Enter�{�^���̃T�C�Y�i�c�j

#define		FILENAME_PLAYERFRONTSIDE		"./DATA/player_p.csv"					//Player�̉摜�i�\�ʁj
#define		FILENAME_PLAYERBACKSIDE			"./DATA/player_b.csv"					//Player�̉摜�i���ʁj
#define		FILENAME_PLAYERLEFTSIDE			"./DATA/player_l.csv"					//Player�̉摜�i�����j
#define		FILENAME_PLAYERRIGHTSIDE		"./DATA/player_r.csv"					//Player�̉摜�i�E���j
#define		FILENAME_HP						"./DATA/HP.csv"							//HP�̉摜
#define		FILENAME_HP_1					"./DATA/HP_1.csv"						//HP-1�̉摜

#define		FILENAME_MONSTER				"./DATA/Monster.csv"					//Monster�̉摜
#define		FILENAME_BOSSFRONTSIDE			"./DATA/BOSS_P.csv"						//BOSS�̉摜�i�\�ʁj
#define		FILENAME_BOSSBACKSIDE			"./DATA/BOSS_B.csv"						//BOSS�̉摜�i���ʁj
#define		FILENAME_BOSSLEFTSIDE			"./DATA/BOSS_L.csv"						//BOSS�̉摜�i�����j
#define		FILENAME_BOSSRIGHTSIDE			"./DATA/BOSS_R.csv"						//BOSS�̉摜�i�E���j
#define		FILENAME_BOSSDEAD				"./DATA/BOSS_D.csv"						//BOSS�̉摜�i���ʁj
#define		FILENAME_LORDFRONTSIDE			"./DATA/LORD_P.csv"						//LORD�̉摜�i�\�ʁj
#define		FILENAME_LORDBACKSIDE			"./DATA/LORD_B.csv"						//LORD�̉摜�i���ʁj
#define		FILENAME_LORDLEFTSIDE			"./DATA/LORD_L.csv"						//LORD�̉摜�i�����j
#define		FILENAME_LORDRIGHTSIDE			"./DATA/LORD_R.csv"						//LORD�̉摜�i�E���j

#define		FILENAME_OBSTACLE				"./DATA/obstacle.csv"					//��Q���̉摜
#define		FILENAME_OBSTACLER				"./DATA/obstacle_R.csv"					//��Q���̉摜�i�ԁj

#define		FILENAME_SCENE1					"./DATA/Scene1.csv"						//�w�i�P�̉摜
#define		FILENAME_SCENE2					"./DATA/Scene2.csv"						//�w�i�Q�̉摜
#define		FILENAME_SCENE3					"./DATA/Scene3.csv"						//�w�i�R�̉摜
#define		FILENAME_SCENE4					"./DATA/Scene4.csv"						//�w�i�S�̉摜
#define		FILENAME_SCENE5					"./DATA/Scene5.csv"						//�w�i�T�̉摜
#define		FILENAME_SCENE6					"./DATA/Scene6.csv"						//�w�i�U�̉摜
#define		FILENAME_SCENE7					"./DATA/Scene7.csv"						//�w�i�V�̉摜

#define		FILENAME_ATTACKUP				"./DATA/attack_u.csv"					//Attack�̉摜�i��j
#define		FILENAME_ATTACKDOWN				"./DATA/attack_d.csv"					//Attack�̉摜�i���j
#define		FILENAME_ATTACKLEFT				"./DATA/attack_l.csv"					//Attack�̉摜�i���j
#define		FILENAME_ATTACKRIGHT			"./DATA/attack_r.csv"					//Attack�̉摜�i�E�j
#define		FILENAME_ATTACK_SOUND			"./DATA/Player_Attack.wav"				//Attack�̉�

#define		FILENAME_PLAYERATTACK			"./DATA/Player_ATT.wav"					//Monster�n�[�g�̉�
#define		FILENAME_MONSTERATTACK			"./DATA/Monster_ATT.wav"				//Player�n�[�g�̉�
#define		FILENAME_DEAD_SOUND				"./DATA/DEAD.wav"						//Monster���ʉ�

#define		FILENAME_ATTMUS					"./DATA/Attack.midi"					//�키�̎��̉��y
#define		FILENAME_NOMMUS					"./DATA/norm.midi"						//���ʂ̎��̉��y
#define		FILENAME_WINMUS					"./DATA/WIN.midi"						//�����̎��̉��y
#define		FILENAME_OVERMUS				"./DATA/Over.midi"						//�Q�[���I�[�o�[�̎��̉��y
#define		FILENAME_OPENMUS				"./DATA/Opening.midi"					//�J��̎��̉��y
#define		FILENAME_BOSSMUS				"./DATA/BOSS.midi"						//�{�X��̎��̉��y


#define		FILENAME_OVER					"./DATA/over.csv"						//�Q�[���I�[�o�[�̉摜
#define		OVER_HEIGHT						23										//�Q�[���I�[�o�[�摜�T�C�Y�i�c�j
#define		OVER_WIDTH						28										//�Q�[���I�[�o�[�摜�T�C�Y�i���j


#define		FILENAME_WIN					"./DATA/WIN.csv"						//�����̉摜
#define		WIN_HEIGHT						40										//�����摜�T�C�Y�i�c�j
#define		WIN_WIDTH						36										//�����摜�T�C�Y�i�c�j

#define		BACKGROUND_COLOR				L_MAGENTA								//�w�i�F
#define		WINDOWS_HEIGHT					80										//�E�B���h�E�Y�T�C�Y�i�c�j
#define		WINDOWS_WIDTH					120										//�E�B���h�E�Y�T�C�Y�i���j
#define		PLAYER_WIDTH					5										//Player�̉摜�T�C�Y�i���j
#define		PLAYER_HEIGHT					12										//Player�̉摜�T�C�Y�i�c�j
#define		HEAD_HEIGHT						5										//Player�̓��T�C�Y�i�c�j
#define		MONSTER_WIDTH					3										//Monster�̉摜�T�C�Y�i���j
#define		MONSTER_HEIGHT					3										//Monster�̉摜�T�C�Y�i�c�j
#define		BOSS_WIDTH						7										//BOSS�̉摜�T�C�Y�i���j
#define		BOSS_HEIGHT						7										//BOSS�̉摜�T�C�Y�i�c�j
#define		LORD_WIDTH						12										//LORD�̉摜�T�C�Y�i���j
#define		LORD_HEIGHT						12										//LORD�̉摜�T�C�Y�i�c�j
#define		HP_WIDTH						4										//HP�̉摜�T�C�Y�i���j
#define		HP_HEIGHT						4										//HP�̉摜�T�C�Y�i�c�j
#define		STRIDE_HEIGHT					3										//Player�̕����i�c�j
#define		STRIDE_WIDTH					STRIDE_HEIGHT*2							//Player�̕����i���j
#define		LORD_STRIDE_HEIGHT				5										//Lord�̕����i�c�j
#define		LORD_STRIDE_WIDTH				LORD_STRIDE_HEIGHT*2					//Lord�̕����i���j

#define		ATTACK_WIDTH_WIDTH				PLAYER_WIDTH+6							//ATTACK�̉摜�T�C�Y�i���j
#define		ATTACK_WIDTH_HEIGHT				4										//ATTACK�̉摜�T�C�Y�i�c�j
#define		ATTACK_HEIGHT_WIDTH				ATTACK_WIDTH_HEIGHT						//ATTACK�̉摜�T�C�Y�i���j
#define		ATTACK_HEIGHT_HEIGHT			PLAYER_HEIGHT							//ATTACK�̉摜�T�C�Y�i�c�j

#define		SIDE_DOWN						0										//��������i���j
#define		SIDE_UP							1										//��������i��j
#define		SIDE_LEFT						2										//��������i���j
#define		SIDE_RIGHT						3										//��������i�E�j
#define		OBSTACLE_HEIGHT					(7)										//��Q���̃T�C�Y�i�c�j
#define		OBSTACLE_WIDTH					(7)										//��Q���̃T�C�Y�i���j

struct Player{
	int YOKO;	//Player���
	int TATE;	//Player��c
	int HP;		//Player�̗�
	int SIDE;	//Player��������
};//Player�\����

struct obstacle{
	int yoko;	//��Q�����
	int tate;	//��Q����c
	int HP;		//��Q���̗�
};//��Q���\����

struct Monster{
	int yoko;	//�G���
	int tate;	//�G��c
	int HP;		//�G�̗�
	int SIDE;	//�G����
};//�G�\����

//=========================================================
//	�֐��̃v���g�^�C�v�錾
//=========================================================
void	Title();
void	Player_Display(int,int);											//	Player��ʕ\���֐��i�\�ʁj
void	PlayerB_Display( int,int);											//	Player��ʕ\���֐��i���ʁj
void	PlayerR_Display( int, int);											//	Player��ʕ\���֐��i�E���j
void	PlayerL_Display( int, int);											//	Player��ʕ\���֐��i�����j
void	PlayerCL_Display(int, int, const char   *);							//	Player��ʍ폜�֐�
void	Scene_Disp(int *);													//	�w�i��ʕ\���֐�

int		Player_UPMove(int, int, const char *);								//	Player��ړ��֐�
int		Player_DOWNMove(int, int, const char *);							//	Player���ړ��֐�
int		Player_LEFTMove(int, int, const char *);							//	Player���ړ��֐�
int		Player_RIGHTMove(int, int, const char *);							//	Player�E�ړ��֐�

void	Player_Attack(int, int, const char *, int);
void	Attack_Display(int, int);											//	Attack��ʕ\���֐��i���j
void	Attack_W_Display(int, int);											//	Attack��ʕ\���֐��i���j�b��
void	AttackCL_Display(int, int, const char *);							//	Attack��ʍ폜�֐��i���j

void	AttackUP_Display(int, int);											//	Attack��ʕ\���֐��i��j
void	AttackUP_W_Display(int, int);										//	Attack��ʕ\���֐��i��j�b��
void	AttackCLUP_Display(int, int, const char *);							//	Attack��ʍ폜�֐��i��j

void	AttackLEFT_Display(int, int);										//	Attack��ʕ\���֐��i���j
void	AttackLEFT_W_Display(int, int);										//	Attack��ʕ\���֐��i���j�b��
void	AttackCLLEFT_Display(int, int, const char *);						//	Attack��ʍ폜�֐��i���j

void	AttackRIGHT_Display(int, int);										//	Attack��ʕ\���֐��i�E�j
void	AttackRIGHT_W_Display(int, int);									//	Attack��ʕ\���֐��i�E�j�b��
void	AttackCLRIGHT_Display(int, int, const char *);						//	Attack��ʍ폜�֐��i�E�j

int*	Monster_MOVE(int, int, const char *,int);							//�G�ړ��֐�
void	Monsters_Display(int, int);											//�G�\���֐�
void	MonstersCL_Display(int, int, const char *);							//�G��ʍ폜�֐�
int*	Monster_Injured(int, int, int, int, int, int, const char *);		//�G�n�[�g����֐�
int*	Monster_Att(int, int, int, int, int, int, const char   *);			//ATT�G����֐�

int*	BOSS_MOVE(int, int, const char   *, int);							//BOSS�ړ��֐�
void	BOSSp_Display(int, int);											//BOSS�\���֐��i�\�ʁj
void	BOSSb_Display(int, int);											//BOSS�\���֐��i���ʁj
void	BOSSl_Display(int, int);											//BOSS�\���֐��i�����j
void	BOSSr_Display(int, int);											//BOSS�\���֐��i�E���j
void	BOSSCL_Display(int, int, const char *);								//BOSS��ʍ폜�֐�
int		BOSS_Side(int, int, int, int, int);									//BOSS�����ς��֐�
int*	BOSS_Injured(int, int, int, int, int, int, const char   *);			//BOSS�n�[�g����֐�
int*	BOSS_Att(int, int, int, int, int, int, const char   *);				//ATTBOSS����֐�

int*	LORD_MOVE(int, int, const char   *, int);							//	LORD�ړ��֐�
void	LORDp_Display(int, int);											//	LORD�\���֐��i�\�ʁj
void 	LORDb_Display(int, int);											//	LORD�\���֐��i���ʁj
void 	LORDl_Display(int, int);											//	LORD�\���֐��i�����j
void 	LORDr_Display(int, int);											//	LORD�\���֐��i�E���j
void	LORDCL_Display(int, int, const char *);								//	LORD��ʍ폜�֐�
void	LORD_HP(int);
int*	LORD_Play(int, int, int, int, int, int, const char   *,int);
int*	LORD_Injured(int, int, int, int, int, int, const char   *);			//	LORD�n�[�g����֐�
int*	LORD_Att(int, int, int, int, int, int, const char   *);				//ATTLORD����֐�

void	Obstacle_Display(int, int);											//��Q���\���֐�
void	ObstacleR_Display(int, int);										//��Q���\���֐��i�ԁj

int*	Obstacle_Obs(int, int, int, int, int, const char   *);				//��Q����֐�
int		Obstacle_Att(int, int, int, int, int, int, const char   *);			//��Q���n�[�g����֐�

void	HP_Disp(int);														//Player�̗͕\���֐�
void	HP_CL(void);														//Player�̗͏����֐�

void	MonsterDead_Disp(int, int, const char *);							//Monster���ʉ��o�֐�
void	BossDead_Disp(int, int, const char *);								//Boss���ʉ��o�֐�
void	LordrDead_Disp(int, int, const char *);								//Lord���ʉ��o�֐�

int*	MonsterOutOfRange(int, int,int, int, int, int, int, const char  *);	//
int*	BossOutOfRange(int, int, int, int, int, int, int, const char  *);	//
int*	LordOutOfRange(int, int, int, int, int, int, int, const char  *);	//

void	LordMissShow(int, int, const char *);


void	Game_Over();														//�Q�[���I�[�o�[���o�֐�
void	Game_Win();															//�������o�֐�


