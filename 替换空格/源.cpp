#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char* str, int length) {
		int n = 0;
		char* p1 = str;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				n++;
			p1++;
		}
		p1++;
		char* p2 = p1;
		int n_plus = n * 2;
		for (int i = 0; i <  n_plus; i++)
		{
			p2++;
		}
		while (p1 >= str)
		{
			if (*p1 != ' ')
			{
				*p2 = *p1;
			}
			else
			{
				*p2 = '0';
				p2--;
				*p2 = '2';
				p2--;
				*p2 = '%';
			}
			p1--;
			p2--;
		}
		
	}
};

int main()
{
	char a[] = "We Are Happy";
	int len = sizeof(a);
	Solution solu;
	solu.replaceSpace(a, len);
	cout << a << endl;
	return 0;
}