#!/bin/python3
from collections import namedtuple
from typing import List
from ctypes import *
import pathlib
import os

Point = namedtuple('Point', ['x', 'y'])


def read_file(path) -> List[str]:
    result = []
    with open(path, 'r') as reader:
        for line in reader.readlines():
            result.append(line)
    return result


def parse_file_input(user_input) -> (List[List[int]], Point):
    rows_cols = user_input[0].strip().split(' ')
    rows = int(rows_cols[0])
    cols = int(rows_cols[1])

    result = ''
    for line in user_input[1:]:
        for item in line.strip().split(' '):
            result += item

    return result, [rows, cols]


if __name__ == '__main__':
    file_input = read_file('../internship-assignment/tests/test_4')
    parsed_input = parse_file_input(file_input)

    libname = pathlib.Path().absolute() / "../C/cmake-build-debug/libStrypesTask.so"
    c_lib = CDLL(libname)

    # s = 'hello'
    # temp_string = c_char_p(s.encode('utf-8'))
    # c_lib.print_str.argtypes = [c_char_p]
    # c_lib.print_str(temp_string)

    c_lib.find_longest_len.argtypes = [c_char_p, c_int, c_int]
    c_lib.find_longest_len.restype = c_int
    graph = c_char_p(parsed_input[0].encode('utf-8'))
    print(c_lib.find_longest_len(graph, parsed_input[1][0] - 1, parsed_input[1][1] - 1))
