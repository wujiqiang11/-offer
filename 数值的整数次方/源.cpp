class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0.0)
            return 0.0;
        else if (exponent==0)
        {
            return 1.0;
        }
        else if(exponent>0)
        {
            double temp = 1;
            for (int i = 0; i < exponent; i++)
            {
                temp *= base;
            }
            return temp;
        }
        else
        {
            double temp = 1;
            for (int i = 0; i < -exponent; i++)
            {
                temp *= base;
            }
            return 1/temp;
        }
    }
};