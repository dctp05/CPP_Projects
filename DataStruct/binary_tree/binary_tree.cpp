#include <iostream>

using namespace std;

struct binary_tree_node{
    int data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
};

typedef struct binary_tree_node node;

node *top = nullptr;

int stack[100];
int top_stack=-1;

node * get_node(int data);
void push_stack(int data);
int pop_stack();
void in_order_traverse(node *nodeptr);

int main(){
    //Create binary tree
    top = get_node(1);
    top->left = get_node(2);
    top->right = get_node(3);

    node *temp;
    temp = top->left;
    temp->left = get_node(4);
    temp->right = get_node(5);
    temp = temp->right;
    temp->right = get_node(6);

    temp = top->right;
    temp->right = get_node(7);
    temp = temp->right;
    temp->left = get_node(8);
    temp->right = get_node(9);

    in_order_traverse(top);

    cout << "Right to left in order traversing of Binary tree" << endl;

    do {
        cout << pop_stack() << " ";
    } while(top_stack >= 0);

    return 0;
}

node * get_node(int data){
    node *new_node;
    new_node = new node;
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

void push_stack(int data){
    if(top_stack == 100){
        cout << "Stack Overflow" << endl;
        exit(0);
    }
    stack[top_stack+1] = data;
    top_stack++;
}

int pop_stack(){
    if(top_stack == -1){
        cout << "Stack is Empty" << endl;
        return NULL;
    }
    return stack[top_stack--];
}

void in_order_traverse(node *nodeptr){
    if(nodeptr->left != nullptr){
        in_order_traverse(nodeptr->left);
    }
    // push_stack(nodeptr->data);
    cout << nodeptr->data;
    if(nodeptr->right != nullptr){
        in_order_traverse(nodeptr->right);
    }
}