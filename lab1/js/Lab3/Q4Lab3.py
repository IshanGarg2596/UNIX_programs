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
            return

        L = []
        L.append(self.root)
        
        while (len(L) != 0):
            n = len(L)

            while(n > 0):
                p = L[0]
                L.pop(0)
                print(p.data, end = ' ')

                for i in range(len(p.children)):
                    L.append(p.children[i])
                n -= 1
            print()

    def treeTransform(self):
        L = self.root
        n = len(self.root.children)
        while L:
            self.subTreeTransform(L)
            L = L.children[0]
    
    def subTreeTransform(self, node):
        L = node.children[1:]
        node.children = node.children[:1]

        root = node.children[0]
        while len(L) > 0:
            root.children.append(L[0])
            root = L[0]
            L.pop(0)


if __name__ == "__main__": 
    T = Tree()

    if T.root == None:
        T.root = Node("A")
    
    T.root.add_child(Node("B"))
    T.root.add_child(Node("C"))
    T.root.add_child(Node("D"))

    T.root.children[0].add_child(Node("E"))
    T.root.children[0].add_child(Node("F"))

    T.root.children[2].add_child(Node("G"))

    T.printTree()
    T.treeTransform()

    print()
    T.printTree()    


