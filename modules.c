#include <stdio.h>

#include "modules.h"





void collecte_donnees (cpu* cpu)
{ 
	    FILE *fp;
	char cputag[5];


        fp = fopen("/proc/stat","r");
	fscanf(fp,"%s %s %s %s %s %s %s %s\n",cputag, cpu->cpu_user, cpu->cpu_nice, cpu->cpu_system, cpu->cpu_idle, cpu->cpu_iowait, cpu->cpu_irq, cpu->cpu_softirq);
	fclose(fp);

}


void collecte (mem* Mem)
{ 
	    int i=0;


     FILE *fm;
   fm = fopen("/proc/meminfo","r");
		while(i<6){
			switch (i)
			{
			case 1:
fscanf(fm,"  %s  \n",Mem->mem_total)     ;			
	break;
			
			case 2:
fscanf(fm,"  %s  \n",Mem->mem_available) ;			
	break;
			case 3:
fscanf(fm,"  %s \n",Mem->mem_free)		;	
	break;
			case 4:
fscanf(fm," %s\n",Mem->buffers)		;	
	break;
			case 5:
fscanf(fm,"  %s  \n",Mem->cached)		;
		break;

			default:
				break;
			}
	i++;
		}
		fclose(fm);

}
	

