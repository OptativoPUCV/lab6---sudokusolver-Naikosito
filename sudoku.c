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
    int i, j;
    int row_check[9][10] = {0}; // Matriz para marcar números en filas
    int col_check[9][10] = {0}; // Matriz para marcar números en columnas
    int subgrid_check[9][10] = {0}; // Matriz para marcar números en submatrices 3x3

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            int num = n->sudo[i][j];
            if(num == 0) continue; // Saltar casillas vacías
            if(row_check[i][num] || col_check[j][num] || subgrid_check[(i / 3) * 3 + (j / 3)][num]){
                return 0; // Si el número ya está marcado, el estado no es válido
            }
            // Marcar número en filas, columnas y submatrices 3x3
            row_check[i][num] = 1;
            col_check[j][num] = 1;
            subgrid_check[(i / 3) * 3 + (j / 3)][num] = 1;
        }
    }

    return 1; // Si pasa todas las validaciones, el estado es válido
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
        pushBack(list, adj_node);
    }

    return list;
}


int is_final(Node* n){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(n->sudo[i][j] == 0){
                return 0; // El nodo no es un estado final
            }
        }
    }
    return 1; // El nodo es un estado final
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