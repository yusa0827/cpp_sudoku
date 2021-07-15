#pragma once
#include <opencv2/opencv.hpp>


class Sudoku {
	//�\�p�̕������w��
	std::string space_ = " ";//�����̂��߂̃X�y�[�X
	std::string vertical_ = "|";//�c��
	std::string horizontal_ = "-";//����

	//3*3�}�X�Ƀo�c��2��3���̎��ɔ��� �����ɍs�Ɨ�̏����ɂ���đ��u���b�N�̌�������
	int counter_del = 0;
	int counter_tate_yoko = 0;


	// special_delete �p�̕ϐ�
	int save_tate_ = 0;
	int save_yoko_ = 0;
	int start_1_tate = 0;//�������v�[���p�̃X�^�[�g�ʒu
	int start_2_tate = 0;//�������v�[���p�̃X�^�[�g�ʒu
	int start_1_yoko = 0;//�������v�[���p�̃X�^�[�g�ʒu
	int start_2_yoko = 0;//�������v�[���p�̃X�^�[�g�ʒu
	int c_46_13 = 0;
	int c_46_13_33 = 0;
	int c_46_46 = 0;
	int c_46_46_33 = 0;
	int c_46_79;
	int c_46_79_33 = 0;





public:
	//���Ɓ@���l
	int s[10][10] = { 0 };
	//�e�i���o�[�@bool_num_[�c][��][�w�蕶��] 1�ɏ�����
	bool bool_num_[10][10][10];
	//�����ʃ}�b�v�p�ϐ�
	int f_map[10][10];

	//�}�b�v�̘a��0����break
	int f_map_sum = 0;

	//���Ƃ�������
	void initailize_bool_num_();
	//void initailize_f_map();
	//N�Ԗڂɂ�����\���쐬
	void Nth_table_3(int number_, int i);
	//����̐��l�ɂ����� 0��1�@����
	void Nth_0_1_checker(int number_);

	//3�����I�ȓ�����2�����I�ȓ����ɗ��Ƃ����� 
	void decliment_3N_to_2N();
	//�񎟌��̓����}�b�s���O��\��
	void Nth_table_2();

	//3*3�u���b�N�̏����@��9�}�X�s��
	//void check_1_in_3_3_blocks(int number_);

	void find_1_in_f_map();
	//�摜�̕\��
	void image_table(cv::Mat image, int i);


	//
	void initailize_f_map_2();

	void change_1_to_number_in_3_3_blocks(int number_);


	//���ʂȏ����@
	// 3*3�G���A���ɏc�܂��͉��݂̂�1������ꍇ�ɑ��̏c�܂��͉����������A
	//���݂���͈͂�1����0�ɕω�������
	void special_delete(int number_);


};


void Sudoku::special_delete(int number_) {

	for (int tate_move = 0; tate_move < 3; tate_move++) {


		/************************************************************************************************/
		c_46_13 = 0;
		// tate=4-6 yoko=4-6 ��true���J�E���g 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
			for (int yoko_ = 1; yoko_ <= 3; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_13++;
				}
			}
		}

		c_46_13_33 = 0;

		if (c_46_13 == 3 || c_46_13 == 2) {
			// tate�Œ�
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_13_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}
				}
			}


			for (int yoko_fix = 1; yoko_fix <= 3; yoko_fix++) {
				c_46_13_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
						bool_num_[tate1][yoko_fix][number_] = false;
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
					}
				}
			}


		}
		/************************************************************************************************/

		/************************************************************************************************/
		c_46_46 = 0;
		// tate=4-6 yoko=4-6 ��true���J�E���g 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 4; yoko_ <= 6; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_46++;
				}
			}
		}

		c_46_46_33 = 0;

		if (c_46_46 == 3 || c_46_46 == 2) {
			// tate�Œ�
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_46_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}

					for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
						bool_num_[tate_fix][yoko1][number_] = false;
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate_fix][yoko1][number_] << std::endl;
					}
				}
			}


			for (int yoko_fix = 4; yoko_fix <= 6; yoko_fix++) {
				c_46_46_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
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
		// tate=4-6 yoko=4-6 ��true���J�E���g 
		for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
			for (int yoko_ = 7; yoko_ <= 9; yoko_++) {
				if (bool_num_[tate_][yoko_][number_] == true) {
					c_46_79++;
				}
			}
		}

		c_46_79_33 = 0;

		if (c_46_79 == 3 || c_46_79 == 2) {
			// tate�Œ�
			for (int tate_fix = tate_move * 3 + 1; tate_fix <= tate_move * 3 + 3; tate_fix++) {
				c_46_79_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
				c_46_79_33 = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
						//std::cout << "�O�@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
						bool_num_[tate1][yoko_fix][number_] = false;
						//std::cout << "��@bool_num_[tate_fix][yoko1][1] = " << bool_num_[tate1][yoko_fix][number_] << std::endl;
					}
				}
			}


		}
		/************************************************************************************************/
	}


}


//�摜�̕\��
void Sudoku::image_table(cv::Mat image, int i){
	for (int tate_draw = 1; tate_draw <= 9; tate_draw++) {
		for (int yoko_draw = 1; yoko_draw <= 9; yoko_draw++) {
			//����������������Ă��Ȃ��}�X��
			if (s[tate_draw][yoko_draw] != 0) {
				cv::putText(image, std::to_string(s[tate_draw][yoko_draw]), cv::Point(50 * (yoko_draw - 1), 50 * tate_draw), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 255), 2, CV_8UC3); //(20,100)�̈ʒu�ɑ傫��2�A����1�̐ԐF�����ŕ`��
			}
		}
	}

	cv::imshow(std::to_string(i), image);
}

//�����}�b�v�̒��Œl��1��������A����͒萔 
void Sudoku::find_1_in_f_map() {
	for (int N_2_ = 1; N_2_ <= 9; N_2_++) {
		for (int N_1_ = 1; N_1_ <= 9; N_1_++) {
			//�����}�b�v��1�̂Ƃ��A����͂��̒l��������Ȃ�
			//���������ꂾ���ł͂ǂ��̐��l��������Ȃ��̂ŁA�T��
			if (f_map[N_2_][N_1_] == 1) {

				//����1�͂ǂ��̐��l���𒲂ׂ�
				for (int N_3_ = 1; N_3_ <= 9; N_3_++) {

					//�݂�����A�����萔������
					if (bool_num_[N_2_][N_1_][N_3_] == true) {
						//�l��u���������B
						s[N_2_][N_1_] = N_3_;

						std::cout << "�G���A���m�肵�܂��� " << "number_ = " << N_3_
							<< ",save_ss_ = " << N_2_ << ",save_dd_ = " << N_1_ << "��1������܂����B" << std::endl;
					}

				}

				
			}

		}
	}




}



//void Sudoku::display_1_to_9_map_from_3N() {
//
//	//3�����I�ɒl���������Ă���
//	for (int number_ = 1; number_ <= 9; number_++) {
//
//		//����̐��l�ɂ����� 0��1�@����
//		Nth_0_1_checker(number_);
//
//		// 1�Ƃ���ȊO�ȊO�̒l�͈̔͂��}�b�s���O
//
//		//�@���l�@number_ �����݂���͈�
//		Nth_table_3(number_);
//	}
//}


//3*3�u���b�N�̏����@��9�}�X���e������
//void Sudoku::check_numbers_in_3_3_blocks() {
//
//	for (int number_ = 1; number_ <= 9; number_++) {
//		//3*3�u���b�N�̏����@��9�}�X�s��
//		change_to_number_from_1_in_3_3_blocks(number_);
//
//	}
//
//}




