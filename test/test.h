#ifndef __TEST_H
#define __TEST_H

#include "../linkedlist.h"
#define NEW_LINE printf("\n")

typedef char *Char_ptr;

typedef struct Test_report{
 int passed;
 int failed;
 int total;
} Test_report;

typedef Test_report *Test_report_ptr;

void it(Char_ptr);
void describe(Char_ptr);
float percentage(int,int);

void assert_int(int actual, int expected, Char_ptr message, Test_report_ptr test_watcher);
void assert_void_ptr(Element actual, Element expected, Matcher mather, Char_ptr message, Test_report_ptr test_watcher);
void assert_list(List_ptr actual, List_ptr expected,  Matcher matcher, Char_ptr message, Test_report_ptr test_watcher);
void assert_ok(int value, Char_ptr message, Test_report_ptr test_watcher);
void assert_is_null(Node_ptr value, Char_ptr message, Test_report_ptr test_watcher);

void print_status(int status, Test_report_ptr test_watcher);
Status is_present_at(List_ptr list, int position, Element element, Matcher matcher);

Status is_even(Element value);
Status is_capital(Element value);
Element to_capital(Element value);
Element add_one(Element value);
Element sum(Element num1, Element num2);
Element get_last(Element val1, Element val2);
void increase_by_one(Element value);
void to_upper_case(Element value);
Status are_int_matching(Element val1, Element val2);
Status are_char_matching(Element val1, Element val2);
void display_int(Element num);
void display_char(Element value);

void test_create_node(Test_report_ptr);
void test_create_list(Test_report_ptr);
void test_add_to_start(Test_report_ptr);
void test_add_to_list(Test_report_ptr);
void test_insert_at(Test_report_ptr);
void test_add_unique(Test_report_ptr);
void test_remove_from_start(Test_report_ptr);
void test_remove_from_end(Test_report_ptr);
void test_remove_at(Test_report_ptr);
void test_remove_first_occurrence(Test_report_ptr);
void test_remove_all_occurrences(Test_report_ptr);
void test_clear_list(Test_report_ptr);
void test_filter(Test_report_ptr);
void test_map(Test_report_ptr);
void test_reduce(Test_report_ptr);
void test_forEach(Test_report_ptr);
void test_reverse(Test_report_ptr);
Test_report_ptr run_tests(Test_report_ptr);

void print(Test_report_ptr test_report);


#endif