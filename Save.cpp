// Save.cpp : 实现文件
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


// CSave 对话框

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


// CSave 消息处理程序


void CSave::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	/*以下程序功能为设置编辑框的字体*/
	CString s("宋体");
	CFont font;
	font.CreatePointFont(200, s);
	GetDlgItem(IDC_EDIT2)->SetFont(&font);
	/*以下程序功能为打开文件夹对话框，获取文件夹路径*/
	CString title;
	title = "浏览文件夹";
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSave::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	/*以下程序功能为将CString类的路径转换为(const char*)*/
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
	//if (fout) { // 如果创建成功
		//fout << "加油，金鑫" << endl; // 使用与cout同样的方式进行写入
		//fout.close(); // 执行完操作后关闭文件句
	//}
	CDialog::OnOK();
}
