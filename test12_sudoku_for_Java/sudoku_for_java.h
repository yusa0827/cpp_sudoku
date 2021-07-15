#pragma once
#include <string>

class Sudoku {
	//�\�p�̕������w��
	std::string space_ = " ";//�����̂��߂̃X�y�[�X
	std::string vertical_ = "|";//�c��
	std::string horizontal_ = "-";//����

	//3*3 �̃C���N�������^�[
	int inclimenter_3_3 = 0;

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


	//��̓R�����g�p�ϐ�
	std::string result_[81];

	//��͌��ʂ̗��R
	std::string reason_[81];


public:
	//���Ɓ@���l
	int s[10][10] = { 0 };
	//���Ɓ@������
	std::string s_str[10][10];
	//�e�i���o�[�@bool_num_[�c][��][�w�蕶��] 1�ɏ�����
	bool bool_num_[10][10][10];
	//�����ʃ}�b�v�p�ϐ�
	int f_map[10][10];
	//�����ʃ}�b�v�̘a��0����break
	int f_map_sum = 0;

	//���Ƃ�������
	void initailize_bool_num_3N_and_feature_map_2N();
	//����̐��l�ɂ����� 0��1�@����
	void Nth_0_1_checker(int number_);

	//���ʂȏ����@
	// 3*3�G���A���ɏc�E���݂̂�1������ꍇ�ɑ��̏c�E��������	
	void special_delete_ver2(int number_);
	int one_counter_in_3_3 = 0;
	int row_or_col_counter = 0;

	//���ꂼ��̓����ʃ}�b�v��3*3�̃}�X�̒���1����������萔�ɕω�
	void change_1_to_number_in_3_3_blocks(int number_);

	//3�����I�ȓ�����2�����I�ȓ����ɗ��Ƃ����� 
	void decliment_3N_to_2N();

	//�S�̂̓����ʃ}�b�v�̒���1����������萔�ɕω�
	void find_1_in_each_f_map();
	   	 
	//���Ƃ̂͂��߂̕\
	void sudoku_table_first();

	//���Ƃ̍Ō�
	void sudoku_table_end();

	//���Ƃ̉�̓R�����g��͌���
	void commnet_result();

	//��̓R�����g��
	int comment_result_num = 0;


};


//���Ƃ̉�̓R�����g��͌���
void Sudoku::commnet_result() {

	std::cout<<std::endl;

	//������
	for (int i = 0; i < comment_result_num; i++) {

		//�R�����g���o��
		std::cout << result_[i] << std::endl;

		//�R�����g���o��
		std::cout << reason_[i] << std::endl;
	}




	//������
	for (int i = 0; i < comment_result_num; i++) {

		//�R�����g�𖳂ɂ���
		result_[i] = "";

		//���R�ɂ���
		result_[i] = "";
	}

	//����������
	comment_result_num = 0;




}



//�S�̂̓����}�b�v�̕ϐ�������������
void Sudoku::sudoku_table_first() {

	std::cout << std::endl;
	//����
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;


	// j��1,2,3�Ƒ������, i��0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//�@1����3�s��
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//�@����0�̒l�̎��́A[�@]�󔒂𕶎���ɑ������
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);
				//0���ƃX�y�[�X
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

