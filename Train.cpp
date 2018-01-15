// Train.cpp : ʵ���ļ�
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


// CTrain �Ի���

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


// CTrain ��Ϣ�������


Cequation equation;
void CTrain::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	equation.input_error_result(ic);
	float ok = equation.output_ok(1);
	str_new str;
	if (ok == ic)
	{
		equation.set_temp(1);
		str.s_new(ok);
		spr = "��ȷ����:";
		spr += str.s;
		spr += "\r\n";
		spr += "������ȷ!";
	}
	else
	{
		//	CPublic::flag += 1;
		equation.set_temp(0);
		str.s_new(ok);
		spr = "��ȷ����:";
		spr += str.s;
		spr += "\r\n";
		spr += "�������!\r\n";
	}
	UpdateData(FALSE);
}


void CTrain::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		spr = "��ȷ��Ϊ:";
		spr += str1.s;
		spr += "%\r\n";
		spr += "\r\n";
		spr += "����ѵ������!\r\n";
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnEnChangeEdit9()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CTrain::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnEnChangeEdit8()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CTrain::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CTrain::OnBnClickedCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CTrain::OnBnClickedCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CTrain::OnBnClickedCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnBnClickedButton4()
{
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
		fout << "��ȷ��Ϊ" << equation.okr << "%"<<endl;
		fout << "��Ŀ��" << "   ��Ŀ" << "   �û���" << "   ��ȷ��" << "   �Ƿ���ȷ"<<endl;

		for (int i = 0; i < inum; i++)
		{
			if (*(equation.temp + i))
			{
				/*�����Ŀ��*/
				fout <<"  ";
				fout << i + 1 <<"      ";
				/*�����Ŀ*/
				fout << *(equation.num1 - inum + i) <<" ";
				fout << *(equation.oper - inum + i) <<" ";
				fout << *(equation.num2 - inum + i) << "     ";
				/*����û���*/
				fout << *(equation.error_result - inum + i) << "       ";
				/*�����ȷ��*/
				fout << *(equation.ok_result - inum + i) << "       ";
				/*���ÿ���������*/
				fout << "��ȷ" << endl << endl;
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


void CTrain::OnStnClickedStatic000()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTrain::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		spr = dlg.strPath;
		UpdateData(FALSE);
	}
}
