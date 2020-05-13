#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node_ptr create_node(Element data)
{
  Node_ptr node = malloc(sizeof(Node));
  node->element = data;
  node->next = NULL;
  return node;
}

List_ptr create_list()
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

Status add_to_list(List_ptr list, Element element)
{

  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
    return Failure;
  if (list->first == NULL)
    list->first = new_node;
  else
    list->last->next = new_node;
  list->last = new_node;
  list->length += 1;
  return Success;
}

Status add_to_start(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
    return Failure;
  Node_ptr previous_first_node = list->first;
  list->first = new_node;
  new_node->next = previous_first_node;
  list->length += 1;
  return Success;
}

Status insert_at(List_ptr list, Element value, int position)
{
  Node_ptr new_node = create_node(value);
  if (new_node == NULL || position > list->length || position < 0)
    return Failure;

  if (position == 0)
    return add_to_start(list, value);

  Node_ptr p_walk = list->first;
  for (int length = 0; length < position - 1; length++)
    p_walk = p_walk->next;

  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->length += 1;
  return Success;
}

void display_list(List_ptr list, Display displayer)
{
  printf("Elements of the list are : \n");
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    (*displayer)(p_walk->element);
    p_walk = p_walk->next;
  }
}