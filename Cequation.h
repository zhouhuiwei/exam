#pragma once
class Cequation
{
private:
	int total;//题目总数量
	float lower; float upper;//数据运算范围
	int flag_add ;
	int flag_minus;
	int flag_cheng;
	int flag_chu;
public:
	CString equation;
	int* num1 = new int[total+1];
	char* oper = new char[total+1];
	int* num2 = new int[total+1];//运算数1,符号，运算数2
	int* ok_result = new int[total + 1];//题目正确运算结果
	int* error_result = new int[total+1];//用户的结果
	int *temp = new int[total + 1];//记录每个题目正确与否
	int okr;//记录正确率

public:
	Cequation();
	~Cequation();
public:
	void initial_set(int t, float l, float u);//参数值初始化
	void input_error_result(int e);//记录用户的答案
	void inner_product();//内部产生题目字符串
//	void inner_equation(CString s);//记录系统生成的题目
	float output_ok(int p);//用于输出正确结果和最终的正确率
	void set_temp(int t);//记录每道题目的正误
	void roomdelete();//删除NEW的空间
	void getflag(bool x,bool y,bool z,bool t);//传回界面上用户设置的参数
//	void shanchu();
};

