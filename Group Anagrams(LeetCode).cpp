#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string orgStr = str;
        string duplicateStr = str;
        sort(duplicateStr.begin(), duplicateStr.end());
        mp[duplicateStr].push_back(orgStr);
    }
    vector<vector<string>> ans;
    for(auto pr: mp){
        ans.push_back(pr.second);
    }
    return ans;
}
