#User function Template for python3

class Solution:
       def minimumNumberOfDeletions(self,S):
        n = len(S)
        res = [[0 for i in range(n)] for j in range(n)]
        for length in range(2, n+1): # starting with length 2 as strings of length 1 will always need only 1 operation 
            for i in range(n-length+1):
                j = i + length - 1
                if S[i] == S[j]:
                    res[i][j] = res[i+1][j-1] # operations required are same as when we disard these 2 same characters. 
                else:
                    res[i][j] = min(res[i+1][j], res[i][j-1]) + 1
        return res[0][n-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=input()

        ob = Solution()
        print(ob.minimumNumberOfDeletions(S))
# } Driver Code Ends