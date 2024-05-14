#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Listnode {
    vector<string> type = {"no", "no", "no"};
    Listnode *left = nullptr;
    Listnode *right = nullptr;
    string data;

    Listnode(string val, vector<string> type_val) : data(val), type(type_val) {}
};

// Function to insert nodes
Listnode* insert(Listnode* root, string data, vector<string> type) {
    if (root == nullptr) {
        return new Listnode(data, type);
    }

    queue<Listnode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Listnode* temp = nodeQueue.front();
        nodeQueue.pop();

        if (temp->left == nullptr) {
            temp->left = new Listnode(data, type);
            break;
        } else {
            nodeQueue.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = new Listnode(data, type);
            break;
        } else {
            nodeQueue.push(temp->right);
        }
    }
    return root;
}

string idtype(const Listnode& node) {
    if (node.type[0] == "yes") return "num";
    if (node.type[1] == "yes") return "op";
    if (node.type[2] == "yes") return "var";
    return "NULL";
}

void preorderTraversal(Listnode* root) {
    if (root == nullptr) return;
    cout << root->data << " (" << idtype(*root) << ")" << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Listnode* root = nullptr;
    root = insert(root, "+", {"no", "yes", "no"});
    root = insert(root, "*", {"no", "yes", "no"});
    root = insert(root, "b", {"no", "no", "yes"});
    root = insert(root, "a", {"no", "no", "yes"});
    root = insert(root, "3", {"yes", "no", "no"});

    preorderTraversal(root);

    return 0;
}
