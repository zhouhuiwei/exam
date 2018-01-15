#pragma once
#include "afxwin.h"


// CTrain 对话框

class CTrain : public CDialogEx
{
	DECLARE_DYNAMIC(CTrain)

public:
	CTrain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTrain();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Train };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();

	float fulim;
	float fllim;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString spr;
	
	int inum;
	afx_msg void OnBnClickedButton3();
	int ic;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedButton5();
	CString scomp;
	afx_msg void OnEnChangeEdit5();
	CEdit edit8;
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
//	bool flag_add;
//	bool flag_minus;
//	bool flag_cheng;
//	bool flag_chu;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	BOOL flag_add;
	BOOL flag_minus;
	BOOL flag_cheng;
	BOOL flag_chu;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnStnClickedStatic000();
	afx_msg void OnBnClickedButton6();
};
