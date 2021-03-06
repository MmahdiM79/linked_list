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






//      ====================================   *   general functions   *   =====================================

void checkIndex(long index, long list_len)
{
    if (index < 0 || index > list_len-1)
        INDEX_OUT_OF_RANGE_ERROR();
}

void checkNullPointer(void *pointer)
{
    if (pointer == NULL)
        NULL_POINTER_ERROR();
}

//      ========================================================================================================












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
    // check given parameteres
    checkNullPointer(list_head);
    checkNullPointer(int_node_to_add);


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


void insert_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_insert, int index)
{
    // check the given pointers
    checkNullPointer(list_head);
    checkNullPointer(int_node_to_insert);

    // check given index
    checkIndex(index, list_head->len);




    // 0 index insert case
    if (index == 0)
    {
        int_node_to_insert->next = list_head->first;
        list_head->first->previous = int_node_to_insert;
        list_head->first = int_node_to_insert;

        // increase the len of the list
        list_head->len++;

        return;
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
    }
    else 
    {
        // set the current node
        curr = list_head->last;

        // set curr to the node at the given index
        for (int curr_index = list_head->len-1; curr_index > index; curr_index--)
            curr = curr->previous;
    }


    // insert the give index
    int_node_to_insert->next = curr;
    int_node_to_insert->previous = curr->previous;
    curr->previous->next = int_node_to_insert;
    curr->previous = int_node_to_insert;

    // increase the len of the list
    list_head->len++;
}


INT_NODE *set_int_node(INT_LIST_HEAD *list_head, INT_NODE *int_node_to_set, int index)
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(int_node_to_set);

    // check index
    checkIndex(index, list_head->len);


    
    // hold the older int node
    INT_NODE *olderNode;


    // index 0 case
    if (index == 0)
    {
        // set pointers to add new node
        olderNode = list_head->first;
        int_node_to_set->next = olderNode->next;
        int_node_to_set->previous = NULL;
        olderNode->next->previous = int_node_to_set;
        list_head->first = int_node_to_set;

        // set old node pointers
        olderNode->next = olderNode->previous = NULL;

        return olderNode;
    }

    // last index case
    if (index == list_head->len-1)
    {
        // set pointers to add new node
        olderNode = list_head->last;
        int_node_to_set->previous = olderNode->previous;
        int_node_to_set->next = NULL;
        olderNode->previous->next = int_node_to_set;
        list_head->last = int_node_to_set;

        // set old node pointers
        olderNode->previous = olderNode->next = NULL;

        return olderNode;
    }



    if (list_head->len - index > index)
    {
        olderNode = list_head->first;

        // go to the node at the given index
        for (int curr_index = 0; curr_index < index; curr_index++)
            olderNode = olderNode->next;
    }
    else
    {
        olderNode = list_head->last;

        // go to the node at the given index
        for (int curr_index = list_head->len-1; curr_index > index; curr_index--)
            olderNode = olderNode->previous;
    }


    // set pointers to add new node
    int_node_to_set->next =olderNode->next;
    int_node_to_set->previous = olderNode->previous;
    olderNode->next->previous = int_node_to_set;
    olderNode->previous->next = int_node_to_set;
    olderNode =olderNode;

    // set old node pointers
    olderNode->next = olderNode->previous = NULL;


    return olderNode;
}


void set_int_node_value(INT_LIST_HEAD *list_head, int index, int new_value)
{
    // check pointers
    checkNullPointer(list_head);

    // check the given index
    checkIndex(index, list_head->len);


        
    // hold the current node
    INT_NODE *curr = list_head->first;

    // go to the given index
    for (int i = 0; i < index; i++)
        curr = curr->next;

    // set value
    curr->value = new_value;
}


int get_int_value_at(INT_LIST_HEAD *list_head, int index)
{
    // check the given pointer
    checkNullPointer(list_head);

    // check given index
    checkIndex(index, list_head->len);



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


    return 0;
}


INT_NODE *get_int_node_at(INT_LIST_HEAD *list_head, int index)
{
    // check given pointer
    checkNullPointer(list_head);

    // check given index
    checkIndex(index, list_head->len);



    INT_NODE *curr;

    if (list_head->len - index > index)
    {
        curr = list_head->first;

        for (int i = 0; i < index; i++)
            curr = curr->next;
    }
    else 
    {
        curr = list_head->last;

        for (int i = list_head->len-1; i > index; i--)
            curr = curr->previous;
    }


    return curr;
}


void remove_int_node(INT_LIST_HEAD *list_head, INT_NODE *node_to_remove, bool flush)
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(node_to_remove);

    
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
            raiseERROR(the given int node is not available in given linked list);

        
        // set pointers and remove given node from list
        curr->next = curr->next->next;
        curr->next->previous = curr->next->previous->previous;
    }



    if (flush) // remove the removed node from memory
            free(node_to_remove);

    node_to_remove->next = NULL;
    node_to_remove->previous = NULL;


    // update list len
    list_head->len--;
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


    // set head pointers and length
    list_head->last = NULL;
    list_head->first = NULL;
    list_head->len = 0;
}


