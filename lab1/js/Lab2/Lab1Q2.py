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


if __name__ == '__main__':
    L1 = [941, 913, 16, 882, 94, 96, 794, 742, 442, 209, 734, 43]
    L2 = [869, 13, 315, 343, 477, 420, 244, 702, 944, 829, 86, 44]
    L3 = [981, 971, 728, 82, 546,152, 230,184,102, 21,174, 178]

    LL1 = LinkedList()
    LL2 = LinkedList()
    LL3 = LinkedList()

    for i in range(len(L1)):
        LL1.insertBack(L1[i])
        LL2.insertBack(L2[i])
        LL3.insertBack(L3[i])

    L = LinkedList()
    curr1 = LL1.head
    curr2 = LL2.head
    curr3 = LL3.head
    i = 0
    while (curr1 and curr2 and curr3):
        if i%2 == 0:
            min = curr1 if curr1.data < curr2.data else curr2
            min = curr3 if curr3.data < min.data else min
            L.insertBack(min.data)
        else:
            max = curr1 if curr1.data > curr2.data else curr2
            max = curr3 if curr3.data > max.data else max
            L.insertBack(max.data)
        curr1 = curr1.next
        curr2 = curr2.next
        curr3 = curr3.next
        i += 1 
    
    print("The required List is:")
    L.printList()