#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int row = -1, col = -1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(n->sudo[i][j] == 0){
                row = i;
                col = j;
                break;
            }
        }
        if(row != -1) break; // Salir del bucle externo si encontramos una casilla vacía
    }

    // Si no se encontró ninguna casilla vacía, devolver la lista vacía
    if(row == -1) return list;

    // Generar nodos adyacentes cambiando el valor de la casilla vacía por números del 1 al 9
    for(int num = 1; num <= 9; num++){
        // Crear una copia del nodo original
        Node* adj_node = copy(n);
        // Asignar el número válido a la casilla vacía
        adj_node->sudo[row][col] = num;
        // Agregar el nodo adyacente a la lista
        appendList(list, adj_node);
    }

    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/