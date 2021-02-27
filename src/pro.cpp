/**
 * Thomas vanBommel
 * Feb 24. '21 - Created
 * Feb 27. '21 - Modified
 * 
 * A. Would the efficiency of your programs suffer, if the input data were given unsorted? Why? 
 *      Attempt #1 - would probably perform better with unsorted data, because every value (sorted)
 *                   goes to the same side of each node...
 * 
 *                   ie:       o
 *                            / \
 *                               o
 *                              / \
 *                                 o
 *                                / \ ... and so on, until rebalanced. Unsorted would have a better
 *                                        chance of using up the other "leafs".
 *  
 *                   How would you correct the problem? 
 *                       Use attempt #2 (with sorted data)
 * 
 *      Attempt #2 - would perform worse and require rebalancing, because it fills in the tree 
 *                   optimally by spliting a vector, using the middle as the root, and recursivly
 *                   splits again, and again...
 * 
 *                   ie:      o - middle of the vector
 *                           / \
 *                        left right - vector gets split into left and right halves
 *                         /|   |\
 *                     left R   L right - vector splits again, and again, and again...
 *
 *                   How would you correct the problem?
 *                       Sort the data before inserting into a tree
 * 
 * B. How much “slower” would your PRO implementation respond to the inquiries, if the list of  
 *    100,000,000 primes was used instead?
 * 
 *       About 20%  - On a balanced tree you would need to traverse ~5 extra nodes, since every row 
 *                    can double the node count in the tree. (for inquiries)
 * 
 *                    ie: 3,000,000 * 2 * 2 * 2 * 2 * 2 = 96,000,000
 *                                    |   |   |   |   | 
 *                                   row row row row row
 * 
 *                          3,000,000 nodes = tree height of 21
 *                        100,000,000 nodes = tree height of 26
 * 
 *                        26 is ~20% more than 21
 * 
 * C. ** See answer in the header of `spell.cpp` **
 * */

#include "common.h"

using namespace std;

/**
 * Run program (prompt user for input)
 * @param tree - Prime tree (must NOT be empty)
 * */
void runPRO(Tree<int> & tree){
    // Get the last number
    vector<int> order;
    tree.inorder(order);
    int last = order.back();

    // Input integer; Tell the user how to leave the program
    int in;
    cout << "Enter a number to check if it is prime: (from 2 to " << last << ")" << endl;
    cout << "Enter -1 to exit" << endl;

    // Get user input
    while(cin >> in, in != -1){

        // Check number is valid
        if(in > 0 && in < 49979687){

            // Inform the user if the number they entered is prime or not
            string response = tree.find(in) ? "is" : "is NOT";
            cout << "You entered " << in << " which " << response << " a prime number" << endl;
        }else{

            // Invalid input
            cout << "Invalid number, valid options are (49979687 < x > 0)" << endl;
        }
    }
}

/**
 * Program entry point
 * */
int main(){
    // Introduction
    cout << "BST PRO Lab #4\nThomas vanBommel\nFeb 27. 2021\n" << endl;

    // Initialize tree
    Tree<int> tree{};

    // Attempt #1 ( ~3.4 minutes )
    // importTreeFromFile("primes3mil.txt", tree, importSequentially);

    // Attempt #2 ( ~1 second )
    importTreeFromFile("primes3mil.txt", tree, importSplitRecursive);

    // Inform user of tree height
    cout << "Tree height: " << tree.height() << "\n" << endl;

    // Check if tree is empty
    if(tree.height() == -1){
        cout << "Empty tree..." << endl;
        return 1;
    }

    // Run program with user interaction
    runPRO(tree);

    // No errors :)
    return 0;
}