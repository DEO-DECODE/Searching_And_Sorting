class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
  int lo = 0, hi = citations.size(), ans;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    int numCitations = citations.end() - lower_bound(citations.begin(), citations.end(), mid);
    if (numCitations >= mid)
    {
      ans = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }
  return ans;
    }
};
