#include <stdio.h>
#include <string.h>
#include <unistd.h>

void get_flag(void)
{
    printf("FLAG{you_hijacked_the_flow}\n");
    fflush(stdout);
    _exit(0);
}

void vuln(void)
{
    char buf[16];
    read(0, buf, 64);
    printf("you sent: %s\n", buf);
}

int main(void)
{
    vuln();
    printf("normal return\n");
    return 0;
}
