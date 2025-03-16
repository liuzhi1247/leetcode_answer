# this file is to record the daily promote leetcode codes

# 2025/03/16
update .cpp files to .md files
add 01背包模板和完全背包模板
add filefolder 技术支持，解决push没法到main的代理连接问题

# 2025/03/15
## 01背包
LC416-->01背包，倒序更新dp[j]
LC1049-->01背包，倒序更新dp[j]
LC494-->01背包，倒序更新dp[j]
LC474-->01背包问题，需要倒序更新dp[i][j]
因为01背包中，物品不能够被重复选择，所以对于j的循环需要进行倒序更新

但是对于**完全背包**，因为物品可以被重复选择，所以需要进行**正序更新**，如果我们使用倒序更新，那么在更新 dp 数组时，可能会漏掉一些可以重复选择的物品，从而导致错误的结果。
## 完全背包题目实例
LC518


