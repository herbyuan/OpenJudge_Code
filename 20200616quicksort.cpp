#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
void Quicksort(int a[], int s, int e)
{
    if (s >= e)
        return;
    int k = a[s];
    int i = s, j = e;
    while(i != j)
    {
        while(j > i && a[j] >= k)
            j--;
        swap(a[i], a[j]);
        while(i < j && a[i] <= k)
            i++;
        swap(a[i], a[j]);
    }
    Quicksort(a, s, i - 1);
    Quicksort(a, i + 1, e);
}
int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
int b[10];
int main()
{
    int size = sizeof(a) / sizeof(int);
    Quicksort(a, 0, size - 1);

    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}