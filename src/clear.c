#include "lgtab.h"

void gtab_clear(gtab_t *gtab, void (*destructor)(void *))
{
    if (destructor != NULL)
        for (size_t i = 0; i < gtab->len; ++i)
            destructor(gtab->i[i]);
    gtab->len = 0;
}
