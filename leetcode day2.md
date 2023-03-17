# 剑指offer day2

妈的，就应该每天都抄10题，然后思路过20题，以量取胜。然后记录下难啃的题目。

[TOC]

**速過思路階段 **

#### [剑指 Offer 32 - I. 从上到下打印二叉树](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)

- 使用队列
- 每次循环，获取队列的节点数
- 依次將節點值放入打印數組， 依次將左右孩子入列
- 循環終止條件：隊列沒有節點



#### [剑指 Offer 33. 二叉搜索树的后序遍历序列](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

（分治遞歸）後序遍歷的順序為left right middle

- 所以，以**數組最後一個數為分界**
- 由於是BFS，按照大小來劃分 子數組，小的為左子樹，大的為右子樹
- 將左右子樹傳入**遞歸函數**進行檢查
- 黨傳入數組長度小於1時，就可以終止了，因爲沒有數組可以比較了
- 用指針在**右子樹逐個比較**, 若存在小的，就返回指針位置，最後判斷是不是指到了末尾，不是説明邏輯不對

​     [面试题33. 二叉搜索树的后序遍历序列（递归分治 / 单调栈，清晰图解）](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/)



#### [剑指 Offer 34. 二叉树中和为某一值的路径](https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)（典型题目）

递归+回溯（递归之后的路径，回溯的时候要撤回）

- 设定两个全局数组变量`ret`  `path` 

- 递归函数（root，targetSum），终止条件：root == null， return

- 处理逻辑：进入递归函数，path更新，targetSum更行，判断是否需要输出

  递归进入左右子树，然后回撤path数组，返回

另外还有一题是不需要返回路径的，只需要判断有没有，这种就直接不需要`path`,保留`targetSum`即可



#### [剑指 Offer 36. 二叉搜索树与双向链表](https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

前序遞歸遍歷

- 終止條件 root == null

- 處理邏輯：

  link `root` 和`prev`節點

- 最後記得🔗頭尾



#### [剑指 Offer 55 - II. 平衡二叉树](https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/)

寫一個求深度的遞歸函數`getHeight(*root)`

邏輯：

`root == null return 0;`

左右都沒有， `return 1；`

左右都有：

左右分別遞歸，

`return max(l,r) + 1;`



主函數：

`root == null  yes`

求左右子樹深度

`if(abs(left - right) <= 1) return ture;`

`else false;`


