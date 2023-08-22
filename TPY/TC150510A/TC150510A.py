#!/usr/bin/python
#coding=utf-8

classmates = ['Michael', 'Bob', 'Tracy']
print '01:', classmates
print '02:', 'Len   =', len(classmates)
print '03:', 'At(1) =',  classmates[0]
print '04:', 'At(-1)=',  classmates[-1]

classmates.append('Adam')
print '05:', 'add Adam:', classmates

classmates.insert(1, 'Jack')
print '06:', 'insert Jack:', classmates

classmates.pop()
print '07:', 'pop   :', classmates

classmates.pop(1)
print '08:', 'pop(1):', classmates

classmates[1] = 'Sarah'
print '09:', 'replace:', classmates

#list里面的元素的数据类型也可以不同
L = ['Apple', 123, True] 
print '10:', L

#list元素也可以是另一个list
s = ['python', 'java', L, 'scheme'] 
print '11:', s
print '12:', 'Len   =', len(s)
print '13:', 's[2][0]=', s[2][0]

# tuple一旦初始化就不能修改
classmates = ('Michael', 'Bob', 'Tracy')
print '14:', classmates
print '15:', 'Len   =', len(classmates)

t = (1,)
print '16:', 't = (1,) is tuple:', t
t = (1)
print '17:', 't = (1) is not tuple:', t

print('output: done.');