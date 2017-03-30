#define				_CRT_SECURE_NO_WARNINGS
#include			<stdio.h>			//標準入出力関数を含む
#include			<stdlib.h>			//標準ライブラリー関数を含む
#include			<string.h>			//文字列関数
#include			<time.h>			//時間関数を含む

#define		FILENAME_TITLE					"./DATA/Title.csv"						//LOGOの画像
#define		TITLE_HEIGHT					20										//LOGOのサイズ（縦）
#define		TITLE_WIDTH						72										//LOGOのサイズ（横）

#define		FILENAME_ENTER					"./DATA/Enter.csv"						//Enterボタンの画像
#define		ENTER_HEIGHT					7										//Enterボタンのサイズ（縦）
#define		ENTER_WIDTH						34										//Enterボタンのサイズ（縦）

#define		FILENAME_PLAYERFRONTSIDE		"./DATA/player_p.csv"					//Playerの画像（表面）
#define		FILENAME_PLAYERBACKSIDE			"./DATA/player_b.csv"					//Playerの画像（裏面）
#define		FILENAME_PLAYERLEFTSIDE			"./DATA/player_l.csv"					//Playerの画像（左側）
#define		FILENAME_PLAYERRIGHTSIDE		"./DATA/player_r.csv"					//Playerの画像（右側）
#define		FILENAME_HP						"./DATA/HP.csv"							//HPの画像
#define		FILENAME_HP_1					"./DATA/HP_1.csv"						//HP-1の画像

#define		FILENAME_MONSTER				"./DATA/Monster.csv"					//Monsterの画像
#define		FILENAME_BOSSFRONTSIDE			"./DATA/BOSS_P.csv"						//BOSSの画像（表面）
#define		FILENAME_BOSSBACKSIDE			"./DATA/BOSS_B.csv"						//BOSSの画像（裏面）
#define		FILENAME_BOSSLEFTSIDE			"./DATA/BOSS_L.csv"						//BOSSの画像（左側）
#define		FILENAME_BOSSRIGHTSIDE			"./DATA/BOSS_R.csv"						//BOSSの画像（右側）
#define		FILENAME_BOSSDEAD				"./DATA/BOSS_D.csv"						//BOSSの画像（死ぬ）
#define		FILENAME_LORDFRONTSIDE			"./DATA/LORD_P.csv"						//LORDの画像（表面）
#define		FILENAME_LORDBACKSIDE			"./DATA/LORD_B.csv"						//LORDの画像（裏面）
#define		FILENAME_LORDLEFTSIDE			"./DATA/LORD_L.csv"						//LORDの画像（左側）
#define		FILENAME_LORDRIGHTSIDE			"./DATA/LORD_R.csv"						//LORDの画像（右側）

#define		FILENAME_OBSTACLE				"./DATA/obstacle.csv"					//障害物の画像
#define		FILENAME_OBSTACLER				"./DATA/obstacle_R.csv"					//障害物の画像（赤）

#define		FILENAME_SCENE1					"./DATA/Scene1.csv"						//背景１の画像
#define		FILENAME_SCENE2					"./DATA/Scene2.csv"						//背景２の画像
#define		FILENAME_SCENE3					"./DATA/Scene3.csv"						//背景３の画像
#define		FILENAME_SCENE4					"./DATA/Scene4.csv"						//背景４の画像
#define		FILENAME_SCENE5					"./DATA/Scene5.csv"						//背景５の画像
#define		FILENAME_SCENE6					"./DATA/Scene6.csv"						//背景６の画像
#define		FILENAME_SCENE7					"./DATA/Scene7.csv"						//背景７の画像

#define		FILENAME_ATTACKUP				"./DATA/attack_u.csv"					//Attackの画像（上）
#define		FILENAME_ATTACKDOWN				"./DATA/attack_d.csv"					//Attackの画像（下）
#define		FILENAME_ATTACKLEFT				"./DATA/attack_l.csv"					//Attackの画像（左）
#define		FILENAME_ATTACKRIGHT			"./DATA/attack_r.csv"					//Attackの画像（右）
#define		FILENAME_ATTACK_SOUND			"./DATA/Player_Attack.wav"				//Attackの音

#define		FILENAME_PLAYERATTACK			"./DATA/Player_ATT.wav"					//Monsterハートの音
#define		FILENAME_MONSTERATTACK			"./DATA/Monster_ATT.wav"				//Playerハートの音
#define		FILENAME_DEAD_SOUND				"./DATA/DEAD.wav"						//Monster死ぬ音

