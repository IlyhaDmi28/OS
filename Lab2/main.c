#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = getpid(); 

    for (int i = 1; i <= 1000; i++) {
        printf("PID: %d, Номер сообщения: %d\n", pid, i);
        fflush(stdout); 
        sleep(2); 
    }

    return 0;
}