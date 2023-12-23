#User function Template for python3


class Solution:
    
    #Function to find all elements in array that appear more than n/k times.
    def countOccurence(self,arr,n,k):
        #Your code here
     d={}
     c=0
     n=len(arr)
     for i in range(n):
      d[arr[i]]=d.get(arr[i],0)+1
     x=int(n//k)
     for i in range(len(arr)):
      if d.get(arr[i],0) >x:
       del d[arr[i]]
       c+=1
     return c





#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math



def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=list(map(int,input().split()))
            
            K=int(input())
            
            print(Solution().countOccurence(A, N, K))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends