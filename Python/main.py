#!/bin/python3
from collections import namedtuple
from typing import List
from ctypes import *
import pathlib
import sys

Point = namedtuple('Point', ['x', 'y'])
lib_path = pathlib.Path().absolute() / "../C/cmake-build-debug/libStrypesTask.so"


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


def setup_lib(path) -> CDLL:
    lib = CDLL(path)
    lib.find_longest_len.argtypes = [c_char_p, c_int, c_int]
    lib.find_longest_len.restype = c_int
    return lib


def run(path_to_input) -> int:
    lib = setup_lib(lib_path)
    file_input = read_file(path_to_input)
    parsed_input = parse_file_input(file_input)

    graph = c_char_p(parsed_input[0].encode('utf-8'))
    return lib.find_longest_len(graph, parsed_input[1][0] - 1, parsed_input[1][1] - 1)


if __name__ == '__main__':
    for arg in sys.argv[1:]:
        print(run(arg))
