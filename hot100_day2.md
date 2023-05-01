# Hot100 day2

[TOC]

​	

#### [22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)★★★

递归回溯的拓展题目，以前的题目递归终止条件是树的节点没了`root == null`

现在这里稍微复杂一点，终止条件是：当括号用完的时候

此外，处理逻辑也稍微复杂一点，分为两种情况：

- 何时可以加左括号
- 何时可以加右括号

```c++
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



#### [31. 下一个排列](https://leetcode.cn/problems/next-permutation/)★★★★（题目比较难理解，但代码不难）

题目就是要找一个数a的下一个最小的大数b，即紧邻的数b>a,且b-a尽可能小

- 直觉中，123465，我们肯定是要找6后面的数，然后找一个略比4大的数 `5`，替换之，然后再将5后面的数升序排列

- 思路没错，但有个bug就是123465783，这个数这样替换就有问题，因为不像上一个12346*，找的是最小的数；这里要找最小的数，需要从后面开始找第一个升序，即78，然后再应用->873, 再对73升序->37

```c++
void nextPermutation(vector<int>& nums) {
        int i=0;
        for (i=nums.size()-2; i >= 0; -- i) { // 从后往前找到第一个相邻升序对
            if (nums[i] < nums[i+1]) break;
        }
        if (i == -1) reverse(nums.begin(),nums.end()); // 无相邻升序对，必定为非递减序列
        else {
            for (int j=nums.size()-1; j >= i+1; -- j) { // 从后往前[i+1,end)找第一个大于a[i+1]的值
                if (nums[i] < nums[j]) {
                    swap(nums[i],nums[j]); // 交换二者
                    reverse(nums.begin()+i+1,nums.end()); // 反转[i+1,end)，变成升序
                    break;
                }
            }
        }
    }
```



#### [32. 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)★★★★

这个和**括号匹配**类似，但是不是单纯地用一个栈来解决。

题解是使用栈记录index，并且用不匹配的右括号的index来作为起始点标记

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)★★

![image-20230421223551955](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230421223551955.png)

> **方法一：最简单的做法, 先找到最值将旋转数组分成两段有序数组，接下来在有序数组中找目标值就轻车熟路了。
> 先找到 「153. 寻找旋转排序数组中的最小值」的索引，由此可以将数组分为升序的两段。
> 根据 nums[0] 与 target 的关系判断 target 在左段还是右段，再对升序数组进行二分查找即可。

- 用不斷二分縮小左右指針的方法，找到最小值

- 判斷target和最小值的關係，確定所在位置（左段 還是 右段）
- 在對應的段進行二分查找即可

[153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)

改進：

因爲是局部有序的，因此就算打亂了一次，我們也可以藉助a[mid], a[left], a[right]的關係進行範圍縮小

（但自己寫的時候最好使用原始的方法，一步步來，防止陷入死循環出錯）

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)★★

先用二分查找找到值，mid，在[0,mid]二分查找left_index，在[mid, end]二分查找right_index

在找到mid之後，左右可以用四個指針來指代，[left1,right1]  [left2,right2]

這裏沒有代碼，官方比較複雜，建議還是按著自己的思路來寫。

以下參考代碼其實沒有使用三次二分法，使用兩次也行，就是縮小範圍的時候，會有

`right = mid -1\left = mid + 1 `

這種跨越的操作，不好理解

>通过夹逼思路，寻找大于 target - 1 的第一个位置beginPos和大于 target的第一个位置end;
>如所求元素存在，起始下标就是 beginPos, 最后元素下标应为 endPos = end - 1;
>如果所求元素不存在，beginPos = end => (beginPos > endPos)。
>
>作者：shimmer-kf
>链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/cer-fen-sou-suo-tong-su-yi-dong-by-shimm-g4sf/
>来源：力扣（LeetCode）
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beginPos = binarySearch(nums, target - 1);
        int endPos = binarySearch(nums, target) - 1;
        if (beginPos > endPos) {
            return vector<int>{-1, -1};
        }
        return vector<int>{beginPos, endPos};
    }

private:
    /* 搜索大于target的第一个元素下标
    *  nums为[], 返回0， target >= max(nums)， 返回 nums.size();
    */
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = right;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] <= target) {
                left = mid + 1;
            } 
        }
        return left;
    }
};

作者：shimmer-kf
链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/cer-fen-sou-suo-tong-su-yi-dong-by-shimm-g4sf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

