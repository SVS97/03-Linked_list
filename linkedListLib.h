/** Header-file 
 * for operations with
 * linked list
 */

 /*Include guard*/
#pragma once
#ifndef LINKED_LIST_LIB_H
#define LINKED_LIST_LIB_H

/* list structure*/
typedef struct Node {
	int value;
	struct Node *next;
} Node;

void linked_list_tail_add		(Node *list_head, int value);
void linked_list_insert			(Node *list_head, unsigned n, int val);
int  linked_list_remove			(Node **list_head, int n);
void linked_list_clear			(Node **list_head);
int linked_list_count_identical         (Node *list_head, int n);
void linked_list_reverse		(Node** list_head);
void linked_list_sort			(Node * list_head);

#pragma comment(lib, "linkedListLib.c")
#endif /* LINKED_LIST_LIB_H */



