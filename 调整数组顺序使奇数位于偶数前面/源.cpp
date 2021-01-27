#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int>& array) {
        int temp;
        bool swap=true;
        while (swap)
        {
            swap = false;
            for (int i = 1; i < array.size(); i++)
            {
                if (array[i - 1] % 2 == 0 && array[i] % 2 == 1)
                {
                    temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                    swap = true;
                }
            }
        }
    }
};