# import matplotlib.pyplot as plt

# plt.style.use('_mpl-gallery-nogrid')

# # make data: correlated + noise
# squares = [1 , 4 , 9 , 16]

# # plot:
# fig, ax = plt.subplots()

# ax.plot(squares)

# plt.show()

import matplotlib.pyplot as plt
import numpy as np
# %matplotlib inline

fig = plt.figure() # 创建画布
ax = fig.add_subplot(111, projection='3d') # 添加三维坐标系

x = np.arange(-20, 20, 0.5) # 定义x的范围
y = np.arange(-20, 20, 0.5) # 定义y的范围
X, Y = np.meshgrid(x, y) # 生成网格矩阵

R = np.sqrt(X**2 + Y**2) # 计算R值
Z = np.sin(R) # 计算Z值

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=plt.get_cmap('CMRmap')) # 绘制三维曲面图

ax.contourf(X, Y, Z, zdir='z', offset=-2, cmap='CMRmap') # 在底部绘制等高线图

ax.set_zlim(-2, 2) # 设置z轴范围

ax.set_title("3D Surface Plot of sin(sqrt(x²+y²))", fontsize=14)  # 设置图形标题
ax.set_xlabel("X", fontsize=12)                             # X轴标签
ax.set_ylabel("Y", fontsize=12)                             # Y轴标签
ax.set_zlabel("Z", fontsize=12)                         # Z轴标签
plt.show()