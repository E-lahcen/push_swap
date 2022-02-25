/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:00:31 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/25 19:18:08 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_arr
{
    int *arr;
    int len;
    int index;
} t_arr;

void    rotate(t_arr *stack);
void    rrotate(t_arr *stack);
void    swap(t_arr *stack);
void    push(t_arr *stack1, t_arr *stack2);
void    init_function(t_arr *stack,int argc, char **argv);
void    ss(t_arr *stack1, t_arr *stack2);
void    rr(t_arr *stack1, t_arr *stack2);
void    rrr(t_arr *stack1, t_arr *stack2);

