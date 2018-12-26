/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** generic C arrays
*/

#ifndef _LBL_GTAB_H
# define _LBL_GTAB_H

# include <pthread.h>
# include <stddef.h>

# define GTAB_REALLOC_SIZE (5)

typedef struct lblgtab_s {
	size_t max_size;
	size_t len;
	void **i;
	pthread_mutex_t lock;
} gtab_t;

int gtab_create(gtab_t *gtab, size_t nsize);
void gtab_destroy(gtab_t *gtab, void (* ifct)(void *));

int gtab_resize(gtab_t *gtab, size_t newsize, void (* destructor)(void *));
void gtab_clear(gtab_t *gtab, void (* destructor)(void *));

int gtab_append(gtab_t *gtab, const void *add);
int gtab_append_at(gtab_t *gtab, const void *add, size_t index);

void gtab_remove(gtab_t *gtab, void *remove, void (* destructor)(void *));
void gtab_remove_at(gtab_t *gtab, size_t index, void (* destructor)(void *));

int gtab_shrink_to_fit(gtab_t *gtab);
void gtab_swap(gtab_t *gtab, size_t p1, size_t p2);
int gtab_copy(const gtab_t *src, gtab_t *dest, void *(*copier)(void *),
		const void *errval);

int gtab_sappend(gtab_t *gtab, const void *add);
int gtab_sappend_at(gtab_t *gtab, const void *add, size_t pos);

int gtab_lock(gtab_t *gtab);
int gtab_unlock(gtab_t *gtab);

#endif /* !_LBL_GTAB_H */
