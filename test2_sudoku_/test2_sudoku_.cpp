// test_sudoku_7_class.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <thread>
#include "class_sudoku_.h"

/*
・数独の辞書数をvector型にする
・クラスをポインタ型にする、使用したらメモリを消去　
・マルチスレッドで2つのスレッドを走らせる
・例えば((1,2),(1,3)(4,5))のように走らせる
・数独での
*/

int main()
{
	//初期化
	int init_s[10][10] = { 0 };
	//初期化 辞書_1
	init_s[1][8] = 8;
	init_s[1][9] = 7;
	init_s[3][3] = 1;
	init_s[3][4] = 2;
	init_s[3][5] = 3;
	init_s[4][3] = 2;
	init_s[4][6] = 4;
	init_s[5][3] = 3;
	init_s[5][7] = 5;
	init_s[6][4] = 8;
	init_s[6][6] = 5;
	init_s[6][8] = 6;
	init_s[7][5] = 1;
	init_s[7][7] = 3;
	init_s[8][1] = 8;
	init_s[8][6] = 7;
	init_s[9][1] = 6;

	//初期化 辞書_2
	//init_s[1][8] = 1;
	//init_s[2][1] = 4;
	//init_s[3][2] = 2;
	//init_s[4][5] = 5;
	//init_s[4][7] = 4;
	//init_s[4][9] = 7;
	//init_s[5][3] = 8;
	//init_s[5][7] = 3;
	//init_s[6][3] = 1;
	//init_s[6][5] = 9;
	//init_s[7][1] = 3;
	//init_s[7][4] = 4;
	//init_s[7][7] = 2;
	//init_s[8][2] = 5;
	//init_s[8][4] = 1;
	//init_s[9][4] = 8;
	//init_s[9][6] = 6;

	//初期化 辞書_2
	//init_s[1][6] = 4;
	//init_s[1][8] = 5;

	//init_s[2][1] = 1;
	//init_s[2][3] = 2;
	//init_s[2][4] = 6;

	//init_s[3][5] = 8;
	//init_s[3][8] = 1;

	//init_s[4][2] = 6;
	//init_s[4][4] = 7;
	//init_s[4][6] = 9;
	//init_s[4][9] = 4;

	//init_s[5][3] = 9;
	//init_s[5][7] = 8;

	//init_s[6][1] = 4;
	//init_s[6][4] = 8;
	//init_s[6][6] = 1;
	//init_s[6][8] = 2;

	//init_s[7][2] = 7;
	//init_s[7][5] = 6;

	//init_s[8][6] = 8;
	//init_s[8][7] = 4;
	//init_s[8][9] = 2;

	//init_s[9][2] = 3;
	//init_s[9][4] = 9;


	/*
-------------
|783|194|256|
|192|657|348|
|546|283|917|
-------------
|861|729|534|
|329|546|871|
|457|831|629|
-------------
|278|465|193|
|915|378|462|
|634|912|785|
-------------
	*/


	for (int i = 1; i < 10; i++) {

		//動的メモリでオブジェクトを生成　スタート値 = 1
		SUDOKU_* sudoku_i = new SUDOKU_(i);
		//初期値をクラスのオブジェクトに代入
		sudoku_i->insert_init_(init_s);
		//初期値により表を作成
		sudoku_i->make_dictionary();
		//表を表示
		sudoku_i->display_table();
		//探査の初期位置ポジション
		sudoku_i->detect_start_position();
		//探査を開始する マルチスレッド
		sudoku_i->MT_nth_single_shot_();



		delete sudoku_i;//メモリ開放

	}

}