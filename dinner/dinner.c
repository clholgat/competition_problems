#include <stdio.h>
#include <stdlib.h>

typedef struct team{
  int order;
  int numMem;
  int *seating;
} *Team;

typedef struct table{
  int numSeats;
  int tableNum;
} *Table;

int checkDining(int numTeams, Team teams[], int numTables, Table tables[]);

int sort(const void *a, const void *b);
int sortB(const void *a, const void *b);
int sortOrder(const void *a, const void *b);
int sortInt(const void *a, const void *b);

void arrRemove(int l, Table *tables, int numTables);

int main(int argc, char *argv[]){
  int numTest = 0;
  int numTeams = 0;
  int numTables = 0;
  int newNum = 0;
  int mems = 0;
  int seats = 0;
  Table *tables;
  Team *teams;
  
  scanf("%d", &numTest);
  
  for(int i = 0; i < numTest; i++){
    scanf("%d %d", &numTeams, &numTables);
    teams = (Team*)malloc(sizeof(Team)*numTeams);
    for(int j = 0; j < numTeams; j++){
      scanf("%d", &mems);
      teams[j] = (Team)malloc(sizeof(struct team));
      teams[j]->numMem = mems;
      teams[j]->order = j;
    }
    tables = (Table*)malloc(sizeof(Table)*numTables);
    for(int j = 0; j < numTables; j++){
      scanf("%d", &seats);
      tables[j] = (Table)malloc(sizeof(struct table));
      tables[j]->numSeats = seats;
      tables[j]->tableNum = j;
    }

    newNum = checkDining(numTeams, teams, numTables, tables);
    
    for(int j = 0; j < numTeams; j++){
      if(newNum != numTables){
        free(teams[j]->seating);
      }
      free(teams[j]);
    }
    free(teams);
    for(int j = 0; j < newNum; j++){
      free(tables[j]);
    }
    free(tables);
  }
}

int checkDining(int numTeams, Team teams[], int numTables, Table tables[]){
  qsort(teams, numTeams, sizeof(Team), sort);
  qsort(tables, numTables, sizeof(Table), sortB); 

  if(teams[0]->numMem > numTables){
    printf("0\n");
    return numTables;
  }

  for(int j = 0; j < numTeams; j++){
    teams[j]->seating = (int*)malloc(sizeof(int)*teams[j]->numMem);
    for(int l = 0; l < teams[j]->numMem; l++){
      teams[j]->seating[l] = tables[l]->tableNum;
      tables[l]->numSeats--;
    }
    for(int l = 0; l < numTables; ){
      if(tables[l]->numSeats <= 0){
        arrRemove(l, tables, numTables);
        numTables--;
      }else{
        l++;
      }
    }
    if(j != numTeams-1 && numTables < teams[j+1]->numMem){
      printf("0\n");
      return numTables;
    } 
  }
  
  qsort(teams, numTeams, sizeof(Team), sortOrder);
  
  printf("1\n");
  for(int i = 0; i < numTeams; i++){
    qsort(teams[i]->seating, teams[i]->numMem, sizeof(int), sortInt);
    for(int j = 0; j < teams[i]->numMem; j++){
      printf("%d ", teams[i]->seating[j]+1);
    }
    printf("\n");
  }
  return numTables;
}

void arrRemove(int l, Table *tables, int numTables){
  free(tables[l]);
  for(int i = l; i < numTables-1; i++){
    tables[i] = tables[i+1];
  }
}

int sort(const void *a, const void *b){
  Team *tA = (Team*)a;
  Team *tB = (Team*)b;
  return (*tB)->numMem - (*tA)->numMem;
}
    
int sortB(const void *a, const void *b){
  Table *tA = (Table*)a;
  Table *tB = (Table*)b;
  return (*tB)->numSeats - (*tA)->numSeats;
}

int sortOrder(const void *a, const void *b){
  return (*((Team*)a))->order - (*((Team*)b))->order;
}

int sortInt(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}
