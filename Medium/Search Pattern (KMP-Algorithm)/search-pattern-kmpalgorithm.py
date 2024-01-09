#User function Template for python3

class Solution:
    def search(self, pat, txt):
     ans=[]
     lp=len(pat)
     ls=len(txt)
     if lp>ls: return -1
    #  building lps array which takes O(n)-tc and O(N) to build
     lps=[0 for i in range(lp)]
     lps[0]=0
     i,j=1,0
     while i<lp:
      if pat[i]==pat[j]:
       lps[i]=j+1
       j+=1
       i+=1
      else:
       if j!=0:
        j=lps[j-1]
       else:
        lps[i]=0
        i+=1
     i=0
     j=0
     while i<ls:
      if txt[i]==pat[j]:
       i+=1
       j+=1
       if j==lp:
        ans.append(i-j+1)
        j=lps[j-1]
      else:
       if j!=0:
        j=lps[j-1]
       else:
        j=0
        i+=1
     return ans





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans)==0:
            print(-1,end="")
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends