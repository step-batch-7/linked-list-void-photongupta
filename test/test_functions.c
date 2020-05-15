#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void test_create_node(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_NODE");
  int num = 1;
  Node_ptr node = create_node(&num);

  it("Should create a node with given value: ");
  assert_void_ptr(node->element, &num, are_int_matching, "should pass the pointer", test_watcher);
  assert_is_null(node->next, "next should be null", test_watcher);
  NEW_LINE;
}

void test_create_list(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_LIST");
  List_ptr list = create_list();

  it("Should create list with length 0: ");
  assert_int(list->length, 0, "length should be 0", test_watcher);
  assert_is_null(list->first, "head should be null", test_watcher);
  assert_is_null(list->last, "last should be null", test_watcher);
  NEW_LINE;
}

void test_add_to_start(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# ADD_TO_START");
  int num1 = 1;
  List_ptr int_list = create_list();

  it("Should add the number at the start of empty list : ");
  assert_int(add_to_start(int_list, &num1), Success, "should add the number", test_watcher);
  assert_int(int_list->length, 1, "length should increase by one", test_watcher);
  assert_ok(is_present_at(int_list, 0, &num1, are_int_matching), "number should be present at first position", test_watcher);
  NEW_LINE;

  int num2 = 2;
  it("Should add the number at the start of the list : ");
  assert_int(add_to_start(int_list, &num2), Success, "should add the number", test_watcher);
  assert_int(int_list->length, 2, "length should increase by one", test_watcher);
  assert_ok(is_present_at(int_list, 0, &num2, are_int_matching), "number should be present at first position", test_watcher);
  NEW_LINE;
}

void test_add_to_list(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# ADD_TO_list");
  int num1 = 1;
  List_ptr list = create_list();

  it("Should add the number at the end of empty list :");
  assert_int(add_to_list(list, &num1), Success, "should add the number", test_watcher);
  assert_int(list->length, 1, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 0, &num1, are_int_matching), "number should be present at last position", test_watcher);
  NEW_LINE;

  int num2 = 1;
  it("Should add the number at the end of the list :");
  assert_int(add_to_list(list, &num2), Success, "should add the number", test_watcher);
  assert_int(list->length, 2, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 1, &num2, are_int_matching), "number should be present at last position", test_watcher);
  NEW_LINE;
}

void test_insert_at(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# INSERT_AT");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;
  int num5 = 5;
  int num6 = 6;
  add_to_list(list, &num1);
  add_to_list(list, &num2);

  it("Should insert at 0th position in the list : ");
  assert_int(insert_at(list, &num3, 0), Success, "should add the number", test_watcher);
  assert_int(list->length, 3, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 0, &num3, are_int_matching), "number should be present at first position", test_watcher);
  NEW_LINE;

  it("Should insert at last position in the list : ");
  assert_int(insert_at(list, &num4, 3), Success, "should add the number", test_watcher);
  assert_int(list->length, 4, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 3, &num4, are_int_matching), "number should be present at last position", test_watcher);
  NEW_LINE;

  it("Should insert at given position in the list : ");
  assert_int(insert_at(list, &num5, 2), Success, "should add the number", test_watcher);
  assert_int(list->length, 5, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 2, &num5, are_int_matching), "number should be present at given position", test_watcher);
  NEW_LINE;

  it("Should not insert if the given position is invalid : ");
  assert_int(insert_at(list, &num6, 10), Failure, "should not add the number", test_watcher);
  assert_int(list->length, 5, "length should remain same", test_watcher);
  assert_ok(!is_present_at(list, 10, &num6, are_int_matching), "number should not be present at the given position", test_watcher);
  NEW_LINE;
}

void test_add_unique(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# ADD_UNIQUE");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;

  it("Should add the number at the end of empty list :");
  assert_int(add_unique(list, &num1, are_int_matching), Success, "should add the number", test_watcher);
  assert_int(list->length, 1, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 0, &num1, are_int_matching), "number should be present at last position", test_watcher);
  NEW_LINE;

  it("Should not add if number is in the list : ");
  assert_int(add_unique(list, &num1, are_int_matching), Failure, "should not add the number", test_watcher);
  assert_int(list->length, 1, "length should remain same", test_watcher);
  assert_ok(!is_present_at(list, 1, &num1, are_int_matching), "number should not be present at the given position", test_watcher);
  NEW_LINE;

  it("Should add if number is not present in the list : ");
  assert_int(add_unique(list, &num2, are_int_matching), Success, "should add the number", test_watcher);
  assert_int(list->length, 2, "length should increase by one", test_watcher);
  assert_ok(is_present_at(list, 1, &num2, are_int_matching), "number should be present at last position", test_watcher);
  NEW_LINE;
}

