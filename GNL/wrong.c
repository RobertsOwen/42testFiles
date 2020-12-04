/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroberts <oroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:32:16 by oroberts          #+#    #+#             */
/*   Updated: 2020/12/04 16:30:43 by oroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char	*ptr;
	int		ret;

	printf("wrong fd\n");
	printf("-1\n");
	ret = get_next_line(-1, &ptr);
	if (ret != -1)
	{
		printf("ERROR\n");
		return (1);
	}
	printf("ok\n");
	printf("5\n");
	ret = get_next_line(5, &ptr);
	if (ret != -1)
	{
		printf("ERROR\n");
		return (1);
	}
	printf("ok");

	return (0);
}