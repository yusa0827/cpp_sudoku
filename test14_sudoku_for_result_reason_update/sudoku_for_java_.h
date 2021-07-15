#pragma once
#include <string>
#include <Windows.h>

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



public:
	//���Ɓ@���l
	int s[10][10] = { 0 };
	//���Ɓ@������
	std::string s_str[10][10];
	//�e�i���o�[�@bool_num_[�c][��][�w�蕶��] 1�ɏ�����
	bool bool_num_[10][10][10];
	bool bool_num_cover[10][10][10];//�ēx�A�����悤�ɉ��ۑ�
	//�����ʃ}�b�v�p�ϐ�
	int f_map[10][10];
	int f_map_sum = 0;

	//1 ���Ƃ�������
	void _1_1_initailize_bool_num_3N_and_feature_map_2N();
	//2 ����̐��l�ɂ����� 0��1�@����  
	void _2_Nth_0_1_checker(int number_);

	//���ʂȏ����@
	//3 3*3�G���A���ɏc�E���݂̂�1������ꍇ�ɑ��̏c�E��������	 
	void _2_4_special_delete_ver2(int number_);
	int one_counter_in_3_3 = 0;
	int row_or_col_counter = 0;

	//���ꂼ��̓����ʃ}�b�v��3*3�̃}�X�̒���1����������萔�ɕω� 5 
	void _2_5_change_1_to_number_in_3_3_blocks(int number_);

	//4 3�����I�ȓ�����2�����I�ȓ����ɗ��Ƃ����� 
	void _4_decliment_3N_to_2N();

	//�S�̂̓����ʃ}�b�v�̒���1����������萔�ɕω� 6 
	void find_1_in_each_f_map();
	   	 
	//���Ƃ̂͂��߂̕\ 7 
	void sudoku_table_first(); 

	//���Ƃ̍Ō�
	void sudoku_table_end();

	//��̓R�����g��
	int comment_result_num = 0;

	//�����}�b�v��\��������֐�
	void f_map_table();

	//�����������Ă���͈͂�������}�b�v������
	void number_working_map(int number_);
	std::string num_working[10][10][10];

	//�����������Ă���͈͂�������}�b�v��������
	void _1_2_num_working_map_initialize();


	//�������@�萔�ƈ�v�����ꍇ
	void _2_1_Nth_0_1_checker_1_TEISU(int number_);

	//�������@3*3�G���A�ɓ���̐��������݂����ꍇ
	void _2_2_Nth_0_1_checker_2_area_3_3(int number_);

	//�������@�����������ƍs��0�ɂ���
	void _2_3_Nth_0_1_checker_3_row_col_3_3(int number_);
	int _2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	//�ו������悤


	//�m�肵���l��F��ς��Đ��Ƃɑ�������\
	void sudoku_table_first_with_paint();
	
	//������ �J�o�[��\��
	void _2_Nth_0_1_checker_for_cover(int number_);


	//������x��͂���Ƃ��ɂ͒l���u��������Ă���̂ŁA���̏����ꎞ�I�ɕۑ����Ă����B
	std::string num_working_cover[10][10][10];


	//special_delete_���ƈꊇ�ŏ�����Ă��܂�
	//���̂��ߍו���������
	//void _3_special_delete_in_detale_overwrite(int number_, int tate_move, int yoko_move);
	bool show_sudoku_table = false;//�����l�͕\��\�������Ȃ��̂�false

	//�Ȃ�
	//void nazo(int number_);
	int keep_tate_move = 0;//���̕ϐ��͏���������
	int keep_yoko_move= 0 ;


	//1����9�܂ł̓����}�b�v�𑫂����킹�����v�l1���m�肳����
	void detect_num_from_Fmap();

	//�Ȃ����̃}�X�����̃}�X�̏c�Ɖ��̐����Ō��肷��̂�
	void investigate_num_on_block();
	//���ϐ��i���o�[
	int keep_number_ = 1;


	void find_1_in_each_f_map_one_time();
	int keep_col_row_num_tate = 0;
	int keep_col_row_num_yoko = 0;



	bool bool_find_1_in_each_f_map_one_time;
	bool break_keep_number_;
	int keep_number_array[10] = { 0 };//10��������


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


