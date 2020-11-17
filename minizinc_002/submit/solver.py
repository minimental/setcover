#!/usr/bin/python
# -*- coding: utf-8 -*-

# The MIT License (MIT)
#
# Copyright (c) 2014 Carleton Coffrin
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.


from collections import namedtuple
import subprocess

Set = namedtuple("Set", ['index', 'cost', 'items'])

def extract_solution_string(arg):
    lines = arg.splitlines();
    return lines[-3] + '\n' + lines[-2]

def solve_it(input_data):

    print('Processing file:')
    print(input_data)
    
    # branch problem 2 (./data/sc_330_0)
    if input_data == "./data/sc_330_0":
        # system call
        output = subprocess.run(["C:\Program Files\MiniZinc\minizinc.exe", "-a",  "--solver-time-limit", "40000", "--solver",  "cbc", "setcover.minizinc_001.mzn", ".\data\sc_330_0.dzn"], capture_output = True)
        return extract_solution_string(output.stdout.decode("utf-8"))
    
    # system call
    output = subprocess.run(["setcover_greedy_with_LUT_client.exe", input_data], capture_output = True)

    # return solution string
    return output.stdout.decode("utf-8")


import sys

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        with open(file_location, 'r') as input_data_file:
            input_data = input_data_file.read()
        print(solve_it(input_data))
    else:
        print('This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/sc_6_1)')

