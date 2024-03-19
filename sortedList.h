#ifndef SORTEDLIST_H
#define SORTEDLIST_H

typedef struct {
    int n;
    int max;
    int *items;
} t_sorted_list;

int append(t_sorted_list *sorted_list, int number);

t_sorted_list* create_list(int max);

void realloc_list(t_sorted_list *sorted_list);

int binary_search(t_sorted_list *sorted_list, int number, int start, int end);

int insert(t_sorted_list *sorted_list,int elem ,int index);

int is_valid_index(t_sorted_list *sorted_list, int index);

int insert(t_sorted_list *sorted_list, int elem, int index);

int destroy_list(t_sorted_list *sorted_list);

void clear_list(t_sorted_list *sorted_list);

int print_list(t_sorted_list *sorted_list);

int is_empty(t_sorted_list *sorted_list);

int is_full(t_sorted_list *sorted_list);

int find_index_to_insert(t_sorted_list *sorted_list, int number);

#endif