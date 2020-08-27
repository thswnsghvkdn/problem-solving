#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<string> copy(int index, vector<string> cities)
{
	vector<string> temp;
	for (int i = index; i >= 0; i--)
		temp.push_back(cities[i]);
	unique(temp.begin(), temp.end());
	return temp;
}
string change_upper(string s)
{

	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);
	}

	return s;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	bool hit;
	vector<string> cache;

	for (int i = 0; i < cities.size(); i++)
	{
		cities[i] = change_upper(cities[i]);
	}


	for (int i = 0; i < cities.size(); i++)
	{
		hit = false;
		string temp = cities[i];
		for (int j = 0; j < cache.size(); j++)
		{
			if (temp == cache[j]) {
				answer += 1;
				hit = true;
				break;
			}
		}
		if (hit == false && cache.size() == cacheSize)
		{
			auto temp_v = copy(i , cities);
			for (int k = 0; k < cacheSize; k++)
			{
				if (cache[k] == temp_v[cacheSize]) {
					cache[k] = temp;
					break;
				}
			}
			answer += 5;
		}
		if (hit == false && cache.size() < cacheSize)
		{
			cache.push_back(cities[i]);
			answer += 5;
		}

	}

	return answer;
}
int main()
{
	cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });

}