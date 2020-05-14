#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

List_ptr filter(List_ptr list, Predicate predicate)

{
  List_ptr filtered_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    if ((*predicate)(p_walk->element))
      add_to_list(filtered_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return filtered_list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr mapped_list = create_list();
  Element element = malloc(sizeof(Element));
  Node_ptr p_walk = list->first;
  for (int index = 0; p_walk != NULL; index++)
  {
    element = (*mapper)(p_walk->element);
    add_to_list(mapped_list, element);
    p_walk = p_walk->next;
  }
  return mapped_list;
}

Element reduce(List_ptr list, Element context, Reducer reducer)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    context = (*reducer)(p_walk->element, context);
    p_walk = p_walk->next;
  }
  return context;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reversed_list;
}

void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}