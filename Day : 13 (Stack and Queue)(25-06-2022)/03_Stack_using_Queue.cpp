#include<bits/stdc++.h>
class Stack {

    queue<int> q;
    int topp;
   public:
    Stack() {
        topp = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
      return q.size();
    }

    bool isEmpty() {
      return q.empty();
    }

    void push(int element) {
       q.push(element);
        topp = element;
    }

    int pop() {
        if(q.empty()) return -1;
        int n = q.size();
        if(n == 1)
        {
            int ele = q.front();
            q.pop();
            return ele;
        }
        while(--n)
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        int to_pop = q.front();
        q.pop();
        topp = q.back();
        return to_pop;
    }

    int top() {
        if(q.empty()) return -1;
        return topp;
    }
};
