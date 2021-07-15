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
	bool_num_[1][4][1] = 1;
	bool_num_[1][5][1] = 1;
	bool_num_[4][3][1] = 1;
	bool_num_[4][7][1] = 1;
	bool_num_[5][2][1] = 1;
	bool_num_[5][9][1] = 1;
	bool_num_[7][3][1] = 1;
	bool_num_[7][7][1] = 1;
	bool_num_[7][9][1] = 1;
	bool_num_[8][2][1] = 1;
	bool_num_[8][3][1] = 1;
	bool_num_[8][4][1] = 1;
	bool_num_[8][5][1] = 1;
	bool_num_[9][5][1] = 1;
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

	int conter_3_3 = 0;//3*3のなかの1のカウンター
	int counter_core = 0;//その行でのカウンター
	int save_tate_ = 0;
	int save_yoko_ = 0;
	int start_1_tate = 0;//初期化プール用のスタート位置
	int start_2_tate = 0;//初期化プール用のスタート位置
	int start_1_yoko = 0;//初期化プール用のスタート位置
	int start_2_yoko = 0;//初期化プール用のスタート位置




	/******************************************************************************/
	//tate=1-3 yoko=1-3
	conter_3_3 = 0;
	for (int tate_ = 1; tate_ <= 3; tate_++) {
		for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
			//1が入っていたらカウント
			if (bool_num_[tate_][yoko_][1] == true) {
				conter_3_3++;
			}
		}
	}	
	assert(conter_3_3 == 0);

	if (conter_3_3 == 2 || conter_3_3 == 3) {
		std::cout << "他の列や行を消去できる可能性があるよ" << std::endl;

		//tate_固定
		counter_core = 0;
		for (int tate_ = 1; tate_ <= 3; tate_++) {//いずれ変数になる
			
			for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
											   
				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_yoko_ = yoko_;//縦の最大値を保持
				
			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {
				
				//初期化させるループ位置を算出
				if (save_yoko_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_yoko = 1;
					start_2_yoko = 4;
				}
				//他ブロックを初期化の一回目
				for (int start_tate = start_1_yoko; start_tate < start_1_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
				//他ブロックを初期化の二回目
				for (int start_tate = start_2_yoko; start_tate < start_2_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
			}
					   			 
		}


		//yoko_固定
		counter_core = 0;
		for (int yoko_ = 1; yoko_ <= 3; yoko_++) {

			for (int tate_ = 1; tate_ <= 3; tate_++) {//いずれ変数になる

				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_tate_ = tate_;//縦の最大値を保持
			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {

				//初期化させるループ位置を算出
				if (save_tate_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_tate = 4;
					start_2_tate = 7;
				}
				if (save_tate_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_tate = 1;
					start_2_tate = 7;
				}
				if (save_tate_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_tate = 1;
					start_2_tate = 4;
				}

				for (int start_tate = start_1_tate; start_tate < start_1_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}

				for (int start_tate = start_2_tate; start_tate < start_2_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}


				//yoko=1-3なので4-9 をfalseに変換
				//bool_num_[4][yoko_][1] = false;
				//bool_num_[5][yoko_][1] = false;
				//bool_num_[6][yoko_][1] = false;
				//bool_num_[7][yoko_][1] = false;
				//bool_num_[8][yoko_][1] = false;
				//bool_num_[9][yoko_][1] = false;
			}

		}			   		 	  
	}
	/******************************************************************************/


	/******************************************************************************/
	//tate=1-3 yoko=1-3
	conter_3_3 = 0;
	for (int tate_ = 1; tate_ <= 3; tate_++) {
		for (int yoko_ = 4; yoko_ <= 6; yoko_++) {//いずれ変数になる
			//1が入っていたらカウント
			if (bool_num_[tate_][yoko_][1] == true) {
				conter_3_3++;
			}
		}
	}


	if (conter_3_3 == 2 || conter_3_3 == 3) {
		std::cout << "他の列や行を消去できる可能性があるよ" << std::endl;

		//tate_固定
		counter_core = 0;
		for (int tate_ = 1; tate_ <= 3; tate_++) {

			for (int yoko_ = 4; yoko_ <= 6; yoko_++) {//いずれ変数になる

				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_yoko_ = yoko_;//縦の最大値を保持

			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {

				//初期化させるループ位置を算出
				if (save_yoko_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_yoko = 1;
					start_2_yoko = 4;
				}
				//他ブロックを初期化の一回目
				for (int start_tate = start_1_yoko; start_tate < start_1_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
				//他ブロックを初期化の二回目
				for (int start_tate = start_2_yoko; start_tate < start_2_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
			}

		}


		//yoko_固定
		counter_core = 0;
		for (int yoko_ = 4; yoko_ <= 6; yoko_++) {//いずれ変数になる

			for (int tate_ = 1; tate_ <= 3; tate_++) {

				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_tate_ = tate_;//縦の最大値を保持
			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {

				//初期化させるループ位置を算出
				if (save_tate_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_tate = 4;
					start_2_tate = 7;
				}
				if (save_tate_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_tate = 1;
					start_2_tate = 7;
				}
				if (save_tate_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_tate = 1;
					start_2_tate = 4;
				}

				for (int start_tate = start_1_tate; start_tate < start_1_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}

				for (int start_tate = start_2_tate; start_tate < start_2_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}

			}

		}
			   		 	  
	}
	/******************************************************************************/


	/******************************************************************************/
	//tate=1-3 yoko=7-9
	conter_3_3 = 0;
	for (int tate_ = 1; tate_ <= 3; tate_++) {
		for (int yoko_ = 7; yoko_ <= 9; yoko_++) {//いずれ変数になる
			//1が入っていたらカウント
			if (bool_num_[tate_][yoko_][1] == true) {
				conter_3_3++;
			}
		}
	}


	if (conter_3_3 == 2 || conter_3_3 == 3) {
		std::cout << "他の列や行を消去できる可能性があるよ" << std::endl;

		//tate_固定
		counter_core = 0;
		for (int tate_ = 1; tate_ <= 3; tate_++) {

			for (int yoko_ = 7; yoko_ <= 9; yoko_++) {//いずれ変数になる

				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_yoko_ = yoko_;//縦の最大値を保持

			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {

				//初期化させるループ位置を算出
				if (save_yoko_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_yoko = 4;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_yoko = 1;
					start_2_yoko = 7;
				}
				if (save_yoko_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_yoko = 1;
					start_2_yoko = 4;
				}
				//他ブロックを初期化の一回目
				for (int start_tate = start_1_yoko; start_tate < start_1_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
				//他ブロックを初期化の二回目
				for (int start_tate = start_2_yoko; start_tate < start_2_yoko + 3; start_tate++) {

					bool_num_[tate_][start_tate][1] = false;
				}
			}

		}


		//yoko_固定
		counter_core = 0;
		for (int yoko_ = 7; yoko_ <= 9; yoko_++) {

			for (int tate_ = 1; tate_ <= 3; tate_++) {//いずれ変数になる

				//1が入っていたらカウント
				if (bool_num_[tate_][yoko_][1] == true) {
					counter_core++;
				}
				save_tate_ = tate_;//縦の最大値を保持
			}

			// tate_=1, yoko_=1-3で conter_3_3 == counter_core が一致したら
			//他の列を削除できる
			if (counter_core == conter_3_3) {

				//初期化させるループ位置を算出
				if (save_tate_ == 3) {// ×××|〇〇〇|〇〇〇
					start_1_tate = 4;
					start_2_tate = 7;
				}
				if (save_tate_ == 6) {// 〇〇〇|×××|〇〇〇
					start_1_tate = 1;
					start_2_tate = 7;
				}
				if (save_tate_ == 9) {// 〇〇〇|〇〇〇|×××
					start_1_tate = 1;
					start_2_tate = 4;
				}

				for (int start_tate = start_1_tate; start_tate < start_1_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}

				for (int start_tate = start_2_tate; start_tate < start_2_tate + 3; start_tate++) {

					bool_num_[start_tate][yoko_][1] = false;
				}

			}

		}

	}
	/******************************************************************************/


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

