/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 03:05:25 by klavada           #+#    #+#             */
/*   Updated: 2020/07/23 19:25:06 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <stdio.h>

int		main(void)
{
//	char *p;
//	p = NULL;
//	int	a;
//	char *test = "12345";

//	a = 123;

	ft_printf("hello %corld\n", 'w');
	printf("hello %corld\n", 'w');

//	ft_printf("%s\n", p);
//	printf("%s\n", p);

//	ft_printf("hello world\n");
//	printf("hello world\n");

//	ft_printf("hello %d world\n", a);
//	printf("hello %d world\n", a);

//	ft_printf("%X\n", 123);
//	printf("%X\n", 123); 
	
//	ft_printf("\n\n");
//	printf("\n\n");

//	ft_printf("%3s %5s %10s\n", test, test, test);
//	printf("%3s %5s %10s\n", test, test, test);

//	ft_printf("%s%s %-5s %-10s\n", test, test, test, test);
//	printf("%s%s %-5s %-10s\n", test, test, test, test);

//	ft_printf("%.3s %.5s %.10s\n", test, test, test);
//	printf("%.3s %.5s %.10s\n", test, test, test);

//	ft_printf("%% abc %--*s %.*s xxx\n", 4,"abc", -0, "123");
//	printf("%% abc %--*s %.*s xxx\n", 4,"abc", -0, "123");

	//ft_printf("%p\n", p);	
	//printf("%p\n", p);
	//ft_printf("%0s %10s\n", "", "");
	//printf("%0s %10s\n", "", "");
	//ft_printf("%0s %00--*.*s \n", "12345", 10, 10, "12345");
	//printf("%0s %00--*.*s \n", "12345", 10, 10, "12345");
	
	//ft_printf("%c %d %s   %x %% %u  %X %p %i 555 asd\n", 'p', 10, "hello", 164, -10, 164, p, 0x123);
	//printf("%c %d %s   %x %% %u  %X %p %i 555 asd\n", 'p', 10, "hello", 164, -10, 164, p, 0x123);
	//printf("My - %d\n", ft_printf("not my:%20s%c%0-*.*d is life\n", "casubmar", '\0', -100, -42, 42));
	//printf("My - %d\n", printf("not my:%20s%c%0-*.*d is life\n", "casubmar", '\0', -100, -42, 42));
	//printf("not my:%20s is life\n", "casubmar");
	//printf("%.3d\n", 3);
	//ft_printf("Hello world, if %-*d, my name is %-*.2s if %p%i\n", 10, 42, 15, "casubmar", &p, 0x123);
	//printf("Hello world, if %-*d, my name is %-*.2s if %p%i\n", 10, 42, 15, "casubmar", &p, 0x123);
	//ft_printf("%-*.*s\n", 5, 1, "casubmar");
	//printf("%-*.*s\n", 5, 1, "casubmar");
	//printf("%20.1s\n", "casubmar");
	//ft_printf("%20.1s\n", "casubmar");
	//printf("%ld\n", ft_strlen("hello"));
	//printf("p0 %.3s\n", "cccc");                   //РАБОТАЕТ
	//ft_printf("p0 %.3s\n", "cccc");                //РАБОТАЕТ
	//printf("pp %.50d\n", 10000);                     //РАБОТАЕТ
	//ft_printf("pp %.50d\n", 10000);                  //РАБОТАЕТ
	//printf("p1 %.4s\n", "cccc");                      //OK
	//ft_printf("p1 %.4s\n", "cccc");                   //OK
	//printf("p2 %.10s\n", "cccc");                       //OK
	//ft_printf("p2 %.10s\n", "cccc");                    //OK
	//ft_printf("p3 %.4s\n", NULL);                     //OK
	//printf("p3 %.4s\n", NULL);                        //OK
	//printf("p4 %.5s\n", "aaaaa");                     //OK
	//ft_printf("p4 %.5s\n", "aaaaa");                  //OK
	//printf("p5 %.3d\n", 100);                             //OK
	//ft_printf("p5 %.3d\n", 100);                         //OK
	//ft_printf("p6 %.0d\n", 100);                           //OK
	//printf("p6 %.0d\n", 100);                           //OK
	//printf("p7 %.4d\n", 100);                            //OK
	//ft_printf("p7 %.4d\n", 100);                        //OK
	//printf("p8 %.10d\n", 100);              //OK
	//ft_printf("p8 %.10d\n", 100);            //OK
	//printf("p9 %.50d\n", 100);                     //ok
	//ft_printf("p9 %.50d\n", 100);              //ok
	//printf("p10 %.1d\n", 100);              //ok
	//ft_printf("p10 %.1d\n", 100);             //ok
	//printf("p11 %.3d\n", 100);               //ok
	//ft_printf("p11 %.3d\n", 100);               //ok
	//printf("p12 %.0d\n", 0);            //ok WTF
	//ft_printf("p12 %.0d\n", 0);         //ok WTF
	//ft_printf("p13 %.3i\n", 100);       //ok
	//printf("p13 %.3i\n", 100);          //ok
	//printf("p14 %.0i\n", 100);            //ok
	//ft_printf("p14 %.0i\n", 100);         //ok
	//printf("p15 %.4i\n", 100);             //ok
	//ft_printf("p15 %.4i\n", 100);          //ok
	//printf("p16 %.10i\n", 100);              //ok
	//ft_printf("p16 %.10i\n", 100);      //ok
	//printf("p17 %.50i\n", 100);           //ok
	//ft_printf("p17 %.50i\n", 100);        //ok
	//printf("p18 %.1i\n", 100);              //ok
	//ft_printf("p18 %.1i\n", 100);         //ok
	//printf("p19 %.3x\n", 100);             //ok
	//ft_printf("p19 %.3x\n", 100);        //ok
	//printf("p20 %.0x\n", 0);               //ok
	//ft_printf("p20 %.0x\n", 0);          //ok
	//printf("p21 %.3x\n", 100);           //ok
	//ft_printf("p21 %.3x\n", 100);           //ok
	//printf("p22 %.0x\n", 100);            //ok
	//ft_printf("p22 %.0x\n", 100);            //ok
	//printf("p23 %.4x\n", 100);             //ok
	//ft_printf("p23 %.4x\n", 100);          //ok
	//printf("p24 %.10x\n", 100);             //ok
	//ft_printf("p24 %.10x\n", 100);           //ok
	//printf("p25 %.50x\n", 100);              //ok
	//ft_printf("p25 %.50x\n", 100);            //ok
	//printf("p26 %.1x\n", 100);                 //ok
	//ft_printf("p26 %.1x\n", 100);           //ok
	//printf("p27 %.3x\n", 100);              //ok
	//ft_printf("p27 %.3x\n", 100);           //ok
	//printf("p28 %.0x\n", 0);                 //ok
	//ft_printf("p28 %.0x\n", 0);               //ok
	//printf("p29 %.3u\n", 100);                  //ok
	//ft_printf("p29 %.3u\n", 100);              //ok
	//printf("p30 %.0u\n", 100);                  //ok
	//ft_printf("p30 %.0u\n", 100);               //ok
	//printf("p31 %.4u\n", 100);                   //ok
	//ft_printf("p31 %.4u\n", 100);                //ok
	//printf("p32 %.10u\n", 100);					//ok
	//ft_printf("p32 %.10u\n", 100);                 //ok
	//printf("p33 %.50u\n", 100);                  //ok
	//ft_printf("p33 %.50u\n", 100);                //ok
	//printf("p34 %.1u\n", 100);                    //ok
	//ft_printf("p34 %.1u\n", 100);                  //ok
	//printf("p35 %.3u\n", 100);                    //ok
	//ft_printf("p35 %.3u\n", 100);                  //ok
	//printf("p36 %.0u\n", 0);                    //ok WTF
	//ft_printf("p36 %.0u\n", 0);                //ok WTF
	//printf("%%\n");                              //ok
	//ft_printf("%%\n");                              //ok
	//ft_printf("%010%");                        //ok
	//printf("%010%");                           //ok
	//ft_printf("%.2s,%5.0d,%d %p", NULL, 42, 42, NULL);
	//ft_printf("ft - %7.5s\n", "yolo");
	//printf("printf - %d\nft_printf - %d", d, d1);
	return (0);
}
