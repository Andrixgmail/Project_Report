#pragma once


// ProjectListCtrl

class ProjectListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(ProjectListCtrl)

public:
	ProjectListCtrl();
	virtual ~ProjectListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void Init();
	void AddProject(CString strProjectID, CString strProjectName, CString strProjectType, CString strProjectStatus, int nImageIndex);
};


