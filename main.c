#include "linkedlist.h"
#include <stdio.h>
#include <string.h>

void display_int(Element num)
{
  printf("%d\n", *(int *)num);
}

void display_char(Element value)
{
  printf("%c\n", *(int *)value);
}

Status are_int_matching(Element val1, Element val2)
{
  return *(int *)val1 == *(int *)val2;
}

Status are_char_matching(Element val1, Element val2)
{
  return *(char *)val1 == *(char *)val2;
}

int main(void)
{
  int num1 = 5;
  int num2 = 6;
  int num3 = 5;
  int num4 = 2;
  List_ptr int_data = create_list();

  add_to_list(int_data, &num1);
  add_to_list(int_data, &num2);
  add_to_list(int_data, &num3);
  add_to_list(int_data, &num4);
  display_list(int_data, &display_int);
  int a = 5;

  List_ptr element = remove_all_occurrences(int_data, &a, &are_int_matching);
  // printf("deleted : ");
  // display_int(element);
  // add_to_start(int_data, &num4);
  // insert_at(int_data, &num1, 2);

  display_list(element, &display_int);
  display_list(int_data, &display_int);

  return 0;
}