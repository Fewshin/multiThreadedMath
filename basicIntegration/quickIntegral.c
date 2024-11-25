#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "abstractSyntaxTree.h"

int main (int argc, char* argv[]) {

  return 0;
}

ast * newAST (int size) {
  int realSize = 0;

  if (size == NULL || size < 1) {
    realSize = 1;
  } else {
    realSize = size;
  }

  ast * base = malloc(sizeof(ast));
  base->root = malloc(sizeof(astNode));
  base->leaves = malloc(realSize * sizeof(astNode));

  return base;
}

int integrationParser (ast * input, int bound) {
  int result = 0;



  return result;
}
