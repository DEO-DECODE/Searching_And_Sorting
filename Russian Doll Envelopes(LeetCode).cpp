class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[0] != b[0])
		return a[0] < b[0];
	else
		return a[1] > b[1];
}
int f(int ind, int prev, vector<vector<int>> &dp, vector<int> &nums, int n)
{
	if (ind == n)
		return 0;
	if (dp[ind][prev + 1] != -1)
	{
		return dp[ind][prev + 1];
	}
	// Not Take
	int len = 0 + f(ind + 1, prev, dp, nums, n);
	// Take
	if (prev == -1 || nums[ind] > nums[prev])
	{
		len = max(len, 1 + f(ind + 1, ind, dp, nums, n));
	}
	return dp[ind][prev + 1] = len;
}
int lengthOfLongest(vector<int> &nums){
	int n=nums.size();
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return f(0, -1, dp, nums, n);
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
	int n = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), cmp);
	int maxWidth = INT_MAX, maxHeight = INT_MAX;
	vector<int> nums;
	for(auto vec: envelopes){
		nums.push_back(vec[1]);
	}
	return lengthOfLongest(nums);
}
};
