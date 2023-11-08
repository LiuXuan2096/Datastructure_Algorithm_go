#if 0
#include <iostream>
#include <stack>
#include <random>

using namespace std;

int* netherlandsFlag(int arr[], int L, int R, int* res);
void quickSortRecursive(int arr[], int size);
void process(int arr[], int L, int R);
void quickSortNoRecursive(int arr[], int size);

struct Op
{
	int l;
	int r;
	Op(int left, int right)
	{
		l = left;
		r = right;
	}
};

random_device rd;
mt19937 gen(rd());
// 实现随机数函数
int random(int low, int high)
{
	uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

int main()
{
	// int arr[] = { 3,3,3,1,1,1,2,2,2 };
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(int);
	// int* res = new int[2];
	// int* p = netherlandsFlag(arr, 0, size - 1, res);
	// cout << p[0] << "  " << p[1] << endl;
	// quickSortRecursive(arr, size);
	quickSortNoRecursive(arr, size);
	cout << "[";
	for (int i = 0; i < size; ++i)
	{
		cout << " " << arr[i];
	}
	cout << "]";
	// delete[] res;
	return 0;
}

// 荷兰国旗问题
int* netherlandsFlag(int arr[], int L, int R, int* res)
{
	if (L > R)
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	else if (L == R)
	{
		res[0] = L;
		res[1] = R;
		return res;
	}
	int less = L - 1;
	int more = R;
	int index = L;
	while (index < more)
	{
		if (arr[index] == arr[R])
		{
			index++;
		}
		if (arr[index] < arr[R])
		{
			swap(arr[++less], arr[index++]);
		}
		else 
		{
			swap(arr[index], arr[--more]);
		}
	}
	swap(arr[more], arr[R]);
	res[0] = less + 1;
	res[1] = more;
	return res;
}

// 快速排序递归版本
void quickSortRecursive(int arr[], int size)
{
	if (size <= 1)
	{
		return;
	}
	process(arr, 0, size - 1);
}

void process(int arr[], int L, int R)
{
	if (L >= R)
	{
		return;
	}
	int randomIndex = random(L, R);
	swap(arr[randomIndex], arr[R]);
	int* res = new int[2];
	res = netherlandsFlag(arr, L, R, res);
	process(arr, L, res[0] - 1);
	process(arr, res[1] + 1, R);
	delete[] res;
}

// 用栈实现快速排序的非递归版本
void quickSortNoRecursive(int arr[], int size)
{
	if (size <= 1)
	{
		return;
	}
	stack<Op> Ops;
	int randomIndex = random(0, size - 1);
	swap(arr[randomIndex], arr[size - 1]);
	int* help = new int[2];
	help = netherlandsFlag(arr, 0, size - 1, help);
	Ops.push(Op{ 0, help[0] - 1});
	Ops.push(Op{ help[1] + 1, size - 1 });
	while (!Ops.empty())
	{
		Op op = Ops.top();
		Ops.pop();
		if (op.l < op.r)
		{
			swap(arr[random(op.l, op.r)], arr[op.r]);
			help = netherlandsFlag(arr, op.l, op.r, help);
			Ops.push(Op{ op.l, help[0] - 1 });
			Ops.push(Op{help[1] + 1, op.r });
		}
	}
	delete[] help;
}
#endif

