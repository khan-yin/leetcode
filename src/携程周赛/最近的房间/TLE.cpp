// bool cmp(vector<int> &a ,vector<int> &b)
// {
//     if(a[0]==b[0])
//         return a[1]>=b[1];
//     return a[0]<=b[0];
// }
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Numbers
{
    int x;
    int absx;
};
Numbers numbers[100010];

bool cmp(Numbers &a ,Numbers &b)
{
    if (a.absx == b.absx)
        return a.x<=b.x;
    else
        return a.absx<b.absx;
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> res;
        int roomsize = rooms.size();
        int querysize = queries.size();
        map<int,int> roommap;

        
        for(int i=0;i<roomsize;i++)
        {
            roommap[rooms[i][0]]=rooms[i][1];
            numbers[i].x = rooms[i][0];
        }

        for(auto item : queries)
        {
            int preferred = item[0];
            int minsize = item[1];
            for(int i=0;i<roomsize;i++)
            {
                numbers[i].absx = abs(numbers[i].x - preferred);
            }
            sort(numbers,numbers+roomsize,cmp);
            bool flag =false;
            for(int i=0;i<roomsize&&!flag;i++)
            {
                // cout<<numbers[i].x<<" "<<numbers[i].absx<<endl;
                if(roommap[numbers[i].x]>=minsize)
                {
                    res.push_back(numbers[i].x);
                    flag=true;
                }
            }
            if(!flag)
                res.push_back(-1);
            
        }

        return res;
        
    }
};