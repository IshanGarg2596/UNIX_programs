if __name__ == "__main__":
    A = []
    B = []

    n = int(input("Enter no of elements"))

    print("Enter List A: ")
    
    for i in range(n):
        e = abs(int(input()))
        A.append(e)

    print("Enter List B: ")
    for i in range(n):
        e = abs(int(input()))
        B.append(e)

    A.sort()
    B.sort()

    sum = 0
    for i in range(n):
        sum += abs(A[i] - B[i])

    print(sum)

    
