/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:22 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/16 14:55:43 by lelhlami         ###   ########.fr       */
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
            // writestack(&stack_1);        
        }
        else
        {
            quick_sort_a(&stack_1, &stack_2, stack_1.len, 0);
            // mini_sort_5(&stack_1, &stack_2);
            // printf("stack main 1 => ");
            // writestack(&stack_1);
            printf("is sorted ? = %d \n", is_sorted(&stack_1));
            // writestack(&stack_2);
        }
        free_function(&stack_1);
        free_function(&stack_2);    }
    // system("leaks push_swap");
    return (0);
}
