#!/usr/bin/python
# -*- coding: UTF-8 -*- 
 
import re
print(re.search('www', 'www.runoob.com').span()) # 在起始位置匹配
print(re.search('com', 'www.runoob.com').span())  # 不在起始位置匹配

line = "Cats are smarter than dogs"
 
matchObj = re.search( r'(.*) are (.*?) .*', line, re.RegexFlag.M|re.RegexFlag.I)
 
if matchObj:
    print ("matchObj.group() : ", matchObj.group())
    print ("matchObj.group(1) : ", matchObj.group(1))
    print ("matchObj.group(2) : ", matchObj.group(2))
else:
    print ("No match!!")

print('output: done.');