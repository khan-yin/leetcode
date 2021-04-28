#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// A / b = C ... r, A >= 0, b > 0
// A为大数字,则A>b，r表示余数
vector<int> div(vector<int> &A,int &b,int &r)
{
    vector<int> C;
    //除法是从高位开始的，不过为了整个加减乘除模板通用，在存储时依旧使用倒存，所以计算时需要从最高位开始访问
    for(int i=A.size();i>=0;i--)
    {
        r = (r*10+A[i]);
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    vector<int> A,C;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');

    int r=0;

    C = div(A,b,r);
    
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    printf("\n%d",r);

    return 0;
}