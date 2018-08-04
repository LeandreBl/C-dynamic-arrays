/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** swap
*/

#include "lgtab.h"

void gtab_swap(gtab_t *gtab, size_t p1, size_t p2)
{
	void *tmp;

	if (p1 >= gtab->len || p2 >= gtab->len)
		return;
	tmp = gtab->i[p1];
	gtab->i[p1] = gtab->i[p2];
	gtab->i[p2] = tmp;
}
