#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self,arr, n, s):
     ans=[-1]
     if s==0:
      return ans
     su=0
     start=0
     for end in range(n):
      su+=arr[end]
      while su>s:
       su=su-arr[start]
       start+=1
      if su==s: 
       ans[0]=start+1
       ans.append(end+1)
       return ans
     return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends