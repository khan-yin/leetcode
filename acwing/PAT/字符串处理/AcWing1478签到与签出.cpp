#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string first_id,first_time;
    string last_id,last_time;
    scanf("%d",&n);
    string id,in_time,out_time;
    for(int i=0;i<n;i++)
    {
        cin>>id>>in_time>>out_time;
        if(!i || in_time < first_time)
        {
            first_id = id;
            first_time = in_time;
        }
        
        if(!i || out_time > last_time)
        {
            last_id = id;
            last_time = out_time;
        }
    }
    
    cout<<first_id<<" "<<last_id<<endl;
    return 0;
}