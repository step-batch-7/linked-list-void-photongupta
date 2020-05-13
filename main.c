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

Status is_even(Element value)
{
  return !((*(int *)value) % 2);
}

Status is_upper_case(Element value)
{
  return ((*(char *)value) < 90);
}

Element add_one(Element value)
{
  int incremented_value = (*(int *)value) + 1;
  Element result = malloc(sizeof(incremented_value));
  memcpy(result, &incremented_value, sizeof(incremented_value));
  return result;
}

Element to_upper_case(Element value)
{
  char capital = (*(char *)value) - 32;
  Element result = malloc(sizeof(capital));
  memcpy(result, &capital, sizeof(capital));
  return result;
}

Element sum(Element num1, Element num2)
{
  int sum = (*(int *)num1) + (*(int *)num2);
  Element result = malloc(sizeof(sum));
  memcpy(result, &sum, sizeof(sum));
  return result;
}

Element get_last_letter(Element val1, Element val2)
{
  char max = (*(char *)val1) > (*(char *)val2) ? (*(char *)val1) : (*(char *)val2);
  Element result = malloc(sizeof(max));
  memcpy(result, &max, sizeof(max));
  return result;
}

int main(void)
{

  return 0;
}