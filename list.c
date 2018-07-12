/**
 * main-file for work
  * with linked list
 */

#include <stdio.h>
#include <string.h>
#include"linkedListLib.h"
#include <stdlib.h>

/** element for search*/
#define COUNT_ELEMENT 6 

int main()
{
	Node* list_head = NULL;
	int arr[] ={8,1,3,5,4,2,6,7,9,10,6};
	int cnt;
	
	/**Creating a list from an array */
	linked_list_from_array(&list_head, arr, 11);

	/** checking empty list */
	if (list_head == NULL) {
		printf("Empty list\n");
		exit(-1);
	}

	printf("Linked List:\n");
	linked_list_print_list(list_head);

	/** Sorting list */
	linked_list_sort(list_head);
	printf("Sorted list:\n");
	linked_list_print_list(list_head);

	/** insert a node with a value of 333 after the 4th element (it will be the fifth) */
	linked_list_insert(list_head, 4, 333);
	printf("List after insertion:\n");
	linked_list_print_list(list_head);

	/** adding elements in the end */
	linked_list_tail_add(list_head, 11);
	linked_list_tail_add(list_head, 12);
	linked_list_tail_add(list_head, 13);
	linked_list_tail_add(list_head, 14);
	printf("List after adding elements:\n");
	linked_list_print_list(list_head);
		
	/** delete the fifth element */
	linked_list_remove(&list_head, 4);
	printf("List after remove Nth element:\n");
	linked_list_print_list(list_head);

	/** revers list */
	linked_list_reverse(&list_head);
	printf("Reversed list:\n");
	linked_list_print_list(list_head);

	/** counting elements */
	cnt = linked_list_count_identical(list_head, 6);
	printf("Number of identical elements (value = %d) in list: %d\n", COUNT_ELEMENT, cnt);
	

	/** making list empty */
	linked_list_clear(&list_head);
	
}