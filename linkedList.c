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
    if (list_head->len > 0)
    {
        // set last node next pointer field
        list_head->last->next = int_node_to_add;

        // set given node privuos pointer field
        int_node_to_add->previous = list_head->last;

        // set list head last pinter field
        list_head->last = int_node_to_add;
    }
    else 
    {
        list_head->first = int_node_to_add;
        list_head->last = int_node_to_add;
    }


    // increase length of the list
    list_head->len++;
}


int insert_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_insert, int index)
{
    // check given index
    if (index-1 > list_head->len || index < 0)
        return 0;


    // 0 index insert case
    if (index == 0)
    {
        int_node_to_insert->next = list_head->first;
        list_head->first->previous = int_node_to_insert;
        list_head->first = int_node_to_insert;

        return 1;
    }

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


int get_int_value_at_index(INT_LIST_HEAD *list_head, int index)
{
    // check given index
    if (index < 0 || index > list_head->len-1)
        return NULL;


    // hold the current node
    INT_NODE *curr;

    if (list_head->len - index > index)
    {
        // set the current node
        curr = list_head->first;

        // set curr to the node at the given index
        for (int curr_index = 0; curr_index < index; curr_index++)
            curr = curr->next;


        return curr->value;
    }

    else 
    {
        // set the current node
        curr = list_head->last;

        // set curr to the node at the given index
        for (int curr_index = list_head->len-1; curr_index > index; curr_index--)
            curr = curr->previous;

        
        return curr->value;
    }


    return NULL;
}


int remove_int_node(INT_LIST_HEAD *list_head, INT_NODE *node_to_remove, bool flush)
{
    // check that we find the node or not
    bool find = false;

    
   
    if (list_head->first == node_to_remove)  // remove first node case
    {
        list_head->first = list_head->first->next;
        list_head->first->previous = NULL;

        find = true; 
    }

    else if (list_head->last == node_to_remove) // remove last node case
    {
        list_head->last = list_head->last->previous;
        list_head->last->next = NULL;

        find = true;
    }

    else // other cases
    {
        // hold the current node
        INT_NODE *curr = list_head->first;


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
    }



    if (flush) // remove the removed node from memory
            free(node_to_remove);

    else  // cut the access of the node to the list
    {
        node_to_remove->next = NULL;
        node_to_remove->previous = NULL;
    }


    // update list len
    list_head->len--;


    return 1;
}


void remove_all_int_list(INT_LIST_HEAD *list_head)
{
    // hold the current node to remove
    INT_NODE *curr = list_head->last;

    // removing nodes
    while (curr != list_head->first)
    {
        curr = curr->previous;
        free(curr->next);
    }

    // free the first node
    free(list_head->first);
}


INT_NODE *remove_node_by_int_value(INT_LIST_HEAD *list_head, int value)
{
    // set current node 
    INT_NODE *curr = list_head->first;
    

    // iterate on all nodes
    while (curr != NULL)
    {
        // check value
        if (curr->value == value)
        {
            remove_int_node(list_head, curr, false);
            return curr;
        }
        else  
            curr = curr->next;
    }
    
    return NULL;
}


int remove_int_node_at(INT_LIST_HEAD *list_head, int index, bool flush)
{
    // check index
    if (index < 0 || index > list_head->len-1)
        return 0;


    // hold the current node
    INT_NODE *curr = list_head->first;


    // go to the node that should be removed
    for (int i = 0; i < index; i++)
        curr = curr->next;


    // set pointers to remove it
    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;


    // free form ram or not
    if (flush)
        free(curr);
    else 
    {
        curr->next = NULL;
        curr->previous = NULL;
    }

    return 1;
}


void apply_to_all_int(INT_LIST_HEAD *list_head, int (*func)(int))
{
    // hold current node
    INT_NODE *curr = list_head->first;

    while (curr != NULL)
    {
        curr->value = func(curr->value);
        curr = curr->next;
    }
}


int list_contains_int_value(INT_LIST_HEAD *list_head, int value_to_check)
{
    for (INT_NODE *curr = list_head->first; curr != NULL; curr = curr->next)
        if (curr->value == value_to_check)
            return 1;

    
    return 0;
}


int *to_int_array(INT_LIST_HEAD *list_head)
{
    // creat output array
    int output[list_head->len];

    // set output array
    for (int i = 0; i < list_head->len; i++)
        output[i] = get_int_value_at_index(list_head, i);


    return output;
}


INT_LIST_HEAD *sub_int_list(INT_LIST_HEAD *list_head, int start_index, int end_index)
{
    // check given start index
    if (start_index < 0 || start_index > list_head->len)
        return NULL;

    // check given end index
    if (end_index < 0 || end_index > list_head->len)
        return NULL;


    
    // output list head
    INT_LIST_HEAD *output = new_int_list_head();

    // set new list
    for (int i = start_index; i < end_index; i++)
        add_int_node(output, new_int_node(get_int_value_at_index(list_head, i)));

    
    return output;
}


void print_int_list(INT_LIST_HEAD *list_head, bool nextLine)
{
    // hold the current node
    INT_NODE *curr = list_head->first;


    printf("[");
    while (curr != NULL)
    {
        printf("%d, ", curr->value);
        curr = curr->next;
    }
    printf("\b\b]");
    

    // go to next line
    if (nextLine)
        printf("\n");
}


// =========================================================================================================================
