#### String

- 当类型为string时，cin会录入一行; 如果要按行读取（空格不断开），可以用getline(cin,     str)
- 求子串方法：

str.substr(0, 8)， 【0，length = 8）

- 求字符串长度

`str.size()`

- `pow()`可以调用指数函数，在cmath库里面

 

#### Hashmap

- ```c++
  map<int, int>::iterator it; //创建一个迭代器，可以给map.end() , map.begin()返回
  ```

- 迭代器循环输出元素

```c++
for (auto i : m)
    cout << i.first << " \t\t\t " << i.second << endl;
//用迭代器循环输出元素
```

- 对于只存key，不存value，可以用set

  ```c++
  #include <set>
  //一些必要的lib
  #include<bits/stdc++.h>
  using namespace std;
  #include <unordered_map>
  #include <map>
  
  if(set.count(key));//检查是否存在：
  ```


#### 递归回溯写法(带输入输出)

```c++
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
class Solution {
  public:
    void recursion(vector<vector<int> >& res, vector<int>& num, int index) {
        //分枝进入结尾，找到一种排列
        if (index == num.size() - 1)
            res.push_back(num);
        else {
            //遍历后续的元素
            for (int i = index; i < num.size(); i++) {
                //交换二者
                swap(num[i], num[index]);
                //继续往后找
                recursion(res, num, index + 1);
                //回溯
                swap(num[i], num[index]);
            }
        }
    }

    vector<vector<int> > permute(vector<int>& num) {
        //先按字典序排序
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        //递归获取
        recursion(res, num, 0);
        return res;
    }
};

int main() {
    //if()空字符
    vector<int> array;
    int a;
    int count;
    cout << "test!!!!!!!"<< endl;
    // cin >> a;
    while(cin>>a){
        array.push_back(a);
    }
    Solution s;
    vector<vector<int>> res = s.permute(array);
    //cout << res.size();

    for(auto x : res){
        for(auto y : x){
            cout << y;
        }
        cout<< endl;
    }   
}
```

