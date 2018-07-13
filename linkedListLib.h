/** Header-file 
 * for operations with
 * linked list
 */

 /*Include guard*/
#pragma once
#ifndef LINKED_LIST_LIB_H
#define LINKED_LIST_LIB_H

/** typedef struct Node - type for node of list
 * It's a structure (Node), which include int value
 * and enclosed structure for next component
 */
typedef struct Node {
	int value;
	struct Node *next;
} Node;
/**linked_list_tail_add() - appends one element to the end of the list
 * @arg1: structure with pointer to head of the list
 * @arg2: value, which will add to the list
 *
 * Return: void type
 */
void linked_list_tail_add		(Node *list_head, int value);

/**linked_list_insert() - put node at exact position in the list
*  @arg1: structure with pointer to head of the list
*  @arg2: number of place, where element would be insert
*
* Return: void type
*/
void linked_list_insert			(Node *list_head, unsigned n, int val);

/**linked_list_remove() - removes node from list
*  @arg1: structure with pointer to head of the list
*  @arg2: number of removing element
*
* Return: int type - value of removing element
*/
int  linked_list_remove			(Node **list_head, int n);

/**linked_list_clear() - make the list empty
*  @arg1: structure with pointer to head of the list
* 
* Return: void type
*/
void linked_list_clear			(Node **list_head);

/**linked_list_count_identical() - returns the number of elements in a list, which are equal to the given one.
*  @arg1: structure with pointer to head of the list
*  @arg2: counting element
*
* Return: int type - number of identical elements
*/
int linked_list_count_identical(Node *list_head, int n);

/**linked_list_reverse() - reverse the order of items in the list.
*  @arg1: structure with pointer to head of the list
*  
*
* Return: void type
*/
void linked_list_reverse		(Node** list_head);

/**linked_list_sort() - given the compare function sorts list items.
*  @arg1: structure with pointer to head of the list
*
*
* Return: void type
*/
void linked_list_sort			(Node * list_head);

#pragma comment(lib, "linkedListLib.c")
#endif /* LINKED_LIST_LIB_H */



