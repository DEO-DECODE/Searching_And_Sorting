class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          unordered_map<string, int> freq;
  for (auto str : words)
  {
    freq[str]++;
  }
  map<int, set<string>> mp;
  for (auto val : freq)
  {
    mp[val.second].insert(val.first);
  }
  vector<string> ans;
   auto itr = --mp.end();
  while (k)
  {
    
    for (auto str : (*itr).second)
    {
      ans.push_back(str);
      k--;
      if (k == 0)
        break;
    }
    itr--;
  }
  return ans;
    }
};
