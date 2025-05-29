
// ProjectReportDlg.h : header file
//

#pragma once
#include "ProjectListCtrl.h"

// CProjectReportDlg dialog
class CProjectReportDlg : public CDialogEx
{
// Construction
public:
	CProjectReportDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTREPORT_DIALOG };
#endif

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
	DECLARE_MESSAGE_MAP()
public:
	ProjectListCtrl m_crtProjectList;
	afx_msg void OnEnChangeEdit1();
	CString m_ID;
	CString m_Name;
	CString m_Type;
	CString m_Status;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonLogin();
	CButton btn_LogIN;
	CButton btn_ADD;
	CButton btn_LogOut;
	afx_msg void OnBnClickedButtonLogout();
};
