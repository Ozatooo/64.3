#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream plik;
    plik.open("dane_obrazki.txt", ios::in);

    int ile = 0;
    char dobry;
    int poprawny = 0;
    int nienaprawialny = 0;
    int naprawialny = 0;
    int zlywiersz = 0;
    int zlakolumna = 0;
    int error_k = 0;
    int error_w = 0;
    int max_errors = 0;

    while(!plik.eof()) {

        string obraz[21];
        zlakolumna=0;
        zlywiersz=0;
        error_k=0;
        error_w=0;

        for(int i=0;i<21;i++) {
            plik >> obraz[i];
            
        }

        for(int i=0;i<20;i++) {
            for(int j=0; j<20; j++)
            {
            if(obraz[i][j]=='1')
            {
            	ile++;
			}
			if(j==19)
			{
			  if(ile%2==1)
        	{
        		dobry='1';
			}
			else
			{
				dobry='0';
			}
			
			if(dobry!=obraz[i][20])
			{
				zlywiersz++;
			}
			ile=0;
			}
		}
    }
        
            for(int i=0;i<20;i++) {
            for(int j=0; j<20; j++)
            {
            if(obraz[j][i]=='1')
            {
            	ile++;
			}
			if(j==19)
			{
				if(ile%2==1)
	        	{
	        		dobry='1';
				}
				else
				{
					dobry='0';
				}
				
				if(obraz[20][i]!=dobry)
				{
					zlakolumna++;
				}
				ile=0;
			}
		}
        }
        

    if(zlakolumna>1 || zlywiersz>1)
    {
        nienaprawialny++;

    }
    else if(zlakolumna>0 || zlywiersz>0)
    {
        naprawialny++;

    }
    else if(zlakolumna==0 || zlywiersz==0)
    {
        poprawny++;

    }
    
    
            for(int i=0;i<20;i++) {
            for(int j=0; j<20; j++)
            {
            if(obraz[i][j]=='1')
            {
            	ile++;
			}
			if(j==19)
			{
			  if(ile%2==1)
        	{
        		dobry='1';
			}
			else
			{
				dobry='0';
			}
			
			if(dobry!=obraz[i][20])
			{
				error_w++;
			}
			ile=0;
			}
		}
    }
        
            for(int i=0;i<20;i++) {
            for(int j=0; j<20; j++)
            {
            if(obraz[j][i]=='1')
            {
            	ile++;
			}
			if(j==19)
			{
				if(ile%2==1)
	        	{
	        		dobry='1';
				}
				else
				{
					dobry='0';
				}
				
				if(obraz[20][i]!=dobry)
				{
					error_k++;
				}
				ile=0;
			}
		}
        }
        if(max_errors<error_k+error_w)
        {
        	max_errors=error_k+error_w;
		}
		
        
			

    }
        cout<<"poprawnych "<<poprawny<<endl;
        cout<<"nie naprawialny "<<nienaprawialny<<endl;
        cout<<"naprawilanych "<<naprawialny<<endl;
        cout<<"maks bledow "<<max_errors;

    return 0;
}
