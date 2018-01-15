// Test.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exam.h"
#include "Test.h"
#include "afxdialogex.h"
#include "Cequation.h"
#include "Public.h"
#include "str_new.h"
#include "string.h"
#include "Save.h"
#include "str_new.h"
#include <fstream>
#include <iostream>
using namespace std;


// CTest �Ի���

IMPLEMENT_DYNAMIC(CTest, CDialogEx)

CTest::CTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest::IDD, pParent)
	, flag_add(FALSE)
	, flag_minus(FALSE)
	, flag_chu(FALSE)
	, flag_cheng(FALSE)
	, spr(_T(""))
	, inum(0)
	, fulim(0)
	, fllim(0)
	, scomp(_T(""))
	, ic(0)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, flag_add);
	DDX_Check(pDX, IDC_CHECK2, flag_minus);
	DDX_Check(pDX, IDC_CHECK4, flag_chu);
	DDX_Check(pDX, IDC_CHECK3, flag_cheng);
	DDX_Text(pDX, IDC_EDIT1, spr);
	DDX_Text(pDX, IDC_EDIT2, inum);
	DDX_Text(pDX, IDC_EDIT3, fulim);
	DDX_Text(pDX, IDC_EDIT4, fllim);
	DDX_Text(pDX, IDC_EDIT5, scomp);
	DDX_Text(pDX, IDC_EDIT8, ic);
	DDX_Control(pDX, IDC_EDIT8, edit8);
}


BEGIN_MESSAGE_MAP(CTest, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &CTest::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &CTest::OnBnClickedButton5)
	ON_BN_CLICKED(IDOK, &CTest::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CTest::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_BUTTON2, &CTest::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTest::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTest::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CTest::OnBnClickedButton7)
END_MESSAGE_MAP()


// CTest ��Ϣ�������


void CTest::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTest::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CTest::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

Cequation equat;
void CTest::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	equat.initial_set(inum, fllim, fulim);
	equat.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
	equat.inner_product();
	scomp = equat.equation;
	CPublic::num = inum - 1;
	spr = " ";
	UpdateData(FALSE);
}


//void CTest::OnBnClickedButton2()
//{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	UpdateData(TRUE);
//	str_new str;
//	equat.input_error_result(ic);
//	float ok = equat.output_ok(1);
//	if (ok == ic)
//	{
//		equat.set_temp(1);
//		str.s_new(ok);
//		spr = "��ȷ����:";
//		spr += str.s;
//		spr += "\r\n";
//		spr += "������ȷ!";
//	}
//	else
//	{
		//	CPublic::flag += 1;
//		equat.set_temp(0);
//		str.s_new(ok);
//		spr = "��ȷ����:";
//		spr += str.s;
//		spr += "\r\n";
//		spr += "�������!\r\n";
//	}
//	UpdateData(FALSE);
//}


void CTest::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	equat.input_error_result(ic);
	float ok = equat.output_ok(1);
	if (ok == ic)
		equat.set_temp(1);
	else
		equat.set_temp(0);
	CPublic::num -= 1;
//	CString str(" ");
	if (CPublic::num >= 0)
	{
		equat.initial_set(inum, fllim, fulim);
		equat.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
		equat.inner_product();
		scomp = equat.equation;
		ic = 0;
		UpdateData(FALSE);
//		edit8.SetWindowTextW(str);
	}
	else
	{
		scomp = " ";
		float fenshu =equat.output_ok(0);
		str_new str1;
		str1.s_new(fenshu);
		spr = "100�����֣����ķ���Ϊ:";
		spr += str1.s;
		spr += "\r\n";
		spr += "\r\n";
		spr += "���ο��Խ���!\r\n";
//		inum = 0;
//		fllim = 0.0;
//		fulim = 0.0;
		ic = 0;
		CPublic::num = 0;
		UpdateData(FALSE);
//		edit8.SetWindowTextW(str);
	}
}


void CTest::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*���³�����Ϊ��CString���·��ת��Ϊ(const char*)*/
	UpdateData(TRUE);
	int nLength = spr.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, spr, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, spr, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // ��������ɹ�
		fout << "����" << inum << "����Ŀ" << endl;
		fout << "��ȷ��Ϊ" << equat.okr << "%" << endl;
		fout << "��Ŀ��" << "   ��Ŀ" << "      �û���" << "   ��ȷ��" << "   �Ƿ���ȷ" << endl;

		for (int i = 0; i < inum; i++)
		{
			if (*(equat.temp + i))
			{
				/*�����Ŀ��*/
				fout << "  ";
				fout << i + 1 << "      ";
				/*�����Ŀ*/
				fout << *(equat.num1 - inum + i) << " ";
				fout << *(equat.oper - inum + i) << " ";
				fout << *(equat.num2 - inum + i) << "       ";
				/*����û���*/
				fout << *(equat.error_result - inum + i) << "         ";
				/*�����ȷ��*/
				fout << *(equat.ok_result - inum + i) << "       ";
				/*���ÿ���������*/
				fout << "��ȷ" << endl << endl;
			}
			else
			{
				fout << "  ";
				fout << i + 1 << "      ";;
				fout << *(equat.num1 - inum + i) << " ";
				fout << *(equat.oper - inum + i) << " ";
				fout << *(equat.num2 - inum + i) << "       ";
				fout << *(equat.error_result - inum + i) << "         ";
				fout << *(equat.ok_result - inum + i) << "       ";
				fout << "����" << endl << endl;
			}
		}
		fout.close(); // ִ���������ر��ļ���
	}
	spr = "�ļ��ѳɹ�����";
	spr += "\r\n";
	spr += "���������⣬�����ȳ�ʼ������";
	spr += "\r\n";
	spr += "���˳����뵥�����ص���ҳ����ť";
	UpdateData(FALSE);
}


void CTest::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		spr = dlg.strPath;
		UpdateData(FALSE);
	}

}
