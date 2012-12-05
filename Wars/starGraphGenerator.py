from random import *
numOfNodes = 50
numOfEdgesPerNode = 100
output = []
for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(i == 0 and j != 0):
            output[i].append(numOfEdgesPerNode)
        elif(j == 0 and i != 0):
            output[i].append(output[j][i])
        else:
			output[i].append(0)
file = open('output-star-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')
file.close
