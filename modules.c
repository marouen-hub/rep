#include <stdio.h>

#include "modules.h"





void collecte_donnees (cpu* cpu)
{ 
	    FILE *fp;



        fp = fopen("/proc/stat","r");
	fscanf(fp, "%*s %s %s %s %s %s %s %s %s %s",
                        cpu->user,
                        cpu->nice,
                        cpu->system,
                        cpu->idle,
                        cpu->iowait,
                        cpu->irq,
                        cpu->softirq,
                        cpu->steal_time,
                        cpu->guest_system);
	fclose(fp);

}


void collecte (mem* mem)
{ 
	    int i=0;


     FILE *fm;
   fm = fopen("/proc/meminfo","r");
		while(i<6){
			switch (i)
			{
			case 1:
fscanf(fm,"  %lu \n",&mem->MemTotal)     ;			
	break;
			
			case 2:
fscanf(fm,"  %lu  \n",&mem->MemFree) ;			
	break;
			case 3:
fscanf(fm,"  %lu \n",&mem->MemAvailable)		;	
	break;
			case 4:
fscanf(fm," %lu\n",&mem->Buffers)		;	
	break;
			case 5:
fscanf(fm,"  %lu  \n",&mem->Cached)		;
		break;

			default:
				break;
			}
	i++;
		}
		fclose(fm);

}



int readStat(int pid, statStuff* s) { 


    
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

 int readStatm(int pid, struct statmStuff *s) { 
    
    const char *format = "%lu %lu %lu %lu %lu %lu %ld"; 

    char buf[256]; 
    FILE *proc; 
    sprintf(buf,"/proc/%d/statm",pid); 
    proc = fopen(buf,"r"); 
    if (proc) { 
        if (7==fscanf(proc, format, 
	    &s->size,
	    &s->resident,
	    &s->share,
	    &s->text,
	    &s->lib,
	    &s->data,
	    &s->dt
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






