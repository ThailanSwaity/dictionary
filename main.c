#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dict.h"

#define TABLE_MAX_ENTRIES 256

typedef struct Entry {
  char* key;
  void *value;
} Entry;

static Entry entries[TABLE_MAX_ENTRIES];
static int table_size = 0;

void bubble_sort_int(int *A, int N) {
  int T;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        T = A[j + 1];
        A[j + 1] = A[j];
        A[j] = T;
      }
    }
  }
}

void bubble_sort_string(char **A, int N) {
  char *T;
  int M;
  int k;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1 - i; j++) {
      M = strlen(A[j]);
      if (strcmp(A[j], A[j + 1]) < 0) M = strlen(A[j]);
      for (k = 0; k < M; k++) {
        if (A[j][k] != A[j + 1][k]) break;
      }
      if (A[j][k] > A[j + 1][k]) {
        T = A[j + 1];
        A[j + 1] = A[j];
        A[j] = T;
      }
    }
  }
}

void bubble_sort_kv_entries(Entry* E, int N) {
  Entry T;
  int M;
  int k;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1 - i; j++) {
      M = strlen(E[j].key);
      if (strcmp(E[j].key, E[j + 1].key) < 0) M = strlen(E[j].key);
      for (k = 0; k < M; k++) {
        if (E[j].key[k] != E[j + 1].key[k]) break;
      }
      if (E[j].key[k] > E[j + 1].key[k]) {
        T = E[j + 1];
        E[j + 1] = E[j];
        E[j] = T;
      }
    }
  }
}

void insert_kv(char *key, void *value, Entry *E) {
  if (table_size == TABLE_MAX_ENTRIES) {
    perror("Maximum number of entries reached.");
    exit(1);
  }

  // Implement insertion sort here

  Entry TE = { key, value };
  E[table_size++] = TE;
}

int main(void)
{
  int array[] = { 17, 3, 4, 1, 7, 3, 15, 98, 12, 15, 8, 9 };
  long unsigned int array_length = sizeof(array) / sizeof(array[0]);

  bubble_sort_int(array, array_length);

  for (int i = 0; i < (int)array_length; i++) {
    printf("%d\n", array[i]);
  }

  char *string_array[] = { "Cale", "Daniel", "Matt", "Madeline", "Ethan", "Thomas", "Rorey", };
  array_length = 7;

  for (int i = 0; i < (int)array_length; i++) {
    printf("%s\n", string_array[i]);
  }

  printf("Size of %s: %ld\n", string_array[1], strlen(string_array[1]));

  for (int i = 0; i < (int)array_length; i++) {
    insert_kv(string_array[i], "Test", entries);
  }

  bubble_sort_kv_entries(entries, table_size);

  for (int i = 0; i < table_size; i++) {
    printf("Key: %s, Value: %s\n", entries[i].key, (char *)entries[i].value);
  }

  return 0;
}
