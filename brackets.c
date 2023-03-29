#include <unistd.h>
#include <stdbool.h>

static char	find_pair(char c)
{
	if (c == '(')
		return (')');
	else if (c == '[')
		return (']');
	else
		return ('}');
}

static bool	verify_bracket(char *str)
{
	int		i = 0;
	int		pos = 0;
	char	find;

	while (str[i])
	{
		//find opening bracket
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			pos = i;
			find = find_pair(str[i]);
			i++;
			continue ;
		}
		//find closing bracket
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			//make sure it is the correct bracket;
			//replace by '0' if it is
			//else we have an incorrect pairing
			if (find == str[i])
			{
				str[i] = '0';
				str[pos] = '0';
				i = 0;
				pos = 0;
				find = NULL;
				continue ;
			}
			else
				return (false);
		}
		i++;
	}	
	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[' || \
			str[i] == ')' || str[i] == '}' || str[i] == ']')
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		if (verify_bracket(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
