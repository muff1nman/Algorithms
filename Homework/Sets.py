#!/usr/bin/python

# Returns a subset of S called Q such that all memebers of Q add to T. else
# returns an empty set

def findSetUsingT( T, fullSet ):
    print "Try:",fullSet," with T:",T

    oneLess = fullSet.copy()
    numRemoved = oneLess.pop()

    if numRemoved == T:
        return {numRemoved}

    if ( len(oneLess) == 0 ):
        return oneLess

    Aset = findSetUsingT( T, oneLess )

    Bset = findSetUsingT( T - numRemoved, oneLess )

    if len(Aset) != 0 :
        return Aset

    if len(Bset) != 0 :
        Bset.add( numRemoved )
        print "Save:",numRemoved
        return Bset

    return set()

def findSetUsingT2( T, fullSet ):
    print "Try:",fullSet," with T:",T
    
    if len(fullSet) == 0 :
        return 0

    oneLess = fullSet.copy()
    numRemoved = oneLess.pop()


    if numRemoved == T :
        return numRemoved

    if numRemoved > T:
        return findSetUsingT2( T, oneLess)

    maxA = findSetUsingT2( T - numRemoved, oneLess )

    maxB = findSetUsingT2( T, oneLess )

    if (maxA + numRemoved) > maxB:
        return maxA + numRemoved
    else:
        return maxB

class Reference:
    INSET = 1
    NOTINSET = 2
    BASE = 0
    
class DynamicTable:

    table = []
    currentNumber = 0
    currentColumn = 0
    currentRow = 0

    def initTable(self):
        for each in range(0,T+1):
            self.table.append([])

    def __init__ (self, someSet, T):
        self.rowSize = len(someSet)
        self.set = someSet
        self.original = someSet
        self.T = T
        self.initTable()
        for each in someSet:
            self.pushColumnZeros()

    def run( self ):
        self.incrementCol()
        while ( self.hasNextCol() ):
            while ( self.hasNextCell() ) :
                self.calcCell( self.currentRow )
                self.incrementCell()
            self.incrementCol()


    def getSet(self):
        return self.traceback( self.T, self.rowSize, self.T )

    def traceback( self, row, col, T ):
        print "Row:",row,"col:",col
        if self.table[row][col][1] == Reference.BASE:
            return {}
        if self.table[row][col][1] == Reference.NOTINSET:
            return self.traceback( row, col - 1 )
        if self.table[row][col][1] == Reference.INSET:
            a = { self.original[col + 1] }
            return a & self.traceback( T - self.original[col + 1] , col - 1 )

    
    def getTable(self):
        return self.table

    def pushColumnZeros( self ):
        for each in self.table:
            each.append([0,0])

    def incrementCol(self):
        """Setup for the next column"""
        self.currentColumn += 1
        print self.currentColumn
        self.currentNumber = self.set[ self.currentColumn - 1 ]

    def getMaxOf( self, T ):
        # TODO check T is zero indexed
        return self.table[T][self.currentColumn - 1][0]

    def incrementCell( self ):
        self.currentRow += 1

    def hasNextCol( self ):
        return self.currentColumn < len(self.set)

    def hasNextCell( self ):
        return self.currentRow <= self.T

    def calcCell( self, T):
        if self.currentNumber > T:
            # this number can't be in the set at this T, copy from left
            self.table[self.currentRow][self.currentColumn] = [self.getMaxOf( self.currentRow ),
                                                Reference.NOTINSET]

        else:
            # compare using this number and not using this number
            notusing = self.getMaxOf( self.currentRow )
            using = self.currentNumber + self.getMaxOf( T - self.currentNumber )

            if notusing > using :
                self.table[self.currentRow][self.currentColumn] = [notusing,Reference.NOTINSET]
            else:
                self.table[self.currentRow][self.currentColumn] = [using,Reference.INSET]

if False:
    a = [4,5,2]
    T = 9
    manager = DynamicTable(a, T)
    print manager.getTable()
    manager.run()
    print manager.getTable()
    manager.getSet()

def printTable( table ) :
    for row in range( 0, T + 1 ):
        for col in range( 0, len(a) + 1 ):
            print table[col][row],
        print ""

# START ALGO
a = [10,3,2,5,9]
T = 7

def getNumber( col ) :
    return a[col - 1]

# initialiaze table
table = list()

for col in range(0, len(a) + 1):
    table.append( [] )
    for row in range(0, T + 1 ):
       table[col].append([0,Reference.BASE]) 

# for each number in the set
for col in range(1, len(a) + 1):
    # for each size of T
    for row in range(1, T + 1):
        # find the optimal collection
        # if the current number is greater than the current T(row), dont use the
        # number
        if getNumber(col) > row:
            table[col][row] = [table[col - 1][row][0], Reference.NOTINSET]
        # else compare using the number with not using the number, return the
        # largest of the two
        else:

            using = getNumber(col) + table[col-1][row - getNumber(col)][0]
            notusing = table[col-1][row][0]

            if notusing > using:
                table[col][row] = [notusing,Reference.NOTINSET]
            else:
                table[col][row] = [using,Reference.INSET]

printTable(table)
print ""

# traceback
def traceback( row, col):
    # follow the references back to the base case.  If a reference is INSET,
    # then grab that number
    print "Row:",row," Col:",col
    if table[col][row][1] == Reference.INSET:
        return ( traceback( row - getNumber(col), col - 1) |
                {getNumber(col)} )
    if table[col][row][1] == Reference.NOTINSET:
        return ( traceback( row, col - 1 ) )
    if table[col][row][1] == Reference.BASE:
        return set()

print traceback( T, len(a) )
