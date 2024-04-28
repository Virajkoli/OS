//C program for Banker's Algorithm 
#include <stdio.h> 
int main() 
{ 
	
	int n, r, i, j, k; 
	n = 5; //Number of processes 
	r = 6; //Number of resources 
	int alloc[5][6] = {{0 , 1 , 1 , 1 , 0 , 0},
  {2 , 0 , 0 , 0 , 1 , 0},
  {3 , 0 , 2 , 0 , 0 , 2},
  {2 , 1 , 1 , 0 , 0 , 1},
  {0 , 0 , 2 , 1 , 1 , 0}}; // P4 

	int max[5][6] = { {7 , 5 , 3 , 3 , 4 , 5},
  {3 , 2 , 2 , 2 , 3 , 3},
  {9 , 0 , 2 , 3 , 2 , 2},
  {2 , 2 , 2 , 2 , 2 , 2},
  {4 , 3 , 3 , 3 , 3 , 3}}; // P4 

	int avail[6] = {  3 , 3 , 2 , 2 , 6 , 5 }; // These are Available Resources 

	int f[n], ans[n], ind = 0; //To store record of executed processes 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][r]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) {   //Checks if remaining need will be fulfilled with available resources or not
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("For allocation matrix : ");
	for(int i=0; i<n; i++){
		printf("\n");
		for(int j=0; j<r; j++){
			printf("%d\t",alloc[i][j]);
		}
	}
		printf("\n\nAnd for MAX need matrix : ");
	for(int i=0; i<n; i++){
		printf("\n");
		for(int j=0; j<r; j++){
			printf("%d\t",max[i][j]);
		}
	}
	printf("\n\nAvailable resources : \t");
	for(int i=0; i<r; i++){
		printf("%d\t",avail[i]);
	}

	printf("\nThe SAFE Sequence is as follows : \n"); 
	for (i = 0; i < n -1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n-1]); 

	return (0); 

}