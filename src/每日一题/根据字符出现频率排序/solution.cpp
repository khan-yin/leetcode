#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

struct Node
{
    char ch;
    int cnt=0;
};

bool cmp(Node &a ,Node &b)
{
    return a.cnt>b.cnt;
}

class Solution {
public:
    Node map[200];
    string frequencySort(string s) {
        for(char c : s)
        {
            map[c-32].ch = c;
            map[c-32].cnt++;            
        }

        sort(map,map+200,cmp);

        string res ="";
        for(int i=0;i<200;i++)
        {
            if(map[i].cnt==0) continue;
            for(int j=0;j<map[i].cnt;j++) res += map[i].ch;
            
        }
        return res;
    }
};