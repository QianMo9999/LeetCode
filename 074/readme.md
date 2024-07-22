
> Problem: [LCR 074. 合并区间](https://leetcode.cn/problems/SsGoHC/description/)

# 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间

# 复杂度

- 时间复杂度: $O(nlogn)$
- 空间复杂度: $O(logn)$



# Code
```C++ []
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = -1, ed = -1;
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i ++ ){
            if(ed < intervals[i][0]){
                if(ed != -1) res.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            }
            else{
                ed = max(ed, intervals[i][1]);
            }
        }
        if(st != -1) res.push_back({st, ed});
        return res;
    }
};
```
  
