from search import *
from vcl import VCL
from mc import MC


def main():
    problema_vcl = VCL((1, 1, 1, 'STANGA', 0, 0, 0), (0, 0, 0, 'DREAPTA', 1, 1, 1))
    problema_mc = MC((3, 3, 'STANGA', 0, 0), (0, 0, 'DREAPTA', 3, 3))
    path = breadth_first_tree_search(problema_mc).solution()
    print(path, '\n')


if __name__ == "__main__":
    main()
