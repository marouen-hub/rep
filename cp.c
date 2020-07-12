#include <stdlib.h>
#include <stdio.h>
#include <error.h>

struct _CPU
{
    char user[50];
    char nice[50];
    char system[50];
    char idle[50];
    char iowait[50];
    char irq[50];
    char softirq[50];
    char steal_time[50];
    char guest_system[50];
};

typedef struct _CPU CPU;

CPU *collect_data();

int main(void)
{
    CPU *cpu = collect_data();

    if (cpu != NULL)
    {
        printf("user: %s\nnice: %s\nsystem: %s\nidle: %s\niowait: %s\nirq: %s\nsoftirq: %s\nsteal_time: %s\nguest_system: %s\n",
               cpu->user,
               cpu->nice,
               cpu->system,
               cpu->idle,
               cpu->iowait,
               cpu->irq,
               cpu->softirq,
               cpu->steal_time,
               cpu->guest_system);

        free(cpu);
    }
}

CPU *collect_data()
{
    FILE *fp = fopen("/proc/stat", "r");

    if (!fp)
    {
        perror("Error: ");
        return NULL;
    }

    CPU *cpu = malloc(sizeof(CPU));

    int result = fscanf(fp, "%*s %s %s %s %s %s %s %s %s %s",
                        cpu->user,
                        cpu->nice,
                        cpu->system,
                        cpu->idle,
                        cpu->iowait,
                        cpu->irq,
                        cpu->softirq,
                        cpu->steal_time,
                        cpu->guest_system);
    if (result == -1)
    {
        perror("Error: ");
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    return cpu;
}
