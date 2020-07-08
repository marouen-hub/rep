#include <stdio.h> 

// how to read and print various things in /proc
// WARNING: This code is extremely old 
// AND it has not proven useful to past students. 
// -- Prof. Couch

/////////////////////////////////
// how to read /proc/*/stat
/////////////////////////////////

struct statStuff { 
    int pid;			// %d 
    char comm[256];		// %s
    char state;			// %c
    int ppid;			// %d
    int pgrp;			// %d
    int session;		// %d
    int tty_nr;			// %d
    int tpgid;			// %d
    unsigned long flags;	// %lu
    unsigned long minflt;	// %lu
    unsigned long cminflt;	// %lu
    unsigned long majflt;	// %lu
    unsigned long cmajflt;	// %lu
    unsigned long utime;	// %lu
    unsigned long stime; 	// %lu
    long cutime;		// %ld
    long cstime;		// %ld
    long priority;		// %ld
    long nice;			// %ld
    long num_threads;		// %ld
    long itrealvalue;		// %ld
    unsigned long starttime;	// %lu
    unsigned long vsize;	// %lu
    long rss;			// %ld
    unsigned long rlim;		// %lu
    unsigned long startcode;	// %lu
    unsigned long endcode;	// %lu
    unsigned long startstack;	// %lu
    unsigned long kstkesp;	// %lu
    unsigned long kstkeip;	// %lu
    unsigned long signal;	// %lu
    unsigned long blocked;	// %lu
    unsigned long sigignore;	// %lu
    unsigned long sigcatch;	// %lu
    unsigned long wchan;	// %lu
    unsigned long nswap;	// %lu
    unsigned long cnswap;	// %lu
    int exit_signal;		// %d
    int processor;		// %d
    unsigned long rt_priority;	// %lu 
    unsigned long policy;	// %lu 
    unsigned long long delayacct_blkio_ticks;	// %llu 
} ; 

static int readStat(int pid, struct statStuff *s) { 
    
    const char *format = "%d %s %c %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %lu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %lu %lu %llu"; 

    char buf[256]; 
    FILE *proc; 
    sprintf(buf,"/proc/%d/stat",pid); 
    proc = fopen(buf,"r"); 
    if (proc) { 
        if (42==fscanf(proc, format, 
	    &s->pid,
	    s->comm,
	    &s->state,
	    &s->ppid,
	    &s->pgrp,
	    &s->session,
	    &s->tty_nr,
	    &s->tpgid,
	    &s->flags,
	    &s->minflt,
	    &s->cminflt,
	    &s->majflt,
	    &s->cmajflt,
	    &s->utime,
	    &s->stime,
	    &s->cutime,
	    &s->cstime,
	    &s->priority,
	    &s->nice,
	    &s->num_threads,
	    &s->itrealvalue,
	    &s->starttime,
	    &s->vsize,
	    &s->rss,
	    &s->rlim,
	    &s->startcode,
	    &s->endcode,
	    &s->startstack,
	    &s->kstkesp,
	    &s->kstkeip,
	    &s->signal,
	    &s->blocked,
	    &s->sigignore,
	    &s->sigcatch,
	    &s->wchan,
	    &s->nswap,
	    &s->cnswap,
	    &s->exit_signal,
	    &s->processor,
	    &s->rt_priority,
	    &s->policy,
	    &s->delayacct_blkio_ticks
	)) { 
	   fclose(proc); 
	   return 1; 
        } else { 
	   fclose(proc); 
	   return 0; 
        } 
     } else {  
	return 0; 
     } 
} 

static void printStat(FILE *out, struct statStuff *stuff) { 
    fprintf(out,"pid = %d\n", stuff->pid); 
    fprintf(out,"comm = %s\n", stuff->comm); 
    fprintf(out,"state = %c\n", stuff->state); 
    fprintf(out,"ppid = %d\n", stuff->ppid); 
    fprintf(out,"pgrp = %d\n", stuff->pgrp); 
    fprintf(out,"session = %d\n", stuff->session); 
    fprintf(out,"tty_nr = %d\n", stuff->tty_nr); 
    fprintf(out,"tpgid = %d\n", stuff->tpgid); 
    fprintf(out,"flags = %lu\n", stuff->flags); 
    fprintf(out,"minflt = %lu\n", stuff->minflt); 
    fprintf(out,"cminflt = %lu\n", stuff->cminflt); 
    fprintf(out,"majflt = %lu\n", stuff->majflt); 
    fprintf(out,"cmajflt = %lu\n", stuff->cmajflt); 
    fprintf(out,"utime = %lu\n", stuff->utime); 
    fprintf(out,"stime = %lu\n", stuff->stime); 
    fprintf(out,"cutime = %ld\n", stuff->cutime); 
    fprintf(out,"cstime = %ld\n", stuff->cstime); 
    fprintf(out,"priority = %ld\n", stuff->priority); 
    fprintf(out,"nice = %ld\n", stuff->nice); 
    fprintf(out,"num_threads = %ld\n", stuff->num_threads); 
    fprintf(out,"itrealvalue = %ld\n", stuff->itrealvalue); 
    fprintf(out,"starttime = %lu\n", stuff->starttime); 
    fprintf(out,"vsize = %lu\n", stuff->vsize); 
    fprintf(out,"rss = %ld\n", stuff->rss); 
    fprintf(out,"rlim = %lu\n", stuff->rlim); 
    fprintf(out,"startcode = %lu\n", stuff->startcode); 
    fprintf(out,"endcode = %lu\n", stuff->endcode); 
    fprintf(out,"startstack = %lu\n", stuff->startstack); 
    fprintf(out,"kstkesp = %lu\n", stuff->kstkesp); 
    fprintf(out,"kstkeip = %lu\n", stuff->kstkeip); 
    fprintf(out,"signal = %lu\n", stuff->signal); 
    fprintf(out,"blocked = %lu\n", stuff->blocked); 
    fprintf(out,"sigignore = %lu\n", stuff->sigignore); 
    fprintf(out,"sigcatch = %lu\n", stuff->sigcatch); 
    fprintf(out,"wchan = %lu\n", stuff->wchan); 
    fprintf(out,"nswap = %lu\n", stuff->nswap); 
    fprintf(out,"cnswap = %lu\n", stuff->cnswap); 
    fprintf(out,"exit_signal = %d\n", stuff->exit_signal); 
    fprintf(out,"processor = %d\n", stuff->processor); 
    fprintf(out,"rt_priority = %lu\n", stuff->rt_priority); 
    fprintf(out,"policy = %lu\n", stuff->policy); 
    fprintf(out,"delayacct_blkio_ticks = %llu\n", stuff->delayacct_blkio_ticks); 
} 
