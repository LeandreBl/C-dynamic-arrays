/*
** EPITECH PROJECT, 2018
** lblgtab
** File description:
** sappend
*/

#include <stdbool.h>

#include "lgtab.h"

static bool already_in(gtab_t *gtab, const void *add)
{
    for (size_t i = 0; i < gtab->len; ++i)
        if (gtab->i[i] == add)
            return (true);
    return (false);
}

int gtab_sappend_at(gtab_t *gtab, const void *add, size_t pos)
{
    if (already_in(gtab, add) == true)
        return (-1);
    return (gtab_append_at(gtab, add, pos));
}

int gtab_sappend(gtab_t *gtab, const void *add)
{
    if (already_in(gtab, add) == true)
        return (-1);
    return (gtab_append(gtab, add));
}