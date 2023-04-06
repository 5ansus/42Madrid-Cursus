#include "../libft.h"

int main(){
	ft_itoa(2147483647);
	ft_putchar_fd('\n', 0);
	ft_itoa(-2147483648);
	ft_putchar_fd('\n', 0);
	ft_itoa(0);
	ft_putchar_fd('\n', 0);
	ft_itoa(-5);
	ft_putchar_fd('\n', 0);
	ft_itoa(5);
	ft_putchar_fd('\n', 0);
	ft_itoa(22);
	ft_putchar_fd('\n', 0);
	ft_itoa(-22);
	ft_putchar_fd('\n', 0);
}
