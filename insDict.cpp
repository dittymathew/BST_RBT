#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;
double GetRand(int min, int max);

int main()
{
	int i,val,temp;
	int a[500000];
	double rand_max=1.00;
	double r;
	r = rand() /(double)RAND_MAX;
	cout<<r<<"\n";
//	r = rand() /1.00;
/*	r = rand() /10.00;
	ofstream out ("dict20K.txt");
	for(i=0;i<500000;i++){
		for (int j=0;j<=i;j++){
			temp =GetRand(0,500000);
			if(a[j]!=temp)
				break;
		}
		val =temp;
	out << val<<"\n";
	}
	ofstream out1 ("loc5000.txt");
	for(i=0;i<500;i++){
	out1 << GetRand(0,500)<<"\n";
	}*/
}
double GetRand(int min, int max)

{
  static int Init = 0;
  double rc;
  if (Init == 0)
  {
    srand(time(NULL));

    Init = 1;
  }
  rc = (rand() % (max - min + 1) + min);
 

  return (rc);

}
