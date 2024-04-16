#include <stdio.h>
#include <unistd.h>

/**
 *
 *
 */

int main ()
{
	pid_t ppid;

	ppid = get_ppid();

	printf("El PPID del proceso actual es: %d\n", ppid);

    return 0;
}


