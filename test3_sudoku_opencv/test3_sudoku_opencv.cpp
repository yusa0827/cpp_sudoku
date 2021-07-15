// test3_sudoku_opencv.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define img_size_ 450 //9 * 50 

#include <iostream>
#include <opencv2/opencv.hpp>
#include "sudoku_3N_.h"


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
	int s[10][10] = { 0 };
	s[1][6] = 4;
	s[1][8] = 5;
	s[2][1] = 1;
	s[2][3] = 2;
	s[2][6] = 6;
	s[3][5] = 8;
	s[3][8] = 1;
	s[4][2] = 6;
	s[4][4] = 7;
	s[4][6] = 9;
	s[4][9] = 4;
	s[5][3] = 9;
	s[5][7] = 8;
	s[6][1] = 4;
	s[6][4] = 8;
	s[6][6] = 1;
	s[6][8] = 2;
	s[7][2] = 7;
	s[7][5] = 6;
	s[8][6] = 8;
	s[8][7] = 4;
	s[8][9] = 2;
	s[9][2] = 3;
	s[9][4] = 9;
	//画像の表示
	for (int tate_draw = 1; tate_draw <= 9; tate_draw++) {
		for (int yoko_draw = 1; yoko_draw <= 9; yoko_draw++) {
			//文字が初期化されていないマスを
			if (s[tate_draw][yoko_draw] != 0) {
				cv::putText(image, std::to_string(s[tate_draw][yoko_draw]), cv::Point(50 * (yoko_draw - 1), 50 * tate_draw), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
			}
		}
	}

	cv::imshow(std::to_string(1), image);


	//加算用変数 N番の数字が多い範囲をプロット [tate][yoko][Nth]
	/*加算される条件
	特定の値以外の定数である
	特定の値の列、行、エリアである
	*/


	//bool_num_[縦][横][指定文字] 1に初期化
	bool bool_num_[10][10][10];
	for (int N_1 = 1; N_1 <= 9; N_1++) {
		for (int N_2 = 1; N_2 <= 9; N_2++) {
			for (int N_3 = 1; N_3 <= 9; N_3++) {
				bool_num_[N_1][N_2][N_3] = 1;
			}
		}
	}


	//特徴量マップ用変数
	int f_map[10][10] = { 0 };

	//表用の文字を指定
	std::string space_ = " ";//文字のためのスペース
	std::string vertical_ = "|";//縦線
	std::string horizontal_ = "-";//横線

	//3次元的に値を可視化している
	for (int number_ = 1; number_ <= 9; number_++) {

		// 1とそれ以外以外の値の範囲をマッピング
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				//0 以外かつ特定番号1以外のとき
				if (s[i][j] != 0 && s[i][j] != number_) {
					//インクリメント
					//bool_num[i][j] = false;
					bool_num_[i][j][number_] = false;
				}

				//特定の値の列、行
				if (s[i][j] == number_) {
					//行　横
					for (int row = 1; row <= 9; row++) {
						//bool_num[i][row] = false;
						bool_num_[i][row][number_] = false;
					}

					//列　縦
					for (int col = 1; col <= 9; col++) {
						//bool_num[col][j] = false;
						bool_num_[col][j][number_] = false;
					}

				}

				//特定の値の列、行、エリアである
				if (s[i][j] == number_) {
					//スタート範囲
					int start_tate;
					int start_yoko;

					//縦のエリアを探索
					if (1 <= i && i <= 3) {
						start_tate = 1;
					}
					else if (4 <= i && i <= 6) {
						start_tate = 4;

					}
					else {
						start_tate = 7;
					}
					//横のエリアを探索
					if (1 <= j && j <= 3) {
						start_yoko = 1;
					}
					else if (4 <= j && j <= 6) {
						start_yoko = 4;

					}
					else {
						start_yoko = 7;
					}

					//エリアに加算する
					for (int i_ = start_tate; i_ < start_tate + 3; i_++) {

						for (int j_ = start_yoko; j_ < start_yoko + 3; j_++) {
							//bool_num[i_][j_] = false;
							bool_num_[i_][j_][number_] = false;
						}
					}
				}
			}
		}


		//　number_ が存在する範囲
		std::cout << std::endl;
		std::cout << "数字" << number_ << "が存在しうる範囲" << std::endl;

		//N番目における表を作成
		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
		for (int j = 0; j < 3; j++) {
			//　1から3行目
			for (int i = j * 3 + 1; i < (j + 1) * 3 + 1; i++) {
				std::cout << vertical_ << bool_num_[i][1][number_] << bool_num_[i][2][number_] << bool_num_[i][3][number_] << vertical_
					<< bool_num_[i][4][number_] << bool_num_[i][5][number_] << bool_num_[i][6][number_] << vertical_
					<< bool_num_[i][7][number_] << bool_num_[i][8][number_] << bool_num_[i][9][number_] << vertical_ << std::endl;
			}

			std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
				<< horizontal_ << horizontal_ << horizontal_ << horizontal_
				<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
		}

		std::cout << std::endl;

	}




	//3次元的な特徴を2次元的な特徴に落とし込む
	//bool_num_[縦][横][指定文字] 1　の要素を　int f_map[縦][横]に加算する
	for (int N_3_ = 1; N_3_ <= 9; N_3_++) {
		for (int N_2_ = 1; N_2_ <= 9; N_2_++) {
			for (int N_1_ = 1; N_1_ <= 9; N_1_++) {
				//trueはチェックを潜り抜けた生き残り
				if (bool_num_[N_1_][N_2_][N_3_] == true) {
					f_map[N_1_][N_2_]++;
				}
			}
		}
	}


	std::cout << "特徴量マップ　値が大きいとが存在しうる可能性が高い" << std::endl;
	//"特徴量マップの作成
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	for (int j = 0; j < 3; j++) {

		//　1から3行目
		for (int i = j * 3 + 1; i < (j + 1) * 3 + 1; i++) {

			std::cout << vertical_ << f_map[i][1] << f_map[i][2] << f_map[i][3] << vertical_
				<< f_map[i][4] << f_map[i][5] << f_map[i][6] << vertical_
				<< f_map[i][7] << f_map[i][8] << f_map[i][9] << vertical_ << std::endl;
		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}

	std::cout << std::endl;


	/*
特徴量マップ　値が大きいとが存在しうる可能性が高い
|524|350|505|
|040|240|354|
|535|304|504|
-------------
|404|030|310|
|430|543|035|
|013|020|505|
-------------
|404|503|435|
|333|340|040|
|405|053|435|
-------------
	*/



	/* 更なるチェック 各マスにチェックする
	bool_num_[i_][j_][number_]
	・3*3エリア内で1が一つのみだったら、それは定数

	・特徴マップで値が1だったら、それは定数
	*/

	//3*3エリア内で1が一つのみだったら、それは定数
	//一時的な座標の保存場所
	int save_tate_;
	int save_yoko_;
	//3*3 のインクリメンター
	int inclimenter = 0;
	//数値を順番に代入
	std::cout << "3 * 3エリア内で1が１つのみ" << std::endl;
	for (int number_ = 1; number_ <= 9; number_++) {
		//std::cout << "number_ = "<< number_ << std::endl;
		//縦に進ませる処理
		for (int tate_tate = 0; tate_tate < 3; tate_tate++) {
			//左ブロック目 3*3 を走査
			inclimenter = 0;
			for (int tate_ = tate_tate * 3 + 1; tate_ <= tate_tate * 3 + 3; tate_++) {
				for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {

						++inclimenter;
						save_tate_ = tate_;
						save_yoko_ = yoko_;

					}
				}
			}
			//もしインクリメントが1そのさいに獲得した座標は大事
			if (inclimenter == 1) {
				std::cout << "エリアが確定しました" << "number_ = " << number_
					<< ",save_ss_ = " << save_tate_ << ",save_dd_ = " << save_yoko_ << "に1がありました。" << std::endl;
				s[save_tate_][save_yoko_] = number_;

			}

			//中央ブロック目
			inclimenter = 0;
			for (int tate_ = tate_tate * 3 + 1; tate_ <= tate_tate * 3 + 3; tate_++) {
				for (int yoko_ = 4; yoko_ <= 6; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {

						++inclimenter;
						save_tate_ = tate_;
						save_yoko_ = yoko_;

					}
				}
			}
			//もしインクリメントが1そのさいに獲得した座標は大事
			if (inclimenter == 1) {
				std::cout << "エリアが確定しました " << "number_ = " << number_
					<< ",save_ss_ = " << save_tate_ << ",save_dd_ = " << save_yoko_ << "に1がありました。" << std::endl;
				s[save_tate_][save_yoko_] = number_;

			}

			//右ブロック目
			inclimenter = 0;
			for (int tate_ = tate_tate * 3 + 1; tate_ <= tate_tate * 3 + 3; tate_++) {
				for (int yoko_ = 7; yoko_ <= 9; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {

						++inclimenter;
						save_tate_ = tate_;
						save_yoko_ = yoko_;

					}
				}
			}
			//もしインクリメントが1そのさいに獲得した座標は大事
			if (inclimenter == 1) {
				std::cout << "エリアが確定しました " << "number_ = " << number_
					<< ",save_ss_ = " << save_tate_ << ",save_dd_ = " << save_yoko_ << "に1がありました。" << std::endl;
				//値を代入する
				s[save_tate_][save_yoko_] = number_;
			}




		}


	}





	//・特徴マップで値が1だったら、それは定数 
	std::cout << "特徴マップで値が1だったら、それは定数" << std::endl;
		//for (int N_3_ = 1; N_3_ <= 9; N_3_++) {
	for (int N_2_ = 1; N_2_ <= 9; N_2_++) {
		for (int N_1_ = 1; N_1_ <= 9; N_1_++) {
			//特徴マップで1のとき、それはその値しか入らない
			//しかしそれだけではどこの数値化分からないので、探す
			if (f_map[N_2_][N_1_] == 1) {

				//その1はどこの数値かを調べる
				for (int N_3_ = 1; N_3_ <= 9; N_3_++) {
				
					//みつけたら、それを定数化する
					if (bool_num_[N_2_][N_1_][N_3_] == true) {
						//値を置き換えた。
						s[N_2_][N_1_] = N_3_;

						std::cout << "エリアが確定しました " << "number_ = " << N_3_
							<< ",save_ss_ = " << N_2_ << ",save_dd_ = " << N_1_ << "に1がありました。" << std::endl;
					}

				}

				//std::cout << "特徴マップで1でした N_2_ = "<< N_2_ <<", N_1_ = " << N_1_ << std::endl;

				

			}

		}
	}

	//画像の表示
	for (int tate_draw = 1; tate_draw <= 9; tate_draw++) {
		for (int yoko_draw = 1; yoko_draw <= 9; yoko_draw++) {
			//文字が初期化されていないマスを
			if (s[tate_draw][yoko_draw] != 0) {
				cv::putText(image, std::to_string(s[tate_draw][yoko_draw]), cv::Point(50 * (yoko_draw - 1), 50 * tate_draw), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
			}
		}
	}


	cv::imshow(std::to_string(2), image);









	cv::waitKey(0);

}


/*

	// // 画像，テキスト，位置（左下），フォント，スケール，色，線太さ，種類
	//int num_yoko;
	//int nun_tate;
	//num_yoko = 0;
	//nun_tate = num_yoko + 1;
	////cv::putText(image, "value_c", cv::Point(20, 100), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 1, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
	//cv::putText(image, "1", cv::Point(50 * num_yoko, 50 * nun_tate), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
	//num_yoko = 1;
	//nun_tate = num_yoko + 1;
	//cv::putText(image, "2", cv::Point(50 * num_yoko, 50 * nun_tate), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
	//num_yoko = 8;
	//nun_tate = num_yoko + 1;
	//cv::putText(image, "9", cv::Point(50 * num_yoko, 50 * nun_tate), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画

*/