
#include <iostream>
#include <cstring>
using namespace std;
bool runnian(int year)
{
	bool leap;
	if (year % 4 == 0)         //能否被4整除
	{
		if (year % 100 == 0)    //能否被100整除
		{
			if (year % 400 == 0)   leap = true;  //能否被400整除，判断闰年
			else leap = false;              //判断闰年
		}
		else leap = true;
	}
	else leap = false;
	return leap;    //返回结果

}
int year(char a[])
{
	int y;
	int x1, x2;
	for (int i = 0; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x1 = i;
			break;
		}
	}
	for (int i = x1 + 1; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x2 = i;
			break;
		}
	}
	if (x1 == 4)
		y = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
	else if (x2 - x1 == 5)
		y = (a[x1 + 1] - '0') * 1000 + (a[x1 + 2] - '0') * 100 + (a[x1 + 3] - '0') * 10 + (a[x1 + 4] - '0');
	else 
		y = (a[x2 + 1] - '0') * 1000 + (a[x2 + 2] - '0') * 100 + (a[x2 + 3] - '0') * 10 + (a[x2 + 4] - '0');
	return y;
}
int month(char a[])
{
	int x1 = 0, x2 = 0;
	for (int i = 0; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x1 = i;
			break;
		}
	}
	for (int i = x1 + 1; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x2 = i;
			break;
		}
	}
	char t[4] = { 0 };
	if (x1 == 3)
		for (int i = 0; i < 3; i++)
		{
			t[i] = a[i];
		}
	else if (x2 - x1 == 4)
		for (int i = 0; i < 3; i++)
		{
			t[i] = a[x1 + 1+i];
		}
	else
		for (int i = 0; i < 3; i++)
		{
			t[i] = a[i+ x2 + 1];
		}
	if (strcmp(t, "Jan") == 0) return 1;
	if (strcmp(t, "Feb") == 0) return 2;
	if (strcmp(t, "Mar") == 0) return 3;
	if (strcmp(t, "Apr") == 0) return 4;
	if (strcmp(t, "May") == 0) return 5;
	if (strcmp(t, "Jun") == 0) return 6;
	if (strcmp(t, "Jul") == 0) return 7;
	if (strcmp(t, "Aug") == 0) return 8;
	if (strcmp(t, "Sep") == 0) return 9;
	if (strcmp(t, "Oct") == 0) return 10;
	if (strcmp(t, "Nov") == 0) return 11;
	if (strcmp(t, "Dec") == 0) return 12;
}
int day(char a[])
{
	int d;
	int x1, x2;
	for (int i = 0; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x1 = i;
			break;
		}
	}
	for (int i = x1 + 1; i < 20; i++)
	{
		if (a[i] == '-')
		{
			x2 = i;
			break;
		}
	}
	if (x1 == 2)
		d = (a[0] - '0') * 10 + (a[1] - '0');
	else if (x2 - x1 == 3)
		d = (a[x1 + 1] - '0') * 10 + a[x1 + 2] - '0';
	else
		d = (a[x2 + 1] - '0') * 10 + a[x2 + 2] - '0';
	return d;
}
int tianshu(int y, int m, int d)
{
	long s = 0;
	for (int i = 1900; i < y; i++)
	{
		if (runnian(i)) s += 366;
		else s += 365;
	}
	for (int i = 1; i < m; i++)
	{
		switch (i)
		{
		case 1:s += 31; break;
		case 2:if (runnian(y))s += 29;
			   else s += 28;
			break;
		case 3:s += 31; break;
		case 4:s += 30; break;
		case 5:s += 31; break;
		case 6:s += 30; break;
		case 7:s += 31; break;
		case 8:s += 31; break;
		case 9:s += 30; break;
		case 10:s += 31; break;
		case 11:s += 30; break;
		case 12:s += 31; break;
		}
	}
	s += d;
	return s;
}
int main()
{
	char a[20];
	int y, m, d;
	int n, xingqi;
	long s;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		s = 0;
		for (int i = 0; i < 20; i++)
			a[i] = 0;
		cin >> a;
		y = year(a);
		m = month(a);
		d = day(a);
		s = tianshu(y, m, d);
		xingqi = s % 7;
		switch (xingqi)
		{
		case 1:cout << "Mon." << endl; break;
		case 2:cout << "Tue." << endl; break;
		case 3:cout << "Wed." << endl; break;
		case 4:cout << "Thu." << endl; break;
		case 5:cout << "Fri." << endl; break;
		case 6:cout << "Sat." << endl; break;
		case 0:cout << "Sun." << endl; break;
		}
	}
}

