#!/usr/bin/env python
from urllib import urlopen
from string import split

words = ['time', ' person', ' year', ' way', ' day', ' thing', ' man', 'world', 'life ',
    'hand', 'part', 'child', 'eye', 'woman', 'place', 'work', 'week', 'case', 'point',
    'government', 'company', 'number', 'group', 'problem', 'fact', 'bike', 'be', 'have',
    'do', 'eat', 'sleep', 'drink', 'put', 'keep', 'run', 'walk', 'say', 'get', 'make',
    'go', 'know', 'take', 'see', 'come', 'think', 'look', 'want', 'give', 'use', 'find',
    'tell', 'ask', 'work', 'seem', 'feel', 'try', 'leave', 'good', 'first', 'new', 'last',
    'long', 'great', 'little', 'own', 'other', 'old', 'right', 'big', 'high', 'different',
    'small', 'large', 'next', 'early', 'young', 'important', 'few', 'public', 'private',
    'more', 'bad', 'same', 'able']

file = urlopen('http://projecteuler.net/project/cipher1.txt')
text = file.read().split(',')
text[-1] = text[-1].strip('\r\n') # get rid of CRLF
ints = [int(x) for x in text]

maxs, space, maxk, maxj, maxi = 0, 0, 0, 0, 0

cur = list(ints)
for k in range(97, 123): #(97, 123)
    for x in range(0, len(ints), 3):
        cur[x] = ints[x] ^ k

    for j in range(97, 123):
        for x in range(1, len(ints), 3):
            cur[x] = ints[x] ^ j

        for i in range(97, 123):
            #pw = str(i) + str(j) + str(k)
            for x in range(2, len(ints), 3):
                cur[x] = ints[x] ^ i

            ctext = [chr(x) for x in cur]
            ctext = "".join(ctext)#

            score = 0
            for word in words:
                if word in ctext:
                    score += 1

            if (score > maxs):
                space = 0
                for x in cur:
                    if (x == 32): space+=1
                maxs, maxk, maxj, maxi = score, k, j, i
                text = ctext

print maxs, space, chr(maxk) + chr(maxj) + chr(maxi)

score = 0
print text
for c in text: score += ord(c)
print score
