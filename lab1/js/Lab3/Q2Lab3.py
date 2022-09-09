class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, obj):
        self.children.append(obj)

class Tree:
    def __init__(self):
        self.root = None

    def printTree(self):
        if (self.root == None):
            return;

        L = []
        L.append(self.root)
        
        while (len(L) != 0):
            n = len(L)

            while(n > 0):
                p = L[0]
                L.pop(0);
                print(p.data, end = ' ')

                for i in range(len(p.children)):
                    L.append(p.children[i])
                n -= 1
            print()
 

if __name__ == "__main__": 
    T = Tree()

    if T.root == None:
        T.root = Node("/user/rt/courses")

    T.root.add_child(Node("cs016/"))
    T.root.add_child(Node("cs252/"))
    
    T.root.children[0].add_child(Node("grades"))
    T.root.children[0].add_child(Node("homeworks/"))
    T.root.children[0].add_child(Node("programs/"))
       
    T.root.children[1].add_child(Node("projects/"))
    T.root.children[1].add_child(Node("grades"))

    
    T.root.children[0].children[1].add_child(Node("hw1"))
    T.root.children[0].children[1].add_child(Node("hw2"))
    T.root.children[0].children[1].add_child(Node("hw3"))

    T.root.children[0].children[2].add_child(Node("pr1"))
    T.root.children[0].children[2].add_child(Node("pr2"))
    T.root.children[0].children[2].add_child(Node("pr3"))

    T.root.children[1].children[0].add_child(Node("papers/"))
    T.root.children[1].children[0].add_child(Node("demos/"))

    T.root.children[1].children[0].children[0].add_child(Node("buylow"))
    T.root.children[1].children[0].children[0].add_child(Node("sellhigh"))

    T.root.children[1].children[0].children[1].add_child(Node("market"))

    T.printTree()
