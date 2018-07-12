/** 
 * Implementations of 
  *functions for work
 * with linked list
 */

#include"linkedListLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** returns a pointer to the Nth element of the list */
static Node* linked_list_get_element(Node* list_head, int element_position) {
	int counter = 0;
	while (counter < element_position && list_head) {
		list_head = list_head->next;
		counter++;
	}
	if (!list_head) {
		return NULL;
	}
	return list_head;
}
/** returns a pointer to the last element in the list */
static Node* linked_list_get_last(Node *list_head) {
	if (list_head == NULL) {
		return NULL;
	}
	while (list_head->next) {
		list_head = list_head->next;
	}
	return list_head;
}

/** returns the pointer to the penultimate element to delete the last element */
static Node* linked_list_get_last_one(Node* list_head) {
	if (list_head == NULL) {
		exit(-1);
	}
	if (list_head->next == NULL) {
		return NULL;
	}
	while (list_head->next->next) {
		list_head = list_head->next;
	}
	return list_head;
}

/** new node (element) in the list */
static void linked_list_push(Node **list_head, int data) {
	Node *tmp = (Node*)malloc(10 * sizeof(Node));
	if (tmp== NULL) {
		fprintf(stderr, "malloc failed\n");
		exit (-1);
	}
	tmp->value = data;
	tmp->next = (*list_head);
	(*list_head) = tmp;
}

/* remove the item pointed by head */
static int linked_list_pop(Node **list_head) {
	Node* prev = NULL;
	int val;
	if (list_head == NULL) {
		exit(-1);
	}
	prev = (*list_head);
	val = prev->value;
	(*list_head) = (*list_head)->next;
	free(prev);
	return val;
}

/* adds a new item to the end of the list */
 void  linked_list_tail_add(Node *list_head, int value) {
	Node *last = linked_list_get_last(list_head);
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}
 
/** removes the last item in the list */
 void linked_list_pop_back(Node **list_head) {
	Node *lastbn = NULL;
	int val = 0;
	/** get NULL */
	if (!list_head) {
		exit(-1);
	}
	/* empty list */
	if (!(*list_head)) {
		exit(-1);
	}
	lastbn = linked_list_get_last_one(*list_head);
	/** if one element in the list */
	if (lastbn == NULL) {
		val = (*list_head)->value;
		free(*list_head);
		*list_head = NULL;
	}
	else {
		val = lastbn->value;
		free(lastbn->next);
		lastbn->next = NULL;
	}
}
 
/** insert a new value into the n-th place */
 void linked_list_insert(Node *list_head, unsigned n, int val) {
	unsigned i = 0;
	Node *tmp = NULL;
	/** Find the desired item */ 
	while (i < n && list_head->next) {
		list_head = list_head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	/** If this is not the last element, then next to the next node */
	if (list_head->next) {
		tmp->next = list_head->next;
		/* else on NULL */
	}
	else {
		tmp->next = NULL;
	}
	list_head->next = tmp;
}

/** removing an element */
 int  linked_list_remove(Node **list_head, int n) {
	if (n == 0) {
		return linked_list_pop(list_head);
	}
	else {
		Node *prev = linked_list_get_element(*list_head, n - 1);
		Node *elm = prev->next;
		int val = elm->value;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}

/** deleting the list*/
 void linked_list_clear(Node **list_head) {
	while ((*list_head)->next) {
		linked_list_pop(list_head);
		*list_head = (*list_head)->next;
	}
	free(*list_head);
}

/** create a list from an array*/
 void linked_list_from_array(Node **list_head, int *arr, int size) {
	int i = size - 1;
	if (arr == NULL || size == 0) {
		exit(-1);
	}
	do {
		linked_list_push(list_head, arr[i]);
	} while (i-- != 0);
}
 
/** print list content*/
 void linked_list_print_list(const Node *list_head) {
	while (list_head) {
		printf("%d ", list_head->value);
		list_head = list_head->next;
	}
printf("\n");
}

/** counting of identical elements*/
int  linked_list_count_identical(Node *list_head, int n) {
	int c = 0;

	while (list_head->next) {
		list_head = list_head->next;
		if (list_head->value == n) {
			c++;
		}
	}
	return c;
}

/** revers of list*/
  void linked_list_reverse(Node** list_head)
{
	if (*list_head == NULL) return;
	struct Node * curr, *next, *prev = NULL;
	curr = *list_head;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list_head = prev;

}

/** bubble sort of list */
  void linked_list_sort(Node * list_head) {
	Node *p = NULL;

	if (list_head != NULL) {
		while (list_head->next != NULL) {
			p = list_head->next;

			do {
				if (p->value < list_head->value) {
					int tmp = p->value;
					p->value = list_head->value;
					list_head->value = tmp;
				}

				p = p->next;
			} while (p != NULL);

			list_head = list_head->next;
		}
	}
}
