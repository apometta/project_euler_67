// Code written by Andrew H. Pometta to solve project euler question number
// 67, "Maximum Path Sums II".  https://projecteuler.net/problem=67
// See the README for a more detailed description of this problem

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/*The strategy is as follows: a vector of int vectors (essentially a 2D
  vector of ints) is used to store the tree.  If you look at the tree
  structure in the file, you'll notice that a number's two children are the
  one below it and the one below it and to the right once - essentially, for
  int vector[y][x], its children are vector[y+1][x] and vector[y+1][x+1].

  Thus, we find the maxmimum possible some with a depth-first traversal of the
  tree.  For each node starting from the second to last row, the find the
  maximum possible sum for the subtree whose root node is that node.  Then,
  we do this for each row at a time, going up, until we reach the top.

  I don't use a traditional tree because two siblings will share a child in
  this tree, although that could be done if you simply insert most numbers in
  the tree twice.
*/

const string INFILE = "p067_triangle.txt";
using intlist = vector<int>;

//Quick function - return max of two ints.
inline int max (int a, int b){
    return a > b ? a : b;
}

/*Takes in a string corresponding to a line in the infile and returns a vector
  of ints.
*/
intlist get_row(string line){
    intlist row;
    //the lines have the following format:
    //([0-9]{2}" ")*[0-9]{2}
    for (size_t i = 0; i < line.length(); i += 3){
        int number;
        istringstream(line.substr(i, i + 2)) >> number;
        row.push_back(number);
    }
    return row;
}

int main (int argc, char **argv) {
    //remove warning: unused variable
    (void) argc; (void) argv;
    //Open input file
    ifstream infile;
    infile.open (INFILE);
    if (not infile.good()){
        cerr << "Error: could not open file " << INFILE << "." << endl;
        return EXIT_FAILURE;
    }

    //Construct tree from input file contents and then close
    string line; vector<intlist> rows;
    while ( getline (infile, line) ) {
        intlist new_row = get_row(line);
        rows.push_back(new_row);
    }
    infile.close();

    //calculate max sum - start at SECOND TO LAST row
    //we don't use iterators for this because we need to keep access of the
    //index, so we might as well use c-style iteration
    for (int i = rows.size() - 2; i >= 0; --i){
        vector<int> *curr_row = &rows.at(i);
        vector<int> *prev_row = &rows.at(i + 1);
        for (size_t j = 0; j < curr_row->size(); ++j){
            curr_row->at(j) += max(prev_row->at(j), prev_row->at(j + 1));
        }
    }
    
    cout << "Max possible sum: " << rows.at(0).at(0) << endl;
    return EXIT_SUCCESS;
}
