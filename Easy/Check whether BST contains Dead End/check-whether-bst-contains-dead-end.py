# Your task is to complete this function
# function should return true/false or 1/0
import sys
class Solution:
 def f(self,root,mini,maxi):
  if root==None:
   return False
  if root.left==None and root.right==None:
   if root.data-mini-1<=0 and maxi-root.data-1<=0:
    return True
  return self.f(root.left,mini,root.data) or self.f(root.right,root.data,maxi)
 
 def isDeadEnd(self,root):
    # Code here
  return self.f(root,1,sys.maxsize)




#{ 
 # Driver Code Starts

class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None

def insert(root, node):
    if root is None:
        root = node
    else:
        if root.data < node.data:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        elif root.data == node.data:
            return
        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)

def traverseInorder(root):
    if root is not None:
        traverseInorder(root.left)
        print(root.data, end=" ")
        traverseInorder(root.right)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        root = None
        for j in arr:
            if root is None:
                root = Node(j)
            else:
                insert(root, Node(j))
                
        ob = Solution()
        if ob.isDeadEnd(root):
            print(1)
        else:
            print(0)
# Contributed by: Harshit Sidhwa

# } Driver Code Ends