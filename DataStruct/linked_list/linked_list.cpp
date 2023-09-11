#include <iostream>

using namespace std;

struct s_linked_list{
    int data;
    struct s_linked_list *next;
};

typedef struct s_linked_list node;
node *start = nullptr;

node *get_node();
void create_list(int n);
void insert_beg();
void insert_end();
int count_node(node *start_ptr);
void insert_mid();
void traverse();
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
    cout << count_node(start) << endl;
    return 0;
}

node *get_node(){
    node *new_node;
    new_node = new node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = nullptr;
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
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

void insert_beg(){
    cout << "-----Inserting node at beginning-----" << endl;
    node *new_node;
    new_node = get_node();
    if(start == nullptr)
        start = new_node;
    else{
        new_node->next = start;
        start = new_node;
    }
}

void insert_end(){
    cout << "-----Inserting node at end-----" << endl;
    node *new_node, *temp;
    new_node = get_node();
    if(start == nullptr)
        start = new_node;
    else{
        temp = start;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = new_node;
    }
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
    int pos, node_ctr, ctr=1;
    node_ctr = count_node(start);
    cout << "Enter the position: ";
    cin >> pos;
    if(pos > 1 && pos <= node_ctr){
        temp = start;
        prev = start;
        while(ctr < pos){
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = new_node;
        new_node->next = temp;
    }
    else cout << "Not a valid position" << endl;
}

int count_node(node *start_ptr){
    node *temp=start_ptr;
    int ctr=1;
    if(temp == nullptr)
        return 0;
    while(temp->next != nullptr){
        temp = temp->next;
        ctr++;
    }
    return ctr;
}

void traverse(){
    cout << "The list contents from left to right:" << endl;
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    node* temp;
    temp = start;
    while(temp->next != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void delete_beg() {
    cout << "-----Deleting node at beginning-----" << endl;
    node *temp;
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else if(count_node(start) == 1){
        delete start;
        start = nullptr;
        return;
    }
    else{
        temp = start;
        start = temp->next;
        delete temp;
    }
}

void delete_end(){
    cout << "-----Deleting node at end-----" << endl;
    if(start == nullptr){
        cout << "List is empty! \n";
        return;
    }
    else if(count_node(start) == 1){
        delete start;
        start = nullptr;
        return;
    }
    node *temp, *prev;
    temp = start;
    prev = start;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
}

void delete_mid(){
    cout << "-----Deleting node in middle-----" << endl;
	if(start == nullptr){
		cout << "List is empty!" << endl;
		return;
	}
    else if(count_node(start) < 3){
        cout << "Not enough nodes to delete in the middle!" << endl;
        return;
    }
	node *temp, *prev;
    int ctr=1, pos, node_ctr;
    cout << "Enter the position: ";
    cin >> pos;
    node_ctr = count_node(start);
    if(pos > node_ctr || pos < 2){
        cout << "Invalid position" << endl;
        return;
    }
    temp = start;
    prev = start;
    while(ctr < pos){
        prev = temp;
        temp = temp->next;
        ctr++;
    }
    prev->next = temp->next;
    delete temp;
}