#define		FILENAME_ATTMUS					"./DATA/Attack.midi"					//戦うの時の音楽
#define		FILENAME_NOMMUS					"./DATA/norm.midi"						//普通の時の音楽
#define		FILENAME_WINMUS					"./DATA/WIN.midi"						//勝利の時の音楽
#define		FILENAME_OVERMUS				"./DATA/Over.midi"						//ゲームオーバーの時の音楽
#define		FILENAME_OPENMUS				"./DATA/Opening.midi"					//開場の時の音楽
#define		FILENAME_BOSSMUS				"./DATA/BOSS.midi"						//ボス戦の時の音楽


#define		FILENAME_OVER					"./DATA/over.csv"						//ゲームオーバーの画像
#define		OVER_HEIGHT						23										//ゲームオーバー画像サイズ（縦）
#define		OVER_WIDTH						28										//ゲームオーバー画像サイズ（横）


#define		FILENAME_WIN					"./DATA/WIN.csv"						//勝利の画像
#define		WIN_HEIGHT						40										//勝利画像サイズ（縦）
#define		WIN_WIDTH						36										//勝利画像サイズ（縦）

#define		BACKGROUND_COLOR				L_MAGENTA								//背景色
#define		WINDOWS_HEIGHT					80										//ウィンドウズサイズ（縦）
#define		WINDOWS_WIDTH					120										//ウィンドウズサイズ（横）
#define		PLAYER_WIDTH					5										//Playerの画像サイズ（横）
#define		PLAYER_HEIGHT					12										//Playerの画像サイズ（縦）
#define		HEAD_HEIGHT						5										//Playerの頭サイズ（縦）
#define		MONSTER_WIDTH					3										//Monsterの画像サイズ（横）
#define		MONSTER_HEIGHT					3										//Monsterの画像サイズ（縦）
#define		BOSS_WIDTH						7										//BOSSの画像サイズ（横）
#define		BOSS_HEIGHT						7										//BOSSの画像サイズ（縦）
#define		LORD_WIDTH						12										//LORDの画像サイズ（横）
#define		LORD_HEIGHT						12										//LORDの画像サイズ（縦）
#define		HP_WIDTH						4										//HPの画像サイズ（横）
#define		HP_HEIGHT						4										//HPの画像サイズ（縦）
#define		STRIDE_HEIGHT					3										//Playerの歩幅（縦）
#define		STRIDE_WIDTH					STRIDE_HEIGHT*2							//Playerの歩幅（横）
#define		LORD_STRIDE_HEIGHT				5										//Lordの歩幅（縦）
#define		LORD_STRIDE_WIDTH				LORD_STRIDE_HEIGHT*2					//Lordの歩幅（横）

#define		ATTACK_WIDTH_WIDTH				PLAYER_WIDTH+6							//ATTACKの画像サイズ（横）
#define		ATTACK_WIDTH_HEIGHT				4										//ATTACKの画像サイズ（縦）
#define		ATTACK_HEIGHT_WIDTH				ATTACK_WIDTH_HEIGHT						//ATTACKの画像サイズ（横）
#define		ATTACK_HEIGHT_HEIGHT			PLAYER_HEIGHT							//ATTACKの画像サイズ（縦）

#define		SIDE_DOWN						0										//方向判定（下）
#define		SIDE_UP							1										//方向判定（上）
#define		SIDE_LEFT						2										//方向判定（左）
#define		SIDE_RIGHT						3										//方向判定（右）
#define		OBSTACLE_HEIGHT					(7)										//障害物のサイズ（縦）
#define		OBSTACLE_WIDTH					(7)										//障害物のサイズ（横）

struct Player{
	int YOKO;	//Player基準横
	int TATE;	//Player基準縦
	int HP;		//Player体力
	int SIDE;	//Player方向判定
};//Player構造体

struct obstacle{
	int yoko;	//障害物基準横
	int tate;	//障害物基準縦
	int HP;		//障害物体力
};//障害物構造体

struct Monster{
	int yoko;	//敵基準横
	int tate;	//敵基準縦
	int HP;		//敵体力
	int SIDE;	//敵方向
};//敵構造体

//=========================================================
//	関数のプロトタイプ宣言
//=========================================================
void	Title();
void	Player_Display(int,int);											//	Player画面表示関数（表面）
void	PlayerB_Display( int,int);											//	Player画面表示関数（裏面）
void	PlayerR_Display( int, int);											//	Player画面表示関数（右側）
void	PlayerL_Display( int, int);											//	Player画面表示関数（左側）
void	PlayerCL_Display(int, int, const char   *);							//	Player画面削除関数
void	Scene_Disp(int *);													//	背景画面表示関数

