class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        

class Tree:
    def __init__(self):
        self.root = None
    

# Function to  print tree
def printTree(root):
    h = height(root)
    for i in range(1, h+1):
        printCurrentLevel(root, i)
        print()
 
 
# Print nodes at a current level
def printCurrentLevel(root, level):
    if root is None:
        return
    if level == 1:
        print(root.data, end= " ")
    elif level > 1:
        printCurrentLevel(root.left, level-1)
        printCurrentLevel(root.right, level-1)
 
 
 
# compute the height of tree
def height(node):
    if node is None:
        return 0
    else:
        
        lheight = height(node.left)
        rheight = height(node.right)

        if lheight > rheight:
            return lheight+1
        else:
            return rheight+1




# checks if node is leaf or not 
def isLeaf(node):
    return node.left is None and node.right is None
 
# applies the arithmetic to operations to data
def operate(op, x, y):
    if op == '+':
        return x + y
    if op == '-':
        return x - y
    if op == '*':
        return x * y
    if op == '/':
        return x / y
 
# evaluate expression 
def evaluate(root):
 
    if root is None:
        return 0
 
    if isLeaf(root):
        return float(root.data)
 
    x = evaluate(root.left)
    y = evaluate(root.right)
 
    
    return operate(root.data, x, y)


if __name__ == "__main__":
    
    T = Tree()

    if T.root == None:
        T.root = Node("/")

    T.root.left = Node("*")
    T.root.right = Node("+")

    T.root.left.left = Node("+")
    T.root.left.right = Node("-")

    T.root.right.left = Node("+")
    T.root.right.right = Node("*")

    T.root.left.left.left = Node("5")
    T.root.left.left.right = Node("2")

    T.root.left.right.left = Node("2")
    T.root.left.right.right = Node("1")

    T.root.right.left.left = Node("2")
    T.root.right.left.right = Node("9")

    T.root.right.right.left = Node("-")
    T.root.right.right.right = Node("8")

    T.root.right.right.left.left = Node("-")
    T.root.right.right.left.right = Node("1")

    T.root.right.right.left.left.right = Node("2")
    T.root.right.right.left.left.left = Node("7")


    printTree(T.root)
    print("Answer is: ", evaluate(T.root))

