#include <prcvar.h>

RCCondition::RCCondition(class RCLock *lock): RCBase()
{
    cv = PR_NewCondVar(lock->lock);
    PR_ASSERT(NULL != cv);
    timeout = PR_INTERVAL_NO_TIMEOUT;
}  /* RCCondition::RCCondition */
