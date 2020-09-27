#include <iostream>
#include <vector>
using namespace std;

vector<int> ar(500000);
int ret = 0;
void swap_ar(int start, int end)
{
	if (start == end) return;

	int mid = (start + end) / 2;

	swap_ar(start, mid);
	swap_ar(mid + 1, end);
	
	int right = mid + 1;
	int left = start;
	vector<int> temp;
	while (left <= mid && right <= end)
	{
		if (ar[left] <= ar[right])
			temp.push_back(ar[left++]);
		else {
			temp.push_back(ar[right++]);
			ret += (mid + 1 - left);
		}
	}

	while (left <= mid)
		temp.push_back(ar[left++]);
	while (right <= end)
		temp.push_back(ar[right++]);

	for (int i = 0; i < temp.size(); i++, start++)
		ar[start] = temp[i];
	

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	
	swap_ar(0, n - 1);
	cout << ret;
}