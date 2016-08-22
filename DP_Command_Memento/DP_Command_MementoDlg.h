#include "MyClass.h"
// DP_Command_MementoDlg.h : header file
//

#pragma once



// CDP_Command_MementoDlg dialog
class CDP_Command_MementoDlg : public CDialogEx, public Observer
{
// Construction
public:
	CDP_Command_MementoDlg(CWnd* pParent = NULL);	// standard constructor
	~CDP_Command_MementoDlg();
// Dialog Data
	enum { IDD = IDD_DP_COMMAND_MEMENTO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	DECLARE_MESSAGE_MAP()


private:
	void UpdateUI();

private:
	Player* pPlayer;
	Caretaker* pCaretaker;
	Command* pBtn1Command;
	Command* pBtn2Command;
	Command* pBtn3Command;
	Command* pBtn5Command;
public:
	virtual void Update(UINT uMsg, LPVOID pParam = NULL);

	afx_msg void OnBnClickedButton5();
};
