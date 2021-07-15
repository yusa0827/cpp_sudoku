#include "pch.h"
#include "framework.h"
#include "MFC_SUDOKU_test2.h"
#include "MFC_SUDOKU_test2Dlg.h"
#include "class_SUDOKU.h"
#include <string>

//SUDOKUクラスはCMFCSUDOKUtest2Dlg（親）クラスを継承したから、親クラスのメンバーを自由に使ってもよい

//クラスの関数はcppで定義するのか
//void SUDOKU::SSS_1() {
//
//	for (int tate_ = 1; tate_ <= 9; tate_++) {
//		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
//
//			CStatic* pStatic = (CStatic*)GetDlgItem(sudoku_text[tate_][yoko_]);
//
//			std::string Button_No_Reflect = std::to_string(s[tate_][yoko_]);
//			//初期値が0だったら表示を無にする
//			if (s[tate_][yoko_] == 0) {
//				Button_No_Reflect = "";
//			}
//
//			CString s_reflect(Button_No_Reflect.c_str());
//			pStatic->SetWindowTextW(s_reflect);
//
//		}
//	}
//
//};