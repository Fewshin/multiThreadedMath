#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include "varTable.h"

void * createVarTable (varTable * table, char initVar, int initVal, int * res) { //create the variable table.
  table = malloc(sizeof(varTable));
  table->size = 0;
  table->nodes = malloc(sizeof(varNode*));
  expandVarTable(table, initVar, initVal, res);
}

void * expandVarTable (varTable * table, char variable, int value, int * res) { //expand the variable table
  bool isPresent = false;
  for (int i = 0; i < table->size; i++) {
    if (table->nodes[i]->symbol == variable) {
      isPresent = true;
      printf("Variable %c is already present in the table. Call editVarTable instead.\n", variable);
      if (res != NULL) {
        *res = -1;
      }
      //No return value present to catch errors/existing cases of duplicate nodes.
    }
  }
  if (!isPresent) {
    table->size++;
    table->nodes = realloc(table->nodes, table->size * sizeof(varNode));
    table->nodes[table->size - 1] = malloc(sizeof(varNode));
    table->nodes[table->size - 1]->symbol = variable;
    table->nodes[table->size - 1]->value = value;
    if (res != NULL) {
      *res = 0;
    }
  }
}

void * editVarTable (varTable * table, char variable, int value, int * res) { //edit keys in the variable table
  bool isPresent = false;
  for (int i = 0; i < table->size; i++) {
    if (table->nodes[i]->symbol == variable) {
      isPresent = true;
      table->nodes[i]->value = value;
      if (res != NULL) {
        *res = 0;
      }
      return;
    }
  }
  if (!isPresent) {
    if (res != NULL) {
      *res = -1;
    }
    printf("Variable %c isn't present in the table. Call expandVarTable instead.\n", variable);
  }
}

void * freeVarTable (varTable * table, int * res) { //free memory allocated by the variable table
  for (int i = 0; i < table->size; i++) {
    free(table->nodes[i]);
  }
  free(table->nodes);
  free(table);
  if (res != NULL) {
    *res = 0;
  }
}