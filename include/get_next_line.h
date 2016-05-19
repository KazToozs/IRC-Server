/*
** get_next_line.h for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 22:33:44 2016 toozs-_c
** Last update Mon May  2 22:33:45 2016 toozs-_c
*/

#ifndef _G_N_L_H_
#define _G_N_L_H_

#include <unistd.h>

#define BUFF_SIZE 4096

char	*get_next_line(const int fd);
char	*my_realloc(char *str, int size);

#endif /* _G_N_L_H_ */
