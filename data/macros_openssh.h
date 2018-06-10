

#define sshpam_const const
#define SNPRINTF_CONST const

#define __dead

//BAD:!!!!! 	RB_ENTRY(mm_share) next;
#define RB_ENTRY(a) a

//BAD:!!!!! 	RB_HEAD(mmtree, mm_share) rb_free;
#define RB_HEAD(a,b) a

//BAD:!!!!! 	TAILQ_ENTRY(packet) next;
#define TAILQ_ENTRY(a) a

//BAD:!!!!! TAILQ_HEAD(, packet) outgoing;
#define TAILQ_HEAD(a,b) a



//BAD:!!!!! 	if (timercmp(&bwstart, &bwend, >)) {
#define timercmp(a,b,op) a op b

#define LLONG long

