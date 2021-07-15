#pragma once
#include <string>
#include <Windows.h>

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
	int s_cover[10][10] = { 0 };
	//数独　文字列
	std::string s_str[10][10];
	std::string s_str_cover[10][10];
	//各ナンバー　bool_num_[縦][横][指定文字] 1に初期化
	bool bool_num_[10][10][10];
	bool bool_num_cover[10][10][10];//再度、解くように仮保存
	//特徴量マップ用変数
	int f_map[10][10];
	int f_map_cover[10][10];
	//特徴量マップの和が0だとbreak
	int f_map_sum = 0;

	//1 数独を初期化
	void _1_initailize_bool_num_3N_and_feature_map_2N();
	//2 特定の数値における 0と1　処理  
	void _2_Nth_0_1_checker(int number_);

	//特別な処理　
	//3 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去	 
	void _2_4_special_delete_ver2(int number_);
	int one_counter_in_3_3 = 0;
	int row_or_col_counter = 0;

	//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化 5 
	void _2_5_change_1_to_number_in_3_3_blocks(int number_);

	//4 3次元的な特徴を2次元的な特徴に落とし込む 
	void _4_decliment_3N_to_2N();

	//全体の特徴量マップの中に1があったら定数に変化 6 
	void find_1_in_each_f_map();


	   	 
	//数独のはじめの表 7 
	void sudoku_table_first(); 

	//数独の最後
	void sudoku_table_end();

	//数独の解析コメント解析結果
	void commnet_result();

	//解析コメント数
	int comment_result_num = 0;

	//特徴マップを表示させる関数
	void f_map_table();

	//数字が聞いている範囲を特徴をマップ化する
	void number_working_map(int number_);
	std::string num_working[10][10][10];

	//数字が聞いている範囲を特徴をマップを初期化
	void num_working_map_initialize();


	//数字被り　定数と一致した場合
	void _2_1_Nth_0_1_checker_1_TEISU(int number_);

	//数字被り　3*3エリアに特定の数字が存在した場合
	void _2_2_Nth_0_1_checker_2_area_3_3(int number_);

	//数字被り　数字がある列と行は0にする
	void _2_3_Nth_0_1_checker_3_row_col_3_3(int number_);
	int _2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	//細分化しよう


	//確定した値を色を変えて数独に代入した表
	void sudoku_table_first_with_paint();



	//数字被り　定数と一致した場合
	void _2_Nth_0_1_checker_1_TEISU_overwrite(int number_);

	//数字被り　3*3エリアに特定の数字が存在した場合
	void _2_Nth_0_1_checker_2_area_3_3_overwrite(int number_);

	//数字被り　数字がある列と行は0にする
	void _2_Nth_0_1_checker_3_row_col_3_3_overwrite(int number_);

	//初期化 カバーを表示
	void _2_Nth_0_1_checker_for_cover(int number_);


	//もう一度解析するときには値が置き換わっているので、その情報を一時的に保存しておく。
	std::string num_working_cover[10][10][10];


	//数独をカバーでもう一度解く　そのために値をコピーしておく　不可逆的であるから
	void copy_sudoku_value();

	//special_delete_だと一括で消されてしまう
	//そのため細分化させる
	void _3_special_delete_in_detale_overwrite(int number_, int tate_move, int yoko_move);
	bool show_sudoku_table = false;//初期値は表を表示させないのでfalse

	//なぞ
	void nazo(int number_);
	int keep_tate_move = 0;//この変数は初期化する
	int keep_yoko_move= 0 ;

	//num_workingを初期化
	void init_num_working();

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
	int keep_number_array[10] = {0};//10個準備する


};


/*
-------------
|   |   | 87|
|   |   |   |
|  1|23 |   |
-------------
|  2|  4|   |
|  3|   |5  |
|   |8 5| 6 |
-------------
|   | 1 |3  |
|8  |  7|   |
|6  |   |   |
-------------
*/

void Sudoku::init_num_working() {




}



