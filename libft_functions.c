#include "push_swap.h"

int ft_lstsize(stack *lst)
{
	int length;
	node *temp;

	length = 0;
	temp = lst->head;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	return (length);
}

// int	ft_lstsize(stack *lst)
// {
// 	int	length;
// 	node* temp;

// 	length = 0;
// 	temp = lst->head;
// 	while (temp != NULL)
// 	{
// 		temp = temp->next;
// 		length++;
// 	}
// 	return (length);
// }

node *ft_lstlast(node *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

static int number_of_strings(const char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			len++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (len);
}

static char *ft_strndup(const char *str, int n)
{
	int j;
	char *dest;

	j = 0;
	if (str == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (str[j] != '\0' && j < n)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char **freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char **make(const char *s, char **res, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			len = 0;
			while (s[j + len] && s[j + len] != c)
				len++;
			res[i] = ft_strndup(s + j, len);
			if (!res[i])
				return (freetab(res));
			i++;
			j += len;
		}
	}
	res[i] = NULL;
	return (res);
}

char **ft_split(const char *s, char c)
{
	char **res;
	int n;

	if (s == NULL)
	{
		return (NULL);
	}
	n = number_of_strings(s, c);
	res = (char **)malloc((n + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = make(s, res, c);
	if (!res)
		return (NULL);
	return (res);
}

int ft_atoi(const char *str)
{
	long res;
	int i;
	int sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}

	return (sign * res);
}
