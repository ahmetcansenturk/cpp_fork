#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

int main()
{
//proses oluşturma 
// tek anneden 3 çocok oluşturmak iç içe prosesler oluştururuz 
// pid == 0 ise çocuk ,  pid>0 ise anne , pid<0  ise işlem başarısız olduğunu anlarız.
// getpid =proses id’sini bize döndürür. Getppid ise parent pid yani  annesinin  proses id’sini bize //döndürür.
  int pid=fork();

  if(pid>0){
  int pid2 =fork();
  if(pid2>0){
  int pid3 =fork();
  if(pid3>0){
sleep(1);
   printf("anne %d \n",getpid());

  //anne
  }
  else if(pid3==0){
  printf("cocuk proses 3 %d   anne %d \n",getpid(),getppid());
//cocuk3 
  }
  }
  else if(pid2==0){
  printf("cocuk proses 2 %d  anne %d  \n",getpid(),getppid());
//cocuk2
  }
  }
  else if(pid==0){
  printf("cocuk proses 1 %d  anne %d   \n",getpid(),getppid());
//cocuk1
  }
}
