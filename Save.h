#pragma once


// CSave 对话框

class CSave : public CDialog
{
	DECLARE_DYNAMIC(CSave)

public:
	CSave(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSave();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CString str;
	afx_msg void OnEnChangeEdit2();
	CString strPath;
	afx_msg void OnBnClickedOk();
	CString name;
};
