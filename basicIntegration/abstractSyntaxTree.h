#ifndef _abstractSyntaxTree_h
#define _abstractSyntaxTree_h

#include "varTable.h"

typedef struct xVariable {
  char symbol; //ASCII Letter or ?
  char operator; //[+, -, *, /, ^, %] or ?
  int value; //value of the variable. TODO: Ensure proper handling of the case when this struct is being used as an operator. 
} xVar;

typedef struct astNode {
  astNode * leftNode;
  astNode * rightNode;
  astNode * parentNode;
  xVar value;
} astNode;

typedef struct abstractSyntaxTree {
  astNode * root;
  astNode ** leaves;
  int size;
} ast;

char * validateInput (char * input); //validates the input of the program and adjusts it to ensure AST functions work consistently.

ast * newAST (int size); //creates the AST
int freeAst (ast * freedAst); //frees the AST
int resizeAst (ast * resizedAst, int newSize); //resizes the AST
int populateAst (char * input, ast * tree); //populates the AST with input cleaned from the input validation function.
void * resolveAst (ast * tree, varTable * key, int * res); //solves the AST.

#endif