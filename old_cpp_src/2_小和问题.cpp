#if 0
/*
��һ�������У�һ������߱���С�������ܺͣ��и�����С��
��������С���ۼ�������������С��
���ӣ� [1,3,4,2,5]
1��߱�1С������û��
3��߱�3С������1
4��߱�4С������1��3
2��߱�2С������1
5��߱�5С������1��3��4�� 2
���������С��Ϊ1+1+3+1+1+3+4+2=16
����һ������arr��������С��
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
	cout << "�������С��Ϊ: " << res << endl;

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

// arr[L...R]��Ҫ�ɺ���ҲҪ��С�ͷ���
// ����mergeʱ������С�ͣ��ۼ�
// �� ���� merge
// �� ���� merge
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