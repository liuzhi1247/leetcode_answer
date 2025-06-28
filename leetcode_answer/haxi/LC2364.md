[力扣中国题目链接](https://leetcode.cn/problems/count-bad-pairs/)

# LeetCode 2364. 统计坏数对的数目

## 题目描述

给你一个下标从 0 开始的整数数组 `nums` 。如果 `i < j` 且 `j - i != nums[j] - nums[i]`，那么我们称 `(i, j)` 是一个**坏数对**。

请你返回 nums 中**坏数对**的总数目。

---

## 示例

```
输入：nums = [4,1,3,3]
输出：5
解释：总共有 6 个数对：(0,1)、(0,2)、(0,3)、(1,2)、(1,3)、(2,3)
只有 (0,2) 不是坏数对，因为 2-0 == nums[2]-nums[0]，其余都是坏数对。
```

---

## 题解思路

- 所有的 (i, j) (i < j) 共有 n*(n-1)/2 个对。
- 如果 (i, j) 不是坏数对，则 `j - i == nums[j] - nums[i]`，即 `j - nums[j] == i - nums[i]`。
- 用哈希表统计每个 `i-nums[i]` 出现的次数，所有相同的值构成“好数对”。
- 用总对数减去“好数对”就是“坏数对”。

---

## 代码实现（C++）

```cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = 1LL * n * (n - 1) / 2;
        unordered_map<int, long long> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[i - nums[i]]++;
        }
        long long good = 0;
        for (auto& [k, v] : cnt) {
            good += v * (v - 1) / 2;
        }
        return total - good;
    }
};
```

---

## 复杂度分析

- 时间复杂度：O(n)
- 空间复杂度：O(n)

---

## 小结

- 利用数学变换将“好数对”计数问题转为哈希计数，利用总对数减法得到“坏数对”。
- 代码简洁高效，适合大数据规模。

---
