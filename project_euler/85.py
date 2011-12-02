#!/usr/bin/python

sizeX=100
sizeY=100

grid=[[x*y for x in range(1,sizeX+1)] for y in range(1,sizeY+1)]
areas=[]
#print grid

for x in range(1,sizeX+1):
	for y in range(x,sizeY+1):
		area=0
		for i in range(0,y):
			row=grid[i]
			ele=row[0:x]
			area+=sum(ele)
		areas.append(area)
		if area==1999998: print x,y

#print sorted(areas)