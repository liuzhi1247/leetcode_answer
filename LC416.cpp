https://leetcode.cn/problems/partition-equal-subset-sum/

01背包
    那每一件商品是数字的话，对应的重量 和 价值是多少呢？

一个数字只有一个维度，即 重量等于价值。

当数字 可以装满 承载重量为 sum / 2 的背包的背包时，这个背包的价值也是 sum / 2。

那么这道题就是 装满 承载重量为 sum / 2 的背包，价值最大是多少？

如果最大价值是 sum / 2，说明正好被商品装满了。

因为商品是数字，重量和对应的价值是相同的。
    
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i : nums) {
            sum += i;
        }
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        if(sum % 2 == 1) return false;
        
        int bagWeight = sum/2;
        vector<int> dp(10001, 0);//01背包中，dp[j] 表示： 容量（所能装的重量）为j的背包，所背的物品价值最大可以为dp[j]。
        //题目中1 <= nums.length <= 200， 1 <= nums[i] <= 100，所有物品的最大容量为20000， 一半则为10000， dp数组最大设置为10001即可。
        for(int i = 0; i < n; i++) { // 遍历物品
            for(int j = bagWeight; j >= nums[i]; j--) { // 遍历背包容量
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[bagWeight] ==bagWeight) return true;
        return false;
    }
};
```
背包问题，不仅可以求 背包能被的最大价值，还可以求这个背包是否可以装满。
