#include <iostream>
using namespace std;
int tot, res, sta, n;
int r[2005], s[2005];
int recall(int m){
    if(m == n + 1){//若所有元素都入过栈，输出当前出栈序列
        tot++;
        cout << "Case #" << tot << ":" << endl;
        for(int i = 1; i <= res; i++){
            cout << r[i] << ' ';
        }
        for(int i = sta; i > 0; i--){
            cout << s[i] << ' ';
        }
        cout << endl;
        return 0;
    }  
    if(sta > 0){
        r[++res] = s[sta--];
        recall(m);//栈顶元素出栈
        s[++sta] = r[res--];//回溯操作
    }
    s[++sta] = m;//当前元素入栈
    recall(m + 1);
    sta--;//回溯操作
    return 0;
}
int main(){
    cin >> n;
    tot = 0;res = 0;sta = 0;
    recall(1);
    cout << "There are total " << tot << " sequences.";
    return 0;
} 