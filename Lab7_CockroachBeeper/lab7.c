//Lab 7: Cockroach Beeper
//Author: Matt Hixon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define SLEEP_TIME   5

//global variables for pids
static pid_t parent = 0;
static pid_t child = 0;

static char *G_signames[] = {"NONE",
                             "SIGHUP",
                             "SIGINT",
                             "SIGQUIT",
                             "SIGILL",
                             "SIGTRAP",
                             "SIGABRT",
                             "SIGBUS",
                             "SIGFPE",
                             "SIGKILL",
                             "SIGUSR1",
                             "SIGSEGV",
                             "SIGUSR2",
                             "SIGPIPE",
                             "SIGALRM",
                             "SIGTERM",
                             "SIGSTKFLT",
                             "SIGCHLD",
                             "SIGCONT",
                             "SIGSTOP",
                             "SIGTSTP",
                             "SIGTTIN",
                             "SIGTTOU",
                             "SIGYRG",
                             "SIGXCPU",
                             "SIGXFSZ",
                             "SIGVTALRM",
                             "SIGPROF",
                             "SIGWINCH",
                             "SIGIO",
                             "SIGPWR",
                             "SIGSYS",
                             NULL};


void forkMe(){
	//set global variables every fork
	pid_t pid;
	if ((pid = fork()) == -1){
		//error forking
		perror("fork()");
		exit(1);
	} else if(pid == 0){
		//child
		parent = getppid();
		child = getpid();
	}else{
		//parent
		parent = getpid();
		child = pid;
	}
}

void handler(int sig) {
	//handle exceptions to act as cockroach
	if(sig == 17){
		//SIGCHILD recieved, fork another process
		printf("%d has received signal %d (%s)\n", getpid(), sig, G_signames[sig]);
		forkMe();
	} else if(sig == 15){
		//SIGTERM recieved, kill everything
		printf("%d has received signal %d (%s)\n", getpid(), sig, G_signames[sig]);

		if(getpid() == child){
			kill(parent, SIGKILL);
			kill(child, SIGKILL);
		} else {
			kill(child, SIGKILL);
			kill(parent, SIGKILL);
		}
		
	} else if (sig > 0 && sig < 32) {
		//display any other signal
       printf("%d has received signal %d (%s)\n", getpid(), sig, G_signames[sig]);
    } else {
		//error recieving signal
       printf("%d has received signal %d (%s)\n", getpid(), sig, G_signames[sig]);
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
    for (sig = 1; sig < 32; sig++) {
      (void)signal(sig, handler);
    }
	//fork process
	forkMe();
	while(1){
		if(getpid() == child){
			//Child
			usleep(500);
			//kill returns -1 if parent is dead
			if(kill(parent, 0) == -1){
				//Parent dead, fork
				forkMe();
			}
		} else{
			//Parent
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
    return 0;
}
