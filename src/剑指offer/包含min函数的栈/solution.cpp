#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> minvalue;

    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(minvalue.empty())
            minvalue.push(x);
        else
        {
            int nowmin = minvalue.top()>x?x: minvalue.top();
            minvalue.push(nowmin);
        }
    }
    
    void pop() {
        s.pop();
        minvalue.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return minvalue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */