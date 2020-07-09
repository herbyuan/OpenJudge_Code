#include <iostream>
#include <iomanip>

using namespace std;
int func1()
{
	int a, b, c;
	a = 0; b = 1;
	for(int i=1;;i++)
	{
		c = (a + b) % 10000;
		a = b;
		b = c;
		if (a == 0 && b == 1)
		{
			return i;
		}
	}
}
int func(long long i)
{
	int a, b, c;
	a = 0; b = 1;
	
	if (i == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	else if (i == 1)
	{
		cout << "1" << endl;
		return 0;
	}
	else
	{
		for (long long j = 2; j <= i; j++)
		{
			c = (a + b) % 10000;
			a = b;
			b = c;
		}
		cout << c << endl;
		return 0;
	}
}

int main()
{
	long long i;
	int x;
	x = func1();
	while (1)
	{
		cin >> i;
		if (i == -1) return 0;
		else func(i % x);
	}
}

