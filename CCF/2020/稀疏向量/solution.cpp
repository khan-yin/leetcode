#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int num_a[a][2];
	int num_b[b][2];
    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&num_a[i][0],&num_a[i][1]);
    }

    for(int i=0;i<b;i++)
    {
        scanf("%d %d",&num_b[i][0],&num_b[i][1]);
    }
    
    // for(int i=0;i<a;i++)
    // {
    //     cout<<num_a[i][0]<<" "<<num_a[i][1]<<endl;
    // }
    // for(int i=0;i<b;i++)
    // {
    //     cout<<num_b[i][0]<<" "<<num_b[i][1]<<endl;
    // }

    long long int ans=0;
    int i=0,j=0;
    
    while(i<a&&j<b)
    {
        if(num_a[i][0]==num_b[j][0])
        {
            ans+=num_a[i][1]*num_b[j][1];
            i++;
            j++;
        }
        else if(num_a[i][0]<num_b[j][0])
        {
            i++;
        }
        else if(num_a[i][0]>num_b[j][0])
        {
            j++;
        }
    }
    cout<<ans<<endl;


    return 0;
}