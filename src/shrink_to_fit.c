/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** shrink to fit (yes its a pain to write it)
*/

#include <stdlib.h>

#include "lblgtab.h"

int gtab_shrink_to_fit(gtab_t *gtab)
{
	if (gtab->len != gtab->max_size) {
		gtab->max_size = gtab->len;
		gtab->i = realloc(gtab->i, gtab->len * sizeof(void *));
		if (gtab->i == NULL)
			return (-1);
	}
	return (0);
}
