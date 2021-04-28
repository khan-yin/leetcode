#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

//A>B
bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size()!=B.size()) return A.size()>B.size();

    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]!=B[i])
            return A[i]>B[i];
    }
    return true;
}

// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t=0; //借位
    for(int i=0;i<A.size();i++)
    {
        // C[i] = A[i] - B[i] - t >=0? (A[i] - B[i] - t):(A[i] - B[i] - t + 10);
        t=A[i]-t;
        if(i<B.size()) t-=B[i];
        // t>=0说明够减 取t t<0则说明不够减则需要向上借位，相当于+10
        C.push_back((t+10)%10);
        //不够减更新借位，够减则借位变为0
        if(t<0) t=1;
        else t=0;
    }
    //去除前导0
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    string a,b;
    vector<int> A,B,C;
    cin>>a>>b;

    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    
    if(cmp(A,B))
    {
        C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    else
    {
        C=sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
    
    return 0;
}