#include <iostream>
#include <vector>
#include "HeaderX.h"

Rectangle::Rectangle (int t,int l,int b,int r)
{
	Top=t;
	Left=l;
	Bottom=b;
	Right=r;

}
Rectangle::Rectangle()
{
	Top=0;
	Left=0;
	Bottom=0;
	Right=0;
}



int Rectangle::GetRight()
{
	return Right;
}

int Rectangle::GetLeft()
{
	return Left;
}

int Rectangle::GetBottom()
{
	return Bottom;
}

int Rectangle::GetTop()
{
	return Top;
}


int Rectangle:: area()
{
	return (Bottom-Top)*(Right-Left);
}


void TwoDimTree::insert( Rectangle & x ) 

{
	insert(x, root);
}

TwoDimTreeNode::TwoDimTreeNode(Rectangle R)
{
		Extent=R;
		TopLeft=NULL;
		TopRight=NULL;
		BottomLeft=NULL;
		BottomRight=NULL;

}

TwoDimTreeNode::TwoDimTreeNode()
{
}



void TwoDimTreeNode::CreateBottomRight(int t, int l, int b, int r)
{
	BottomRight= new TwoDimTreeNode(Rectangle(t,l,b,r)) ;
}

void TwoDimTreeNode::CreateTopRight(int t, int l, int b, int r)
{
	TopRight= new TwoDimTreeNode(Rectangle(t,l,b,r)) ;
	
}

void TwoDimTreeNode::CreateBottomLeft(int t, int l, int b, int r)
{
	BottomLeft= new TwoDimTreeNode(Rectangle(t,l,b,r)) ;
}
void TwoDimTreeNode::CreateTopLeft(int t, int l, int b, int r)
{
	TopLeft= new TwoDimTreeNode(Rectangle(t,l,b,r)) ;
}

TwoDimTree::TwoDimTree(Rectangle &r)
{
	root= new TwoDimTreeNode(r);
}



void TwoDimTree::insert( Rectangle  x, TwoDimTreeNode * &t )     // in this function we create our nodes and we push our rectangles to our vectors
{
	int centx= (t->Extent.GetRight() + t->Extent.GetLeft()) /2 ; // t->Extent.Right + left /2 
	int centxy= (t->Extent.GetTop() +t->Extent.GetBottom())/2 ; // t->extent.top + bottom /2 
	if(x.GetLeft() <= centx && centx<= x.GetRight()) // t.left <=centx <= t.right     //****????
	{
		t->Vertical.push_back(x); //burda kaldýnnnnnnnnn
	}
	else if(x.GetTop()<=centxy && centxy<=x.GetBottom()) // t.top <=centx <= t.bottom
	{
		t->Horizontal.push_back(x);
	}
	else{
		int recx = x.GetLeft()+ x.GetRight()/2;// x.left + right /2
		int recy = x.GetTop()+x.GetBottom()/2;// x.top + bottom /2

		if(recx > centx && recy > centxy)//
		{
			if(t->BottomRight==NULL){ //t->bottomright==Null
				t->CreateBottomRight(centxy, centx, t->Extent.GetBottom(), t->Extent.GetRight());/*t->bOTTOMRG = new TwoDimTreeNode(...extent...);*/
			}
			/*TwoDimTreeNode* j=t->GetBottomRight();*/
			insert(x, t->BottomRight); //insert(x, t->bottomright);
		} 

		else if(recx >centx && recy <centxy)
		{
			if(t->TopRight ==NULL){ //t->bottomright==Null
				t->CreateTopRight(t->Extent.GetTop(), centx, centxy, t->Extent.GetRight());/*t->TopRight = new TwoDimTreeNode(...extent...);*/
			}
			insert(x, t->TopRight); //insert(x, t->Topright);
		}

		else if (recx < centx && recy > centxy)//
		{
			if(t->BottomLeft==NULL){ //t->bottomright==Null
				t->CreateBottomLeft(centxy, t->Extent.GetLeft(),t->Extent.GetBottom(), centx);/*t->bOTTOMRG = new TwoDimTreeNode(...extent...);*/
			}
			/*TwoDimTreeNode* j=t->GetBottomRight();*/
			insert(x, t->BottomLeft); //insert(x, t->bottomright);
		} 

		else
		{
			if(t->TopLeft==NULL){ //t->bottomright==Null
				t->CreateTopLeft(t->Extent.GetTop(), t->Extent.GetLeft(),centxy, centx);/*t->bOTTOMRG = new TwoDimTreeNode(...extent...);*/
			}
			/*TwoDimTreeNode* j=t->GetBottomRight();*/
			insert(x, t->TopLeft); //insert(x, t->bottomright);
		}
	}
}


int TwoDimTree::find(int x, int y, TwoDimTreeNode *&t, int &c,vector<Rectangle>&Point)
{
	// in this function we find the count of the rectangles on that point
	
	if (t==NULL)
	{
		return c;
	}


	int centx=(t->Extent.GetRight() + t->Extent.GetLeft() )/2 ; 
	int centxy= (t->Extent.GetTop() +t->Extent.GetBottom())/2 ; 
	
	
	for (unsigned int i =0; i<t->Vertical.size(); i++)
	{
		
		if(y >= t->Vertical[i].GetLeft() && y <=t->Vertical[i].GetRight() && x> t->Vertical[i].GetTop() && x<= t->Vertical[i].GetBottom())
		{
			
			c++;
			Point.push_back(t->Vertical[i]);  // we storage our rectangles top left bottom right points.
			
		
			
		}
	}

	for (unsigned int i =0; i<t->Horizontal.size(); i++)
	{
	 if (y>= t->Horizontal[i].GetLeft() && y <=t->Horizontal[i].GetRight() && x> t->Horizontal[i].GetTop() && x<= t->Horizontal[i].GetBottom())
		{
			c++;
			Point.push_back(t->Horizontal[i]); //we storage our rectangles top left bottom right points
		}
		
	}
		
		    
		if(x > centx && y>centxy)
		{
			find(x,y,t->BottomRight,c,Point);
		}
		else if(x > centx && y<centxy)
		{
			find(x,y,t->TopRight,c,Point);
		}
		else if( x< centx && y>centxy)
		{
			find(x,y,t->BottomLeft,c,Point);
		}
		else 
		{
			find(x,y,t->TopLeft,c,Point);
		}

	return c;
}


int TwoDimTree::findX(int x, int y,int &c,vector<Rectangle>&point)
{
	return find(x,y,root,c,point); // countu mainde 0 a eþitle ve findýn yanýnda gönder.
}


