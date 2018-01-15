#include "stdafx.h"
#include "str_new.h"


str_new::str_new()
{
}


str_new::~str_new()
{
}
void str_new::s_new(double var)
{
	char double_s[30];
	char *p = double_s;
	_gcvt_s(double_s, 30, var, 8);
	*p = *double_s;
	CString str;
	for (int i = 0; i < 30; i++)
	if (*p == '\0')
		break;
	else
	{
		str += *p;
		p++;
	}
	s = str;

};
