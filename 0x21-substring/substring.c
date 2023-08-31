#include "substring.h"

/**
 * is_valid_substring - Check if a substring is valid based on given words.
 * @s: The string to check for a valid substring.
 * @words: An array of words to form the valid substring.
 * @word_len: The length of each word in the words array.
 * @start_idx: The starting index of the potential substring.
 * @nb_words: The number of words in the words array.
 *
 * Return: 1 if the substring is valid, 0 otherwise.
 */

int is_valid_substring(char const *s, char const **words,
int word_len, int start_idx, int nb_words) {
int word_count[256] = {0};

for (int i = 0; i < nb_words; i++)
{
int word_start = start_idx + i * word_len;
char word[word_len + 1];
strncpy(word, s + word_start, word_len);
word[word_len] = '\0';

int word_index = 0;
while (word[word_index] != '\0')
{
if (word[word_index] != words[i][word_index])
{
return (0);
}
word_index++;
}

word_count[(unsigned char)words[i][0]]++;
}

for (int i = 0; i < nb_words; i++)
{
if (word_count[(unsigned char)words[i][0]] != 1)
{
return (0);
}
}

return (1);
}

/**
 * find_substring - Find all possible substrings containing a list of words.
 * @s: The string to scan for substrings.
 * @words: An array of words to find in the substrings.
 * @nb_words: The number of elements in the words array.
 * @n: Pointer to store the number of elements in the returned array.
 *
 * Return: An allocated array of indices in s where substrings were found.
 *         If no solution is found, NULL can be returned.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int word_len = strlen(words[0]);
int s_len = strlen(s);
int max_substrings = s_len - nb_words * word_len + 1;

int *result = (int *)malloc(max_substrings * sizeof(int));
if (!result)
{
return (NULL);
}

int count = 0;
for (int i = 0; i < max_substrings; i++)
{
if (is_valid_substring(s, words, word_len, i, nb_words))
{
result[count] = i;
count++;
}
}

*n = count;
return (result);
}
