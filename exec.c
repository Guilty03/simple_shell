#include "simple_shell.h"

#define MAX_ARGS 1024


/**
 * _exec - execute the command
 * @cmd: the command
 * @array: array holding the arguments
 * Return: Return 0 on success
 */
int _exec(char *cmd, char **array)
{
    if (cmd == NULL || array == NULL)
    {
        perror("Invalid input");
        return (-1);
    }
    /**
     * create array of pointers to store the command and arguments
     * exec_args = [cmd]
     * for arg in array:
     * exec_args.append(arg)
     * exec_args.append(None)
     */
    char *exec_args[MAX_ARGS + 2];
    int i;
    exec_args[0] = cmd;
    for (i = 0; array[i] != NULL && i < MAX_ARGS; i++)
    {
        exec_args[i + 1] = array[i];
    }
    exec_args[i + 1] = NULL;
    if (execvp(cmd, exec_args) == -1)
    {
        perror("Execution failed");
        return (-1);
    }
    perror("Unexpected error");
    return (-1);
}
