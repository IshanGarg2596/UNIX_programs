if __name__  == "__main__":
    n = int(input("Enter no of elements: "))

    List = []
    for i in range(n):
        List.append(int(input()))
    

    n = len(List)
    dp = [1] * n

    for i in range(n):
        for j in range(i):
            if List[i] > List[j] and dp[i] < dp[j] + 1:
                dp[i] = dp[i] + 1 

    print("Largest increasing subsequence is of length", max(dp))