//�Ō�ɕ\��������
void Sudoku::sudoku_table_end() {

	std::cout << std::endl;
	//����
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;


	// j��1,2,3�Ƒ������, i��0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//�@1����3�s��
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//�@����0�̒l�̎��́A[�@]�󔒂𕶎���ɑ������
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				s_str[tate_][yoko_] = std::to_string(s[tate_][yoko_]);
				//0���ƃX�y�[�X
				if (s[tate_][yoko_] == 0) {
					s_str[tate_][yoko_] = " ";


					//��͂��s�\���ł���
					std::string out = "��͂��s�\���ł���";
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
			// tate=4-6 yoko=4-6 ��true���J�E���g 
			for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {
						one_counter_in_3_3++;
					}
				}
			}

			row_or_col_counter = 0;

			if (one_counter_in_3_3 == 3 || one_counter_in_3_3 == 2) {
				// tate�Œ�
				for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
					row_or_col_counter = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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
					row_or_col_counter = 0;//���̏��������g�܂�Ă��Ȃ��������ĂȂ�
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



//�S�̂̓����}�b�v�̒��Œl��1��������萔�ɕϊ� 
void Sudoku::find_1_in_each_f_map() {
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//�����}�b�v��1�̂Ƃ��ɂ��̒l��������Ȃ�
			if (f_map[tate_][yoko_] == 1) {
				//����1�͂ǂ��̐��l���𒲂ׂ�
				for (int number_ = 1; number_ <= 9; number_++) {
					//�݂�����A�����萔������
					if (bool_num_[tate_][yoko_][number_] == true) {



						//���Ƃ̐��l����
						s[tate_][yoko_] = number_;


						result_[comment_result_num] = "�c"+ std::to_string(tate_)+ "��" + std::to_string(yoko_) + "��" + std::to_string(number_);
						reason_[comment_result_num] = "�����̃}�X��" +std::to_string(number_)+ "�ȊO������̂�" + std::to_string(number_);

						comment_result_num++;


					}
				}
			}
		}
	}
}


//3*3�u���b�N�̂Ȃ���1����������萔�ɕω�
void Sudoku::change_1_to_number_in_3_3_blocks(int number_) {


	for (int tate_tate = 0; tate_tate < 3; tate_tate++) {

		for (int yoko_yoko = 0; yoko_yoko < 3; yoko_yoko++) {

			//���u���b�N�� 3*3 �𑖍�
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
			//3*3�u���b�N�ŃC���N�������g1�̂Ƃ��Ɋm��@���W���m��
			if (inclimenter_3_3 == 1) {

				//���Ƃ̐��l����
				s[save_tate_][save_yoko_] = number_;

				



				result_[comment_result_num] = "�c" + std::to_string(save_tate_) + "��" + std::to_string(save_yoko_) + "��" + std::to_string(number_);
				reason_[comment_result_num] = "�����̃}�X��3*3�͎c���̂���" + std::to_string(number_) + "������";

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
				//true�̓`�F�b�N����蔲���������c��
				if (bool_num_[tate_][yoko_][number_] == true) {
					f_map[tate_][yoko_]++;
					//�S�̂̓����}�b�v�̘a��0���ƃu���C�N
					f_map_sum++;
				}
			}
		}
	}


}

void Sudoku::Nth_0_1_checker(int number_) {
	// 1�Ƃ���ȊO�ȊO�̒l�͈̔͂��}�b�s���O
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//0 �ȊO������ԍ�1�ȊO�̂Ƃ�
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;
			}

			//����̒l�̗�A�s
			if (s[tate_][yoko_] == number_) {
				//�s�@��
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;
				}

				//��@�c
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;
				}

			}

			//����̒l�̗�A�s�A�G���A�ł���
			if (s[tate_][yoko_] == number_) {
				//�X�^�[�g�͈�
				int start_tate;
				int start_yoko;

				//�c�̃G���A��T��
				if (1 <= tate_ && tate_ <= 3) {
					start_tate = 1;
				}
				else if (4 <= tate_ && tate_ <= 6) {
					start_tate = 4;
				}
				else {
					start_tate = 7;
				}
				//���̃G���A��T��
				if (1 <= yoko_ && yoko_ <= 3) {
					start_yoko = 1;
				}
				else if (4 <= yoko_ && yoko_ <= 6) {
					start_yoko = 4;
				}
				else {
					start_yoko = 7;
				}

				//�G���A�ɉ��Z����
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

	//�����ɏ�����
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//���Ƃ�������
				bool_num_[tate_][yoko_][number_] = true;

				//���������}�b�v��������
				f_map[tate_][yoko_] = 0;
			}
		}
	}

}