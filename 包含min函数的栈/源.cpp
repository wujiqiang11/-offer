#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> arr;
    int min_index;

public:
    void push(int value) {
        if (arr.empty())
        {
            min_index = 0;
        }
        else
        {
            if (value < arr[min_index])
                min_index = arr.size();
        }
        arr.push_back(value);
    }
    void pop() {
        if (arr.size() > 0)
        {
            arr.erase(arr.end()-1);
            if (min_index == arr.size())
            {
                if (!arr.empty())
                {
                    int temp = arr[0];
                    min_index = 0;
                    for (int i = 0; i < arr.size(); i++)
                    {
                        if (arr[i] < temp)
                        {
                            min_index = i;
                        }
                    }
                }
            }
        }
    }
    int top() {
        if (arr.size() > 0)
        {
            return arr[arr.size()-1];
        }
    }
    int min() {
        return arr[min_index];
    }
};

int main()
{
    Solution su;
    int a[] = { 1,2,5,2,-7,4,0 };
    for (int i = 0; i < 7; i++)
    {
        su.push(a[i]);
    }
    
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();
    cout << su.min() << endl;
    cout << su.top() << endl;
    su.pop();



    return 0;
}