void Sudoku::_2_Nth_0_1_checker_3_row_col_3_3_overwrite(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//特定の値の列、行
			if (s_cover[tate_][yoko_] == number_) {
				//行　横
				for (int row = 1; row <= 9; row++) {
					bool_num_cover[tate_][row][number_] = false;

					//候補を消す
					num_working[tate_][row][number_] = "+";
				}

				//列　縦
				for (int col = 1; col <= 9; col++) {
					bool_num_cover[col][yoko_][number_] = false;

					//候補を消す
					num_working[col][yoko_][number_] = "+";
				}
			}
		}
	}


	std::cout << "_2_Nth_0_1_checker_3_row_col_3_3_overwrite" << std::endl;

}


//初期値の値をコピーしている
void Sudoku::copy_sudoku_value() {
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//数独　数値
			s_cover[tate_][yoko_] = s[tate_][yoko_];
		}
	}
}

void Sudoku::_2_Nth_0_1_checker_2_area_3_3_overwrite(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//特定の3*3エリアに特定の数値があった場合
			if (s_cover[tate_][yoko_] == number_) {
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
						bool_num_cover[i_][j_][number_] = false;//0にする

						num_working[i_][j_][number_] = "*";//候補を消す
						//std::cout << num_working[i_][j_] << std::endl;

					}
				}
			}

		}
	}

	std::cout << "_2_Nth_0_1_checker_2_area_3_3_overwrite" << std::endl;

}

void Sudoku::_2_Nth_0_1_checker_for_cover(int number_) {

	//std::cout << "_2_Nth_0_1_checker_for_cover"<<std::endl;
	//横線
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;


	// 数独表を表示
	for (int j = 0; j < 3; j++) {
		//　1から3行目
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {

			//　もし0の値の時は、[　]空白を文字列に代入する
			//for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//	s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);

			//	//0以外の数値だったら、数字に上書き
			//	if (s[tate_][yoko_] != 0) {
			//		num_working[tate_][yoko_][number_] = s_str[tate_][yoko_];
			//	}

			//}

			std::cout << vertical_ << num_working[tate_][1][number_] << num_working[tate_][2][number_] << num_working[tate_][3][number_] << vertical_
				<< num_working[tate_][4][number_] << num_working[tate_][5][number_] << num_working[tate_][6][number_] << vertical_
				<< num_working[tate_][7][number_] << num_working[tate_][8][number_] << num_working[tate_][9][number_] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}


}

void Sudoku::_2_Nth_0_1_checker_1_TEISU_overwrite(int number_) {

	//初期化
	//_2_Nth_0_1_checker_for_init(number_);

	//* 候補を消す
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {


			//0 以外かつ特定番号1以外のとき
			if (s_cover[tate_][yoko_] != 0 && s_cover[tate_][yoko_] != number_) {
				bool_num_cover[tate_][yoko_][number_] = false;


				//候補を消す 特定以外の定数を置き換える
				num_working[tate_][yoko_][number_] = "@";

			}
		}
	}


	std::cout << "_2_Nth_0_1_checker_1_TEISU_overwrite" << std::endl;

}

//1 数独を初期化
void Sudoku::_1_initailize_bool_num_3N_and_feature_map_2N() {

	//同時に初期化
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//各数字の特徴マップを1にする
				bool_num_[tate_][yoko_][number_] = true;

				//再度計算する用
				bool_num_cover[tate_][yoko_][number_] = true;

				//特徴特徴マップを初期化　
				f_map[tate_][yoko_] = 0;
			}
		}
	}
}

//数字が聞いている範囲を特徴をマップを初期化
void Sudoku::num_working_map_initialize() {
	//同時に初期化
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
				//各数字の特徴マップをその数字にする
				num_working[tate_][yoko_][number_] = std::to_string(number_);
			}
		}
	}
}


