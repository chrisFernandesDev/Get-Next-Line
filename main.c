#include "get_next_line.h"

int main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo");
		return 1;
	}

	char	*linha;
	while ((linha = get_next_line(fd)) != NULL)
	{
		printf("%s\n", linha);
		free(linha);
	}

	close (fd);
	return (0);
}