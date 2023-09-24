class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> st;
  for (auto val : nums1)
  {
    st.insert(val);
  }
  vector<int> ans;
  for (int i = 0; i < nums2.size(); ++i)
  {
    auto it = st.upper_bound(nums2[i]);
    if (it != st.end())
    {
      ans.push_back(*it);
      st.erase(it);
    }
    else
    {
      ans.push_back((*st.begin()));
      st.erase(st.begin());
    }
  }
  return ans;
    }
};
