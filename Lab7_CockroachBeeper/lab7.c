#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define SLEEP_TIME   5

static char *G_signames[] = {"NONE",
                             "SIGHUP",
                             "SIGINT",
                             "SIGQUIT",
                             "SIGILL",
                             "SIGTRAP",
                             "SIGABRT",
                             "SIGEMT",
                             "SIGFPE",
                             "SIGKILL",
                             "SIGBUS",
                             "SIGSEGV",
                             "SIGSYS",
                             "SIGPIPE",
                             "SIGALRM",
                             "SIGTERM",
                             "SIGURG",
                             "SIGSTOP",
                             "SIGTSTP",
                             "SIGCONT",
                             "SIGCHLD",
                             "SIGTTIN",
                             "SIGTTOU",
                             "SIGIO",
                             "SIGXCPU",
                             "SIGXFSZ",
                             "SIGVTALRM",
                             "SIGPROF",
                             "SIGWINCH",
                             "SIGINFO",
                             "SIGUSR1",
                             "SIGUSR2",
                             NULL};

void handler(int sig) {
	printf("We made it to the handler");
	if(sig == 17){
		//SIGCHILD recieved
		//make new child
		getpid());
		parentBeeper();
	}

	if(sig == 15){
		//SIGTERM
		printf("SIGTERM recieved to %d ", getpid());
		if(getpid() == 0){
			
			kill(getpid(), SIGKILL);
			kill(getppid(), SIGKILL);
		} else{
			
			kill(getppid(), SIGKILL);
			kill(getpid(), SIGKILL);
		}
		
	}

    if (sig > 0 && sig < 32) {
       printf("%d has received signal %d (%s)\n",
               getpid(),
               sig, G_signames[sig]);
    } else {
       printf("%d Invalid signal %d\n",
              getpid(),
              sig);
    }
}

void parentBeeper(){
	int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;
    int        remains = 0;
    int        sig;
    char       whoami[50];
    pid_t      pid;
	
	
	if ((pid = fork()) == -1){
		perror("fork()");
		exit(1);
	}
	for (sig = 1; sig < 32; sig++) {
      (void)signal(sig, handler);
    }
	if(pid == 0){
		//you are the child
		childBeeper();
	} else{
		//you are the parent start beeping
		while (1) {
				   if (remains == 0) {
					  now = time(NULL);
					  t = localtime(&now);
					  printf("PARENT: %d %02d:%02d:%02d beep!\n",
						      getpid(),
						      t->tm_hour, t->tm_min, t->tm_sec);
					  remains = sleep(nap);
					} else {
					  remains = sleep(remains - 1);
					}
				}
			}
}

void childBeeper(){
//you are child, check for parent
	if(getppid() == 31410){
		parentBeeper();
	} else{
		usleep(500);
		//printf("CHJILD : %d", getpid());
		childBeeper();
	}
	
}

int main() {
    int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;
    int        remains = 0;
    int        sig;
    char       whoami[50];
    pid_t      pid;
	
	//set handler to handle all signals
    

	parentBeeper();	

	//both child and parent run this
    return 0;
}
