
// MFC_SUDOKU_test2Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MFC_SUDOKU_test2.h"
#include "MFC_SUDOKU_test2Dlg.h"
#include "afxdialogex.h"

#include <string>
#include "class_SUDOKU.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCSUDOKUtest2Dlg ダイアログ



CMFCSUDOKUtest2Dlg::CMFCSUDOKUtest2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_SUDOKU_TEST2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSUDOKUtest2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSUDOKUtest2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCSUDOKUtest2Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCSUDOKUtest2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCSUDOKUtest2Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCSUDOKUtest2Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCSUDOKUtest2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCSUDOKUtest2Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCSUDOKUtest2Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCSUDOKUtest2Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCSUDOKUtest2Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON58, &CMFCSUDOKUtest2Dlg::OnBnClickedButton58)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCSUDOKUtest2Dlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CMFCSUDOKUtest2Dlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCSUDOKUtest2Dlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCSUDOKUtest2Dlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCSUDOKUtest2Dlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CMFCSUDOKUtest2Dlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CMFCSUDOKUtest2Dlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CMFCSUDOKUtest2Dlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CMFCSUDOKUtest2Dlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON31, &CMFCSUDOKUtest2Dlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON32, &CMFCSUDOKUtest2Dlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CMFCSUDOKUtest2Dlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CMFCSUDOKUtest2Dlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CMFCSUDOKUtest2Dlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON36, &CMFCSUDOKUtest2Dlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CMFCSUDOKUtest2Dlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON38, &CMFCSUDOKUtest2Dlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON39, &CMFCSUDOKUtest2Dlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON41, &CMFCSUDOKUtest2Dlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON42, &CMFCSUDOKUtest2Dlg::OnBnClickedButton42)
	ON_BN_CLICKED(IDC_BUTTON43, &CMFCSUDOKUtest2Dlg::OnBnClickedButton43)
	ON_BN_CLICKED(IDC_BUTTON44, &CMFCSUDOKUtest2Dlg::OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON45, &CMFCSUDOKUtest2Dlg::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON46, &CMFCSUDOKUtest2Dlg::OnBnClickedButton46)
	ON_BN_CLICKED(IDC_BUTTON47, &CMFCSUDOKUtest2Dlg::OnBnClickedButton47)
	ON_BN_CLICKED(IDC_BUTTON48, &CMFCSUDOKUtest2Dlg::OnBnClickedButton48)
	ON_BN_CLICKED(IDC_BUTTON49, &CMFCSUDOKUtest2Dlg::OnBnClickedButton49)
	ON_BN_CLICKED(IDC_BUTTON51, &CMFCSUDOKUtest2Dlg::OnBnClickedButton51)
	ON_BN_CLICKED(IDC_BUTTON52, &CMFCSUDOKUtest2Dlg::OnBnClickedButton52)
	ON_BN_CLICKED(IDC_BUTTON53, &CMFCSUDOKUtest2Dlg::OnBnClickedButton53)
	ON_BN_CLICKED(IDC_BUTTON54, &CMFCSUDOKUtest2Dlg::OnBnClickedButton54)
	ON_BN_CLICKED(IDC_BUTTON55, &CMFCSUDOKUtest2Dlg::OnBnClickedButton55)
	ON_BN_CLICKED(IDC_BUTTON56, &CMFCSUDOKUtest2Dlg::OnBnClickedButton56)
	ON_BN_CLICKED(IDC_BUTTON57, &CMFCSUDOKUtest2Dlg::OnBnClickedButton57)
	ON_BN_CLICKED(IDC_BUTTON59, &CMFCSUDOKUtest2Dlg::OnBnClickedButton59)
	ON_BN_CLICKED(IDC_BUTTON61, &CMFCSUDOKUtest2Dlg::OnBnClickedButton61)
	ON_BN_CLICKED(IDC_BUTTON62, &CMFCSUDOKUtest2Dlg::OnBnClickedButton62)
	ON_BN_CLICKED(IDC_BUTTON63, &CMFCSUDOKUtest2Dlg::OnBnClickedButton63)
	ON_BN_CLICKED(IDC_BUTTON64, &CMFCSUDOKUtest2Dlg::OnBnClickedButton64)
	ON_BN_CLICKED(IDC_BUTTON65, &CMFCSUDOKUtest2Dlg::OnBnClickedButton65)
	ON_BN_CLICKED(IDC_BUTTON66, &CMFCSUDOKUtest2Dlg::OnBnClickedButton66)
	ON_BN_CLICKED(IDC_BUTTON67, &CMFCSUDOKUtest2Dlg::OnBnClickedButton67)
	ON_BN_CLICKED(IDC_BUTTON68, &CMFCSUDOKUtest2Dlg::OnBnClickedButton68)
	ON_BN_CLICKED(IDC_BUTTON69, &CMFCSUDOKUtest2Dlg::OnBnClickedButton69)
	ON_BN_CLICKED(IDC_BUTTON71, &CMFCSUDOKUtest2Dlg::OnBnClickedButton71)
	ON_BN_CLICKED(IDC_BUTTON72, &CMFCSUDOKUtest2Dlg::OnBnClickedButton72)
	ON_BN_CLICKED(IDC_BUTTON73, &CMFCSUDOKUtest2Dlg::OnBnClickedButton73)
	ON_BN_CLICKED(IDC_BUTTON74, &CMFCSUDOKUtest2Dlg::OnBnClickedButton74)
	ON_BN_CLICKED(IDC_BUTTON75, &CMFCSUDOKUtest2Dlg::OnBnClickedButton75)
	ON_BN_CLICKED(IDC_BUTTON76, &CMFCSUDOKUtest2Dlg::OnBnClickedButton76)
	ON_BN_CLICKED(IDC_BUTTON77, &CMFCSUDOKUtest2Dlg::OnBnClickedButton77)
	ON_BN_CLICKED(IDC_BUTTON78, &CMFCSUDOKUtest2Dlg::OnBnClickedButton78)
	ON_BN_CLICKED(IDC_BUTTON79, &CMFCSUDOKUtest2Dlg::OnBnClickedButton79)
	ON_BN_CLICKED(IDC_BUTTON89, &CMFCSUDOKUtest2Dlg::OnBnClickedButton89)
	ON_BN_CLICKED(IDC_BUTTON81, &CMFCSUDOKUtest2Dlg::OnBnClickedButton81)
	ON_BN_CLICKED(IDC_BUTTON82, &CMFCSUDOKUtest2Dlg::OnBnClickedButton82)
	ON_BN_CLICKED(IDC_BUTTON83, &CMFCSUDOKUtest2Dlg::OnBnClickedButton83)
	ON_BN_CLICKED(IDC_BUTTON84, &CMFCSUDOKUtest2Dlg::OnBnClickedButton84)
	ON_BN_CLICKED(IDC_BUTTON85, &CMFCSUDOKUtest2Dlg::OnBnClickedButton85)
	ON_BN_CLICKED(IDC_BUTTON86, &CMFCSUDOKUtest2Dlg::OnBnClickedButton86)
	ON_BN_CLICKED(IDC_BUTTON87, &CMFCSUDOKUtest2Dlg::OnBnClickedButton87)
	ON_BN_CLICKED(IDC_BUTTON88, &CMFCSUDOKUtest2Dlg::OnBnClickedButton88)
	ON_BN_CLICKED(IDC_BUTTON91, &CMFCSUDOKUtest2Dlg::OnBnClickedButton91)
	ON_BN_CLICKED(IDC_BUTTON92, &CMFCSUDOKUtest2Dlg::OnBnClickedButton92)
	ON_BN_CLICKED(IDC_BUTTON93, &CMFCSUDOKUtest2Dlg::OnBnClickedButton93)
	ON_BN_CLICKED(IDC_BUTTON94, &CMFCSUDOKUtest2Dlg::OnBnClickedButton94)
	ON_BN_CLICKED(IDC_BUTTON95, &CMFCSUDOKUtest2Dlg::OnBnClickedButton95)
	ON_BN_CLICKED(IDC_BUTTON96, &CMFCSUDOKUtest2Dlg::OnBnClickedButton96)
	ON_BN_CLICKED(IDC_BUTTON97, &CMFCSUDOKUtest2Dlg::OnBnClickedButton97)
	ON_BN_CLICKED(IDC_BUTTON98, &CMFCSUDOKUtest2Dlg::OnBnClickedButton98)
	ON_BN_CLICKED(IDC_BUTTON99, &CMFCSUDOKUtest2Dlg::OnBnClickedButton99)

	//Resource.hが自動に書き換わるときResource.h Resource.hのファイルを上書き修正する
	ON_BN_CLICKED(IDC_BUTTON_No1, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo1)
	ON_BN_CLICKED(IDC_BUTTON_No9, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo9)
	ON_BN_CLICKED(IDC_BUTTON_No2, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo2)
	ON_BN_CLICKED(IDC_BUTTON_No3, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo3)
	ON_BN_CLICKED(IDC_BUTTON_No4, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo4)
	ON_BN_CLICKED(IDC_BUTTON_No5, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo5)
	ON_BN_CLICKED(IDC_BUTTON_No6, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo6)
	ON_BN_CLICKED(IDC_BUTTON_No7, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo7)
	ON_BN_CLICKED(IDC_BUTTON_No8, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo8)
	ON_BN_CLICKED(IDC_BUTTON_No1, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo1)
	ON_BN_CLICKED(IDC_BUTTON_reflect, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonreflect)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS1, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis1)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS2, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis2)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS3, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis3)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS4, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis4)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS5, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis5)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS6, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis6)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS7, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis7)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS8, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis8)
	ON_BN_CLICKED(IDC_BUTTON_ANALYSIS9, &CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis9)
	ON_BN_CLICKED(IDC_BUTTON_demo_input, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput)
	ON_BN_CLICKED(IDC_BUTTON_demo_input2, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput2)
	ON_BN_CLICKED(IDC_BUTTON_demo_input3, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput3)
	ON_BN_CLICKED(IDC_BUTTON_demo_input4, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput4)
	ON_BN_CLICKED(IDC_BUTTON_demo_input5, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput5)
	ON_BN_CLICKED(IDC_BUTTON_demo_input6, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput6)
	ON_BN_CLICKED(IDC_BUTTON_demo_input7, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput7)
	ON_BN_CLICKED(IDC_BUTTON_demo_input8, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput8)
	//ON_BN_CLICKED(IDC_BUTTON_demo_input9, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput9)
	ON_BN_CLICKED(IDC_BUTTON_demo_input10, &CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput10)
	END_MESSAGE_MAP()


