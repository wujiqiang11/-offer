#include<vector>
#include<iostream>
using namespace std;

int Partition(vector<int>& array, int low, int high)
{
	int p = array[low];
	while (low < high)
	{
		while (array[high] >= p&&low<high)
		{
			high--;
		}
		array[low] = array[high];
		while (array[low] <= p && low < high)
		{
			low++;
		}
		array[high] = array[low];
	}
	array[low] = p;
	return p;
}

void QuickSort(vector<int>& array, int low, int high)
{
	if (low < high)
	{
		int p = Partition(array, low, high);
		QuickSort(array, low, p - 1);
		QuickSort(array, p, high);
	}
}

int main()
{
	vector<int> array = { 2,5,6,3,1,4 };
	QuickSort(array, 0, array.size() - 1);
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
