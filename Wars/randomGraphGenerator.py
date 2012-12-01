from random import *
numOfNodes = randint(2,100)
output = []
for i in range(numOfNodes):
    output.append([])
    for j in range(numOfNodes):
        if(j > i):
            output[i].append(randint(0,500))
        elif(i > j):
            output[i].append(output[j][i])
        else:
			output[i].append(0)
file = open('output-random-graph.txt', 'w') #NOTE: Python will overwite whatever file is here automatically. Be sure to save the file if you would like to keep it
file.write(str(numOfNodes) + '\n')
for i in range(numOfNodes):
    for j in range(numOfNodes):
        file.write((str(output[i][j]) + ' '))
    file.write('\n')
file.close
