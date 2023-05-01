# Hot100 day1



[TOC]

**速過思路階段 **

#### 1. 两数相加

这题把两个数放在两个链表的node上

解法就是： 逐个对应节点相加，记录carry的值： `carry = sum / 10` 结果值：`sum = sum % 10` 

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode pre = new ListNode(0);
        ListNode cur = pre;
        int carry = 0;
        while(l1 != null || l2 != null) {
            int x = l1 == null ? 0 : l1.val;
            int y = l2 == null ? 0 : l2.val;
            int sum = x + y + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            cur.next = new ListNode(sum);

            cur = cur.next;
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }
        if(carry == 1) {
            cur.next = new ListNode(carry);
        }
        return pre.next;
    }
}

作者：guanpengchn
链接：https://leetcode.cn/problems/add-two-numbers/solution/hua-jie-suan-fa-2-liang-shu-xiang-jia-by-guanpengc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### 2. 无重复最长字串

`hash map`  ` double pointer` 

用hash表记录下字串的值

right++ ： 查重

left--： 去掉原来的记录

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> map;
        int res = 0; //记录答案
        for(int right = 0; right < s.size(); right++) {
            map[s[right]] += 1;
            while(left <= right && map[s[right]] >= 2) { //若存在重复字符，重新维护子串
                map[s[left++]] -= 1;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

作者：nefuct
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/shuang-zhi-zhen-mapwei-hu-zi-chuan-by-ne-ezl4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。	
```



#### [4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

创建一个有序的新数组即可(时间复杂度达不到要求)

```java
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int[] nums;
    int m = nums1.length;
    int n = nums2.length;
    nums = new int[m + n];
    if (m == 0) {
        if (n % 2 == 0) {
            return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
        } else {

            return nums2[n / 2];
        }
    }
    if (n == 0) {
        if (m % 2 == 0) {
            return (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;
        } else {
            return nums1[m / 2];
        }
    }

    int count = 0;
    int i = 0, j = 0;
    while (count != (m + n)) {
        if (i == m) {
            while (j != n) {
                nums[count++] = nums2[j++];
            }
            break;
        }
        if (j == n) {
            while (i != m) {
                nums[count++] = nums1[i++];
            }
            break;
        }

        if (nums1[i] < nums2[j]) {
            nums[count++] = nums1[i++];
        } else {
            nums[count++] = nums2[j++];
        }
    }

    if (count % 2 == 0) {
        return (nums[count / 2 - 1] + nums[count / 2]) / 2.0;
    } else {
        return nums[count / 2];
    }
}

作者：windliang
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。					
```

#### [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)（难度较大）

回文就是正着念反着念都是一个意思是

这题用动态规划法，转移方程`dp[i][j]`表示第`i`个值和第`j`个值是否相等

- length >= 3, 转移方程：`dp[i][j]`  = (`dp[i] == [j] && dp[i+1][j-1]`)
- 之前学的dp都只有一维，并且`dp[0]`是已知的，但是现在的这个并不是，其实这里的`dp[i][i]`和`dp[i][i+1]`相当于是dp[0]的概念，因为所有的转移方程，最后都会递归到判断临近的两个字母是否是回文。

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};

作者：chenlele
链接：https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-c-by-gpe3dbjds1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### [6. N 字形变换](https://leetcode.cn/problems/zigzag-conversion/)

>
>
>[冰镇西瓜](https://leetcode.cn/u/bing-zhen-xi-gua-c/)
>
>来自江苏
>
>2022-11-26
>
>这个题包装的很唬人，但是实际就是给s的每一位标记就好了：假设numRows为4，那就是那s每一位的行数就是：1234321234321

```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1)return s;
        int len = s.length();
        int flag[] = new int[len];//给每个元素打标记，记录在哪行
        flag[0] = 1;
        int direction = 1;//控制标记的变化方向
        for(int i = 1; i < len; i++){
            if(flag[i - 1] == 1)direction = 1;
            else if(flag[i - 1] == numRows)direction = -1;
            flag[i] = flag[i - 1] + direction;
        }
        int j = 1, n = 0;
        char[] arr = new char[len]; 
        while(j <= numRows){
            for(int i = 0; i < len; i++){
                if(flag[i] == j)
                    arr[n++] = s.charAt(i);
            }
            j++;
        }
        return new String(arr);
    }
}


```

#### [7. 整数反转](https://leetcode.cn/problems/reverse-integer/)

- 负数用一样的方法反转也没问题

- 在比较result时，先比较其是否小于MIN或大于MAX，如是，直接return 0；不是的话，再进位，加digit，得到本轮的新数
- 如果不同上面说的话，那就直接找出`MIN`和`MAX`是多少，然后判断就行了

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode-solution-bccn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

```C++
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int m = x % 10;
            if((x > 0 && (ans < 214748364 || (ans == 214748364 && m <= 7))) 
            || (x < 0 && (ans > -214748364 || (ans == -214748364 && m >= -8)))){
                ans = ans * 10 + m;
            }else{
                return 0;
            }
            x /= 10;
        }
        return ans;  
    }
};
```

