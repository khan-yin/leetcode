#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MedianFinder {
public:
    // 用最大堆存储较小的那一半数据
    priority_queue<int, vector<int>, greater<int> > maxqueue;
    // 用最小堆存储较大的那一半数据
    priority_queue<int,vector<int>, less<int> > minqueue;

    /** initialize your data structure here. */
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        // 当两者相等时，我们往存储较大的一边插入一个新节点
        if(maxqueue.size()==minqueue.size())
        {
            maxqueue.push(num);
            int top = maxqueue.top();
            maxqueue.pop();
            minqueue.push(top);
        }
        else
        {
            // 当两者不相等时，必然是存储较小的那一半size<存储较大的那一半，所以需要往较小的一半里面添加元素
            minqueue.push(num);
            int top = minqueue.top();
            minqueue.pop();
            maxqueue.push(top);
        }
    }
    
    double findMedian() {
        if(maxqueue.size()==minqueue.size())
            return (maxqueue.top()+minqueue.top())*1.0/2;
        else
            return minqueue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */