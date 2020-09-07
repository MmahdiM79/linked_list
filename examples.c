#include "linkedList.h"




int main(int n, char *args[])
{
    /*              =============  int node functions ============              */




    //      *  create a new int list head  *

    // for each int list you need a list head
    // so first of all we make a pointer of INT_LIST_HEAD
    // for this, we use new_int_list_head() function
    INT_LIST_HEAD *head = new_int_list_head();

    // there is a easiest way to make a pointer of INT_LIST_HEAD
    // for this we used a defined string
    ilh h = new_int_list_head();




    //      *  create a new int node  *

    // now you need some int nodes for your list
    // you need the pointer of int nodes to add them to the list
    // for this we use new_int_node(int) function
    INT_NODE *intNode = new_int_node(0);

    // like INT_LIST_HEAD, 
    // there is a easiest way to make a pointer of INT_NODE
    iNode ind = new_int_node(1);




    //      *  add int nodes to the int list head  *

    // we use add_int_node(INT_LIST_HEAD *, INT_NODE *) function,
    // to add the int nodes to the list
    add_int_node(head, intNode);
    add_int_node(h, ind);

    // you can easily create and add a int node to the list in one line
    add_int_node(head, new_int_node(1));




    //      *  print an int list  *

    // with print_int_list(INT_LIST_HEAD *, bool) you can print your list in standard output(terminal)
    // set the seccond parametr 'true' if you want to go to the next line after printing the list
    printf("\n'head' linked list nodes:  ");
    print_int_list(head, true);
    printf("\n\n\n\n\n");




    //      *  insert an int node  *

    // you can also add a new int node to the middle of the list
    // for this, we use insert_int_node(INT_LIST_HEAD *, INT_NODE *, int)
    // make sure that your given index is in this range: (0, list len)
    // see the examples:

    // befor insert
    printf("'head' linked list nodes befor insert new node:  ");print_int_list(head, true);
    // insert the node
    insert_int_node(head, new_int_node(2), 0);
    // now see the result
    printf("'head' linked list nodes after insert a new node at index 0:  ");print_int_list(head, true);

    // another example
    insert_int_node(head, new_int_node(3), 1);
    printf("'head' linked list nodes after insert a new node at index 1:  ");print_int_list(head, true);
    printf("\n\n\n\n\n");
    



    //      *  set a int node at a index  *

    // you can replace an int node in your list
    // for this, we use set_int_node(INT_LIST_HEAD *, INT_NODE *, int)
    // this function returns the older int node after replace the given node
    // see examples:

    // befor set a new int node
    printf("'head' linked list nodes befor set new node:  ");print_int_list(head, true);
    // set an int node to index 0 and hold the function output
    iNode hold = set_int_node(head, new_int_node(4), 0);
    // now check the list
    printf("'head' linked list after set a new int node at index 0:  "); print_int_list(head, true);
    // now set the value of the node that set function returned
    printf("value of int node which set_int_node returns it:  %d\n", hold->value);
    printf("\n\n\n\n\n");




    //      *  set value of an int node  *

    // some times, you don't need to replace an int node.
    // only you need to change the value of it
    // for example in arrays you do this like this: array[7] = 7;
    // you can change the value of an int node by set_int_node_value(INT_LIST_HEAD *, int, int) function
    // see example:

    // befor change value of the int node
    printf("'head' linked list befor change the value of the int node at index 0:  "); print_int_list(head, true);
    // change the value
    set_int_node_value(head, 0, 40);
    // now see the result
    printf("'head' linked list after change the value of the int node at index 0:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");
    



    //      *  get the value of an int node  *

    // we save the data to use them later
    // in arrays, we can access the value with this syntax: int a = array[7];
    // you can read the value of a specific int node by get_int_value_at_index(INT_LIST_HEAD *, int) function
    // this function returns NULL if someting went wrongs
    // see example:

    printf("'head' linked list:  "); print_int_list(head, true);
    printf("value of int node at index 2:  %d\n", get_int_value_at_index(head, 2));
    printf("\n\n\n\n\n");




    //      *  remove an int node from a list  *

    // sometimes we don't need an int node in your list anymore
    // if you have pointer of that int node, you can easily remove it from list.
    // for this we use remove_int_node(INT_LIST_HEAD *, INT_NODE *, bool) function
    // if you set the last parameter 'true', that int node also will remove from the RAM
    // see example:

    // first we create a new int node
    iNode holdToRemove = new_int_node(5);
    // insert in to the list
    insert_int_node(head, holdToRemove, 2);
    // check the list
    printf("'head' list after insert the new int node at index 2:  "); print_int_list(head, true);
    // now we remove it from the list
    remove_int_node(head, holdToRemove, true);
    // and now check whats happend
    printf("'head' list after remove the added int node:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");




    //      *  clear a linked list (remove all nodes)  *

    // somtimes you need to clear all int nodes of a list
    // for this, you can use remove_all_int_list(INT_LIST_HEAD *)
    // just remember that this function also will remove all int nodes from RAM
    // see example:

    // head list befor remove all int nodes
    printf("'head' linked list befor clear it:  "); print_int_list(head, true);
    // clear it
    remove_all_int_list(head);
    // now see what happend
    printf("'head' linked list after clear it:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");





    // add some int nodes for other functions examples
    add_int_node(head, new_int_node(0));
    add_int_node(head, new_int_node(1));
    add_int_node(head, new_int_node(2));
    add_int_node(head, new_int_node(3));
    add_int_node(head, new_int_node(4));
    add_int_node(head, new_int_node(5));
    add_int_node(head, new_int_node(6));
    add_int_node(head, new_int_node(7));




    //      *  remove an int node by its value  *

    // you can remove an int node by its value
    // it's very use full when you don't have the pointer of it
    // for this, you can use remove_node_by_int_value(INT_LIST_HEAD *, int) function
    // this function remove the first int node that has the same value with your given value
    // see example:

    // first add another node with value 7
    add_int_node(head, new_int_node(7));
    // check the linked list
    printf("'head' linked list befor remove int node with value 7:  "); print_int_list(head, true);
    // remove int node
    remove_node_by_int_value(head, 7);
    // check the linked list
    printf("'head' linked list after remove int node with value 7:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");


    




    return 0; 
}
