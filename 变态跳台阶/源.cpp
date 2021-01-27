class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0)
            return 1;
        else
        {
            int nn = 0;
            for (int n = number; n >= 1; n--)
            {
                nn += jumpFloorII(number - n);
            }
            return nn;
        }
    }
};