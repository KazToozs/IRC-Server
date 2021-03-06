/*
** list.c for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 19 18:06:47 2016 toozs-_c
** Last update Sun May 29 15:43:59 2016 toozs-_c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

int		ch_push_back(t_channel **list, char *name)
{
  t_channel	*block;
  t_channel	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->next = NULL;
  block->name = strdup(name);
  if ((*list) == NULL)
    {
      block->prev = NULL;
      (*list) = block;
    }
  else
    {
      tmp = (*list);
      while ((*list)->next != NULL)
        (*list) = (*list)->next;
      (*list)->next = block;
      (*list)->next->prev = (*list);
      (*list) = tmp;
    }
  return (0);
}

void			ch_remove_node(t_channel **head, t_channel **node)
{
  t_channel		*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  if (tmp->name)
    free(tmp->name);
  free(tmp);
}
