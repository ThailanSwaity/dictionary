#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dict.h"

int main(void)
{
  char *string_array[] = { "Klive", "Alex", "Birdo", "Mario", "Luigi", "Donkey Kong", "Waluigi", };
  unsigned int array_length = 7;

  Dictionary dict = dict_new(25);

  for (int i = 0; i < (int)array_length; i++) {
    dict_insert_kv(string_array[i], "test", &dict);
  }

  for (int i = 0; i < (int)dict.size; i++) {
    printf("%d, %s\n", i, dict.dict[i].key);
  }

  for (int i = 0; i < (int)dict.size; i++) {
    Entry E = dict_find_kv(dict.dict[i].key, &dict);
    printf("Looking for: %s, Found: %s, Value: %s\n", dict.dict[i].key, E.key, (char *)E.value);
  }

  Entry E = dict_find_kv("Timothy", &dict);
  printf("Looking for: %s, Found: %s, Value: %s\n", "Timothy", E.key, (char *)E.value);

  return 0;
}
