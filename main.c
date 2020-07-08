#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modules.h"
#include <dirent.h>
#include <errno.h>

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

#include <arpa/inet.h>
int main()
{ 
while(1)
{
printf("**********Ip*****************\n");

int n;
    struct ifreq ifr;
    char array[] = "eth0";
 
    n = socket(AF_INET, SOCK_DGRAM, 0);
    //Type of address to retrieve - IPv4 IP address
    ifr.ifr_addr.sa_family = AF_INET;
    //Copy the interface name in the ifreq structure
    strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);
    //display result
    printf("IP Address is %s - %s\n" , array , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );






printf("**********MAC*****************\n");

    struct ifconf ifc;
    char buf[1024];
    int success = 0;

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1) { /* handle error*/ };

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) { /* handle error */ }

    struct ifreq* it = ifc.ifc_req;
    const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));

    for (; it != end; ++it) {
        strcpy(ifr.ifr_name, it->ifr_name);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            if (! (ifr.ifr_flags & IFF_LOOPBACK)) { // don't count loopback
                if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
                    success = 1;
                    break;
                }
            }
        }
        else { /* handle error */ }
    }

    unsigned char chMAC [6];

    if (success) memcpy(chMAC, ifr.ifr_hwaddr.sa_data, 6);

    printf("Mac: %02X:%02X:%02X:%02X:%02X:%02X\n"
       , chMAC[0], chMAC[1], chMAC[2], chMAC[3], chMAC[4], chMAC[5]);








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

 printf("**********cpu per process*****************\n");
 DIR *dir;
 int PIDN;
 struct dirent *ent;
 const char l[]="0123456789";

 if ((dir = opendir("/proc")) == NULL)
        perror("operation error");
 else 
 {
        printf(" PID      \n");

        while ((ent = readdir(dir)) != NULL)

            if(strspn(ent->d_name, l)) 
            {   
		printf("***************************\n");
                printf(" %s\n", ent->d_name);
		PIDN= atoi(ent->d_name);




		statStuff s ;
		readStat(PIDN ,&s);
		    printf("pid = %d\n", s.pid); 
		    printf("comm = %s\n", s.comm); 
		    printf("state = %c\n", s.state); 
		    printf("ppid = %d\n", s.ppid); 
		    printf("pgrp = %d\n", s.pgrp); 
		    printf("session = %d\n", s.session); 
		    printf("tty_nr = %d\n", s.tty_nr); 
		    printf("tpgid = %d\n", s.tpgid); 
		    printf("flags = %lu\n", s.flags); 
		    printf("minflt = %lu\n", s.minflt); 
		    printf("cminflt = %lu\n", s.cminflt); 
		    printf("majflt = %lu\n", s.majflt); 
		    printf("cmajflt = %lu\n", s.cmajflt); 
		    printf("utime = %lu\n", s.utime); 
		    printf("stime = %lu\n", s.stime); 
		    printf("cutime = %ld\n", s.cutime); 
		    printf("cstime = %ld\n", s.cstime); 
		    printf("priority = %ld\n", s.priority); 
		    printf("nice = %ld\n", s.nice); 
		    printf("num_threads = %ld\n", s.num_threads); 
		    printf("itrealvalue = %ld\n", s.itrealvalue); 
		    printf("starttime = %lu\n", s.starttime); 
		    printf("vsize = %lu\n", s.vsize); 
		    printf("rss = %ld\n", s.rss); 
		    printf("rlim = %lu\n", s.rlim); 
		    printf("startcode = %lu\n", s.startcode); 
		    printf("endcode = %lu\n", s.endcode); 
		    printf("startstack = %lu\n", s.startstack); 
		    printf("kstkesp = %lu\n", s.kstkesp); 
		    printf("kstkeip = %lu\n", s.kstkeip); 
		    printf("signal = %lu\n", s.signal); 
		    printf("blocked = %lu\n", s.blocked); 
		    printf("sigignore = %lu\n", s.sigignore); 
		    printf("sigcatch = %lu\n", s.sigcatch); 
		    printf("wchan = %lu\n", s.wchan); 
		    printf("nswap = %lu\n", s.nswap); 
		    printf("cnswap = %lu\n", s.cnswap); 
		    printf("exit_signal = %d\n", s.exit_signal); 
		    printf("processor = %d\n", s.processor); 
		    printf("rt_priority = %lu\n", s.rt_priority); 
		    printf("policy = %lu\n", s.policy); 
		    printf("delayacct_blkio_ticks = %llu\n", s.delayacct_blkio_ticks);


statmStuff stuff ;
readStatm(PIDN, &stuff);

printf("size = %lu\n", stuff.size); 
printf("resident = %lu\n", stuff.resident); 
printf("share = %lu\n", stuff.share); 
printf("text = %lu\n", stuff.text); 
printf("lib = %lu\n", stuff.lib); 
printf("data = %lu\n", stuff.data); 
printf("dt = %lu\n", stuff.dt); 


            }

        closedir(dir);
 }



sleep(3);
}

return 0;

}
	

