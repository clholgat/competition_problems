#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
  return *(const int *)a - *(const int*)b;
}

int main(int argc, char *argv[]){
  int numSets = 0;
  int M = 0;
  int num = 0;
  int *vals = NULL;
  
  scanf("%d", &numSets);
  
  for(int i = 0; i < numSets; i++){
    scanf("%d %d", &num, &M);
    printf("%d %d\n", num, (M+1)/2);
    vals = (int*)malloc(sizeof(int)*M);
    for(int j = 0; j < M; j++){
      scanf("%d", &vals[j]);
      if(j%2 == 0){
        qsort(vals, j+1, sizeof(int), sort);
        for(int k = 0; k <= j; k++){
        }
        printf("%d ", vals[j/2]);
      }
    }
    printf("\n");
  }
}
      
