// test11_sudoku_webcamera.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <opencv2/opencv.hpp>



int main()
{
	cv::VideoCapture cap(0);//デバイスのオープン
   //cap.open(0);//こっちでも良い．

	if (!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
	{
		//読み込みに失敗したときの処理
		return -1;
	}

	cv::Mat frame; //取得したフレーム

	/* 中心座標用変数 */
	int rows_;//行
	int cols_;//列
	cv::Point center;//点の座標
	int dot_r = 2;//点の半径	
	int draw_in = -1;// -1 のとき円内を塗りつぶす	
	cv::Scalar dot_S(0, 255, 255);//色

	/* アシスト用の矩形 */
	int img_size = 360;
	int img_size_half = img_size / 2;

	cv::Point top_left;//点の座標
	cv::Point buttom_right;//点の座標
	cv::Point offset_img_size_half(img_size_half, img_size_half);
	cv::Point offset_out(10, 10);//オフセット10ピクセルを外にとる

	/* ROIの画像も同時に表示 */
	cv::Rect roi_rect(0, 0, img_size, img_size);
	//cv::Rect roi_rect_offset(top_left - offset_out, buttom_right - offset_out);
	cv::Rect roi_rect_offset;
	cv::Mat roi_img;//ROi用変数

	while (cap.read(frame))//無限ループ
	{
		//
		//取得したフレーム画像に対して，クレースケール変換や2値化などの処理を書き込む．
		//

		cols_ = frame.cols;//行
		rows_ = frame.rows;//列

		center.x = cols_ / 2;//点の中心座標
		center.y = rows_ / 2;//点の中心座標

		//top_left.x = center.x - img_size_half;//左上座標
		//top_left.y = center.y - img_size_half;
		top_left = center - offset_img_size_half;//左上座標


		//buttom_right.x = center.x + img_size_half;//右下座標
		//buttom_right.y = center.y + img_size_half;
		buttom_right = center + offset_img_size_half;//右下座標

		cv::circle(frame, center, dot_r, dot_S, draw_in, cv::LINE_AA);
		cv::rectangle(frame, top_left, buttom_right, dot_S, 2, 8); //ROI
		cv::rectangle(frame, top_left - offset_out, buttom_right + offset_out, dot_S, 2, 8); //-オフセット
		cv::rectangle(frame, top_left + offset_out, buttom_right - offset_out, dot_S, 2, 8); //+オフセット


		for (int line_time = 1; line_time <= 2; line_time++) {
			int lines_x = top_left.x + (buttom_right.x - top_left.x) / 3 * line_time;
			int lines_y = top_left.y + (buttom_right.y - top_left.y) / 3 * line_time;			
			cv::line(frame, cv::Point(lines_x, top_left.y), cv::Point(lines_x, buttom_right.y), dot_S, 2, cv::LINE_8);
			cv::line(frame, cv::Point(top_left.x, lines_y), cv::Point(buttom_right.x, lines_y), dot_S, 2, cv::LINE_8);

		}
		
		/* ROIの画像も同時に表示 */
		roi_rect.x = top_left.x;
		roi_rect.y = top_left.y;

		roi_rect.x = top_left.x;
		roi_rect.y = top_left.y;

		//cv::Point roi_t_l = top_left - offset_out;
		//cv::Point roi_b_r = buttom_right - offset_out;

		cv::Rect roi_rect_offset(top_left - offset_out, buttom_right + offset_out);

		//矩形領域をcv::Rectを使うことで切り出す
		roi_img = frame(roi_rect_offset); // 切り出し画像

		cv::imshow("frame", frame);//画像を表示．
		cv::imshow("roi_img", roi_img);//画像を表示．

		const int key = cv::waitKey(1);
		if (key == 'q'/*113*/)//qボタンが押されたとき
		{
			break;//whileループから抜ける．
		}
		else if (key == 's'/*115*/)//sが押されたとき
		{
			//フレーム画像を保存する．
			cv::imwrite("img.png", frame);
		}
	}
	cv::destroyAllWindows();
	return 0;
}

