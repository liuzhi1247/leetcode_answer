# https://leetcode.cn/problems/coin-change-ii/

完全背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);//dp[j] 表示凑成金额 j 的组合数。
        dp[0] = 1;//0的时候只有一种方法
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; ++j) {//记得j要等于amount
                if (dp[j] < INT_MAX - dp[j - coins[i]]) {//因为case中有一个大case和超过int，所以要做前置的处理
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        return dp[amount];//返回dp[amount]
    }
};
