#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/wait.h>

int main()
{
    while(1)
    {
        printf("[BelongAL@localhost] ");
        fflush(stdout);//刷新标准输出缓冲区
        char cmd_buff[1024] = {0};
        fgets(cmd_buff, 1023, stdin);//从标准输入读取数据
        cmd_buff[strlen(cmd_buff)-1] = '\0';
        printf("cmd:[%s]\n",cmd_buff);

        char *argv[32] = {NULL};
        int argc = 0;
        char *ptr = cmd_buff;
        while( *ptr != '\0')
        {
            if(!isspace(*ptr))
            {
                argv[argc] = ptr;
                argc++;
                while(!isspace(*ptr) && *ptr != '\0')
                {
                    ptr++;
                }
                *ptr = '\0';
            }
            ptr++;
        }
        argv[argc] = NULL;
        pid_t pid = fork();//创建子进程
        if(pid < 0)//若创建错误就重新创建
        {
            continue;
        }
        else if(pid == 0)//运行程序
        {
            execvp(argv[0],argv);
            exit(0);//若程序替换失败就直接退出(否则子进程就会变成另一个shell，一个终端不需要多个shell)
        }
        wait(NULL);

    }
    return 0;
}
