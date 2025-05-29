// LogIN_Page.cpp : implementation file
//

#include "pch.h"
#include "ProjectReport.h"
#include "afxdialogex.h"
#include "LogIN_Page.h"


// LogIN_Page dialog

IMPLEMENT_DYNAMIC(LogIN_Page, CDialogEx)

LogIN_Page::LogIN_Page(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LogIn, pParent)
	, m_Password(_T(""))
{

}

LogIN_Page::~LogIN_Page()
{
}

void LogIN_Page::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Password, m_Password);
}


BEGIN_MESSAGE_MAP(LogIN_Page, CDialogEx)
	ON_BN_CLICKED(IDOK, &LogIN_Page::OnBnClickedOk)
END_MESSAGE_MAP()


// LogIN_Page message handlers


void LogIN_Page::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_Password == "lodoxradiation")
	{
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(_T("Invalid Password"), _T("Error"), MB_ICONERROR);
	}
	//CDialogEx::OnOK();
}
