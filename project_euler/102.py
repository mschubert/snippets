#!/usr/bin/env python

from urllib import urlopen

tris = urlopen('http://projecteuler.net/project/triangles.txt').read()
tris = tris.split('\r\n')[0:-1] # \r\n

count = 0

for tri in tris:
    pts = tri.split(',')
    pts = [float(x) for x in pts]

    xs, ys = [0], [0]

    for p1,p2 in [[[pts[0], pts[1]], [pts[2], pts[3]]],
                 [[pts[2], pts[3]], [pts[4], pts[5]]],
                 [[pts[4], pts[5]], [pts[0], pts[1]]]]:
        #print "p1,p2:", p1, p2

        ab = [p2[0]-p1[0], p2[1]-p1[1]]
        x,y,p = ab[1], -ab[0], ab[1]*p1[0]-ab[0]*p1[1] # n x = n p

        if (x != 0):
            curx = p/x
            if (curx >= min(p1[0],p2[0]) and curx <= max(p1[0],p2[0])):
                xs.append(curx)

        if (y != 0):
            cury = p/y
            if (cury >= min(p1[1],p2[1]) and cury <= max(p1[1],p2[1])):
                ys.append(cury) # mit x,y schneiden

    if (min(xs)<0 and max(xs)>0 and min(ys)<0 and max(ys)>0):
        count += 1
    #print xs, ys

print count
