class Solution:
    def transitiveClosure(self, N, graph):
        # code here
        def dfs(start):
            if start in visited:
                return
            visited.add(start)
            for nei in range(len(graph[start])):
                if graph[start][nei] == 1:
                    dfs(nei)

        res = [[0]*N for _ in range(N)]
        for start in range(len(graph)):
            visited = set()
            dfs(start)
            for junction in visited:
                res[start][junction] = 1
        
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        graph = []
        for i in range(0,N):
            graph.append([int(j) for j in input().split()])
        ob = Solution()
        ans = ob.transitiveClosure(N, graph)
        for i in range(N):
            for j in range(N):
                print(ans[i][j], end = " ")
            print()
# } Driver Code Ends