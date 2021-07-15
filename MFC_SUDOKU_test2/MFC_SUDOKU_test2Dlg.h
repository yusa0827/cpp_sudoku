
// MFC_SUDOKU_test2Dlg.h : ヘッダー ファイル
//

#pragma once
#include "class_SUDOKU.h"
#include <string>




// CMFCSUDOKUtest2Dlg ダイアログ
class CMFCSUDOKUtest2Dlg : public CDialogEx//, public SUDOKU
{
// コンストラクション
public:
	CMFCSUDOKUtest2Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_SUDOKU_TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton58();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton36();
	afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton39();
	afx_msg void OnBnClickedButton41();
	afx_msg void OnBnClickedButton42();
	afx_msg void OnBnClickedButton43();
	afx_msg void OnBnClickedButton44();
	afx_msg void OnBnClickedButton45();
	afx_msg void OnBnClickedButton46();
	afx_msg void OnBnClickedButton47();
	afx_msg void OnBnClickedButton48();
	afx_msg void OnBnClickedButton49();
	afx_msg void OnBnClickedButton51();
	afx_msg void OnBnClickedButton52();
	afx_msg void OnBnClickedButton53();
	afx_msg void OnBnClickedButton54();
	afx_msg void OnBnClickedButton55();
	afx_msg void OnBnClickedButton56();
	afx_msg void OnBnClickedButton57();
	afx_msg void OnBnClickedButton59();
	afx_msg void OnBnClickedButton61();
	afx_msg void OnBnClickedButton62();
	afx_msg void OnBnClickedButton63();
	afx_msg void OnBnClickedButton64();
	afx_msg void OnBnClickedButton65();
	afx_msg void OnBnClickedButton66();
	afx_msg void OnBnClickedButton67();
	afx_msg void OnBnClickedButton68();
	afx_msg void OnBnClickedButton69();
	afx_msg void OnBnClickedButton71();
	afx_msg void OnBnClickedButton72();
	afx_msg void OnBnClickedButton73();
	afx_msg void OnBnClickedButton74();
	afx_msg void OnBnClickedButton75();
	afx_msg void OnBnClickedButton76();
	afx_msg void OnBnClickedButton77();
	afx_msg void OnBnClickedButton78();
	afx_msg void OnBnClickedButton79();
	afx_msg void OnBnClickedButton89();
	afx_msg void OnBnClickedButton81();
	afx_msg void OnBnClickedButton82();
	afx_msg void OnBnClickedButton83();
	afx_msg void OnBnClickedButton84();
	afx_msg void OnBnClickedButton85();
	afx_msg void OnBnClickedButton86();
	afx_msg void OnBnClickedButton87();
	afx_msg void OnBnClickedButton88();
	afx_msg void OnBnClickedButton91();
	afx_msg void OnBnClickedButton92();
	afx_msg void OnBnClickedButton93();
	afx_msg void OnBnClickedButton94();
	afx_msg void OnBnClickedButton95();
	afx_msg void OnBnClickedButton96();
	afx_msg void OnBnClickedButton97();
	afx_msg void OnBnClickedButton98();
	afx_msg void OnBnClickedButton99();
	//afx_msg void OnBnClickedButtonNum1();
	//afx_msg void OnBnClickedButtonNo1(int& Button_No_now, int& Button_No_back);
	//afx_msg void OnBnClickedButtonNumber1();
	afx_msg void OnBnClickedButtonNo9();
	afx_msg void OnBnClickedButtonNo2();
	afx_msg void OnBnClickedButtonNo3();
	afx_msg void OnBnClickedButtonNo4();
	afx_msg void OnBnClickedButtonNo5();
	afx_msg void OnBnClickedButtonNo6();
	afx_msg void OnBnClickedButtonNo7();
	afx_msg void OnBnClickedButtonNo8();
	afx_msg void OnBnClickedButtonNo1();

