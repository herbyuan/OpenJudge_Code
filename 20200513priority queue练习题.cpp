#include <iostream>
#include <set>
#include <cmath>
using namespace std;
bool isPrime(int k)
{
	for (int i = 2; i <= sqrt(k); i++)
	{
		if (k % i == 0)
			return false;
	}
	return true;
}
class MyCompare
{
public:
    bool operator ()(const int &a, const int &b)
    {
        int pa = 0;
        int pb = 0;
        for (int i = 2; i <= sqrt(a); ++i)
        {
            if (a % i == 0)
            {
                if (isPrime(i))
                {
                    pa++;
                }
                if (i * i != a && isPrime(a/i))
                {
                	pa++;
                }
            }
        }
        for (int i = 2; i <= sqrt(b); ++i)
        {
            if (b % i == 0)
            {
                if (isPrime(i))
                {
                    pb++;
                }
                if (i * i != b && isPrime(b/i))
                {
                	pb++;
                }
            }
        }
        if (pa == pb)
        {
        	return (a < b);
        }
        else
        	return (pa < pb);
    }
};
int main()
{

    int n;
    int t;
    cin >> n;
    set<int,MyCompare> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            scanf("%d", &t);
            q.insert(t);
        }
	printf("%d %d\n", *(q.rbegin()),*(q.begin()));
	q.erase(*(q.begin()));
	q.erase(*(q.rbegin()));
    }
    return 0;
}
