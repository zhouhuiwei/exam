#pragma once
#include "afxwin.h"


// CTest �Ի���

class CTest : public CDialogEx
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTest();

// �Ի�������
	enum { IDD = IDD_DIALOG_Test };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOk();
	BOOL flag_add;
	BOOL flag_minus;
//	BOOL cheng;
	BOOL flag_chu;
	BOOL flag_cheng;
	CString spr;
//	CString inum;
	int inum;
	float fulim;
	float fllim;
	CString scomp;
	int ic;
	CEdit edit8;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
};
