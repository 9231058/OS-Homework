// In The Name Of God
// ========================================
// * File Name : hdd.h
// 
// * Creation Date : 12-12-2014
//
// * Last Modified : Sat 13 Dec 2014 12:21:07 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#define MAX_CYLINDERS 10

void set_head(int position);

// Please remeber use set_head before using the following algorithm

int fcfs(int req[], int n);

int sstf(int req[], int n);

int c_scan(int req[], int n);
