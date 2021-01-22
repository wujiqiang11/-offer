#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> array)
{
    int n = 1000000;
    for (auto i = array.begin(); i != array.end(); i++)
    {
        if (*i < n)
            n = *i;
    }
    return n;
}
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int p1 = 0;
        int p2 = rotateArray.size() - 1;
        cout << p2 << endl;
        if (rotateArray[p2] > rotateArray[p1])
            return rotateArray[0];
        if (p2 == p1)
            return rotateArray[0];
        int p_mid = (p1 + p2) / 2;
        cout << "p_mid" << p_mid << endl;
        if (rotateArray[p1] == rotateArray[p2] == rotateArray[p_mid])
            return search(rotateArray);
        else if (rotateArray[p_mid] > rotateArray[p1]||rotateArray[p_mid] >rotateArray[p2])
        {
            vector<int> temp(rotateArray.begin() + p_mid + 1, rotateArray.end());
            return minNumberInRotateArray(temp);
        }
        else
        {
            vector<int> temp(rotateArray.begin(), rotateArray.begin() + p_mid + 1);
            return minNumberInRotateArray(temp);
        }
    }
};

int main()
{
    //vector<int> arr = { 3,4,5,1,2 };
    vector<int> arr = { 3,4,4,5,1,2 };
    Solution solu;
    int re = solu.minNumberInRotateArray(arr);
    cout << re << endl;
    return 0;
}