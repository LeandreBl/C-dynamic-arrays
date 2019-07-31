/*
** EPITECH PROJECT, 2018
** lbl generic tab
** File description:
** various tests
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

#include "lgtab.h"

Test(gtab_create, various_tests)
{
	gtab_t tab;

	cr_assert(gtab_create(&tab, 10, NULL) == 0);
	cr_assert(tab.max_size == 10);
	cr_assert(tab.len == 0);
	gtab_destroy(&tab);

	gtab_create(&tab, 0, NULL);
	cr_assert(tab.max_size == 0);
	cr_assert(tab.len == 0);
	gtab_destroy(&tab);
}

Test(gtab_resize, various_tests)
{
	gtab_t tab;
	char *p;

	gtab_create(&tab, 5, free);
	/* In order to maintain the test, we will not use gtab_append */
	while (tab.len < tab.max_size) {
		tab.i[tab.len] = strdup("Xsalut");
		if (tab.i[tab.len] == NULL) {
			cr_log(CR_LOG_ERROR, "Not enough memory\n");
			return;
		}
		p = tab.i[tab.len];
		p[0] = tab.len + '0';
		++tab.len;
	}
	cr_assert(gtab_resize(&tab, 2) == 0);
	cr_assert(tab.len == 2);
	cr_assert(tab.max_size == 2);
	for (size_t i = 0; i < tab.len; ++i) {
		p = tab.i[i];
		cr_assert(strcmp(p + 1, "salut") == 0);
		cr_assert(p[0] == (char)('0' + i));
	}
	gtab_destroy(&tab);
}

Test(gtab_append, various_tests)
{
	gtab_t tab;
	char *p;

	gtab_create(&tab, 10, free);
	for (size_t i = 0; i < tab.max_size; ++i) {
		p = strdup("toto.blop.");
		if (p == NULL) {
			cr_log(CR_LOG_ERROR, "Not enough memory\n");
			return;
		}
		p[4] = i + '0';
		p[9] = '9' - i;
		cr_assert(gtab_append(&tab, p) == 0);
	}
	cr_assert(tab.len == 10);
	cr_assert(tab.max_size == 10);
	for (size_t i = 0; i < tab.len; ++i) {
		p = tab.i[i];
		cr_assert(strncmp(p, "toto", 4) == 0);
		cr_assert(p[4] == (char)i + '0');
		cr_assert(strncmp(p + 5, "blop", 4) == 0);
		cr_assert(p[9] == '9' - (char)i);
	}
	gtab_destroy(&tab);
}

Test(gtab_append_at, various_tests)
{
	gtab_t tab;

	gtab_create(&tab, 0, NULL);
	for (size_t i = 0; i < 5; ++i)
		gtab_append(&tab, (void *)i);

	cr_assert(gtab_append_at(&tab, (void *)51, 2) == 0);
	cr_assert(gtab_append_at(&tab, (void *)12, 0) == 0);
	cr_assert(gtab_append_at(&tab, (void *)89, 5) == 0);

	cr_assert(gtab_append_at(&tab, (void *)42, 56) == -1);
	cr_assert(gtab_append_at(&tab, (void *)42, 200) == -1);

	cr_assert(tab.len == 8);
	cr_assert(tab.max_size >= 8);
	// [ 0] [ 1] [ 2] [ 3] [ 4] [ 5]
	// [ 0] [ 1] [51] [ 2] [ 3] [ 4] [ 5]
	// [12] [ 0] [ 1] [51] [ 2] [ 3] [ 4] [ 5]
	// [12] [ 0] [ 1] [51] [ 2] [89] [ 3] [ 4] [ 5]
	cr_assert((long)tab.i[3] == 51);
	cr_assert((long)tab.i[0] == 12);
	cr_assert((long)tab.i[5] == 89);
	gtab_destroy(&tab);
}

