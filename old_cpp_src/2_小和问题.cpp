#if 0
/*
在一个数组中，一个数左边比它小的数的总和，叫该数的小和
所有数的小和累加起来，叫数组小和
例子： [1,3,4,2,5]
1左边比1小的数：没有
3左边比3小的数：1
4左边比4小的数：1、3
2左边比2小的数：1
5左边比5小的数：1、3、4、 2
所以数组的小和为1+1+3+1+1+3+4+2=16
给定一个数组arr，求数组小和
*/
#include<iostream>

using namespace std;

int smallSum(int arr[], int size, int* help);
int process(int arr[], int l, int r, int* help);
int merge(int arr[], int l, int m, int r, int* help);

int main()
{
	int arr[] = { 1,2,3,4 };  // 0+1+1+2+1+2+3 = 10
	int size = sizeof(arr) / sizeof(int);
	int* p = new int[size];
	int res = smallSum(arr, size, p);
	cout << "该数组的小和为: " << res << endl;

	return 0;
}

int smallSum(int arr[], int size, int* help)
{
	if (size <= 1)
	{
		return 0;
	}
	return process(arr, 0, size - 1, help);
}

// arr[L...R]既要派好序，也要求小和返回
// 所有merge时产生的小和，累加
// 左 排序 merge
// 右 排序 merge
// merge
int process(int arr[], int l, int r, int* help)
{
	if (l == r)
	{
		return 0;
	}
	int mid = l + ((r - l) >> 1);
	return process(arr, l, mid, help) + process(arr, mid + 1, r, help)
		+ merge(arr, l, mid, r, help);
}

int merge(int arr[], int l, int mid, int r, int* help)
{
	int i = l;
	int p = l;
	int q = mid + 1;
	int res = 0;
	while (p <= mid && q <= r)
	{
		if (arr[p] < arr[q])
		{
			res += arr[p] * (r - q + 1);
 		}
		else
		{
			res += 0;
		}
		help[i++] = arr[p] < arr[q] ? arr[p++] : arr[q++];
	}
	while (p <= mid)
	{
		help[i++] = arr[p++];
	}
	while (q <= r)
	{
		help[i++] = arr[q++];
	}
	for (int j = l; j <= r; ++j)
	{
		arr[j] = help[j];
	}
	return res;
}
#endif