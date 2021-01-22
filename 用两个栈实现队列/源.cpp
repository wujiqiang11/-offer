#include<iostream>
#include<stack>

using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            int temp;
            while (!stack1.empty())
            {
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int re;
        re = stack2.top();
        stack2.pop();
        return re;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};