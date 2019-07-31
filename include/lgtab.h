/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** generic C arrays
*/

#ifndef _LBL_GTAB_H
#define _LBL_GTAB_H

#include <pthread.h>
#include <stddef.h>
#include <sys/cdefs.h>

#define GTAB_REALLOC_SIZE (5)

typedef struct lblgtab_s {
	size_t max_size;
	size_t len;
	void **i;
	void (*destructor)(void *);
} gtab_t;

int gtab_create(gtab_t *gtab, size_t nsize, void (*destructor)(void *)) __THROW __nonnull((1));
void gtab_destroy(gtab_t *gtab) __THROW __nonnull((1));

int gtab_resize(gtab_t *gtab, size_t newsize) __THROW __nonnull((1));
void gtab_clear(gtab_t *gtab) __THROW __nonnull((1));

int gtab_append(gtab_t *gtab, const void *add) __THROW __nonnull((1));
int gtab_append_at(gtab_t *gtab, const void *add, size_t index) __THROW __nonnull((1));

void gtab_remove(gtab_t *gtab, void *remove) __THROW __nonnull((1));
void gtab_remove_at(gtab_t *gtab, size_t index) __THROW __nonnull((1));

int gtab_shrink_to_fit(gtab_t *gtab) __THROW __nonnull((1));
void gtab_swap(gtab_t *gtab, size_t p1, size_t p2) __THROW __nonnull((1));
int gtab_copy(const gtab_t *src, gtab_t *dest, void *(*copier)(void *), const void *errval) __THROW
	__nonnull((1, 2));

int gtab_sappend(gtab_t *gtab, const void *add) __THROW __nonnull((1));
int gtab_sappend_at(gtab_t *gtab, const void *add, size_t pos) __THROW __nonnull((1));

#endif /* !_LBL_GTAB_H */
