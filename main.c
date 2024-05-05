/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:17:34 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/05/04 14:52:52 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("> %s", line);
		free(line);
		
	}
	
	return (0);
}
