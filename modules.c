#include <stdio.h>

#include "modules.h"





void collecte_donnees_cpu (cpu* Cpu)
{ 
	    FILE *fp;
		
	char cputag[5];
unsigned int i=0;

        fp = fopen("/proc/stat","r");
	fscanf(fp,"%s %s %s %s %s %s %s %s\n",cputag, Cpu->cpu_user, Cpu->cpu_nice, Cpu->cpu_system, Cpu->cpu_idle, Cpu->cpu_iowait, Cpu->cpu_irq, Cpu->cpu_softirq);
	fclose(fp);
				


printf("cpu_user = %s\n", Cpu->cpu_user );
printf("cpu_nice = %s\n", Cpu->cpu_nice );
printf("cpu_system = %s\n", Cpu->cpu_system );
printf("cpu_idle = %s\n", Cpu->cpu_idle);
printf("cpu_iowait = %s\n", Cpu->cpu_iowait);
printf("cpu_irq = %s\n", Cpu->cpu_irq);
printf("cpu_softirq = %s\n", Cpu->cpu_softirq);
printf("cpu_steal_time = \n");
printf("cpu_guest_system =\n") ;


}



void collecte_donnees_ram (mem* Mem)
{ 
	    unsigned int i=0;
char title[20];char value[30];char unit[5];

     FILE *fm;
   fm = fopen("/proc/meminfo","r");
		while(i<6){
			switch (i)
			{
			case 1:
fscanf(fm," %s %s %s \n",title,Mem->mem_total,unit)     ;			
	break;
			
			case 2:
fscanf(fm," %s %s %s \n",title,Mem->mem_available,unit) ;			
	break;
			case 3:
fscanf(fm," %s %s %s \n",title,Mem->mem_free,unit)		;	
	break;
			case 4:
fscanf(fm," %s %s %s \n",title,Mem->buffers,unit)		;	
	break;
			case 5:
fscanf(fm," %s %s %s \n",title,Mem->cached,unit)		;
		break;

			default:
				break;
			}
	i++;
		}
	printf("mem_total = %s\n", Mem->mem_total );
	printf("mem_available = %s\n", Mem->mem_available);
	printf("mem_free = %s\n", Mem->mem_free);
	printf("buffers = %s\n", Mem->buffers);
	printf("cached = %s\n", Mem->cached);
	printf("-------------\n");

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






