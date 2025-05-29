#pragma once
#include "afxdialogex.h"


// LogingDlg dialog

class LogingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogingDlg)

public:
	LogingDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LogingDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LogingDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
