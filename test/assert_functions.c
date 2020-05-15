#include "test.h"
#include <stdio.h>
#include <string.h>

//----------------------------------------ASSERT---------------------------------------------------

void assert_int(int actual, int expected, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(actual == expected, test_watcher);
  printf("%s", message);
}

void assert_void_ptr(Element actual, Element expected, Matcher mather, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status((*mather)(actual, expected), test_watcher);
  printf("%s", message);
}

void assert_list(List_ptr actual, List_ptr expected, Matcher matcher, Char_ptr message, Test_report_ptr test_watcher)
{
  Status status = Failure;
  Node_ptr expected_p_walk = expected->first;
  Node_ptr actual_p_walk = actual->first;
  while (expected_p_walk != NULL)
  {
    status = (*matcher)(expected_p_walk->element, actual_p_walk->element);
    expected_p_walk = expected_p_walk->next;
    actual_p_walk = actual_p_walk->next;
  }
  NEW_LINE;
  print_status(status, test_watcher);
  printf("%s", message);
}

void assert_ok(int value, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(value, test_watcher);
  printf("%s", message);
}

void assert_is_null(Node_ptr value, Char_ptr message, Test_report_ptr test_watcher)
{
  NEW_LINE;
  print_status(value == NULL, test_watcher);
  printf("%s", message);
}