//1 ���Ƃ�������
void Sudoku::_1_1_initailize_bool_num_3N_and_feature_map_2N() {

	//�����ɏ�����
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//�e�����̓����}�b�v��1�ɂ���
				bool_num_[tate_][yoko_][number_] = true;

				//�ēx�v�Z����p
				bool_num_cover[tate_][yoko_][number_] = true;

				//���������}�b�v���������@
				f_map[tate_][yoko_] = 0;
			}
		}
	}
}

//�����������Ă���͈͂�������}�b�v��������
void Sudoku::_1_2_num_working_map_initialize() {
	//�����ɏ�����
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
				//�e�����̓����}�b�v�����̐����ɂ���
				num_working[tate_][yoko_][number_] = std::to_string(number_);
			}
		}
	}
}

void Sudoku::detect_num_from_Fmap() {

	//���Ƃ������� �S�̂̓����}�b�v�̕ϐ�������������
	_1_1_initailize_bool_num_3N_and_feature_map_2N();

	//����R�����g�ϐ���������
	_1_2_num_working_map_initialize();


	//�e�ԍ��ɂ����ā@0��1�ɕ�����@0���݂��Ȃ��@1���݂���\��������
	for (int number_ = 1; number_ <= 9; number_++) {

		//N�Ԗڂ̓����}�b�v �����̒l�Ƃ��Ԃ��Ă����� 0�ɕύX
		//sudoku._2_Nth_0_1_checker(number_);

		//2_1 �萔�̏ꍇ�@  
		_2_1_Nth_0_1_checker_1_TEISU(number_);
		//2_2 3*3�G���A�ɂ��̐���������ꍇ
		_2_2_Nth_0_1_checker_2_area_3_3(number_);
		//2_3 �����������ƍs��0�ɂ���
		_2_3_Nth_0_1_checker_3_row_col_3_3(number_);
		//2_4 3*3�G���A���ɏc�E���݂̂�1������ꍇ�ɑ��̏c�E�������� 
		_2_4_special_delete_ver2(number_);//��Փx*****

		//���ꂼ��̓����ʃ}�b�v��3*3�̃}�X�̒���1����������萔�ɕω�
		//���̏����œ�����m�肳���Ă���̂ŁA���O����
		//_2_5_change_1_to_number_in_3_3_blocks(number_);/*

	}


	//��L�̏���������Ə㏑������邩������Ȃ�
	//���肳���āA�m�肳���鏈���������΂����̂ł͂Ȃ����E�E�E
	_4_decliment_3N_to_2N();
	
	//�������@���[�v�ɓ���O�ɏ���������
	keep_col_row_num_tate = 1;
	keep_col_row_num_yoko = 1;
	keep_number_ = 1;//�T�����鐔��������������
	//�z��̏����������Ȃ��Ƃ����Ȃ�
	for (int i = 0; i < 10; i++) {
		keep_number_array[i] = 0;
	}

	//1�}�X1�}�X�o�͂����鏈�����s��
	find_1_in_each_f_map_one_time(); //������bool�ϐ���true�ŕԂ�����A�ǂ���1����9�܂ł̒l������̂��𒲂ׂ���

	//�������A���̎��̗��R��}�����Ȃ��Ă͂����Ȃ��ł��ˁB
	if (bool_find_1_in_each_f_map_one_time == true) {

		//�ȈՒT����1-9�܂ŏI���܂ł͂��̏���������
		break_keep_number_ = false;

		//�ǂ��ɂ��̐���������̂��𒲂ׂ�
		//�܂�9�܂ŒT�����Ă��Ȃ�������A�ȈՒT�������s
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();
		if (break_keep_number_ == false) investigate_num_on_block();

		//��̒��������Ő��l�����ׂĊ���������A�ȉ��́u�����������Ă��鏈���v�͂���Ȃ�



		//�܂��͊ȈՒT�����ł��邩���m�F
		//���ɏ�L�̏����Ńq�b�g���Ȃ����������̓����}�b�v���ēx���ׂ�
		bool break_array = false;//�z��T�������邩�ǂ��� �����l�͂��Ȃ�

		//�ȉ��̏�����break_array�̏����Ŏ��s������
		for (int num = 1; num <= 9; num++) {

			//keep_number_array[num] = num;//�q�b�g�������l���L�^���Ă���
			//�z��Ƃ��̒l����v���Ă��Ȃ�������A�T��������
			if (keep_number_array[num] != num) {
				break_array = true;//�����l�T��������K�v������
			}
		}

		if (break_array == true) {//�����l�T��������K�v������ꍇ
		
			for (int num = 1; num <= 9; num++) {

				//keep_number_array[num] = num;//�q�b�g�������l���L�^���Ă���
				//�z��Ƃ��̒l����v���Ă��Ȃ�������A�T��������
				if (keep_number_array[num] != num) {
					std::cout << num << " ���̐����𒲍�����K�v������܂�" << std::endl;

					//�q�b�g���Ȃ��������l�̓����}�b�v��\��������A���������K�v

					//����R�����g�ϐ���������
					_1_2_num_working_map_initialize();

					//���ƕ\�ɐ��l���Ȃ������ꍇ�ɓ����}�b�v���g���āA�\��������B

					//2_1 �萔�̏ꍇ�@  
					_2_1_Nth_0_1_checker_1_TEISU(num);
					number_working_map(num);
					//2_2 3*3�G���A�ɂ��̐���������ꍇ
					_2_2_Nth_0_1_checker_2_area_3_3(num);
					number_working_map(num);
					//2_3 �����������ƍs��0�ɂ���
					_2_3_Nth_0_1_checker_3_row_col_3_3(num);
					number_working_map(num);
					//2_4 3*3�G���A���ɏc�E���݂̂�1������ꍇ�ɑ��̏c�E�������� 
					_2_4_special_delete_ver2(num);//��Փx*****
					number_working_map(num);

					//
					std::cout << "�c�}�X�F" << keep_col_row_num_tate << " ���}�X�F" << keep_col_row_num_yoko
						<< " ��" << s[keep_col_row_num_tate][keep_col_row_num_yoko]
						<< std::endl;
					std::cout << "�c�}�X�F" << keep_col_row_num_tate << " ���}�X�F" << keep_col_row_num_yoko
						<< " �ɂ�" << num << "�̐��l���c�܂��͉��ŕ����Ă��܂�" << std::endl;



				}

			}
		
		}

		

	}


}


