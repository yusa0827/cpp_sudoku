
// MFC_SUDOKU_test2.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCSUDOKUtest2App:
// このクラスの実装については、MFC_SUDOKU_test2.cpp を参照してください
//

class CMFCSUDOKUtest2App : public CWinApp
{
public:
	CMFCSUDOKUtest2App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCSUDOKUtest2App theApp;