void test_remove_from_start(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REMOVE_FROM_START");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;

  it("Should not remove if the list is empty : ");
  Element element = remove_from_start(list);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 0, "length should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  it("Should remove the number from start of the list : ");
  element = remove_from_start(list);
  assert_void_ptr(element, &num1, are_int_matching, "should remove the first number", test_watcher);
  assert_int(list->length, 1, "length should be decreased by one", test_watcher);
  assert_ok(is_present_at(list, 0, &num2, are_int_matching), "first position should not contain that number", test_watcher);
  NEW_LINE;
}

void test_remove_from_end(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REMOVE_FROM_END");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;

  it("Should not remove if the list is empty : ");
  Element element = remove_from_end(list);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 0, "length should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  it("Should remove the number from end of the list : ");
  element = remove_from_end(list);
  assert_void_ptr(element, &num2, are_int_matching, "should remove the last number", test_watcher);
  assert_int(list->length, 1, "length should be decreased by one", test_watcher);
  assert_ok(!is_present_at(list, 1, &num2, are_int_matching), "last position should not contain that number", test_watcher);
  NEW_LINE;
}

void test_remove_at(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REMOVE_AT");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;
  int num5 = 5;

  it("Should not remove if the list is empty: ");
  Element element = remove_from_end(list);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 0, "length should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  add_to_list(list, &num4);
  add_to_list(list, &num5);
  it("Should remove from the last position of the list: ");
  element = remove_at(list, 4);
  assert_void_ptr(element, &num5, are_int_matching, "should remove the last number", test_watcher);
  assert_int(list->length, 4, "length should be decreased by one", test_watcher);
  assert_ok(!is_present_at(list, 4, &num5, are_int_matching), "first position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should remove from the 0th position of the list: ");
  element = remove_at(list, 0);
  assert_void_ptr(element, &num1, are_int_matching, "should remove the first number", test_watcher);
  assert_int(list->length, 3, "length should be decreased by one", test_watcher);
  assert_ok(!is_present_at(list, 0, &num1, are_int_matching), "last position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should remove from the given position of the list: ");
  element = remove_at(list, 1);
  assert_void_ptr(element, &num3, are_int_matching, "should remove the number at given position", test_watcher);
  assert_int(list->length, 2, "length should be decreased by one", test_watcher);
  assert_ok(!is_present_at(list, 1, &num3, are_int_matching), "given position should not contain that number", test_watcher);
  NEW_LINE;

  it("Should not remove if given position is invalid : ");
  element = remove_at(list, 5);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 2, "length should be remain same", test_watcher);
  NEW_LINE;
}

void test_remove_first_occurrence(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REMOVE_FIRST_OCCURRENCE");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;

  it("Should not remove if the list is empty: ");
  Element element = remove_from_end(list);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 0, "length should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num4);
  it("Should remove the first occurrence of the given number from list : ");
  element = remove_first_occurrence(list, &num2, are_int_matching);
  assert_void_ptr(element, &num2, are_int_matching, "should remove the first occurrence", test_watcher);
  assert_int(list->length, 2, "length should be decrease by 1", test_watcher);
  assert_ok(!is_present_at(list, 1, &num2, are_int_matching), "number shouldn't be present at its position", test_watcher);
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  element = remove_first_occurrence(list, &num3, are_int_matching);
  assert_is_null(element, "should not remove", test_watcher);
  assert_int(list->length, 2, "length should remain same", test_watcher);
  NEW_LINE;
}

void test_remove_all_occurrences(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REMOVE_ALL_OCCURRENCES");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 2;

  it("Should not remove if the list is empty: ");
  List_ptr removed_elements = remove_all_occurrences(list, &num1, are_int_matching);
  assert_is_null(removed_elements->first, "first of list should be null", test_watcher);
  assert_is_null(removed_elements->last, "last of list should be null", test_watcher);
  assert_int(removed_elements->length, 0, "length of list should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  add_to_list(list, &num4);
  it("Should remove all occurrences of the given number from list : ");
  removed_elements = remove_all_occurrences(list, &num2, are_int_matching);
  List_ptr expected = create_list();
  add_to_list(expected, &num2);
  add_to_list(expected, &num4);
  List_ptr remaining_elements = create_list();
  add_to_list(remaining_elements, &num1);
  add_to_list(remaining_elements, &num3);
  assert_list(removed_elements, expected, are_int_matching, "should give the removed elements list", test_watcher);
  assert_list(list, remaining_elements, are_int_matching, "should remove all the occurrences ", test_watcher);
  assert_int(list->length, 2, "length should be decrease according to the number of occurrence", test_watcher);
  NEW_LINE;

  it("Should not remove if the list doesn't contain the given number : ");
  removed_elements = remove_all_occurrences(list, &num2, are_int_matching);
  assert_is_null(removed_elements->first, "first of removed elements should be null", test_watcher);
  assert_is_null(removed_elements->last, "last of removed elements should be null", test_watcher);
  assert_int(removed_elements->length, 0, "length of removed elements should be 0", test_watcher);
  assert_int(list->length, 2, "length should be remain same", test_watcher);
  NEW_LINE;
}

void test_clear_list(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CLEAR_LIST");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  it("Should clear the empty list : ");
  assert_int(clear_list(list), Success, "should clear the list", test_watcher);
  assert_int(list->length, 0, "length should remain 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  it("Should remove all the elements present in the list : ");
  assert_int(clear_list(list), Success, "should clear the list", test_watcher);
  assert_int(list->length, 0, "length should be reduced to 0", test_watcher);
  NEW_LINE;
}

void test_map(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# MAP");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  it("Should give empty list for empty list: ");
  List_ptr mapped_list = map(list, &add_one);
  assert_is_null(mapped_list->first, "first of list should be null", test_watcher);
  assert_is_null(mapped_list->last, "last of list should be null", test_watcher);
  assert_int(mapped_list->length, 0, "length of list should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  it("Should map all the element of the list according to the given mapper : ");
  mapped_list = map(list, &add_one);
  List_ptr expected = create_list();
  add_to_list(expected, &num2);
  add_to_list(expected, &num3);
  assert_list(mapped_list, expected, are_int_matching, "should increase all elements of the list by one ", test_watcher);
  assert_int(mapped_list->length, expected->length, "length of mapped list should be same as original list", test_watcher);
  NEW_LINE;
}

void test_filter(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# FILTER");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  it("Should give empty list for empty list: ");
  List_ptr even_list = filter(list, &is_even);
  assert_is_null(even_list->first, "first of list should be null", test_watcher);
  assert_is_null(even_list->last, "last of list should be null", test_watcher);
  assert_int(even_list->length, 0, "length of list should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  it("Should give all the required element : ");
  even_list = filter(list, &is_even);
  List_ptr expected = create_list();
  add_to_list(expected, &num2);
  assert_list(even_list, expected, are_int_matching, "should give all the evens of the list", test_watcher);
  assert_int(even_list->length, expected->length, "length of even list should be equal to the number of evens in the list", test_watcher);
  NEW_LINE;
}

void test_reduce(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REDUCE");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int context = 0;

  it("Should give the context back if the list is empty : ");
  Element result = reduce(list, &context, &sum);
  assert_void_ptr(result, &context, are_int_matching, "should give the context back", test_watcher);
  assert_int(list->length, 0, "length of the original should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  it("Should remove the number from end of the list : ");
  result = reduce(list, &context, &sum);
  assert_void_ptr(result, &num3, are_int_matching, "should give sum of all the numbers", test_watcher);
  assert_int(list->length, 2, "length of the original list should remain same", test_watcher);
  NEW_LINE;
}

void test_forEach(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# FOREACH");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  it("Should give empty list for empty list: ");
  forEach(list, &increase_by_one);
  assert_is_null(list->first, "first of list should be null", test_watcher);
  assert_is_null(list->last, "last of list should be null", test_watcher);
  assert_int(list->length, 0, "length of list should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  it("Should give all the required element : ");
  forEach(list, &increase_by_one);
  List_ptr expected = create_list();
  add_to_list(expected, &num2);
  add_to_list(expected, &num3);
  assert_list(list, expected, are_int_matching, "should add one to all the elements", test_watcher);
  assert_int(list->length, 2, "length of list should remain same", test_watcher);
  NEW_LINE;
}

void test_reverse(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# REVERSE");
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  it("Should give empty list for empty list: ");
  List_ptr reversed_list = reverse(list);
  assert_is_null(reversed_list->first, "first of list should be null", test_watcher);
  assert_is_null(reversed_list->last, "last of list should be null", test_watcher);
  assert_int(reversed_list->length, 0, "length of list should be 0", test_watcher);
  NEW_LINE;

  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  it("Should give all the elements in reverse order : ");
  reversed_list = reverse(list);
  List_ptr expected = create_list();
  add_to_list(expected, &num3);
  add_to_list(expected, &num2);
  add_to_list(expected, &num1);
  assert_list(reversed_list, expected, are_int_matching, "should give all the element in reverse order", test_watcher);
  assert_int(reversed_list->length, list->length, "length should be equal to the length of original list", test_watcher);
  NEW_LINE;
}