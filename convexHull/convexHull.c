#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct point{
  int x;
  int y;
  double change;
} *Point;

int ccw(Point one, Point two, Point three);
void cotan(Point one, Point two);
void arrRem(int j, Point *points, int num);
int sortChange(const void *a, const void *b);

int main(int argc, char *argv[]){
  int numSets = 0;
  int set = 0;
  int numPoints = 0;
  int first = 0;
  Point *points;
  Point *hull;
  int numHull = 0;
  Point start = NULL;
  Point temp = NULL;
  
  
  scanf("%d", &numSets);
  for(int i = 0; i < numSets; i++){
    scanf("%d %d", &set, &numPoints);
    points = (Point*)malloc(sizeof(Point)*numPoints);
    hull = (Point*)malloc(sizeof(Point)*numPoints);
    for(int j = 0; j < numPoints; j++){
      points[j] = (Point)malloc(sizeof(struct point));
      scanf("%d %d", &points[j]->x, &points[j]->y);
      if(start == NULL){
        start = points[j];
        first = j;
      }else if(start->y == points[j]->y){
        if(start->x < points[j]->x){
          start = points[j];
          first = j;
        }
      }else if(start->y > points[j]->y){
        start = points[j];
        first = j;
      }
    }
    temp = points[0];
    points[0] = points[first];
    points[first] = temp;
    for(int j = 1; j < numPoints; j++){
      cotan(points[0], points[j]);
    }
    qsort(points+1, numPoints-1, sizeof(Point), sortChange);
    numHull = 2;
    for(int j = 3; j < numPoints; j++){
      while(ccw(points[numHull-1], points[numHull], points[j]) <= 0){
        if(numHull == 2){
          temp = points[numHull];
          points[numHull] = points[j];
          points[j] = temp;
          j++;
        }else{
          numHull--;
        }
      }
      numHull++;
      temp = points[numHull];
      first = numHull;
      points[numHull] = points[j];
      points[j] = temp;
    }
    for(int j = 0; j < numHull; j++){
      if(temp->y < points[j]->y){
        temp = points[j];
        first = j;
      }else if(temp->y == points[j]->y){
        if(temp->x > points[j]->x){
          temp = points[j];
          first = j;
        }
      }
    }
    printf("%d %d\n", set, numHull);
    printf("%d %d\n", points[first]->x, points[first]->y);
    for(int j = first-1; points[j] != points[first]; j = ((j-1)%numHull+numHull)%numHull){
      printf("%d %d\n", points[j]->x, points[j]->y);
    }      
    
  }
}

int ccw(Point one, Point two, Point three){
  return (two->x-one->x)*(three->y-one->y)-(two->y-one->y)*(three->x-one->x);
}

void cotan(Point one, Point two){
  if(one->y != two->y){
    two->change = (double)(one->x-two->x)/(double)(one->y-two->y);
  }else{
    two->change = (double)INT_MAX;
  }
}

void arrRem(int j, Point *points, int num){
  for(int i = j; i < num-1; i++){
    points[i] = points[i+1];
  }
}
    
int sortChange(const void *a, const void *b){
  Point *pA = (Point*)a;
  Point *pB = (Point*)b;
  //printf("sort %f \n", (*pB)->change);
  return ((*pA)->change > (*pB)->change)?(-1):(1);
}
