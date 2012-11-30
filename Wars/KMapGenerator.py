from array import *

numOfNodes = 100
numOfEdgesPerNode = 500

output = []

for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(i != j):
            output[i].append(numOfEdgesPerNode)
        else:
            output[i].append(0)

file = open('output-k-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')

file.close
