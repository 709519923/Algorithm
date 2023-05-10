# Self-driving Learning Note

[TOC]

#### Kinematic model of a simple 2D robot

![image-20230508151733347](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230508151733347.png)

####  关于汽车建模（非两轮，四轮，前驱）

假设：

- 縱向速度係常數
- left and right axle  are lumped into a single view（左右軸集中在一個視野--即有個等效重心在中間）

- 漂移，斜坡，空氣阻力順力忽略

標準狀態空間表示：

橫向位置，側向滑動角，偏航角，偏航率





### Lesson 6 (vehicle actuation system )

- steering

  - simple model:  wheel angle = constant * steering angle 

  $$
  \delta = c \times \delta_{steering}
  $$

- throttling (油門)

  - 發動機扭矩（engine torque） --> 變速器（齒輪比）（transmission - {gear ratio}） --> 輪胎力矩（wheel torque）

  - 汽油、柴油、電動引擎角速度(angular velocity)與力矩（torque）對比， 電動引擎的角速度越快，效率越差

![image-20230509152017724](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509152017724.png)

- braking
  - braking pressure --> disk force --> wheel torque
  - 



### Lesson 7 (tire slip and modeling)

這堂課的内容就是教授打轉向盤時，汽車位移角的model

![image-20230509152722386](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509152722386.png)

![image-20230509153049189](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509153049189.png)

为了简化计算，正切会有近似值代替，因为角度在13.99°之前，误差为1%，

cos *θ* ≈ 1，約為 0.1408 弧度 (8.07°)

tan *θ* ≈ *θ*，約為 0.1730 弧度 (9.91°)

sin *θ* ≈ *θ*，約為 0.2441 弧度 (13.99°)

cos *θ* ≈ 1 − *θ*2/2，約為 0.6620 弧度 (37.93°)

![image-20230509153209085](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509153209085.png)

Tire slip angle(轮胎指向的方向和实际行驶方向的夹角)

#### tire 建模

- 线性模型，力和slip angle是线性的

![image-20230509161153569](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509161153569.png)

- 魔法公式

![image-20230509161558383](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509161558383.png)

- 

#### Lab

- bicycle kinematics modeling 

  （source: Lesson 2: The Kinematic Bicycle Model,5:40）

![image-20230509164122571](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509164122571.png)

x,y是中心坐标的Δ

Θ是实际行驶角度的Δ

δ是实际行驶角度和目标行驶角度的夹角的Δ

β是δ在中心坐标的转换

注意这些参数都是打点的，都是差值、变化量

所以初始值state可以是【x,y,θ,δ】表示车所在位置，行驶的角度，目标角度

输入（input）可以是【v, φ】，即行驶速度，角度改变的速率，可以理解为$\delta = \frac{dw}{dt} $



由于需要计算绕圆行驶的参数，我们引用ICR

![image-20230509173227261](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20230509173227261.png)

