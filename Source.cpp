#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "HeaderX.h"

using namespace std;


int main ()
{
	ifstream inputtxt;                                          //we get filename
	string txtname;
	string line;


	cout << "Please enter a file name." <<endl;
	do
	{
		cin >> txtname;
		inputtxt.open(txtname);

	}while (!inputtxt.is_open());

	int t,q,r,s;
	getline(inputtxt,line);
	istringstream ss(line);	

	ss>>t>>q>>r>>s;
	Rectangle ext(t,q,r,s);
	TwoDimTree tree(ext);


	while (getline(inputtxt,line))
	{
		istringstream abc(line);	

		abc>>t>>q>>r>>s;

		if(t==-1||q==-1||r==-1||s==-1)break;  // if any of the rectangle point is equal to -1 we wexit the while loop and stop reading txt file

		Rectangle rec(t,q,r,s);
		tree.insert(rec);
	}
	int x,y;
	int j;
	int coun=0;
	
	while(cin>> x>> y)            //we get input from user
	{
		vector<Rectangle>Pointss;
		if(x!=-1 ||y!=-1)
		{
			int j=tree.findX(x,y,coun,Pointss);  // this function calculate the count and return count
			coun=0;
			cout << j <<endl;
			for(int s=0; s<Pointss.size(); s++)   
			{
				cout<< Pointss[s].GetTop()<< " " << Pointss[s].GetLeft() << " " <<Pointss[s].GetBottom()<< " "<<Pointss[s].GetRight() <<endl;
			}
		}
	}

	return 0;
}