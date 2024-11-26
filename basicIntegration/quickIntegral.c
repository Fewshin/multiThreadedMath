#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "abstractSyntaxTree.h"

int main (int argc, char* argv[]) {

  return 0;
}

char * validateInput (char * input) { //validates the homogenizes inputs for processing
  //TODO: Validate the input formula
  return input;
}

ast * newAST (int size) { //initializes the Abstract Syntax Tree
  int realSize = 0;

  if (size == NULL || size < 1) { //Checking if the input size is workable
    realSize = 1;
  } else {
    realSize = size;
  }

  //Allocating memory for the AST
  ast * base = malloc(sizeof(ast)); //allocate the tree structure
  base->leaves = malloc(realSize * sizeof(astNode *)); //allocate the list of leaves
  for (int i = 0; i < realSize; i++) { //allocate the memory for each of the leaves
    base->leaves[i] = malloc(sizeof(astNode));
  }
  base->root = NULL; //setting the root pointer to NULL
  base->size = realSize; //setting the size of the tree

  return base; //return the created tree
}

int freeAst (ast * freedAst) { //frees the memory for the Abstract Syntax Tree
  for (int i = 0; i < freedAst->size; i++) { //freeing the leaves
    free(freedAst->leaves[i]);
  }
  free(freedAst->leaves); //freeing the list of leaves
  free(freedAst); //freeing the tree structure

  return 0;
}

int resizeAst (ast * resizedAst, int newSize) { //resizes the memory for the Abstract Syntax Tree
  //should this even happen ever?
}

int populateAst (char * input, ast * tree) { //parses the input formula to populate the AST
  //TODO: Parse input into AST
  return 0;
}

int integrate (char * input, int bound) { //solves the integral
  int result = 0;
  //TODO: Do a reverse integral on the input, substitute in the bounds, feed the problems into two different ASTs, and solve the problems. 


  return result;
}
