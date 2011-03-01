#include <stdio.h>
#include <stdlib.h>

typedef struct person{
  int num;
  struct person *next;
  struct person *last;
} *Person, pobj;

void insert(int i);
Person rem(Person you);

Person one = NULL;

int main(int argv, char *argc[]){  
  int numTest = 0;
  int k = 0;
  int n = 0;
  
  Person current = NULL;
  scanf("%d", &numTest);
  
  for(int i = 0; i < numTest; i++){
    scanf("%d %d", &n, &k);
    for(int j = 1; j <= n; j++){
      insert(j);
    }
    current = one;
    while(current->next != current){
      for(int l = 1; l <= k%n; l++){
        current = current->next;
      }
      current = rem(current);
      n--;
    }
    printf("%d\n", current->num);
    rem(current);
  }
}

void insert(int i){
  
  if(i == 1){
    one = (Person)malloc(sizeof(pobj));
    one->next = one;
    one->last = one;
    one->num = 1;
    return;
  }
  Person you = one;
  Person next;
  Person insert = (Person)malloc(sizeof(pobj));
  insert->num = i;
  for(int j = 2; j < i; j++){
    you = you->next;
  }
  next = you->next;
  next->last = insert;
  you->next = insert;
  insert->last = you;
  insert->next = next;
  return;
}

Person rem(Person you){
  Person last = you->last;
  Person next = you->next;
  last->next = next;
  next->last = last;
  //printf("removing %d\n", you->num);
  free(you);
  you = NULL;
  return next;
}
  
