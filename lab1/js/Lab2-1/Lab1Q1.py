class Node:

    def __init__(self, data = None, next = None):
        self.data = data  
        self.next = next  
 

class LinkedList:
    
    def __init__(self):
        self.head = None
 
    def insertBack(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            temp = self.head
            while (temp.next):
                temp = temp.next
            temp.next = Node(data)
            
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data)
            temp = temp.next
    
    def reverse(self):
        prev = None
        curr = self.head
        while(curr is not None):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        self.head = prev


def sortedInsert(head, llNode):
 
    temp = Node()
    curr = temp
    temp.next = head
 
    while curr.next and curr.next.data > llNode.data:
        curr = curr.next
 
    llNode.next = curr.next
    curr.next = llNode
    return temp.next
 
 
def Sort(head):
 
    res = None     
    curr = head      
 
    while curr:
        temp = curr.next
 
        res = sortedInsert(res, curr)
        curr = temp
 
    return res

    
 
 
if __name__ == '__main__':
 
    L = LinkedList()
 
    n = int(input("Enter no of elements: "))
    print("Enter List elements: ")

    for i in range(n):
        data = int(input())
        L.insertBack(data)

    print(" sorted Linked List in descending order:")
    L.head = Sort(L.head)
    L.printList()

    print(" Linked List reversed:")
    L.reverse()
    L.printList()