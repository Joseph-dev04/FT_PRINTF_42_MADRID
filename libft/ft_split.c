/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:09:05 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/29 15:40:16 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_world(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free_matrix(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_fill(char **split, char const *str, char c, int n_words)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	while (k < n_words)
	{
		while (str[i] == c && str[i])
			i++;
		j = i;
		while (str[i] != c && str[i])
			i++;
		split[k] = ft_substr(str, j, i - j);
		if (!split[k])
			return (ft_free_matrix(split, k - 1));
		k++;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = ft_count_world(s, c);
	split = malloc(sizeof(char *) * (n_words + 1));
	if (!split)
		return (NULL);
	return (ft_fill(split, s, c, n_words));
}

/*
int	main()
{
	char a[50] = "100c200c300c400c500c600c700c800c900";
	char **str = ft_split(a, 'c');
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;	
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return (0);
}*/