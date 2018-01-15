#include "stdafx.h"
#include "Cequation.h"
#include "time.h"
#include "str_new.h"
#include "string.h"


Cequation::Cequation()
{
	 flag_add=0;
	 flag_minus=0;
	 flag_cheng=0;
	 flag_chu=0;
	 /*切记，空指针要初始化，不然delete空指针会报错*/
	 if (num1 == NULL)
	 {
		 *num1 = 1;
	 }
	 if (num2 == NULL)
	 {
		 *num2 = 1;
	 }
	 if (oper == NULL)
	 {
		 *oper = '+';
	 }
	 if (ok_result == NULL)
	 {
		 *ok_result = 2;
	 }
	 if (error_result == NULL)
	 {
		 *error_result = 2;
	 }
	 if (temp == NULL)
	 {
		 *temp= 1;
	 }
}


Cequation::~Cequation()
{
	roomdelete();
}

void Cequation::initial_set(int t, float l, float u)
{
	total = t;
	lower = l;
	upper = u;
}

void Cequation::input_error_result(int e)
{
	*error_result = e;
	error_result++;
}

void Cequation::inner_product()
{
	int n = flag_add + flag_minus + flag_cheng + flag_chu;
	int *f = new int[n];
	int flag[4];
	flag[0] = flag_add;
	flag[1] = flag_minus;
	flag[2] = flag_cheng;
	flag[3] = flag_chu;
	int j = 0;
	for (int i = 0; i < 4;i++)
	{
		if (flag[i] == 1)
		{
			*(f + j) = i + 1;
			j++;
		}
		else
			j = j;
	}
	srand((unsigned)time(NULL)*10);
	int a = lower + (upper - lower)*rand() / (RAND_MAX + 1.0);
	int b = lower + (upper - lower)*rand() / (RAND_MAX + 1.0);
	int sig =(n*rand() / (RAND_MAX + 1.0)); 
	*num1 = a;
	*num2 = b;
	num1++;
	num2++;


	str_new str;//转化字符串
	str.s_new(a);
	equation = "( ";
	equation += str.s;

	int ssig = *(f + sig);
	if (ssig == 1)
	{
		*ok_result = a + b;
		ok_result++;
		equation += " )    +    ( ";
		*oper = '+';
		oper++;
	}
	else if (ssig == 2)
	{
		*ok_result = a - b;
		ok_result++;
		equation += " )    -    ( ";
		*oper = '-';
		oper++;
	}
	else if (ssig == 3)
	{
		*ok_result = a * b;
		ok_result++;
		equation += " )    ×    ( ";
		*oper = '*';
		oper++;
	}
	else if (ssig == 4)
	{
		if (b == 0)
			b = 1;
		*ok_result = a / b;
		ok_result++;
		equation += " )    ÷    ( ";
		*oper = '/';
		oper++;
		
	}
	str.s_new(b);
	equation += str.s;
	equation += " )";

	delete []f;

}
float Cequation::output_ok(int p)
{
	p = p;
	if (p)
		return *(ok_result - 1);
	else
	{
		int temp_total = 0;
		for (int i = 0; i < total; i++)
		{
			temp--;
			temp_total += *temp;
		}
		okr = temp_total * 100 / total;
		return okr;
	}
}
void Cequation::set_temp(int t)
{
	*temp = t;
	temp++;
}
void Cequation::getflag(bool x, bool y, bool z, bool t)
{
	if (x == TRUE)
	    flag_add = 1;
	if (y == TRUE)
		flag_minus = 1;
	if (z == TRUE)
		flag_cheng = 1;
	if (t == TRUE)
		flag_chu = 1;
}
//void Cequation::inner_equation(CString s)
//{
//	*equ = s;
//	equ++;
//}
//void Cequation::shanchu()
//{
	//delete [] num1;
	//delete [] oper;
	//delete [] num2;
	//delete [] error_result;
	//delete [] ok_result;
	//delete [] temp;
//}
void Cequation::roomdelete()
{
//	delete[] num1;
//	delete[] oper;
//	delete[] num2;
//	delete[] error_result;
//	delete[] ok_result;
// 	delete[] temp;
}