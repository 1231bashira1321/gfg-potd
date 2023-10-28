from math import log2

class Solution:
    def is_bleak(self, n):
        bits = int(log2(n))+1
        
        for e in range(n-bits, n+1):
            if e + bin(e).count('1') == n:
                return 0
        return 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.is_bleak(n)
		print(ans)

# } Driver Code Ends