#include "lgtab.h"

void gtab_clear(gtab_t *gtab, void (* destructor)(void *))
{
	gtab_resize(gtab, 0, destructor);
}
