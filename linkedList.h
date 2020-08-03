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
#include <stdbool.h>




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


/* 
 * This function remove the given node from the given list 
 * If you set the 'free' parametr true, the given node will remove from the memory
 * (return 1 if every think is ok or return 0 if the given list dose not contain the given node)
 */
int remove_int_node(INT_LIST_HEAD *list_head, INT_NODE *node_to_remove, bool free);


/* 
 * This fuction remove first node that has the same value with given value
 * (return the removed node or return NULL if there isn't any node with given value) 
 */
INT_NODE *remove_node_by_int_value(INT_LIST_HEAD *list_head, int value);


/* This method return 1 if the given the given list, contains the given value. otherwise return 0 */
int list_contains_int_value(INT_LIST_HEAD *list_head, int value_to_check);



#endif