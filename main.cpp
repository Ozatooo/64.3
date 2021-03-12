#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream plik;
    plik.open("dane_obrazki.txt", ios::in);

    int ile = 0;
    int dobry = 0;
    int poprawny = 0;
    int nienaprawialny = 0;
    int naprawialny = 0;
    int zlywiersz = 0;
    int zlakolumna = 0;

    while(!plik.eof()) {

        string obraz[21];

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
			  if(ile%2==0)
        	{
        		dobry=0;
			}
			else
			{
				dobry=1;
			}
			
			if(obraz[i][20]!=dobry)
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
				if(ile%2==0)
	        	{
	        		dobry=0;
				}
				else
				{
					dobry=1;
				}
				
				if(obraz[i][20]!=dobry)
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
    else if(zlakolumna<=1 || zlywiersz<=1)
    {
        naprawialny++;

    }
    else
    {
        poprawny++;

    }
			    
        zlakolumna=0;
        zlywiersz=0;

        
        	
        

    }
        cout<<"poprawnych"<<poprawny<<endl;
        cout<<"nie naprawialny"<<nienaprawialny<<endl;
        cout<<"naprawilanych"<<naprawialny;

    return 0;
}
