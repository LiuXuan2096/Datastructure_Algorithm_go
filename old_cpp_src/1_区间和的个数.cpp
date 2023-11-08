#if 0
/*
https://leetcode.com/problems/count-of-range-sum/
����һ���������� nums �Լ��������� lower �� upper ���������У�ֵλ�ڷ�Χ [lower, upper] 
������ lower �� upper��֮�ڵ� ����͵ĸ��� ��

����� S(i, j) ��ʾ�� nums �У�λ�ô� i �� j ��Ԫ��֮�ͣ����� i �� j (i �� j)��
*/
#include <iostream>

using namespace std;

int countRangeSum(int arr[],int size, int lower, int upper, long* help, long* sum);
int process(long* sum, int l, int r, int lower, int upper, long* help);
int merge(long* sum, int L, int M, int R, int lower, int upper, long* help);

int main()
{
	int arr[] = { -2, 5, -1 };
	int size = sizeof(arr) / sizeof(int);
	long* sum = new long[size];
	long* p = new long[size];
	int res = countRangeSum(arr, size, -2, 2, p, sum);
	cout << "����������������Ϊ: " << res << endl;
	delete[] sum;
	delete[] p;
	return 0;
}

int countRangeSum(int arr[],int size, int lower, int upper, long* help, long *sum)
{
	if (size == 0)
	{
		return 0;
	}
	sum[0] = arr[0];
	for (int i = 1; i < size; ++i)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	return process(sum, 0, size - 1, lower, upper, help);
}

int process(long* sum, int l, int r, int lower, int upper, long* help)
{
	if (l == r)
	{
		return sum[l] >= lower && sum[r] <= upper ? 1 : 0;
	}
	int mid = l + ((r - l) >> 1);
	return process(sum, l, mid, lower, upper, help)
		+ process(sum, mid + 1, r, lower, upper, help)
		+ merge(sum, l, mid, r, lower, upper, help);
}

int merge(long* sum, int L, int M, int R, int lower, int upper, long* help)
{
	// ���ȼ������� �� ����һ���ǣ��м�����������������
	int ans = 0;
	int windowL = L;
	int windowR = L;
	for (int i = M + 1; i <= R; ++i)
	{
		long max = sum[i] - lower;
		long min = sum[i] - upper;
		while (windowR <= M && sum[windowR] <= max)
		{
			windowR++;
		}
		while (windowL <= M && sum[windowL] < min)
		{
			++windowL;
		}
		ans += windowR - windowL;
	}

	// ��ʼ�鲢�����Ǻܴ�ͳ�İ���������鲢��һ����������Ĺ���
	int i = L;
	int p = L;
	int q = M + 1;
	while (p <= M && q <= R)
	{
		help[i++] = sum[p] <= sum[q] ? sum[p++] : sum[q++];
	}
	while (p <= M)
	{
		help[i++] = sum[p++];
	}
	while (q <= R)
	{
		help[i++] = sum[q++];
	}
	for (int j = L; j <= R; ++j)
	{
		sum[j] = help[j];
	}

	return ans;
}
#endif