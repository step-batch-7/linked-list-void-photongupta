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
  return 0;
}