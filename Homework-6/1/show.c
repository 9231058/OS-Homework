// In The Name Of God
// ========================================
// * File Name : show.c
// 
// * Creation Date : 13-12-2014
//
// * Last Modified : Sat 13 Dec 2014 03:04:13 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdio.h>
#include "hdd.h"
#include "show.h"

void show_header(){
	for(int i = 0; i < MAX_CYLINDERS; i++)
		printf("-----");
	printf("\n");
	for(int i = 0; i < MAX_CYLINDERS; i++)
		printf("%04d ", i);
	printf("\n");
}

void show_head(int position){
	int index = 0;
	for(index = 0; index < position; index++)
		printf("     ");
	printf("  *\n");
}

void show_footer(){
	for(int i = 0; i < MAX_CYLINDERS; i++)
		printf("-----");
	printf("\n");
}
