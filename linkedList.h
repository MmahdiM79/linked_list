

/*
 *                                          In The Name of God 
 * 
 * 
 * 
 * 
 * ==========================================
 * [] File Name:  linkedList.h
 * 
 * [] Creation Date:  26-07-2020
 * 
 * [] Created By:  Mohammad Mahdi Malmasi (m.mahdi.m79@gmail.com / https://github.com/MmahdiM79)
 * ==========================================
 */
/*
 *  Copyright ©️  2020  Mohammad Mahdi Malmasi.
 */




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__




//      *  micros  *

// this micro raise an error with given message
#define raiseERROR(x) {printf("\n\x1b[31m \berror:  \x1b[0m"#x"\n\n"); exit(EXIT_FAILURE);}












/*      =================================== int node part ===================================       */


/* hold an int data */
typedef struct int_node
{
    // value of this node
    int value;

    // pointers
    struct int_node *next;
    struct int_node *previous;

}INT_NODE;
#define iNode INT_NODE * // a easiest way to make a pointer to the int node


typedef struct int_list_head
{
    // length of the list
    long len;

    // a pointer to the first node
    INT_NODE *first;

    // a pionter to the last node
    INT_NODE *last;

}INT_LIST_HEAD;
#define ilh INT_LIST_HEAD * // a easiest way to make a pointer to the int list head




/* This function create a new int node with given value and return the pointer of it */
INT_NODE *new_int_node(int value);


/* This function create a new int node head and return the pointer of it */
INT_LIST_HEAD *new_int_list_head();


/* This function add the given node to the end of the list */
void add_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_add);


/* This function insert the given node at the given index of the list */
int insert_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_insert, int index);


/* 
 * This function replaces the int node at the specified position in this list with the specified element 
 * This function return the older int node
 */
INT_NODE *set_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_set, int index);


/* 
 * This function set the given value to the node at the given index.
 * returns 0 if every things is ok or -1 if some your given index is invalid
 */
int set_int_node_value(INT_LIST_HEAD *list_head, int index, int new_value);


/* This function return the value at the given index. return null if your given index is wrong */
int get_int_value_at_index(INT_LIST_HEAD *list_head, int index);


/* 
 * This function remove the given node from the given list 
 * If you set the 'free' parametr true, the given node will remove from the memory
 * (return 1 if every think is ok or return 0 if the given list dose not contain the given node)
 */
int remove_int_node(INT_LIST_HEAD *list_head, INT_NODE *node_to_remove, bool flush);


/* This function remove all of the nodes and free ram */
void remove_all_int_list(INT_LIST_HEAD *list_head);


/* 
 * This fuction remove first node that has the same value with given value
 * (return the removed node or return NULL if there isn't any node with given value) 
 */
INT_NODE *remove_node_by_int_value(INT_LIST_HEAD *list_head, int value);


/* 
 * This function remove the node at given index 
 * set 'flush' true if you want to remove the node from RAM
 * This function returns 1 if every things is ok. otherwise returns 0
 */
int remove_int_node_at(INT_LIST_HEAD *list_head, int index, bool flush);


/* This function removes all of the elements of this collection that satisfy the given function */
void remove_int_if(INT_LIST_HEAD *list_head, bool (*func)(int));


/* This function apply the given function for all of the list values */
void apply_to_all_int(INT_LIST_HEAD *list_head, int (*func)(int));


/* This function return 1 if the given the given list, contains the given value. otherwise return 0 */
int list_contains_int_value(INT_LIST_HEAD *list_head, int value_to_check);


/* This function return a array of given list */
int *to_int_array(INT_LIST_HEAD *list_head);


/*
 * This function return a sub linkedlist of given linkedlist
 * example:
 *      list_head = {2, 3, 5, 8, 1, 100, 30, 7, 9}
 *      sub_int_list(list_head, 1, 5) returns {3, 5, 8, 1}
 * 
 * This function returns NULL if somting wrongs
 */
INT_LIST_HEAD *sub_int_list(INT_LIST_HEAD *list_head, int start_index, int end_index);


/* 
 * This function print the given list in terminal. 
 * Set nextLine true for going next line after print the list 
 */
void print_int_list(INT_LIST_HEAD *list_head, bool nextLine);


/* This function adds the list_2 nodes to the end of the list_1 nodes */
void merge_int_lists(INT_LIST_HEAD *list_1, INT_LIST_HEAD *list_2);


/* 
 * This function returns 'true' if the given function returns 'true' at least for one of the int nodes values
 * otherwise returns 'false'
 */
bool any_int_value(INT_LIST_HEAD *list_head, bool (*func)(int));


/*
 * This function returns 'true' if the given function returns true for all of the int values of this list
 * otherwise returns 'false'
 */
bool all_int_values(INT_LIST_HEAD *list_head, bool (*func)(int));


/* This function reverse the given list */
void reverse_int_list(INT_LIST_HEAD *list_head);


/*      ======================================================================================      */




#endif