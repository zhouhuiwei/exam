#pragma once


// CPrint 对话框

class CPrint : public CDialogEx
{
	DECLARE_DYNAMIC(CPrint)

public:
	CPrint(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPrint();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Print };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString str;
	int inum;
	float fllim;
	float fulim;
	afx_msg void OnBnClickedOk2();
	BOOL flag_add;
	BOOL flag_minus;
	BOOL flag_cheng;
	BOOL flag_chu;
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnEnUpdateEdit2();
	afx_msg void OnEnKillfocusEdit4();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnBnKillfocusCheck1();
	afx_msg void OnBnKillfocusCheck2();
	afx_msg void OnBnKillfocusCheck3();
	afx_msg void OnBnKillfocusCheck4();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedOk5();
};