//�q���g�@��������̋t�Z����
void Sudoku::investigate_num_on_block() {

	//�u���C�N�ϐ�
	bool break_ = false;
	


	//���Ƃ̕\���܂��̓v���b�g
	sudoku_table_first();

	//���ɂ��̃}�X�̏c�Ɖ����琔����I�яo���@
	//�g����ϐ� keep_col_row_num_yoko keep_col_row_num_tate s[tate_][yoko_]
	// keep_number_ �͌�������������ۑ����Ă���
	for (int number_ = keep_number_; number_ <= 9; number_++) {

		//���ۑ�������
		keep_number_ = number_;
		
		//�c�Ɖ��𒲂ׂȂ��Ă͂����Ȃ�
		//�c�Œ�	 
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			//0 �ȊO�������̂Ƃ��͂��̏ꏊ�����
			if (s[keep_col_row_num_tate][yoko_] != 0 && s[keep_col_row_num_tate][yoko_] == number_) {
				std::cout << "�c�F" << keep_col_row_num_tate << " ���F" << yoko_ << " ��" << number_  << std::endl;
				break_ = true;
			}
		}

		if (break_ == true) {
			keep_number_array[number_] = number_;//�q�b�g�������l���L�^���Ă���
			//break_ = false;�@
			break;
		}

		//�c�Œ�	 
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			//0 �ȊO�������̂Ƃ��͂��̏ꏊ�����
			if (s[tate_][keep_col_row_num_yoko] != 0 && s[tate_][keep_col_row_num_yoko] == number_) {
				std::cout << "�c�F" << tate_ << " ���F" << keep_col_row_num_yoko << " ��" << number_ << std::endl;
				break_ = true;
			}
		}

		if (break_ == true) {
			keep_number_array[number_] = number_;//�q�b�g�������l���L�^���Ă���
			//break_ = false;
			break;

		}


	}


	////�������q�b�g���Ȃ�������A�����������Ă���\��������
	//if (break_ == false) {
	//	std::cout << "�������q�b�g���܂���ł���" << std::endl;
	//}


	//�T�����鐔�l���C���N�������g����
	keep_number_++;
	if (keep_number_ >= 10) {
		std::cout << "�ȈՓI�ȒT���͏I���܂���" << std::endl;


		//�S�Ă̐��l�����ׂĉ�͂��ꂽ�̂����m�F����B
		//for (int num = 1; num <= 9; num++) {

		//	//keep_number_array[num] = num;//�q�b�g�������l���L�^���Ă���
		//	//�z��Ƃ��̒l����v���Ă��Ȃ�������A�T��������
		//	if (keep_number_array[num] != num) {
		//		std::cout << num << " ���̐����𒲍�����K�v������܂�" << std::endl;
		//	}
		//}


		//std::cout << "�q�b�g���Ȃ��������l����͂��܂�" << std::endl;



		//�����𔲂���
		break_keep_number_ = true;

		//keep_number_�p�̔z�����������@�����l0

	}

}


