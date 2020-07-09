#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T *t1, T *t2)
{
    T t = *t1;
    T *p = t1 + 1;
    while(p < t2)
    {
        t = t + *(p++);
    }
    return t;

}
int main()
{
    string array[4] = { "Tom", "Jack", "Mary", "John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
    cout << SumArray(a, a + 4) << endl;
    return 0;
}