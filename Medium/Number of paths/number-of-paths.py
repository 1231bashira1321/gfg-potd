class Solution:
    def numberOfPaths(self, rows, columns):
        num_paths = 1
        MOD = 10**9 + 7
        for i in range(rows - 1):
            num_paths = (num_paths * (i + columns)) % MOD
            temp = pow(i + 1, MOD - 2, MOD)
            num_paths = (num_paths * temp) % MOD
        
        return num_paths


#{ 
 # Driver Code Starts
#Initial Template for Python 3

        

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        M, N = map(int, input().split())
        ans = ob.numberOfPaths(M, N)
        print(ans)




# } Driver Code Ends