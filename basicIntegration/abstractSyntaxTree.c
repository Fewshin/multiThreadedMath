#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "abstractSyntaxTree.h"
#include "varTable.c"

char * validateInput (char * input) { //validates the homogenizes inputs for processing. NOTE: Allocates Memory
  //TODO: Validate the input formula

  char * cleanedInput = malloc(sizeof(char));

  return cleanedInput;
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
  //ex. 2x^3 + x^2 + 5x + 7
  // (1/2)x^4 + (1/3)x^3 + (5/2)x^2 + 7x

  //valid operators: [+, -, *, /, ^] Parenthesis should be handled as multiplication.

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] = '(') { //Parenthesis Handling
      char * buffer = malloc(sizeof(char)); //buffer fed to recursion
      int bSize = 1; //buffer size
      int openParen = 1; //number of open parenthesis

      ast * buffAst = malloc(sizeof(ast));

      for (int j = 0; 1; j++) { //parse through input until appropriate closing parenthesis is found.
        if (bSize < j + 1) { //resize buffer as needed
          buffer = realloc(buffer, (j + 1) * sizeof(char)); //lol
          bSize = (j + 1);
        }

        if (input[i + j + 1] == '(') { //handle the case nested parenthesis.
          buffer[j] = input[i + j + 1];
          openParen++;

        } else if (input[i + j + 1] == ')' && openParen > 1) { //if a closing parenthesis is present, pair it with an opening one (in the case of there being more than 1 opening)
          buffer[j] = input[i + j + 1];
          openParen--;

        } else if (input[i + j + 1] == ')' && openParen == 1) { //final closing parenthesis has been detected, feed the enclosed string back into the function using recursion.
          populateAst(buffer, buffAst); //TODO: Parallelize this process.
          i = i + j;
          break;

        } else  {
          buffer[j] = input[i + j + 1];

        }
      }

      //TODO: Build the sections of the tree contained by parenthesis by building them as their own tree and merging them into the parent tree. 


      //WARNING: MEMORY LEAKS POSSIBLE. Merge new nodes into the parent tree and connect root to appropriate node. 
      free(buffAst);
      free(buffer);

    } else if (1) {

    } 
  } 

  return 0;
}

void * resolveAst (ast * tree, varTable * key, int * res) { //solves the AST by substituting in the appropriate values. Use DFS.
  return;
}