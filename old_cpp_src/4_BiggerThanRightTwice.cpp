#if 0
/*
��һ�������У������κ�һ����num�����ж��ٸ�(�������*2)��Ȼ<num�������ܸ���
���磺[3,1,7,0,2]
3�ĺ����У�1��0
1�ĺ����У�0
7�ĺ����У�0��2
0�ĺ���û��
2�ĺ���û��
�����ܹ���5��
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
	cout << "���Ϊ: " << res << endl;
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
	// �������ǰ����������з�������������
	int ans = 0;
	int windowR = mid + 1;  // Ŀǰ������������ �Ǵ�[M+1,windowR]
	for (int i = l; i <= mid; ++i)
	{
		while (windowR <= r && (long)arr[i] > (long)arr[windowR] * 2)
		{
			windowR++;
		}
		ans += windowR - mid - 1;
	}

	// ��merge
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