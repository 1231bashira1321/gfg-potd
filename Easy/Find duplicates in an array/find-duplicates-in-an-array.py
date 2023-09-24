class Solution:
    def duplicates(self, arr, n): 
    #  for i in range(n):
    #   arr[i]=arr[i]+1
     ans=[]
     for i in range(n):
      index=arr[i]%n
      arr[index]=arr[index]+n
     for i in range(n):
      if arr[i]/n>=2:
       ans.append(i)
     if len(ans)==0:
      ans.append(-1)
     ans.sort()
     return ans




#{ 
 # Driver Code Starts
if(__name__=='__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i,end=" ")
        print()



# } Driver Code Ends