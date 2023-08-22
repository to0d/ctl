#!/usr/bin/python
#coding=utf-8

print '1: Hello world'
print '2: I\'m ok'
print '3: I\'m learning\nPython.'
print '4: \\\n\\'
print '5: \\\t\\'
print r'6: \\\t\\'
print '''7:line1
... line2
... line3'''
print r'''8:line1
... line2
... line3'''

print '9: The quick brown fox', 'jumps over', 'the lazy dog'

print "not False =", not False
print "not True  =", not True

print "True and False =", True and False
print "True or False  =", True or False

age = 10
if age >= 18:
    print '10: test if , err'
else:
    print '10: test if , ok'
    
_null=None
if _null == None:
    print "11: Test None: OK"

a = 123     # a是整数
print "12:", a
a = 'ABC'   # a变为字符串
print "13:", a

print "14:", "Test function ord: ", ord('A')
print "15:", "Test function chr: ", chr(65)
print "16:", '中文'

print "17: format with %  :", 'Hi, %s, you have $%d.' % ('Michael', 1000000)
print "18: format without%:", 'Hi, %s, you have $%d.' 


print('output: done.');

