#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> mp;

int solution(vector<int> cookie) {
    int answer = -1;
    int sum = 0;
    for (int i = 0; i < cookie.size(); i++)
    {
        sum += cookie[i];
        mp[sum]++;
    }
    sum = 0;
    for (int i = 0; i < cookie.size(); i++)
    {
        if(i >= 1)
            sum += cookie[i - 1];
        int sum2 = 0;
        for (int j = i; j < cookie.size(); j++)
        {
            sum2 += cookie[j];
            if (mp[sum2 * 2 + sum])
                answer = max(answer, sum2);
        }
    }
    if (answer == -1)
        answer = 0;
    return answer;
}

int main()
{
    cout << solution({1,1,2,3});
}