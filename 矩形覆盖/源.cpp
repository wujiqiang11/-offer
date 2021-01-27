class Solution {
public:
    int rectCover(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
        {
            return 2;
        }
        else
        {
            int n = 0;
            int n1 = 1;
            int n2 = 2;

            for (int i = 0; i < number - 2; i++)
            {
                n = n1 + n2;
                n1 = n2;
                n2 = n;
            }
            return n;
        }

    }
};