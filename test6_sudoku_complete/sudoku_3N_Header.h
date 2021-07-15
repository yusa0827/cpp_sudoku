#pragma once
#include <opencv2/opencv.hpp>


class Sudoku {
	//表用の文字を指定
	std::string space_ = " ";//文字のためのスペース
	std::string vertical_ = "|";//縦線
	std::string horizontal_ = "-";//横線

	//3*3マスにバツが2個か3この時に発動 ここに行と列の条件によって他ブロックの候補を消去
	int counter_del = 0;
	int counter_tate_yoko = 0;


	// special_delete 用の変数
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





public:
	//数独　数値
	int s[10][10] = { 0 };
	//各ナンバー　bool_num_[縦][横][指定文字] 1に初期化
	bool bool_num_[10][10][10];
	//特徴量マップ用変数
	int f_map[10][10];

	//マップの和が0だとbreak
	int f_map_sum = 0;

	//数独を初期化
	void initailize_bool_num_();
	//void initailize_f_map();
	//N番目における表を作成
	void Nth_table_3(int number_, int i);
	//特定の数値における 0と1　処理
	void Nth_0_1_checker(int number_);

	//3次元的な特徴を2次元的な特徴に落とし込む 
	void decliment_3N_to_2N();
	//二次元の特徴マッピングを表示
	void Nth_table_2();

	//3*3ブロックの処理　を9マス行う
	//void check_1_in_3_3_blocks(int number_);

	void find_1_in_f_map();
	//画像の表示
	void image_table(cv::Mat image, int i);


	//
	void initailize_f_map_2();

	void change_1_to_number_in_3_3_blocks(int number_);


	//特別な処理　
	// 3*3エリア内に縦または横のみに1がある場合に他の縦または横を消去し、
	//存在する範囲を1から0に変化させる
	void special_delete(int number_);


};


void Sudoku::special_delete(int number_) {

	for (int tate_move = 0; tate_move < 3; tate_move++) {


		/************************************************************************************************/
		c_46_13 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
			for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_13++;
				}
			}
		}

		c_46_13_33 = 0;

		if (c_46_13 == 3 || c_46_13 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_13_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 1; yoko <= 3; yoko++) {
					if (bool_num_[tate_fix][yoko][number_] == true) {
						c_46_13_33++;
					}
					save_yoko_ = yoko;
				}

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
					//std::cout << "tate_fix = " << tate_fix << std::endl;

					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}
				}
			}


			for (int yoko_fix = 1; yoko_fix <= 3; yoko_fix++) {
				c_46_13_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {
					if (bool_num_[tate][yoko_fix][number_] == true) {
						c_46_13_33++;
					}
					save_tate_ = tate;
				}

				if (c_46_13 == c_46_13_33) {

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
						bool_num_[tate1][yoko_fix][number_] = false;
					}

					for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
						bool_num_[tate1][yoko_fix][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
					}
				}
			}


		}
		/************************************************************************************************/

		/************************************************************************************************/
		c_46_46 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 4; yoko_ <= 6; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_46++;
				}
			}
		}

		c_46_46_33 = 0;

		if (c_46_46 == 3 || c_46_46 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_46_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 4; yoko <= 6; yoko++) {
					if (bool_num_[tate_fix][yoko][number_] == true) {
						c_46_46_33++;
					}
					save_yoko_ = yoko;
				}

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
					
					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}
				}
			}


			for (int yoko_fix = 4; yoko_fix <= 6; yoko_fix++) {
				c_46_46_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {
					if (bool_num_[tate][yoko_fix][number_] == true) {
						c_46_46_33++;
					}
					save_tate_ = tate;
				}

				if (c_46_46 == c_46_46_33) {

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
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
						bool_num_[tate1][yoko_fix][number_] = false;
						
					}

					for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
						bool_num_[tate1][yoko_fix][number_] = false;
						
					}
				}
			}


		}
		/************************************************************************************************/

		/************************************************************************************************/
		c_46_79 = 0;
		// tate=4-6 yoko=4-6 のtrueをカウント 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 7; yoko_ <= 9; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_79++;
				}
			}
		}

		c_46_79_33 = 0;

		if (c_46_79 == 3 || c_46_79 == 2) {
			// tate固定
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_79_33 = 0;//この初期化が組まれていないかもしてない
				for (int yoko = 7; yoko <= 9; yoko++) {
					if (bool_num_[tate_fix][yoko][number_] == true) {
						c_46_79_33++;
					}
					save_yoko_ = yoko;
				}

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

					for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
						bool_num_[tate_fix][yoko1][number_] = false;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						bool_num_[tate_fix][yoko1][number_] = false;
						
					}
				}
			}


			for (int yoko_fix = 7; yoko_fix <= 9; yoko_fix++) {
				c_46_79_33 = 0;//この初期化が組まれていないかもしてない
				for (int tate = tate_move * 3 + 1; tate <= tate_move * 3 + 3; tate++) {
										
					if (bool_num_[tate][yoko_fix][number_] == true) {
						c_46_79_33++;
					}
					save_tate_ = tate;
				}

				if (c_46_79 == c_46_79_33) {

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
						bool_num_[tate1][yoko_fix][number_] = false;
					}

					for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
						//std::cout << "前　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
						bool_num_[tate1][yoko_fix][number_] = false;
						//std::cout << "後　bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
					}
				}
			}


		}
		/************************************************************************************************/
	}


}


