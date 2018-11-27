/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 13
 * Date: November 16, 2018
 *
 * Description: Make our double stack functions.
*/

#include <stdio.h>
#include <stdlib.h>

#include "double_stack.h"

// implement stack as list that we insert / remove the first element
typedef struct DoubleStack {
	struct DoubleStack *next_p;
	double d;
} DoubleStack;

static DoubleStack *doubleStackBase_p = NULL;

static DoubleStack *doubleStack_new (double d)
/* allocate and fill in a 'struct DoubleStack' node from the heap*/
{
  // malloc, we're making the size of one type, not one element
  // i.e. we're making 1 space the size of DoubleStack
	DoubleStack *doubleStack_p = malloc(1 * sizeof(DoubleStack));

	doubleStack_p->next_p = NULL;
	doubleStack_p->d = d;

	return doubleStack_p;
}

void doubleStack_push (double d)
/* see header */
{
	DoubleStack *doubleStack_p;

	doubleStack_p = doubleStack_new(d);

	doubleStack_p->next_p = doubleStackBase_p;

	doubleStackBase_p = doubleStack_p;
}

void doubleStack_print (void)
{
  DoubleStack *doubleStack_p = doubleStackBase_p; 
  
  while (doubleStack_p != NULL)
  {
    printf ("%20.14g\n", doubleStack_p->d);
    
    doubleStack_p = doubleStack_p->next_p;
  }
}

