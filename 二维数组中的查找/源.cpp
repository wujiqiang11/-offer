#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int len = array.size();
        if (len == 0)
            return false;
        int m = 0;  //ÐÐºÅ
        int n = array[0].size() - 1;  //ÁÐºÅ
        while (m <= len - 1 && n >= 0)
        {
            if (array[m][n] == target)
                return true;
            else if (array[m][n]<target)
            {
                m += 1;
            }
            else if (array[m][n]>target)
            {
                n -= 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
    //vector<vector<int>> array = {};
    Solution solu;
    bool a = solu.Find(7, array);
    cout << a << endl;
    return 0;
}