#include<stdio.h>
#include<unistd.h>

char str[100] = {'\0'};
const char *lable="|/-\\";
int main()
{
  int i = 0;
  for(i = 0;i<100;i++)
  {
    str[i] = '#';  
    printf("\033[46;31m[%-100s][%d%%][%c]\r\033[0m",str,i+1,lable[i%4]);
    fflush(stdout);
    usleep(100000);
  }
  printf("\n");
  return 0;
}