//画像の表示
void Sudoku::image_table(cv::Mat image, int i){
	for (int tate_draw = 1; tate_draw <= 9; tate_draw++) {
		for (int yoko_draw = 1; yoko_draw <= 9; yoko_draw++) {
			//文字が初期化されていないマスを
			if (s[tate_draw][yoko_draw] != 0) {
				cv::putText(image, std::to_string(s[tate_draw][yoko_draw]), cv::Point(50 * (yoko_draw - 1), 50 * tate_draw), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)の位置に大きさ2、太さ1の赤色文字で描画
			}
		}
	}

	cv::imshow(std::to_string(i), image);
}

//特徴マップの中で値が1だったら、それは定数 
void Sudoku::find_1_in_f_map() {
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

				
			}

		}
	}




}



//void Sudoku::display_1_to_9_map_from_3N() {
//
//	//3次元的に値を可視化している
//	for (int number_ = 1; number_ <= 9; number_++) {
//
//		//特定の数値における 0と1　処理
//		Nth_0_1_checker(number_);
//
//		// 1とそれ以外以外の値の範囲をマッピング
//
//		//　数値　number_ が存在する範囲
//		Nth_table_3(number_);
//	}
//}


//3*3ブロックの処理　を9マスを各数字で
//void Sudoku::check_numbers_in_3_3_blocks() {
//
//	for (int number_ = 1; number_ <= 9; number_++) {
//		//3*3ブロックの処理　を9マス行う
//		change_to_number_from_1_in_3_3_blocks(number_);
//
//	}
//
//}




//3*3ブロックの処理　を9マス行う
void Sudoku::change_1_to_number_in_3_3_blocks(int number_) {
	//3*3 のインクリメンター
	int inclimenter = 0;
	//3*3エリア内で1が一つのみだったら、それは定数
	//一時的な座標の保存場所
	int save_tate_;
	int save_yoko_;
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
		//3*3ブロックでインクリメント1のときに確定　座標を確保
		if (inclimenter == 1) {
			std::cout << "エリアが確定しました " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_
				<< " に1がありました。" << std::endl;
			s[save_tate_][save_yoko_] = number_;//値を代入する
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
		//3*3ブロックでインクリメント1のときに確定　座標を確保
		if (inclimenter == 1) {
			std::cout << "エリアが確定しました " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_
				<< " に1がありました。" << std::endl;
			s[save_tate_][save_yoko_] = number_;//値を代入する
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
		//3*3ブロックでインクリメント1のときに確定　座標を確保
		if (inclimenter == 1) {
			std::cout << "エリアが確定しました " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_ 
				<< " に1がありました。" << std::endl;
			s[save_tate_][save_yoko_] = number_;//値を代入する
		}

			   
	}

}


void Sudoku::initailize_f_map_2() {

	//特徴特徴マップを初期化
	for (int N_1 = 1; N_1 <= 9; N_1++) {
		for (int N_2 = 1; N_2 <= 9; N_2++) {
			f_map[N_1][N_2] = 0;
		}
	}

}

void Sudoku::decliment_3N_to_2N() {

	f_map_sum = 0;
	//

	for (int N_3_ = 1; N_3_ <= 9; N_3_++) {
		for (int N_2_ = 1; N_2_ <= 9; N_2_++) {
			for (int N_1_ = 1; N_1_ <= 9; N_1_++) {
				//trueはチェックを潜り抜けた生き残り
				if (bool_num_[N_1_][N_2_][N_3_] == true) {
					f_map[N_1_][N_2_]++;
					//全体の特徴マップの和が0だとブレイク
					f_map_sum++;
				}
			}
		}
	}


}

void Sudoku::Nth_0_1_checker(int number_) {
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



}


void Sudoku::Nth_table_2() {
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

}

void Sudoku::Nth_table_3(int number_, int i) {

	//　number_ が存在する範囲
	std::cout << i << "番目 数字" << number_ << "が存在しうる範囲" << std::endl;

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


//数独を初期化
void Sudoku::initailize_bool_num_() {

	for (int N_1 = 1; N_1 <= 9; N_1++) {
		for (int N_2 = 1; N_2 <= 9; N_2++) {
			for (int N_3 = 1; N_3 <= 9; N_3++) {
				bool_num_[N_1][N_2][N_3] = 1;
			}
		}
	}
}