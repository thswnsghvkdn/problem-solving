#include <iostream>
using namespace std;

int n, m;
int A[10001];
int tot;
void check_sum(int start)
{
	int sum = 0;
	for (int i = start; i < n; i++)
	{
		sum += A[i];
		if (sum == m) {
			tot++;
			return;
		}
	}
	return;
}
#include <iostream>
using namespace std;

int n, m;
int A[10001];
int tot;
void check_sum(int start)
{
	int sum = 0;
	for (int i = start; i < n; i++)
	{
		sum += A[i];
		if (sum == m) {
			tot++;
			return;
		}
	}
	return;
}
void two_pointer()
{
	int high = 0, low = 0;
	int sum = 0;
	while (high < n && low <= high)
	{
		sum += A[high++];
		if (sum == m)
			tot++;
		while (sum > m)
		{
			sum -= A[low++];
			if (sum == m)
				tot++;
			if (low > high && low < n)
			{
				high = low;
				sum = A[high];
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	// 기본적인 O(n^2) 방법
	//for (int i = 0; i < n; i++)
		//check_sum(i);

	two_pointer();
	cout << tot;
}