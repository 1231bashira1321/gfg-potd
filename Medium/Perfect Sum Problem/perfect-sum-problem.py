#User function Template for python3
import math
class Solution:
    # def f(self,arr,n,target,dp):
    #  if n==0:
    #   if target==0 and arr[0]==0:
    #   return 2
    #   if target==0 or arr[0]==target:
    #   return 1
    #   return 0
    #  if dp[n][target]==-1:
    #   take=0
    #   if arr[n]<=target:
    #   take=self.f(arr,n-1,target-arr[n],dp)
    #   nt=self.f(arr,n-1,target,dp)
    #   dp[n][target]=take+nt
    #  return dp[n][target]
     
    def perfectSum(self, arr, n, sum):
        # code here
     dp=[[0 for i in range(sum+1)]for i in range(n+1)]
     if arr[0]==0:
      dp[0][0]=2
     else:
      dp[0][0]=1
     if arr[0]<=sum and arr[0]!=0:
      dp[0][arr[0]]=1
     for ind in range(1,n):
      for target in range(sum+1):
       take=0
       if arr[ind]<=target:
        take=dp[ind-1][target-arr[ind]]
       nt=dp[ind-1][target]
       dp[ind][target]=take+nt
     return dp[n-1][sum]%(pow(10,9)+7)




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,sum = input().split()
		n,sum = int(n),int(sum)
		arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.perfectSum(arr,n,sum)
		print(ans)

# } Driver Code Ends