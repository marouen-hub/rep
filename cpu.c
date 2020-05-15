#include <stdio.h>

#include "cpu.h"





void collecte_donnees (cpu* cpu)
{ 
	    FILE *fp;
	char cputag[5];


        fp = fopen("/proc/stat","r");
	fscanf(fp,"%s %s %s %s %s %s %s %s\n",cputag, cpu->cpu_user, cpu->cpu_nice, cpu->cpu_system, cpu->cpu_idle, cpu->cpu_iowait, cpu->cpu_irq, cpu->cpu_softirq);
	fclose(fp);

}


