
// MFC_SUDOKU_test1Dlg.h : ヘッダー ファイル
//

#pragma once


// CMFCSUDOKUtest1Dlg ダイアログ
class CMFCSUDOKUtest1Dlg : public CDialogEx
{
// コンストラクション
public:
	CMFCSUDOKUtest1Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_SUDOKU_TEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
