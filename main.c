#include <stdio.h>
#include <stdlib.h>

void mass(int** arr, int m, int n);
int movee(int** arr, int i, int j);

int *path;

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);

	int** arr;
	arr = (int**)malloc(sizeof(int*) * m);

	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	mass(arr, m, n);

    path= (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++) {
		path[i] = 0;
	}

    int res = 0;
    i = m - 1;
    j = n - 1;
    res = movee(arr, i, j);


	for (i = 0; i < 10; i++) {
		printf("%c ", path[i]);
	}
	printf("\n");
	
	free(path);

	for (i = 0; i < m; i++)
	{
		free(arr[i]);
	}
	free(arr);

	printf("%d", res);
	return 0;

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void mass(int** arr, int m, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < m; i++)

	{
		for (j = 0; j < n; j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int movee (int** arr, int i, int j)
{
    int a, b;
    
    if( i == 0 && j == 0)
    {
        return 1;
    }

    if( ( i < 0) || ( j < 0 ) )
    {
        return 0;
    }

    if( arr[i][j] == 1 )
    {
        return 0;
    }
    
    a= movee(arr, i-1, j);
    b= movee(arr, i, j-1);
    
    if ((a==0) && (b==0)){
        return 0;
    }
    if (a==0){
        path[b]='r';
        return b+1;
    }
    if (b==0){
        path[a]='b';
        return a+1;
    }
    if (a<b){
        path[a]='b';
        return a+1;
    }
    else {
        path[b]='r';
        return b+1;
    }
}
