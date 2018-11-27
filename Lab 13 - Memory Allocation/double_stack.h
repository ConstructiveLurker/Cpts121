/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 13
 * Date: November 16, 2018
 *
 * Description: Make external functions.
*/

#ifndef _FUNCTION_PROTO

// pop a double value off the stack -- return 0 or 1 for success or failure
//extern int doubleStack_pop (double *d_p);

// push a double value on the stack
extern void doubleStack_push (double d);

// print the stack on stdout without altering
extern void doubleStack_print (void);

#define _FUNCTION_PROTO
#endif


