/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** remove at
*/

#include "lgtab.h"

void gtab_remove_at(gtab_t *gtab, size_t index)
{
	if (index > gtab->len)
		return;
	if (gtab->destructor != NULL)
		gtab->destructor(gtab->i[index]);
	for (size_t i = index; i < gtab->len - 1; ++i)
		gtab->i[i] = gtab->i[i + 1];
	--gtab->len;
}
