#!/usr/bin/python3

import sys

# dictionaries to store metrics
file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

# counter for number of lines processed
line_count = 0

# function to print metrics


def print_metrics(metrics, file_size):
    codes = [200, 301, 400, 401, 403, 404, 405, 500]
    print("Total file size: " + str(file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(str(code) + ": " + str(status_codes[code]))


# read stdin line by line
try:
    for line in sys.stdin:
        try:
            line_count += 1
            arguments = line.split
            file_size = int(arguments[-1])
            http_code = int(arguments[-2])
            status_codes[http_code] += 1
            if line_count == 10:
                print_metrics(status_codes, file_size)
                line_count = 0
        except Exception:
            continue
except Exception:
    pass
finally:
    print_metrics(status_codes, file_size)
