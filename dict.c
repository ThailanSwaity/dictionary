#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Dictionary dict_new(const unsigned int max_size) {
  Entry *new_entry_list = malloc(sizeof(Entry) * max_size);
  Dictionary dictionary = { .dict = new_entry_list, .size = 0, .max_size = max_size };
  return dictionary;
}

// I am not proud of this code lol
void dict_insert_kv(char *key, void *value, Dictionary *D) {
  assert(D->size < D->max_size);

  Entry E = { key, value };
  if (D->size == 0) {
    D->dict[D->size++] = E;
    return;
  }

  int M;
  int k;
  int i;
  int j;

  for (i = 0; i < (int)D->size; i++) {
    M = strlen(D->dict[i].key);
    if (strcmp(key, D->dict[i].key) < 0) M = strlen(key);
    assert(strcmp(key, D->dict[i].key) != 0);
    for (k = 0; k < M; k++) {
      if (key[k] != D->dict[i].key[k]) break;
    }
    if (key[k] < D->dict[i].key[k]) {
      // Shift all elements after i - 1 to the right, and insert E at i
      for (j = D->size; j > i; j--) {
        D->dict[j] = D->dict[j - 1];
      }
      D->dict[i] = E;
      D->size++;
      break;
    }
  }
  if (i == D->size) D->dict[D->size++] = E;
}

Entry dict_find_kv(char *key, Dictionary *D) {
  perror("To be implemented");
  exit(1);
}

void dict_delete_kv(char *key, Dictionary *D) {
  perror("To be implemented");
  exit(1);
}