void Sudoku::detect_num_from_Fmap() {

	//数独を初期化 全体の特徴マップの変数を初期化する
	_1_initailize_bool_num_3N_and_feature_map_2N();

	//解説コメント変数を初期化
	num_working_map_initialize();


	//各番号において　0と1に分ける　0存在しない　1存在する可能性がある
	for (int number_ = 1; number_ <= 9; number_++) {

		//N番目の特徴マップ 既存の値とかぶっていたら 0に変更
		//sudoku._2_Nth_0_1_checker(number_);

		//2_1 定数の場合　  
		_2_1_Nth_0_1_checker_1_TEISU(number_);
		/*std::cout << "特徴マップ　数：" << number_ << "　定数を消去" << std::endl;
		number_working_map(number_);*/
		//2_2 3*3エリアにその数字がある場合
		_2_2_Nth_0_1_checker_2_area_3_3(number_);
		//std::cout << "特徴マップ　数：" << number_ << "　3*3エリアを消去" << std::endl;
		//number_working_map(number_);
		//2_3 数字がある列と行は0にする
		_2_3_Nth_0_1_checker_3_row_col_3_3(number_);
		//std::cout << "特徴マップ　数：" << number_ << "　測定の文字における列と行を消去" << std::endl;
		//number_working_map(number_);
		//2_4 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去 
		_2_4_special_delete_ver2(number_);//難易度*****
		//std::cout << "特徴マップ　数：" << number_ << "　特定の列と行による候補を消去" << std::endl;
		//number_working_map(number_);


		//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
		//この処理で動作を確定させているので、除外する
		//_2_5_change_1_to_number_in_3_3_blocks(number_);/*

	}


	//上記の処理をすると上書きされるかもしれない
	//特定させて、確定させる処理を除けばいいのではないか・・・

	_4_decliment_3N_to_2N();

	//数値が確定したら代入する
	//find_1_in_each_f_map();



	//初期化　ループに入る前に初期化する
	keep_col_row_num_tate = 1;
	keep_col_row_num_yoko = 1;
	keep_number_ = 1;//探査する数字を初期化する
	//配列の初期化もしないといけない
	for (int i = 0; i <= 10; i++) {
		keep_number_array[i] = 0;
	}




	//1マス1マス出力さえる処理を行う
	find_1_in_each_f_map_one_time(); //ここでbool変数をtrueで返したら、どこに1から9までの値があるのかを調べられる

	//しかし、その時の理由を図示しなくてはいけないですね。
	if (bool_find_1_in_each_f_map_one_time == true) {

		//簡易探査が1-9まで終わるまではこの処理をする
		break_keep_number_ = false;

		//どこにその数字があるのかを調べる
		//まだ9まで探査していなかったら、簡易探査を実行
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();

		//上の調査処理で数値がすべて完結したら、以下の「数字が効いている処理」はいらない



		//まずは簡易探査ができるかを確認
		//次に上記の処理でヒットしなかった数字の特徴マップを再度調べる
		bool break_array = false;//配列探査をするかどうか 初期値はしない

		//以下の処理をbreak_arrayの条件で実行させる
		for (int num = 1; num <= 9; num++) {

			//keep_number_array[num] = num;//ヒットした数値を記録しておく
			//配列とその値が一致していなかったら、探査させる
			if (keep_number_array[num] != num) {
				break_array = true;//初期値探査をする必要がある
			}
		}

		if (break_array == true) {//初期値探査をする必要がある場合
		
			for (int num = 1; num <= 9; num++) {

				//keep_number_array[num] = num;//ヒットした数値を記録しておく
				//配列とその値が一致していなかったら、探査させる
				if (keep_number_array[num] != num) {
					std::cout << num << " この数字を調査する必要があります" << std::endl;

					//ヒットしなかった数値の特徴マップを表示させる、初期化が必要

					//解説コメント変数を初期化
					num_working_map_initialize();

					//数独表に数値がなかった場合に特徴マップを使って、表示させる。

					//2_1 定数の場合　  
					_2_1_Nth_0_1_checker_1_TEISU(num);
					number_working_map(num);
					//2_2 3*3エリアにその数字がある場合
					_2_2_Nth_0_1_checker_2_area_3_3(num);
					number_working_map(num);
					//2_3 数字がある列と行は0にする
					_2_3_Nth_0_1_checker_3_row_col_3_3(num);
					number_working_map(num);
					//2_4 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去 
					_2_4_special_delete_ver2(num);//難易度*****
					number_working_map(num);

					//
					std::cout << "縦マス：" << keep_col_row_num_tate << " 横マス：" << keep_col_row_num_yoko
						<< " は" << s[keep_col_row_num_tate][keep_col_row_num_yoko]
						<< std::endl;
					std::cout << "縦マス：" << keep_col_row_num_tate << " 横マス：" << keep_col_row_num_yoko
						<< " には" << num << "の数値が縦または横で聞いています" << std::endl;



				}

			}
		
		}

		

	}


}



