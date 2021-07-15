// test5_sudokku_delete_by_3_3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<assert.h>

void table(bool bool_num_[10][10][10]) {

	//表用の文字を指定
	std::string space_ = " ";//文字のためのスペース
	std::string vertical_ = "|";//縦線
	std::string horizontal_ = "-";//横線
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	for (int j = 0; j < 3; j++) {

		//　1から3行目
		for (int i = j * 3 + 1; i < (j + 1) * 3 + 1; i++) {

			std::cout << vertical_ << bool_num_[i][1][1] << bool_num_[i][2][1] << bool_num_[i][3][1] << vertical_
				<< bool_num_[i][4][1] << bool_num_[i][5][1] << bool_num_[i][6][1] << vertical_
				<< bool_num_[i][7][1] << bool_num_[i][8][1] << bool_num_[i][9][1] << vertical_ << std::endl;
		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}
	std::cout << std::endl;

}

int main()
{
  
	// bool_num_[tate][yoko][number]
	bool bool_num_[10][10][10] = { 0 };


	// 1番目
	//bool_num_[1][4][1] = 1;
	//bool_num_[1][5][1] = 1;
	//bool_num_[4][3][1] = 1;
	//bool_num_[4][7][1] = 1;
	//bool_num_[5][2][1] = 1;
	//bool_num_[5][3][1] = 1;
	//bool_num_[5][4][1] = 1;
	//bool_num_[5][5][1] = 1;
	//bool_num_[5][6][1] = 1;
	//bool_num_[5][9][1] = 1;
	//bool_num_[6][7][1] = 1;
	//bool_num_[7][3][1] = 0;
	//bool_num_[7][7][1] = 1;
	//bool_num_[7][9][1] = 1;
	//bool_num_[8][2][1] = 1;
	//bool_num_[8][3][1] = 1;
	//bool_num_[8][4][1] = 1;
	//bool_num_[8][5][1] = 1;
	//bool_num_[9][5][1] = 1;
	//bool_num_[9][7][1] = 1;
	//bool_num_[9][9][1] = 1;


	/*
-------------
|000|000|000|
|000|110|000|
|101|101|000|
-------------
|000|010|100|
|000|001|001|
|000|000|000|
-------------
|101|001|101|
|101|110|000|
|100|011|101|
-------------
	*/
	bool_num_[2][4][1] = 1;
	bool_num_[2][5][1] = 1;
	bool_num_[3][1][1] = 1;
	bool_num_[3][3][1] = 1;
	bool_num_[3][4][1] = 1;
	bool_num_[3][6][1] = 1;
	bool_num_[4][5][1] = 1; 
	bool_num_[4][7][1] = 1;
	bool_num_[5][6][1] = 1;
	bool_num_[5][9][1] = 1;
	bool_num_[7][1][1] = 1;
	bool_num_[7][3][1] = 1;
	bool_num_[7][6][1] = 1;
	bool_num_[7][7][1] = 1;
	bool_num_[7][9][1] = 1;
	bool_num_[8][1][1] = 1;
	bool_num_[8][3][1] = 1;
	bool_num_[8][4][1] = 1;
	bool_num_[8][5][1] = 1;
	bool_num_[9][1][1] = 1;
	bool_num_[9][5][1] = 1;
	bool_num_[9][6][1] = 1;
	bool_num_[9][7][1] = 1;
	bool_num_[9][9][1] = 1;






	//表を表示
	table(bool_num_);

	/*
	3*3まるでヒットした列をつぶす

	×××　××〇　×〇×　〇××
	〇〇〇　〇〇〇　〇〇〇　〇〇〇
	〇〇〇　〇〇〇　〇〇〇　〇〇〇

	・3*3で1を数える

	*/

	//int conter_3_3 = 0;//3*3のなかの1のカウンター
	//int counter_core = 0;//その行でのカウンター
	int save_tate_ = 0;
	int save_yoko_ = 0;
	int start_1_tate = 0;//初期化プール用のスタート位置
	int start_2_tate = 0;//初期化プール用のスタート位置
	int start_1_yoko = 0;//初期化プール用のスタート位置
	int start_2_yoko = 0;//初期化プール用のスタート位置



	int c_46_13 = 0;
	int c_46_13_33 = 0;

	int c_46_46 = 0;
	int c_46_46_33 = 0;

	int c_46_79;
	int c_46_79_33 = 0;

	// tate = 1,4, 6 
	for (int tate_move = 0; tate_move < 3; tate_move++) {


		/************************************************************************************************/
		c_46_13 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
			for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
				if (bool_num_[tate_][yoko_][1] == true) {
					c_46_13++;
				}
			}
		}

		c_46_13_33 = 0;
		std::cout << "c_46_13 = " << c_46_13 << std::endl;

		if (c_46_13 == 3 || c_46_13 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_13_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 1; yoko <= 3; yoko++) {
					if (bool_num_[tate_fix][yoko][1] == true) {
						c_46_13_33++;
					}
					save_yoko_ = yoko;
				}
				std::cout << "c_46_13_33 = " << c_46_13_33 << std::endl;

				if (save_yoko_ == 3) {
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {
					start_1_yoko = 1;
					start_2_yoko = 4;
				}

				if (c_46_13 == c_46_13_33) {
					std::cout << "tate_fix = " << tate_fix << std::endl;

					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}
				}
			}


			for (int yoko_fix = 1; yoko_fix <= 3; yoko_fix++) {
				c_46_13_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {
					if (bool_num_[tate][yoko_fix][1] == true) {
						c_46_13_33++;
					}
					save_tate_ = tate;
				}
				std::cout << "c_46_13_33 = " << c_46_13_33 << std::endl;

				if (c_46_13 == c_46_13_33) {
					std::cout << "yoko_fix = " << yoko_fix << std::endl;

					if (save_tate_ == 3) {
						start_1_tate = 4;
						start_2_tate = 7;
					}
					if (save_tate_ == 6) {
						start_1_tate = 1;
						start_2_yoko = 7;
					}
					if (save_tate_ == 9) {
						start_1_tate = 1;
						start_2_yoko = 4;
					}

					for (int tate1 = 1; tate1 <= 3; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}

					for (int tate1 = 7; tate1 <= 9; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}
				}
			}


		}
		//表を表示
		table(bool_num_);
		/************************************************************************************************/
			   		 	  	  
		/************************************************************************************************/
		c_46_46 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 4; yoko_ <= 6; yoko_++) {
				if (bool_num_[tate_][yoko_][1] == true) {
					c_46_46++;
				}
			}
		}

		c_46_46_33 = 0;
		std::cout << "c_46_46 = " << c_46_46 << std::endl;

		if (c_46_46 == 3 || c_46_46 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_46_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 4; yoko <= 6; yoko++) {
					if (bool_num_[tate_fix][yoko][1] == true) {
						c_46_46_33++;
					}
					save_yoko_ = yoko;
				}
				std::cout << "c_46_46_33 = " << c_46_46_33 << std::endl;

				if (save_yoko_ == 3) {
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {
					start_1_yoko = 1;
					start_2_yoko = 4;
				}

				if (c_46_46 == c_46_46_33) {
					std::cout << "tate_fix = " << tate_fix << std::endl;

					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}
				}
			}


			for (int yoko_fix = 4; yoko_fix <= 6; yoko_fix++) {
				c_46_46_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {
					if (bool_num_[tate][yoko_fix][1] == true) {
						c_46_46_33++;
					}
					save_tate_ = tate;
				}
				std::cout << "c_46_46_33 = " << c_46_46_33 << std::endl;

				if (c_46_46 == c_46_46_33) {
					std::cout << "yoko_fix = " << yoko_fix << std::endl;

					if (save_tate_ == 3) {
						start_1_tate = 4;
						start_2_tate = 7;
					}
					if (save_tate_ == 6) {
						start_1_tate = 1;
						start_2_yoko = 7;
					}
					if (save_tate_ == 9) {
						start_1_tate = 1;
						start_2_yoko = 4;
					}

					for (int tate1 = 1; tate1 <= 3; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}

					for (int tate1 = 7; tate1 <= 9; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}
				}
			}


		}
		//表を表示
		table(bool_num_);
		/************************************************************************************************/

		/************************************************************************************************/
		c_46_79 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 7; yoko_ <= 9; yoko_++) {
				if (bool_num_[tate_][yoko_][1] == true) {
					c_46_79++;
				}
			}
		}

		c_46_79_33 = 0;
		std::cout << "c_46_79 = " << c_46_79 << std::endl;

		if (c_46_79 == 3 || c_46_79 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_79_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 7; yoko <= 9; yoko++) {
					if (bool_num_[tate_fix][yoko][1] == true) {
						c_46_79_33++;
					}
					save_yoko_ = yoko;
				}
				std::cout << "c_46_79_33 = " << c_46_79_33 << std::endl;

				if (save_yoko_ == 3) {
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {
					start_1_yoko = 1;
					start_2_yoko = 4;
				}

				if (c_46_79 == c_46_79_33) {
					std::cout << "tate_fix = " << tate_fix << std::endl;

					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
						bool_num_[tate_fix][yoko1][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][1] << std::endl;
					}
				}
			}


			for (int yoko_fix = 7; yoko_fix <= 9; yoko_fix++) {
				c_46_79_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {

					std::cout << "bool_num_[" << tate << "][" << yoko_fix << "][" << 1 << "] = " << bool_num_[tate][yoko_fix][1] << std::endl;


					if (bool_num_[tate][yoko_fix][1] == true) {
						c_46_79_33++;
					}
					save_tate_ = tate;
				}
				std::cout << "c_46_79_33 = " << c_46_79_33 << std::endl;

				if (c_46_79 == c_46_79_33) {
					std::cout << "yoko_fix = " << yoko_fix << std::endl;

					if (save_tate_ == 3) {
						start_1_tate = 4;
						start_2_tate = 7;
					}
					if (save_tate_ == 6) {
						start_1_tate = 1;
						start_2_yoko = 7;
					}
					if (save_tate_ == 9) {
						start_1_tate = 1;
						start_2_yoko = 4;
					}

					for (int tate1 = start_1_tate; tate1 <= start_1_tate + 2; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}

					for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
						std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
						bool_num_[tate1][yoko_fix][1] = false;
						std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][1] << std::endl;
					}
				}
			}


		}
		//表を表示
		table(bool_num_);
		/************************************************************************************************/
	}






}




