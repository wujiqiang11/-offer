#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
private:
    vector<string> result;
    map<string, int> hashMap;
    void push(string str)
    {
        auto iter = hashMap.find(str);
        if (iter == hashMap.end())
        {
            result.push_back(str);
            hashMap.insert(pair<string, int>(str, 1));
        }
        return;
    }
    void array(string &str, int begin)
    {
        if (begin == str.length())
            push(str);
        else
        {
            for (int i = begin; i < str.length(); i++)
            {
                auto temp = str[begin];
                str[begin] = str[i];
                str[i] = temp;
                array(str, begin + 1);
                temp = str[begin];
                str[begin] = str[i];
                str[i] = temp;
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        if (str.length() == 0)
            return result;
        else
        {
            array(str, 0);
            sort(result.begin(), result.end());
            return result;
        }
    }
};

int main()
{
    Solution su;
    string str = "aaa";
    vector<string> re = su.Permutation(str);
    for (int i = 0; i < re.size(); i++)
        cout << re[i] << "  ";
    cout << endl;

    return 0;
}
