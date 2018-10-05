#include <signal.h>
#include <stdio.h>
int main(void)
{
    signal(SIGINT,SIG_IGN);
    while(1)
       sleep(1);
    return 0;
}
