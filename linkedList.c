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


int insert_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_insert, int index)
{
    // check given index
    if (index-1 > list_head->len || index < 0)
        return 0;


    // hold the current node
    INT_NODE *curr;

    if (list_head->len - index > index)
    {
        // set the current node
        curr = list_head->first;

        // set curr to the node at the given index
        for (int curr_index = 0; curr_index < index; curr_index++)
            curr = curr->next;

        
        // insert the give index
        int_node_to_insert->next = curr;
        int_node_to_insert->previous = curr->previous;
        curr->previous->next = int_node_to_insert;
        curr->previous = int_node_to_insert;

        return 1;
    }

    else 
    {
        // set the current node
        curr = list_head->last;

        // set curr to the node at the given index
        for (int curr_index = list_head->len-1; curr_index > index; curr_index--)
            curr = curr->previous;

        
        // insert the give index
        int_node_to_insert->next = curr;
        int_node_to_insert->previous = curr->previous;
        curr->previous->next = int_node_to_insert;
        curr->previous = int_node_to_insert;

        return 1;
    }

    return 0;
}


int remove_int_node(INT_LIST_HEAD *list_head, INT_NODE *node_to_remove, bool remove)
{
    // hold the current node
    INT_NODE *curr = list_head->first;

    // check that we find the node or not
    bool find = false;


    // go to the previous node of the node that we want to remove it
    for (int i = 0; i < list_head->len; i++)
    {
        // check pointers
        if (curr->next == node_to_remove)
        {
            find = true;
            break; 
        }
        else  
            curr = curr->next;
    }


    // check that we find the node in list or not
    if (!find)
        return 0;

    
    // set pointers and remove given node from list
    curr->next = curr->next->next;
    curr->next->previous = curr->next->previous->previous;
    list_head->len--;


    if (remove) // remove the removed node from memory
        free(node_to_remove);

    else  // cut the access of the node to the list
    {
        node_to_remove->next = NULL;
        node_to_remove->previous = NULL;
    }


    return 1;
}