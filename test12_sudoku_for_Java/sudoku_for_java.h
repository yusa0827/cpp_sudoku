#pragma once
#include <string>

class Sudoku {
	//表用の文字を指定
	std::string space_ = " ";//文字のためのスペース
	std::string vertical_ = "|";//縦線
	std::string horizontal_ = "-";//横線

	//3*3 のインクリメンター
	int inclimenter_3_3 = 0;

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


	//解析コメント用変数
	std::string result_[81];

	//解析結果の理由
	std::string reason_[81];


public:
	//数独　数値
	int s[10][10] = { 0 };
	//数独　文字列
	std::string s_str[10][10];
	//各ナンバー　bool_num_[縦][横][指定文字] 1に初期化
	bool bool_num_[10][10][10];
	//特徴量マップ用変数
	int f_map[10][10];
	//特徴量マップの和が0だとbreak
	int f_map_sum = 0;

	//数独を初期化
	void initailize_bool_num_3N_and_feature_map_2N();
	//特定の数値における 0と1　処理
	void Nth_0_1_checker(int number_);

	//特別な処理　
	// 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去	
	void special_delete_ver2(int number_);
	int one_counter_in_3_3 = 0;
	int row_or_col_counter = 0;

	//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
	void change_1_to_number_in_3_3_blocks(int number_);

	//3次元的な特徴を2次元的な特徴に落とし込む 
	void decliment_3N_to_2N();

	//全体の特徴量マップの中に1があったら定数に変化
	void find_1_in_each_f_map();
	   	 
	//数独のはじめの表
	void sudoku_table_first();

	//数独の最後
	void sudoku_table_end();

	//数独の解析コメント解析結果
	void commnet_result();

	//解析コメント数
	int comment_result_num = 0;


};


//数独の解析コメント解析結果
void Sudoku::commnet_result() {

	std::cout<<std::endl;

	//初期化
	for (int i = 0; i < comment_result_num; i++) {

		//コメントを出力
		std::cout << result_[i] << std::endl;

		//コメントを出力
		std::cout << reason_[i] << std::endl;
	}




	//初期化
	for (int i = 0; i < comment_result_num; i++) {

		//コメントを無にする
		result_[i] = "";

		//理由にする
		result_[i] = "";
	}

	//初期化する
	comment_result_num = 0;




}



//全体の特徴マップの変数を初期化する
void Sudoku::sudoku_table_first() {

	std::cout << std::endl;
	//横線
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;


	// jが1,2,3と増えると, iが0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//　1から3行目
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//　もし0の値の時は、[　]空白を文字列に代入する
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);
				//0だとスペース
				if (s[tate_][yoko_] == 0) {
					s_str[tate_][yoko_] = " ";
				}

			}

			std::cout << vertical_ << s_str[tate_][1] << s_str[tate_][2] << s_str[tate_][3] << vertical_
				<< s_str[tate_][4] << s_str[tate_][5] << s_str[tate_][6] << vertical_
				<< s_str[tate_][7] << s_str[tate_][8] << s_str[tate_][9] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}
}

//最後に表示させる
void Sudoku::sudoku_table_end() {

	std::cout << std::endl;
	//横線
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;


	// jが1,2,3と増えると, iが0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//　1から3行目
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//　もし0の値の時は、[　]空白を文字列に代入する
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);
				//0だとスペース
				if (s[tate_][yoko_] == 0) {
					s_str[tate_][yoko_] = " ";


					//解析が不十分でした
					std::string out = "解析が不十分でした";
					std::cout << out << std::endl;


				}

			}

			std::cout << vertical_ << s_str[tate_][1] << s_str[tate_][2] << s_str[tate_][3] << vertical_
				<< s_str[tate_][4] << s_str[tate_][5] << s_str[tate_][6] << vertical_
				<< s_str[tate_][7] << s_str[tate_][8] << s_str[tate_][9] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}
}

void Sudoku::special_delete_ver2(int number_) {

	for (int tate_move = 0; tate_move < 3; tate_move++) {

		for (int yoko_move = 0; yoko_move < 3; yoko_move++) {

			one_counter_in_3_3 = 0;
			// tate=4-6 yoko=4-6 のtrueをカウント 
			for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {
						one_counter_in_3_3++;
					}
				}
			}

			row_or_col_counter = 0;

			if (one_counter_in_3_3 == 3 || one_counter_in_3_3 == 2) {
				// tate固定
				for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
					row_or_col_counter = 0;//この初期化が組まれていないかもしてない
					for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
						if (bool_num_[tate_][yoko_][number_] == true) {
							row_or_col_counter++;
						}
						save_yoko_ = yoko_;
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

					if (one_counter_in_3_3 == row_or_col_counter) {

						for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;
						}

						for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;
						}
					}
				}


				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					row_or_col_counter = 0;//この初期化が組まれていないかもしてない
					for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
						if (bool_num_[tate_][yoko_][number_] == true) {
							row_or_col_counter++;
						}
						save_tate_ = tate_;
					}

					if (one_counter_in_3_3 == row_or_col_counter) {

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
							bool_num_[tate1][yoko_][number_] = false;
						}

						for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;
						}
					}
				}
			}		
		}
	}
}



