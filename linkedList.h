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


typedef struct int_node_head
{
    // length of the list
    long len;

    // a pointer to the first node
    INT_NODE *first;

    // a pionter to the last node
    INT_NODE *last;

}INT_NODE_HEAD;



INT_NODE* new_int_node(int value);




#endif