#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  return NULL;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  list_ptr cell = malloc(sizeof(s_list_node_t));
  cell->data = sprite;
  cell->next = list;
  return cell;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return (l == NULL);
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if (l == NULL) {
    return NULL;
  }
  return l->next;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  if (l == NULL) {
    return NULL;
  }
  return l->data;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  if (*l == NULL) {
    return NULL;
  }

  list_ptr cur = *l;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  sprite_t sprite = cur->data;
  list_remove(cur, l);
  return sprite;
}

/* Remove the given cell in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  if (elt == NULL || l == NULL) {
    return;
  }
  if (elt == *l) {
    *l = elt->next;
  } else {
    list_ptr prev = *l;
    while (prev != NULL && prev->next != elt) {
      prev = prev->next;
    }
    if (prev != NULL) {
      prev->next = elt->next;
    }
  }
  free(elt);
  return;
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  while (l != NULL) {
    list_ptr next = l->next;
    sprite_free(l->data);
    free(l);
    l = next;
  }
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  int count = 0;
  while (l != NULL) {
    count += 1;
    l = l->next;
  }
  return count;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}
