#if 0
/*
��һ�������У��κ�һ��ǰ�����a�����κ�һ���������b�����(a,b)�ǽ���ģ��ͳ�Ϊ�����
����һ������arr��������Ľ����������
*/
#include <iostream>

using namespace std;

int reversePairNumber(int arr[], int size, int* help);
int process(int arr[], int l, int r, int* help);
int merge(int arr[], int l, int m, int r, int* help);

int main()
{
	int arr[] = { 4,3,2,1 }; // 3+2+1+0 =6
	int size = sizeof(arr) / sizeof(int);
	int* p = new int[size];
	int res = reversePairNumber(arr, size, p);
	cout << "��������" << res << "������ԡ�" << endl;
	
	return 0;
}

int reversePairNumber(int arr[], int size, int* help)
{
	if (size <= 1)
	{
		return 0;
	}
	return process(arr, 0, size - 1, help);
}

// arr[L...R]��Ҫ�ź���ҲҪ���������������
// ����mergeʱ��������������������ۼ� ����
// �� ���� merge���������������
// �� ���� merge���������������
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

int merge(int arr[], int l, int m, int r, int* help)
{
	int i = r;
	int p = m;
	int q = r;
	int res = 0;
	while (p >= l && q > m)
	{
		if (arr[p] > arr[q])
		{
			res += q - m;
		}
		else
		{
			res += 0;
		}
		help[i--] = arr[p] > arr[q] ? arr[p--] : arr[q--];

	}
	while (p >= l)
	{
		help[i--] = arr[p--];
	}
	while (q > m)
	{
		help[i--] = arr[q--];
	}
	for (int j = l; j <= r; ++j)
	{
		arr[j] = help[j];
	}
	return res;
}
#endif