//ヒント　答えからの逆算処理
void Sudoku::investigate_num_on_block() {

	//ブレイク変数
	bool break_ = false;
	


	//数独の表をまずはプロット
	sudoku_table_first();

	//次にそのマスの縦と横から数字を選び出す　
	//使える変数 keep_col_row_num_yoko keep_col_row_num_tate s[tate_][yoko_]
	// keep_number_ は検索した文字を保存している
	for (int number_ = keep_number_; number_ <= 9; number_++) {

		//仮保存させる
		keep_number_ = number_;
		
		//縦と横を調べなくてはいけない
		//縦固定	 
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//0 以外かつ数字のときはその場所を特定
			if (s[keep_col_row_num_tate][yoko_] != 0 && s[keep_col_row_num_tate][yoko_] == number_) {
				std::cout << "縦：" << keep_col_row_num_tate << " 横：" << yoko_ << " に" << number_  << std::endl;
				break_ = true;
			}
		}

		if (break_ == true) {
			keep_number_array[number_] = number_;//ヒットした数値を記録しておく
			//break_ = false;　
			break;
		}

		//縦固定	 
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			//0 以外かつ数字のときはその場所を特定
			if (s[tate_][keep_col_row_num_yoko] != 0 && s[tate_][keep_col_row_num_yoko] == number_) {
				std::cout << "縦：" << tate_ << " 横：" << keep_col_row_num_yoko << " に" << number_ << std::endl;
				break_ = true;
			}
		}

		if (break_ == true) {
			keep_number_array[number_] = number_;//ヒットした数値を記録しておく
			//break_ = false;
			break;

		}


	}


	////数字がヒットしなかったら、数字が効いている可能性がある
	//if (break_ == false) {
	//	std::cout << "数字がヒットしませんでした" << std::endl;
	//}


	//探索する数値をインクリメントする
	keep_number_++;
	if (keep_number_ >= 10) {
		std::cout << "簡易的な探査は終わりました" << std::endl;


		//全ての数値がすべて解析されたのかを確認する。
		//for (int num = 1; num <= 9; num++) {

		//	//keep_number_array[num] = num;//ヒットした数値を記録しておく
		//	//配列とその値が一致していなかったら、探査させる
		//	if (keep_number_array[num] != num) {
		//		std::cout << num << " この数字を調査する必要があります" << std::endl;
		//	}
		//}


		//std::cout << "ヒットしなかった数値を解析します" << std::endl;



		//処理を抜ける
		break_keep_number_ = true;

		//keep_number_用の配列を準備する　初期値0

	}

}



//数値が効いている範囲を表示
void Sudoku::number_working_map(int number_) {

	//　まず全体的に * を記入する

	//横線
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;




	// jが1,2,3と増えると, iが0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//　1から3行目
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//　もし0の値の時は、[　]空白を文字列に代入する
			//for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//	s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);
			//	//0だとスペース
			//	if (s[tate_][yoko_] == 0) {
			//		s_str[tate_][yoko_] = " ";
			//	}

			//}

			std::cout << vertical_ << num_working[tate_][1][number_] << num_working[tate_][2][number_] << num_working[tate_][3][number_] << vertical_
				<< num_working[tate_][4][number_] << num_working[tate_][5][number_] << num_working[tate_][6][number_] << vertical_
				<< num_working[tate_][7][number_] << num_working[tate_][8][number_] << num_working[tate_][9][number_] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}



}

//2 1つのマスにアクセスしている
//2 特定の数値における 0と1　処理  
void Sudoku::_2_Nth_0_1_checker(int number_) {
	// 1とそれ以外以外の値の範囲をマッピング
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {





			//特定の3*3エリアに特定の数値があった場合
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
						bool_num_[i_][j_][number_] = false;//0にする

						num_working[i_][j_][number_] = "*";//候補を消す

					}
				}
			}




			//一度 * となるか確認する

			std::cout << "tate_ = " << tate_ << " yoko_ = " << yoko_ << std::endl;
			//number_working_map();


			//0 以外かつ特定番号1以外のとき
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;


				//候補を消す
				num_working[tate_][yoko_][number_] = "*";

			}



			//特定の値の列、行
			if (s[tate_][yoko_] == number_) {
				//行　横
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;

					//候補を消す
					num_working[tate_][yoko_][number_] = "*";


				}

				//列　縦
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;


					//候補を消す
					num_working[tate_][yoko_][number_] = "*";
				}

			}

			//一度 * となるか確認する
			//number_working_map(int number_);
			//Sleep(2000);




		}
	}
}

