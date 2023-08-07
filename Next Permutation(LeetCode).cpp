class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0, n = nums.size();
	int j = n - 1;
	vector<int> temp;
	while (j - 1 >= 0 && nums[j] <= nums[j - 1])
	{
		j--;
		temp.push_back(nums[j]);
	}
	if(j==0){
		sort(nums.begin(), nums.end());
		return;
	}
	int targetIndex = j - 1;
	j = n - 1;
	while (j > targetIndex && nums[targetIndex] >= nums[j])
	{
		j--;
	}
	// cout<<targetIndex<<" "<<nums[targetIndex]<<" "<<j<<" "<<nums[j]<<endl;;
	swap(nums[targetIndex], nums[j]);
	sort(nums.begin() + targetIndex+1, nums.end());
    }
};
