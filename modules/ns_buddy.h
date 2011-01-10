
#define BUDDY_INVITING 	1
#define BUDDY_INVITED 	2
#define BUDDY_ACCEPTED	3
#define BUDDY_BLOCKED	4

int buddies_count(u_int32_t snid);
int buddy_add(u_int32_t buddy_snid, u_int32_t target_snid, int status);
