#ifndef _varTable_h
#define _varTable_h

typedef struct varNode {
  char symbol;
  int value;
} varNode;

typedef struct varTable {
  int size;
  varNode ** nodes;
} varTable;


inline void * createVarTable (varTable * table, char initVar, int initVal, int * res); //create the variable table
inline void * expandVarTable (varTable * table, char variable, int value, int * res); //add a value to the variable table
inline void * editVarTable (varTable * table, char variable, int value, int * res); //edit a value in the variable table
inline void * freeVarTable (varTable * table, int * res); //free the memory allocated by the variable table

#endif