//3*3�u���b�N�̏����@��9�}�X�s��
void Sudoku::change_1_to_number_in_3_3_blocks(int number_) {
	//3*3 �̃C���N�������^�[
	int inclimenter = 0;
	//3*3�G���A����1����݂̂�������A����͒萔
	//�ꎞ�I�ȍ��W�̕ۑ��ꏊ
	int save_tate_;
	int save_yoko_;
	//�c�ɐi�܂��鏈��
	for (int tate_tate = 0; tate_tate < 3; tate_tate++) {
		//���u���b�N�� 3*3 �𑖍�
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
		//3*3�u���b�N�ŃC���N�������g1�̂Ƃ��Ɋm��@���W���m��
		if (inclimenter == 1) {
			std::cout << "�G���A���m�肵�܂��� " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_
				<< " ��1������܂����B" << std::endl;
			s[save_tate_][save_yoko_] = number_;//�l��������
		}

		//�����u���b�N��
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
		//3*3�u���b�N�ŃC���N�������g1�̂Ƃ��Ɋm��@���W���m��
		if (inclimenter == 1) {
			std::cout << "�G���A���m�肵�܂��� " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_
				<< " ��1������܂����B" << std::endl;
			s[save_tate_][save_yoko_] = number_;//�l��������
		}

		//�E�u���b�N��
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
		//3*3�u���b�N�ŃC���N�������g1�̂Ƃ��Ɋm��@���W���m��
		if (inclimenter == 1) {
			std::cout << "�G���A���m�肵�܂��� " << "number_ = " << number_
				<< ",tate = " << save_tate_ << ",yoko = " << save_yoko_ 
				<< " ��1������܂����B" << std::endl;
			s[save_tate_][save_yoko_] = number_;//�l��������
		}

			   
	}

}


void Sudoku::initailize_f_map_2() {

	//���������}�b�v��������
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
				//true�̓`�F�b�N����蔲���������c��
				if (bool_num_[N_1_][N_2_][N_3_] == true) {
					f_map[N_1_][N_2_]++;
					//�S�̂̓����}�b�v�̘a��0���ƃu���C�N
					f_map_sum++;
				}
			}
		}
	}


}

void Sudoku::Nth_0_1_checker(int number_) {
	// 1�Ƃ���ȊO�ȊO�̒l�͈̔͂��}�b�s���O
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			//0 �ȊO������ԍ�1�ȊO�̂Ƃ�
			if (s[i][j] != 0 && s[i][j] != number_) {
				//�C���N�������g
				//bool_num[i][j] = false;
				bool_num_[i][j][number_] = false;
			}

			//����̒l�̗�A�s
			if (s[i][j] == number_) {
				//�s�@��
				for (int row = 1; row <= 9; row++) {
					//bool_num[i][row] = false;
					bool_num_[i][row][number_] = false;
				}

				//��@�c
				for (int col = 1; col <= 9; col++) {
					//bool_num[col][j] = false;
					bool_num_[col][j][number_] = false;
				}

			}

			//����̒l�̗�A�s�A�G���A�ł���
			if (s[i][j] == number_) {
				//�X�^�[�g�͈�
				int start_tate;
				int start_yoko;

				//�c�̃G���A��T��
				if (1 <= i && i <= 3) {
					start_tate = 1;
				}
				else if (4 <= i && i <= 6) {
					start_tate = 4;

				}
				else {
					start_tate = 7;
				}
				//���̃G���A��T��
				if (1 <= j && j <= 3) {
					start_yoko = 1;
				}
				else if (4 <= j && j <= 6) {
					start_yoko = 4;

				}
				else {
					start_yoko = 7;
				}

				//�G���A�ɉ��Z����
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

		//�@1����3�s��
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

	//�@number_ �����݂���͈�
	std::cout << i << "�Ԗ� ����" << number_ << "�����݂�����͈�" << std::endl;

	//N�Ԗڂɂ�����\���쐬
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	for (int j = 0; j < 3; j++) {
		//�@1����3�s��
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


//���Ƃ�������
void Sudoku::initailize_bool_num_() {

	for (int N_1 = 1; N_1 <= 9; N_1++) {
		for (int N_2 = 1; N_2 <= 9; N_2++) {
			for (int N_3 = 1; N_3 <= 9; N_3++) {
				bool_num_[N_1][N_2][N_3] = 1;
			}
		}
	}
}