
#include <opencv2/opencv.hpp>


//���Ƃ̕\���쐬
cv::Mat  make_sudoku_image(int img_size) {

	//500x500�̉摜�@CV_8UC3(8bit 3�`�����l��)  ������
	cv::Mat image = cv::Mat::zeros(img_size + 5, img_size, CV_8UC3);
	cv::rectangle(image, cv::Point(0, 0), cv::Point(img_size + 5, img_size), cv::Scalar(255, 255, 255), -1, cv::LINE_8);

	//����
	for (int i = 0; i <= 3; i++) { //450 / 3 = 150
		//�@����8
		cv::line(image, cv::Point(150 * i, 0), cv::Point(150 * i, img_size), cv::Scalar(255, 0, 0), 5, cv::LINE_8);
		cv::line(image, cv::Point(0, 150 * i), cv::Point(img_size, 150 * i), cv::Scalar(255, 0, 0), 5, cv::LINE_8);
	}

	//�א�
	for (int i = 0; i <= 9; i++) { //450 / 9 = 50  
		//�@����8
		cv::line(image, cv::Point(50 * i, 0), cv::Point(50 * i, img_size), cv::Scalar(255, 0, 0), 1, cv::LINE_8);
		cv::line(image, cv::Point(0, 50 * i), cv::Point(img_size, 50 * i), cv::Scalar(255, 0, 0), 1, cv::LINE_8);

	}

	return image;
}