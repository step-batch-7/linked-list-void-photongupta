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

int is_list_empty(List_ptr list)
{
  return list->length == 0;
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
  if (list->first == NULL)
    list->last = new_node;
  new_node->next = list->first;
  list->first = new_node;
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

Status add_unique(List_ptr list, Element value, Matcher are_matching)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    if ((*are_matching)(p_walk->element, value))
      return Failure;
    p_walk = p_walk->next;
  }
  return add_to_list(list, value);
}

Element remove_from_start(List_ptr list)
{
  Element element = malloc(sizeof(Element));
  if (is_list_empty(list))
    return NULL;

  if (list->length == 1)
    list->last = NULL;

  Node_ptr first_node = list->first;
  element = first_node->element;
  list->first = first_node->next;
  free(first_node);
  list->length -= 1;
  return element;
}

Element remove_from_end(List_ptr list)
{
  Element element = malloc(sizeof(Element));
  if (is_list_empty(list) || list->length == 1)
    return remove_from_start(list);

  Node_ptr temp = NULL;
  Node_ptr p_walk = list->first;
  while (p_walk->next != NULL)
  {
    temp = p_walk;
    p_walk = p_walk->next;
  }
  element = p_walk->element;
  free(p_walk);
  temp->next = NULL;
  list->last = temp;
  list->length -= 1;
  return element;
}

Element remove_at(List_ptr list, int position)
{
  Element element = malloc(sizeof(Element));
  if (position > list->length - 1 || position < 0)
    return NULL;

  if (position == 0)
    return remove_from_start(list);

  if (position == list->length - 1)
    return remove_from_end(list);

  Node_ptr temp_node;
  Node_ptr p_walk = list->first;
  for (int length = 0; length < position; length++)
  {
    temp_node = p_walk;
    p_walk = p_walk->next;
  }
  temp_node->next = p_walk->next;
  element = p_walk->element;
  free(p_walk);
  list->length -= 1;
  return element;
}

Status clear_list(List_ptr list)
{
  while (!is_list_empty(list))
  {
    remove_from_end(list);
  }
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