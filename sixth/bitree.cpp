#include <fmt/core.h>

struct node{
    int val;
    node *left;
    node *right;
    node(): val(0), left(nullptr), right(nullptr){}
    node(int val): val(val), left(nullptr), right(nullptr){}
    node(int val, node *left, node *right): val(val), left(left), right(right){}
};

void preorder(node *node){
    if(node == nullptr){
        return;
    }
    fmt::print("{}", node->val);
    preorder(node->left);
    preorder(node->right);
}

void inorder(node *node){
    if(node == nullptr){
        return;
    }
    inorder(node->left);
    fmt::print("{}", node->val);
    inorder(node->right);
}

void postorder(node *node){
    if(node == nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    fmt::print("{}", node->val);
}

int main(){
    node *head = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    head->left = node1;
    head->right = node2;
    node1->right = node3;
    node2->left = node4;

    preorder(head);
    fmt::print("\n");
    inorder(head);
    fmt::print("\n");
    postorder(head);
    fmt::print("\n");
}