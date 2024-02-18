#!/usr/bin/python3

import torch

print("------------------ PyTorch的安装 ------------------ ")
print("torch.__version__: ", torch.__version__)
print("")

print("------------------ 数据操作  ------------------ ")
x = torch.arange(12)
x1 = torch.arange(2, 12, 2)
print("x : ", x)
print("x1: ", x1)                   #长为2

print("")
print("x.shape   : ", x.shape)      #张量的shape属性
print("x.numel() : ", x.numel())
print("x.size()  : ", x.size())
print("")

print("------------------ reshape 函数  ------------------ ")
x=x.reshape(2, 6)
print("x : ", x)
x=x.reshape(-1, 4)
print("x : ", x)
print("")

print("------------------ zeros/ones 函数 ------------------ ")
print("torch.zeros((2, 3, 4)):\n", torch.zeros((2, 3, 4)))
print("")

print("torch.ones((2, 3, 4)):\n", torch.ones((2, 3, 4)))
print("")


print("output: done!")