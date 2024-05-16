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

/*
   2.Cree la función int is_valid(Node * n), para validar si un estado/nodo es válido (cumple con las restricciones del problema). Debe validar que:

   No se repitan números en las filas
   No se repitan números en las columnas
   No se repitan números en las submatrices de 3x3
   Si el estado es válido la función retorna 1, si no lo es retorna 0.

   Para marcar los números que vayan apareciendo en una fila/columna/submatriz puede usar un arreglo de enteros de largo 10 inicializado con 0s. Cada vez que aparezca un número i, verifique que la casilla i del arreglo sea igual a 0, luego márquela con un '1'. Si la casilla es '1' quiere decir que el número ya estaba marcado por lo que la fla/columna/submatriz no es válida.
*/

int is_valid(Node* n){
   int filas_check[9][9] = {0};
   int columnas_check[9][9] = {0};
   int submatriz_check[9][9] = {0};
   int i,j;
   for(i=0;i<9;i++){
      for(j=0;j<9;j++){
         int num = n->sudo[i][j];
         if(num != 0){
            //Si es distinto de 0, verificar que no se repita en la fila
            if(filas_check[i][num-1] == 1){
               return 0;
            }
            filas_check[i][num-1] = 1;
            //Verificar que no se repita en la columna
            if(columnas_check[j][num-1] == 1){
               return 0;
            }
            columnas_check[j][num-1] = 1;
            //Verificar que no se repita en la submatriz
            int submatriz_fila = i / 3;
            int submatriz_columna = j / 3;
            if(submatriz_check[submatriz_fila][submatriz_columna][num-1] == 1){
               return 0;
            }
            submatriz_check[submatriz_fila][submatriz_columna][num-1];
            
            
         }
      }
   }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
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