#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>

//���Ƃ̉�@�p�̃N���X
class SUDOKU_ {
private://�\����ɂ͏o�Ă��Ȃ��ϐ�
	int tate;
	int yoko;
	int sleep_from_class;// ��������E���Ă���
	bool maybe_fix;//�`�F�b�J�[�ɔ���������false�ɂȂ��Ă�����x
	


public://���C���Ŏg���ϐ���֐�����

	
	//���ƍ��W�̏�����
	int s[10][10] = { 0 };
	//�����@���l�𕶎���ɓ����
	std::string s_[10][10];
	//���݂̃}�X�������ƈ�v���Ă��Ȃ������m�F���邽�߂̕ϐ�
	std::string s_tate_yoko_;
	//s[start_tate][start_yoko] = init_value_from_class
	int init_value_from_class;
	//�T���X�^�[�g�ʒu�@�����ƈ�v�����ꍇ�͓���
	int start_tate = 1;
	int start_yoko = 1;
	//�����̐�
	int key_num = -1;
	//�����@�����Ƃ͏����l�̒萔
	std::string key_[81];//�z��̐������߂�K�v������
	//s[9][9]�܂Ŗ��܂��false��true�ɂ���
	bool fin_sudoku_switch = false;
	
	//  �R���X�g���N�^ �X�^�[�g�ʒu�̒l�������Ă���
	SUDOKU_(int start_number) {
		init_value_from_class = start_number;
	};
	   	
	//���������@�萔����
	void insert_init_(int init_s[10][10]);
	//�������
	void make_dictionary();
	//�\��\�� �\�����Ԃ�0.2�b
	void display_table(int sleep_ = 200);
	//�����ʒu�|�W�V�������N���X�ɑ�����������l�ŒT��
	void detect_start_position();
	//�T���J�n�@�c�A���A�e(3*3)�G���A���`�F�b�N
	void check_row_and_col_and_area();
	//�w�肵���l�őS�T��
	void start_multi_thread_();
	
	//�}���`�X���b�h�֐��@�����lN�݂̒T�����J�n
	void MT_nth_single_shot_();//
};

//�����l���N���X�̃����o�[�ϐ��ɑ��
void SUDOKU_::insert_init_(int init_s[10][10]) {
	//��
	for (int j = 1; j <= 9; j++) {
		//�c
		for (int i = 1; i <= 9; i++) {
			//�����l����
			if (init_s[j][i] != 0) {
				s[j][i] = init_s[j][i];
			}
		}
	}
}


