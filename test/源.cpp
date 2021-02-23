#include<iostream>
#include<string>
using namespace std;
void test1(string &a)
{
	a[2] = 'b';
	cout << a << endl;
}
int main()
{
	string a = "aaaaaaa";
	test1(a);
	cout << a << endl;
	return 0;
}