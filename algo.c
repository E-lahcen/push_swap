/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:22 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/25 21:50:19 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int argc, char **argv)
{
    t_arr stack_1, stack_2;
    int i = 0;
    if (argc > 2)
    {
        init_stack1(&stack_1, argc, argv);
        init_stack2(&stack_2, argc);
        push(&stack_1, &stack_2);
        push(&stack_1, &stack_2);
        push(&stack_1, &stack_2);
        push(&stack_2, &stack_1);
        rrr(&stack_1, &stack_2);
        printf("len : %d\n", stack_1.len);
        while (i < stack_1.len)
        {
            printf("%d |  ", stack_1.arr[i]);
            i++;
        }
        printf("\n");
        i = 0;
        while (i < stack_2.len)
        {
            printf("%d |  ", stack_2.arr[i]);
            i++;
        }
        free_function(&stack_1);
        free_function(&stack_2);
    }
    // system("leaks a.out");
    return (0);
}



// int pick_min(t_arr arr)
// {
//     while (arr.index % 20 && arr.len)
//     {

//     }
// }

// int main(int argc, char **argv)
// {
//     t_arr arr;
//     init_function(&arr, argc, argv);
// }