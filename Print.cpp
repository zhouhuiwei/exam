// Print.cpp : ʵ���ļ�
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


// CPrint �Ի���

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


// CPrint ��Ϣ�������


void CPrint::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*��ȡ��ʼ����*/
	UpdateData(TRUE);
	equatio.initial_set(inum, fllim, fulim);
	equatio.getflag(flag_add, flag_minus, flag_cheng, flag_chu);
	/*������Ŀ�ʹ�*/
	int num = inum;
	for (; num > 0; num--)
	{
		Sleep(1000);
		equatio.inner_product();
	}
	/***************************��ӡ���***********************************/
	/*���³�����Ϊ��CString���·��ת��Ϊ(const char*)*/
	UpdateData(TRUE);
	int nLength = str.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, str, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, str, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // ��������ɹ�
		fout << "��Ŀ��" << "   ��Ŀ" << endl;

		for (int i = 0; i < inum; i++)
		{
				/*�����Ŀ��*/
				fout << "  ";
				fout << i + 1 << "      ";
				/*�����Ŀ*/
				fout << *(equatio.num1 - inum + i) << " ";
				fout << *(equatio.oper - inum + i) << " ";
				fout << *(equatio.num2 - inum + i) << "     "<<endl;
				/*�����ȷ��*/
//				fout << *(equation.ok_result - inum + i) << "       "<<endl;

		}
		fout.close(); // ִ���������ر��ļ���
	}

	str = "�����ѳɹ���ӡ";
	UpdateData(FALSE);
}


void CPrint::OnEnKillfocusEdit2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnEnKillfocusEdit4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnEnKillfocusEdit3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnKillfocusCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CPrint::OnBnClickedCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnClickedOk3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CPrint::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnClickedCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnClickedCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CPrint::OnBnClickedOk4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	/***************************��ӡ���***********************************/
	/*���³�����Ϊ��CString���·��ת��Ϊ(const char*)*/
	UpdateData(TRUE);
	int nLength = str.GetLength();
	int nBytes = WideCharToMultiByte(CP_ACP, 0, str, nLength, NULL, 0, NULL, NULL);
	char *VoicePath = new char[nBytes + 1];
	memset(VoicePath, 0, nLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, str, nLength, VoicePath, nBytes, NULL, NULL);
	VoicePath[nBytes] = 0;

	ofstream fout(VoicePath);
	if (fout) { // ��������ɹ�
		fout << "��Ŀ��" << "   ��" << endl;


		for (int i = 0; i < inum; i++)
		{
			/*�����Ŀ��*/
			fout << "  ";
			fout << i + 1 << "      ";
			/*�����ȷ��*/
			fout << *(equatio.ok_result - inum + i) << "       " << endl;

		}
		fout.close(); // ִ���������ر��ļ���
	}

	str = "���ѳɹ���ӡ";
	UpdateData(FALSE);
}


void CPrint::OnBnClickedOk5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSave dlg;
	if (dlg.DoModal() == IDOK)
	{
		str = dlg.strPath;
		UpdateData(FALSE);
	}
}
