# https://leetcode.cn/problems/last-stone-weight-ii/
// same as LC416

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 1 <= stones.length <= 30, 1 <= stones[i] <= 100
        // sum should be the half
        vector<int> dp(1501, 0);
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int total = sum / 2;

        for(int i = 0; i<stones.size(); ++i) {
            for(int j = total; j >= stones[i]; --j ) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        //one sumup is dp[total], the other sumup is sum - dp[total]
        // sum - dp[total] is bigger than dp[total].
        return sum - dp[total] * 2;
    }
};
