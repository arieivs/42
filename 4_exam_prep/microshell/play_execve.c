#include <unistd.h>

/*
 * - execve stops at first NULL
 * - argv is actually NULL terminated... and I've been passing ac for this
 *   all this time...
 * - So now replacing ; and | for NULL makes sense
 */

int	main(int ac, char **av, char **envp)
{
	//char	*args[]={"/bin/ls", "-l", NULL, "/bin/ls", "-a", NULL};
	(void)ac;
	(void)av;

	execve("/bin/ls", av + 1, envp);
	return (0);
}

