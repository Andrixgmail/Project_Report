
// ProjectReportDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ProjectReport.h"
#include "ProjectReportDlg.h"
#include "afxdialogex.h"
#include "logIN_Page.h"
#include "afxdialogex.h"
#include "sqlite3.h"
#include "string"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CProjectReportDlg dialog



CProjectReportDlg::CProjectReportDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECTREPORT_DIALOG, pParent)
	, m_ID(_T(""))
	, m_Name(_T(""))
	, m_Type(_T(""))
	, m_Status(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Project, m_crtProjectList);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_Name, m_Name);
	DDX_Text(pDX, IDC_EDIT_Type, m_Type);
	DDX_Text(pDX, IDC_EDIT_Status, m_Status);
	DDX_Control(pDX, IDC_BUTTON_LOGIN, btn_LogIN);
	DDX_Control(pDX, IDC_BUTTON_ADD, btn_ADD);
	DDX_Control(pDX, IDC_BUTTON_LogOut, btn_LogOut);
}

BEGIN_MESSAGE_MAP(CProjectReportDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_EDIT1, &CProjectReportDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CProjectReportDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CProjectReportDlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_LogOut, &CProjectReportDlg::OnBnClickedButtonLogout)
END_MESSAGE_MAP()


// CProjectReportDlg message handlers

BOOL CProjectReportDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//LogIN_Page dlg;
	//dlg.DoModal();
	btn_LogIN.EnableWindow(TRUE);
	btn_LogOut.EnableWindow(FALSE);
	m_crtProjectList.EnableWindow(FALSE);
	btn_ADD.EnableWindow(FALSE);
	//m_crtProjectList.Init();
	/*m_crtProjectList.AddProject(_T("P001"), _T("Project 1"), _T("Type 1"), _T("Status 1"), 0);
	m_crtProjectList.AddProject(_T("P002"), _T("Project 2"), _T("Type 2"), _T("Status 2"), 1);
	m_crtProjectList.AddProject(_T("P003"), _T("Project 3"), _T("Type 3"), _T("Status 3"), 2);
	m_crtProjectList.AddProject(_T("P004"), _T("Project 4"), _T("Type 4"), _T("Status 4"), 3);*/
	OpenDatabase();
	CreateProjectTable();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjectReportDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjectReportDlg::OnPaint()
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
HCURSOR CProjectReportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProjectReportDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CProjectReportDlg::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
	if (m_ID.IsEmpty() || m_Name.IsEmpty() || m_Type.IsEmpty() || m_Status.IsEmpty())
	{
		AfxMessageBox(_T("Please fill in all fields"));
		return;
	}
	m_crtProjectList.AddProject(m_ID, m_Name, m_Type, m_Status, 0);
	if (!InsertProject(m_ID, m_Name, m_Type, m_Status)) // Insert the project into the database
	{
		AfxMessageBox(_T("Failed to insert project into database"));
		return;
	}

	m_ID = _T("");
	m_Name = _T("");
	m_Type = _T("");
	m_Status = _T("");
	UpdateData(FALSE);
}

void CProjectReportDlg::OnBnClickedButtonLogin()
{
	// TODO: Add your control notification handler code here
	LogIN_Page dlg;
	dlg.DoModal();
	if (dlg.m_Password == "lodoxradiation")
	{
		btn_LogIN.EnableWindow(FALSE);
		btn_LogOut.EnableWindow(TRUE);
		m_crtProjectList.EnableWindow(TRUE);
		btn_ADD.EnableWindow(TRUE);
		m_crtProjectList.Init();
	}
	else
	{
		MessageBox(_T("Invalid Password"), _T("Error"), MB_ICONERROR);
	}
}
void CProjectReportDlg::OnBnClickedButtonLogout()
{
	// TODO: Add your control notification handler code here
	btn_LogIN.EnableWindow(TRUE);
	m_crtProjectList.EnableWindow(FALSE);
	btn_ADD.EnableWindow(FALSE);
	btn_LogOut.EnableWindow(FALSE);
}

// Implement the database opening function
BOOL CProjectReportDlg::OpenDatabase()
{
	//sqlite3* m_db;
	int rc = sqlite3_open("ProjectReport.db", &m_db);

	if (rc == SQLITE_OK)
	{
		CString strMessage;
		strMessage=L"Database opened successfully:";
		AfxMessageBox(strMessage);
	}
	else
	{
		CString strError;
		strError.Format(_T("Failed to open database: %s"), std::string(sqlite3_errmsg(m_db)).c_str());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

// Implement the database closing function
void CProjectReportDlg::CloseDatabase()
{
}

// Implement the table creation function
BOOL CProjectReportDlg::CreateProjectTable()
{
	const char* sql = "CREATE TABLE IF NOT EXISTS Projects ("
		"ID TEXT PRIMARY KEY, "
		"Name TEXT NOT NULL, "
		"Type TEXT NOT NULL, "
		"Status TEXT NOT NULL);";

	char* errMsg = nullptr;
	int rc = sqlite3_exec(m_db, sql, nullptr, nullptr, &errMsg);

	if (rc != SQLITE_OK)
	{
		CString strError;
		strError.Format(_T("Failed to create table: %s"), errMsg);
		sqlite3_free(errMsg);
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}
// Implement the project insertion function
BOOL CProjectReportDlg::InsertProject(const CString& id, const CString& name, const CString& type, const CString& status)
{
	CString sql;
	sql.Format(_T("INSERT INTO Projects (ID, Name, Type, Status) VALUES ('%s', '%s', '%s', '%s');"), id, name, type, status);

	char* errMsg = nullptr;
	int rc = sqlite3_exec(m_db, CT2A(sql), nullptr, nullptr, &errMsg);

	if (rc != SQLITE_OK)
	{
		CString strError;
		strError.Format(_T("Failed to insert project: %s"), errMsg);
		sqlite3_free(errMsg);
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

// Override the OnDestroy handler to close the database when the dialog closes
void CProjectReportDlg::OnDestroy()
{
	
}

