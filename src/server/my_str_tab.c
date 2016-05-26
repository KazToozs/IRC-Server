/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/toozs-_c/rendu/Piscine_C_J08/ex_04
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Nov  3 10:09:14 2014 cristopher toozs-hobson
** Last update Tue May 10 16:32:47 2016 toozs-_c
*/

#include <stdlib.h>
#include "my.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
        {
          free(tab[i]);
          i++;
        }
      free(tab);
    }
}

int		count_words(char *str)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\r')
	{
	  cpt++;
	  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\r')
	    i++;
	}
      else
	i++;
    }
  return (cpt);
}

int		count_chars(char *str, int *i)
{
  int		cpt;

  cpt = 0;
  while (str[*i] && str[*i] != ' ' && str[*i] != '\r')
    {
      cpt++;
      *i = *i + 1;
    }
  return (cpt);
}

char		**my_str_tab(char *str)
{
  int		i;
  int		words;
  int		size;
  char		**tab;

  i = 0;
  size = 0;
  words = count_words(str);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  while (str[i] && words > 0)
    {
      if (str[i] != ' ')
      	{
	  if ((tab[size] = my_strdup(str + i)) == NULL)
	    return (NULL);
	  tab[size++] [count_chars(str, &i)] = '\0';
	  words = words - 1;
      	}
      else
	i++;
    }
  tab[size] = NULL;
  return (tab);
}
