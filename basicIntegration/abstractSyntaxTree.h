#ifndef _abstractSyntaxTree_h
#define _abstractSyntaxTree_h

typedef struct astNode {
  void * leftNode;
  void * rightNode;
  void * parentNode;
} astNode;

typedef struct abstractSyntaxTree {
  astNode * root;
  astNode * leaves;
} ast;

ast * newAST (int size);

int integrationParser (ast * input, int bound);

#endif