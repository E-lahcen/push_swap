/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:14 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/25 18:47:58 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    init_function(t_arr *stack,int argc, char **argv)
{
    int i;
    
    i = 0;
    stack = (t_arr *)malloc(sizeof(t_arr));
    if (!stack)
    {
        write(1, "Issue in struct initialisation!", 25);
        return (0);
    }
    if (argc)
    {
        stack->arr = (int *)malloc(sizeof(int) * argc);
        if (!stack->arr)
        {
            write(1, "Issue in array initialisation!", 25);
            return (0);
        }
    }
    //init array with input args
    while (i < argc)
    {
        stack->arr[i] = argv[ i + 1];
        i++;
    }
    //init index
    stack->index = 0;
    //init array length
    stack->len = argc - 1;
}

void    free_function(t_arr *stack)
{
    free(stack->arr);
    free(stack);
}