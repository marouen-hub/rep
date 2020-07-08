typedef struct cpu cpu ;

struct cpu {
	char cpu_user[50];
	char cpu_nice[50];
	char cpu_system[50];
	char cpu_idle[50];
	char cpu_iowait[50];
	char cpu_irq[50];
	char cpu_softirq[50];
	char cpu_steal_time[50];
	char cpu_guest_system[50];
		} ;
extern void collecte_donnees (cpu* cpu);

typedef struct mem mem ;

struct mem {
	char mem_total [50];
	char mem_available[50];
	char mem_free[50];
	char buffers[50];
	char cached[50];
		} ;
extern void collecte (mem* Mem);



typedef struct statStuff statStuff ;
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

extern  int readStat(int pid ,statStuff *s);

typedef struct statmStuff statmStuff ;

struct statmStuff { 
    unsigned long size; 
    unsigned long resident; 
    unsigned long share; 
    unsigned long text; 
    unsigned long lib; 
    unsigned long data; 
    unsigned long dt; 
} ; 

extern int readStatm(int pid,statmStuff *s);

