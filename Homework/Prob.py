#!/usr/bin/python

# The Algorithm Design Manual
# 8-14
# The traditional ...

numberOfGames = raw_input("The Number of Games:")
scoreRequired = raw_input("The score required to win:")
Bw = raw_input("Probablity to win with black:")
Bd = raw_input("Probablity to draw with black:")
Bl = raw_input("Probablity to loose with black:")
Ww = raw_input("Probablity to win with white:")
Wd = raw_input("Probablity to draw with white:")
Wl = raw_input("Probablity to loose with white:")

print "Number of Games:",numberOfGames
print "Required:",scoreRequired
print "Bw:",Bw
print "Bd:",Bd
print "Bl:",Bl
print "Ww:",Ww
print "Wd:",Wd
print "Wl:",Wl

try:
    numberOfGames = int( numberOfGames )
    scoreRequired = float( scoreRequired )
    Bw = float( Bw )
    Bd = float( Bd )
    Bl = float( Bl )
    Ww = float( Ww )
    Wd = float( Wd )
    Wl = float( Wl )
except:
    print "Invalid input."

# init the enums for isBlack or isWhite
isBlack = 0
isWhite  = 1

# init table to zeros
table = list()

for each in range(0, numberOfGames + 1 ) :
    table.append([0,0])

for col in table:
    for each in range(0, (numberOfGames* 2) + 1):
        col.append(0)

# the probablity of getting a zero with zero games is 1
table[0][2] = 1

for col in range(1, numberOfGames + 1 ):
    for row in range(2, (numberOfGames*2) + 3 ) :
        # calc cell
        if col % 2 == isBlack:
            table[col][row] =  ( Bw * table[col - 1][row - 2] 
                               + Bd * table[col - 1][row - 1] 
                               + Bl * table[col - 1][row] )

        if col % 2 == isWhite:
            table[col][row] =  ( Ww * table[col - 1][row - 2] 
                               + Wd * table[col - 1][row - 1] 
                               + Wl * table[col - 1][row] )


# traceback
totalProbablity = 0
for each in range( int(scoreRequired * 2 + 2), (numberOfGames*2) + 3):
    totalProbablity += table[numberOfGames][each]

print totalProbablity