void SUDOKU_::MT_nth_single_shot_() {

	//�T���̏����ʒu�Ə����l����
	tate = start_tate;
	yoko = start_yoko;
	//�N���X�ɑ�������l�������ʒu�̏����l
	s[tate][yoko] = init_value_from_class;

	for (;;) {
		//���Ƃ̃��[���Ɉᔽ������true��fALSE
		maybe_fix = true;
		//�����ƏƂ炵���킹�邽�߂Ɍ��݂̃}�X�𕶎���
		s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";
				
		//���݂̃}�X�Ǝ�������v���邩���m�F
		for (int i = 0; i < key_num; i++) {

			//�����ƈ�v�����ꍇ�͌J��グ
			if (s_tate_yoko_ == key_[i]) {

				//s[tate][9]�̂Ƃ��As[yoko+1][1] �������Ƃ���9��������A1�ɂ���
				++yoko;//�����C���N�������g
				if (yoko > 9) {//9=1�ɂȂ�����A1�ɏ�����
					yoko = 1;
					++tate;//�c��1�i�߂�
				}

				//�����ƈ�v��������
				maybe_fix = false;
			}

		}

		/* check
		���ň�v���Ȃ������m�F ��v������l���C���N�������g
		�c�ň�v���Ȃ������m�F ��v������l���C���N�������g
		3*3�ȓ��ɓ��������������Ă��Ȃ������m�F ��v������l���C���N�������g
		*/
		SUDOKU_::check_row_and_col_and_area();


		
		//���݂̃}�Xs[][]��9�𒴂�����
		if (s[tate][yoko] > 9) {

			//�萔�̏ꍇ�͏��������Ă͂����Ȃ�
			//--yoko;//1�X�e�b�v�߂� �������A�萔�̏ꍇ�͂���ɃX�L�b�v����for���̏���

			maybe_fix = false;//�܂�������\��������܂�
			bool jisyo_check = true;

			//���݂̃}�X��������
			s[tate][yoko] = 0;

			//�J�艺��
			if (yoko == 1) {//s[tate][1](���[)�̂Ƃ��A���Ɉړ�s[tate - 1][9]
				tate = tate - 1;
				yoko = 9;

			}
			else {//�ׂɈړ�����
				yoko = yoko - 1;
			}


			//�ړ������Z�����萔��������A������x���������@�ړ�
			int incliment = 0;
			for (;;) {

				//�߂����l��������ł�������Abreak����@�L�[������for������				
				for (int i = 0; i < key_num; i++) {

					//1�X�e�b�v�߂����l�𕶎���Ƃ��� ���ɖ߂��Ă݂�
					s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";



					//�@1�X�e�b�v�߂����l�𕶎��񂪒萔�ł͂Ȃ������`�F�b�N����
					if (s_tate_yoko_ == key_[i]) {
						jisyo_check = false;


						if (yoko == 1) {//s[tate][1]�̂Ƃ��A���Ɉړ�s[tate - 1][9]
							tate = tate - 1;
							yoko = 9;
						}
						else {
							yoko = yoko - 1;
						}


						incliment = 0;
						break;//��v�����甲����
					}

				}

				++incliment;
				// incliment ���O��C���N�������g�����Ƃ���
				if (incliment == 3) {

					++s[tate][yoko];

					maybe_fix = false;//�܂�������\��������܂�
					break;//��v�����甲����
				}

			}


		}

		
		//���Ƃ̃��[���Ɉᔽ���Ă����Ȃ�������true
		if (maybe_fix == true) {

			//�ᔽ���Ă��Ȃ������Ƃ��̉�
			static int repeat_times = 0;
			++repeat_times;//�C���N�������g

			//true�ŋA���Ă�����A�\�쐬
			if (repeat_times % 1000000 == 0) {
				std::cout << "���s�� = " << repeat_times << std::endl;

				std::cout << "init_value_from_class�@= " << init_value_from_class << std::endl;

				
				//�\�쐬
				SUDOKU_::display_table(sleep_from_class);
							   
			}

			//�w�肵�������l
			if (s[start_tate][start_yoko] != init_value_from_class) {

				std::cout << "�����l�@= " << init_value_from_class 
					<< "�ł͂Ȃ������̂�break���܂��B" << std::endl;
				break;
			}




			//cheker�őS�ĂɊY�����Ȃ��A���ׂĖ��܂����琬���H�@�I��
			if (yoko == 9 && tate == 9) {
				std::cout <<"�����l�@= " << init_value_from_class 
					<< "���ׂẴ}�X�����܂�܂���." << std::endl;
				std::cout << "�������I�����܂�." << std::endl;
				SUDOKU_::display_table(sleep_from_class);//�\�쐬
				
				fin_sudoku_switch = true;// true�ɂȂ�ƁA���C���֐����I��������
				break;
			}


			//�ׂɃX�L�b�v����
			++yoko;//s[tate][yoko] �� s[tate][yoko + 1]

			if (yoko > 9) {
				++tate;//�c�𑝂₵�āA
				yoko = 1;//����������

			}

			//�X�L�b�v�����}�X�������ɂ��邩���m�F
			for (int i = 0; i < key_num; i++) {


				// �����̂��߂ɕ������������
				s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";
				//���������������v�����ꍇ�A���ɃX�L�b�v
				if (s_tate_yoko_ == key_[i]) {

					++yoko;//���ɃX�L�b�v
					//�ŃX�L�b�v�����}�X��9�𒴂����玟�̍s��1�}�X��
					if (yoko > 9) {//9=1�ɂȂ�����A1�ɏ�����
						yoko = 1;
						++tate;//�c��1�i�߂�

					}


				}

				//�萔�ł͂Ȃ������A�܂�0�������ꍇ��1�ɂ���
				if (s[tate][yoko] == 0) {
					s[tate][yoko] = 1;//���̃X�e�b�v�ւ̏������@�萔�̏ꍇ�͏����������Ă͂����Ȃ�
				}


			}

		}


	}

}



