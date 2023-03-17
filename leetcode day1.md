# 剑指offer day1

[TOC]

**速過思路階段**

#### [剑指 Offer 24. 反转链表](https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/)  **JZ6** **从尾到头打印链表**

- 使用stack全部入棧，然後再出棧鏈接



#### **JZ25** **合并两个排序的链表**

- 使用一個指針， 一個虛擬頭節點
- 每一次比較兩個鏈表開頭，哪個大cur.next就指向哪個，然後被指的跳一個，結束前，cur也跳一個



#### **JZ52 两个链表的第一个公共结点**

- 兩個cur在上，一個在下
- 每次兩個都++，判斷是否相等
- 如果到尾了，開始遍歷對面的鏈表

原理：

兩條鏈：相交在中間

size: 3-->2

size: 1-->2

黨兩個指針相遇的時候，他們走的路程是**相等**的：

cur1: 3+2+1 = 6

cur2: 1+2+3 = 6

如果没有交点，那么相等的时候

#### **JZ23** **链表中环的入口结点**

沒有環的話，指針最後會指向Null

有環情況：

- 利用快慢指針得出來相遇節點
- 得出后，快指針變成正常指針，和慢指針從頭遍歷，第二次相遇即入口點



#### **JZ22** **链表中倒数最后k个结点**（同反轉鏈表，都用stack的思想）



#### **JZ35** **复杂链表的复制**

即兩個指針域

方法：先遍歷第一遍得到正常指針域

第二遍使用move函數來讀取鏈表的第k個數，接到random域去即可



#### **JZ76** **删除链表中重复的结点**

- 遇到有重複的節點

- 先保存節點值在一個臨時的temp
- 用while來循環隔斷鏈接



#### **JZ18** **删除链表的节点**

這就是一個正常的刪除操作，條件是值相等

需要用一個前後指針來操作 prev cur

```c++
if(cur.val = val){
	cur = cur->next;//skip
	prev.next = cur;//link
	continue;
}else{
	prev.next = cur;//link
	cur = cur.next;//shift
	prev = prev.next;//shift
}
```



#### **JZ55** **二叉树的深度**（遞歸）

- 遞歸遍歷

#### **JZ77** **按之字形顺序打印二叉树**（迭代）

- 使用兩個輔助stack

- 每一層在stack裏，出stack的時候，都按照左右左右，右左右左地交替遍歷孩子，壓入stack，待下一層使用
- 終止條件是兩個stack都遍歷空

#### **JZ54** **二叉搜索树的第k个节点**（遞歸）

S1:

- 前序遍歷，找第k個

S2:

- 寫一個search的遞歸函數
- 直接在遞歸的過程當中，加入一個全局變量，count來統計目前位置的排位，如果排位count = val， 則直接返回所在結點的地址給res

#### **JZ7** **重建二叉树**

前序中序重建二叉樹，規律：中序數組第一個，是前序數組的中間，以這個為中間劃分左右子數組

- 重點：使用遞歸函數，**遞歸建樹**

```c
//函數傳入兩個子數組
//數組采用左右指針來包括：
// 左子樹：前序數組：pre.begin()+1  pre.begin()+1+i 中序數組：vin.begin() vin.begin()+i
// 右子樹：前序數組：pre.begin()+i+1 pre.end() 中序數組：vin.begin()+i+1 vin.end()
root->left = reConstructBinaryTree(leftpre, leftvin); 

root->right = reConstructBinaryTree(rightpre, rightvin); 
```

#### **JZ26** **树的子结构 ** (難點)

方法：先想一個最簡單的比較函數`recur()`

- 先比較父節點，AB的值不等，false； A空，不匹配，也是false；B空，B是空樹，肯定匹配，返回true
- 再比較子節點，即`recur(A.left,B.left)`  && `recur(A.right,B.right)`

```java
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        return (A != null && B != null) && (recur(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B));
    }
    boolean recur(TreeNode A, TreeNode B) {
        if(B == null) return true;
        if(A == null || A.val != B.val) return false;
        return recur(A.left, B.left) && recur(A.right, B.right);
    }
}

作者：jyd
链接：https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solution/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (B == null || A == null) {
            return false;
        }
        if (A.val == B.val && (helper(A.left, B.left) && helper(A.right, B.right))) {
            return true;
        }
        return isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    private boolean helper(TreeNode root1, TreeNode root2) {
        if (root2 == null) {
            return true;
        }
        if (root1 == null) {
            return false;
        }
        if (root1.val == root2.val) {
            return helper(root1.left, root2.left) && helper(root1.right, root2.right);
        } else {
            return false;
        }
    }
}
```

#### **JZ27** **二叉树的镜像**

自底而上的逐層交換左右節點。。。。其實自上而下也可以，反正每一個函數棧都會交換一次，順序不影響

```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/solution/er-cha-shu-de-jing-xiang-by-leetcode-sol-z44i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```





# 刷題總結

#### [剑指 Offer 24. 反转链表](https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/) [剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

- 存節點要帶*   `stack<ListNode*> stk;`
- 末尾节点的指针需要指向NULL（离谱）

```c++

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        stack<ListNode*> stk;
        ListNode* dummy = new ListNode(-1);
        while(head){         
            stk.push(head);
            cout << stk.top()->val << endl;
            head = head->next;
        }
        ListNode* cur = dummy;
        while(!stk.empty()){
            cur->next = stk.top();
            cout << cur->next->val << endl;
            stk.pop();
            cur = cur->next;
        }
        cur->next = NULL; //末尾节点的指针需要指向NULL
        cout << dummy->next->val << endl;
        return dummy->next;
    }
};
```

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> stk;
        vector<int> list;
        while(head){
            stk.push(head);
            head = head->next;
        }
        while(!stk.empty()){
            list.push_back(stk.top()->val);
            stk.pop();
        }
        return list;
    }
};

