/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** generic C arrays
*/

#include <stdlib.h>

#include "lgtab.h"

int gtab_create(gtab_t *gtab, size_t nsize, void (*destructor)(void *))
{
  gtab->i = malloc(nsize * sizeof(void *));
  if (gtab->i == NULL)
    return (-1);
  gtab->max_size = nsize;
  gtab->len = 0;
  gtab->destructor = destructor;
  return (0);
}

void gtab_destroy(gtab_t *gtab)
{
  if (gtab->destructor != NULL)
    while (gtab->len > 0)
      gtab_remove_at(gtab, gtab->len - 1);
  free(gtab->i);
}
