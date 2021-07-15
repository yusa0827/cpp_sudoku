// test3_sudoku_opencv.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define img_size_ 450 //9 * 50 

#include <iostream>
#include <opencv2/opencv.hpp>
#include "sudoku_3N_Header.h"


/*
各指定文字における存在しうる範囲を求め、
さらにマスにおける存在しうる範囲を各指定文字でインクリメントして、可視化する
一番最初に特徴マップを作りたい！！！！
色塗りがしたかったけど、それは時間がかかるからやめる、後にする
*/

int main()
{

	int img_size = 450;
	//cv::Mat image = make_sudoku_image(img_size);


	//500x500の画像　CV_8UC3(8bit 3チャンネル)  黒→白
	cv::Mat image = cv::Mat::zeros(img_size + 5, img_size, CV_8UC3);
	cv::rectangle(image, cv::Point(0, 0), cv::Point(img_size + 5, img_size), cv::Scalar(255, 255, 255), -1, cv::LINE_8);

	//太線
	for (int i = 0; i <= 3; i++) { //450 / 3 = 150
		//　太さ8
		cv::line(image, cv::Point(150 * i, 0), cv::Point(150 * i, img_size), cv::Scalar(255, 0, 0), 5, cv::LINE_8);
		cv::line(image, cv::Point(0, 150 * i), cv::Point(img_size, 150 * i), cv::Scalar(255, 0, 0), 5, cv::LINE_8);
	}

	//細線
	for (int i = 0; i <= 9; i++) { //450 / 9 = 50  
		//　太さ8
		cv::line(image, cv::Point(50 * i, 0), cv::Point(50 * i, img_size), cv::Scalar(255, 0, 0), 1, cv::LINE_8);
		cv::line(image, cv::Point(0, 50 * i), cv::Point(img_size, 50 * i), cv::Scalar(255, 0, 0), 1, cv::LINE_8);

	}

	//数独用変数
	Sudoku sudoku;
	sudoku.s[1][6] = 4;
	sudoku.s[1][8] = 5;
	sudoku.s[2][1] = 1;
	sudoku.s[2][3] = 2;
	sudoku.s[2][4] = 6;
	sudoku.s[3][5] = 8;
	sudoku.s[3][8] = 1;
	sudoku.s[4][2] = 6;
	sudoku.s[4][4] = 7;
	sudoku.s[4][6] = 9;
	sudoku.s[4][9] = 4;
	sudoku.s[5][3] = 9;
	sudoku.s[5][7] = 8;
	sudoku.s[6][1] = 4;
	sudoku.s[6][4] = 8;
	sudoku.s[6][6] = 1;
	sudoku.s[6][8] = 2;
	sudoku.s[7][2] = 7;
	sudoku.s[7][5] = 6;
	sudoku.s[8][6] = 8;
	sudoku.s[8][7] = 4;
	sudoku.s[8][9] = 2;
	sudoku.s[9][2] = 3;
	sudoku.s[9][4] = 9;

	//初期画像の表示
	//sudoku.image_table(image, 0);



	//加算用変数 N番の数字が多い範囲をプロット [tate][yoko][Nth]
	/*加算される条件
	特定の値以外の定数である
	特定の値の列、行、エリアである
	*/

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

	int plus_ = 22;
	for (int i = 1; i < plus_; i++) {

		//数独を初期化 bool_num_[N_1][N_2][N_3] = 1 に初期化
		sudoku.initailize_bool_num_();


		//各番号において　0と1に分ける　0存在しない　1存在する可能性がある
		for (int number_ = 1; number_ <= 9; number_++) {

			//N番目に既存の値とかぶっていたら 0に変更
			//N番目の特徴マップ用の計算をしている
			sudoku.Nth_0_1_checker(number_);


			std::cout << "特別処理前" << std::endl;
			//N番目の特養マップを表示　1とそれ以外以外の値の範囲をマッピング
			sudoku.Nth_table_3(number_, i);

			// 3*3エリア内に縦または横のみに1がある場合に他の縦または横を消去し、
			//存在する範囲を1から0に変化させる
						
			std::cout << "特別処理後" << std::endl;
			sudoku.special_delete(number_);
					
					   
			//N番目の特養マップを表示　1とそれ以外以外の値の範囲をマッピング
			sudoku.Nth_table_3(number_, i);
		}




		//全体の特徴マップの変数を初期化する
		sudoku.initailize_f_map_2();

		//3次元特徴bool_num_ を2次元特徴にf_mapに加算する
		sudoku.decliment_3N_to_2N();



		/*
		俺は何を作ったのか
		それは1から9までのそれぞれの特徴マップにおいれ
		3*3のなかに列や行のみが3つ存在していいたら、他の行や列を削除する
		*/

		//それぞれの特徴量マップを表示
		sudoku.Nth_table_2();


		//特徴量マップの3*3のマスの中に1があったら、それを定数に変化させる
		for (int number_ = 1; number_ <= 9; number_++) {
			//3*3ブロックの処理　を9マス行う
			sudoku.change_1_to_number_in_3_3_blocks(number_);

		}


		//全体の特徴量マップの中に1があったら、それを定数に変化させる
		sudoku.find_1_in_f_map();


		//マップの和が0だとbreak
		if (sudoku.f_map_sum == 0) {
			//画像の表示
			sudoku.image_table(image, i);
			break;
		}



	}



	cv::waitKey(0);

}