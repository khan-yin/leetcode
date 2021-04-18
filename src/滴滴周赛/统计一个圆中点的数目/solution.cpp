#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double distance(int x1,int y1,int x2,int y2)
    {
        return (x2-x1)*1.0*(x2-x1)+(y2-y1)*1.0*(y2-y1);
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // set<vector<int>> pure;
        // for(auto it : points)
        // {
        //     if(pure.find(it)!=pure.end())
        //     {
        //         cout<<it[0]<<" "<<it[1]<<endl;
        //     }
        //     pure.insert(it);
        // }
        // cout<<pure.size()<<" "<<points.size()<<endl;
        vector<int> res(queries.size());

        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            double r=queries[i][2];
            for(auto it : points)
            {
                if(distance(x,y,it[0],it[1])<=(r*r))
                    res[i]++;
            }
        }
        return res;
    }
};