# This file is to record the daily promote leetcode codes

## 2025/03/16

- Update .cpp files to .md files
- Add 01背包模板和完全背包模板
- Add filefolder 技术支持，解决push没法到main的代理连接问题
- update 完全背包的组合问题/排列问题/求最小值解法
- add 01背包题目record.md以及完全背包record.md

## 2025/03/15

### 01背包

- LC416 --> 01背包，倒序更新dp[j]
- LC1049 --> 01背包，倒序更新dp[j]
- LC494 --> 01背包，倒序更新dp[j]
- LC474 --> 01背包问题，需要倒序更新dp[i][j]

因为01背包中，物品不能够被重复选择，所以对于j的循环需要进行倒序更新。

但是对于**完全背包**，因为物品可以被重复选择，所以需要进行**正序更新**，如果我们使用倒序更新，那么在更新 dp 数组时，可能会漏掉一些可以重复选择的物品，从而导致错误的结果。

### 完全背包题目实例


完全背包的组合问题
- LC518 --> 完全背包的组合问题，所有元素可多次选择，但是与顺序无关。 需要先遍历物品，然后遍历背包容量。

完全背包的排列问题
- LC377 --> 完全背包的排列问题，所有元素可多次选择，但是与顺序有关。 需要先遍历背包容量，然后遍历物品。
- LC70 --> 完全背包的排列问题, 思路同LC377。

求最小数
- LC322 --> 完全背包的组合问题。
- LC279 --> 完全背包的组合问题，基本流程同LC322。

**外层 `for` 循环遍历物品，内层 `for` 循环遍历背包容量**：计算的是组合数。
**外层 `for` 循环遍历背包容量，内层 `for` 循环遍历物品**：计算的是排列数。