from numpy import arange, genfromtxt
import numpy as np
import matplotlib.pyplot as plt
import networkx as nx
import sys

def get_labels(fname):
    f = open(fname,"r")
    header = f.readline()
    header = header[:-1]
    labels = header.split(',')
    labels = labels[1:]
    # print(labels)
    return labels

def make_label_dict(labels):
    l = {}
    for i, label in enumerate(labels):
        l[i] = label
    return l

def show_graph(adj, mylabels):
    rows, cols = np.where(adj==1)
    edges = zip(rows.tolist(),cols.tolist())
    
    layers = get_layers(rows, cols, adj)
    pos ={}
    countlayers  = {}
    for layer in layers.values():
        countlayers[layer] = []
        for i , l in layers.items():
            if l == layer:
                countlayers[layer].append(i)
    #print(countlayers)
    for layer, list in countlayers.items():
        l = len(list)
        x = 0 - len(list)/2
        for item in list:
            pos[item] = (x, layer)
            x = x + 1

    G = nx.Graph()

    G.add_edges_from(edges)
    nodes = arange(int(np.shape(adj)[0]))
    nx.draw_networkx(G, pos, nodelist=nodes,labels = mylabels ,with_labels=True, node_color='#c4daef')
    plt.show()
    plt.close()
    
def get_layers(rows, cols, adj):
    layers = {}
    array = np.array(adj)
    for i in arange(array.shape[0]):
       if (list.count(cols.tolist(), i) == 0):
           layers[i] = 0
    while len(layers) < array.shape[0]:
        temp_layers = {}
        for j in layers:
            for i in arange(array.shape[0]):
                if (array[j,i]):
                    temp_layers[i] = layers[j] + 1
        layers.update(temp_layers)
    #print(layers)
    return layers

mydata = genfromtxt(sys.argv[1], delimiter=',')
adjacency = mydata[1:,1:]

show_graph(adjacency,make_label_dict(get_labels(sys.argv[1])))
sys.exit()
