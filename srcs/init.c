/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:14 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/17 14:34:45 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    init_stack1(t_arr *stack,int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc)
    {
        stack->arr = (int *)malloc(sizeof(int) * argc - 1);
        if (!stack->arr)
        {
            write(1, "Issue in array initialisation!", 25);
            return;
        }
    }
    //init array with input args
    while (i < argc - 1)
    {
        stack->arr[i] = atoi(argv[i + 1]);
        i++;
    }
    //init index
    stack->index_min = 0;
    //init array length
    stack->len = argc - 1;
    //init stack name (A or B)
    stack->who = 'A';
}

void    init_stack2(t_arr *stack,int argc)
{
    int i;
    
    i = 0;
    if (argc)
    {
        stack->arr = (int *)malloc(sizeof(int) * argc - 1);
        if (!stack->arr)
        {
            write(1, "Issue in array initialisation!", 25);
            return;
        }
    }
    //init array with input args
    while (i < argc - 1)
    {
        stack->arr[i] = 0;
        i++;
    }
    //init index
    stack->index_min = 0;
    //init array length
    stack->len = 0;
    //init stack name (A or B)
    stack->who = 'B';
}

void    free_function(t_arr *stack)
{
    free(stack->arr);
}

void    free_inst(t_instructions *inst)
{
    free(inst->arr);
}