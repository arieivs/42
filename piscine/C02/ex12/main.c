void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	//char str[] = "Are pandas cool?\n\tYes, of course!";
	char str[] = "Bonjour les aminches\n\n\nc est fo u\ttout\tce qu on peut faire avec\n\n\nprint_memory\n\n\n\tlol\tlol\t ";

	//ft_print_memory(str, 34);
	ft_print_memory(str, 92);
	return (0);
}
