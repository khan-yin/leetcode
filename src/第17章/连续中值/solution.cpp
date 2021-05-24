#include<queue>
#include<iostream>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    int cnt=0;
    priority_queue<int> maxq;//大根堆，存储较小的一端
    priority_queue<int,vector<int>,greater<int>> minq;//小根堆，存储较大的一端
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        cnt++;
        if (maxq.size() == minq.size())
        {
            minq.push(num);
            int mid = minq.top();  minq.pop();
            maxq.push(mid);
        }
        else
        {
            maxq.push(num);
            int t = maxq.top(); maxq.pop();
            minq.push(t);   
        }
    }
    
    double findMedian() {
        // cout<<maxq.top()<<endl;
        if(cnt&1)//奇数
        {
            return maxq.top()*1.0;
        }
        else
        {
            return (minq.top()+maxq.top())*1.0/2;
        }
    }
};
