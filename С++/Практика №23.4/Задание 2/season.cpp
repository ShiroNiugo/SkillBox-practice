#include <iostream>

#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define WINTER 4

#define SEASON AUTUMN

#if SEASON >= SPRING && SEASON <= WINTER
#define SHOW(s) printf("%s\n", (s == 1)?"Spring":((s==2)?"Summer":((s==3)?"Autumn":"Winter")))
int main()
{
	SHOW(SEASON);
	return 0;
}
#endif