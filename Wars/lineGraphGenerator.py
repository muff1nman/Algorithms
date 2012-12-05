from random import *
numOfNodes = 50
numOfEdgesPerNode = 100
output = []
for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(j == i + 1):
            output[i].append(numOfEdgesPerNode)
        elif(i-1 == j):
            output[i].append(output[j][i])
        else:
			output[i].append(0)
file = open('output-line-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')
file.close