// CMFCSUDOKUtest2Dlg メッセージ ハンドラー

BOOL CMFCSUDOKUtest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMFCSUDOKUtest2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCSUDOKUtest2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCSUDOKUtest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//クリックしたらそのボタンの値を　back　の値に変換
// back　の値を　数独値に入れて、その値をボタンの名前にする
//二回目クリックされたら、文字を消去　

void CMFCSUDOKUtest2Dlg::sudoku_table_button_value(int tate_, int yoko_) {

	//まず数字が0の場合はButton_No_backを代入する
	if (s[tate_][yoko_] == 0) {

		//数独値を代入する
		s[tate_][yoko_] = Button_No_back;
		//仮保存
		keep_sudoku_button_value[tate_][yoko_] = Button_No_back;


		//数独ボタンのIDを入れる
		CButton* pButton_ = (CButton*)GetDlgItem(sudoku_ID[tate_][yoko_]);

		//前のボタンの名前も変更する
		std::string Button_No_ = std::to_string(s[tate_][yoko_]);
		CString s_(Button_No_.c_str());
		pButton_->SetWindowTextW(s_);
	}
	else {
		
		//クリックしたときに、以前のボタンの値と一致していた時
		if (keep_sudoku_button_value[tate_][yoko_] == Button_No_back) {

			//数独値を0に戻す
			s[tate_][yoko_] = 0;
			//仮保存
			keep_sudoku_button_value[tate_][yoko_] = Button_No_back;

			//数独ボタンのIDを入れる
			CButton* pButton_ = (CButton*)GetDlgItem(sudoku_ID[tate_][yoko_]);

			//前のボタンの名前を無にする
			std::string Button_No_ = "";
			CString s_(Button_No_.c_str());
			pButton_->SetWindowTextW(s_);

		}
		else {
			//クリックしたときに数独値と数独ボタンが一致していないとき

			//数独値を代入する
			s[tate_][yoko_] = Button_No_back;
			//仮保存
			keep_sudoku_button_value[tate_][yoko_] = Button_No_back;


			//数独ボタンのIDを入れる
			CButton* pButton_ = (CButton*)GetDlgItem(sudoku_ID[tate_][yoko_]);

			//前のボタンの名前を置き換える
			std::string Button_No_ = std::to_string(s[tate_][yoko_]);
			CString s_(Button_No_.c_str());
			pButton_->SetWindowTextW(s_);

		}


	}

	//もし数値が0の時にクリックしたら、Button_No_back変数が代入される * 別物であった　表示される前
	//もし0以外の数字が入っていたら、今クリックした値に置き換える **　表示された後
	//もしButton_No_backがある状態でクリックしたら、文字を消去する **　表示された後
	   
}



