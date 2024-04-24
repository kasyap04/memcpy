#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *key ;
    char *data ;
    struct Node* next ;
} Node ;


Node *create_node(char *key, char *data){
    Node *node = (Node*) malloc(sizeof(Node)) ;

    if(node == NULL){
        return NULL ;

        exit(EXIT_FAILURE) ;
    }

    node->key   = key ;
    node->data  = data ;
    node->next  = NULL ;

    return node ;
}

Node *insert_value(Node **last_node, char *key, char * data){
    Node *node = create_node(key, data) ;

    Node *tmp = *last_node ;
    while(tmp->next != NULL){
        tmp = tmp->next ;
    }
    tmp->next = node ;

    printf("Last : %s-%s  new : %s\n", tmp->key, tmp->data, key) ;

    return tmp ;
}

void display(Node* head){
    Node *current = head ;

    while(current != NULL){
        printf("%s : %s\n", current->key, current->data) ;
        current = current->next ;
    }
}

void free_mem(Node *head){
    Node *current = head ;

    while(current != NULL){
        Node *tmp = current ;
        printf("%s : %s\n", current->key, current->data) ;
        free(tmp) ;
        current = current->next ;
    }

    free(current) ;
}