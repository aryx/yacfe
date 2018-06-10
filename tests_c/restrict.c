extern int sigtimedwait (__const int/*sigset_t*/ *__restrict __set,
						 /*siginfo_t*/ int *__restrict __info,
						 __const struct timespec *__restrict __timeout);


extern int sigtimedwait (__const sigset_t *__restrict __set,
						 siginfo_t *__restrict __info,
						 __const struct timespec *__restrict __timeout);


