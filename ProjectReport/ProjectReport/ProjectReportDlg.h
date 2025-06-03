
// ProjectReportDlg.h : header file
//

#pragma once
#include "ProjectListCtrl.h"
#include "sqlite3.h"

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
	//int createDB(const char* s);
	//int createTable(const char* s);
	////static int insertData(const char* dbName, const char* id, const char* name, const char* type, const char* status)
	//int insertData(const char* s, const char* i, const char* n, const char* t, const char* st);

protected:
	sqlite3* m_db; // Database connection

	BOOL OpenDatabase();
	void CloseDatabase();
	BOOL CreateProjectTable();
	BOOL InsertProject(const CString& id, const CString& name, const CString& type, const CString& status);

	void OnDestroy();

};
