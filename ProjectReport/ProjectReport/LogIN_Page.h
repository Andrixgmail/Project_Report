#pragma once
#include "afxdialogex.h"


// LogIN_Page dialog

class LogIN_Page : public CDialogEx
{
	DECLARE_DYNAMIC(LogIN_Page)

public:
	LogIN_Page(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LogIN_Page();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LogIn };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Password;
	afx_msg void OnBnClickedOk();
};
