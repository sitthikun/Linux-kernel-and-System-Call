#include <linux/unistd.h>
#include <stdio.h>
#include <linux/types.h>
//#include <prinfo.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define __NR_getprocessinfo 339

typedef struct prinfo prinfo;

struct prinfo {
	long state;				//current state of process
	long nice;				//process nice value
	pid_t pid;				//process id
	pid_t parent_pid;			//process id of parent
	pid_t youngest_child_pid;		//process id of youngest child
	pid_t younger_sibling_pid;		//pid of younger sibling
	pid_t older_sibling_pid;		//pid of older sibling
	unsigned long start_time;		//process start time
	long user_time;				//cpu time spent in user mode
	long sys_time;				//cpu time spent in system mode
	long cutime;				//total user time of children
	long cstime;				//total system time of children
	long uid;				//user id of process owner
	char comm[16];				//name of program executed
};



long getprocessinfo(struct prinfo *info)
{
return syscall(__NR_getprocessinfo,info);
}

int main(void)
{
struct prinfo info;
long sample;
int i,j;

for(i=0; i<=30000; i++)                /* Loop added to increase the user time of process*/
for(j=0; j<=100; j++)

sample = getprocessinfo(&info);        /* calling the system call getprocessinfo()*/


/*Printing the values of the different fields of the struct prinfo where the process information is stored*/

printf("state of current process=		%ld\n",info.state);
printf("nice value of current process=		%ld\n",info.nice);

printf("pid of current process=			%ld\n",(int)(info.pid));
printf("pid of parent process=			%ld\n",(int)(info.parent_pid));
printf("pid of youngest child=			%ld\n",info.youngest_child_pid);
printf("pid younger sibling =			%ld\n",info.younger_sibling_pid);
printf("pid of older sibling =			%ld\n",info.older_sibling_pid);
printf(" process start time of older sibling =	%ld\n",info.start_time);
printf("user time of current process=		%ld\n",info.user_time);
printf("system time of current process=		%ld\n",info.sys_time);
printf("total user time of children =		%ld\n",info.cutime);
printf("total child system time of children=	%ld\n",info.cstime);
printf("uid of current process=			%ld\n",info.uid);
printf(" name of current process=		%s\n",info.comm);

} 
