#include<iostream>
#include<queue>
using namespace std;

typedef struct matx{
	int x;
	int y;
}maze;

int main(void)
{
	maze Maze;
	int state =0;
	int n,m;
	cin >> n;
	cin >> m;
	int matrix[n][m];
	int flag[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			flag[i][j]=0;
        for(int i=0;i<n;i++)
	   for(int j=0;j<m;j++)
	     cin >> matrix[i][j];
	queue<maze> datastructure;
	Maze.x = 0;
	Maze.y = 0;
	datastructure.push(Maze);
	while(datastructure.size() > 0)
	{
		maze output = datastructure.front();
		flag[output.x][output.y] = 1;
		datastructure.pop();
		if(output.x == n-1 && output.y == m-1)
		{
			state = 1;
			break;
		}
		if(output.y -1 >= 0&& flag[output.x][output.y-1] != 1)
		{
			if(matrix[output.x][output.y -1] != 0)
			{
			    Maze.x = output.x;
			    Maze.y = output.y-1;
			    datastructure.push(Maze);
			} 
		}
		if(output.y + 1 < m && flag[output.x][output.y+1] != 1)
		{
			if(matrix[output.x][output.y+1] != 0)
			{
		            Maze.x = output.x;
	    		    Maze.y = output.y+1;		    
			    datastructure.push(Maze);
			}
		}
		if(output.x -1 >= 0 && flag[output.x-1][output.y] != 1)
		{
			if(matrix[output.x-1][output.y] != 0)
			{
				Maze.x = output.x-1;
				Maze.y = output.y;
				datastructure.push(Maze);
			}
		}
		if( output.x + 1 < n && flag[output.x+1][output.y] != 1)
		{
			if(matrix[output.x+1][output.y] != 0)
			{
				Maze.x = output.x+1;
				Maze.y = output.y;
				datastructure.push(Maze);
			}
		}
		if(output.y -1 >= 0 &&  output.x -1 >=0 && flag[output.x-1][output.y-1] != 1)
		{
			if(matrix[output.x-1][output.y -1] != 0)
			{
				Maze.x = output.x-1;
				Maze.y = output.y-1;
				datastructure.push(Maze);
			} 
		}
		if(output.y+1 < m && output.x+1 < n  && flag[output.x+1][output.y+1] != 1)
		{
			if(matrix[output.x+1][output.y+1] != 0)
			{
				Maze.x = output.x+1;
				Maze.y = output.y+1;
				datastructure.push(Maze);
			}
		}
		if(output.y + 1 < m && output.x -1 >=0 && flag[output.x-1][output.y+1] != 1)
		{
			if(matrix[output.x-1][output.y +1] != 0)
			{
				Maze.x = output.x-1;
				Maze.y = output.y+1;
				datastructure.push(Maze);
			}
		}
		if(output.x+1 < n && output.y-1 >=0  && flag[output.x+1][output.y-1] != 1)
		{
			if(matrix[output.x+1][output.y-1] != 0)
			{
				Maze.x = output.x+1;
				Maze.y = output.y-1;
			 	datastructure.push(Maze);
			}
		}
	}
	if(state == 1) cout << "Path Exists" << endl;
	else cout << "Path not exists" << endl;
}
