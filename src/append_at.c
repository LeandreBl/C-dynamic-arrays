/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** append at
*/

#include "lgtab.h"

int gtab_append_at(gtab_t *gtab, const void *add, size_t index)
{
    if (index > gtab->len
        || (gtab->len == gtab->max_size
            && gtab_resize(gtab, gtab->len + GTAB_REALLOC_SIZE, NULL) == -1))
        return (-1);
    for (size_t i = gtab->len; i > index; --i)
        gtab->i[i] = gtab->i[i - 1];
    gtab->i[index] = (void *)add;
    ++gtab->len;
    return (0);
}