void SUDOKU_::check_row_and_col_and_area() {

	//check_ ���ň�v���Ȃ������m�F
	for (int i = 1; i < 10; i++) {
		//�����z��ԍ��o�Ȃ��悤�ɁA�܂������ăK�[�h
		if (i != yoko) {
			//����ł��l����v�����ꍇ�̓C���N�������g
			if (s[tate][yoko] == s[tate][i]) {
				
				++s[tate][yoko];//�l��������
				maybe_fix = false;//�܂�������\��������܂�
			}
		}
	}

	//check_ �c�ň�v���Ȃ������m�F
	for (int i = 1; i < 10; i++) {
		//�����z��ԍ��o�Ȃ��悤�ɁA�܂������ăK�[�h
		if (i != tate) {
			//����ł��l����v�����ꍇ�̓C���N�������g
			if (s[tate][yoko] == s[i][yoko]) {

				++s[tate][yoko];//�l��������
				maybe_fix = false;//�܂�������\��������܂�
			}
		}
	}

	//check_ ���Əc�@�X���C�h�͈́i3*3�j��T��
	int state_of_yoko;
	int state_of_tate;
	//���@�X���C�h�͈͂�T��
	if (1 <= yoko && yoko <= 3) {
		state_of_yoko = 1;
	}
	else if (4 <= yoko && yoko <= 6) {
		state_of_yoko = 4;
	}
	else {
		state_of_yoko = 7;
	}
	//�c�@�X���C�h�͈͂�T��
	if (1 <= tate && tate <= 3) {
		state_of_tate = 1;
	}
	else if (4 <= tate && tate <= 6) {
		state_of_tate = 4;
	}
	else {
		state_of_tate = 7;
	}
	//�����c�X���C�h�ň�v���Ȃ������`�F�b�N
	for (int i = state_of_tate; i < state_of_tate + 3; i++) {
		for (int j = state_of_yoko; j < state_of_yoko + 3; j++) {

			// �ϐ��̉��Əc�̍��W����v���Ȃ����Ƃ�����
			if (i != tate && j != yoko) {

				//���W����v���Ȃ��A�l����v�����ꍇ�A�J��グ
				if (s[tate][yoko] == s[i][j]) {

					++s[tate][yoko];//�l��������
					maybe_fix = false;//�܂�������\��������܂�

				}
			}
		}
	}



}


void SUDOKU_::start_multi_thread_() {

	tate = start_tate;
	yoko = start_yoko;
	s[tate][yoko] = init_value_from_class;
	
	for (;;) {


		std::string s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";

		//�l������ȏ�オ��Ȃ����Ƃ��u�[���ŕ\��
		maybe_fix = true;//�����Ƃ��������ɉ�Ȃ�����Atrue�ŋA���Ă�����Abreak


		//*******************************************************����
		//�����ɂ���Ƃ������Ƃ́A����̏������X�L�b�v���Ȃ��Ƃ����Ȃ�
		//check1�@�����^�Œ萔�łȂ������m�F s[1][1] 
		//�����ƈ�v�����ꍇ�A�ׂɈړ�����
		for (int i = 0; i < key_num; i++) {

			//�@s[1][1]���萔�ł͂Ȃ������`�F�b�N����
			if (s_tate_yoko_ == key_[i]) {

				//s[yoko][9]�̂Ƃ��As[yoko+1][1] �������Ƃ���9��������A1�ɂ���
				++yoko;//�����C���N�������g
				if (yoko == 10) {//9=1�ɂȂ�����A1�ɏ�����
					yoko = 1;
					++tate;//�c��1�i�߂�

				}

				maybe_fix = false;//�܂�������\��������܂�
				//break;���̕����������ɂ��邩������Ȃ��̂ŁA break�͂��Ȃ�
			}

		}

		/* check
		���ň�v���Ȃ������m�F ��v������l���C���N�������g
		�c�ň�v���Ȃ������m�F ��v������l���C���N�������g
		3*3�ȓ��ɓ��������������Ă��Ȃ������m�F ��v������l���C���N�������g
		*/
		SUDOKU_::check_row_and_col_and_area();


		//s[][]�ɉ��Z���邽�߁A���L�̃t�H���X�J�E���^�[�ł͖��Ӗ�
		if (s[tate][yoko] > 9) {

			
			maybe_fix = false;//�܂�������\��������܂�

			bool jisyo_check = true;


			s[tate][yoko] = 0;//�@������


			//�J��グ
			if (yoko == 1) {//s[tate][1](���[)�̂Ƃ��A���Ɉړ�s[tate - 1][9]
				tate = tate - 1;
				yoko = 9;

			}
			else {//�ׂɈړ�����
				yoko = yoko - 1;
			}


			//�ړ������Z�����萔��������A������x���������@�ړ�


			int incliment = 0;
			for (;;) {

				//�߂����l��������ł�������Abreak����@�L�[������for������				
				for (int i = 0; i < key_num; i++) {

					//1�X�e�b�v�߂����l�𕶎���Ƃ��� ���ɖ߂��Ă݂�
					s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";


					//�@1�X�e�b�v�߂����l�𕶎��񂪒萔�ł͂Ȃ������`�F�b�N����
					if (s_tate_yoko_ == key_[i]) {
						jisyo_check = false;


						if (yoko == 1) {//s[tate][1]�̂Ƃ��A���Ɉړ�s[tate - 1][9]
							tate = tate - 1;
							yoko = 9;

						}
						else {
							yoko = yoko - 1;
						}


						incliment = 0;
						break;//��v�����甲����
					}

				}

				++incliment;
				//�����Ɉ���������Ȃ������Ƃ��C���N�������g
				if (incliment == 3) {

					++s[tate][yoko];

					maybe_fix = false;//�܂�������\��������܂�
					break;//��v�����甲����
				}


			}


		}


		//�ύX���ꂸ�ɋA���Ă�����Atrue�ƂȂ�
		if (maybe_fix == true) {

			static int repeat_times = 0;//�C���N�������g
			++repeat_times;

			//true�ŋA���Ă�����A�\�쐬
			if (repeat_times % 1000000 == 0) {
				std::cout << "���s�� = " << repeat_times << std::endl;
				SUDOKU_::display_table(sleep_from_class);//�\�쐬
			}

			//cheker�őS�ĂɊY�����Ȃ��A���ׂĖ��܂����琬���H�@�I��
			if (yoko == 9 && tate == 9) {
				std::cout << "checker�ł����Ȃ��A���ׂẴ}�X�����܂�܂���." << std::endl;
				SUDOKU_::display_table(sleep_from_class);//�\�쐬
				std::cout << "�������I�����܂�." << std::endl;
				fin_sudoku_switch = true;// true�ɂȂ�ƁA���C���֐����I��������
				break;
			}

			//�J��グ
			++yoko;//s[tate][yoko] �� s[tate][yoko + 1]

			if (yoko > 9) {
				++tate;//�c�𑝂₵�āA
				yoko = 1;//����������

			}


			//�X�L�b�v�����}�X�������ɂ��邩���m�F
			for (int i = 0; i < key_num; i++) {

				// �����̂��߂ɕ������������
				s_tate_yoko_ = "s[" + std::to_string(tate) + "][" + std::to_string(yoko) + "]";
				//���������������v�����ꍇ�A���ɃX�L�b�v
				if (s_tate_yoko_ == key_[i]) {

					++yoko;//���ɃX�L�b�v
					//�ŃX�L�b�v�����}�X��9�𒴂����玟�̍s��1�}�X��
					if (yoko > 9) {//9=1�ɂȂ�����A1�ɏ�����
						yoko = 1;
						++tate;//�c��1�i�߂�

					}


				}

				//�萔�ł͂Ȃ������A�܂�0�������ꍇ��1�ɂ���
				if (s[tate][yoko] == 0) {
					s[tate][yoko] = 1;//���̃X�e�b�v�ւ̏������@�萔�̏ꍇ�͏����������Ă͂����Ȃ�
				}


			}

		}


	}
}



//���߂ɑ���ł���}�X��T��
void SUDOKU_::detect_start_position() {
	
	//init_value_from_class = start_number;
	s[start_tate][start_yoko] = init_value_from_class;

	//������s[start_tate][start_yoko]�͎����ɂ��邩�������Ŕ��f����
	for (int i = 0; i < key_num; i++) {
		//���݂̃}�X�𕶎���
		s_tate_yoko_ = "s[" + std::to_string(start_tate) + "][" + std::to_string(start_yoko) + "]";
		//�����ƈ�v�����ꍇ�͌J��グ
		if (s_tate_yoko_ == key_[i]) {
			//s[tate][yoko] �� s[tate][yoko + 1] 
			start_yoko++;
			//s[tate][9] �� s[tate + 1][1]
			if (start_yoko > 9) {
				start_yoko = 1;
				start_tate++;
			}			
		}
	}
	
	std::cout << "���߂ɑ���ł���}�X " 
		<< "s[" << start_tate <<"]["<< start_yoko <<"] = " << init_value_from_class << std::endl;
	
}

//�\�̕\��
void SUDOKU_::display_table(int sleep_) {
	//�N���X��private�ϐ��ɑ��
	sleep_from_class = sleep_;
	
	//�\�p�̕������w��
	std::string space_ = " ";//�����̂��߂̃X�y�[�X
	std::string vertical_ = "|";//�c��
	std::string horizontal_ = "-";//����

	std::cout << std::endl;
	//����
	std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_
		<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;

	// j��1,2,3�Ƒ������, i��0+1,3+1,6*1
	for (int j = 0; j < 3; j++) {

		//�@1����3�s��
		for (int i = j * 3 + 1; i < (j + 1) * 3 + 1; i++) {

			// �S�ĕ�����ɓ����A�Ȃ��Ȃ�[�@]�󔒂��g����������
			//�@����0�̒l�̎��́A�󗓂̕������������
			for (int k = 1; k <= 9; k++) {

				s_[i][k] = std::to_string(s[i][k]);

				//0���ƃX�y�[�X
				if (s_[i][k] == "0") {
					s_[i][k] = " ";
				}
				//9�𒴂����X
				if (s[i][k] > 9) {
					s_[i][k] = "X";
				}

				s_tate_yoko_ = "s[" + std::to_string(i) + "][" + std::to_string(k) + "]";

				//�����ƈ�v������A�����̐F��ς���
				for (int x = 0; x < key_num + 1; x++) {

					//�@s[1][1]���萔�ł͂Ȃ������`�F�b�N���� 
					//�@�����ƈ�v������
					if (s_tate_yoko_ == key_[x]) {
						
						//�����ƈ�v������F��ς���
						s_[i][k] = "\033[33m" + s_[i][k] + "\033[0m";
						s_[i][k] = "\033[33m" + s_[i][k] + "\033[0m";
						
					}
				}
			}

			std::cout << vertical_ << s_[i][1] << s_[i][2] << s_[i][3] << vertical_
				<< s_[i][4] << s_[i][5] << s_[i][6] << vertical_
				<< s_[i][7] << s_[i][8] << s_[i][9] << vertical_ << std::endl;

		}

		std::cout << horizontal_ << horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_
			<< horizontal_ << horizontal_ << horizontal_ << horizontal_ << std::endl;
	}

	std::cout << std::endl;
	//��~�@sleep_[ms]
	Sleep(sleep_);

}

//�����̍쐬
void SUDOKU_::make_dictionary() {

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {

			//�����l��0�łȂ������玫��(�萔)�ɕۑ�
			if (s[i][j] != 0) {
				key_[++key_num] = "s[" + std::to_string(i) + "][" + std::to_string(j) + "]";

			}

		}

	}
}