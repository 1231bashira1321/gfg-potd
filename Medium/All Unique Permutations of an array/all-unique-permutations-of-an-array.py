class Solution:
    def uniquePerms(self, arr, n):
        # code here 
        res = set()
        def backtrack(temp_arr, vis):
            if len(temp_arr) == n:
                res.add(tuple(temp_arr))
                return
            for i in range(n):
                if vis[i] == 0:
                    temp_arr.append(arr[i])
                    vis[i]=1
                    backtrack(temp_arr,vis)
                    temp_arr.pop()
                    vis[i] = 0
        vis = [0]*n
        backtrack([],vis)
        res = list(res)
        res.sort()
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n=int(input())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        res = ob.uniquePerms(arr,n)
        for i in range(len(res)):
            for j in range(n):
                print(res[i][j],end=" ")
            print()
# } Driver Code Ends