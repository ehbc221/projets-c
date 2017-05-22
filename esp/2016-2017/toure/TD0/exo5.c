#include "stdio.h"
int main(int argc, char const *argv[])
{
	int i=8, j=5, valeur_int;
	float x=0.005, y=-0.01, valeur_float;
	char c='c', d='d', valeur_char;
	printf("Exercice 5 :\n");
	// (3 * i - 2 * j) % (2 * d - c)
	printf("\n(a)\n");
	valeur_int = (3 * i - 2 * j) % (2 * d - c);
	printf("(3 * i - 2 * j) %% (2 * d - c) : %d\n", valeur_int);
	// 2 * ((i / 5) + (4 * (j - 3)) % ( i + j - 2))
	printf("\n(b)\n");
	valeur_int = 2 * ((i / 5) + (4 * (j - 3)) % ( i + j - 2));
	printf("2 * ((i / 5) + (4 * (j - 3)) %d ( i + j - 2)) : %d\n", valeur_int);
	// (i - 3 * j ) % ( c + 2 * d ) / ( x - y )
	printf("\n(c)\n");
	valeur_float = (i - 3 * j ) % ( c + 2 * d ) / ( x - y );
	printf("(i - 3 * j ) %% ( c + 2 * d ) / ( x - y ) : %f\n", valeur_float);
	// -(i + j)
	printf("\n(d)\n");
	valeur_int = -(i + j);
	printf("-(i + j) : %d\n", valeur_int);
	// ++i
	printf("\n(e)\n");
	valeur_int = ++i;
	printf("++i : %d\n", valeur_int);
	// i++
	printf("\n(f)\n");
	valeur_int = i++;
	printf("i++ : %d\n", valeur_int);
	// --j
	printf("\n(g)\n");
	valeur_int = --j;
	printf("--j : %d\n", valeur_int);
	// ++x
	printf("\n(h)\n");
	valeur_float = ++x;
	printf("++x : %f\n", valeur_float);
	// y--
	printf("\n(i)\n");
	valeur_float = y--;
	printf("y-- : %f\n", valeur_float);
	// i <= j
	printf("\n(j)\n");
	valeur_int = i <= j;
	printf("i <= j : %d\n", valeur_int);
	// c>d
	printf("\n(k)\n");
	valeur_int = c>d;
	printf("c>d : %d\n", valeur_int);
	// x >= 0
	printf("\n(l)\n");
	valeur_int = x >= 0;
	printf("x >= 0 : %d\n", valeur_int);
	// x < y
	printf("\n(m)\n");
	valeur_int = x < y;
	printf("x < y : %d\n", valeur_int);
	// j != 6;
	printf("\n(n)\n");
	valeur_int = j != 6;;
	printf("j != 6; : %d\n", valeur_int);
	// c == 99
	printf("\n(o)\n");
	valeur_int = c == 99;
	printf("c == 99 : %d\n", valeur_int);
	// 5 * (i + j ) > ' c '
	printf("\n(p)\n");
	valeur_int = 5 * (i + j ) > ' c ';
	printf("5 * (i + j ) > ' c ' : %d\n", valeur_int);
	// ( 2 * x + y) == 0
	printf("\n(q)\n");
	valeur_int = ( 2 * x + y) == 0;
	printf("( 2 * x + y) == 0 : %d\n", valeur_int);
	// 2 * x + ( y = = 0)
	printf("\n(r)\n");
	valeur_int = 2 * x + ( y == 0);
	printf("2 * x + ( y == 0) : %d\n", valeur_int);
	// 2 * x + y == 0
	printf("\n(s)\n");
	valeur_int = 2 * x + y == 0;
	printf("2 * x + y == 0 : %d\n", valeur_int);
	// ! ( i <= j )
	printf("\n(t)\n");
	valeur_int = ! ( i <= j );
	printf("! ( i <= j ) : %d\n", valeur_int);
	// ! ( c == 99)
	printf("\n(u)\n");
	valeur_int = ! ( c == 99);
	printf("! ( c == 99) : %d\n", valeur_int);
	// ! ( x > 0)
	printf("\n(v)\n");
	valeur_int = ! ( x > 0);
	printf("! ( x > 0) : %d\n", valeur_int);
	// (i > 0) && ( j < 5)
	printf("\n(w)\n");
	valeur_int = (i > 0) && ( j < 5);
	printf("(i > 0) && ( j < 5) : %d\n", valeur_int);
	// ( i > 0) || ( j < 5)
	printf("\n(x)\n");
	valeur_int = ( i > 0) || ( j < 5);
	printf("( i > 0) || ( j < 5) : %d\n", valeur_int);
	// (x > y) && (i > 0) || ( j < 5)
	printf("\n(y)\n");
	valeur_int = (x > y) && (i > 0) || ( j < 5);
	printf("(x > y) && (i > 0) || ( j < 5) : %d\n", valeur_int);
	// (x > y) && (i > 0) && ( j < 5 )
	printf("\n(z)\n");
	valeur_int = (x > y) && (i > 0) && ( j < 5 );
	printf("(x > y) && (i > 0) && ( j < 5 ) : %d\n", valeur_int);
	return 0;
}
