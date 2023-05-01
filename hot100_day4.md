# Hot100_day4

[TOC]





#### [56. 合并区间](https://leetcode.cn/problems/merge-intervals/)

这里本来想用哈希表的办法，找出中间的空隙，然后分开的，但是[1,3] [4,5]这种情况不行

解法：

- 先按第一个值排序
- 区间最大值用`t`表示， t和后面的区间的第二个值比较，取最大的。什么时候截止？小于等于某个区间的第一个值就截止，不用继续下去了。
- 得到一个区间之后，记得更新下一个区间的起始值

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {//小于等于某个区间的第一个值就截止，不用继续下去了。
                t = max(t, intervals[j][1]); // t和后面的区间的第二个值比较，取最大的
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;//得到一个区间之后，记得更新下一个区间的起始值
        }
        return ans;
    }
};
```