INT_NODE *remove_node_by_int_value(INT_LIST_HEAD *list_head, int value)
{
    // check pointer
    checkNullPointer(list_head);



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


INT_NODE *remove_int_node_at(INT_LIST_HEAD *list_head, int index, bool flush)
{
   // check pointer
   checkNullPointer(list_head);

   // check index
   checkIndex(index, list_head->len);




    // hold the int node that we want removed it
    INT_NODE *output;


    if (index == 0 && list_head->len != 1) // first int node case
    {
        output = list_head->first;
        list_head->first = list_head->first->next;
        list_head->first->previous = NULL;
    }

    else if (index == 0 && list_head->len == 1) // only one node case
    {
        output = list_head->first;
        list_head->first = NULL;
        list_head->last = NULL;
    }

    else if (index == list_head->len-1) // last int node case
    {
        output = list_head->last;
        list_head->last = list_head->last->previous;
        list_head->last->next = NULL;
    }

    else  // other cases
    {
        if (index < (list_head->len)/2)
        {
            output = list_head->first;

            // go to the node that should be removed
            for (int i = 0; i < index; i++)
                output = output->next;
        }
        else
        {
            output = list_head->last;

            // go to the node that should be removed
            for (int i = list_head->len-1; i > index; i--)
                output = output->previous;
        } 


        // set pointers to remove it
        output->previous->next = output->next;
        output->next->previous = output->previous;
    }



    // increase length of the linked list
    list_head->len--;



    // free form ram or not
    if (flush)
    {
        free(output);
        return NULL;
    }
    
    // else 
    output->next = NULL;
    output->previous = NULL;


    return output;
}


long remove_int_if(INT_LIST_HEAD *list_head, bool (*func)(int))
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(func);



    // hold the number of removed int nodes
    long numberOfRemovedNodes = 0;


    // check all nodes
    iNode current = list_head->first;
    while (current != NULL)
    {
        if (func(current->value))
        {
            numberOfRemovedNodes++;
            
            if (current == list_head->first)
            {
                current = current->next;
                remove_int_node(list_head, current->previous, true);
            }
            else if (current == list_head->last)
            {
                remove_int_node(list_head, current, true);
                current = NULL;
            }
            else
            {
                current = current->previous;
                current->next = current->next->next;
                free(current->next->previous);
                current->next->previous = current;
            }
        }

        current = current->next;
    }


    return numberOfRemovedNodes;
}


void apply_to_all_int(INT_LIST_HEAD *list_head, int (*func)(int))
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(func);

    
    // hold current node
    INT_NODE *curr = list_head->first;

    while (curr != NULL)
    {
        curr->value = func(curr->value);
        curr = curr->next;
    }
}


bool list_contains_int_value(INT_LIST_HEAD *list_head, int value_to_check)
{
    // check the given pointer
    checkNullPointer(list_head);


    // check values of given linked list
    INT_NODE *current = list_head->first;
    while (current != NULL)
    {
        if (current->value == value_to_check)
            return true;

        current = current->next;
    }

    
    return false;
}


int *to_int_array(INT_LIST_HEAD *list_head)
{
    // check pointer
    checkNullPointer(list_head);



    // creat output array
    int *output = (int *) malloc((list_head->len)*sizeof(int));

    // set output array
    INT_NODE *current = list_head->first;
    for (int i = 0; i < list_head->len; i++)
    {
        output[i] = current->value;
        current = current->next;
    }


    return output;
}


INT_LIST_HEAD *sub_int_list(INT_LIST_HEAD *list_head, int start_index, int end_index)
{
    // check pointer
    checkNullPointer(list_head);

    // check given indexes
    if (start_index != list_head->len)
        checkIndex(start_index, list_head->len);
    if (end_index != list_head->len)
        checkIndex(end_index, list_head->len);
    if (end_index < start_index)
        raiseERROR(end index is less than start index);



    
    // output list head
    INT_LIST_HEAD *output = new_int_list_head();

    // find the pointer of the first node in sub list
    INT_NODE *current = list_head->first;
    for (int i = 0; i < start_index; i++)
        current = current->next;

    // set new list
    for (int i = start_index; i < end_index; i++)
    {
        add_int_node(output, new_int_node(current->value));
        current = current->next;
    }

    
    return output;
}


void print_int_list(INT_LIST_HEAD *list_head, bool nextLine)
{
    // check pointers
    checkNullPointer(list_head);

    
    // empty list case
    if (list_head->len == 0)
    {
        printf("[]");
        
        if (nextLine)
            printf("\n");

        return;
    }


    
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


void merge_int_lists(INT_LIST_HEAD *list_1, INT_LIST_HEAD *list_2)
{
    // check pointers
    checkNullPointer(list_1);
    checkNullPointer(list_2);


    list_1->last->next = list_2->first;
    list_2->first->previous = list_1->last;

    list_1->last = list_2->last;
}


bool any_int_value(INT_LIST_HEAD *list_head, bool (*func)(int))
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(func);


    
    // hold the current node
    INT_NODE *curr = list_head->first;


    // check all nodes
    while (curr != NULL)
    {
        if (func(curr->value) == true)
            return true;

        curr = curr->next;
    }
    

    return false;
}


bool all_int_values(INT_LIST_HEAD *list_head, bool (*func)(int))
{
    // check pointers
    checkNullPointer(list_head);
    checkNullPointer(func);



    // hold the current node
    INT_NODE *curr = list_head->first;


    // check all nodes
    while (curr != NULL)
    {
        if (func(curr->value) == false)
            return false;

        curr = curr->next;
    }
    

    return true;
}


void reverse_int_list(INT_LIST_HEAD *list_head)
{
    // check the given pointer
    checkNullPointer(list_head);



    // hold nodes for swaping
    INT_NODE *currFirst = list_head->first;
    INT_NODE *currLast = list_head->last;

    // hold the value for swaping
    int hold;


    // swaping
    for (int i = 0; i < (list_head->len)/2; i++)
    {
        hold = currFirst->value;
        currFirst->value = currLast->value;
        currLast->value = hold;


        currFirst = currFirst->next;
        currLast = currLast->previous;
    }
}


// =========================================================================================================================
