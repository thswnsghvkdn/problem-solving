#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
	string name;
	int kor;
	int eng;
	int mat;
};

bool cmp(Person a , Person b)
{
	if (a.kor == b.kor && a.eng == b.eng && a.mat == b.mat)
		return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng)
		return a.mat > b.mat;
	if (a.kor == b.kor)
		return a.eng < b.eng;
	return a.kor > b.kor;
}
int main()
{
	int n;
	cin >> n;
	vector<Person> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].mat;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i].name << "\n";
}