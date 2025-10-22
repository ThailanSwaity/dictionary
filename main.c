#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dict.h"

int main(void)
{
  char *string_array[] = { "Cale", "Daniel", "Matt", "Madeline", "Ethan", "Thomas", "Rorey", };
  unsigned int array_length = 7;

  Dictionary dict = dict_new(25);

  for (int i = 0; i < (int)array_length; i++) {
    dict_insert_kv(string_array[i], "test", &dict);
  }

  for (int i = 0; i < (int)dict.size; i++) {
    printf("Key: %s, Value: %s\n", dict.dict[i].key, (char *)dict.dict[i].value);
  }

  printf("dict size: %d", dict.size);

  return 0;
}
