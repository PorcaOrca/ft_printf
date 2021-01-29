if (*str == 'd')
			{
				temp = ft_itoa(va_arg(argptr, int));
				n_lenght = ft_strlen(temp);
				prec -= n_lenght;
			//	if (pad > prec)
			//		c_just = ' ';
				if (prec > 0)
					pad -= prec;
				pad -= n_lenght;
				if (!left && pad > 0)
				{
					if (*temp == '-')
						pad--;
					while (pad--)
						ft_putchar_fd(c_just, 1);
				}
				if (*temp == '-')
				{
					ft_putchar_fd('-', 1);
					n_lenght--;
					temp++;
					prec++;
					pad--;
				}
				if (prec > 0)
				{
					while (prec--)
						ft_putchar_fd('0', 1);
				}
				while (n_lenght--)
				{
					ft_putchar_fd(*temp, 1);
					temp++;
				}
				if (left && pad > 0)
				{
					while (pad--)
						ft_putchar_fd(c_just, 1);
				}
