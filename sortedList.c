#include "sortedList.h"

#include <stdio.h>

#include <stdlib.h>

#define GROWTH_FACTOR 2

t_sorted_list * create_list(int max, int is_ascending) {
  t_sorted_list * sorted_list = (t_sorted_list * ) malloc(sizeof(t_sorted_list));
  sorted_list -> items = (int * ) malloc(sizeof(int) * max);
  if (sorted_list == NULL || sorted_list -> items == NULL) return NULL;
  sorted_list -> max = max;
  sorted_list -> n = 0;
  sorted_list -> is_ascending = is_ascending;
  return sorted_list;
}

int append(t_sorted_list * sorted_list, int number) {
  if (sorted_list == NULL) return 0;
  if (sorted_list -> n == sorted_list -> max) realloc_list(sorted_list);

  int index = find_index(sorted_list, number);
  insert(sorted_list, number, index);
  return 1;
}

t_sorted_list * reverse_order(t_sorted_list * sorted_list) {
  t_sorted_list * reversed_list = create_list(sorted_list -> max, !sorted_list -> is_ascending);
  int j = sorted_list -> n;
  for (int i = 0; i < sorted_list -> n; i++, j--) {
    reversed_list -> items[i] = sorted_list -> items[j];
  }
  return reversed_list;
}

int find_index(t_sorted_list * sorted_list, int number) {
  int left = 0;
  int right = sorted_list -> n - 1;
  int mid;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (sorted_list -> is_ascending) {
      if (number <= sorted_list -> items[mid] && (mid == 0 || number > sorted_list -> items[mid - 1])) {
        return mid;
      } else if (number > sorted_list -> items[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      if (number >= sorted_list -> items[mid] && (mid == 0 || number < sorted_list -> items[mid - 1])) {
        return mid;
      } else if (number < sorted_list -> items[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return left;
}

int insert(t_sorted_list * sorted_list, int elem, int index) {
  if (index == sorted_list -> n) {
    sorted_list -> items[index] = elem;
    sorted_list -> n++;
    return 1;
  }

  for (int i = sorted_list -> n - 1; i >= index; i--) {
    sorted_list -> items[i + 1] = sorted_list -> items[i];
  }

  sorted_list -> items[index] = elem;
  sorted_list -> n++;
  return 1;
}

int destroy_list(t_sorted_list * sorted_list) {
  if (sorted_list == NULL) return 0;
  free(sorted_list -> items);
  free(sorted_list);
  return 1;
}

void clear_list(t_sorted_list * sorted_list) {
  sorted_list -> n = 0;
}

void realloc_list(t_sorted_list * sorted_list) {
  sorted_list -> max *= GROWTH_FACTOR;
  sorted_list -> items = (int * ) realloc(sorted_list -> items, sorted_list -> max * sizeof(int));
  if (sorted_list -> items == NULL) {
    printf("Erro ao realocar memória\n");
    exit(EXIT_FAILURE);
  }
}

int remove_item(t_sorted_list * sorted_list, int elem) {
  if (sorted_list -> n == 0 || sorted_list == NULL) return 0;
  int index = find_index(sorted_list, elem);

  for (int i = index; i < sorted_list -> n - 1; i++) {
    sorted_list -> items[index] = sorted_list -> items[index + 1];
  }
  sorted_list -> n--;

  return 0;
}

int print_list(t_sorted_list * sorted_list) {
  if (is_empty(sorted_list)) return 0;
  printf("[");
  for (int i = 0; i < sorted_list -> n; i++) {
    if (i < sorted_list -> n - 1) printf("%d, ", sorted_list -> items[i]);
    else printf("%d", sorted_list -> items[i]);
  }
  printf("]\n");
  return 1;
}

int is_empty(t_sorted_list * sorted_list) {
  return sorted_list -> n == 0 ? 1 : 0;
}

int is_full(t_sorted_list * sorted_list) {
  return sorted_list -> n == sorted_list -> max ? 1 : 0;
}