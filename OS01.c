#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include<fcntl.h>
int main()  
{  
int p1, p2, p3,p4;  
p1 = fork();  
if (p1 == 0) {  
 sleep(2);  
 printf("child[1] --> pid = %d and ppid = %d\n",   getpid(), getppid());  
}  
else {  
 p2 = fork();  
 if (p2 == 0) {  
  sleep(2);  
  printf("child[2] --> pid = %d and ppid = %d\n",  getpid(), getppid());  
}  
 else {  
  p3 = fork();  
  if (p3 == 0) {  
 sleep(2);
 printf("child[3] --> pid = %d and ppid = %d\n",  getpid(), getppid());  
  }  
else {  
 p4 = fork();  
 if (p4 == 0) {  
  printf("child[4] --> pid = %d and ppid = %d\n",  getpid(), getppid());  
   }
else{
sleep(2);
   printf("parent --> pid = %d\n", getpid());  
  }  
 }  
}  
}
return 0;  
}  

