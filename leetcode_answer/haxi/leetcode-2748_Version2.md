[力扣中国题目链接](https://leetcode.cn/problems/number-of-beautiful-pairs/)

# LeetCode 2748. 美丽下标对的数目

## 题目描述

给你一个由正整数组成的下标从 0 开始的数组 nums。

如果对于下标对 (i, j) 满足 0 ≤ i < j < nums.length，且 nums[i] 的最高位与 nums[j] 的最低位互质，则认为 (i, j) 是一个美丽下标对。

请你返回美丽下标对的数目。

---

## 题解思路

- **目标**：对于每个 nums[j]，统计有多少 nums[i]（i < j），使得 nums[i] 的最高位与 nums[j] 的最低位互质。
- **优化**：不必直接枚举所有 nums[i]，因为最高位只可能是 1~9。用 cnt[y] 统计每个最高位 y 出现的次数即可。
- **做法**：
    1. 初始化答案 ans=0，和长度为 10 的数组 cnt，初值为 0。
    2. 遍历 nums，设当前数为 x=nums[j]。
    3. 枚举 y=1~9，若 gcd(x % 10, y) == 1，则 ans += cnt[y]。
    4. 计算 x 的最高位，并将 cnt[最高位]++。
    5. 返回 ans。

---

## 代码实现（C++）

```cpp
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0, cnt[10]{};
        for (int x : nums) {
            for (int y = 1; y < 10; y++) {
                if (cnt[y] && gcd(x % 10, y) == 1) {
                    ans += cnt[y];
                }
            }
            int high = x;
            while (high >= 10) { 
                high /= 10;
            }
            cnt[high]++; // 统计最高位的出现次数
        }
        return ans;
    }
};
```

---

## 复杂度分析

- 时间复杂度：O(n × 9) = O(n)
- 空间复杂度：O(1) （只用 10 个计数器）

---

## 小结

- 用计数数组代替暴力枚举，实现高效查询。
- 最高位只有 1~9 九种可能，降低了复杂度。
- 适合所有“值域有限”的子问题高效计数。

---