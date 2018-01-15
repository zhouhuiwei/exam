// Print.cpp : 实现文件
//

#include "stdafx.h"
#include "exam.h"
#include "Print.h"
#include "afxdialogex.h"
#include "Save.h"
#include "Cequation.h"
#include <fstream>
#include <iostream>
using namespace std;
#include "windows.h"


// CPrint 对话框

IMPLEMENT_DYNAMIC(CPrint, CDialogEx)

CPrint::CPrint(CWnd* pParent /*=NULL*/)
: CDialogEx(IDD_DIALOG_Print, pParent)
, str(_T(""))
, inum(0)
, fllim(0)
, fulim(0)
, flag_add(FALSE)
, flag_minus(FALSE)
, flag_cheng(FALSE)
, flag_chu(FALSE)
{

}

CPrint::~CPrint()
{
}

void CPrint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, str);
	DDX_Text(pDX, IDC_EDIT2, inum);
	DDX_Text(pDX, IDC_EDIT4, fllim);
	DDX_Text(pDX, IDC_EDIT3, fulim);
	DDX_Check(pDX, IDC_CHECK1, flag_add);
	DDX_Check(pDX, IDC_CHECK2, flag_minus);
	DDX_Check(pDX, IDC_CHECK3, flag_cheng);
	DDX_Check(pDX, IDC_CHECK4, flag_chu);
}


BEGIN_MESSAGE_MAP(CPrint, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPrint::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CPrint::OnBnClickedOk2)
	ON_EN_KILLFOCUS(IDC_EDIT2, &CPrint::OnEnKillfocusEdit2)
//	ON_EN_UPDATE(IDC_EDIT2, &CPrint::OnEnUpdateEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT4, &CPrint::OnEnKillfocusEdit4)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CPrint::OnEnKillfocusEdit3)
	ON_BN_KILLFOCUS(IDC_CHECK1, &CPrint::OnBnKillfocusCheck1)
	ON_BN_KILLFOCUS(IDC_CHECK2, &CPrint::OnBnKillfocusCheck2)
	ON_BN_KILLFOCUS(IDC_CHECK3, &CPrint::OnBnKillfocusCheck3)
	ON_BN_KILLFOCUS(IDC_CHECK4, &CPrint::OnBnKillfocusCheck4)
	ON_EN_CHANGE(IDC_EDIT2, &CPrint::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_CHECK2, &CPrint::OnBnClickedCheck2)
	ON_BN_CLICKED(IDOK3, &CPrint::OnBnClickedOk3)
	ON_BN_CLICKED(IDC_CHECK1, &CPrint::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CPrint::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CPrint::OnBnClickedCheck4)
	ON_BN_CLICKED(IDOK4, &CPrint::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK5, &CPrint::OnBnClickedOk5)
END_MESSAGE_MAP()


// CPrint 消息处理程序


void CPrint::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		str = dlg.strPath;
		UpdateData(FALSE);
	}
}

Cequation equatio;
void CPrint::OnBnClickedOk2()
{
	// TODO:  在此添加控件通知处理程序代码
	/*获取初始参数*/
	UpdateData(TRUE);
	equatio.initial_set(inum, fllim, fulim);
	equatio.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
	/*生成题目和答案*/
	int num = inum;
	for (; num > 0; num--)
	{
		Sleep(1000);
		equatio.inner_product();
	}
	/***************************打印输出***********************************/
	/*以下程序功能为将CString类的路径转换为(const char*)*/
	UpdateData(TRUE);
	int nLength = str.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, str, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, str, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // 如果创建成功
		fout << "题目号" << "   题目" << endl;

		for (int i = 0; i < inum; i++)
		{
				/*输出题目号*/
				fout << "  ";
				fout << i + 1 << "      ";
				/*输出题目*/
				fout << *(equatio.num1 - inum + i) << " ";
				fout << *(equatio.oper - inum + i) << " ";
				fout << *(equatio.num2 - inum + i) << "     "<<endl;
				/*输出正确答案*/
//				fout << *(equation.ok_result - inum + i) << "       "<<endl;

		}
		fout.close(); // 执行完操作后关闭文件句
	}

	str = "试题已成功打印";
	UpdateData(FALSE);
}


void CPrint::OnEnKillfocusEdit2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnEnKillfocusEdit4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnEnKillfocusEdit3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CPrint::OnBnClickedCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnClickedOk3()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CPrint::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnClickedCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnClickedCheck4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPrint::OnBnClickedOk4()
{
	// TODO:  在此添加控件通知处理程序代码

	/***************************打印输出***********************************/
	/*以下程序功能为将CString类的路径转换为(const char*)*/
	UpdateData(TRUE);
	int nLength = str.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, str, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, str, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // 如果创建成功
		fout << "题目号" << "   答案" << endl;


		for (int i = 0; i < inum; i++)
		{
			/*输出题目号*/
			fout << "  ";
			fout << i + 1 << "      ";
			/*输出正确答案*/
			fout << *(equatio.ok_result - inum + i) << "       " << endl;

		}
		fout.close(); // 执行完操作后关闭文件句
	}

	str = "答案已成功打印";
	UpdateData(FALSE);
}


void CPrint::OnBnClickedOk5()
{
	// TODO:  在此添加控件通知处理程序代码
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		str = dlg.strPath;
		UpdateData(FALSE);
	}
}
