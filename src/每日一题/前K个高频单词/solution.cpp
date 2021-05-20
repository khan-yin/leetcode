#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;

struct Word
{
    string s;
    int c;
    bool operator<(const Word &w) const
    {
        if(c==w.c)
        {
            return s > w.s;
        }
        else return c<w.c;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<Word> q;
        unordered_map<string,int> m;
        vector<string> res;
        for(auto word : words)
        {
            m[word]++;
            // cout<<word<<" "<<m[word]<<endl;
        }

        for(auto item : m)
        {
            q.push({item.first,item.second});
        }
        int cnt=0;
        while(cnt<k)
        {
            auto item = q.top();
            res.push_back(item.s);
            q.pop();
            cnt++;
        }

        return res;
    }
};