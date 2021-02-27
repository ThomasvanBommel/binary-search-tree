/**
 * Thomas vanBommel
 * Feb 27. '21 - Created
 * 
 * C. How much “slower” would your spell implementation respond to the inquiries, if you inserted 
 *    words and never tried to balance the tree? 
 * */

#include "common.h"

using namespace std;

void runSPELL(){
    
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

    // No errors :)
    return 0;
}