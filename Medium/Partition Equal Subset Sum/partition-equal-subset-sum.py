# User function Template for Python3
#isme empty set ko bhi consider krna h
class Solution:
 def equalPartition(self, N, arr):
        # code here
     s=sum(arr)
     if s%2 !=0:
      return False
     prev=[False for i in range(s//2+1)]
     curr=[False for i in range(s//2+1)]
     prev[0]=curr[0]=True
     if arr[0]<=s//2:
      prev[arr[0]]=True
     for i in range(1,N):
      for target in range((s//2)+1):
       take=False
       if arr[i]<=target:
        take=prev[target-arr[i]]
       notTake=prev[target]
       curr[target]=take or notTake
      prev=[curr[i] for i in range((s//2)+1)]
     return prev[s//2]
     



#{ 
 # Driver Code Starts
# Initial Template for Python3

import sys
input = sys.stdin.readline
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for it in range(N):
            arr[it] = int(arr[it])
        
        ob = Solution()
        if (ob.equalPartition(N, arr) == 1):
            print("YES")
        else:
            print("NO")
# } Driver Code Ends