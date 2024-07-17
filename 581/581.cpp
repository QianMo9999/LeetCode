class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < nums.size() - 1 && nums[i] <= nums[i + 1]) i++;
        while (j > 1 && nums[j] >= nums[j - 1]) j--;
        if (i >= j) return 0;
        int maxn = -1e5 - 10, minn = 1e5 + 10;
        for (int k = i; k <= j; k++)
        {
            maxn = max(nums[k], maxn);
            minn = min(nums[k], minn);
        }
        while (i > 0 && nums[i - 1] > minn) i--;
        while (j < nums.size() - 1 && nums[j + 1] < maxn) j++;

        return j - i + 1;
    }
};