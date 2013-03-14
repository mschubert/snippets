import networkx as nx
import numpy as np

aff = np.loadtxt("affinity_NARM.csv", delimiter=",", dtype=str)
aff_float = aff[1:,1:].astype('float')
aff_sym = 0.5 * (aff_float + aff_float.transpose())
names = aff[0,1:]

graph = nx.from_numpy_matrix(1-aff_sym)
matching = nx.algorithms.max_weight_matching(graph)

weight=0
for k,v in matching.items():
    print(names[k], names[v], aff_sym[k,v])
    weight += aff_sym[k,v]

#(' Cerone Luca', 'Menden Michael', 0.29999999999999999)
#('Cokelaer Thomas', 'Iorio Francesco', 0.40000000000000002)
#('Costa Vitor', 'MacNamara Aidan', 0.20000000000000001)
#('Eduati Federica', 'Goncalves Emanuel', 0.59999999999999998)
#('Faura Marti Bernardo', 'Schubert Michael', 0.5)
#('Terfve Camille', 'Venditti Roberto', 0.0)
#
#total_weight=2
