
#include <opencv2/opencv.hpp>


//数独の表を作成
cv::Mat  make_sudoku_image(int img_size) {

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

	return image;
}