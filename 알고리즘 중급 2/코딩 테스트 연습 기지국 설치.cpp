#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 0;

    for (int station : stations)
    {
        int a = (station - w - 1) - start;
        int b = (int)ceil((double)a / (double)(w * 2 + 1));
        answer += max(b, 0);
        start = station + w;
    }
    answer += (int)ceil((double)(n - start) / double(w + 2 + 1));
    
    return answer;
}


int main()
{
    
    cout << solution(16, { 9 }, 2);


}