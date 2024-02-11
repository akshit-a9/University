#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Node structure for the Huffman tree
struct Node {
    char symbol;
    int weight;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

// Function to initialize the Huffman tree
Node* initializeTree() {
    Node* rootNode = new Node{'\0', 0, nullptr, nullptr, nullptr};
    return rootNode;
}

// Function to find a node in the tree
Node* findNode(Node* tree, char symbol) {
    if (tree == nullptr) {
        return nullptr;
    } else if (tree->symbol == symbol) {
        return tree;
    } else {
        Node* foundNode = findNode(tree->leftChild, symbol);
        if (foundNode) {
            return foundNode;
        }
        return findNode(tree->rightChild, symbol);
    }
}

// Function to update the tree after a symbol is encoded
void updateTree(Node*& tree, char symbol, map<char, Node*>& lookup) {
    Node* currentNode = lookup[symbol];
    // If the symbol is not found, create a new node
    if (!currentNode) {
        currentNode = new Node{symbol, 1, tree, nullptr, nullptr};
        if (!tree->leftChild) {
            tree->leftChild = currentNode;
        } else {
            tree->rightChild = currentNode;
        }
        lookup[symbol] = currentNode;
    }
    // Update weights and reorganize the tree as before
    currentNode->weight++;
    while (currentNode->parent) {
        Node* sibling = (currentNode->parent->leftChild == currentNode)
                            ? currentNode->parent->rightChild
                            : currentNode->parent->leftChild;
        if (sibling && currentNode->weight > sibling->weight) {
            // Swap nodes
            swap(currentNode->symbol, sibling->symbol);
            swap(currentNode->weight, sibling->weight);
            lookup[currentNode->symbol] = currentNode;
            lookup[sibling->symbol] = sibling;
        } else {
            break; // No need to continue
        }
        currentNode = currentNode->parent;
    }
}

// Function to encode a symbol using Adaptive Huffman coding
void encodeSymbol(Node* tree, char symbol, map<char, Node*>& lookup) {
    // Update the tree first
    updateTree(tree, symbol, lookup);

    // Traverse the tree to find the codeword
    vector<int> codeword;
    Node* currentNode = lookup[symbol];
    while (currentNode && currentNode->parent) {
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
    
    string input = "aardva";
    
    map<char, Node*> lookup;

    for (char c : input) {
        encodeSymbol(huffmanTree, c, lookup);
        cout << " ";
    }
    
    return 0;
}
