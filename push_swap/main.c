#include "./libft/libft.h"
#include <time.h>
void	leaks(void){
	system("leaks main");
}
int	compare(void *n1, void *n2)
{
	int	num1;
	int	num2;

	num1 = *((int*) n1);
	num2 = *((int*) n2);
	//ft_printf("%d -- %d\n", num1, num2);
	return (num1 - num2);
}

void	delete(void	*ptr)
{
	int	*p;

	p = (int *) ptr;
	free(p);
}

void	printer(void *p)
{
	int	*num;

	num = (int *) p;
	ft_printf("%d\n", *num);
}

int main(void){
	int *a[10];
	t_bst	*tree = NULL;
	t_bst	*new = NULL;
	int ret;
	void *p;
	atexit(leaks);
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		a[i] = malloc(sizeof(int));
		*(a[i]) = rand() % 100;
		ft_printf("%d\n", *(a[i]));
		p = (void *) a[i];
		new = ft_bstnew(p);
		ret = ft_bstinsert(&tree, new, compare);
		if (ret == -1)
		{
			ft_bstprint(&tree, printer);
			ft_bstclear(&tree, delete);
			ft_bstclear(&new, delete);
			break;
		}
	}
	ft_bstprint(&tree, printer);

	ft_bstclear(&tree, delete);
}
