# https://leetcode.cn/problems/ones-and-zeroes/

//01背包问题
倒序更新dp[i][j]
dp数组的定义为最多有i个0和j个1的strs的最大子集的大小为dp[i][j]

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         // 初始化 dp 数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // 遍历每一个字符串
        for (const string& s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = count(s.begin(), s.end(), '1');
            
            // 倒序更新 dp 数组
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
