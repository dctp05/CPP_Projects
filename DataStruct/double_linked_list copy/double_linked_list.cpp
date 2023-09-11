#include <iostream>

using namespace std;

struct d_linked_list{
    struct d_linked_list *left;
    int data;
    struct d_linked_list *right;
};

typedef struct d_linked_list node;
node *start = nullptr;

node* get_node();
void create_list(int n);
void traverse();
void insert_beg();
void insert_end();
int count_node(node *start_ptr);
void insert_mid();
void delete_beg();
void delete_end();
void delete_mid();

int main(){
    int num_nodes;
    cout << "How many nodes in the list? " << endl;
    cin >> num_nodes;
    create_list(num_nodes);
    traverse();
    insert_beg();
    traverse();
    insert_end();
    traverse();
    insert_mid();
    traverse();
    delete_beg();
    traverse();
    delete_end();
    traverse();
    delete_mid();
    traverse();
    return 0;
}

node *get_node(){
    node *new_node;
    new_node = new node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->right = nullptr;
    new_node->left = nullptr;
    return new_node;
}

void create_list(int n){
    cout << "-----Creating " << n << " nodes-----" << endl;
    int i;
    node *new_node, *temp;
    for(i=0; i<n; i++){
        new_node = get_node();
        if (start == nullptr){
            start = new_node;
        }
        else{
            temp = start;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            temp->right = new_node;
            new_node->left = temp;
        }
    }
}

void traverse(){
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    node *temp;
    temp = start;
    cout << "The contents from left to right, then right to left: " << endl;
    while(temp->right != nullptr){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << temp->data << endl;
    while(temp->left != nullptr){
        cout << temp->data << " ";
        temp = temp->left;
    }
    cout << temp->data << endl;
}

void insert_beg(){
    cout << "-----Inserting node at beginning-----" << endl;
    node *temp, *new_node;
    new_node = get_node();
    if(start == nullptr){
        start = new_node;
        return;
    }
    temp = start;
    start = new_node;
    start->right = temp;
    temp->left = new_node;
}

void insert_end(){
    cout << "-----Inserting node at end-----" << endl;
    node *temp, *new_node;
    new_node = get_node();
    if(start == nullptr){
        start = new_node;
        return;
    }
    temp = start;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    temp->right = new_node;
    new_node->left = temp;
}

int count_node(node *start_ptr){
    node *temp=start_ptr;
    int ctr=1;
    if(temp == nullptr)
        return 0;
    while(temp->right != nullptr){
        temp = temp->right;
        ctr++;
    }
    return ctr;
}

void insert_mid(){
    cout << "-----Inserting node in middle-----" << endl;
    node *new_node;
    new_node = get_node();
    if(start == nullptr){
        start = new_node;
        return;
    }
    node *prev, *temp;
    int node_ctr, pos, ctr=1;
    node_ctr = count_node(start);
    cout << "Enter position: ";
    cin >> pos;
    if(pos > 1 && pos <= node_ctr){
        temp = start;
        prev = start;
        while(ctr < pos){
            prev = temp;
            temp = temp->right;
            ctr++;
        }
        prev->right = new_node;
        new_node->left = prev;
        new_node->right = temp;
        temp->left = new_node;
    }
    else cout << "Invalid position!" << endl;
}

void delete_beg(){
    cout << "-----Deleting node at beginning-----" << endl;
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else if(count_node(start) == 1){
        delete start;
        start = nullptr;
        return;
    }
    node *temp, *node_del;
    temp = start->right;
    node_del = start;
    start = temp;
    temp->left = nullptr;
    delete node_del;
}

void delete_end(){
    cout << "-----Deleting node at end-----" << endl;
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else if(count_node(start) == 1){
        delete start;
        start = nullptr;
        return;
    }
    node *prev, *temp;
    prev = start;
    temp = start;
    while(temp->right != nullptr){
        prev = temp;
        temp = temp->right;
    }
    prev->right = nullptr;
    delete temp;
}

void delete_mid(){
    cout << "-----Deleting node in middle-----" << endl;
    if (start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else if(count_node(start) < 3){
        cout << "Not enough nodes to delete in the middle!" << endl;
        return;
    }
    node *prev, *del, *after;
    int pos, node_ctr, ctr=1;
    node_ctr = count_node(start);
    cout << "Enter position: ";
    cin >> pos;
    if(pos > node_ctr){
        cout << "This node doesn't exist";
        return;
    }
    if(pos > 1 && pos < node_ctr){
        prev = start;
        del = start;
        after = start->right;
        while(ctr < pos){
            prev = del;
            del = del->right;
            after = after->right;
            ctr++;
        }
        prev->right = after;
        after->left = prev;
        delete del;
    }
}