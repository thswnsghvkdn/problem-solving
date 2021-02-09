#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<char, int> mp;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill.length(); i++)
    {
        char t = skill[i];
        mp[t] = i + 1;
    }

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int size = 1;
        bool flag = true;
        for (int j = 0; j < skill_trees[i].length(); j++)
        {
            if (mp[skill_trees[i][j]] == 0) continue;
            if (size != mp[skill_trees[i][j]])
                flag = false;
            else if (size == mp[skill_trees[i][j]])
                size++;
        }

        if (flag)
            answer++;
    }
    
    return answer;
}

int main()
{
    int ans =  solution("CBD" , { "BACDE", "CBADF", "AECB", "BDA" } );
    cout << ans;
}