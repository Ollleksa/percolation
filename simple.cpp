#include <fstream>
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int N = 10;

class material
{
    private:
        int M[N][N];
        int coun;
    public:
        material()
        {
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    M[i][j] = 0;

            coun = 0;
        }

        void show();
        void iter();
        void unite(int value, int i, int j);
        int check();

        int res()
        {
            return coun;
        }
};

void material::show()
{
	ofstream myfile;
	char filename[256];
	sprintf(filename,"data/data%d.dat",coun);
	myfile.open(filename);
	for(int x = 0; x < N; x++)
	{
		for(int y = 0; y < N; y++)
                {
                    if(M[x][y] == 0)
                    {
                        myfile << 0 << "\t";
                    }
                    else
                    {
                        myfile << 1 << "\t";
                    }
                }
                myfile << "\n";
	}
        myfile.close();
}

void material::iter()
{
    int x, y;
    x = rand()%N;
    y = rand()%N;
    if(M[x][y] == 0)
    {
        M[x][y] = x*N + y + 1;

        if(y+1 < N)
            if(M[x][y+1] != 0)
                unite(M[x][y],x,y+1);

        if(x+1 < N)
            if(M[x+1][y] != 0)
                unite(M[x][y],x+1,y);

        if(y > 0)
            if(M[x][y-1] != 0)
                unite(M[x][y],x,y-1);

        if(x > 0)
            if(M[x-1][y] != 0)
                unite(M[x][y],x-1,y);

        coun++;
    }
}

void material::unite(int value, int i, int j)
{
    for(int k = 0; k < N; k++)
        for(int l = 0; l < N; l++)
        {
            if(M[k][l] == M[i][j])
            {
                M[k][l] = value;
            }
        }
}

int material::check()
{
    int ch = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(M[0][i] == M[N-1][j])
                if(M[0][i] > 0)
                    ch = 1;

    return ch;
}

int main()
{
    material one;
    int i = 0;

    srand (time(NULL));
    while(one.check() == 0 )
    //while(i < 100)
    {
        one.iter();
        cout << one.res() << endl;
        i++;
    }

    one.show();
    cout << "It take " << one.res() << " iterations" << endl;
    return 1;
}
