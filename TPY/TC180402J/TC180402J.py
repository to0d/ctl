#!/usr/bin/python3

import _thread
import time

# 为线程定义一个函数
def my_thread( threadName, delay):
    count = 0
    while count < 2:
        time.sleep(delay)
        count += 1
        print ("%s" % ( threadName ))

# 创建两个线程
try:
    _thread.start_new_thread( my_thread, ("Thread-1", 1, ) )
    _thread.start_new_thread( my_thread, ("Thread-2", 2, ) )
except:
    print ("Error: 无法启动线程")

time.sleep(5)

print('output: done.');