```

#### [剑指 Offer 25. 合并两个排序的链表](https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;

            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL) cur->next = l2;
        if(l2 == NULL) cur->next = l1;
        return dummy->next;
    }
};
```

#### [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)

- 空指针也是可以比较的，用于判断没有交点的情况

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while(p1 != p2){ //这里两个空指针也是可以比较的，用于判断没有交点的情况
        if(p1 != NULL) 
            p1 = p1->next;
        else
            p1 = headB;
        if(p2 != NULL)
            p2 = p2->next;
        else
            p2 = headA;
    }
    return p1;
}
```
#### [剑指 Offer II 022. 链表中环的入口节点](https://leetcode.cn/problems/c32eOV/)

对于一些边界条件，可能考虑不清楚，需要一点点地加入判断进去，比如这题没有环情况怎么处理，建议重复问题可以使用哈希表

```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        if(slow->next == NULL) return NULL;
        if(fast->next->next == NULL) return NULL;
        fast = fast->next->next;
        slow = slow->next;
        while(fast != slow){
            if(fast->next == NULL || fast->next->next == NULL) return NULL; //尾巴没有衔接
            fast = fast->next->next;
            slow = slow->next;            
        }
        //find the meet position
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
```

#### [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

```c++
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        stack<ListNode*> stk;
        while(head){
            stk.push(head);
            head = head->next;
        }
        k--;//栈顶就是倒数第一个
        while(k--){
            stk.pop();
        }
        return stk.top();
    }
};
```

#### [剑指 Offer 35. 复杂链表的复制](https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/)

```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node *cur = new Node(-1);
        Node *curHead = cur;
        Node *dummy = head;
        int size = 0;
        while(head){
            cur->next = new Node(head->val);
            mp[head] = cur->next;
            cur = cur->next;
            head = head->next;
            size++;
        }
        head = dummy;
        cur = curHead->next;
        while(size--){
            cur->random = mp[head->random];            
            cur = cur->next;
            head = head->next;
        }
        return curHead->next;
    }
};
```

#### [82. 删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)(重要，关于空指针的处理)

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur;
        dummy->next = head;
        cur = dummy;
        while(cur->next && cur->next->next){
            //same
            if(cur->next->val == cur->next->next->val){
                ListNode* temp = new ListNode(cur->next->val);
                while(cur->next && temp->val == cur->next->val){//注意空指针处理
                    cout<< temp->val << endl;
                    cur->next = cur->next->next; //delete
                }
                continue;
            }
            else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```



#### [剑指 Offer 18. 删除链表的节点](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

```c++
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        while(head){
            if(head->val == val){
                head = head->next;
            }
            prev->next = head;
            prev = prev->next;
            if(head) head = head->next;//空指针处理
        }
        return dummy->next;
    }
};
```

#### [剑指 Offer 07. 重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root= new TreeNode(preorder[0]);
        //find division
        int flag;
        for(; flag < inorder.size(); flag++){
            if(inorder[flag] == preorder[0])
            break;
        }
        //左开右闭
        vector<int> lnewPreorder(preorder.begin()+1, preorder.begin()+1+flag);
        vector<int> lnewInorder(inorder.begin(), inorder.begin()+flag);
        root->left = buildTree(lnewPreorder,lnewInorder);

        vector<int> rnewPreorder(preorder.begin()+flag+1, preorder.end());
        vector<int> rnewInorder(inorder.begin()+1+flag, inorder.end());
        root->right = buildTree(rnewPreorder,rnewInorder);
         return root;
    }
};	
```

#### [剑指 Offer 32 - III. 从上到下打印二叉树 III](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        vector<vector<int>> ret;
        if(root == NULL) return ret; //空节点特例
        stk1.push(root);
        int layer = 0;
        while(!stk1.empty() || !stk2.empty()){
            vector<int> path;
            if(layer % 2 == 0){//left->right
                while(!stk1.empty()){
                    TreeNode* temp = stk1.top();
                    path.push_back(temp->val);
                    stk1.pop();
                    if(temp->left) stk2.push(temp->left);
                    if(temp->right)stk2.push(temp->right);
                }
            }
            if(layer % 2 == 1){//left<-right
                while(!stk2.empty()){
                    TreeNode* temp = stk2.top();
                    path.push_back(temp->val);
                    stk2.pop();
                    if(temp->right) stk1.push(temp->right);
                    if(temp->left)stk1.push(temp->left);
                }
            }
            layer++;
            ret.push_back(path);
        }
        return ret;
    }
};
```

#### [剑指 Offer 54. 二叉搜索树的第k大节点](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)

```c++
class Solution {
public:
    stack<TreeNode*> ret;
    int kthLargest(TreeNode* root, int k) {
        recursion(root);
        k--;
        while(k--){
            ret.pop();
        }
        return ret.top()->val;
    }
    void recursion(TreeNode* root){
        if(root == NULL) return;
        recursion(root->left);
        ret.push(root);
        recursion(root->right);
    }
};
```

#### [剑指 Offer 26. 树的子结构](https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/)

```c++
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL) return false;
        if(B == NULL) return false;
        return comparison(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);   
    }
    bool comparison(TreeNode* A, TreeNode* B){
        if(B == NULL) return true;
        if(A == NULL) return false;
        if(A->val != B->val) return false;
        return comparison(A->left,B->left) && comparison(A->right,B->right);
    }
};
```

#### [剑指 Offer 27. 二叉树的镜像](https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/)

```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        return root;
    }
};
```

