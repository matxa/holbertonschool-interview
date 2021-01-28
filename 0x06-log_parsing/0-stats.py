#!/usr/bin/python3
"""Log Parser"""
from sys import stdin

# Status codes
status_codes = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0,
}

# Global variables
file_size = 0
line_count = 0


def parse_log(line):
    """Parse log
    GET status code from line
    increment file size
    """
    line = line.split(" ")
    status_code = line[-2]
    global file_size
    file_size += eval(line[-1])
    if type(eval(status_code)) == int and status_code in status_codes.keys():
        status_codes[status_code] += 1


def parse_print():
    """Print status of
    stin
    """
    print("File size: {}".format(file_size))
    for k, v in sorted(status_codes.items()):
        print("{}: {}".format(k, v))


try:
    for line in stdin:
        if line_count % 10 == 0 and line_count != 0:
            parse_print()
        if len(line) > 70:
            parse_log(line)
        line_count += 1

except KeyboardInterrupt:
    parse_print()
except BrokenPipeError:
    pass
