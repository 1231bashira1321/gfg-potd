#User function Template for python3

class Solution:
    
    #Function to check if two strings are isomorphic.
    def areIsomorphic(self,str1,str2):
     n1=len(str1)
     n2=len(str2)
     if n1 !=n2:
      return False
     d1={}
     d2={}
     for i in range (n1):
      if d1.get(str1[i],0)==0:
        if d2.get(str2[i],0)==0:
          d1[str1[i]]=str2[i]
          d2[str2[i]]=1
        else:
          return False
      else:
        if d1[str1[i]] !=str2[i]:
         return False
     return True





#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys
from collections import defaultdict

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        ob = Solution()
        if(ob.areIsomorphic(s,p)):
            print(1)
        else:
            print(0)
# } Driver Code Ends