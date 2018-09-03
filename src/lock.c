#include "lgtab.h"

int gtab_lock(gtab_t *gtab)
{
	return (pthread_mutex_lock(gtab->lock));
}

int gtab_unlock(gtab_t *gtab)
{
	return (pthread_mutex_unlock(gtab->lock));
}