#!/usr/bin/python3

import torch
import torch.nn as nn
import torch.optim as optim

# 定义一个简单的模型
class SimpleModel(nn.Module):
    def __init__(self):
        super(SimpleModel, self).__init__()
        self.fc = nn.Linear(10, 5)
        self.relu = nn.ReLU()

    def forward(self, x):
        x = self.fc(x)
        x = self.relu(x)
        return x


# 创建模型实例
model = SimpleModel()

# 定义损失函数和优化器
criterion = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr=0.01)

# 定义训练轮数
num_epochs = 10  # 例如，设置为10轮

# 创建一个简单的输入张量
inputs = torch.randn(1, 10)  # 例如，创建一个大小为 (1, 10) 的随机张量作为输入数据
print("输入数据示例：", inputs)

# 创建一个简单的目标张量
targets = torch.randn(1, 5)  # 例如，创建一个大小为 (1, 5) 的随机张量作为目标值
print("目标值示例：", targets)

# 训练模型
for epoch in range(num_epochs):
    optimizer.zero_grad()
    outputs = model(inputs)
    loss = criterion(outputs, targets)
    loss.backward()
    optimizer.step()

# 示例：生成执行跟踪
traced_script_module = torch.jit.trace(model, inputs)

# 保存执行跟踪模型
traced_script_module.save("traced_model.pt")

# 打印计算图
print(traced_script_module.graph)

output = traced_script_module(inputs)
print("output", output)


