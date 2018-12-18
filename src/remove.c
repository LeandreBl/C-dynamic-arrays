/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** remove
*/

#include "lgtab.h"

void gtab_remove(gtab_t *gtab, void *ptr, void (*ifct)(void *))
{
    for (size_t i = 0; i < gtab->len; ++i)
        if (gtab->i[i] == ptr)
            gtab_remove_at(gtab, i, ifct);
}