//���l�������Ă���͈͂�\��
void Sudoku::number_working_map(int number_) {

	//�@�܂��S�̓I�� * ���L������

	//����
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;




	// j��1,2,3�Ƒ������, i��0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {
		//�@1����3�s��
		for (int tate_ = j * 3 + 1; tate_ < (j + 1) * 3 + 1; tate_++) {
			//�@����0�̒l�̎��́A[�@]�󔒂𕶎���ɑ������

			std::cout << vertical_ << num_working[tate_][1][number_] << num_working[tate_][2][number_] << num_working[tate_][3][number_] << vertical_
				<< num_working[tate_][4][number_] << num_working[tate_][5][number_] << num_working[tate_][6][number_] << vertical_
				<< num_working[tate_][7][number_] << num_working[tate_][8][number_] << num_working[tate_][9][number_] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}



}


//��{�I�ɂ�sign�@����������
void Sudoku::_2_1_Nth_0_1_checker_1_TEISU(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//0 �ȊO������ԍ�1�ȊO�̂Ƃ�
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;
				/*std::cout << "�����}�b�v�@�萔�������@���F" << number_ << std::endl;*/

				//��������
				num_working[tate_][yoko_][number_] = "@";
			}
		}
	}
}

void Sudoku::_2_2_Nth_0_1_checker_2_area_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {


			//�����3*3�G���A�ɓ���̐��l���������ꍇ
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
						bool_num_[i_][j_][number_] = false;//0�ɂ���


						//std::cout << "�����}�b�v�@3*3�G���A�������@���F" << number_ << std::endl;

						//�����3*3�G���A�ɓ���̐��l���������ꍇ�A��������
						num_working[i_][j_][number_] = "*";
						//std::cout << num_working[i_][j_] << std::endl;



					}
				}
			}

		}
	}

}

