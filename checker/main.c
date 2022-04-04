/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:53:57 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/24 11:38:46 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../get_next_line/get_next_line.h"

int main(int argc, char **argv)
{
    t_arr           stack;
    t_instructions  inst;
    int             i;

    if (argc >= 2)
    {
        init_stack1(&stack, argc, argv);
        i = -1;
        printf("here\n");
        while ((inst.arr[++i] = get_next_line(0)));
        i = -1;
        while (inst.arr[++i])
            printf("%s |", inst.arr[i]);
        printf("\n");
        free_function(&stack);
        free_inst(&inst);
    }
    return (0);
}