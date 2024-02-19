#!/usr/bin/python3

import torch

print("===================== PyTorch的安装 =====================")
print("torch.__version__: ", torch.__version__)
print("")

print("===================== 一、数据操作 =====================")
print("------------- 1.1 基本操作对象  ------------- ")
x = torch.arange(12)
x1 = torch.arange(2, 12, 2)
print("x : ", x)
print("x1: ", x1)                   #长为2

print("")
print("x.shape   : ", x.shape)      #张量的shape属性
print("x.numel() : ", x.numel())
print("x.size()  : ", x.size())
print("")

print("------------- reshape 函数  ------------- ")
x=x.reshape(2, 6)
print("x : ", x)
x=x.reshape(-1, 4)
print("x : ", x)
print("")

print("------------- zeros/ones 函数 ------------- ")
print("torch.zeros((2, 3, 4)):\n", torch.zeros((2, 3, 4)))
print("")

print("torch.ones((2, 3, 4)):\n", torch.ones((2, 3, 4)))
print("")

print("------------- randn 函数 ------------- ")
print("torch.randn(3, 4):\n", torch.randn(3, 4))
print("")

print("------------- tensor 函数 ------------- ")
print("torch.tensor([[3, 1, 4, 3], [6, 3, 8, 4], [9, 2, 6, 4]]):\n", torch.tensor([[3, 1, 4, 3], [6, 3, 8, 4], [9, 2, 6, 4]]))
print("")

print("------------- 1.2 运算符  ------------- ")
x = torch.tensor([1.0, 2, 4, 8])
y = torch.tensor([1, 2, 3, 4])
print("x + y: ", x + y)
print("x - y: ", x - y)
print("x * y: ", x * y)
print("x / y: ", x / y)
print("x ** y:", x ** y)
print("")

print("------------- exp 函数 ------------- ")
print("torch.exp(x): ", torch.exp(x))
print("")

print("------------- cat 函数 ------------- ")
X = torch.arange(12, dtype=torch.float32).reshape((3, 4))
Y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
print("torch.cat((X, Y), dim=0):\n", torch.cat((X, Y), dim=0))
print("torch.cat((X, Y), dim=1):\n", torch.cat((X, Y), dim=1))
print("")
print("X == Y:\n", X == Y)
print("")
print("X:\n", X)
print("X.sum():\n", X.sum())
print("X.cumsum(dim=0):\n", X.cumsum(dim=0))
print("")

print("------------- 1.3 广播机制 ------------- ")
a = torch.arange(3).reshape((3, 1))
b = torch.arange(2).reshape((1, 2))
print("a, b:\n", a, b)
print("a + b:\n", a + b)
print("")

print("------------- 1.4 索引和切片 ------------- ")
print("X[-1]:\n", X[-1])
print("X[1:3]:\n", X[1:3])
X[1, 2] = 99
print("X[1, 2] = 99:\n", X)
print("")
X[0:2, :] = 12
print("X[0:2, :] = 12:\n", X)
print("")

print("------------- 1.5 对象转换 ------------- ")
A = X.numpy()  # tensor转换成ndarray
B = torch.tensor(A)  # ndarray转换成tensor
print("type(A): ", type(A))
print("type(B): ", type(B))
print("")

a = torch.tensor([3.5])
b = torch.tensor([2, 4, 6])

print("a: ", a)
print("b: ", b)

print("a.item()  : ", a.item())
print("b.tolist(): ", b.tolist())
print("float(a)  : ", float(a))
print("int(a)    : ", int(a))
print("")

print("===================== 二、线性代数 =====================")
print("------------- 2.1 标量 ------------- ")
x = torch.tensor(3.0)
y = torch.tensor(2.0)
print("x + y, x - y, x * y, x / y, x ** y: ", x + y, x - y, x * y, x / y, x ** y)
print("")

print("------------- 2.2 向量 ------------- ")
x = torch.arange(4)
print("x: ", x)
print("x[3], len(x), x.shape: ", x[3], len(x), x.shape)
print("")

print("------------- 2.3 矩阵 ------------- ")
A = torch.arange(20).reshape(5, 4)
print("A:\n", A)
print("A.T:\n", A.T)
print("")

B = torch.tensor([[1, 2, 3], [2, 0, 4], [3, 4, 5]])
print("B:\n", B)
print("B == B.T:\n", B == B.T)
print("")

print("------------- 2.4 张量 ------------- ")
X = torch.arange(24).reshape(2, 3, 4)
print("X:\n", X)
print("")

print("------------- 2.5 张量的基本运算 ------------- ")
A = torch.arange(20, dtype=torch.float32).reshape(5, 4)
print("A:\n", A)
B = A.clone()  # 通过分配新内存，将A的一个副本分配给B
print("B:\n", B)
print("A + B:\n", A + B)
print("A * B:\n", A * B)
print("")

a = 2
X = torch.arange(24).reshape(2, 3, 4)
print("X:\n", X)
print("a: ", a)
print("a + X:\n", a + X)
print("a * X:\n", a * X)
print("")


print("------------- 2.6 聚合 ------------- ")
x = torch.arange(4, dtype=torch.float32)
print("x      : ", x)
print("x.sum(): ", x.sum())
print("A.shape: ", A.shape)
print("A.sum(): ", A.sum())
print("")

A_sum_axis1 = A.sum(axis=1)
print("A_sum_axis1      : ", A_sum_axis1)
print("A_sum_axis1.shape: ", A_sum_axis1.shape)
print("")

print("A.mean()                  : ", A.mean())
print("A.sum() / A.numel()       : ", A.sum() / A.numel())
print("A.mean(axis=0)            : ", A.mean(axis=0))
print("A.sum(axis=0) / A.shape[0]: ", A.sum(axis=0) / A.shape[0])
print("")

A_mean = A.mean(axis=1, keepdims=True)
print("A_mean      :\n", A_mean)
print("A - A_mean  :\n", A - A_mean)
print("")

print("------------- 2.7 点积 ------------- ")
y = torch.ones(4, dtype=torch.float32)
print("x               : ", x)
print("y               : ", y)
print("torch.dot(x, y) : ", torch.dot(x, y))
print("torch.sum(x * y): ", torch.sum(x * y))
print("")

print("------------- 2.8 矩阵–向量积 ------------- ")
print("torch.mv(A, x): ", torch.mv(A, x))
print("")

print("------------- 2.9 矩阵–矩阵乘法 ------------- ")
B = torch.ones(4, 3)
print("A             :\n", A)
print("A             :\n", B)
print("torch.mm(A, B):\n", torch.mm(A, B))
print("")

print("------------- 2.10 范数 ------------- ")
u = torch.tensor([3.0,  -4.0])
print("u             : ", u)
print("torch.norm(u) : ", torch.norm(u))
print("")

print("torch.abs(u).sum() : ", torch.abs(u).sum())
print("")

print("torch.norm(torch.ones((4, 9))): ", torch.norm(torch.ones((4, 9))))
print("")



print("output: done!")