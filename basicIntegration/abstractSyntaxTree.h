#ifndef _abstractSyntaxTree_h
#define _abstractSyntaxTree_h

typedef struct xVariable {
  char symbol; //ASCII Letter or ?
  char operator; //[+, -, *, /, ^, %] or ?
  int value; //value of the variable. TODO: Ensure proper handling of the case when this struct is being used as an operator. 
} xVar;

typedef struct varTable {
  char symbol;
  int value;
} varTable;

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

char * validateInput (char * input);

ast * newAST (int size);
int freeAst (ast * freedAst);
int resizeAst (ast * resizedAst, int newSize);
int populateAst (char * input, ast * tree);
void * resolveAst (ast * tree, varTable * key);

void * createVarTable (varTable * table, char initVar, int initVal);
void * expandVarTable (char variable, int value);
void * freeVarTable (varTable * table);

int integrate (char * input, int leftBound, int rightBound);

#endif