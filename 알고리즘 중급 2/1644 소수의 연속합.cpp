#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> primes;
vector<bool> check;
int n;
int main()
{
	cin >> n;
    check.resize(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (!check[i]) continue;
        for (int j = i * i; j <= n; j += i)
        {
            check[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (check[i]) primes.push_back(i);
    }
	int low = 0, high = 0;
    int sum = 0;
    int tot = 0;
    while ( high < primes.size() )
    {
        if (sum < n)
            sum += primes[high++];
        else
            sum -= primes[low++];

        if (sum == n)
            tot++; 
    }

    cout << tot;
}