// PAT甲级真题1052
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


struct Node
{
    string address;
    int key;
    string next;
    
    bool operator<(const Node& a) const
    {
        return key < a.key;
    }
};


unordered_map<string,Node> map;

int main()
{
    int n;
    char head[10];
    scanf("%d%s", &n, head);
    char address[20],next[20];
    while (n -- )
    {
        int key;
        scanf("%s%d%s", address, &key, next);
        map[address] = {address, key, next};
    }
    
    vector<Node> res;
    for(string i=head;i!="-1";i=map[i].next)
    {
        res.push_back(map[i]);
    }
    
    printf("%d ", res.size());
    if (res.empty()) puts("-1");
    else
    {
        sort(res.begin(),res.end());
        printf("%s\n",res[0].address.c_str());
        for(int i=0;i<res.size();i++)
        {
            if(i+1==res.size()) 
                printf("%s %d -1\n", res[i].address.c_str(), res[i].key);
            else
                printf("%s %d %s\n", res[i].address.c_str(), res[i].key, res[i + 1].address.c_str());
        }
    }
    
    return 0;
}