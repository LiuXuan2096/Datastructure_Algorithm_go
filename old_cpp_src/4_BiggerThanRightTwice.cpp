#if 0
/*
在一个数组中，对于任何一个数num，求有多少个(后面的数*2)依然<num，返回总个数
比如：[3,1,7,0,2]
3的后面有：1，0
1的后面有：0
7的后面有：0，2
0的后面没有
2的后面没有
所以总共有5个
*/
#include <iostream>

using namespace std;

int reversePairs(int arr[], int size, int *help);
int process(int arr[], int l, int r, int *help);
int merge(int arr[], int l, int m, int r, int* help);

int main()
{
	int arr[] = { 8,3,3,1 };  // 3 + 1 + 1+0 = 5
	int size = sizeof(arr) / sizeof(int);
	int* p = new int[size];
	int res = reversePairs(arr, size, p);
	cout << "结果为: " << res << endl;
	return 0;
}

int reversePairs(int arr[], int size, int* help)
{
	if (size <= 1)
	{
		return 0;
	}
	return process(arr, 0, size - 1, help);
}

int process(int arr[], int l, int r, int* help)
{
	if (l == r)
	{
		return 0;
	}
	int mid = l + ((r - l) >> 1);
	return process(arr, l, mid, help)
		+ process(arr, mid + 1, r, help)
		+ merge(arr, l, mid, r, help);
}

int merge(int arr[], int l, int mid, int r, int* help)
{
	// 先求出当前左组和右组中符合条件的数量
	int ans = 0;
	int windowR = mid + 1;  // 目前囊括进来的数 是从[M+1,windowR]
	for (int i = l; i <= mid; ++i)
	{
		while (windowR <= r && (long)arr[i] > (long)arr[windowR] * 2)
		{
			windowR++;
		}
		ans += windowR - mid - 1;
	}

	// 再merge
	int i = l;
	int p = l;
	int q = mid + 1;
	while (p <= mid && q <= r)
	{
		help[i++] = arr[p] <= arr[q] ? arr[p++] : arr[q++];
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

	return ans;
}
#endif