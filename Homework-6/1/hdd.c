// In The Name Of God
// ========================================
// * File Name : hdd.c
// 
// * Creation Date : 12-12-2014
//
// * Last Modified : Sat 13 Dec 2014 12:33:00 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdlib.h>
#include <memory.h>
#include "hdd.h"

static int head;

void set_head(int position){
	head = position;
}

int fcfs(int req[], int n){
	int index = 0;
	int seek = 0;
	while(index != n){
		seek += abs(head - req[index]);
		head = req[index];
		index++;
	}
	return seek;
}

int sstf(int req[], int n){
	int seek = 0;
	int done = 0;
	int single_done[n];
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		int min = MAX_CYLINDERS;
		int min_index = -1;
		for(int i = 0; i < n; i++){
			if(!single_done[i] && min > abs(head - req[i])){
				min = abs(head - req[i]);
				min_index = i;
			}
		}
		seek += abs(head - req[min_index]);
		head = req[min_index];
		done++;
		single_done[min_index] = 1;
	}
	return seek;
}

int c_scan(int req[], int n){
	int seek = 0;
	int done = 0;
	int single_done[n];
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		for(int i = 0; i < n; i++){
			if((!single_done[i]) && req[i] == head){
				single_done[i] = 1;
				done++;
			}
		}
		seek++;
		head = (head + 1) % (MAX_CYLINDERS);
	}
	return seek;
}
