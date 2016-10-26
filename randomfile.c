#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


int randNum(){
  int *ans;
  int randomData= open("dev/random", O_RDONLY);
  srandom(read(randomData, ans, 4));
  close(randomData);
  return ans;
}

void printArray(int *x){
  printf("[ ");
  int i=0;
  while (i!=10){
    printf("%d, ", x[i]);
    i++;
  }
  printf("]");
}

int main(){
  int n[11];
  n[11]='\0';
  int i=0;
  while(i!=10)
    n[i]=randNum();
  printArray(n);  
  return 0;
}
