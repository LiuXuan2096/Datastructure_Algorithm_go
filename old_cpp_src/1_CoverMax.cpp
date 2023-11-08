/*
题目：

给定很多线段，每个线段都有两个数[start, end]，
表示线段开始位置和结束位置，左右都是闭区间
规定：
1）线段的开始和结束位置一定都是整数值
2）线段重合区域的长度必须>=1
返回线段最多重合区域中，包含了几条线段
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
	cout << "做大重合数为: " << res << endl;
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