# project_euler_67
A small program, in C++, that solves the Project Euler riddle number 67: 
https://projecteuler.net/problem=67
This program, written by Andrew H. Pometta, is a small C++ program designed to 
solve riddle number 67 in project Euler: https://projecteuler.net/problem=67.

The page's specification for the problems are below:

***

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

***

The file p-67_triangle.txt contains the 1-- row tree.  The implementation file is 
maximum_path_sums_II.cpp.  It was compiled on my system with:
g++ -Wall -Wextra -std=gnu++11 maximum_path_sums_II.cpp -o maximum_path

Implementation details are contained within the C++ file.  Confirmation of the 
puzzle online ensures that the correct answer is gotten.
