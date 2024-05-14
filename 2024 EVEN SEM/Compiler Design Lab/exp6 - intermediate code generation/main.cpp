#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Listnode {
    vector<string> type = {"no","no","no"};
    Listnode *left;
    Listnode *right;
    string data;

};

Listnode* newNode(string val,vector<string> type) {
    Listnode* temp = (Listnode*)malloc(sizeof(Listnode));
    temp->data = val;
    temp->type = type;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert nodes
Listnode* insert(Listnode* root, string data,vector<string> type) {
    // If tree is empty, new node becomes the root
    if (root == NULL) {
        root = newNode(data,type);
        return root;
    }

    // Queue to traverse the tree and find the position to insert the node
    Listnode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Listnode* temp = queue[front++];
        // Insert node as the left child of the parent node
        if (temp->left == NULL) {
            temp->left = newNode(data,type);
            break;
        }
        // If the left child is not null, push it to the queue
        else
            queue[rear++] = temp->left;
        // Insert node as the right child of parent node
        if (temp->right == NULL) {
            temp->right = newNode(data,type);
            break;
        }
        // If the right child is not null, push it to the queue
        else
            queue[rear++] = temp->right;
    }
    return root;
}




string idtype(Listnode node){
    if (node.type[0]=="yes"){
        return "num";
    }

    if (node.type[1]=="yes"){
        return "op";
    }
    if (node.type[2]=="yes"){
        return "var";
    }
return "NULL";
}

void preorderTraversal(Listnode* root) {
    if (!root)
        return;
    cout<<root->data<<endl;
    cout<< idtype(*root)<<endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){

    Listnode* root = NULL;


   root = insert(root,"+",{"no","yes","no"});

   root = insert(root,"*",{"no","yes","no"});

   root = insert(root,"b",{"no","no","yes"});
   root = insert(root,"a",{"no","no","yes"});

   root = insert(root,"3",{"yes","no","no"});

preorderTraversal(root);


    return 0;
}
