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
    // for this we use new_int_node(value) function
    INT_NODE *intNode = new_int_node(0);

    // like INT_LIST_HEAD, 
    // there is a easiest way to make a pointer of INT_NODE
    iNode ind = new_int_node(1);



    //      *  add int nodes to the int list head  *

    // we use add_int_node(INT_LIST_HEAD, INT_NODE) function,
    // to add the int nodes to the list
    add_int_node(head, intNode);
    add_int_node(h, ind);

    // you can easily create and add a int node to the list in one line
    add_int_node(head, new_int_node(1));



    //      *  print an int list  *

    // with print_int_list(INT_LIST_HEAD, bool) you can print your list in standard output(terminal)
    // set the seccond parametr 'true' if you want to go to the next line after printing the list
    printf("'head' linked list nodes:  ");
    print_int_list(head, true);





    

    return 0; 
}
