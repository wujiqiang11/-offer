#include<vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        vector<int> marker(pushV.size(), 1);
        int p1;
        int p2;
        for (int i = 0; i < popV.size(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < pushV.size(); j++)
                {
                    if (pushV[j] == popV[i])
                    {
                        p1 = j;
                        p2 = j;
                        marker[j] = 0;
                    }
                }
                p1--;
                p2++;
            }
            else
            {
                if (p1 >= 0)
                {
                    if (popV[i] == pushV[p1])
                    {
                        p1--;
                        while (p1>=0)
                        {
                            if (marker[p1] == 0)
                                p1--;
                            else
                                break;
                        }
                        continue;
                    }
                }
                if (p2 < pushV.size())
                {
                    while (p2 < pushV.size())
                    {
                        if (popV[i] == pushV[p2])
                        {
                            p1 = p2-1;
                            while (p1 >= 0)
                            {
                                if (marker[p1] == 0)
                                    p1--;
                                else
                                    break;
                            }
                            marker[p2] = 0;
                            p2++;
                            continue;
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
};