// Save.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exam.h"
#include "Save.h"
#include "afxdialogex.h"
#include "shlobj.h"
#include "targetver.h"
#include "string.h"
#include <fstream>
#include <iostream>
using namespace std;


// CSave �Ի���

IMPLEMENT_DYNAMIC(CSave, CDialog)

CSave::CSave(CWnd* pParent /*=NULL*/)
	: CDialog(CSave::IDD, pParent)
	, strPath(_T(""))
	, name(_T(""))
{

}

CSave::~CSave()
{
}

void CSave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, str);
	DDX_Text(pDX, IDC_EDIT2, strPath);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(CSave, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CSave::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CSave::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CSave::OnBnClickedOk)
END_MESSAGE_MAP()


// CSave ��Ϣ�������


void CSave::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	/*���³�����Ϊ���ñ༭�������*/
	CString s("����");
	CFont font;
	font.CreatePointFont(200, s);
	GetDlgItem(IDC_EDIT2)->SetFont(&font);
	/*���³�����Ϊ���ļ��жԻ��򣬻�ȡ�ļ���·��*/
	CString title;
	title = "����ļ���";
	CString error;
	error = "Select Directory error";
	BROWSEINFO bInfo;
	LPITEMIDLIST pidl;
	ZeroMemory((PVOID)&bInfo, sizeof (BROWSEINFO));

	bInfo.hwndOwner = this->m_hWnd;
	bInfo.pszDisplayName = strPath.GetBuffer(MAX_PATH);
	bInfo.lpszTitle = title;
	bInfo.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
	bInfo.lpfn = NULL;
	bInfo.lParam = 0;

	pidl = SHBrowseForFolder(&bInfo);

	if (pidl == NULL)
	{
		AfxMessageBox(error);
		return;
	}
	SHGetPathFromIDList(pidl, strPath.GetBuffer(MAX_PATH));
	strPath.ReleaseBuffer();
	UpdateData(FALSE);
}


void CSave::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CSave::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*���³�����Ϊ��CString���·��ת��Ϊ(const char*)*/
	UpdateData(TRUE);
	CString gang;
	gang = "\\";
	strPath += gang;
	
	strPath += name;
	CString houzhui;
		houzhui = ".txt";
		strPath += houzhui;
		UpdateData(FALSE);
	//int nLength = strPath.GetLength();
	//int nBytes = WideCharToMultiByte(CP_ACP, 0, strPath, nLength, NULL, 0, NULL, NULL);
//	char *VoicePath = new char[nBytes + 1];
	//memset(VoicePath, 0, nLength + 1);
	//WideCharToMultiByte(CP_OEMCP, 0, strPath, nLength, VoicePath, nBytes, NULL, NULL);
	//VoicePath[nBytes] = 0;


	//ofstream fout(VoicePath);
	//if (fout) { // ��������ɹ�
		//fout << "���ͣ�����" << endl; // ʹ����coutͬ���ķ�ʽ����д��
		//fout.close(); // ִ���������ر��ļ���
	//}
	CDialog::OnOK();
}