Test(gtab_remove, various_test)
{
	gtab_t tab;

	gtab_create(&tab, 0, NULL);
	for (size_t i = 0; i < 100; ++i)
		gtab_append(&tab, (void *)i);
	gtab_remove(&tab, (void *)50);
	gtab_remove(&tab, (void *)6);
	for (size_t i = 0; i < tab.len; ++i)
		cr_assert((long)tab.i[i] != 50 && (long)tab.i[i] != 6);
	gtab_destroy(&tab);
}

Test(gtab_remove_at, various_tests)
{
	gtab_t tab;

	gtab_create(&tab, 0, NULL);
	for (size_t i = 0; i < 100; ++i)
		gtab_append(&tab, (void *)i);
	gtab_remove_at(&tab, 78);
	gtab_remove_at(&tab, 21);
	gtab_remove_at(&tab, 0);
	for (size_t i = 0; i < tab.len; ++i)
		cr_assert((long)tab.i[i] != 78 && (long)tab.i[i] != 21 && (long)tab.i[i] != 0);
	gtab_destroy(&tab);
}

Test(gtab_shrink_to_fit, various_tests)
{
	gtab_t tab;

	gtab_create(&tab, 500, NULL);
	for (size_t i = 0; i < 42; ++i)
		gtab_append(&tab, NULL);
	cr_assert(gtab_shrink_to_fit(&tab) == 0);
	cr_assert(tab.len == 42);
	cr_assert(tab.max_size == 42);
	gtab_destroy(&tab);
}

Test(gtab_swap, various_tests)
{
	gtab_t tab;

	gtab_create(&tab, 3, NULL);
	for (size_t i = 0; i < tab.max_size; ++i)
		gtab_append(&tab, (void *)i);
	gtab_swap(&tab, 2, 0);
	cr_assert((long)tab.i[0] == 2);
	cr_assert((long)tab.i[2] == 0);
	gtab_destroy(&tab);
}

Test(gtab_copy, various_tests)
{
	gtab_t tab;
	gtab_t cpy;
	char *p;

	gtab_create(&tab, 5, free);
	for (size_t i = 0; i < tab.max_size; ++i) {
		p = strdup("totoX");
		p[4] = i + '0';
		gtab_append(&tab, p);
	}
	cr_assert(gtab_copy(&tab, &cpy, (void *(*)(void *))strdup, NULL) == 0);
	cr_assert(cpy.len == 5);
	cr_assert(cpy.max_size >= 5);
	for (size_t i = 0; i < cpy.max_size; ++i) {
		p = cpy.i[i];
		cr_assert(strncmp(p, "toto", 4) == 0);
		cr_assert(p[4] == (char)i + '0');
		cr_assert(cpy.i[i] != tab.i[i]);
	}
	gtab_destroy(&tab);
	gtab_destroy(&cpy);
}

Test(gtab_sappend, various_tests)
{
	gtab_t tab;

	gtab_create(&tab, 0, NULL);
	for (size_t i = 0; i < 10; ++i)
		gtab_append(&tab, (void *)i);
	cr_assert(gtab_sappend(&tab, (void *)9) == -1);
	cr_assert(gtab_sappend(&tab, (void *)0) == -1);
	cr_assert(gtab_sappend(&tab, (void *)5) == -1);
	cr_assert(gtab_sappend(&tab, (void *)4) == -1);

	cr_assert(gtab_sappend(&tab, (void *)10) == 0);
	cr_assert(gtab_sappend(&tab, (void *)21) == 0);

	cr_assert(gtab_sappend(&tab, (void *)10) == -1);
	cr_assert(gtab_sappend(&tab, (void *)21) == -1);
	gtab_destroy(&tab);
}

Test(gtab_clear, simple_clear)
{
	gtab_t tab;

	gtab_create(&tab, 5, free);

	for (size_t i = 0; i < 10; ++i)
		gtab_append(&tab, strdup("toto"));
	gtab_clear(&tab);
	cr_assert(tab.len == 0);
	gtab_destroy(&tab);
}