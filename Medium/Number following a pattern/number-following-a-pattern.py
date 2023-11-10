class Solution:
    def printMinNumberForPattern(self,S):
        
        result=[]
        stack=[]
        num=1
        for c in S:
            if c == "D":
                stack.append(num)
                num+=1
            else:
                stack.append(num)
                num+=1
                # convert to str and reverse stack
                # add to result and clean
                result += [str(i) for i in stack][::-1]
                stack = []
                    
        
        stack.append(num)
        result += [str(i) for i in stack][::-1]
            
        return int(''.join(result))

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        print(ob.printMinNumberForPattern(S))
# } Driver Code Ends