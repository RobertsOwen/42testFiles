/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroberts <oroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:44:16 by oroberts          #+#    #+#             */
/*   Updated: 2019/11/12 12:47:57 by oroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#ifndef STRING
# define STRING "this is a string"
#endif

int main ()
{
	void *test = (void *)140367269735040;

	void **tests = malloc(sizeof(void *) * 4);
	for (int i = 0; i < 4; i++)
		tests[i] = malloc(42);

	//unsigned long tmp = 140732898131832;
	//unsigned int	u = 4147483647;
	//char			str[] = STRING;

	int printed;
	
	t_flags def;
	t_flags space;
	ft_freset(&space);
	space.space = 10;
	t_flags dot;
	ft_freset(&dot);
	dot.dot = 10;
	ft_freset(&def);
	/*
	printf("int\t\t: %%d: %d\n", 42);
	printf("string\t\t: %%s: %s\n", "42 4 EVA");
	printf("char\t\t: %%c: %c\n", 'A');					//int
	printf("pointer\t\t: %%p: %p\n", test);
	printf("int ?\t\t: %%i: %i\n", 42);
	printf("unsigned int\t: %%u: %u\n", 300000000);
	printf("Hexa lower\t: %%x: %x\n", 42);				//unsigned int
	printf("Hexa upper\t: %%X: %X\n", 42);				//unsigned int

	printf("sizeof(void *) = %lu\n", sizeof(void *));
	printf("sizeof(luint) = %lu\n", sizeof(unsigned long int));


	printf("flags:\n");
	printf("\t-1int: \"%-1d\"\n", 42);
	printf("\t-2int: \"%-2d\"\n", 42);
	printf("\t-3int: \"%-3d\"\n", 42);
	printf("\t-4int: \"%-4d\"\n", 42);
	
	printf("\n\t1int : \"%1d\"\n", 42);
	printf("\t2int : \"%2d\"\n", 42);
	printf("\t3int : \"%3d\"\n", 42);
	printf("\t4int : \"%4d\"\n", 42);

	printf("\n\t+int : \"%+d\"\n", 42);

	printf("\n\t01int: \"%01d\"\n", 42);
	printf("\t02int: \"%02d\"\n", 42);
	printf("\t03int: \"%03d\"\n", 42);
	printf("\t04int: \"%04d\"\n", 42);

	printf("\n\t01.1int: \"%01.1d\"\n", 42);
	printf("\t02.2int: \"%02.2d\"\n", 42);
	printf("\t03.3int: \"%03.3d\"\n", 42);
	printf("\t04.4int: \"%04.4d\"\n", 42);

	printf("\n\t5.4int: \"%5.4d\"\n", 42);	//" 0042"
	printf("\t4.8int: \"%4.8d\"\n", 42);	//"00000042"
	printf("\t10.2int: \"%10.2d\"\n", 42);	//"        42"
	printf("\t10.8int: \"%10.8d\"\n", 42);	//"  00000042"

	printf("\n\t01int: \"%01d\"\n", 42);
	printf("\t02int: \"%02d\"\n", 42);
	printf("\t03int: \"%03d\"\n", 42);
	printf("\t04int: \"%04d\"\n", 42);

	printf("\n\t05.1int: \"%05.1f\"\n", 42.123456789);
	printf("\t05.2int: \"%05.2f\"\n", 42.123456789);
	printf("\t05.3int: \"%05.3f\"\n", 42.123456789);
	printf("\t05.4int: \"%05.4f\"\n", 42.123456789);

	printf("\n\t0*.*x: \"%0*.*x\"\n", 3, 1, 42);
	printf("\t03.2x: \"%03.2x\"\n", 42);
	printf("\t03.3x: \"%03.3x\"\n", 42);
	printf("\t03.4x: \"%03.4x\"\n", 42);
	
	printf("\n\t.1s: \"%.1s\"\n", "42 4 EVA");
	printf("\t.2s: \"%.2s\"\n", "42 4 EVA");
	printf("\t.3s: \"%.3s\"\n", "42 4 EVA");
	printf("\t.4s: \"%.4s\"\n", "42 4 EVA");

	printf("\n\t-8s : \"%-8s\"\n", "42 4 EVA");
	printf("\t-9s : \"%-9s\"\n", "42 4 EVA");
	printf("\t-10s: \"%-10s\"\n", "42 4 EVA");
	printf("\t-11s: \"%-11s\"\n", "42 4 EVA");

	printf("\t15s : \"%15s\"\n", "0123456789");			//"     0123456789"
	printf("\tt-15s : \"%-15s\"\n", "0123456789");		//"0123456789     "
	printf("\t.5s : \"%.5s\"\n", "0123456789");			//"01234"
	printf("\t15.5s : \"%15.5s\"\n", "0123456789");		//"          01234"
	printf("\t-15.5s : \"%-15.5s\"\n", "0123456789");	//"01234          "

	printf("\n\t1c : \"%1c\"\n", 'A');
	printf("\t-1c : \"%-1c\"\n", 'A');
	printf("\t3c: \"%3c\"\n", 'A');
	printf("\t-3c: \"%-3c\"\n", 'A');

	printf("\n\t12u : \"%12u\"\n", (unsigned int)3000000000);			//"3000000000"
	printf("\t12.11u : \"%12.11u\"\n", (unsigned int)3000000000);	//" 03000000000"
	printf("\t11.12u: \"%11.12u\"\n", (unsigned int)3000000000);	//"003000000000"
	printf("\t-15.13: \"%-15.13u\"\n", (unsigned int)3000000000);	//"003000000000  "

	printf("\n\n\t\tPTR:\n\n\n");

	printf("\t-15p: \"%-15p\"\n", test);
	printf("\t15p:  \"%15p\"\n", NULL);
	

	printf("\n\n\t\tHEX:\n\n\n");

	printf("\t-4x: \"%-4x\"\n", 300);
	printf("\t4x: \"%4x\"\n", 300);
	printf("\t.4x: \"%.4x\"\n", 300);
	printf("\t04x: \"%04x\"\n", 300);
	printf("\t05.4x: \"%05.4x\"\n", 300);
	printf("\t-5.4x: \"%-5.4x\"\n", 300);
*/
	ft_putstr_flags("\n\n\n\n\t\t\t\ttest\n\n\n", def);

	ft_putstr_flags("\nint:\n", def);
	printed = ft_putnbr_flags(42, dot);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(-42, dot);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(100, space);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(-100000, space);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(0, dot);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(INT_MIN, space);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putnbr_flags(INT_MAX, dot);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	space.space += 5;
	ft_putstr_flags("\nstr:\n", def);
	printed = ft_putstr_flags("0123456789", space);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);

	printed = ft_putstr_flags("01234567890123456789", dot);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putstr_flags("\n", def);


	ft_putstr_flags("\nstring:\n", def);
	printed = ft_putstr_flags("42 4 EVA\n", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("\ntes grands morts\n", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("Bonjour ca a l'air de fonctionner !\n", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("a + !\n", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("a + !\n", def);
	ft_putnbr(printed);
	ft_putchar('\n');

	printed = ft_putstr_flags("123456789-", def);
	ft_putnbr(printed);
	ft_putchar('\n');




	//ft_putstr_flags("chars:");
	//for (int i = 0; i < 128; i++)
	//{
	//	ft_putstr_flags("i=");
	//	ft_putnbr(i);
	//	ft_putstr_flags("=>\"");
	//	ft_putchar(i);
	//	ft_putstr_flags("\"\n");
	//}

	ft_putstr_flags("\nunsigned int:\n", def);
	printed = ft_putunsignednbr(UINT_MAX);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');
	printed = ft_putunsignednbr(0);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');
	printed = ft_putunsignednbr(10);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');
	printed = ft_putunsignednbr(42);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');
	printed = ft_putunsignednbr(100000);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');


	ft_putstr_flags("\npointers:\n", def);
	printed = ft_putpointer(test);
	ft_putstr_flags("=>", def);
	ft_putnbr(printed);
	ft_putchar('\n');




	printed = ft_printf("voici le dernier test.\n\
ce dernier a pour vocation de tester TOUT les fontionnements de ft_printf.\n\
Le resultat sera comparee a la vraie fonction printf\n\
specials: 100%5% de reussite\n\
entiers:\n\
	A:d      : \"%d\" == \"42\"\n\
	B:055d   : \"%05d\" == \"00042\"\n\
	C:7d     : \"%7d\" == \"     42\"\n\
	D:-3d    : \"%-3d\" == \"42 \"\n\
	\n\
	E:012d   : \"%012d\" == \"000000000042\"\n\
	F:4.8d   : \"%4.8d\" == \"00000042\"\n\
	G:10.2d  : \"%10.2d\" == \"        42\"\n\
	H:10.8d  : \"%10.8d\" == \"  00000042\"\n\
	\n\
strings:\n\
	A:s      : \"%s\" == \"42 4 EVA\"\n\
	B:s      : \"%s\" == \"je ne sais plus quoi dire à force...\"\n\
	C:s      : \"%s\" == \"\"\n\
	D:s      : \"%s\"\n\
	\n\
	E:15s    : \"%15s\" == \"     0123456789\"\n\
	F:-15s   : \"%-15s\" == \"0123456789     \"\n\
	G:.5s    : \"%.5s\" == \"01234\"\n\
	H:15.5s  : \"%15.5s\" == \"  3000000000\"\n\
	I:-15.5s : \"%-15.5s\" == \"01234          \"\n\
	\n\
chars:\n\
	A:c      : \"%c\" == \"4\"\n\
	B:c      : \"%c\" == \"\t\"\n\
	C:c      : \"%c\" == \"\\\"\n\
	D:c      : \"%c\" == \"%%\"\n\
	\n\
	E:1c     : \"%1c\" == \"A\"\n\
	F:-1c    : \"%-1c\" == \"A\"\n\
	G:3c     : \"%3c\" == \"  A\"\n\
	H:-3c    : \"%-3c\" == \"A  \"\n\
	\n\
unsigned int:\n\
	A:u      : \"%u\" == \"4294967295\"\n\
	B:02u    : \"%02u\" == \"00\"\n\
	C:-12u   : \"%-12u\" == \"4000000000  \"\n\
	D:.12u   : \"%.12u\" == \"000123456789\"\n\
	\n\
	E:12u    : \"%12u\" == \"  3000000000\"\n\
	F:12.11u : \"%12.11u\" == \" 03000000000\"\n\
	G:11.12u : \"%11.12u\" == \"003000000000\"\n\
	H:-15.13u: \"%-15.13u\" == \"0003000000000  \"\n\
	\n\
Hex numbers:\n\
	A:x      : \"%x\" == \"12c\"\n\
	B:X      : \"%X\" == \"12C\"\n\
	C:-4x    : \"%-4x\" == \"12c \"\n\
	D:4X     : \"%4X\" == \" 12C\"\n\
	\n\
	E:.4x    : \"%.4x\" == \"012c\"\n\
	F:04X    : \"%04X\" == \"012C\"\n\
	G:05.4x  : \"%05.4x\" == \" 012c\"\n\
	H:-5.4X  : \"%-5.4X\" == \"012C \"\n\
pointers:\n\
	A:p      : \"%p\" == \"0x7fa9cd402a80\"\n\
	B:15p    : \"%15p\" == \" 0x7fa9cd402a80\"\n\
	C:-16p   : \"%-16p\" == \"0x7fa9cd402a80  \"\n\
	D:17p    : \"%17p\" == \"   0x7fa9cd402a80\"\n\
	\n\
	E:5p     : \"%5p\" == \"  0x0\"\n\
	F:-5p    : \"%-5p\" == \"0x0  \"\n\
	\n\
Tout les tests sont terminer.\n", \
42, 42, 42, 42, 42, 42, 42, 42, \
"42 4 EVA", "je ne sais plus quoi dire à force...", "", "bvuer gfyiuasbiuehbb r\vten\tdg\\d\\nYEET", \
	"0123456789", "0123456789", "0123456789", "0123456789", "0123456789", \
'4', '\t','\\', '%', \
	'A', 'A', 'A', 'A', \
UINT_MAX, 0, (unsigned int)4000000000, 123456789, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
300, 300, 300, 300, \
	300, 300, 300, 300, \
tests[0], tests[1], tests[2], tests[3], NULL, NULL);
	
	int printedTrue = printf("voici le dernier test.\n\
ce dernier a pour vocation de tester TOUT les fontionnements de ft_printf.\n\
Le resultat sera comparee a la vraie fonction printf\n\
specials: 100%5% de reussite\n\
entiers:\n\
	A:d      : \"%d\" == \"42\"\n\
	B:055d   : \"%05d\" == \"00042\"\n\
	C:7d     : \"%7d\" == \"     42\"\n\
	D:-3d    : \"%-3d\" == \"42 \"\n\
	\n\
	E:012d   : \"%012d\" == \"000000000042\"\n\
	F:4.8d   : \"%4.8d\" == \"00000042\"\n\
	G:10.2d  : \"%10.2d\" == \"        42\"\n\
	H:10.8d  : \"%10.8d\" == \"  00000042\"\n\
	\n\
strings:\n\
	A:s      : \"%s\" == \"42 4 EVA\"\n\
	B:s      : \"%s\" == \"je ne sais plus quoi dire à force...\"\n\
	C:s      : \"%s\" == \"\"\n\
	D:s      : \"%s\"\n\
	\n\
	E:15s    : \"%15s\" == \"     0123456789\"\n\
	F:-15s   : \"%-15s\" == \"0123456789     \"\n\
	G:.5s    : \"%.5s\" == \"01234\"\n\
	H:15.5s  : \"%15.5s\" == \"  3000000000\"\n\
	I:-15.5s : \"%-15.5s\" == \"01234          \"\n\
	\n\
chars:\n\
	A:c      : \"%c\" == \"4\"\n\
	B:c      : \"%c\" == \"\t\"\n\
	C:c      : \"%c\" == \"\\\"\n\
	D:c      : \"%c\" == \"%%\"\n\
	\n\
	E:1c     : \"%1c\" == \"A\"\n\
	F:-1c    : \"%-1c\" == \"A\"\n\
	G:3c     : \"%3c\" == \"  A\"\n\
	H:-3c    : \"%-3c\" == \"A  \"\n\
	\n\
unsigned int:\n\
	A:u      : \"%u\" == \"4294967295\"\n\
	B:02u    : \"%02u\" == \"00\"\n\
	C:-12u   : \"%-12u\" == \"4000000000  \"\n\
	D:.12u   : \"%.12u\" == \"000123456789\"\n\
	\n\
	E:12u    : \"%12u\" == \"  3000000000\"\n\
	F:12.11u : \"%12.11u\" == \" 03000000000\"\n\
	G:11.12u : \"%11.12u\" == \"003000000000\"\n\
	H:-15.13u: \"%-15.13u\" == \"0003000000000  \"\n\
	\n\
Hex numbers:\n\
	A:x      : \"%x\" == \"12c\"\n\
	B:X      : \"%X\" == \"12C\"\n\
	C:-4x    : \"%-4x\" == \"12c \"\n\
	D:4X     : \"%4X\" == \" 12C\"\n\
	\n\
	E:.4x    : \"%.4x\" == \"012c\"\n\
	F:04X    : \"%04X\" == \"012C\"\n\
	G:05.4x  : \"%05.4x\" == \" 012c\"\n\
	H:-5.4X  : \"%-5.4X\" == \"012C \"\n\
pointers:\n\
	A:p      : \"%p\" == \"0x7fa9cd402a80\"\n\
	B:15p    : \"%15p\" == \" 0x7fa9cd402a80\"\n\
	C:-16p   : \"%-16p\" == \"0x7fa9cd402a80  \"\n\
	D:17p    : \"%17p\" == \"   0x7fa9cd402a80\"\n\
	\n\
	E:5p     : \"%5p\" == \"  0x0\"\n\
	F:-5p    : \"%-5p\" == \"0x0  \"\n\
	\n\
Tout les tests sont terminer.\n", \
42, 42, 42, 42, 42, 42, 42, 42, \
"42 4 EVA", "je ne sais plus quoi dire à force...", "", "bvuer gfyiuasbiuehbb r\vten\tdg\\d\\nYEET", \
	"0123456789", "0123456789", "0123456789", "0123456789", "0123456789", \
'4', '\t','\\', '%', \
	'A', 'A', 'A', 'A', \
UINT_MAX, 0, (unsigned int)4000000000, 123456789, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
300, 300, 300, 300, \
	300, 300, 300, 300, \
tests[0], tests[1], tests[2], tests[3], NULL, NULL);

	printf("original %d == %d man-made\n", printedTrue, printed);







	printf("\n\n\n\t\tT E S T   D E   C O M P T A G E\n\n\n\n");

	printed = ft_printf("entiers:\n\
	A:d      : \"%d\" == \"42\"\n\
	B:05d    : \"%05d\" == \"00042\"\n\
	C:7d     : \"%7d\" == \"     42\"\n\
	D:-3d    : \"%-3d\" == \"42 \"\n\
	\n\
	E:012d   : \"%012d\" == \"000000000042\"\n\
	F:4.8d   : \"%4.8d\" == \"00000042\"\n\
	G:10.2d  : \"%10.2d\" == \"        42\"\n\
	H:10.8d  : \"%10.8d\" == \"  00000042\"\n\
	\n", 42, 42, 42, 42, 42, 42, 42, 42);
	printedTrue= printf("entiers:\n\
	A:d      : \"%d\" == \"42\"\n\
	B:05d    : \"%05d\" == \"00042\"\n\
	C:7d     : \"%7d\" == \"     42\"\n\
	D:-3d    : \"%-3d\" == \"42 \"\n\
	\n\
	E:012d   : \"%012d\" == \"000000000042\"\n\
	F:4.8d   : \"%4.8d\" == \"00000042\"\n\
	G:10.2d  : \"%10.2d\" == \"        42\"\n\
	H:10.8d  : \"%10.8d\" == \"  00000042\"\n\
	\n", 42, 42, 42, 42, 42, 42, 42, 42);
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);





	printed = ft_printf("strings:\n\
	A:s      : \"%s\" == \"42 4 EVA\"\n\
	B:s      : \"%s\" == \"je ne sais plus quoi dire à force...\"\n\
	C:s      : \"%s\" == \"\"\n\
	D:s      : \"%s\"\n\
	\n\
	E:15s    : \"%15s\" == \"     0123456789\"\n\
	F:-15s   : \"%-15s\" == \"0123456789     \"\n\
	G:.5s    : \"%.5s\" == \"01234\"\n\
	H:15.5s  : \"%15.5s\" == \"          01234\"\n\
	I:-15.5s : \"%-15.5s\" == \"01234          \"\n\
	\n", "42 4 EVA", "je ne sais plus quoi dire à force...", "", "bvuer gfyiuasbiuehbb r\vten\tdg\\d\\nYEET", \
	"0123456789", "0123456789", "0123456789", "0123456789", "0123456789");
	printedTrue = printf("strings:\n\
	A:s      : \"%s\" == \"42 4 EVA\"\n\
	B:s      : \"%s\" == \"je ne sais plus quoi dire à force...\"\n\
	C:s      : \"%s\" == \"\"\n\
	D:s      : \"%s\"\n\
	\n\
	E:15s    : \"%15s\" == \"     0123456789\"\n\
	F:-15s   : \"%-15s\" == \"0123456789     \"\n\
	G:.5s    : \"%.5s\" == \"01234\"\n\
	H:15.5s  : \"%15.5s\" == \"          01234\"\n\
	I:-15.5s : \"%-15.5s\" == \"01234          \"\n\
	\n", "42 4 EVA", "je ne sais plus quoi dire à force...", "", "bvuer gfyiuasbiuehbb r\vten\tdg\\d\\nYEET", \
	"0123456789", "0123456789", "0123456789", "0123456789", "0123456789");
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);






	printed = ft_printf("chars:\n\
	A:c      : \"%c\" == \"4\"\n\
	B:c      : \"%c\" == \"\t\"\n\
	C:c      : \"%c\" == \"\\\"\n\
	D:c      : \"%c\" == \"%%\"\n\
	\n\
	E:1c     : \"%1c\" == \"A\"\n\
	F:-1c    : \"%-1c\" == \"A\"\n\
	G:3c     : \"%3c\" == \"  A\"\n\
	H:-3c    : \"%-3c\" == \"A  \"\n\
	\n", '4', '\t','\\', '%', \
	'A', 'A', 'A', 'A');
	printedTrue = printf("chars:\n\
	A:c      : \"%c\" == \"4\"\n\
	B:c      : \"%c\" == \"\t\"\n\
	C:c      : \"%c\" == \"\\\"\n\
	D:c      : \"%c\" == \"%%\"\n\
	\n\
	E:1c     : \"%1c\" == \"A\"\n\
	F:-1c    : \"%-1c\" == \"A\"\n\
	G:3c     : \"%3c\" == \"  A\"\n\
	H:-3c    : \"%-3c\" == \"A  \"\n\
	\n", '4', '\t','\\', '%', \
	'A', 'A', 'A', 'A');
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);







	printed = ft_printf("unsigned int:\n\
	A:u      : \"%u\" == \"4294967295\"\n\
	B:02u    : \"%02u\" == \"00\"\n\
	C:-12u   : \"%-12u\" == \"4000000000  \"\n\
	D:.12u   : \"%.12u\" == \"000123456789\"\n\
	\n\
	E:12u    : \"%12u\" == \"  3000000000\"\n\
	F:12.11u : \"%12.11u\" == \" 03000000000\"\n\
	G:11.12u : \"%11.12u\" == \"003000000000\"\n\
	H:-15.13u: \"%-15.13u\" == \"0003000000000  \"\n\
	\n", UINT_MAX, 0, (unsigned int)4000000000, 123456789, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
	(unsigned int)3000000000, (unsigned int)3000000000);
	printedTrue = printf("unsigned int:\n\
	A:u      : \"%u\" == \"4294967295\"\n\
	B:02u    : \"%02u\" == \"00\"\n\
	C:-12u   : \"%-12u\" == \"4000000000  \"\n\
	D:.12u   : \"%.12u\" == \"000123456789\"\n\
	\n\
	E:12u    : \"%12u\" == \"  3000000000\"\n\
	F:12.11u : \"%12.11u\" == \" 03000000000\"\n\
	G:11.12u : \"%11.12u\" == \"003000000000\"\n\
	H:-15.13u: \"%-15.13u\" == \"0003000000000  \"\n\
	\n", UINT_MAX, 0, (unsigned int)4000000000, 123456789, \
	(unsigned int)3000000000, (unsigned int)3000000000, \
	(unsigned int)3000000000, (unsigned int)3000000000);
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);

	


	printed = ft_printf("Hex numbers:\n\
	A:x      : \"%x\" == \"12c\"\n\
	B:X      : \"%X\" == \"12C\"\n\
	C:-4x    : \"%-4x\" == \"12c \"\n\
	D:4X     : \"%4X\" == \" 12C\"\n\
	\n\
	E:.4x    : \"%.4x\" == \"012c\"\n\
	F:04X    : \"%04X\" == \"012C\"\n\
	G:05.4x  : \"%05.4x\" == \" 012c\"\n\
	H:-5.4X  : \"%-5.4X\" == \"012C \"\n\
	\n", 300, 300, 300, 300, \
	300, 300, 300, 300);
	printedTrue = printf("Hex numbers:\n\
	A:x      : \"%x\" == \"12c\"\n\
	B:X      : \"%X\" == \"12C\"\n\
	C:-4x    : \"%-4x\" == \"12c \"\n\
	D:4X     : \"%4X\" == \" 12C\"\n\
	\n\
	E:.4x    : \"%.4x\" == \"012c\"\n\
	F:04X    : \"%04X\" == \"012C\"\n\
	G:05.4x  : \"%05.4x\" == \" 012c\"\n\
	H:-5.4X  : \"%-5.4X\" == \"012C \"\n\
	\n", 300, 300, 300, 300, \
	300, 300, 300, 300);
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);




	printed = ft_printf("pointers:\n\
	A:p      : \"%p\" == \"0x7fa9cd402a80\"\n\
	B:15p    : \"%15p\" == \" 0x7fa9cd402a80\"\n\
	C:-16p   : \"%-16p\" == \"0x7fa9cd402a80  \"\n\
	D:17p    : \"%17p\" == \"   0x7fa9cd402a80\"\n\
	\n\
	E:5p     : \"%5p\" == \"  0x0\"\n\
	F:-5p    : \"%-5p\" == \"0x0  \"\n\
	\n", tests[0], tests[1], tests[2], tests[3], NULL, NULL);
	printedTrue = printf("pointers:\n\
	A:p      : \"%p\" == \"0x7fa9cd402a80\"\n\
	B:15p    : \"%15p\" == \" 0x7fa9cd402a80\"\n\
	C:-16p   : \"%-16p\" == \"0x7fa9cd402a80  \"\n\
	D:17p    : \"%17p\" == \"   0x7fa9cd402a80\"\n\
	\n\
	E:5p     : \"%5p\" == \"  0x0\"\n\
	F:-5p    : \"%-5p\" == \"0x0  \"\n\
	\n", tests[0], tests[1], tests[2], tests[3], NULL, NULL);
	printf("original %d == %d man-made\n\n\n", printedTrue, printed);


	printf("\n\n\n\n\t\tT E S T   S U P P L E M E N T A I R E\n\n\n");

	ft_printf("6\tpointeur\t: |%*p|\n", 18, NULL);

	printf("\n");

	printf("9\tint3\t\t: |%00d|\t\t\t|%0.0d|\t\t|%06.0d|\n", 78, 123, 42);
	ft_printf("9\tint3\t\t: |%00d|\t\t\t|%0.0d|\t\t|%06.0d|\n", 78, 123, 42);

	printf("\n");

	printf("11\tint5\t\t: |%6.4d|\t\t|%-8d|\t|%06.4d|\n", -78, -123, -42);
	ft_printf("11\tint5\t\t: |%6.4d|\t\t|%-8d|\t|%06.4d|\n", -78, -123, -42);

	printf("\n");

	printf("12\tint6\t\t: |%08.3d|\t|%.*d|\t\t|%.1d|\n", -45, 0, -23, -17);
	ft_printf("12\tint6\t\t: |%08.3d|\t|%.*d|\t\t|%.1d|\n", -45, 0, -23, -17);

	printf("\n");

	printf("13\tint7\t\t: |%8.3d|\t|%.*d|\t\t|%05d|\n", -45, -4, -789, -2);
	ft_printf("13\tint7\t\t: |%8.3d|\t|%.*d|\t\t|%05d|\n", -45, -4, -789, -2);

	printf("\n");

	printf("14\tint8\t\t: |%00d|\t\t\t|%0.0d|\t\t|%06.0d|\n", -78, -123, -42);
	ft_printf("14\tint8\t\t: |%00d|\t\t\t|%0.0d|\t\t|%06.0d|\n", -78, -123, -42);

	printf("\n");

	printf("19\tint13\t\t: |%*.4d|\t\t|%08d|\t|%d|\n", -6, -2, -4, -2);
	ft_printf("19\tint13\t\t: |%*.4d|\t\t|%08d|\t|%d|\n", -6, -2, -4, -2);
	
	printf("\n");

	printf("hexa \t\t: |%.0x|\n", 0);
	ft_printf("hexa \t\t: |%.0x|\n", 0);

	printf("%%\t\t: |%05%|\n");
	ft_printf("%%\t\t: |%05%|\n");

	printf(".p: %.p\n", NULL);
	ft_printf(".p: %.p\n", NULL);

	printf(".-5s: %.*s\n", -5,  "0123456789");
	ft_printf(".-5s: %.*s\n", -5,"0123456789");

	printf("%.*d\n", -5, 42);
	ft_printf("%.*d\n", -5, 42);


	for (int i = 0; i < 4; i++)
		free(tests[i]);

	printf("                            ,\n\
                          _/((\n\
                 _.---. .'   `\\  (QUACK)\n\
               .'      `     ^ \\ \n\
              /     \\       .--'\n\
             |      /       )'-.\n\
             ; ,   <__..-(   '-.)\n\
              \\ \\-.__)    ``--._)\n\
               '.'-.__.-.\n\
                 '-...-'\n");
	
	return (0);
}

/*
                            ,
                          _/((
                 _.---. .'   `\  (QUACK)
               .'      `     ^ \
              /     \       .--'
             |      /       )'-.
             ; ,   <__..-(   '-.)
              \ \-.__)    ``--._)
               '.'-.__.-.
                 '-...-'
*/