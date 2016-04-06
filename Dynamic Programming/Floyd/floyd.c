/*Input : Size(n) of the n X n weighted directed graph followed by the graph
Output : n X n matrix where i,j the element corresponds to the minimum distance between point i and j*/
#include<stdio.h>
#include<stdlib.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
int main() {
	int n,k,j,i;
	scanf("%d",&n);
	int **R;
	R = malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		R[i]=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&R[i][j]);
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				R[i][j]=MIN(R[i][j],R[i][k]+R[k][j]);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)
			printf("%d ",R[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
		free(R[i]);
	free(R);
}
