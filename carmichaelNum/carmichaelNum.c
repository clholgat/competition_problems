#include <stdio.h>

void searchPrime(long int num);

int main(int argc, char *argv[]){
  int numCases = 0;
  long int num = 0;
  
  scanf("%d", &numCases);
  
  for(int i = 0; i < numCases; i++){
    scanf("%ld", &num);
    searchPrime(num);
  }
}

void searchPrime(long int num){
  FILE *fp = fopen("primes1.txt", "r");
  long int prime = 0;
  fscanf(fp, "%ld", &prime);
  while(prime < num){
    fscanf(fp, "%ld", &prime);
  }
  
  if(prime == num){
    printf("%ld is normal.\n", num);
  }else{
    printf("The number %ld is a Carmichael number.\n", num);
  }
  
  fclose(fp);
}
    
