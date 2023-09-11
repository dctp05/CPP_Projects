#include <iostream>

using namespace std;

struct circ_s_linked_list{
    int data;
    struct circ_s_linked_list *next;
};

typedef struct circ_s_linked_list node;
node *start = nullptr;



