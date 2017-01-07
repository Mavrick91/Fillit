/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:13:21 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/31 03:35:16 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_double_list *change_hash_into_alpha(t_double_list *li) {
  int i;
  int j;
  char alpha;
  t_tetriminos *tmp;

  tmp = li->begin;
  alpha = 'A';
  while (tmp && alpha <= 'Z') {
    i = 0;
    while (tmp->tetriminos[i]) {
      j = 0;
      while (tmp->tetriminos[i][j]) {
        tmp->tetriminos[i][j] = convert_hash(tmp, alpha, i, j);
        j++;
      }
      i++;
    }
    alpha++;
    tmp = tmp->tetris_next;
  }
  return (li);
}

char convert_hash(t_tetriminos *tmp, char alpha, int i, int j) {
  if (tmp->tetriminos[i][j] == '#')
    tmp->tetriminos[i][j] = alpha;
  return (tmp->tetriminos[i][j]);
}