# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class  Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def  cloneGraph(self, node):
        if  not  node:
            return  None
        dic =  {}
        Node =  UndirectedGraphNode
        clonedFirstNode =  Node(node.label)
        dic[node.label] =  clonedFirstNode
        def  dfs(x, clonedX):
            for  y in  x.neighbors:
                if  y.label not  in  dic:
                    clonedY =  Node(y.label)
                    dic[y.label] =  clonedY
                    dfs(y, dic[y.label])
                clonedX.neighbors.append(dic[y.label])
        dfs(node, clonedFirstNode)
        return  clonedFirstNode
                
