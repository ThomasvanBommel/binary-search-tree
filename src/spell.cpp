/**
 * Thomas vanBommel
 * Feb 27. '21 - Created
 * 
 * C. How much “slower” would your spell implementation respond to the inquiries, if you inserted 
 *    words and never tried to balance the tree? 
 * 
 *      ... I don't balance the tree :) 
 * 
 *          However, if the tree wern't sorted it could have (at worst case) a height of 100,000 
 *          (with 100,000 words):
 * 
 *          ie: Current height    = 16 (using split-recursive method)
 *              Worst-case height = 100,000
 * 
 *              100,000 is 6,250 times bigger than 16
 *              ...so, in theory up to 6,250 times slower
 * */

#include "common.h"

using namespace std;

/**
 * Interactive spelling checker
 * @param tree - Word tree to use
 * */
void runSPELL(Tree<string> & tree){
    // Used for user input
    string in;

    // Inform the user how to play
    cout << "Enter a word to check if spelled correctly:" << endl;
    cout << "Enter -1 to exit" << endl;

    // While input != '-1', print if the input word is spelled correctly (found inside the tree)
    while(cin >> in, in != "-1")
        cout << "'" + in + "' is " << (tree.find(in) ? "" : "NOT") << " spelled correctly\n" << endl;
}

/**
 * Program entry point
 * */
int main(){
    // Introduction
    cout << "BST SPELL Lab #4\nThomas vanBommel\nFeb 27. 2021\n" << endl;

    // Initialize tree
    Tree<string> tree{};

    // Attempt #1
    importTreeFromFile("Words.txt", tree, importSplitRecursive);

    // Inform user of tree height
    cout << "Tree height: " << tree.height() << "\n" << endl;

    // Check if tree is empty
    if(tree.height() == -1){
        cout << "Empty tree..." << endl;
        return 1;
    }

    // Start interaction
    runSPELL(tree);

    // No errors :)
    return 0;
}