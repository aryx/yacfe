typedef struct csum_rx_done_desc rx_done_desc;


typedef struct user_info_t {
	u_int			user_magic;
	int			event_head, event_tail;
	event_t			event[MAX_EVENTS];
	struct user_info_t	*next;
	struct pcmcia_socket	*socket;
} user_info_t;



typedef struct socket_bind_t {
    struct pcmcia_driver	*driver;
    u_char		function;
    dev_link_t		*instance;
    struct socket_bind_t *next;
} socket_bind_t;
