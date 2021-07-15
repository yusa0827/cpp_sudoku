// test09_sudoku_image.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <string>
#include "sudoku_3N_Header.h"
/*
画像を読み込むために、カメラの映像に閾値範囲を付与させる（アシスト）

数独の豆知識を投稿する


リアルタイムでの画像処理が必要　
*/

int main()
{



	//画像用変数   
	cv::Mat img, tmp;

	//画像を読み込み
	//img = cv::imread("sample_sudoku.jpg", 0);
	img = cv::imread("DSC_0392.jpg", 0);

	//画像を読み込み
	tmp = cv::imread("tmp.jpg", 0);

	// 画像データが読み込めなかったときは終了する
	if (img.empty() == true || tmp.empty() == true) {
		return 0;
	}

	//画像をRGBからグレースケール
	//cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

	//閾値160で2値画像 //閾値を自動で設定
	cv::threshold(img, img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	//画像サイズを出力
	std::cout << "画像サイズ [" << img.rows << "][" << img.cols << "]" << std::endl;

	//テンプレ―マッチング用変数
	//cv::Mat temp;//テンプレート画像
	cv::Mat result;//テンプレート画像のMat型の結果
	cv::Point max_pt;//最高類似度の座標
	double maxVal;//最高類似度の値

	//テンプレ―マッチング cv::TM_CCOEFF_NORMED = 5
	cv::matchTemplate(img, tmp, result, cv::TM_CCOEFF_NORMED);

	//類似度のMat型結果から座標を取得
	cv::minMaxLoc(result, NULL, &maxVal, NULL, &max_pt);

	cv::Rect roi_rect(0, 0, tmp.cols, tmp.rows);
	roi_rect.x = max_pt.x;
	roi_rect.y = max_pt.y;

	// 探索結果の場所に矩形を描画
	cv::rectangle(img, roi_rect, cv::Scalar(0, 255, 255), 3);

	//矩形領域をcv::Rectを使うことで切り出す
	cv::Mat roi_img = img(roi_rect); // 切り出し画像

	//画像サイズを出力
	std::cout << "画像サイズ [" << roi_img.rows << "][" << roi_img.cols << "]" << std::endl;

	//リサイズ360*360に変換 同じサイズだとリサイズできない
	int img_size = 360;
	cv::resize(roi_img, roi_img, cv::Size(img_size, img_size));

	//画像サイズを出力
	std::cout << "画像サイズ [" << roi_img.rows << "][" << roi_img.cols << "]" << std::endl;

	//数字テンプレートを設定
	cv::Mat temp_num[10];//テンプレート画像のMat型の結果

	//数値の座標
	cv::Point num_p[81];

	//座標数値のインクリメンター
	int p_counter = 0;

	/* 360  画像次元を数独次元に変換 */
	int yoko_;
	int tate_;

	/* 数独の変数 */
	int s_img[10][10] = { 0 };

	for (int num_ = 1; num_ <= 9; num_++) {

		//N番目の数字をインクルード
		temp_num[num_] = img = cv::imread("temp_num\\temp_" + std::to_string(num_) + ".jpg", 0);

		//テンプレートマッチングで1~9を検出 1つの文字につき最大9個
		for (int detect_p = 1; detect_p <= 9; detect_p++) {
			cv::Mat result_num;
			cv::Point max_pt_num;
			double maxVal_num;

			cv::Rect roi_rect_num(0, 0, temp_num[num_].cols, temp_num[num_].rows);
			cv::matchTemplate(roi_img, temp_num[num_], result_num, cv::TM_CCOEFF_NORMED);

			cv::minMaxLoc(result_num, NULL, &maxVal_num, NULL, &max_pt_num);


			if (maxVal_num < 0.85) {
				break;
			}

			roi_rect_num.x = max_pt_num.x;//roi_rect_num(0, 0 の0がが変更
			roi_rect_num.y = max_pt_num.y;//roi_rect_num(0, 0 の0がが変更

			cv::rectangle(roi_img, roi_rect_num, cv::Scalar(0, 0, 0), 2);
			num_p[p_counter].x = (roi_rect_num.x + roi_rect_num.x + temp_num[num_].cols) / 2;
			num_p[p_counter].y = (roi_rect_num.y + roi_rect_num.y + temp_num[num_].rows) / 2;


			//数独のマスを取得
			tate_ = int(num_p[p_counter].y * 9 / img_size) + 1;
			yoko_ = int(num_p[p_counter].x * 9 / img_size) + 1;

			//数独の変数に代入
			s_img[tate_][yoko_] = num_;



			p_counter++;
		}

		//画像表示
		cv::imshow("sample_", roi_img);

		cv::waitKey(1000);

	}




	//画像サイズを出力
	std::cout << "画像 num_p[0].x = " << num_p[0].x << std::endl;
	//画像サイズを出力
	std::cout << "画像 num_p[0].y = " << num_p[0].y << std::endl;
	//画像サイズを出力
	std::cout << "s_img[" << 2 << "][" << 3 << "] = " << s_img[2][3] << std::endl;
	//画像サイズを出力
	std::cout << "s_img[" << 1 << "][" << 4 << "] = " << s_img[1][4] << std::endl;



	//画像表示
	//cv::imshow("sample_", img);

	//画像表示
	//cv::imshow("sample__", roi_img);

	//待ち時間
	//cv::waitKey(0);


	


	//数独用変数
	Sudoku sudoku;


	//画像の解析数値を数独解法に代入
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			sudoku.s[tate_][yoko_] = s_img[tate_][yoko_];


		}

	}

	sudoku.sudoku_table();


	//画像の数字と解析した数独の数字が合っているかを確認
	bool ckeck_img_and_number = false;
	if (ckeck_img_and_number == false) {

		bool Answer;
		std::cout << "入力した画像と解析した数値はあっていますか" << std::endl;
		std::cout << "YES:1 NO:0  ANSWER=";
		std::cin >> Answer;


		if (Answer == true) {

			
		}
		else {
			std::cout << "マスの数値を修正しますか" << std::endl;
			std::cout << "YES:1 NO:0  ANSWER=" << std::endl;


			if (Answer == true) {
				int Answer_tate;
				int Answer_yoko;
				int Answer_number;
				/* スマホの入力場面をタッチすることも可 */
				std::cout << "どこのマスの数値を修正しますか" << std::endl;
				std::cout << "左から何マス目:";
				std::cin >> Answer_yoko;
				std::cout << "上らか何マス目:";
				std::cin >> Answer_tate;
				std::cout << "そのマスの値は:";
				std::cin >> Answer_number;


				if (Answer_yoko == 0 || Answer_tate == 0 || Answer_number == 0) {

					std::cout << "もう一度入力してください";
				}
				



			}

			return 0;


		}

		//cv::waitKey(0);
		

	}
	auto start = std::chrono::system_clock::now();



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

		//マップの和が0だとbreak
		if (sudoku.f_map_sum == 0) {

			auto end = std::chrono::system_clock::now();

			auto diff = end - start;
			std::cout << "elapsed time = "
				<< std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
				<< " msec."
				<< std::endl;

			break;
		}

	}

	sudoku.sudoku_table();

}