/*
9番目 数字1が存在しうる範囲
-------------
|000|110|000|
|000|000|000|
|000|000|000|
-------------
|001|000|100|
|010|000|001|
|000|000|000|
-------------
|001|000|101|
|011|110|000|
|000|010|101|
-------------

9番目 数字2が存在しうる範囲
-------------
|000|110|100|
|000|000|000|
|000|101|100|
-------------
|100|010|000|
|010|001|000|
|000|000|000|
-------------
|100|001|000|
|000|000|000|
|100|011|000|
-------------

9番目 数字3が存在しうる範囲
-------------
|001|100|101|
|000|100|101|
|001|101|101|
-------------
|000|000|000|
|000|000|000|
|000|000|000|
-------------
|000|001|101|
|000|100|000|
|000|000|000|
-------------

9番目 数字4が存在しうる範囲
-------------
|000|000|000|
|000|000|000|
|000|000|000|
-------------
|000|000|000|
|000|000|000|
|000|000|000|
-------------
|000|000|000|
|000|000|000|
|000|000|000|
-------------

9番目 数字5が存在しうる範囲
-------------
|000|000|000|
|000|110|000|
|101|101|000|
-------------
|000|010|100|
|000|001|001|
|000|000|000|
-------------
|101|001|101|
|101|110|000|
|100|011|101|
-------------

9番目 数字6が存在しうる範囲
-------------
|101|000|101|
|000|000|000|
|101|000|101|
-------------
|000|000|000|
|000|000|000|
|000|000|101|
-------------
|000|000|000|
|101|000|010|
|100|000|111|
-------------

9番目 数字7が存在しうる範囲
-------------
|100|010|101|
|000|010|101|
|100|001|101|
-------------
|000|000|000|
|000|000|000|
|000|000|000|
-------------
|000|000|000|
|000|010|000|
|000|011|101|
-------------

9番目 数字8が存在しうる範囲
-------------
|111|000|001|
|010|000|001|
|000|000|000|
-------------
|101|000|000|
|000|000|000|
|000|000|000|
-------------
|101|000|011|
|000|000|000|
|100|000|011|
-------------

9番目 数字9が存在しうる範囲
-------------
|110|010|101|
|010|010|101|
|100|000|101|
-------------
|000|000|000|
|000|000|000|
|000|000|101|
-------------
|100|000|111|
|110|000|010|
|000|000|000|
-------------
*/

