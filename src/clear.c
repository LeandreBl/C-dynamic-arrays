#include "lgtab.h"

void gtab_clear(gtab_t *gtab)
{
  if (gtab->destructor != NULL)
    for (size_t i = 0; i < gtab->len; ++i)
      gtab->destructor(gtab->i[i]);
  gtab->len = 0;
}