int		Player_UPMove(int, int, const char *);								//	Player上移動関数
int		Player_DOWNMove(int, int, const char *);							//	Player下移動関数
int		Player_LEFTMove(int, int, const char *);							//	Player左移動関数
int		Player_RIGHTMove(int, int, const char *);							//	Player右移動関数

void	Player_Attack(int, int, const char *, int);
void	Attack_Display(int, int);											//	Attack画面表示関数（下）
void	Attack_W_Display(int, int);											//	Attack画面表示関数（下）｜白
void	AttackCL_Display(int, int, const char *);							//	Attack画面削除関数（下）

void	AttackUP_Display(int, int);											//	Attack画面表示関数（上）
void	AttackUP_W_Display(int, int);										//	Attack画面表示関数（上）｜白
void	AttackCLUP_Display(int, int, const char *);							//	Attack画面削除関数（上）

void	AttackLEFT_Display(int, int);										//	Attack画面表示関数（左）
void	AttackLEFT_W_Display(int, int);										//	Attack画面表示関数（左）｜白
void	AttackCLLEFT_Display(int, int, const char *);						//	Attack画面削除関数（左）

void	AttackRIGHT_Display(int, int);										//	Attack画面表示関数（右）
void	AttackRIGHT_W_Display(int, int);									//	Attack画面表示関数（右）｜白
void	AttackCLRIGHT_Display(int, int, const char *);						//	Attack画面削除関数（右）

int*	Monster_MOVE(int, int, const char *,int);							//敵移動関数
void	Monsters_Display(int, int);											//敵表示関数
void	MonstersCL_Display(int, int, const char *);							//敵画面削除関数
int*	Monster_Injured(int, int, int, int, int, int, const char *);		//敵ハート判定関数
int*	Monster_Att(int, int, int, int, int, int, const char   *);			//ATT敵判定関数

int*	BOSS_MOVE(int, int, const char   *, int);							//BOSS移動関数
void	BOSSp_Display(int, int);											//BOSS表示関数（表面）
void	BOSSb_Display(int, int);											//BOSS表示関数（裏面）
void	BOSSl_Display(int, int);											//BOSS表示関数（左側）
void	BOSSr_Display(int, int);											//BOSS表示関数（右側）
void	BOSSCL_Display(int, int, const char *);								//BOSS画面削除関数
int		BOSS_Side(int, int, int, int, int);									//BOSS方向変え関数
int*	BOSS_Injured(int, int, int, int, int, int, const char   *);			//BOSSハート判定関数
int*	BOSS_Att(int, int, int, int, int, int, const char   *);				//ATTBOSS判定関数

int*	LORD_MOVE(int, int, const char   *, int);							//	LORD移動関数
void	LORDp_Display(int, int);											//	LORD表示関数（表面）
void 	LORDb_Display(int, int);											//	LORD表示関数（裏面）
void 	LORDl_Display(int, int);											//	LORD表示関数（左側）
void 	LORDr_Display(int, int);											//	LORD表示関数（右側）
void	LORDCL_Display(int, int, const char *);								//	LORD画面削除関数
void	LORD_HP(int);
int*	LORD_Play(int, int, int, int, int, int, const char   *,int);
int*	LORD_Injured(int, int, int, int, int, int, const char   *);			//	LORDハート判定関数
int*	LORD_Att(int, int, int, int, int, int, const char   *);				//ATTLORD判定関数

void	Obstacle_Display(int, int);											//障害物表示関数
void	ObstacleR_Display(int, int);										//障害物表示関数（赤）

int*	Obstacle_Obs(int, int, int, int, int, const char   *);				//障害判定関数
int		Obstacle_Att(int, int, int, int, int, int, const char   *);			//障害物ハート判定関数

void	HP_Disp(int);														//Player体力表示関数
void	HP_CL(void);														//Player体力消し関数

void	MonsterDead_Disp(int, int, const char *);							//Monster死ぬ演出関数
void	BossDead_Disp(int, int, const char *);								//Boss死ぬ演出関数
void	LordrDead_Disp(int, int, const char *);								//Lord死ぬ演出関数

int*	MonsterOutOfRange(int, int,int, int, int, int, int, const char  *);	//
int*	BossOutOfRange(int, int, int, int, int, int, int, const char  *);	//
int*	LordOutOfRange(int, int, int, int, int, int, int, const char  *);	//

void	LordMissShow(int, int, const char *);


void	Game_Over();														//ゲームオーバー演出関数
void	Game_Win();															//勝利演出関数


