#include<vector>
#include<set>
using namespace std;

typedef set<int, greater<int>> intSet;


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        intSet tempSet;
        vector<int> result;
        int len = input.size();
        if (len == 0 || len < k)
            return result;
        for (auto iter = input.begin(); iter != input.end(); iter++)
        {
            if (tempSet.size() < k)
            {
                tempSet.insert(*iter);
            }
            else
            {
                if (*(tempSet.begin()) > (*iter))
                {
                    tempSet.erase(tempSet.begin());
                    tempSet.insert(*iter);
                }
            }
        }
        for (auto iter = tempSet.begin(); iter != tempSet.end(); iter++)
        {
            result.insert(result.begin(), *iter);
        }
        return result;
    }
};