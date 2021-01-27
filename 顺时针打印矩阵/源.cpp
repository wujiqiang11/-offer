#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> temp;
        vector<int> temp2;
        int m = matrix.size();
        if (m == 0)
            return  temp;
        int n = matrix[0].size();
        if (n == 0)
            return temp;
        int x = 0;
        int y = 0;
        while (m>0)
        {
            temp2 = print(matrix, x, y, n, m);
            temp.insert(temp.end(), temp2.begin(), temp2.end());
            m = m - 2;
            n = n - 2;
            x = x + 1;
            y = y + 1;
        }
        return temp;
    }
    vector<int> print(vector<vector<int>> matrix, int x, int y, int m, int n)
    {
        vector<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(matrix[y][x+i]);
        }
        for (int i = 1; i < n; i++)
        {
            temp.push_back(matrix[y + i][x + m - 1]);
        }
        if (n > 1)
        {
            for (int i = m - 2; i >= 0; i--)
            {
                temp.push_back(matrix[y + n - 1][x + i]);
            }
        }
        if (m > 1)
        {
            for (int i = n - 2; i >= 1; i--)
            {
                temp.push_back(matrix[y + i][x]);
            }
        }
        return temp;
    }
};