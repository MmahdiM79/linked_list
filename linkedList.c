/*
 *              In The Name of God 
 * 
 * ==========================================
 * [] File Name:  linkedList.h
 * 
 * [] Creation Date:  28-07-2020
 * 
 * [] Created By:  Mohammad Mahdi Malmasi (m.mahdi.m79@gmail.com / https://github.com/MmahdiM79)
 * ==========================================
 */
/*
 *  Copyright ©️  2020  Mohammad Mahdi Malmasi.
 */



#include "linkedList.h"






//    *    int node functions    *


INT_NODE *new_int_node(int value)
{
    // create a new int node
    INT_NODE *output = (INT_NODE *) malloc(sizeof(INT_NODE));

    // set value
    output->value = value;

    // set pointers
    output->next = NULL;
    output->previous = NULL;


    return output;
}


INT_LIST_HEAD *new_int_list_head() 
{
    // create a new int node head
    INT_LIST_HEAD *output = (INT_LIST_HEAD *) malloc(sizeof(INT_LIST_HEAD));

    // set list length
    output->len = 0;

    // set pointers
    output->first = NULL;
    output->last = NULL;


    return output;
} 


void add_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_add)
{
    // set last node next pointer field
    list_head->last->next = int_node_to_add;

    // set given node privuos pointer field
    int_node_to_add->previous = list_head->last;

    // set list head last pinter field
    list_head->last = int_node_to_add;
}