/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** resize
*/

#include <stdlib.h>

#include "lgtab.h"

int gtab_resize(gtab_t *gtab, size_t newsize, void (* ifct)(void *))
{
	if (newsize == gtab->max_size)
		return (0);
	for (size_t i = newsize; i < gtab->len; ++i)
		ifct(gtab->i[i]);
	gtab->max_size = newsize;
	if (newsize < gtab->len)
		gtab->len = newsize;
	gtab->i = realloc(gtab->i, gtab->max_size * sizeof(void *));
	if (gtab->i == NULL)
		return (-1);
	return (0);
}