	//自作関数
	//void OnBnClickedButtonNo1_(int& Button_No_now, int& Button_No_back);
	void OnBnClickedButtonNoChanger();
	int Button_No_now = 1;//今の値
	int Button_No_back = 1;//前の値
	//1-9までの指定ボタン
	int Button_ID[10] = { 0, IDC_BUTTON_No1 , IDC_BUTTON_No2,IDC_BUTTON_No3,
IDC_BUTTON_No4 , IDC_BUTTON_No5,IDC_BUTTON_No6,
IDC_BUTTON_No7 , IDC_BUTTON_No8,IDC_BUTTON_No9 };


	//数独ボタンのIDを数列化する
	int sudoku_ID[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,IDC_BUTTON11,IDC_BUTTON12,IDC_BUTTON13,IDC_BUTTON14,IDC_BUTTON15,
		IDC_BUTTON16,IDC_BUTTON17,IDC_BUTTON18,IDC_BUTTON19},
		{0,IDC_BUTTON21,IDC_BUTTON22,IDC_BUTTON23,IDC_BUTTON24,IDC_BUTTON25,
		IDC_BUTTON26,IDC_BUTTON27,IDC_BUTTON28,IDC_BUTTON29},
		{0,IDC_BUTTON31,IDC_BUTTON32,IDC_BUTTON33,IDC_BUTTON34,IDC_BUTTON35,
		IDC_BUTTON36,IDC_BUTTON37,IDC_BUTTON38,IDC_BUTTON39},
		{0,IDC_BUTTON41,IDC_BUTTON42,IDC_BUTTON43,IDC_BUTTON44,IDC_BUTTON45,
		IDC_BUTTON46,IDC_BUTTON47,IDC_BUTTON48,IDC_BUTTON49},
		{0,IDC_BUTTON51,IDC_BUTTON52,IDC_BUTTON53,IDC_BUTTON54,IDC_BUTTON55,
		IDC_BUTTON56,IDC_BUTTON57,IDC_BUTTON58,IDC_BUTTON59},
		{0,IDC_BUTTON61,IDC_BUTTON62,IDC_BUTTON63,IDC_BUTTON64,IDC_BUTTON65,
		IDC_BUTTON66,IDC_BUTTON67,IDC_BUTTON68,IDC_BUTTON69},
		{0,IDC_BUTTON71,IDC_BUTTON72,IDC_BUTTON73,IDC_BUTTON74,IDC_BUTTON75,
		IDC_BUTTON76,IDC_BUTTON77,IDC_BUTTON78,IDC_BUTTON79},
		{0,IDC_BUTTON81,IDC_BUTTON82,IDC_BUTTON83,IDC_BUTTON84,IDC_BUTTON85,
		IDC_BUTTON86,IDC_BUTTON87,IDC_BUTTON88,IDC_BUTTON89},
		{0,IDC_BUTTON91,IDC_BUTTON92,IDC_BUTTON93,IDC_BUTTON94,IDC_BUTTON95,
		IDC_BUTTON96,IDC_BUTTON97,IDC_BUTTON98,IDC_BUTTON99}
	};

	//数独の値
	int s[10][10] = { 0 };

	//二回目のクリックで初期化
	bool only_one_click[10][10] = { true };

	//ボタンにより数独表の値を代入
	void sudoku_table_button_value(int tate_, int yoko_);

	//数独ボタンが二回押されているかの確認変数
	int keep_sudoku_button_value[10][10] = { 0 };

	//afx_msg void OnBnClickedButton101();
	afx_msg
		void OnBnClickedAnalysisButtonNoChanger();
	void OnBnClickedButtonreflect();

	//数独ボタン表の数独表に反映ための変数
	int sudoku_text[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
	{0,IDC_STATIC11,IDC_STATIC12,IDC_STATIC13,IDC_STATIC14,IDC_STATIC15,
	IDC_STATIC16,IDC_STATIC17,IDC_STATIC18,IDC_STATIC19},
		{0,IDC_STATIC21,IDC_STATIC22,IDC_STATIC23,IDC_STATIC24,IDC_STATIC25,
	IDC_STATIC26,IDC_STATIC27,IDC_STATIC28,IDC_STATIC29},
		{0,IDC_STATIC31,IDC_STATIC32,IDC_STATIC33,IDC_STATIC34,IDC_STATIC35,
	IDC_STATIC36,IDC_STATIC37,IDC_STATIC38,IDC_STATIC39},
		{0,IDC_STATIC41,IDC_STATIC42,IDC_STATIC43,IDC_STATIC44,IDC_STATIC45,
	IDC_STATIC46,IDC_STATIC47,IDC_STATIC48,IDC_STATIC49},
		{0,IDC_STATIC51,IDC_STATIC52,IDC_STATIC53,IDC_STATIC54,IDC_STATIC55,
	IDC_STATIC56,IDC_STATIC57,IDC_STATIC58,IDC_STATIC59},
		{0,IDC_STATIC61,IDC_STATIC62,IDC_STATIC63,IDC_STATIC64,IDC_STATIC65,
	IDC_STATIC66,IDC_STATIC67,IDC_STATIC68,IDC_STATIC69},
		{0,IDC_STATIC71,IDC_STATIC72,IDC_STATIC73,IDC_STATIC74,IDC_STATIC75,
	IDC_STATIC76,IDC_STATIC77,IDC_STATIC78,IDC_STATIC79},
		{0,IDC_STATIC81,IDC_STATIC82,IDC_STATIC83,IDC_STATIC84,IDC_STATIC85,
	IDC_STATIC86,IDC_STATIC87,IDC_STATIC88,IDC_STATIC89},
		{0,IDC_STATIC91,IDC_STATIC92,IDC_STATIC93,IDC_STATIC94,IDC_STATIC95,
	IDC_STATIC96,IDC_STATIC97,IDC_STATIC98,IDC_STATIC99}
	};

	afx_msg void OnBnClickedButtonAnalysis1();
	afx_msg void OnBnClickedButtonAnalysis2();
	afx_msg void OnBnClickedButtonAnalysis3();
	afx_msg void OnBnClickedButtonAnalysis4();
	afx_msg void OnBnClickedButtonAnalysis5();
	afx_msg void OnBnClickedButtonAnalysis6();
	afx_msg void OnBnClickedButtonAnalysis7();
	afx_msg void OnBnClickedButtonAnalysis8();
	afx_msg void OnBnClickedButtonAnalysis9();

	//解析を開始するボタン
	int analysis_s_bottun_ID[10] = {
		0,IDC_BUTTON_ANALYSIS1, IDC_BUTTON_ANALYSIS2,IDC_BUTTON_ANALYSIS3,
		IDC_BUTTON_ANALYSIS4,IDC_BUTTON_ANALYSIS5,IDC_BUTTON_ANALYSIS6,
		IDC_BUTTON_ANALYSIS7,IDC_BUTTON_ANALYSIS8,IDC_BUTTON_ANALYSIS9
	};

	//解析用数ボタン
	int ANALYSIS_Button_No_now = 1;//今の値
	int ANALYSIS_Button_No_back = 1;//前の値
	afx_msg void OnBnClickedButtondemoinput();

	//特徴マップの表示用変数
	int static_analysis[10][10] = {
		{0,0,0,0,0,0,0,0,0},
	{0,IDC_STATIC_ANALYSIS11,IDC_STATIC_ANALYSIS12,IDC_STATIC_ANALYSIS13,IDC_STATIC_ANALYSIS14,IDC_STATIC_ANALYSIS15,
	IDC_STATIC_ANALYSIS16,IDC_STATIC_ANALYSIS17,IDC_STATIC_ANALYSIS18,IDC_STATIC_ANALYSIS19},
		{0,IDC_STATIC_ANALYSIS21,IDC_STATIC_ANALYSIS22,IDC_STATIC_ANALYSIS23,IDC_STATIC_ANALYSIS24,IDC_STATIC_ANALYSIS25,
	IDC_STATIC_ANALYSIS26,IDC_STATIC_ANALYSIS27,IDC_STATIC_ANALYSIS28,IDC_STATIC_ANALYSIS29},
		{0,IDC_STATIC_ANALYSIS31,IDC_STATIC_ANALYSIS32,IDC_STATIC_ANALYSIS33,IDC_STATIC_ANALYSIS34,IDC_STATIC_ANALYSIS35,
	IDC_STATIC_ANALYSIS36,IDC_STATIC_ANALYSIS37,IDC_STATIC_ANALYSIS38,IDC_STATIC_ANALYSIS39},
		{0,IDC_STATIC_ANALYSIS41,IDC_STATIC_ANALYSIS42,IDC_STATIC_ANALYSIS43,IDC_STATIC_ANALYSIS44,IDC_STATIC_ANALYSIS45,
	IDC_STATIC_ANALYSIS46,IDC_STATIC_ANALYSIS47,IDC_STATIC_ANALYSIS48,IDC_STATIC_ANALYSIS49},
		{0,IDC_STATIC_ANALYSIS51,IDC_STATIC_ANALYSIS52,IDC_STATIC_ANALYSIS53,IDC_STATIC_ANALYSIS54,IDC_STATIC_ANALYSIS55,
	IDC_STATIC_ANALYSIS56,IDC_STATIC_ANALYSIS57,IDC_STATIC_ANALYSIS58,IDC_STATIC_ANALYSIS59},
		{0,IDC_STATIC_ANALYSIS61,IDC_STATIC_ANALYSIS62,IDC_STATIC_ANALYSIS63,IDC_STATIC_ANALYSIS64,IDC_STATIC_ANALYSIS65,
	IDC_STATIC_ANALYSIS66,IDC_STATIC_ANALYSIS67,IDC_STATIC_ANALYSIS68,IDC_STATIC_ANALYSIS69},
		{0,IDC_STATIC_ANALYSIS71,IDC_STATIC_ANALYSIS72,IDC_STATIC_ANALYSIS73,IDC_STATIC_ANALYSIS74,IDC_STATIC_ANALYSIS75,
	IDC_STATIC_ANALYSIS76,IDC_STATIC_ANALYSIS77,IDC_STATIC_ANALYSIS78,IDC_STATIC_ANALYSIS79},
		{0,IDC_STATIC_ANALYSIS81,IDC_STATIC_ANALYSIS82,IDC_STATIC_ANALYSIS83,IDC_STATIC_ANALYSIS84,IDC_STATIC_ANALYSIS85,
	IDC_STATIC_ANALYSIS86,IDC_STATIC_ANALYSIS87,IDC_STATIC_ANALYSIS88,IDC_STATIC_ANALYSIS89},
		{0,IDC_STATIC_ANALYSIS91,IDC_STATIC_ANALYSIS92,IDC_STATIC_ANALYSIS93,IDC_STATIC_ANALYSIS94,IDC_STATIC_ANALYSIS95,
	IDC_STATIC_ANALYSIS96,IDC_STATIC_ANALYSIS97,IDC_STATIC_ANALYSIS98,IDC_STATIC_ANALYSIS99},
	};

	/*数独解析用変数一式*/
	//////////////////////////////////////////////////////////////////////

		//数独　文字列
	std::string s_str[10][10];
	//各ナンバー　bool_num_[縦][横][指定文字] 1に初期化
	bool bool_num_[10][10][10];
	bool bool_num_cover[10][10][10];//再度、解くように仮保存
	//特徴量マップ用変数
	int f_map[10][10];
	int f_map_sum = 0;

	//1 数独を初期化
	void _1_1_initailize_bool_num_3N_and_feature_map_2N();
	//2 特定の数値における 0と1　処理  
	void _2_Nth_0_1_checker(int number_);

	//特別な処理　
	//3 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去	 
	void _2_4_special_delete_ver2(int number_);
	int one_counter_in_3_3 = 0;
	int row_or_col_counter = 0;

	//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化 5 
	void _2_5_change_1_to_number_in_3_3_blocks(int number_);

	//数独表に書き込む
	void show_sudoku_table_MFC();

	//4 3次元的な特徴を2次元的な特徴に落とし込む 
	void _4_decliment_3N_to_2N();

	//全体の特徴量マップの中に1があったら定数に変化 6 
	void find_1_in_each_f_map();

	//数独のはじめの表 7 
	void sudoku_table_first();

	//数独の最後
	void sudoku_table_end();

	//解析コメント数
	int comment_result_num = 0;

	//特徴マップを表示させる関数
	void f_map_table();

	//数字が聞いている範囲を特徴をマップ化する
	void number_working_map(int number_);
	std::string num_working[10][10][10];

	//数字が聞いている範囲を特徴をマップを初期化
	void _1_2_num_working_map_initialize();


	//数字被り　定数と一致した場合
	void _2_1_Nth_0_1_checker_1_TEISU(int number_);

	void show_Fmap();
	//初期化された特徴マップを書き込む
	void show_Fmap_init();

	//数字被り　3*3エリアに特定の数字が存在した場合
	void _2_2_Nth_0_1_checker_2_area_3_3(int number_);

	//数字被り　数字がある列と行は0にする
	void _2_3_Nth_0_1_checker_3_row_col_3_3(int number_);
	int _2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	//細分化しよう


	//確定した値を色を変えて数独に代入した表
	void sudoku_table_first_with_paint();

	//初期化 カバーを表示
	void _2_Nth_0_1_checker_for_cover(int number_);


	//もう一度解析するときには値が置き換わっているので、その情報を一時的に保存しておく。
	std::string num_working_cover[10][10][10];


	//special_delete_だと一括で消されてしまう
	//そのため細分化させる
	//void _3_special_delete_in_detale_overwrite(int number_, int tate_move, int yoko_move);
	bool show_sudoku_table = false;//初期値は表を表示させないのでfalse

	//なぞ
	//void nazo(int number_);
	int keep_tate_move = 0;//この変数は初期化する
	int keep_yoko_move = 0;

	//1から9までの特徴マップを足し合わせた合計値1を確定させる
	void detect_num_from_Fmap();

	//なぜそのマスがそのマスの縦と横の数字で決定するのか
	void investigate_num_on_block();
	//仮変数ナンバー
	int keep_number_ = 1;


	void find_1_in_each_f_map_one_time();
	int keep_col_row_num_tate = 0;
	int keep_col_row_num_yoko = 0;

	bool bool_find_1_in_each_f_map_one_time;
	bool break_keep_number_;
	int keep_number_array[10] = { 0 };//10個準備する

		// special_delete 用の変数
	int save_tate_ = 0;
	int save_yoko_ = 0;
	int start_1_tate = 0;//初期化プール用のスタート位置
	int start_2_tate = 0;//初期化プール用のスタート位置
	int start_1_yoko = 0;//初期化プール用のスタート位置
	int start_2_yoko = 0;//初期化プール用のスタート位置
	
	//3*3 のインクリメンター
	int inclimenter_3_3 = 0;
	//////////////////////////////////////////////////////////////////////
	afx_msg void OnBnClickedButtondemoinput2();
	afx_msg void OnBnClickedButtondemoinput3();
	afx_msg void OnBnClickedButtondemoinput4();
	afx_msg void OnBnClickedButtondemoinput5();
	afx_msg void OnBnClickedButtondemoinput6();
	afx_msg void OnBnClickedButtondemoinput7();
	//数独表に書き込む
	//void show_sudoku_table();

	afx_msg
		void delete_button_number_name();
	void OnBnClickedButtondemoinput8();
	void OnBnClickedButtondemoinput10();

	//解析のパーセンテージ
	void sudoku_analysis_percent();

	bool delete_button_number[10] = { false };
	//afx_msg void OnBnClickedButtondemoinput9();
	//afx_msg 
};
