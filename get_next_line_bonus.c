/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:58:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/05 14:59:37 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <assert.h>

static int	contains_linebreak(char *buff)
{
	int i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
			return (1);
	}
	return (0);
}

static int	end_gnl(int ret, char **save, char **line)
{
	if (ret == -1)
	{
		free(*save);
		*save = NULL;
		return (-1);
	}
	if (ret == 0)
	{
		*line = gnl_strdup(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
	*line = content_before_linebreak(*save, '\n');
	*save = content_after_linebreak(*save, '\n');
	return (1);
}

static int	update_save(char **save, char **line)
{
	*line = content_before_linebreak(*save, '\n');
	*save = content_after_linebreak(*save, '\n');
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[4100];
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	if (save[fd] == NULL)
		save[fd] = gnl_strdup("");
	ret = 1;
	buff[0] = '\0';
	if (contains_linebreak(save[fd]))
		return (update_save(&(save[fd]), line));
	while (!contains_linebreak(buff) && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			save[fd] = gnl_strjoin(save[fd], buff);
		}
	}
	return (end_gnl(ret, &(save[fd]), line));
}
