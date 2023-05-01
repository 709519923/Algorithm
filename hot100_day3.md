# Hot100_day3

[TOC]

#### [39. 组合总和](https:- leetcode.cn/problems/combination- sum/)

递归回溯法

- 每一遍的递归，都有n个选择
- 返回条件：如果target < 0 return (剪枝),  if 数组遍历到尽头idx==size of array return (超过一个)
-   target == 0 vector.add,  pop弹出

这里考虑一下**传递的参数是否有数组**的问题，理论上这个res数组可以是全局变量，但是，对于数据的安全性来说，放在局部更合理。

```c++
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/combination-sum/solution/zu-he-zong-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



#### [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)

- 按行求：

![image-20230425183614588](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230425183614588.png)

- 动态规划法：

  - 从左到右扫一遍leftmax[]
  - 从右到左扫一遍rightmax[]
  - 交集，减去方块高度即可

  ![image-20230425185126050](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230425185126050.png)

```java
public int trap(int[] height) {
    int sum = 0;
    int max = getMax(height);//找到最大的高度，以便遍历。
    for (int i = 1; i <= max; i++) {
        boolean isStart = false; //标记是否开始更新 temp
        int temp_sum = 0;
        for (int j = 0; j < height.length; j++) {
            if (isStart && height[j] < i) {
                temp_sum++;
            }
            if (height[j] >= i) {
                sum = sum + temp_sum;
                temp_sum = 0;
                isStart = true;
            }
        }
    }
    return sum;
}
private int getMax(int[] height) {
		int max = 0;
		for (int i = 0; i < height.length; i++) {
			if (height[i] > max) {
				max = height[i];
			}
		}
		return max;
}

作者：windliang
链接：https://leetcode.cn/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

```c++
//dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### [46. 全排列](https://leetcode.cn/problems/permutations/)

递归回溯：

- 注意哪些是要用到的全局变量
- 需要增添历史数组来记录某个数是否已经被使用

```c++
class Solution {
public:
    vector<int> path;
    vector<bool> state;
    vector<vector<int>> ans;
    void dfs(vector<int> nums)
    {
        if(path.size() == nums.size()) 
        {
            ans.push_back(path);
            return ;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(state[i] == false)
            {
                path.push_back(nums[i]);
                state[i] = 1;
                dfs(nums);
                state[i] = false;
                path.pop_back();    //这里这一段并非再是可有可无了，必须存在
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        state = vector<bool>(nums.size());
        dfs(nums);
        return ans;
    }
};
```

#### [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)★★

互为异位词等同于排序后字符串相同，因此通过**哈希表**来维护，key设为排序后的字符串，val来保存每个异位词结果，最后返回哈希表值的集合即可

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)

- 先上下反转

- 再左右对称

```c++
// 按照题目要求进行原地操作
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先转置
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再左右镜像对称
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }

    }
};

作者：zhywanna
链接：https://leetcode.cn/problems/rotate-image/solution/c-beats-100-gao-duan-de-ti-jie-wang-wang-kfuh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

