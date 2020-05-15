#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "ram.h"
int main()
{ 
printf("**********Cpu*****************\n");
cpu cpu;
collecte_donnees(&cpu);	

printf("cpu_user = %s\n", cpu.cpu_user );
printf("cpu_nice = %s\n", cpu.cpu_nice );
printf("cpu_system = %s\n", cpu.cpu_system );
printf("cpu_idle = %s\n", cpu.cpu_idle);
printf("cpu_iowait = %s\n", cpu.cpu_iowait);
printf("cpu_irq = %s\n", cpu.cpu_irq);
printf("cpu_softirq = %s\n", cpu.cpu_softirq);
printf("cpu_steal_time = \n");
printf("cpu_guest_system =\n") ; 


printf("**********Memory*****************\n");

mem Mem;
collecte(&Mem) ; 
	
	printf("mem_total = %s\n", Mem.mem_total );
	printf("mem_available = %s\n", Mem.mem_available);
	printf("mem_free = %s\n", Mem.mem_free);
	printf("buffers = %s\n", Mem.buffers);
	printf("cached = %s\n", Mem.cached);

return 0;
}
	