void Sudoku::_2_3_Nth_0_1_checker_3_row_col_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//����̒l�̗�A�s
			if (s[tate_][yoko_] == number_) {
				//�s�@��
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;


					//���̌�������
					num_working[tate_][row][number_] = "+";
				}

				//��@�c
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;

					//�c�̌�������
					num_working[col][yoko_][number_] = "+";
				}
			}
		}
	}

}
void Sudoku::_2_4_special_delete_ver2(int number_) {

	//���̏��������������̂����J�E���g
	_2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	for (int tate_move = 0; tate_move < 3; tate_move++) {

		for (int yoko_move = 0; yoko_move < 3; yoko_move++) {

			one_counter_in_3_3 = 0;
			// tate=4-6 yoko=4-6 ��true���J�E���g 
			for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {
						one_counter_in_3_3++;//3*3�̉��Z��
					}
				}
			}

			row_or_col_counter = 0;

			//3*3�̉��Z����3�܂���2�̂Ƃ�
			//��
			//�����3*3�G���A���ɏc�����ɐ��l���A�Ȃ��Ă�����A����ɑΉ������c�����𑊎E����
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

						//3�̂����̑Ώۃu���b�N��������1��
						for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;

							//���̌�������
							num_working[tate_][yoko1][number_] = "-";
						}

						//3�̂����̑Ώۃu���b�N��������1��
						for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;
							
							//���̌�������
							num_working[tate_][yoko1][number_] = "-";
						}


						//���̏��������������̂����J�E���g
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

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

						//3�̂����̑Ώۃu���b�N��������1��
						for (int tate1 = start_1_tate; tate1 <= start_1_tate + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;

							//�c�̌�������
							num_working[tate1][yoko_][number_] = ":";
						}

						//3�̂����̑Ώۃu���b�N��������1��
						for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;

							//�c�̌�������
							num_working[tate1][yoko_][number_] = ":";
						}


						//���̏��������������̂����J�E���g
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

					}
				}
			}
		}
	}
}


//3*3�u���b�N�ɐ��������������萔�ɕω�
void Sudoku::_2_5_change_1_to_number_in_3_3_blocks(int number_) {

	//�m�萔�l�̌�
	comment_result_num = 0;

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
							   
				//���Ƃ̐��l���m��
				s[save_tate_][save_yoko_] = number_;

				//�m�肵�����l��\�L
				num_working[save_tate_][save_yoko_][number_] = " ";

				//�m�萔�l�̌�
				comment_result_num++;

			}

		}
	}

	//�m�萔�l�̌���1�ȏ�̎�
	if (comment_result_num > 0) {

	}

}

void Sudoku::_4_decliment_3N_to_2N() {

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

//�S�̂̓����}�b�v�̒��Œl��1��������萔�ɕϊ� 
void Sudoku::find_1_in_each_f_map() {

	comment_result_num = 0;

	//����������������烋�[�v�𔲂���
	//find_1_in_each_f_map_bool = false;

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


						std::cout << "tate_=" << tate_ << " yoko_=" << yoko_ << " number_=" << number_ << std::endl;

						comment_result_num++;

						//int tate_, intyoko_, int number_ 
						//investigate_num_on_block();

						//�Ȃ����̃}�X�ɒl����������̂����ēx��������֐����쐬

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

			//���ۑ�
			keep_col_row_num_tate = tate_;
			keep_col_row_num_yoko = yoko_;

			//�����}�b�v��1�̂Ƃ��ɂ��̒l��������Ȃ�
			if (f_map[tate_][yoko_] == 1) {

				//����1�͂ǂ��̐��l���𒲂ׂ�
				for (int number_ = 1; number_ <= 9; number_++) {
					//�݂�����A�����萔������
					if (bool_num_[tate_][yoko_][number_] == true) {

						//���Ƃ̐��l����
						s[tate_][yoko_] = number_;


						std::cout << "tate_=" << tate_ << " yoko_=" << yoko_ << " number_=" << number_ << std::endl;

						comment_result_num++;

						//�񓚂�������ꂽ��A���̏ꏊ����肷��
						bool_find_1_in_each_f_map_one_time = true;


						detect_num = true;

						//�Ȃ����̃}�X�ɒl����������̂����ēx��������֐����쐬

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

			//�łȂ������珉�������Ă�����
			//keep_col_row_num_yoko = 0;

		}


		keep_col_row_num_yoko++;

		if (keep_col_row_num_yoko > 10) {
			keep_col_row_num_yoko = 1;
			keep_col_row_num_tate = 0;

		}


	}

	std::cout << "comment_result_num = " << comment_result_num << std::endl;




	//�Ȃ����̃}�X�̒l�����肳���̂��𒲍�����
	//investigate_num_on_block();//
	//investigate_num_on_block();

}


//�����}�b�v��\��������֐�
void Sudoku::f_map_table() {

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

//�Ō�ɕ\�������� ��͌��ʂ��s�\����������A�s�\���ƕ\��������
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
