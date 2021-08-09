// PAT甲级真题1148
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int p[N];
int n;


int check(int k,int i,int j)
{
    int t = p[k];
    //好人
    if(t>0)
    {
        if(t==i||t==j) return 1;
        else return 0;
    }
    else 
    {
        t =-t;
        // 狼人
        if(t==i || t==j) return 0;
        else return 1;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &p[i]);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int s = check(i,i,j) + check(j,i,j);
            
            if(s!=1) continue;
            
            s=0;
            for (int k = 1; k <= n; k ++ )
            {
                s+=check(k,i,j);
            }
            
            if(s!=2) continue;
            cout<<i<<" "<<j<<endl;
            return 0;
        }
    }
    
    puts("No Solution");
    return 0;
}