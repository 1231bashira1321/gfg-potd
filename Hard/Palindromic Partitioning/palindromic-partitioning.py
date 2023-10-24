#User function Template for python3
import sys
class Solution:
    def ispalindrome(self,i,j,s):
     while i<j:
      if s[i] !=s[j]:
       return False
      i+=1
      j-=1
     return True
     
    def f(self,i,n,s,dp):
     if i==n:
      return 0
     if dp[i]==-1:
      mini=sys.maxsize
      for j in range(i,n):
       if self.ispalindrome(i,j,s)==True:
        count=1+self.f(j+1,n,s,dp)
        mini=min(mini,count)
      dp[i]=mini
     return dp[i]
     
    def palindromicPartition(self, string):
     s=string
     n=len(string)
     dp=[0 for i in range(n+1)]
     for i in range(n-1,-1,-1):
      mini=sys.maxsize
      for j in range(i,n):
       if self.ispalindrome(i,j,s)==True:
        count=1+dp[j+1]
        mini=min(mini,count)
      dp[i]=mini
     return dp[0]-1




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends