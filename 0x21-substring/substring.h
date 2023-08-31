#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int is_valid_substring(char const *s,
char const **words, int word_len, int start_idx, int nb_words);
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
