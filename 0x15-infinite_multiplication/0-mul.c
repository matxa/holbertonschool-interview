#include "holberton.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: multiplication
 */
int main(int argc, char **argv)
{
	check_args(argc, argv);
	write_to_file(argv);
	multiply();
	return (0);
}

/**
 * _error - print error and exit
 * Return: VOID
 */
void _error(void)
{
	int i;
	char *error = "Error\n";

	for (i = 0; error[i] != '\0'; i++)
		_putchar(error[i]);
	exit(98);
}

/**
 * check_args - check input arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: VOID
 */
void check_args(int argc, char **argv)
{
	int i;

	if (argc != 3)
		_error();
	else
	{
		for (i = 0; argv[1][i] != '\0'; i++)
			if (!isdigit(argv[1][i]))
				_error();

		for (i = 0; argv[2][i] != '\0'; i++)
			if (!isdigit(argv[2][i]))
				_error();
	}
}

/**
 * write_to_file - write to file
 * @argv: argument vector
 * Return: VOID
 */
void write_to_file(char **argv)
{
	int i;
	FILE *fp;

	fp = fopen("output", "w");
	if (fp == NULL)
		exit(1);

	for (i = 0; argv[1][i] != '\0'; i++)
		fputc(argv[1][i], fp);

	fputs("*", fp);

	for (i = 0; argv[2][i] != '\0'; i++)
		fputc(argv[2][i], fp);

	fputs("\n", fp);
	fputs("quit()", fp);
	fputs("\n", fp);

	fclose(fp);
}

/**
 * multiply - multiply
 * Return: VOID
 */
void multiply(void)
{
	FILE *fp;
	char c;

	system("bc -q output > answer");

	fp = fopen("answer", "r");
	if (fp == NULL)
		exit(1);

	while (1)
	{
		c = fgetc(fp);
		if (c == EOF)
			break;
		if (c != '\\' && c != '\n')
			_putchar(c);
	}
	_putchar('\n');
}
