#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int randNum(){
  int *ans = (int*)malloc(4);
  int randomData= open("/dev/random", O_RDONLY);
  read(randomData, ans, 4);
  close(randomData);
  int temp = *ans;
  free(ans);
  return temp;
}

void printArray(int *x){
  int i=0;
  while (i!=10){
    printf("random %d: %d\n",i, x[i]);
    i++;
  }
}

int main(){
  umask(0111);
  int fd = open("randfile.txt",O_CREAT|O_WRONLY,0666); //file for rand vals
  int rand1[10];
  int rand2[10];
  int i=0;
  printf("\nGenerating random numbers:\n");
  while(i!=10){ //populating array
    rand1[i]=randNum();
    i++;
  }
  printArray(rand1);
  printf("\nWriting numbers to file...\n");
  write(fd,rand1,40);
  close(fd);
  int fd2 = open("randfile.txt",O_RDONLY,0666);//open to read from beginning
  printf("Reading numbers from file...\n\n");
  read(fd2,rand2,40);
  close(fd2);
  printf("Verification that written values were the same:\n\n");
  printArray(rand2);
  return 0;
}