void CMFCSUDOKUtest2Dlg::OnBnClickedButton11()
{
	//初期値座標
	int tate_ = 1; int yoko_ = 1;
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton12()
{	
	int tate_ = 1; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton13()
{
	int tate_ = 1; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton14()
{
	int tate_ = 1; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton15()
{
	int tate_ = 1; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton16()
{
	int tate_ = 1; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton17()
{
	int tate_ = 1; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton18()
{
	int tate_ = 1; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton19()
{
	int tate_ = 1; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton21()
{
	int tate_ = 2; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton22()
{
	int tate_ = 2; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton23()
{
	int tate_ = 2; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton24()
{
	int tate_ = 2; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton25()
{
	int tate_ = 2; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton26()
{
	int tate_ = 2; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton27()
{
	int tate_ = 2; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton28()
{
	int tate_ = 2; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton29()
{
	int tate_ = 2; int yoko_ = 9 ;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton31()
{
	int tate_ = 3; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton32()
{
	int tate_ = 3; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton33()
{
	int tate_ = 3; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton34()
{
	int tate_ = 3; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton35()
{
	int tate_ = 3; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton36()
{
	int tate_ = 3; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton37()
{
	int tate_ = 3; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton38()
{
	int tate_ = 3; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton39()
{
	int tate_ = 3; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton41()
{
	int tate_ = 4; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton42()
{
	int tate_ = 4; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton43()
{
	int tate_ = 4; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton44()
{
	int tate_ = 4; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton45()
{
	int tate_ = 4; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton46()
{
	int tate_ = 4; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton47()
{
	int tate_ = 4; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton48()
{
	int tate_ = 4; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton49()
{
	int tate_ = 4; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton51()
{
	int tate_ = 5; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton52()
{
	int tate_ = 5; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton53()
{
	int tate_ = 5; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton54()
{
	int tate_ = 5; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton55()
{
	int tate_ = 5; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton56()
{
	int tate_ = 5; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton57()
{
	int tate_ = 5; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton58()
{
	int tate_ = 5; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton59()
{
	int tate_ = 5; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton61()
{
	int tate_ = 6; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton62()
{
	int tate_ = 6; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton63()
{
	int tate_ = 6; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton64()
{
	int tate_ = 6; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton65()
{
	int tate_ = 6; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton66()
{
	int tate_ = 6; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton67()
{
	int tate_ = 6; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton68()
{
	int tate_ = 6; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton69()
{
	int tate_ = 6; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton71()
{
	int tate_ = 7; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton72()
{
	int tate_ = 7; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton73()
{
	int tate_ = 7; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton74()
{
	int tate_ = 7; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton75()
{
	int tate_ = 7; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton76()
{
	int tate_ = 7; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton77()
{
	int tate_ = 7; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton78()
{
	int tate_ = 7; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton79()
{
	int tate_ = 7; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton81()
{
	int tate_ = 8; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton82()
{
	int tate_ = 8; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton83()
{
	int tate_ = 8; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton84()
{
	int tate_ = 8; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton85()
{
	int tate_ = 8; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton86()
{
	int tate_ = 8; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton87()
{
	int tate_ = 8; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton88()
{
	int tate_ = 8; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton89()
{
	int tate_ = 8; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton91()
{
	int tate_ = 9; int yoko_ = 1;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton92()
{
	int tate_ = 9; int yoko_ = 2;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton93()
{
	int tate_ = 9; int yoko_ = 3;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton94()
{
	int tate_ = 9; int yoko_ = 4;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton95()
{
	int tate_ = 9; int yoko_ = 5;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton96()
{
	int tate_ = 9; int yoko_ = 6;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton97()
{
	int tate_ = 9; int yoko_ = 7;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton98()
{
	int tate_ = 9; int yoko_ = 8;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButton99()
{
	int tate_ = 9; int yoko_ = 9;//初期値座標
	sudoku_table_button_value(tate_, yoko_);
}


void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNoChanger()
{

//今のボタン
	CButton* pButton_now = (CButton*)GetDlgItem(Button_ID[Button_No_now]);
	//前のボタン
	CButton* pButton_back = (CButton*)GetDlgItem(Button_ID[Button_No_back]);

	//今の値と前の値が一致しなかったら、
	if (Button_No_back != Button_No_now) {

		//前のボタンの名前も変更する
		std::string Button_No_Back = std::to_string(Button_No_back);
		CString s_back(Button_No_Back.c_str());
		pButton_back->SetWindowTextW(s_back);

		//今のボタンの名前に変更すし、前のボタンの名前も変更する
		//今のボタンの名前に変更
		std::string Button_No_Name = std::to_string(Button_No_now * 10 + Button_No_now);
		CString s_now(Button_No_Name.c_str());
		pButton_now->SetWindowTextW(s_now);

	}

}

//数独ボタン
/***********************************************************************/
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo1()
{
	Button_No_now = 1;

	//ボタンをクリックすると、1-9までの値をその値に整地する
	OnBnClickedButtonNoChanger();
	
	//前のボタンとして保存
	Button_No_back = 1;

}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo2()
{
	Button_No_now = 2;
	OnBnClickedButtonNoChanger();
	Button_No_back = 2;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo3()
{
	Button_No_now = 3;
	OnBnClickedButtonNoChanger();
	Button_No_back = 3;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo4()
{
	Button_No_now = 4;
	OnBnClickedButtonNoChanger();
	Button_No_back = 4;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo5()
{
	Button_No_now = 5;
	OnBnClickedButtonNoChanger();
	Button_No_back = 5;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo6()
{
	Button_No_now = 6;
	OnBnClickedButtonNoChanger();
	Button_No_back = 6;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo7()
{
	Button_No_now = 7;
	OnBnClickedButtonNoChanger();
	Button_No_back = 7;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo8()
{
	Button_No_now = 8;
	OnBnClickedButtonNoChanger();
	Button_No_back = 8;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonNo9()
{
	Button_No_now = 9;
	OnBnClickedButtonNoChanger();
	Button_No_back = 9;
}
/***********************************************************************/


//数独ボタンの値を数独表に反映させる
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonreflect()
{

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			CStatic* pStatic = (CStatic*)GetDlgItem(sudoku_text[tate_][yoko_]);

			std::string Button_No_Reflect = std::to_string(s[tate_][yoko_]);
			//初期値が0だったら表示を無にする
			if (s[tate_][yoko_] == 0) {
				Button_No_Reflect = "";
			}

			CString s_reflect(Button_No_Reflect.c_str());
			pStatic->SetWindowTextW(s_reflect);

		}
	}



}


//解析を始める数字を確定させる 初期
void CMFCSUDOKUtest2Dlg::OnBnClickedAnalysisButtonNoChanger()
{

	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	//特徴マップを初期化　数独を初期化
	_1_1_initailize_bool_num_3N_and_feature_map_2N();
	//可視化される特徴をマップを初期化
	_1_2_num_working_map_initialize();

	//特徴マップを初期化して表示
	show_Fmap_init();

	//今のボタン
	CButton* pButton_now = (CButton*)GetDlgItem(analysis_s_bottun_ID[ANALYSIS_Button_No_now]);
	//前のボタン
	CButton* pButton_back = (CButton*)GetDlgItem(analysis_s_bottun_ID[ANALYSIS_Button_No_back]);

	//今の値と前の値が一致しなかったら、
	if (ANALYSIS_Button_No_back != ANALYSIS_Button_No_now) {

		//前のボタンの名前も変更する 前のボタンがdeleteされていたら生じさせない
		if (delete_button_number[ANALYSIS_Button_No_back] == true) {

			pButton_back->SetWindowTextW(L"");

		}
		else {
			//deleteボタンネームでなかったら、数字を下記国
			std::string Button_No_Back = std::to_string(ANALYSIS_Button_No_back);
			CString s_back(Button_No_Back.c_str());
			pButton_back->SetWindowTextW(s_back);
		}


		//前のボタンの名前も変更する 前のボタンがdeleteされていたら生じさせない
		if (delete_button_number[ANALYSIS_Button_No_now] == true) {

			pButton_now->SetWindowTextW(L"");

		}
		else {
			//deleteボタンネームでなかったら、数字を下記国　表示されていることを確認するため
			std::string Button_No_Name = std::to_string(ANALYSIS_Button_No_now * 10 + ANALYSIS_Button_No_now);
			CString s_back(Button_No_Name.c_str());
			pButton_now->SetWindowTextW(s_back);
		}

		//今のボタンの名前に変更すし、前のボタンの名前も変更する
		//今のボタンの名前に変更
		//std::string Button_No_Name = std::to_string(ANALYSIS_Button_No_now * 10 + ANALYSIS_Button_No_now);
		//CString s_now(Button_No_Name.c_str());
		//pButton_now->SetWindowTextW(s_now);

	}

	////特徴マップを初期化　数独を初期化
	//_1_1_initailize_bool_num_3N_and_feature_map_2N();
	////可視化される特徴をマップを初期化
	//_1_2_num_working_map_initialize();
}

void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis1()
{
	ANALYSIS_Button_No_now = 1;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 1;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis2()
{
	ANALYSIS_Button_No_now = 2;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 2;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis3()
{
	ANALYSIS_Button_No_now = 3;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 3;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis4()
{
	ANALYSIS_Button_No_now = 4;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 4;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis5()
{
	ANALYSIS_Button_No_now = 5;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 5;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis6()
{
	ANALYSIS_Button_No_now = 6;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 6;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis7()
{
	ANALYSIS_Button_No_now = 7;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 7;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis8()
{
	ANALYSIS_Button_No_now = 8;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 8;
}
void CMFCSUDOKUtest2Dlg::OnBnClickedButtonAnalysis9()
{
	ANALYSIS_Button_No_now = 9;
	OnBnClickedAnalysisButtonNoChanger();
	ANALYSIS_Button_No_back = 9;
}



void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//デモ用に数独表を初期化
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			s[tate_][yoko_] = 0;
		}
	}

	s[1][8] = 8;
	s[1][9] = 7;
	s[3][3] = 1;
	s[3][4] = 2;
	s[3][5] = 3;
	s[4][3] = 2;
	s[4][6] = 4;
	s[5][3] = 3;
	s[5][7] = 5;
	s[6][4] = 8;
	s[6][6] = 5;
	s[6][8] = 6;
	s[7][5] = 1;
	s[7][7] = 3;
	s[8][1] = 8;
	s[8][6] = 7;
	s[9][1] = 6;

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			CStatic* pStatic = (CStatic*)GetDlgItem(sudoku_text[tate_][yoko_]);

			std::string Button_No_Reflect = std::to_string(s[tate_][yoko_]);
			//初期値が0だったら表示を無にする
			if (s[tate_][yoko_] == 0) {
				Button_No_Reflect = "";
			}

			CString s_reflect(Button_No_Reflect.c_str());
			pStatic->SetWindowTextW(s_reflect);

		}
	}


}

//消去してもよい　//変数を初期化するボタン
void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput2()
{
	//特徴マップを初期化　数独を初期化
	_1_1_initailize_bool_num_3N_and_feature_map_2N();
	//可視化される特徴をマップを初期化
	_1_2_num_working_map_initialize();
}

//特徴マップを初期化　数独を初期化
void CMFCSUDOKUtest2Dlg::_1_1_initailize_bool_num_3N_and_feature_map_2N() {

	//同時に初期化
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//各数字の特徴マップを1にする
				bool_num_[tate_][yoko_][number_] = true;
				//再度計算する用
				bool_num_cover[tate_][yoko_][number_] = true;
				//特徴特徴マップを初期化　
				f_map[tate_][yoko_] = 0;
			}
		}
	}
}

//可視化される特徴をマップを初期化
void CMFCSUDOKUtest2Dlg::_1_2_num_working_map_initialize() {
	//同時に初期化
	for (int number_ = 1; number_ <= 9; number_++) {
		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
				//各数字の特徴マップをその数字にする
				num_working[tate_][yoko_][number_] = std::to_string(number_);
			}
		}
	}
}

void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput3()
{
	//前のボタン
	CButton* pButton_back = (CButton*)GetDlgItem(analysis_s_bottun_ID[ANALYSIS_Button_No_back]);

	//解析終了ボタンは実行させない
	if (delete_button_number[ANALYSIS_Button_No_back] == true) {
		pButton_back->SetWindowTextW(L"");
	}

	// ANALYSIS_Button_No_back = 1;
	// 今の値（back）があると実行しない

	//指定したボタン数字はいくつなのか	ANALYSIS_Button_No_back
	_2_1_Nth_0_1_checker_1_TEISU(ANALYSIS_Button_No_back);

	//それに対する関数処理をまとめる
	show_Fmap();
}

//2_1 定数の場合　  
void CMFCSUDOKUtest2Dlg::_2_1_Nth_0_1_checker_1_TEISU(int number_) {
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//0 以外かつ特定番号1以外のとき
			if (s[tate_][yoko_] != 0 && s[tate_][yoko_] != number_) {
				bool_num_[tate_][yoko_][number_] = false;
				/*std::cout << "特徴マップ　定数を消去　数：" << number_ << std::endl;*/

				//候補を消す
				num_working[tate_][yoko_][number_] = "@";
			}
		}
	}

};

//特徴マップに書き込む関数
void CMFCSUDOKUtest2Dlg::show_Fmap() {

	for (int tate_ = 1; tate_ <= 9; tate_++) {

		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			CStatic* pStatic = (CStatic*)GetDlgItem(static_analysis[tate_][yoko_]);
			//特徴マップ
			std::string Button_No_Reflect = num_working[tate_][yoko_][ANALYSIS_Button_No_back];
			CString s_reflect(Button_No_Reflect.c_str());
			pStatic->SetWindowTextW(s_reflect);

		}

	}
}

//初期化された特徴マップを書き込む
void CMFCSUDOKUtest2Dlg::show_Fmap_init() {
	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			CStatic* pStatic = (CStatic*)GetDlgItem(static_analysis[tate_][yoko_]);
			pStatic->SetWindowTextW(L"");

		}
	}

}



//2_2 3*3エリアにその数字がある場合
void CMFCSUDOKUtest2Dlg::_2_2_Nth_0_1_checker_2_area_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {
			
			//特定の3*3エリアに特定の数値があった場合
			if (s[tate_][yoko_] == number_) {
				//スタート範囲
				int start_tate;
				int start_yoko;

				//縦のエリアを探索
				if (1 <= tate_ && tate_ <= 3) {
					start_tate = 1;
				}
				else if (4 <= tate_ && tate_ <= 6) {
					start_tate = 4;
				}
				else {
					start_tate = 7;
				}
				//横のエリアを探索
				if (1 <= yoko_ && yoko_ <= 3) {
					start_yoko = 1;
				}
				else if (4 <= yoko_ && yoko_ <= 6) {
					start_yoko = 4;
				}
				else {
					start_yoko = 7;
				}

				//エリアに加算する
				for (int i_ = start_tate; i_ < start_tate + 3; i_++) {
					for (int j_ = start_yoko; j_ < start_yoko + 3; j_++) {
						bool_num_[i_][j_][number_] = false;//0にする


						//std::cout << "特徴マップ　3*3エリアを消去　数：" << number_ << std::endl;

						//特定の3*3エリアに特定の数値があった場合、候補を消す
						num_working[i_][j_][number_] = "*";
						//std::cout << num_working[i_][j_] << std::endl;



					}
				}
			}

		}
	}

}

void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput4()
{
	_2_2_Nth_0_1_checker_2_area_3_3(ANALYSIS_Button_No_back);
	show_Fmap();
}

//2_3 数字がある列と行は0にする
void CMFCSUDOKUtest2Dlg::_2_3_Nth_0_1_checker_3_row_col_3_3(int number_) {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			//特定の値の列、行
			if (s[tate_][yoko_] == number_) {
				//行　横
				for (int row = 1; row <= 9; row++) {
					bool_num_[tate_][row][number_] = false;

					//横の候補を消す
					num_working[tate_][row][number_] = "+";
				}

				//列　縦
				for (int col = 1; col <= 9; col++) {
					bool_num_[col][yoko_][number_] = false;

					//縦の候補を消す
					num_working[col][yoko_][number_] = "+";
				}
			}
		}
	}

}

void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput5()
{
	_2_3_Nth_0_1_checker_3_row_col_3_3(ANALYSIS_Button_No_back);
	show_Fmap();
}


void CMFCSUDOKUtest2Dlg::_2_4_special_delete_ver2(int number_) {


	//この処理を何回やったのかをカウント
	_2_3_Nth_0_1_checker_3_row_col_3_3_counter = 0;

	for (int tate_move = 0; tate_move < 3; tate_move++) {

		for (int yoko_move = 0; yoko_move < 3; yoko_move++) {

			one_counter_in_3_3 = 0;
			// tate=4-6 yoko=4-6 のtrueをカウント 
			for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {//int tate_ = 4; tate_ <= 6; tate_++
				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					if (bool_num_[tate_][yoko_][number_] == true) {
						one_counter_in_3_3++;//3*3の加算数
					}
				}
			}

			row_or_col_counter = 0;

			//3*3の加算数が3または2のとき
			//↓
			//これは3*3エリア内に縦か横に数値が連なっていたら、それに対応した縦か横を相殺する
			if (one_counter_in_3_3 == 3 || one_counter_in_3_3 == 2) {
				// tate固定
				for (int tate_ = tate_move * 3 + 1; tate_ <= tate_move * 3 + 3; tate_++) {
					row_or_col_counter = 0;//この初期化が組まれていないかもしてない
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

						//3のうちの対象ブロックを除いた1つ
						for (int yoko1 = start_1_yoko; yoko1 <= start_1_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;

							//横の候補を消す
							num_working[tate_][yoko1][number_] = "-";
						}

						//3のうちの対象ブロックを除いた1つ
						for (int yoko1 = start_2_yoko; yoko1 <= start_2_yoko + 2; yoko1++) {
							bool_num_[tate_][yoko1][number_] = false;

							//横の候補を消す
							num_working[tate_][yoko1][number_] = "-";
						}


						//この処理を何回やったのかをカウント
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

					}
				}


				for (int yoko_ = yoko_move * 3 + 1; yoko_ <= yoko_move * 3 + 3; yoko_++) {
					row_or_col_counter = 0;//この初期化が組まれていないかもしてない
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

						//3のうちの対象ブロックを除いた1つ
						for (int tate1 = start_1_tate; tate1 <= start_1_tate + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;

							//縦の候補を消す
							num_working[tate1][yoko_][number_] = ":";
						}

						//3のうちの対象ブロックを除いた1つ
						for (int tate1 = start_2_yoko; tate1 <= start_2_yoko + 2; tate1++) {
							bool_num_[tate1][yoko_][number_] = false;

							//縦の候補を消す
							num_working[tate1][yoko_][number_] = ":";
						}


						//この処理を何回やったのかをカウント
						_2_3_Nth_0_1_checker_3_row_col_3_3_counter++;

					}
				}
			}
		}
	}



}

//3 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去	
void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput6()
{
	_2_4_special_delete_ver2(ANALYSIS_Button_No_back);

	//それに対する関数処理をまとめる
	show_Fmap();
}


//それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
void CMFCSUDOKUtest2Dlg::_2_5_change_1_to_number_in_3_3_blocks(int number_) {

	//確定数値の個数
	comment_result_num = 0;

	for (int tate_tate = 0; tate_tate < 3; tate_tate++) {
		for (int yoko_yoko = 0; yoko_yoko < 3; yoko_yoko++) {

			//左ブロック目 3*3 を走査
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

			//3*3ブロックでインクリメント1のときに確定　座標を確保
			if (inclimenter_3_3 == 1) {

				//数独の数値が確定
				s[save_tate_][save_yoko_] = number_;

				//確定した数値を表記
				num_working[save_tate_][save_yoko_][number_] = " ";

				//確定数値の個数
				comment_result_num++;

			}

		}
	}

	//確定数値の個数が1個以上の時
	if (comment_result_num > 0) {

		CStatic* pStatic = (CStatic*)GetDlgItem(1266);
		pStatic->SetWindowTextW(L"解析結果　解析できました");

			}
	else {

		CStatic* pStatic = (CStatic*)GetDlgItem(1266);
		pStatic->SetWindowTextW(L"解析結果　解析できませんでした");

	}

}

//数独表に書き込む
void CMFCSUDOKUtest2Dlg::show_sudoku_table_MFC() {

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			CStatic* pStatic = (CStatic*)GetDlgItem(sudoku_text[tate_][yoko_]);

			std::string Button_No_Reflect = std::to_string(s[tate_][yoko_]);
			//初期値が0だったら表示を無にする
			if (s[tate_][yoko_] == 0) {
				Button_No_Reflect = "";
			}

			CString s_reflect(Button_No_Reflect.c_str());
			pStatic->SetWindowTextW(s_reflect);

		}
	}

}
//解析した値を数独表に書き込む
void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput7()
{
	_2_5_change_1_to_number_in_3_3_blocks(ANALYSIS_Button_No_back);
	
	//確定した数値を数独表に乗せる
	show_sudoku_table_MFC();
	
	//ここで数独内での数字で全て使われたらボタンに数字を消す
	delete_button_number_name();

	//解析数を反映させる
	sudoku_analysis_percent();

}


void CMFCSUDOKUtest2Dlg::delete_button_number_name() {
	
	for (int number_ = 1; number_ <= 9; number_++) {

		//消去する番号のカウンター
		int delete_number_counter = 0;

		//int* intptr = &delete_number_counter;

		for (int tate_ = 1; tate_ <= 9; tate_++) {
			for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

				//番号と数字が一致した回数
				if (s[tate_][yoko_] == number_) {
					delete_number_counter++;
				}

			}

		}

		//数字のカウンターが9個だったら、ボタンの文字を消す
		if (delete_number_counter == 9) {
			
			//その数字ナンバー　の名前意を消す

			CStatic* pStatic = (CStatic*)GetDlgItem(analysis_s_bottun_ID[number_]);

			//CString s_reflect(Button_No_Reflect.c_str());
			pStatic->SetWindowTextW(L"");

			//ボタンを消去するようにうごく
			delete_button_number[number_] = true;


		}


	}

}

void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput8()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

		//特徴マップを初期化　数独を初期化
	_1_1_initailize_bool_num_3N_and_feature_map_2N();
	//可視化される特徴をマップを初期化
	_1_2_num_working_map_initialize();

	//特徴マップを初期化して表示
	show_Fmap_init();
}


/* 解決した数字は選択肢から消す */
/* 特別処理（縦と横の1から9までの解析方法） */
/* 処理のアルゴリズムを図示で買い込みしたほうがいい */
/* 解析終了数値はアルゴリズム解析を実行させない */

void CMFCSUDOKUtest2Dlg::sudoku_analysis_percent() {

	int sudoku_analysis_percent_counter = 0;

	for (int tate_ = 1; tate_ <= 9; tate_++) {
		for (int yoko_ = 1; yoko_ <= 9; yoko_++) {

			if (s[tate_][yoko_] != 0) {
				sudoku_analysis_percent_counter++;
			}

		}
	}

	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_ANALYSIS_PERCENT);

	std::string sudoku_percent = std::to_string(sudoku_analysis_percent_counter) + " / 81";
	////初期値が0だったら表示を無にする
	//if (s[tate_][yoko_] == 0) {
	//	Button_No_Reflect = "";
	//}

	CString s_reflect(sudoku_percent.c_str());
	pStatic->SetWindowTextW(s_reflect);
	
}



void CMFCSUDOKUtest2Dlg::OnBnClickedButtondemoinput10()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	int plus_ = 22;
	for (int i = 1; i < plus_; i++) {

		//数独を初期化 全体の特徴マップの変数を初期化する
		_1_1_initailize_bool_num_3N_and_feature_map_2N();

		//解説コメント変数を初期化
		_1_2_num_working_map_initialize();


		//各番号において　0と1に分ける　0存在しない　1存在する可能性がある
		for (int number_ = 1; number_ <= 9; number_++) {

			//N番目の特徴マップ 既存の値とかぶっていたら 0に変更
			//sudoku._2_Nth_0_1_checker(number_);

			//2_1 定数の場合　  
			_2_1_Nth_0_1_checker_1_TEISU(number_);
			////2_2 3*3エリアにその数字がある場合
			_2_2_Nth_0_1_checker_2_area_3_3(number_);
			//2_3 数字がある列と行は0にする
			_2_3_Nth_0_1_checker_3_row_col_3_3(number_);
			//2_4 3*3エリア内に縦・横のみに1がある場合に他の縦・横を消去 
			_2_4_special_delete_ver2(number_);//難易度*****
			//number_working_map(number_);


			////それぞれの特徴量マップの3*3のマスの中に1があったら定数に変化
			_2_5_change_1_to_number_in_3_3_blocks(number_);
			//number_working_map(number_);

			//数独の初期の表
			//sudoku_table_first();

			//_2_5_change_1_to_number_in_3_3_blocks(ANALYSIS_Button_No_back);

			//確定した数値を数独表に乗せる
			show_sudoku_table_MFC();

			//ここで数独内での数字で全て使われたらボタンに数字を消す
			delete_button_number_name();

			//解析数を反映させる
			sudoku_analysis_percent();

		}


		//マップの和が0だとbreak
		if (f_map_sum == 0) {
			break;
		}

	}

	//sudoku_table_end();

	//_2_5_change_1_to_number_in_3_3_blocks(ANALYSIS_Button_No_back);

	////確定した数値を数独表に乗せる
	//show_sudoku_table_MFC();

	////ここで数独内での数字で全て使われたらボタンに数字を消す
	//delete_button_number_name();

	////解析数を反映させる
	//sudoku_analysis_percent();
}
