/*
 *              In The Name of God 
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




#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


/* hold an int data */
typedef struct int_node
{
    // value of this node
    int value;

    // pointers
    struct int_node *next;
    struct int_node *previous;

}INT_NODE;


typedef struct int_list_head
{
    // length of the list
    long len;

    // a pointer to the first node
    INT_NODE *first;

    // a pionter to the last node
    INT_NODE *last;

}INT_LIST_HEAD;




/* This function create a new int node with given value and return the pointer of it */
INT_NODE *new_int_node(int value);


/* This function create a new int node head and return the pointer of it */
INT_LIST_HEAD *new_int_list_head();


/* This function add the given node to the end of the list */
void add_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_add);


/* This function insert the given node at the given index of the list */
int insert_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_insert, int index);


/* This method return 1 if the given the given list, contains the given value. otherwise return 0 */
int list_contains_int_value(INT_LIST_HEAD *list_head, int value_to_check);



#endif