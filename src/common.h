/**
 * Thomas vanBommel
 * Feb 27. '21 - Created
 * */

#include "BST.h"
#include "Timer.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Import a tree object from a file using a specified method
 * @param filename - Filename to import from
 * @param tree - Tree to fill / import values into
 * @param method - How to fill the tree
 * */
template<class T>
void importTreeFromFile(string filename, Tree<T> & tree, void (* method)(ifstream &, Tree<T> &)){
    // Attempt to open the file
    ifstream in;
    in.open(filename, ifstream::in);

    // Ensure file opened
    if(in.is_open()){

        // Inform user import has started ----------------------------------------------------------
        cout << "Loading values into tree..." << endl;

        // Call import method
        method(in, tree);

        // Inform user import has finished ---------------------------------------------------------
        cout << "Finished loading values into tree\n" << endl;

        // Close the open file
        in.close();
    } else{

        // File never opened, inform the user
        cout << "File did not open" << endl;
    }
}

/**
 * Attempt #1
 * Import values from a .txt file sequentially
 * @param file - File to import from
 * @param tree - Tree to input values to
 * */
template<class T>
void importSequentially(ifstream & file, Tree<T> & tree){
    // Start timer
    Timer timer{true};

    // Value holder
    T val;

    // Keep track of number of values inserted
    int count = 0;

    // While stream has association to file
    while(file.good()){

        // Add numbers into the tree
        file >> val, tree.insert(val);

        // Every 20,000 values added
        if(++count % 20000 == 0){

            // Balance the tree
            tree.rebalance();

            // Write to console
            cout << "  [" << timer.time() << "ms] " << count/1000 << "k values inserted..." << endl;
        }
    }
}

/**
 * Attempt #2
 * Adds values to a vector and recursively splits (high+low), and inserts into the tree
 * All the fun was lost when I saw the method already implemented in BST.h
 * (was about to attempt my own)
 * @param file - File to import from
 * @param tree - Tree to input values to
 * */
template<class T>
void importSplitRecursive(ifstream & file, Tree<T> & tree){
    // Start timer
    Timer timer{true};

    // Value container
    vector<T> container{};

    // While stream has association to file
    while(file.good()){

        // Get value
        T val;
        file >> val;

        // Insert - is this the fastest way to insert into a vector from a file? (~450ms)
        container.push_back(val);
    }

    // Insert into tree (using piotrs split-recursive method)
    tree.balance(container, 0, container.size());

    // Print elapsed time
    cout << "Completed in " << timer.time() << "ms" << endl;
}