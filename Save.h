#pragma once


// CSave �Ի���

class CSave : public CDialog
{
	DECLARE_DYNAMIC(CSave)

public:
	CSave(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSave();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CString str;
	afx_msg void OnEnChangeEdit2();
	CString strPath;
	afx_msg void OnBnClickedOk();
	CString name;
};
