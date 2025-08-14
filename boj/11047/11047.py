# https://www.acmicpc.net/problem/11047
# https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11047/11047
# ------------------------------------------------------------------------------
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline
output = sys.stdout.write

# ------------------------------------------------------------------------------
#                      /$$             /$$     /$$
#                     | $$            | $$    |__/
#   /$$$$$$$  /$$$$$$ | $$ /$$   /$$ /$$$$$$   /$$  /$$$$$$  /$$$$$$$
#  /$$_____/ /$$__  $$| $$| $$  | $$|_  $$_/  | $$ /$$__  $$| $$__  $$
# |  $$$$$$ | $$  \ $$| $$| $$  | $$  | $$    | $$| $$  \ $$| $$  \ $$
#  \____  $$| $$  | $$| $$| $$  | $$  | $$ /$$| $$| $$  | $$| $$  | $$
#  /$$$$$$$/|  $$$$$$/| $$|  $$$$$$/  |  $$$$/| $$|  $$$$$$/| $$  | $$
# |_______/  \______/ |__/ \______/    \___/  |__/ \______/ |__/  |__/
# solution ---------------------------------------------------------------------


def solve():
    return

# lgtm -------------------------------------------------------------------------
#  /$$        /$$$$$$  /$$$$$$$$ /$$      /$$
# | $$       /$$__  $$|__  $$__/| $$$    /$$$
# | $$      | $$  \__/   | $$   | $$$$  /$$$$
# | $$      | $$ /$$$$   | $$   | $$ $$/$$ $$
# | $$      | $$|_  $$   | $$   | $$  $$$| $$
# | $$      | $$  \ $$   | $$   | $$\  $ | $$
# | $$$$$$$$|  $$$$$$/   | $$   | $$ \/  | $$
# |________/ \______/    |__/   |__/     |__/
# ------------------------------------------------------------------------------


def log(*args):
    print(*args, file=sys.stderr)


def run_test(problem_number, test_number):

    input_path = f"{problem_number}/test-input-{test_number}.txt"
    output_path = f"{problem_number}/my-output-{test_number}.txt"

    import os
    if not os.path.exists(input_path):
        log("Input file not found:", input_path)
        return

    sys.stdin = open(input_path, 'r')
    sys.stdout = open(output_path, 'w')
    log(f"test case -  {test_number}")
    solve()
    print()


if __name__ == "__main__":
    args = sys.argv
    if len(args) == 3:
        p, t = map(int, args[1:])
        for i in range(1, t + 1):
            run_test(p, i)
    elif len(args) == 4:
        p, t, target = map(int, args[1:])
        run_test(p, target)
    else:
        solve()
