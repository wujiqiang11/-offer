#include<vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if (len <= 0)
            return 0;
        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < len; i++)
        {
            if (result == numbers[i])
                times++;
            else
            {
                times--;
                if (times == 0)
                {
                    result = numbers[i];
                    times = 1;
                }
            }
        }

        int n = 0;
        for (int i = 0; i < len; i++)
        {
            if (numbers[i] == result)
                n++;
        }

        if (n > len / 2)
            return result;
        else
            return 0;
    }
};