#include<bits/stdc++.h>
class Queue {
    stack<int> s1;
    stack<int> s2;
    public:
    Queue() {
        
    }

    void enQueue(int val) {
       s1.push(val);
    }

    int deQueue() {
        if(s1.empty()) return -1;
        while( s1.size() > 1)
        {
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        int pop = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return pop;
    }

    int peek() {
        if(s1.empty()) return -1;
         int n = s1.size();
        while( s1.size() > 1)
        {
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        int topp = s1.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return topp;
    }

    bool isEmpty() {
        return s1.empty();
    }
};
