
// MFC_SUDOKU_test1.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCSUDOKUtest1App:
// このクラスの実装については、MFC_SUDOKU_test1.cpp を参照してください
//

class CMFCSUDOKUtest1App : public CWinApp
{
public:
	CMFCSUDOKUtest1App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCSUDOKUtest1App theApp;
