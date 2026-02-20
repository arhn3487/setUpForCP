import math
import sys
import os
input = sys.stdin.readline

def dbg(*args):
    if 'ONLINE_JUDGE' in os.environ:
        return
    import traceback
    stack = traceback.extract_stack()
    line = stack[-2].line
    names = line[line.find('dbg(')+4 : line.rfind(')')]
    print(f"[{names}]:", *args, file=sys.stderr)

def solve():
    
    return

def main():
    t = int(input())
    for i in range(1, t + 1):
        # print(f"Case {i} : ")
        solve()
    return

if __name__ == "__main__":
    main()