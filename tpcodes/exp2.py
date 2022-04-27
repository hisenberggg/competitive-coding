graph2=dict()
visited = [] 
queue = []     

def bfs(visited, graph, node,endnode): 
  visited.append(node)
  queue.append(node)

  while queue:          
    m = queue.pop(0)
    print (m, end = " ")
    if m==endnode: 
      break


    for neighbour in graph2[m]:
      if neighbour not in visited:
        visited.append(neighbour)
        queue.append(neighbour)

# Driver Code

g=int(input("Enter number of nodes "))
nodes=[]
graph2=dict()
for g in range(g):
  
  gname=input("Enter Node name ")
  nodes.append(gname)
  b= input("Enter nodes that "+gname+" has edges to ")
  b=b.split()
  graph2[gname]=b

startnode= input("Enter the start node ")
endnode=input("Enter Destination node ")



bfs(visited, graph2, startnode,endnode)