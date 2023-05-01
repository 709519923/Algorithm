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

  

