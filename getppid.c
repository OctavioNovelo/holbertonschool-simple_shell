#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 * Return: 0
 */

int main ()
{
	pid_t ppid;

	ppid = get_ppid();

	printf("El PPID del proceso actual es: %d\n", ppid);

    return 0;
}


