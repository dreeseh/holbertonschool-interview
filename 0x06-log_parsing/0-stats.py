#!/usr/bin/python3
'''
a module that contains a script that
reads stdin line by line and computes metrics
'''
import sys


def printOut(dict, stats_size):
    '''prints stats from beginning'''
    print("File size: {}".format(stats_size))
    for k in sorted(dict.keys()):
        if dict[k]:
            print("{}: {}".format(k, dict[k]))

stats = {"200": 0,
         "301": 0,
         "400": 0,
         "401": 0,
         "403": 0,
         "404": 0,
         "405": 0,
         "500": 0}

counter = 0
stats_size = 0

try:
    for line in sys.stdin:
        if counter != 0 and counter % 10 == 0:
            printOut(stats, stats_size)

        split_list = line.split()
        counter += 1

        try:
            stats_size += int(split_list[-1])
        except:
            pass

        try:
            if split_list[-2] in stats:
                stats[split_list[-2]] += 1
        except:
            pass

    printOut(stats, stats_size)

except KeyboardInterrupt:
    printOut(stats, stats_size)
    raise
