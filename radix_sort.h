#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

int * radix_sort(int *, int, int);
int most_significant_binary_digit(int); // most sig index
int get_max_binary_length(int *, int); // most sig index + 1
int get_bit(int, int);

extern const int ASCENDING;
extern const int DESCENDING;

#endif
