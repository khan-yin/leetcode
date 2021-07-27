// PAT甲级真题1058
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int a,b,c,d,e,f;
    scanf("%d.%d.%d %d.%d.%d", &a,&b,&c,&d,&e,&f);
    a += d, b += e, c +=f;
    b += c/29, c %= 29;
    a += b/17, b %= 17;
    printf("%d.%d.%d",a,b,c);
    
    
    return 0;
}


// =========小题大做了=========
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> change(string a)
{
    vector<LL> res;
    for(int i=0;i<a.size();i++)
    {
        LL t=0;
        int j = i;
        while (j<a.size()&&a[j]!='.') t = t*10 + (a[j++]-'0');
        res.push_back(t);
        i = j;
    }
    return res;
}

LL inter[3] ={1,17,29};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<LL> t1,t2;
    
    t1 = change(s1);
    t2 = change(s2);
    vector<LL> res(3);
    LL t = 0;
    for(int i=2;i>=0;i--)
    {
        LL s = (t1[i] + t2[i] + t);
        res[i] = s % inter[i];
        t = s / inter[i];
    }
    if(t) res[0]=t;
    
    cout<<res[0]<<'.'<<res[1]<<'.'<<res[2];
    
    return 0;
}