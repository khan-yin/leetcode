#include<queue>
#include<deque>
#include<iostream>
using namespace std;

class MaxQueue {
public:
    queue<int> q;
    deque<int> maxdq;
    MaxQueue() {
        
    }
    
    int max_value() {
        if(q.empty())
            return -1;
        return maxdq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!maxdq.empty()&&maxdq.back()<value)
            maxdq.pop_back();
        maxdq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int f = q.front();
        while(f==maxdq.front())
        {
            maxdq.pop_front();
        }
        q.pop();
        return f;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */