#include "test.h"
#include <stdio.h>
#include <string.h>

void describe(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
  NEW_LINE;
}

void it(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
}

void print_status(int status, Test_report_ptr test_watcher)
{
  if (status)
  {
    test_watcher->passed++;
    printf("✅ ");
  }
  else
  {
    test_watcher->failed++;
    printf("❌ ");
  }
  test_watcher->total++;
}

Status is_present_at(List_ptr list, int position, Element element, Matcher matcher)
{
  if (position > list->length - 1 || position < 0)
    return 0;

  Node_ptr p_walk = list->first;
  for (int count = 0; count != position; count++)
    p_walk = p_walk->next;

  return (*matcher)(element, p_walk->element);
}

float percentage(int total, int value)
{
  return (100 * value) / total;
}

//----------------------------------------PREDICATE---------------------------------------------------

Status is_even(Element value)
{
  return !((*(int *)value) % 2);
}

Status is_capital(Element value)
{
  return ((*(char *)value) < 90);
}

//----------------------------------------MAPPER---------------------------------------------------

Element add_one(Element value)
{
  int incremented_value = (*(int *)value) + 1;
  Element result = malloc(sizeof(incremented_value));
  memcpy(result, &incremented_value, sizeof(incremented_value));
  return result;
}

Element to_capital(Element value)
{
  char capital = (*(char *)value) - 32;
  Element result = malloc(sizeof(capital));
  memcpy(result, &capital, sizeof(capital));
  return result;
}

//----------------------------------------REDUCER---------------------------------------------------

Element sum(Element num1, Element num2)
{
  int sum = (*(int *)num1) + (*(int *)num2);
  Element result = malloc(sizeof(sum));
  memcpy(result, &sum, sizeof(sum));
  return result;
}

Element get_last(Element val1, Element val2)
{
  char max = (*(char *)val1) > (*(char *)val2) ? (*(char *)val1) : (*(char *)val2);
  Element result = malloc(sizeof(max));
  memcpy(result, &max, sizeof(max));
  return result;
}

//----------------------------------------PROCESSOR---------------------------------------------------

void increase_by_one(Element value)
{
  int incremented_value = (*(int *)value) + 1;
  memcpy(value, &incremented_value, sizeof(incremented_value));
}

void to_upper_case(Element value)
{
  char capital = (*(char *)value) - 32;
  memcpy(value, &capital, sizeof(capital));
}

//----------------------------------------MATCHER---------------------------------------------------

Status are_int_matching(Element val1, Element val2)
{
  return *(int *)val1 == *(int *)val2;
}

Status are_char_matching(Element val1, Element val2)
{
  return *(char *)val1 == *(char *)val2;
}

//----------------------------------------DISPLAYER---------------------------------------------------

void display_int(Element num)
{
  printf("%d\n", *(int *)num);
}

void display_char(Element value)
{
  printf("%c\n", *(int *)value);
}