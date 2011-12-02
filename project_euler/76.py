#!/usr/bin/env python

limit=6

def evaluate(ints, score, depth=2):
    if (depth > limit):
        return score
    newints = []

    for i in ints:
        val = [i/10, i%10]
        newints.append([val[0]+1, val[1]])
        if (val[1] < val[0]):
            newints.append([val[0], val[1]+1])

    newints = list(set([a*10+b for a,b in newints]))
    newints.sort()

    #print depth, ':', newints, score+len(newints)
    return evaluate(newints, score+len(newints), depth+1)

print evaluate([1, 1], 0)