void Sudoku::_2_3_Nth_0_1_checker_3_row_col_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//特定の値の列、行
			if (s[tate_][yoko_] == number_) {
				//行　横
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;


					//横の候補を消す
					num_working[tate_][row][number_] = "+";
				}

				//列　縦
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;

					//縦の候補を消す
					num_working[col][yoko_][number_] = "+";
				}
			}
		}
	}

}

void Sudoku::_2_2_Nth_0_1_checker_2_area_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {


			//特定の3*3エリアに特定の数値があった場合
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
						bool_num_[i_][j_][number_] = false;//0にする


						//std::cout << "特徴マップ　3*3エリアを消去　数：" << number_ << std::endl;

						//特定の3*3エリアに特定の数値があった場合、候補を消す
						num_working[i_][j_][number_] = "*";
						//std::cout << num_working[i_][j_] << std::endl;



					}
				}
			}

		}
	}

}

//基本的にはsign　が代入される
void Sudoku::_2_1_Nth_0_1_checker_1_TEISU(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//0 以外かつ特定番号1以外のとき
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;


				/*std::cout << "特徴マップ　定数を消去　数：" << number_ << std::endl;*/

				//候補を消す
				num_working[tate_][yoko_][number_] = "@";
			}
		}
	}
}

//special_delete_だと一括で消されてしまう
//そのため細分化させる

void Sudoku::_3_special_delete_in_detale_overwrite(int number_, int tate_move, int yoko_move) {


	//std::cout << "_3_special_delete_in_detale_overwrite" << std::endl;

	//表示させるかをbool
	//bool show_sudoku_table = false;

	/*for (int tate_move = 0; tate_move < 3; tate_move++) {

		for (int yoko_move = 0; yoko_move < 3; yoko_move++) {*/

	one_counter_in_3_3 = 0;
	// tate=4-6 yoko=4-6 のtrueをカウント 
	for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
		for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
			if (bool_num_cover[tate_][yoko_][number_] == true) {
				one_counter_in_3_3++;//3*3の加算数
			}
		}
	}

	row_or_col_counter = 0;

	//3*3の加算数が3または2のとき
	//↓
	//これは3*3エリア内に縦か横に数値が連なっていたら、それに対応した縦か横を相殺する
	if (one_counter_in_3_3 == 3 || one_counter_in_3_3 == 2) {
		// tate固定
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			row_or_col_counter = 0;//この初期化が組まれていないかもしてない
			for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
				if (bool_num_cover[tate_][yoko_][number_] == true) {
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

				//3のうちの対象ブロックを除いた1つ
				for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
					bool_num_cover[tate_][yoko1][number_] = false;

					//候補の横を消す
					num_working[tate_][yoko1][number_] = "-";

				}

				//3のうちの対象ブロックを除いた1つ
				for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
					bool_num_cover[tate_][yoko1][number_] = false;

					//候補の縦を消す
					num_working[tate_][yoko1][number_] = "-";
				}


				//書き込まれたら一度止める処理を入れる
				//クリックされたらfalseからtrueに代わって、再度表現とか

				show_sudoku_table = true;





			}

			//一度抜ける
			if (show_sudoku_table == true) {
				break;
			}

		}

		////一度抜ける
		//if (show_sudoku_table == true) {
		//	break;
		//}

		//縦と横の効きは合計何回やったのかをカウントしておく
		//それを解析に生かす


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

				//3のうちの対象ブロックを除いた1つ
				for (int tate1 = start_1_tate; tate1 <= start_1_tate + 2; tate1++) {
					bool_num_cover[tate1][yoko_][number_] = false;

					//候補の横を消す
					num_working[tate1][yoko_][number_] = ":";

				}

				//3のうちの対象ブロックを除いた1つ
				for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
					bool_num_cover[tate1][yoko_][number_] = false;

					//候補の縦を消す
					num_working[tate1][yoko_][number_] = ":";
				}

				show_sudoku_table = true;

			}


			//一度抜ける
			if (show_sudoku_table == true) {
				break;
			}

		}



		//一度抜ける
		//if (show_sudoku_table == true) {
		//	break;
		//}

	}
	//	}
	//}


}

