#pragma once
class Cequation
{
private:
	int total;//��Ŀ������
	float lower; float upper;//�������㷶Χ
	int flag_add ;
	int flag_minus;
	int flag_cheng;
	int flag_chu;
public:
	CString equation;
	int* num1 = new int[total+1];
	char* oper = new char[total+1];
	int* num2 = new int[total+1];//������1,���ţ�������2
	int* ok_result = new int[total + 1];//��Ŀ��ȷ������
	int* error_result = new int[total+1];//�û��Ľ��
	int *temp = new int[total + 1];//��¼ÿ����Ŀ��ȷ���
	int okr;//��¼��ȷ��

public:
	Cequation();
	~Cequation();
public:
	void initial_set(int t, float l, float u);//����ֵ��ʼ��
	void input_error_result(int e);//��¼�û��Ĵ�
	void inner_product();//�ڲ�������Ŀ�ַ���
//	void inner_equation(CString s);//��¼ϵͳ���ɵ���Ŀ
	float output_ok(int p);//���������ȷ��������յ���ȷ��
	void set_temp(int t);//��¼ÿ����Ŀ������
	void roomdelete();//ɾ��NEW�Ŀռ�
	void getflag(bool x,bool y,bool z,bool t);//���ؽ������û����õĲ���
//	void shanchu();
};

