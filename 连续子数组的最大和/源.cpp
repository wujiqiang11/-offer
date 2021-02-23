#include<vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if (len == 0)
            return 0;
        int maxSum = array[0];
        int tempSum = 0;
        int index = 0;
        for (int i = 0; i < len; i++)
        {
            tempSum = tempSum + array[i];
            
            if (tempSum > maxSum)
                maxSum = tempSum;
            if (tempSum < 0)
                tempSum = 0;
        }
        return maxSum;
    }
};