#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
import subprocess

Set = namedtuple("Set", ['index', 'cost', 'items'])

def solve_it(input_data):
    print('Processing file:')
    print(input_data)
    
    # branch problem 2 (./data/sc_330_0)
    if input_data == "./data/sc_330_0":
        return "todo: return minizinc solution for problem sc_330_0"
    
    # system call
    output = subprocess.run(["setcover_greedy_with_LUT_client.exe", input_data], capture_output = True)

    # return solution string
    return output.stdout.decode("utf-8")


import sys

if __name__ == '__main__':
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        input_data_file = open(file_location, 'r')
        input_data = ''.join(input_data_file.readlines())
        input_data_file.close()
        print 'Solving:', file_location
        print solve_it(input_data)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/sc_6_1)'

