#ifndef _abstractSyntaxTree_h
#define _abstractSyntaxTree_h

typedef struct astNode {
  void * leftNode;
  void * rightNode;
  void * parentNode;
} astNode;

typedef struct abstractSyntaxTree {
  astNode * root;
  astNode ** leaves;
  int size;
} ast;

typedef struct xVariable {
  char symbol;
  int value;
} xVar;

char * validateInput (char * input);

ast * newAST (int size);
int freeAst (ast * freedAst);
int resizeAst (ast * resizedAst, int newSize);
int populateAst (char * input, ast * tree);

int integrate (char * input, int leftBound, int rightBound);

#endif