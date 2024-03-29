/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	struct DynArr *dyn;
	dyn = newDynArr(20);

	char c = nextChar(s);

	while (c){
		if (c == '(')
			addDynArr(dyn, '(');
		if (c == '{')
			addDynArr(dyn, '{');
		if (c == '[')
			addDynArr(dyn, '[');


		if (c == ')'){
			if (!isEmptyDynArr(dyn)){
				if (topDynArr(dyn) == '('){
					popDynArr(dyn);
				}
				else
					return 0;
			}
			else
				return 0;
		}

		if (c == '}'){
			if (!isEmptyDynArr(dyn)){
				if (topDynArr(dyn) == '{'){
					popDynArr(dyn);
				}
				else
					return 0;
			}
			else
				return 0;
		}

		if (c == ']'){
			if (!isEmptyDynArr(dyn)){
				if (topDynArr(dyn) == '['){
					popDynArr(dyn);
				}
				else
					return 0;
			}
			else
				return 0;
		}

		c = nextChar(s);
	}

	if (isEmptyDynArr(dyn))
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	if (s == 0)
		printf("Error: argument required\n");

	else{
		res = isBalanced(s);

		if (res)
			printf("The string %s is balanced\n", s);
		else
			printf("The string %s is not balanced\n", s);
	}
	return 0;	
}

