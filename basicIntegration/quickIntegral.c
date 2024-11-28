#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "abstractSyntaxTree.c"
#include "varTable.c"

int main (int argc, char* argv[]) {

  return 0;
}

char * solveAnti (char * input) { //Solves the anti-derivative. Note: Allocates Memory.
  //TODO: Convert input into the anti-derivative. 
  char * antiDerivative = malloc(sizeof(char));

  return antiDerivative;
}

int integrate (char * input, int leftBound, int rightBound) { //solves the integral
  int result = 0;
  //TODO: Find the anti-derivative of the input, substitute in the bounds, feed the problems into two different ASTs, and solve the problems. 

  char * cleanedInput = validateInput(input);
  if (cleanedInput == "Invalid Input") {
    printf("Invalid Input: %s\n", input);
    free(cleanedInput);
    return 0;
  }

  char * antiDeriative = solveAnti(cleanedInput);
  ast * antiTree = newAST(1); //TODO: System for determining the number of leaves in the tree
  if (populateAst(antiDeriative, antiTree) == -1) {
    printf("Failed to populate the abstract syntax tree\n");
    goto exit;
  }

  pthread_t leftThread;
  pthread_create(&leftThread, NULL, resolveAst(antiTree, NULL, NULL), NULL);

  pthread_t rightThread;
  pthread_create(&rightThread, NULL, resolveAst(antiTree, NULL, NULL), NULL);

  pthread_join(leftThread, NULL);
  pthread_join(rightThread, NULL);

  exit:
  freeAst(antiTree);
  free(antiDeriative);
  free(cleanedInput);
  return result;
}
