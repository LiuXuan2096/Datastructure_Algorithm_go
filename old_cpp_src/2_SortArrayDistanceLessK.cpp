#if 0
/*
��֪һ��������������顣����������ָ������������ź�˳��Ļ���ÿ��Ԫ���ƶ��ľ���һ��������k
k��������鳤����˵�ǱȽ�С�ġ���ѡ��һ�����ʵ�������ԣ�����������������
*/
#include <queue>
#include "ShowArray.h"

using namespace std;

void sortedArrDistanceLessK(int arr[], int size, int k);

int main()
{
	int arr[] = { 2,3,0,1,6,7,4,5,99,88 }; //k = 2
	int size = sizeof(arr) / sizeof(int);
	showArray(arr, size);
	sortedArrDistanceLessK(arr, size, 2);
	showArray(arr, size);
	return 0;
}

void sortedArrDistanceLessK(int arr[], int size, int k)
{
	// Ĭ�ϴ����,Ҫ������С����
	priority_queue<int, vector<int>, greater<int>> heap;
	int index = 0;
	for (; index <= min(size - 1, k - 1); ++index)
	{
		heap.push(arr[index]);
	}
	int i = 0;
	for (; index < size; ++i, ++index)
	{
		heap.push(arr[index]);
		arr[i] = heap.top();
		heap.pop();
	}
	while (!heap.empty())
	{
		arr[i++] = heap.top();
		heap.pop();
	}

}
#endif