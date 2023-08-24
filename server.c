#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}

void	ft_print_signal(int signal)
{
	static char	value;
	static int	bit_ctrl;

	if (signal == SIGUSR1)
		value = (value << 1) + 1;
	else
		value = (value << 1);
	bit_ctrl++;
	if (bit_ctrl == 8)
	{
		write(1, &value, 1);
		value = 0;
		bit_ctrl = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_print_signal);
	signal(SIGUSR2, ft_print_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
