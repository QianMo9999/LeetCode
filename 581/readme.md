> Problem: [LCR 581. 最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/)

# 最短无序连续子数组
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
请你找出符合题意的 最短 子数组，并输出它的长度。
## 算法思路
- 双指针
### 找到左边界
```
while (i < nums.size() - 1 && nums[i] <= nums[i + 1]) i++;
```
### 找到右边界
```
while (j > 1 && nums[j] >= nums[j - 1]) j--;
```
### 边界情况
```
if (i >= j) return 0;
```
### 找到子数组的最大值和最小值
```
int maxn = -1e5 - 10, minn = 1e5 + 10;  
for (int k = i; k <= j; k++) {  
    maxn = max(nums[k], maxn);  
    minn = min(nums[k], minn);  
}
```
### 调整左边界
```
while (i > 0 && nums[i - 1] > minn) i--;
```
### 调整右边界
```
while (j < nums.size() - 1 && nums[j + 1] < maxn) j++;
```
### 返回结果
```
return j - i + 1;
```
## 复杂度
- 时间复杂度 $O(n)$
- 空间复杂度 $O(1)$
