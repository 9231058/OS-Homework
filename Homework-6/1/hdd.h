// In The Name Of God
// ========================================
// * File Name : hdd.h
// 
// * Creation Date : 12-12-2014
//
// * Last Modified : Sat 13 Dec 2014 03:05:45 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#define MAX_CYLINDERS 10
#define SHOW		// Comment it if you don't want showing feature

void set_head(int position);

// Please remeber use set_head before using the following algorithm

int fcfs(int req[], int n);

int sstf(int req[], int n);

int scan(int req[], int n);

int c_scan(int req[], int n);

int look(int req[], int n);

int c_look(int req[], int n);