void Sudoku::_2_4_special_delete_ver2(int number_) {


	//この処理を何回やったのかをカウント
	_2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	for (int tate_move = 0; tate_move < 3; tate_move++) {

		for (int yoko_move = 0; yoko_move < 3; yoko_move++) {

			one_counter_in_3_3 = 0;
			// tate=4-6 yoko=4-6 のtrueをカウント 
			for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {
						one_counter_in_3_3++;//3*3の加算数
					}
				}
			}

			row_or_col_counter = 0;

			//3*3の加算数が3または2のとき
			//↓
			//これは3*3エリア内に縦か横に数値が連なっていたら、それに対応した縦か横を相殺する
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

						//3のうちの対象ブロックを除いた1つ
						for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;

							//横の候補を消す
							num_working[tate_][yoko1][number_] = "-";


						}

						//3のうちの対象ブロックを除いた1つ
						for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;


							//横の候補を消す
							num_working[tate_][yoko1][number_] = "-";

						}


						//この処理を何回やったのかをカウント
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

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

						//3のうちの対象ブロックを除いた1つ
						for (int tate1 = start_1_tate; tate1 <= start_1_tate + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;

							//縦の候補を消す
							num_working[tate1][yoko_][number_] = ":";

						}

						//3のうちの対象ブロックを除いた1つ
						for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;


							//縦の候補を消す
							num_working[tate1][yoko_][number_] = ":";

						}


						//この処理を何回やったのかをカウント
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

					}
				}
			}
		}
	}
}

void Sudoku::_4_decliment_3N_to_2N() {

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

//全体の特徴マップの中で値が1だったら定数に変換 
void Sudoku::find_1_in_each_f_map() {

	comment_result_num = 0;

	//数字が一個見つかったらループを抜ける
	//find_1_in_each_f_map_bool = false;

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


						std::cout << "tate_=" << tate_ << " yoko_=" << yoko_ << " number_=" << number_ << std::endl;

						comment_result_num++;

						//int tate_, intyoko_, int number_ 
						//investigate_num_on_block();

						//なぜこのマスに値が代入されるのかを再度調査する関数を作成

					}
				}



			}
		}
	}

	std::cout << "comment_result_num = " << comment_result_num << std::endl;

}

void Sudoku::find_1_in_each_f_map_one_time() {

	bool_find_1_in_each_f_map_one_time = false;

	comment_result_num = 0;


	bool detect_num = false;

	for (int tate_ = keep_col_row_num_tate; tate_ <= 9; tate_++) {
		for (int yoko_ = keep_col_row_num_yoko; yoko_ <= 9; yoko_++) {

			//仮保存
			keep_col_row_num_tate = tate_;
			keep_col_row_num_yoko = yoko_;

			//特徴マップで1のときにその値しか入らない
			if (f_map[tate_][yoko_] == 1) {

				//その1はどこの数値かを調べる
				for (int number_ = 1; number_ <= 9; number_++) {
					//みつけたら、それを定数化する
					if (bool_num_[tate_][yoko_][number_] == true) {

						//数独の数値を代入
						s[tate_][yoko_] = number_;


						std::cout << "tate_=" << tate_ << " yoko_=" << yoko_ << " number_=" << number_ << std::endl;

						comment_result_num++;

						//回答を見つけられたら、その場所を特定する
						bool_find_1_in_each_f_map_one_time = true;


						detect_num = true;

						//なぜこのマスに値が代入されるのかを再度調査する関数を作成

					}


					if (detect_num == true) {
						break;
					}


				}


				//if (detect_num == true) {
				//	break;
				//}

			}


			if (detect_num == true) {
				break;
			}

		}




		if (detect_num == true) {
			break;
		}
		else {

			//でなかったら初期化してあげる
			//keep_col_row_num_yoko = 0;

		}


		keep_col_row_num_yoko++;

		if (keep_col_row_num_yoko > 10) {
			keep_col_row_num_yoko = 1;
			keep_col_row_num_tate = 0;

		}


	}

	std::cout << "comment_result_num = " << comment_result_num << std::endl;




	//なぜそのマスの値が決定されるのかを調査する
	//investigate_num_on_block();//
	//investigate_num_on_block();

}


