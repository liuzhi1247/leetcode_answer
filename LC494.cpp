# https://leetcode.cn/problems/target-sum/
# dp solution
这两行需要进行特殊前置处理
// if (abs(target) > sum) return 0; // 此时没有方案
//if ((target + sum) % 2 == 1) return 0; // 此时没有方案

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0; // 此时没有方案
        if ((target + sum) % 2 == 1) return 0; // 此时没有方案
        int total = (sum + target) / 2;
        // left - (sum - left ) = target  --> left = (sum + target) / 2

        // dp[i][j]：使用 下标为[0, i]的nums[i]能够凑满j（包括j）这么大容量的包，有dp[i][j]种方法。
        vector<int> dp(total+1, 0);
        dp[0] = 1; // 装满背包容量为0 的方法个数是1，即 放0件物品。

        for(int i = 0; i < nums.size(); i++) {
            for(int j = total; j >= nums[i]; --j) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[total];
    }
};
