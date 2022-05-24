#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_microshell {
	int		nb_instructions;
	int		*nb_commands;
	char	**envp;
}				t_microshell;

#endif
