/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:22 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/01 18:48:39 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    writestack(t_arr *stack_1)
{
    int i;

    i = 0;
    while (i < stack_1->len)
    {
        printf("%d ", stack_1->arr[i]);
        i++;
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    t_arr stack_1, stack_2;
    int i = 0;
    if (argc > 2)
    {
        init_stack1(&stack_1, argc, argv);
        init_stack2(&stack_2, argc);
        if (argc == 4)
        {
            mini_sort_3(&stack_1);
            writestack(&stack_1);        
        }
        else
        {
            quick_sort_a(&stack_1, &stack_2, stack_1.len);
            // mini_sort_5(&stack_1, &stack_2);
            // writestack(&stack_1);        
            // writestack(&stack_2);        

        }
        free_function(&stack_1);
        free_function(&stack_2);    }
    // system("leaks a.out");
    return (0);
}
