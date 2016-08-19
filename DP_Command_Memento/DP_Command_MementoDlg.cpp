
// DP_Command_MementoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DP_Command_Memento.h"
#include "DP_Command_MementoDlg.h"
#include "afxdialogex.h"
#include "MyClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDP_Command_MementoDlg dialog



CDP_Command_MementoDlg::CDP_Command_MementoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDP_Command_MementoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

CDP_Command_MementoDlg::~CDP_Command_MementoDlg()
{
	if (this->pBtn1Command)
		delete this->pBtn1Command;
	if (this->pBtn2Command)
		delete this->pBtn2Command;
	if (this->pBtn3Command)
		delete this->pBtn3Command;
	if (this->pBtn4Command)
		delete this->pBtn4Command;
	if (this->pPlayer)
		delete this->pPlayer;
	if (this->pCaretaker)
		delete this->pCaretaker;
}

void CDP_Command_MementoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDP_Command_MementoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDP_Command_MementoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDP_Command_MementoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDP_Command_MementoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDP_Command_MementoDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDP_Command_MementoDlg message handlers

BOOL CDP_Command_MementoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	this->pPlayer = new Player();
	this->pCaretaker = new Caretaker();
	this->pBtn1Command = new BattleCommand(this->pPlayer);
	this->pBtn2Command = new SaveCommand(this->pPlayer, this->pCaretaker);
	this->pBtn3Command = new LoadCommand(this->pPlayer, this->pCaretaker);
	this->pBtn4Command = new UndoCommand(this->pPlayer);
	UpdateUI();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDP_Command_MementoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDP_Command_MementoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDP_Command_MementoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CDP_Command_MementoDlg::UpdateUI()
{
	CString csHP;
	csHP.Format(_T("%d"), pPlayer->GetHP());
	((CStatic*)GetDlgItem(IDC_STATIC_HP))->SetWindowText(csHP);
	
	CString csEXP;
	csEXP.Format(_T("%d"), pPlayer->GetEXP());
	((CStatic*)GetDlgItem(IDC_STATIC_EXP))->SetWindowText(csEXP);
}

void CDP_Command_MementoDlg::OnBnClickedButton1()
{
	this->pBtn1Command->execute();
	UpdateUI();
}

void CDP_Command_MementoDlg::OnBnClickedButton2()
{
	this->pBtn2Command->execute();
	UpdateUI();
}

void CDP_Command_MementoDlg::OnBnClickedButton3()
{
	this->pBtn3Command->execute();
	UpdateUI();
}

void CDP_Command_MementoDlg::OnBnClickedButton4()
{
	this->pBtn4Command->execute();
	UpdateUI();
}
