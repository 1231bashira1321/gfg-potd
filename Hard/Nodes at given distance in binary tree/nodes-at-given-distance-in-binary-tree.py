from collections import deque

class Solution:
    
    def helper(self, node, target):
        if node.data==target and not self.target_node:
            self.target_node = node
        
        if node.left:
            self.ancestor[node.left] = node
            self.helper(node.left, target)
        
        if node.right:
            self.ancestor[node.right] = node
            self.helper(node.right, target)

    def KDistanceNodes(self, root, target, k):
        self.ancestor = {}
        self.target_node = None
        self.helper(root, target)

        q = deque()
        q.append([self.target_node, 0])
        res = []
        visited = {self.target_node}

        while q:
            node, distance = q.popleft()

            if distance==k:
                res.append(node.data)
                continue

            if self.ancestor.get(node, None):
                if self.ancestor[node] not in visited:
                    q.append([self.ancestor[node], distance+1])
                    visited.add(self.ancestor[node])
            
            if node.left and node.left not in visited:
                q.append([node.left, distance+1])
                visited.add(node.left)
            
            if node.right and node.right not in visited:
                q.append([node.right, distance+1])
                visited.add(node.right)
        
        return sorted(res)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque

# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree
def buildTree(s):
    # Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root

if __name__ == "__main__":
    x = Solution()
    t = int(input())
    for _ in range(t):
        line = input()
        target=int(input())
        k=int(input())

        root = buildTree(line)
        res = x.KDistanceNodes(root,target,k)
        
        for i in res:
            print(i, end=' ')
        print()

# } Driver Code Ends