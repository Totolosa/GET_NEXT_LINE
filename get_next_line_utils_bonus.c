/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:17:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/07 18:26:31 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (dest);
}

char	*gnl_strdup(const char *s)
{
	char	*dest;
	int		i;

	if ((dest = malloc(sizeof(char) * gnl_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*content_after_linebreak(char *s, char c)
{
	int		i;
	int		j;
	int		len;

	len = gnl_strlen(s);
	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	i++;
	while (i < len + 1)
	{
		s[j] = s[i];
		i++;
		j++;
	}
	return (s);
}

char	*content_before_linebreak(char *buff, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buff[i] != c && buff[i])
		i++;
	if ((res = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		res[j] = buff[j];
	res[j] = 0;
	return (res);
}
