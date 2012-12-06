from random import *
numOfNodes = 100
numOfEdgesPerNodeCluster = 100
numOfEdgesPerNodeConn = 1
output = []
for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(j > i and (i/10) + 1 == (j/10)  +1):
            output[i].append(numOfEdgesPerNodeCluster)
        elif(j > i):
            if(randint(0,100) == 42):
                output[i].append(numOfEdgesPerNodeConn)
            else:
                output[i].append(0)
        elif(i > j):
            output[i].append(output[j][i])
        else:
			output[i].append(0)
file = open('output-cluster-weak-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')
file.close
