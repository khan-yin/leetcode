#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A,int &b)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        t=A[i]*b+t;
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    return C;
}
int main()
{
    string a;
    int b;
    cin>>a>>b;
    vector<int> A,C;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    //特判b等于0，否则会出现前导0，这是最快的修改办法
    if(!b)
        cout<<0<<endl;
    else
    {
        C=mul(A,b);
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    
    return 0;
}