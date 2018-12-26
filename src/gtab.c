/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** generic C arrays
*/

#include <stdlib.h>

#include "lgtab.h"

int gtab_create(gtab_t *gtab, size_t nsize)
{
    gtab->i = malloc(nsize * sizeof(void *));
    if (gtab->i == NULL)
        return (-1);
    gtab->max_size = nsize;
    gtab->len = 0;
    gtab->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    return (0);
}

void gtab_destroy(gtab_t *gtab, void (*ifct)(void *))
{
    if (ifct != NULL)
        while (gtab->len > 0)
            gtab_remove_at(gtab, gtab->len - 1, ifct);
    free(gtab->i);
}
