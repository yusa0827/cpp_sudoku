﻿// test3_sudoku_opencv.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define img_size_ 450 //9 * 50 

#include <iostream>
#include <chrono>
#include <string>
#include "sudoku_for_java.h"

//test08_sudoku_complete を参照

int main()
{



	auto start = std::chrono::system_clock::now();

	//数独用変数
	Sudoku sudoku;
	//sudoku.s[1][6] = 4;
	//sudoku.s[1][8] = 5;
	//sudoku.s[2][1] = 1;
	//sudoku.s[2][3] = 2;
	//sudoku.s[2][4] = 6;
	//sudoku.s[3][5] = 8;
	//sudoku.s[3][8] = 1;
	//sudoku.s[4][2] = 6;
	//sudoku.s[4][4] = 7;
	//sudoku.s[4][6] = 9;
	//sudoku.s[4][9] = 4;
	//sudoku.s[5][3] = 9;
	//sudoku.s[5][7] = 8;
	//sudoku.s[6][1] = 4;
	//sudoku.s[6][4] = 8;
	//sudoku.s[6][6] = 1;
	//sudoku.s[6][8] = 2;
	//sudoku.s[7][2] = 7;
	//sudoku.s[7][5] = 6;
	//sudoku.s[8][6] = 8;
	//sudoku.s[8][7] = 4;
	//sudoku.s[8][9] = 2;
	//sudoku.s[9][2] = 3;
	//sudoku.s[9][4] = 9;


	//初期化 辞書_1
	sudoku.s[1][8] = 8;
	sudoku.s[1][9] = 7;
	sudoku.s[3][3] = 1;
	sudoku.s[3][4] = 2;
	sudoku.s[3][5] = 3;
	sudoku.s[4][3] = 2;
	sudoku.s[4][6] = 4;
	sudoku.s[5][3] = 3;
	sudoku.s[5][7] = 5;
	sudoku.s[6][4] = 8;
	sudoku.s[6][6] = 5;
	sudoku.s[6][8] = 6;
	sudoku.s[7][5] = 1;
	sudoku.s[7][7] = 3;
	sudoku.s[8][1] = 8;
	sudoku.s[8][6] = 7;
	sudoku.s[9][1] = 6;



	//数独の初期の表
	sudoku.sudoku_table_first();


	/* 更なるチェック 各マスにチェックする
bool_num_[i_][j_][number_]
・3*3エリア内で1が一つのみだったら、それは定数
・特徴マップで値が1だったら、それは定数
*/


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

	/*
-------------
|326|951|487|
|958|746|132|
|471|238|695|
-------------
|562|394|871|
|783|162|549|
|194|875|263|
-------------
|247|619|358|
|835|427|916|
|619|583|724|
-------------

	*/

	int plus_ = 22;
	for (int i = 1; i < plus_; i++) {

		//数独を初期化 全体の特徴マップの変数を初期化する
		sudoku.initailize_bool_num_3N_and_feature_map_2N();

		//各番号において　0と1に分ける　0存在しない　1存在する可能性がある
		for (int number_ = 1; number_ <= 9; number_++) {

			//N番目の特徴マップ 既存の値とかぶっていたら 0に変更
			sudoku.Nth_0_1_checker(number_);

			// 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去
			sudoku.special_delete_ver2(number_);

		}


		//3次元特徴bool_num_ を2次元特徴にf_mapに加算する
		sudoku.decliment_3N_to_2N();

		//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
		for (int number_ = 1; number_ <= 9; number_++) {
			//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
			sudoku.change_1_to_number_in_3_3_blocks(number_);
		}

		//全体の特徴量マップの中に1があったら定数に変化
		sudoku.find_1_in_each_f_map();

		//数独の初期の表
		sudoku.sudoku_table_first();
		
		//解析コメントを出力する
		sudoku.commnet_result();

		//マップの和が0だとbreak
		if (sudoku.f_map_sum == 0) {

			auto end = std::chrono::system_clock::now();

			std::cout << "試行回数 " << i << std::endl;

			auto diff = end - start;
			std::cout << "elapsed time = "
				<< std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
				<< " msec."
				<< std::endl;

			break;
		}

	}

	sudoku.sudoku_table_end();

}