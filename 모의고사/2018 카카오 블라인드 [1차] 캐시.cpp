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
int LRU(vector<string> &cache, int size, string city)
{
	vector<string>::iterator it = find(cache.begin(), cache.end(), city);
	if (cache.size() < size)
	{
		if (it == cache.end())
		{
			cache.push_back(city);
			return 5;
		}
		else
		{
			cache.erase(it);
			cache.push_back(city);
			return 1;
		}
	
	}
	
	else {
		if (it == cache.end())
		{
			cache.erase(cache.begin());
			cache.push_back(city);
			return 5;
		}
		else
		{
			cache.erase(it);
			cache.push_back(city);
			return 1;
		}
	}
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
	if(cacheSize == 0)
	{
		return 5 * cities.size();
	}


	for (int i = 0; i < cities.size(); i++)
	{
		cities[i] = change_upper(cities[i]);
	}


	for (int i = 0; i < cities.size(); i++)
	{
		answer += LRU(cache, cacheSize, cities[i]);
	}

	return answer;
}
int main()
{
	cout << solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome","Paris","Jeju","NewYork", "Rome" });

}