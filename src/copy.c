/*
** EPITECH PROJECT, 2018
** lblgtab
** File description:
** copy
*/

#include "lgtab.h"

static int use_copier(const gtab_t *src, gtab_t *dest, void *(*copier)(void *),
                      const void *errval)
{
    for (size_t i = 0; i < src->len; ++i) {
        dest->i[i] = copier(src->i[i]);
        if (dest->i[i] == errval)
            return (-1);
    }
    return (0);
}

static void no_copier(const gtab_t *src, gtab_t *dest)
{
    for (size_t i = 0; i < src->len; ++i)
        dest->i[i] = src->i[i];
}

int gtab_copy(const gtab_t *src, gtab_t *dest, void *(*copier)(void *),
              const void *errval)
{
    if (gtab_create(dest, src->max_size) == -1)
        return (-1);
    dest->len = src->len;
    if (copier != NULL)
        return (use_copier(src, dest, copier, errval));
    else
        no_copier(src, dest);
    return (0);
}