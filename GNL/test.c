/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroberts <oroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:55 by hbaudet           #+#    #+#             */
/*   Updated: 2021/08/05 17:23:54 by oroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <fcntl.h>

int    main(int ac, char *av[])
{
//    char    bis[] = "this is a string";
    char    *line;
    int        fd[ac + 1];
    int        i;
    // int        j;
    // int        gnl;
    //char    **ptr;
    
    // j = 1;
    i = 1;
    //if (!(line = malloc(sizeof(char) * 18)))
    //    return (-1);
   // ptr = &line;
    //line = strncpy(line, bis, 17);
    /*if (ac == 1)
    {
        while ((gnl = (get_next_line(0, ptr))) == 1)
            printf("%s\n", line);
        printf("d%s", line);
    }*/
    if (ac == 2)
    {
		//fprintf(stderr, "file:%s\n", av[1]);
        if (!(fd[i] = open(av[i], O_RDONLY)))
            return (-1);
        while ((line = (get_next_line(fd[i]))) != NULL)
		{
			printf("%s", line);
			free(line);
			line = NULL;
		}
        // printf("%s", line);
    }
	else
    {
        /*
        while (i < ac)
        {
            if (!(fd[i] = open(av[i], O_RDONLY)))
                return (-1);
            i++;
        }
        while (j < 5)
        {
            printf("line %d of all files :\n", j);
            i = 1;
            while (i < ac)
            {
                line = get_next_line(fd[i]);
                printf("%s\n", line);
                i++;
            }
            printf("\n\n");
            j++;
        }
        i = 1;
        while (i < ac)
        {
            printf("End of %s\n", av[i]);
            while ((line = (get_next_line(fd[i]))))
                printf("%s\n", line);
            printf("%s", line);
            close(fd[i]);
            i++;
            //printf("-------------\n\n");
        }
        free(line);*/
    }
    //fprintf(stderr, "\n             /|_\n            /  ,\\     \n         .-'   _,'  < QUACK!\n        / _   |\n       /   )_ |\n   ,=='`.____)_)\n\t\t\t\t\t\t\t\t\tgithub/hbaudet\n");
    return (0);
}
