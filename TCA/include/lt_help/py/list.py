#!/usr/bin/python

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def makeList(*args):
    pnode = None
    phead = None
    
    for v in args:
        if pnode == None :
            pnode = ListNode(v)
            phead = pnode
        else : 
            pnode.next = ListNode(v)
            pnode = pnode.next
    return phead
    
def sizeofList(list):
    size = 0;
    pnode = list;
    while pnode != None:
        size=size+1
        pnode = pnode.next
    
    return size;


def outputList(list):
    pnode = list

    print "[",
    while pnode != None:        
        if pnode != list :
            print "->",
        print pnode.val,
        pnode = pnode.next
    print "]",


        