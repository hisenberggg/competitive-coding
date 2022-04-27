class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def createBinaryTree(self, desc):
        return TreeNode(val=3)
if __name__=='__main__':
    desc = [[1,2,3],[4,5,6]]
    a = Solution()
    op = a.createBinaryTree(desc)
    print(op.val)