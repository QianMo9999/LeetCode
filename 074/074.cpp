class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = -1, ed = -1;
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (ed < intervals[i][0]) {
                if (ed != -1) res.push_back({ st, ed });
                st = intervals[i][0];
                ed = intervals[i][1];
            }
            else {
                ed = max(ed, intervals[i][1]);
            }
        }
        if (st != -1) res.push_back({ st, ed });
        return res;
    }
};