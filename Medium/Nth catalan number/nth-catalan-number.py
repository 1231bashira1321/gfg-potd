#User function Template for python3

class Solution:
    #Function to find the nth catalan number.
    def findCatalan(self,n):
        #return the nth Catalan number.
     if n==0:
      return 0
     f1=1
     f2=1
     for i in range(n-1):
      f1=f1*(2*n-i)
     for i in range(n):
      f2=f2*(n-i)
     return (f1//f2)%(1000000007)



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.findCatalan(n)
        
        print(res)
        

# } Driver Code Ends