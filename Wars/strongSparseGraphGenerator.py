from random import *
numOfNodes = 6
output = []
for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(j > i):
            if(randint(0,25) == 5):
                output[i].append(randint(300,500))
            else:
                output[i].append(1)
        elif(i > j):
            output[i].append(output[j][i])
        else:
			output[i].append(0)
file = open('output-strong-sparse-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')
file.close
