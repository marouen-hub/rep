typedef struct mem mem ;

struct mem {
	char mem_total [50];
	char mem_available[50];
	char mem_free[50];
	char buffers[50];
	char cached[50];
		} ;
extern void collecte (mem* Mem);
