#!/usr/bin/python3

import torch
import torch.nn as nn
import torch.fx as fx

print("=================================================================")
# 定义一个简单的PyTorch模型
class Model(torch.nn.Module):
    def forward(self, x):
        return x * 2

model = Model()

from torch.fx import symbolic_trace

# Symbolic tracing frontend - captures the semantics of the module
symbolic_traced : torch.fx.GraphModule = fx.symbolic_trace(model)

# High-level intermediate representation (IR) - Graph representation
print("FX IR:")
print(symbolic_traced.graph)
print("FX Graph:")
symbolic_traced.graph.print_tabular()

print("=================================================================")
import dis

def add(x, y):
    return x + y

print("Bytecode:")
print(dis.dis(add))



## 使用TorchDynamo来优化model
#optimized_model = dynamo.optimize(model)
#
## 现在可以使用优化后的model
#x = torch.tensor([1.0])
#y = optimized_model(x)
#
#symbolic_traced2 : torch.fx.GraphModule = symbolic_trace(optimized_model)
#print("symbolic_traced2:")
#print(symbolic_traced2.graph)