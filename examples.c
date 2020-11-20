/*
 *                                          In The Name of God 
 * 
 * 
 * 
 * 
 * ==========================================
 * [] File Name:  examples.c
 * 
 * [] Creation Date:  16-07-2020
 * 
 * [] Created By:  Mohammad Mahdi Malmasi (m.mahdi.m79@gmail.com / https://github.com/MmahdiM79)
 * ==========================================
 */
/*
 *  Copyright ©️  2020  Mohammad Mahdi Malmasi.
 */







#include "linkedList.h"



bool isEven(int number);
int NUMx3(int number);
bool isLessThan10(int number);
bool isMoreThan0(int number);



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
    // you can read the value of a specific int node by get_int_value_at(INT_LIST_HEAD *, int) function
    // this function returns NULL if someting went wrongs
    // see example:

    printf("'head' linked list:  "); print_int_list(head, true);
    printf("value of int node at index 2:  %d\n", get_int_value_at(head, 2));
    printf("\n\n\n\n\n");




    //      *  get a node at a specific index  *

    // if you want the pointer of a node at a specific index,
    // use get_int_node_at(INT_LIST_HEAD *, int)
    // make sure that your given index is correct
    // and the given pointer isn't NULL
    // see example:

    printf("'head' linked list:  "); print_int_list(head, true);
    printf("pionter of node at index 1:  %p\n", get_int_node_at(head, 1));
    printf("value of this node:  %d\n", get_int_node_at(head, 1)->value);
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
    // if function not find the given value in list, it returns NULL
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




    //      *  remove an int node at a specific index  *

    // you can also remove an int node by its index
    // for this, you can use remove_int_node_at(INT_LIST_HEAD *, int, bool) function
    // if you want also remove it from RAM, set the last parameter 'true'
    // this function returns the removed int node
    // if you set the last parameter true, it returns NULL
    // see example:

    // befor removing
    printf("'head' linked list befor remove int node at index 5:  "); print_int_list(head, true);
    // remove int node at index 5 and hold it
    iNode holdToCheck = remove_int_node_at(head, 5, false);
    // after removing
    printf("'head' linked list after remove int node at index 5:  "); print_int_list(head, true);
    // see the value of removed int node
    printf("value of int node that function returned:  %d\n", holdToCheck->value);
    printf("\n\n\n\n\n");




    //      *  remove if has condition  *

    // you can remove int nodes that has a specific condition
    // for this, you can use remove_int_if(INT_LIST_HEAD *, bool (*)(int)) function
    // you should write a function that takes an int and returns true if that int value has the condition
    // then when you call remove_int_if function, get the pointer of your written function to it
    // this function returns the number of removed int nodes
    // see example:

    // see the list befor removing
    printf("'head' linked list befor remove Even nodes:  "); print_int_list(head, true);
    
    // we have a function which named isEven
    // this function returns true if tne given value is an Even number
    // now removing Even numbers from the list
    remove_int_if(head, isEven);

    // now see the result
    printf("'head' linked list after remove Even numbers:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");




    //      *  apply to all int node values  *

    // some times we need to do a same thing with all of the linked list values
    // for example, multiply all the values by 3
    // you can use apply_to_all_int(INT_LIST_HEAD *, int (*)(int)) function to do it
    // you should write a function that takes an int value and do what you want with it and returns the new value
    // then call the apply_to_all_function and get the pointer of your written function to it
    // see the example:

    // see the list befor removing
    printf("'head' linked list befor multiply all the valuse by 3:  "); print_int_list(head, true);

    // we have a function which named NUMx3
    // this function returns (your given number) * 3
    // now multipling all the values by 3
    apply_to_all_int(head, NUMx3);

    // now see the result
    printf("'head' linked list after multiply all the valuse by 3:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");




    //      *  check a specific value  *

    // if you need to check that your list contains a specific value,
    // you can easily use list_contains_int_value(INT_LIST_HEAD *, int)
    // this function returns true if your given list contains your given value
    // otherwise returns false
    // see example:

    // see the 'head' linked list
    printf("'head' linked list:  "); print_int_list(head, true);
    // check that linked list contains 7
    printf("is 'head' linked list contains 7 (1 means true and 0 means false):  %d\n", list_contains_int_value(head, 7));
    // check that linked list contains 9
    printf("is 'head' linked list contains 9 (1 means true and 0 means false):  %d\n", list_contains_int_value(head, 9));
    printf("\n\n\n\n\n");




    //      *  make an array from a linked list  *

    // if you want an array from your current linked list,
    // you can easily use to_int_array(INT_LIST_HEAD *) function
    // see example:

    // see the 'head' linked list
    printf("'head' linked list:  "); print_int_list(head, true);

    // make an array from it
    int *headArray = to_int_array(head);
    int headArraySize = head->len;

    // print array
    printf("the made array from 'head' linked list:  {");
    for (int i = 0; i < headArraySize; i++)
        printf("%d, ", headArray[i]);
    printf("\b\b}\n");
    printf("\n\n\n\n\n");




    //      *  create a sub linked list  *

    // you need a sublist from your linked list?
    // just create a new 'INT_LIST_HEAD *' and use
    // sub_int_list(INT_LIST_HEAD *, int, int) function
    // first int is start index and the seccond int is end index
    // see example:

    // create a sub list from 'head' linked list
    h = sub_int_list(head, 0, 3);
    // see 'head' linked list
    printf("'head' linked list:  "); print_int_list(head, true);
    // see 'h' linked list
    printf("a sub list from 'head' linked list. index 0 to 3:  "); print_int_list(h, true);
    printf("\n\n\n\n\n");




    //      *  merge 2 linked list  *

    // you can merge 2 linked list
    // its mean to add a linked list at the end of the an other linked list
    // you can do this with merge_int_lists(INT_LIST_HEAD *, INT_LIST_HEAD *) function
    // see example:

    // 'head' linked list befor merging
    printf("'head' linked list befor merging with 'h' linked list:  "); print_int_list(head, true);
    // 'head' linked list befor merging
    printf("'h' linked list befor merging:  "); print_int_list(h, true);
    // merge two linked list
    merge_int_lists(head, h);
    // 'head' linked list after merging
    printf("'head' linked list after merging with 'h' linked list:  "); print_int_list(head, true);
    // 'head' linked list after merging
    printf("'h' linked list after merging:  "); print_int_list(h, true);
    printf("\n\n\n\n\n");





    //      *  any int value function  *

    // this function is very use full to check the values of a linked list
    // any_int_value(INT_LIST_HEAD *, bool (*)(int))
    // this function returns true if at least one of the linked list values, 
    // establish the condition of the given function
    // see example:

    // see the 'head' linked list
    printf("'head' linked list:  "); print_int_list(head, true);
    // we have a function which named 'isLessThan10'
    // this function returns true if the given int value,
    // is less than 10
    // now we pass it to any_int_value function
    // and see the output
    printf("is any of the 'head' linked list values is less than 10? (1 means true and 0 means false):  %d\n",
            any_int_value(head, isLessThan10));
    printf("\n\n\n\n\n");




    //      *  all int values function  *

    // this function is very use full to check all of the values of a linked list
    // all_int_values(INT_LIST_HEAD *, bool (*)(int))
    // this function returns true if all of the linked list values, 
    // establish the condition of the given function
    // see example:

    // see the 'head' linked list
    printf("'head' linked list:  "); print_int_list(head, true);
    // we have a function which named 'isMoreThan0'
    // this function returns true if the given int value,
    // is more than 0
    // now we pass it to all_int_values function
    // and see the output
    printf("is all of the 'head' linked list values is more than 0? (1 means true and 0 means false):  %d\n",
            all_int_values(head, isMoreThan0));
    printf("\n\n\n\n\n");




    //      *  reverse your list  *

    // you can reverse your list very easily by following function:
    // reverse_int_list(INT_LIST_HEAD *)
    // see example:

    // 'head' linked list befor reversing
    printf("'head' linked list befor reversing:  "); print_int_list(head, true);
    // reverse linked list 
    reverse_int_list(head);
    // 'head' linked list after reversing
    printf("'head' linked list after reversing:  "); print_int_list(head, true);
    printf("\n\n\n\n\n");

    

    




    return 0; 
}










// used for remove_int_if function example
bool isEven(int number)
{
    return (number%2 == 0);
}

// used for apply_to_all_int function example
int NUMx3(int number)
{
    return number * 3;
}

// used for any_int_value function example
bool isLessThan10(int number)
{
    return number < 10;
}

// used for all_int_values function
bool isMoreThan0(int number)
{
    return number > 0;
}