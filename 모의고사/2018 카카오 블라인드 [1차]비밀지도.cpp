#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> DtoB(int dec, int n)
{
	vector<int>s;
	for (int i = 0; i < n; i++)
	{
		s.push_back(dec % 2);
		dec /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	cin >> n;
	vector<int> s1, s2;
	int map[17][17];
	for (int i = 0; i < n; i++)
	{
		s1 = DtoB(arr1[i], n);
		s2 = DtoB(arr2[i], n);
		string temp = "";
		for (int j = 0; j < n; j++)
		{
			if (s1[j] == 1 || s2[j] == 1)
				temp += '#';
			else temp += ' ';
		}
		answer.push_back(temp);
	}
	
	return answer;
}
int main()
{
	vector<int> a1 = { 9, 20 , 28, 18, 11 };
	vector<int> a2 = { 30, 1 , 21, 17, 28 };

	vector<string> answer = solution(5, a1, a2);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}