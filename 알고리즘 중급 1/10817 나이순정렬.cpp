#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct {
	string name;
	int seq;
	int age;
}Person;

bool cmp(Person a, Person b)
{
	if (a.age == b.age)
		return a.seq < b.seq;
	return a.age < b.age;
}
int main()
{
	int n;
	cin >> n;
	Person* p;
	p = new Person[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].age;
		cin >> p[i].name;
		p[i].seq = i;
	}

	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << p[i].age << " " << p[i].name << "\n";
	}

	delete [] p;


}