#include <iostream>
#include <vector>

using namespace std;

class Rectangle 
	{

	public: 
		Rectangle(int a,int b,int c,int d);
		Rectangle();
		int GetRight();
		int GetLeft();
		int GetTop();
		int GetBottom();
		int area();

	private: 
	
		int Top; // y coordinate of the upper edge 
		int Left; // x coordinate of the left edge 
		int Bottom; // y coordinate of the bottom edge 
    	int Right; // x coordinate of the right edge .... 
	};

//*********************************************************
	class TwoDimTreeNode
	{
	public: 
		TwoDimTreeNode(Rectangle R);
		TwoDimTreeNode();
		//~TwoDimTreeNode();
		Rectangle Extent;
	    
		
		void CreateBottomRight(int t, int l, int b, int r);
		void CreateTopRight(int t, int l, int b, int r);
		void CreateBottomLeft(int t, int l, int b, int r);
		void CreateTopLeft(int t, int l, int b, int r);
		
		friend class TwoDimTree;
	private: 
		
		
		vector<Rectangle> Vertical, Horizontal;
		
		TwoDimTreeNode *TopLeft, *TopRight, *BottomLeft, *BottomRight; 
	};

//********************************************************
	class TwoDimTree
	{
	public:
		
		TwoDimTree(){
		root=nullptr;
		}

		
		TwoDimTree(Rectangle &r);
		void insert(Rectangle &x );
		int findX(int x,int y, int &c,vector<Rectangle>&point);
		
		friend class Rectangle;
	private:
		TwoDimTreeNode *root;
		
		void insert( Rectangle  x, TwoDimTreeNode *& t ) ;
		int find( int x, int y, TwoDimTreeNode*&t,int &c, vector<Rectangle>&Point);


	};

	