//特徴マップを表示させる関数
void Sudoku::f_map_table() {

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

//3*3を探査　探査　縦横　探査
void Sudoku::nazo(int number_) {

	bool working_row_col = true;



	//while (working_row_col) {

		//初期値を仮保存した変数に置き換える
	for (int tate_move = keep_tate_move; tate_move < 3; tate_move++) {

		//初期値を仮保存した変数に置き換える
		for (int yoko_move = keep_yoko_move; yoko_move < 3; yoko_move++) {

			//次の場所から始めるためにインクリメントさせる
			keep_tate_move = tate_move;
			keep_yoko_move = yoko_move;

			////}
			//std::cout << "keep_tate_move_ = " << keep_tate_move << std::endl;
			//std::cout << "keep_yoko_move = " << keep_yoko_move << std::endl;

			_3_special_delete_in_detale_overwrite(number_, tate_move, yoko_move);//

			////書き込みがあったら、停止させて表示させる
			//if (show_sudoku_table == true) {

			//	static int times = 1;

			//	std::cout << "time = " << times++ << std::endl;

			//	_2_Nth_0_1_checker_for_cover(number_);

			//	//falseにして返す
			//	show_sudoku_table = false;

			//}


			//書き込みは終わっているのでこのループを抜ける
			if (show_sudoku_table == true) {
				break;
			}



		}

		//書き込みは終わっているのでこのループを抜ける
		if (show_sudoku_table == true) {

			working_row_col = false;
			break;
		}

		//次にスタートする変数値は仮保存されている
		keep_yoko_move = 0;//横の値を依存させていた。

	}







	//書き込みがあったら、停止させて表示させる
	if (show_sudoku_table == true) {

		static int times = 1;

		std::cout << "time = " << times++ << std::endl;

		//表示
		_2_Nth_0_1_checker_for_cover(number_);

		//falseにして返す
		show_sudoku_table = false;

		//繰り上げ処理
		//keep_tate_move++;
		keep_yoko_move++;

		if (keep_yoko_move >= 3) {
			keep_yoko_move = 0;
			keep_tate_move++;
		}



	}


}

//3*3ブロックに数字が一個だったら定数に変化
void Sudoku::_2_5_change_1_to_number_in_3_3_blocks(int number_) {

	//確定数値の個数
	comment_result_num = 0;

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



				//数独の数値が確定
				s[save_tate_][save_yoko_] = number_;


				//確定した数値を表記
				num_working[save_tate_][save_yoko_][number_] = " ";

				////コメントの流れ
				////解析されたマスが分かる
				////そのマスの数字が分かる
				////そのマスが効いている範囲が分かる。
				//std::cout << "数字が確定 "<< std::endl;
				//std::cout << "縦 " << save_tate_ << " :横 " << save_yoko_ << std::endl;
				//std::cout << "着目する数字は"<< number_ << std::endl;


				////毎回初期化させる

				////その数字の効いている範囲を可視化する。
				////まずは数独表を表示
				////次にその数字
				////まずは特徴マップ（*）を表示して、次に数字を上書きする
				//_2_Nth_0_1_checker_for_cover(number_);//初期化　3で埋め尽くす
				//_2_Nth_0_1_checker_1_TEISU_overwrite(number_);//定数を書き込み　特定の数字以外は@にする
				//_2_Nth_0_1_checker_for_cover(number_);
				//_2_Nth_0_1_checker_2_area_3_3_overwrite(number_);//3*3内の特定の数字以外は*にする
				//_2_Nth_0_1_checker_for_cover(number_);
				//_2_Nth_0_1_checker_3_row_col_3_3_overwrite(number_);
				//_2_Nth_0_1_checker_for_cover(number_);


				//std::cout << "_3_special_delete_in_detale_overwrite" << std::endl;

				////スペシャルデリートを細分化させる
				////_3_special_delete_in_detale_overwrite(number_);//表示関数を組み込む



				////なんか気持ち悪い処理ですね・・・
				////クリックしたら、表示させるプログラムがいい　変数を維持させたい　マックスまでループさせる
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				//nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
				////Sleep(1000);
				////何回クリックさせなくてはいけないかをカウンターでログに残している

				////_2_3_Nth_0_1_checker_3_row_col_3_3_counterの分、クリックする

				////do while 文を使うのか 



				////_2_Nth_0_1_checker_for_cover(number_);


				////仮変数にも代入 しかし解析し終わった後に入れる
				//s_cover[save_tate_][save_yoko_] = number_;

				////一回解き終わったら、数独表以外は初期化
				//number_working_map_initialize();
				//
				//
				////最終的な出力結果
				////確定した値を色を変えて数独に代入した表
				//sudoku_table_first_with_paint();


				////特徴マップを初期化すべき



				//Sleep(2000);

				////result_[comment_result_num] = "縦" + std::to_string(save_tate_) + "横" + std::to_string(save_yoko_) + "は" + std::to_string(number_);
				////reason_[comment_result_num] = "ここのマスの3*3は残り一つのため" + std::to_string(number_) + "が入る";


				//確定数値の個数
				comment_result_num++;


			}

		}
	}

	//確定数値の個数が1個以上の時
	if (comment_result_num > 0) {


		//for (int i = 0; i < comment_result_num; comment_result_num++) {


		//	//コメントの流れ
		//		//解析されたマスが分かる
		//		//そのマスの数字が分かる
		//		//そのマスが効いている範囲が分かる。
		//	std::cout << "数字が確定 " << std::endl;
		//	std::cout << "縦 " << save_tate_ << " :横 " << save_yoko_ << std::endl;
		//	std::cout << "着目する数字は" << number_ << std::endl;


		//	//毎回初期化させる

		//	//その数字の効いている範囲を可視化する。
		//	//まずは数独表を表示
		//	//次にその数字
		//	//まずは特徴マップ（*）を表示して、次に数字を上書きする
		//	_2_Nth_0_1_checker_for_cover(number_);//初期化　3で埋め尽くす
		//	_2_Nth_0_1_checker_1_TEISU_overwrite(number_);//定数を書き込み　特定の数字以外は@にする
		//	_2_Nth_0_1_checker_for_cover(number_);
		//	_2_Nth_0_1_checker_2_area_3_3_overwrite(number_);//3*3内の特定の数字以外は*にする
		//	_2_Nth_0_1_checker_for_cover(number_);
		//	_2_Nth_0_1_checker_3_row_col_3_3_overwrite(number_);
		//	_2_Nth_0_1_checker_for_cover(number_);


		//	std::cout << "_3_special_delete_in_detale_overwrite" << std::endl;

		//	//スペシャルデリートを細分化させる
		//	//_3_special_delete_in_detale_overwrite(number_);//表示関数を組み込む



		//	//なんか気持ち悪い処理ですね・・・
		//	//クリックしたら、表示させるプログラムがいい　変数を維持させたい　マックスまでループさせる
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	nazo(number_);//でも実際にはアプリ上で行うので、何回クリックさせるかは考えなくていい
		//	//Sleep(1000);
		//	//何回クリックさせなくてはいけないかをカウンターでログに残している

		//	//_2_3_Nth_0_1_checker_3_row_col_3_3_counterの分、クリックする

		//	//do while 文を使うのか 



		//	//_2_Nth_0_1_checker_for_cover(number_);


		//	//仮変数にも代入 しかし解析し終わった後に入れる
		//	s_cover[save_tate_][save_yoko_] = number_;

		//	//一回解き終わったら、数独表以外は初期化
		//	num_working_map_initialize();


		//	//最終的な出力結果
		//	//確定した値を色を変えて数独に代入した表
		//	sudoku_table_first_with_paint();


			//特徴マップを初期化すべき



		//Sleep(2000);

		//result_[comment_result_num] = "縦" + std::to_string(save_tate_) + "横" + std::to_string(save_yoko_) + "は" + std::to_string(number_);
		//reason_[comment_result_num] = "ここのマスの3*3は残り一つのため" + std::to_string(number_) + "が入る";

		//comment_result_num++;





		//comment_result_num = 0;
	}



}

//確定した値を色を変えて数独に代入した表
void Sudoku::sudoku_table_first_with_paint() {


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

				//確定した値を数独表に代入するときは色を付ける
				if (save_tate_ == tate_ && save_yoko_ == yoko_) {

					s_str[tate_][yoko_] = "\033[33m" + std::to_string(s[tate_][yoko_]) + "\033[0m";
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