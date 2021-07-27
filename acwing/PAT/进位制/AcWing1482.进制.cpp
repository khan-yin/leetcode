#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;


LL get(char c)
{
    if(c<='9') return c-'0';
    else return c-'a' + 10;
}

LL getnum(string a,LL r)
{
    LL res=0;
    for(int i=0;i<a.size();i++)
    {
        if ((double)res * r + get(a[i]) > 1e16) return 1e18;
        res = res * r + get(a[i]);
    }
    return res;
}


int main()
{
    string N1,N2;
    int tag, radix;//默认tag=1
    cin>>N1>>N2>>tag>>radix;
    if(tag==2) swap(N1,N2);
    LL target = getnum(N1,radix);
    
    //范围太大通过二分来查找
    LL l = 0, r = max(target + 1,36ll);
    for (auto c : N2) l = max(l, (LL)get(c) + 1);
    while(l<r)
    {
        LL mid = l + r >> 1;
        if(getnum(N2,mid)>=target) r = mid;
        else l = mid+1;
    }
    
    if (getnum(N2, r) != target) puts("Impossible");
    else cout << r << endl;
    
    
    return 0;
}