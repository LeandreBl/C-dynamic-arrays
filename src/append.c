/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** append
*/

#include "lblgtab.h"

int gtab_append(gtab_t *gtab, const void *add)
{
	if (gtab->len == gtab->max_size &&
		gtab_resize(gtab, gtab->len + GTAB_REALLOC_SIZE, NULL) == -1)
		return (-1);
	gtab->i[gtab->len] = (void *)add;
	++gtab->len;
	return (0);
}
