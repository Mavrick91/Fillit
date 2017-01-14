/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:48:13 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/31 00:28:26 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_double_list *push_back_dlist(t_double_list *li, char **data)
{
  t_tetriminos *elem;

  if (!(elem = (t_tetriminos *) malloc(sizeof(*elem))))
    return (NULL);
  elem->tetriminos = data;
  elem->tetris_next = NULL;
  elem->tetris_prev = NULL;
  if (li == NULL)
  {
    if (!(li = (t_double_list *) malloc(sizeof(*li))))
      return (NULL);
    li->begin = elem;
    li->end = elem;
  } else
  {
    li->end->tetris_next = elem;
    elem->tetris_prev = li->end;
    li->end = elem;
  }
  return (li);
}
