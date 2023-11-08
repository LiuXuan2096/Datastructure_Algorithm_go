/*
��Ŀ��

�����ܶ��߶Σ�ÿ���߶ζ���������[start, end]��
��ʾ�߶ο�ʼλ�úͽ���λ�ã����Ҷ��Ǳ�����
�涨��
1���߶εĿ�ʼ�ͽ���λ��һ����������ֵ
2���߶��غ�����ĳ��ȱ���>=1
�����߶�����غ������У������˼����߶�
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Line
{
	int start;
	int end;

	Line(int s, int e)
		: start(s)
		, end(e)
	{}
};

bool compare(Line l1, Line l2)
{
	return l1.start < l2.start;
}

int maxCover(int (*arr)[2], int size);

int main()
{
	int arr[][2] = {
		{1,3},
		{1,4},
		{2,5},
		{2,6},
		{1,6}
	};
	int size = sizeof(arr) / (2 * sizeof(int));
	int res = maxCover(arr, size);
	cout << "�����غ���Ϊ: " << res << endl;
	return 0;
}

int maxCover(int(*arr)[2], int size)
{
	vector<Line> lines;
	priority_queue<int, vector<int>, greater<int>> heap;

	for (int i = 0; i < size; ++i)
	{
		lines.push_back(Line(arr[i][0], arr[i][1]));
	}
	sort(lines.begin(), lines.end(), compare);

	int Max = 0;
	for (Line line : lines)
	{
		while (!heap.empty() && heap.top() <= line.start)
		{
			heap.pop();
		}
		heap.push(line.end);
		Max = max(Max, (int)heap.size());
	}
	return Max;
}