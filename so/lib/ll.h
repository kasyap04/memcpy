#include "ll.c"
#ifndef MYHEADER_H
#define MYHEADER_H


extern Node *create_node(char *key, char *data) ;

extern Node *insert_value(Node **last_node, char *key, char * data) ;

extern void display(Node* head) ;

extern void free_mem(Node *head) ;


#endif