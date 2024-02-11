#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int symbol;
    int weight;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

Node* initializeTree() {
    Node* rootNode = new Node{256, 0, nullptr, nullptr, nullptr};
    return rootNode;
}

void updateTree(Node*& tree, int symbol) {
    Node* currentNode = tree;
    while (currentNode->symbol != symbol) {
        if (currentNode->leftChild && currentNode->leftChild->symbol == symbol) {
            currentNode = currentNode->leftChild;
        } else if (currentNode->rightChild && currentNode->rightChild->symbol == symbol) {
            currentNode = currentNode->rightChild;
        } else {
            Node* newNode = new Node{symbol, 1, currentNode, nullptr, nullptr};
            if (!currentNode->leftChild) {
                currentNode->leftChild = newNode;
            } else {
                currentNode->rightChild = newNode;
            }
            currentNode = newNode;
        }
    }
    currentNode->weight++;
    while (currentNode->parent) {
        Node* sibling = (currentNode->parent->leftChild == currentNode)
                            ? currentNode->parent->rightChild
                            : currentNode->parent->leftChild;
        if (currentNode->weight > sibling->weight) {
            swap(currentNode->symbol, sibling->symbol);
            swap(currentNode->weight, sibling->weight);
        } else {
            break;
        }
        currentNode = currentNode->parent;
    }
}

void encodeSymbol(Node* tree, int symbol) {
    updateTree(tree, symbol);

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

    for (int i = codeword.size() - 1; i >= 0; i--) {
        cout << codeword[i];
    }
}

int main() {
    Node* huffmanTree = initializeTree();
    
    string input = "aardva";
    for (char c : input) {
        encodeSymbol(huffmanTree, static_cast<int>(c));
    }
    
    cout << endl;
    
    return 0;
}

