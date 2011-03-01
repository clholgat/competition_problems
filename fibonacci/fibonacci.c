#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 1024

long long unsigned int *previous;
long long unsigned int genFib(int j);


int main(int argc, char *argv[]){
  int numCases = 0;
  long long unsigned int A = 0;
  long long unsigned int B = 0;
  previous = (long long unsigned int*)calloc(MAX_ARRAY, sizeof(long long unsigned int));
  previous[0] = 1;
  previous[1] = 2;
  int num = 0;
  long long unsigned int curFib = 0;
  int j = 0;
  
  scanf("%d", &numCases);
  for(int i = 0; i < numCases; i++){
    scanf("%lld %lld", &A, &B);
    num = 0;
    curFib = 0;
    for(j = 0; curFib < A; j++){
      curFib = genFib(j);
    }
    //printf("Start %lld %d\n", curFib, j);
    num++;
    while(curFib <= B){
      j++;
      curFib = genFib(j);
      //printf("CurFib %lld %d\n", curFib, j);
      num++;
    }
    printf("%d\n", num);
  }
}

long long unsigned int genFib(int j){
  if(j >= MAX_ARRAY){
    return genFib(j-1)+genFib(j-2);
  }else if(previous[j] != 0){
    return previous[j];
  }else{
    previous[j] = genFib(j-1)+genFib(j-2);
    return previous[j];
  }
}
      
