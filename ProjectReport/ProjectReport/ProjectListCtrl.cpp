// ProjectListCtrl.cpp : implementation file
//

#include "pch.h"
#include "ProjectReport.h"
#include "ProjectListCtrl.h"


// ProjectListCtrl

IMPLEMENT_DYNAMIC(ProjectListCtrl, CListCtrl)

ProjectListCtrl::ProjectListCtrl()
{

}

ProjectListCtrl::~ProjectListCtrl()
{
}


BEGIN_MESSAGE_MAP(ProjectListCtrl, CListCtrl)
END_MESSAGE_MAP()



// ProjectListCtrl message handlers




void ProjectListCtrl::Init()
{
    // TODO: Add your implementation code here.
	ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL | LVS_NOSORTHEADER);
	SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);

	// Insert columns
	InsertColumn(0, _T("Project ID"), LVCFMT_LEFT, 200);
	InsertColumn(1, _T("Project Name"), LVCFMT_LEFT, 200);
	InsertColumn(2, _T("Project Type"), LVCFMT_LEFT, 200);
	InsertColumn(3, _T("Project Status"), LVCFMT_LEFT, 200);
}


void ProjectListCtrl::AddProject(CString strProjectID, CString strProjectName, CString strProjectType, CString strProjectStatus, int nImageIndex)
{
	// TODO: Add your implementation code here.
	int nItem = InsertItem(GetItemCount(), _T(""), nImageIndex);
	LVITEM item = { 0 };

	item.iItem = nItem;
	item.iSubItem = 0;
	item.mask = LVIF_TEXT;
	item.pszText = strProjectID.GetBuffer();
	SetItem(&item);

	item.iSubItem = 1;
	item.pszText = strProjectName.GetBuffer();
	SetItem(&item);

	item.iSubItem = 2;
	item.pszText = strProjectType.GetBuffer();
	SetItem(&item);

	item.iSubItem = 3;
	item.pszText = strProjectStatus.GetBuffer();
	SetItem(&item);
}
