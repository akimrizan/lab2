#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char name[];

void childTask(){
printf("please enter my name : ");
scanf("%s" ,name);
printf("\nmy name is %s.PPID:%d\n", name, getppid(), getpid());
}

int main(void) {
for (int i=1; i<5; i++){
pid_t pid =fork();
if(pid==0){
printf("%d.", i);
childTask();
exit(0);
}
else {
wait(NULL);
printf("next child process\n");
}
}
printf("job done\n");
return EXIT_SUCCESS;
}
