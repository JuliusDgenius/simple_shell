#include "main.h"
/**
 * expd_env_var -This  expands environment variables
 * @arg: the argument passed
 * Return: expanded argument
 */
char *expand_env_variables(char *arg)
{
	char *expanded_arg, *var_name, *var_value;
	char *percent;
	int var_len = 0;
	int i = 0;

	expanded_arg = (char *) malloc(BUFFER_SIZE);
	if (expanded_arg == NULL)
	{
		free(expanded_arg);
		return (NULL);
	}
	while ((percent = _strchr(arg, '/')) != NULL)
	{
		while (percent[i + 1] != '/' && percent[i + 1] != '\0')
		{
			var_len++;
			i++;
		}
		var_name = (char *) malloc(var_len + 1);
		if (var_name == NULL)
		{
			free(var_name);
			return (NULL);
		}
		_strncpy(var_name, percent + 1, var_len);
		var_name[var_len] = '\0';
		var_value = _getenv(var_name);

		if (var_value != NULL)
		{
			_strcat(expanded_arg, var_value);
		}
		free(var_name);
		arg = percent + var_len + 2;
	}
	_strcat(expanded_arg, arg);
	return (expanded_arg);
}