//全体の特徴マップの中で値が1だったら定数に変換 
void Sudoku::find_1_in_each_f_map() {
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//特徴マップで1のときにその値しか入らない
			if (f_map[tate_][yoko_] == 1) {
				//その1はどこの数値かを調べる
				for (int number_ = 1; number_ <= 9; number_++) {
					//みつけたら、それを定数化する
					if (bool_num_[tate_][yoko_][number_] == true) {



						//数独の数値を代入
						s[tate_][yoko_] = number_;


						result_[comment_result_num] = "縦"+ std::to_string(tate_)+ "横" + std::to_string(yoko_) + "は" + std::to_string(number_);
						reason_[comment_result_num] = "ここのマスは" +std::to_string(number_)+ "以外が入るので" + std::to_string(number_);

						comment_result_num++;


					}
				}
			}
		}
	}
}


//3*3ブロックのなかに1があったら定数に変化
void Sudoku::change_1_to_number_in_3_3_blocks(int number_) {


	for (int tate_tate = 0; tate_tate < 3; tate_tate++) {

		for (int yoko_yoko = 0; yoko_yoko < 3; yoko_yoko++) {

			//左ブロック目 3*3 を走査
			inclimenter_3_3 = 0;
			for (int tate_ = tate_tate * 3 + 1; tate_ <= tate_tate * 3 + 3; tate_++) {
				for (int yoko_ = yoko_yoko * 3 + 1; yoko_ <= yoko_yoko * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {

						++inclimenter_3_3;
						save_tate_ = tate_;
						save_yoko_ = yoko_;

					}
				}
			}
			//3*3ブロックでインクリメント1のときに確定　座標を確保
			if (inclimenter_3_3 == 1) {

				//数独の数値を代入
				s[save_tate_][save_yoko_] = number_;

				



				result_[comment_result_num] = "縦" + std::to_string(save_tate_) + "横" + std::to_string(save_yoko_) + "は" + std::to_string(number_);
				reason_[comment_result_num] = "ここのマスの3*3は残り一つのため" + std::to_string(number_) + "が入る";

				comment_result_num++;


			}

		}			   
	}

}


void Sudoku::decliment_3N_to_2N() {

	f_map_sum = 0;

	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
				//trueはチェックを潜り抜けた生き残り
				if (bool_num_[tate_][yoko_][number_] == true) {
					f_map[tate_][yoko_]++;
					//全体の特徴マップの和が0だとブレイク
					f_map_sum++;
				}
			}
		}
	}


}

void Sudoku::Nth_0_1_checker(int number_) {
	// 1とそれ以外以外の値の範囲をマッピング
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//0 以外かつ特定番号1以外のとき
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;
			}

			//特定の値の列、行
			if (s[tate_][yoko_] == number_) {
				//行　横
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;
				}

				//列　縦
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;
				}

			}

			//特定の値の列、行、エリアである
			if (s[tate_][yoko_] == number_) {
				//スタート範囲
				int start_tate;
				int start_yoko;

				//縦のエリアを探索
				if (1 <= tate_ && tate_ <= 3) {
					start_tate = 1;
				}
				else if (4 <= tate_ && tate_ <= 6) {
					start_tate = 4;
				}
				else {
					start_tate = 7;
				}
				//横のエリアを探索
				if (1 <= yoko_ && yoko_ <= 3) {
					start_yoko = 1;
				}
				else if (4 <= yoko_ && yoko_ <= 6) {
					start_yoko = 4;
				}
				else {
					start_yoko = 7;
				}

				//エリアに加算する
				for (int i_ = start_tate; i_ < start_tate + 3; i_++) {
					for (int j_ = start_yoko; j_ < start_yoko + 3; j_++) {
						bool_num_[i_][j_][number_] = false;
					}
				}
			}
		}
	}



}


void Sudoku::initailize_bool_num_3N_and_feature_map_2N() {

	//同時に初期化
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//数独を初期化
				bool_num_[tate_][yoko_][number_] = true;

				//特徴特徴マップを初期化
				f_map[tate_][yoko_] = 0;
			}
		}
	}

}