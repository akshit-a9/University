#include <iostream>
#include <vector>

using namespace std;

// Node structure for the Huffman tree
struct Node {
    int symbol;
    int weight;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

// Function to initialize the Huffman tree
Node* initializeTree() {
    Node* rootNode = new Node{256, 0, nullptr, nullptr, nullptr};
    return rootNode;
}

// Function to update the tree after a symbol is encoded
void updateTree(Node* tree, int symbol) {
    // Find the node corresponding to the symbol
    Node* currentNode = tree;
    while (currentNode->symbol != symbol) {
        if (currentNode->leftChild && currentNode->leftChild->symbol == symbol) {
            currentNode = currentNode->leftChild;
        } else {
            currentNode = currentNode->rightChild;
        }
    }

    // Update the weights and reorganize the tree if necessary
    currentNode->weight++;
    while (currentNode->parent) {
        Node* sibling = (currentNode->parent->leftChild == currentNode)
                            ? currentNode->parent->rightChild
                            : currentNode->parent->leftChild;
        if (currentNode->weight > sibling->weight) {
            // Swap nodes
            swap(currentNode->symbol, sibling->symbol);
            swap(currentNode->weight, sibling->weight);
        } else {
            break; // No need to continue
        }
        currentNode = currentNode->parent;
    }
}

// Function to encode a symbol using Adaptive Huffman coding
void encodeSymbol(Node* tree, int symbol) {
    // Update the tree first
    updateTree(tree, symbol);

    // Traverse the tree to find the codeword
    vector<int> codeword;
    Node* currentNode = tree;
    while (currentNode->parent) {
        if (currentNode->parent->leftChild == currentNode) {
            codeword.push_back(0);
        } else {
            codeword.push_back(1);
        }
        currentNode = currentNode->parent;
    }

    // Output the codeword (in reverse order)
    for (int i = codeword.size() - 1; i >= 0; i--) {
        cout << codeword[i];
    }
}

int main() {
    Node* huffmanTree = initializeTree();
    
    // Example: Encoding the symbol 'A' (ASCII value 65)
    int symbol = 65;
    encodeSymbol(huffmanTree, symbol);
    
    return 0;
}
