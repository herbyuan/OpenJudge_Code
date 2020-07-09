#include <iostream>
#include <iomanip>
using namespace std;

int M[4];

void MultMatrix(int A[4], int B[4])
{
	M[0] = (A[0] * B[0] + A[1] * B[2]) % 10000;
	M[1] = (A[0] * B[1] + A[1] * B[3]) % 10000;
	M[2] = (A[2] * B[0] + A[3] * B[2]) % 10000;
	M[3] = (A[2] * B[1] + A[3] * B[3]) % 10000;
}

void func(long long n)
{
	int base[4] = { 1,1,1,0 };
	if (n == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			M[i] = base[i];
		}
	}
	int N[4];
	if (n == 2)
	{
		MultMatrix(base, base);
	}
	else if (n % 2 == 0)
	{
		func(n / 2);
		for (int i = 0; i < 4; i++)
		{
			N[i] = M[i];
		}
		MultMatrix(N, N);
	}
	else if (n % 2 == 1)
	{
		func(n - 1);
		for (int i = 0; i < 4; i++)
		{
			N[i] = M[i];
		}
		MultMatrix(N, base);
	}
}

int main()
{
	long long i;
	while (1)
	{
		cin >> i;
		if (i == -1) return 0;
		else if (i == 0) cout << "0" << endl;
		else if (i == 1) cout << "1" << endl;
		else if (i == 2) cout << "1" << endl;
		else
		{
			func(i - 1);
			cout << M[0] << endl;
		}
	}
}
