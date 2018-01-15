// Train.cpp : 实现文件
//

#include "stdafx.h"
#include "exam.h"
#include "Train.h"
#include "afxdialogex.h"
#include "Public.h"
#include "string.h"
#include "str_new.h"
#include "Cequation.h"
#include "Save.h"
#include <fstream>
#include <iostream>
using namespace std;


// CTrain 对话框

IMPLEMENT_DYNAMIC(CTrain, CDialogEx)

CTrain::CTrain(CWnd* pParent /*=NULL*/)
: CDialogEx(IDD_DIALOG_Train, pParent)
, fulim(0)
, fllim(0)
, spr(_T(""))
, inum(0)
, ic(0)
, scomp(_T(""))
, flag_add(FALSE)
, flag_minus(FALSE)
, flag_cheng(FALSE)
, flag_chu(FALSE)
{

}

CTrain::~CTrain()
{
}

void CTrain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, fulim);
	DDX_Text(pDX, IDC_EDIT4, fllim);
	DDX_Text(pDX, IDC_EDIT1, spr);

	DDX_Text(pDX, IDC_EDIT2, inum);
	DDX_Text(pDX, IDC_EDIT8, ic);
	DDX_Text(pDX, IDC_EDIT5, scomp);
	DDX_Control(pDX, IDC_EDIT8, edit8);
	DDX_Check(pDX, IDC_CHECK1, flag_add);
	DDX_Check(pDX, IDC_CHECK2, flag_minus);
	DDX_Check(pDX, IDC_CHECK3, flag_cheng);
	DDX_Check(pDX, IDC_CHECK4, flag_chu);
}


BEGIN_MESSAGE_MAP(CTrain, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTrain::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTrain::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTrain::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CTrain::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON5, &CTrain::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT5, &CTrain::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT8, &CTrain::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT3, &CTrain::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_CHECK1, &CTrain::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTrain::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CTrain::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CTrain::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_BUTTON4, &CTrain::OnBnClickedButton4)
	ON_STN_CLICKED(IDC_STATIC000, &CTrain::OnStnClickedStatic000)
	ON_BN_CLICKED(IDC_BUTTON6, &CTrain::OnBnClickedButton6)
END_MESSAGE_MAP()


// CTrain 消息处理程序


Cequation equation;
void CTrain::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	equation.initial_set(inum, fllim, fulim);
	equation.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
	equation.inner_product();
	scomp = equation.equation;
//	equation.inner_equation(scomp);
	CPublic::num = inum - 1;
	spr = " ";
	UpdateData(FALSE);
}


void CTrain::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	equation.input_error_result(ic);
	float ok = equation.output_ok(1);
	str_new str;
	if (ok == ic)
	{
		equation.set_temp(1);
		str.s_new(ok);
		spr = "正确答案是:";
		spr += str.s;
		spr += "\r\n";
		spr += "计算正确!";
	}
	else
	{
		//	CPublic::flag += 1;
		equation.set_temp(0);
		str.s_new(ok);
		spr = "正确答案是:";
		spr += str.s;
		spr += "\r\n";
		spr += "计算错误!\r\n";
	}
	UpdateData(FALSE);
}


void CTrain::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CPublic::num -= 1;
//	CString str(" ");
	if (CPublic::num >= 0)
	{
		UpdateData(TRUE);
		equation.initial_set(inum, fllim, fulim);
		equation.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
		equation.inner_product();
		scomp = equation.equation;
//		equation.inner_equation(scomp);
		ic = 0;
		UpdateData(FALSE);
//		edit8.SetWindowTextW(str);
	}
	else
	{
		scomp = " ";
		ic = 0;
		float okr = equation.output_ok(0);
		str_new str1;
		str1.s_new(okr);
		spr = "正确率为:";
		spr += str1.s;
		spr += "%\r\n";
		spr += "\r\n";
		spr += "本次训练结束!\r\n";
//		inum = 0;
//		fllim = 0.0;
//		fulim = 0.0;
		CPublic::num = 0;
		UpdateData(FALSE);
//		edit8.SetWindowTextW(str);
	}
}


void CTrain::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CTrain::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CTrain::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
}

void CTrain::OnBnClickedCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
}

void CTrain::OnBnClickedCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
}

void CTrain::OnBnClickedCheck4()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	/*以下程序功能为将CString类的路径转换为(const char*)*/
	UpdateData(TRUE);
	int nLength = spr.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, spr, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, spr, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // 如果创建成功
		fout << "共有" << inum << "道题目" << endl;
		fout << "正确率为" << equation.okr << "%"<<endl;
		fout << "题目号" << "   题目" << "   用户答案" << "   正确答案" << "   是否正确"<<endl;

		for (int i = 0; i < inum; i++)
		{
			if (*(equation.temp + i))
			{
				/*输出题目号*/
				fout <<"  ";
				fout << i + 1 <<"      ";
				/*输出题目*/
				fout << *(equation.num1 - inum + i) <<" ";
				fout << *(equation.oper - inum + i) <<" ";
				fout << *(equation.num2 - inum + i) << "     ";
				/*输出用户答案*/
				fout << *(equation.error_result - inum + i) << "       ";
				/*输出正确答案*/
				fout << *(equation.ok_result - inum + i) << "       ";
				/*输出每道题的正误*/
				fout << "正确" << endl << endl;
			}
			else
			{
				fout << "  ";
				fout << i + 1 << "      ";;
				fout << *(equation.num1 - inum + i) <<" ";
				fout << *(equation.oper - inum + i) <<" ";
				fout << *(equation.num2 - inum + i) << "     ";
				fout << *(equation.error_result - inum + i) << "       ";
				fout << *(equation.ok_result - inum + i) << "       ";
				fout << "错误" << endl << endl;
			}
		}
		fout.close(); // 执行完操作后关闭文件句
	}
	spr = "文件已成功保存";
	spr += "\r\n";
	spr += "若重新做题，请首先初始化参数";
	spr += "\r\n";
	spr += "若退出，请单击“回到首页”按钮";
	UpdateData(FALSE);

}


void CTrain::OnStnClickedStatic000()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CTrain::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		spr = dlg.strPath;
		UpdateData(FALSE);
	}
}
