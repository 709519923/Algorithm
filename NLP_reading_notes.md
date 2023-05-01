# NLP

#### 



#### word net

即**同义词**或者**上位词**相关的词语统计起来，组成词网

缺点：

- 缺失一些词语间的差别--good-proficient, 没有办法很好地描述一些词的内涵

- 无法up-to-date,新词的意义不理解
- 主观？
- 需要手工创建，适配
- 无法计算单词的相似程度

#### discrete symbols

motel = [0 0 0 0 0 0 0 0 0 0 1 0 0 0 0] 

hotel = [0 0 0 0 0 0 0 1 0 0 0 0 0 0 0]

因为正交，没有相似性可言similarity

#### **word vector**

**Continuous Bag of words,  skip-gram**

用weight来表示一个单词，训练的方法：

![image-20230501141714866](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230501141714866.png)