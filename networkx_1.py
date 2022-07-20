import networkx as nx
import matplotlib.pyplot as plt
import csv
fig = plt.figure()
G = nx.Graph()
G.add_nodes_from([1,2,3,4,5,6])
G.add_edges_from([(1,2),(1,5),(2,3),(2,5),(3,4),(4,5),(2,6),(4,6)])
G.add_weighted_edges_from([(1,2,3),(1,5,2),(2,3,4),(2,5,2),(3,4,6),(4,5,1),(2,6,1),(4,6,2)])
pos = nx.spring_layout(G, k=0.7)
edge_labels = {(i,j): w['weight'] for i,j,w in G.edges(data=True)}
nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
nx.draw_networkx(G,pos,with_labels=True,alpha=0.5)



plt.axis("off")
plt.show()
fig.savefig("daiku.png")