#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


int randNum(){
  unsigned int *ans = (int*)malloc(4);
  unsigned int randomData= open("/dev/random", O_RDONLY);
  read(randomData, ans, 4);
  close(randomData);
  int temp = *ans;
  free(ans);
  return temp;
}

void printArray(int *x){
  printf("generating random numbers:\n");
  int i=0;
  while (i!=10){
    printf("random %d: %u\n",i, x[i]);
    i++;
  }
}

int main(){
  int n[11];
  n[10]='\0';
  int i=0;
  while(i!=10){
    n[i]=randNum();
    i++;
  }
  printArray(n); 
  return 0;
}
