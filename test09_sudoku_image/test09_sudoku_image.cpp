// test09_sudoku_image.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

/*
画像を読み込むために、カメラの映像に閾値範囲を付与させる（アシスト）
*/

int main()
{
	//画像用変数   
	cv::Mat img, tmp;

	//画像を読み込み
	img = cv::imread("sample_sudoku.jpg", 0);

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
	int s[10][10] = {0};

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


			if (maxVal_num < 0.8) {
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
			s[tate_][yoko_] = num_;



			p_counter++;
		}

		//画像表示
		cv::imshow("sample_", roi_img);

		cv::waitKey(1000);

	}


	cv::Scalar dot_S(0, 255, 255);

	// -1 のとき円内を塗りつぶす
	int draw_in = -1;

	for (int number_ = 0; number_ <= 4; number_++) {


		//std::cout << num_p[number_] << std::endl;
		//cv::circle(roi_img, num_p[number_], 20, dot_S, draw_in, cv::LINE_AA);
	}

	/* 360  */
	//int yoko_ = int(num_p[0].x * 9 / img_size) + 1;
	//int tate_ = int(num_p[0].y * 9 / img_size) + 1;
	std::cout << num_p[0] << std::endl;


	//画像サイズを出力
	std::cout << "画像 num_p[0].x = " << num_p[0].x << std::endl;
	//画像サイズを出力
	std::cout << "画像 num_p[0].y = " << num_p[0].y << std::endl;
	//画像サイズを出力
	std::cout << "s[" << 2 << "][" << 3 << "] = " << s[2][3] << std::endl;
	//画像サイズを出力
	std::cout << "s[" << 1 << "][" << 4 << "] = " << s[1][4] << std::endl;
	//画像サイズを出力
	std::cout << "s[" << 4 << "][" << 4 << "] = " << s[4][4] << std::endl;
	//画像サイズを出力
	std::cout << "s[" << 9 << "][" << 8 << "] = " << s[9][8] << std::endl;
	//画像サイズを出力
	std::cout << "s[" << 8 << "][" << 8 << "] = " << s[8][8] << std::endl;



	//画像表示
	//cv::imshow("sample_", img);

	//画像表示
	cv::imshow("sample__", roi_img);

	//待ち時間
	cv::waitKey(0);


	




	



}

