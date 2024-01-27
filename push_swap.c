/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/01/27 22:41:02 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char**argv)
{   
    char **str;
    stack *pile;
    if (argc == 2)
        {
        str = ft_split(argv[1], " ");
        pile = create_stack(str);
        }
    pile = create_stack(argv+1);
}



