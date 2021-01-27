#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() <= 2&&sequence.size()>0)
            return true;
        else if (sequence.size()==0)
        {
            return false;
        }
        else
        {
            vector<int> left;
            vector<int> right;
            int large = 0;
            bool large_t = false;
            for (int i = 0; i < sequence.size() - 1; i++)
            {
                if (sequence[i] >= sequence[sequence.size()-1])
                {
                    if (!large_t)
                        large = i;
                    large_t = true;
                }
                else if(large_t)
                {
                    return false;
                }
            }
            left.assign(sequence.begin(), sequence.begin() + large);
            right.assign(sequence.begin() + large, sequence.end() - 1);
            if(left.size()>0&&right.size()>0)
                return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
            else if(left.size()>0)
            {
                return VerifySquenceOfBST(left);
            }
            else
            {
                return VerifySquenceOfBST(right);
            }
        }
    }
};

int main()
{
    vector<int> a = { 7,4,6,5 };
    cout << a[a.size()-1] << endl;
    Solution su;
    su.VerifySquenceOfBST(a);
    return 0;
}