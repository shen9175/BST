#include "bst.h"
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T> vector<T> RandVect(T a, T b);

template<typename T> void test1(BST_smart_pointer<T> testobj);
template<typename T> void test2(BST_smart_pointer<T> testobj);
int main()
{
	BST_smart_pointer<unsigned> d;//
	test1(d);
	cout<<"Now testing initilization list initialization and copy contructor:"<<endl;
	BST_smart_pointer<int> c{15,6,7,13,9,3,2,4,18,17,20,21};/*{802,187,395,674,668,609,573,865,448,654};*//*{2,4,5,7,0,6,8,3,9,1};*//*{690,753,820,335,456,441,377,169,591,671};*///{9,8,0,4,7,3,2,1,6,5};//{15,6,3,2,4,7,13,9,18,20,173};
	cout<<"Before pass"<<endl;
	cout<<"There are "<<c.size()<<" element(s) in the default initialization object."<<endl;
	cout<<"Tree Height:"<<c.GetTreeHeight()<<endl;
	cout<<"Tree Left Height:"<<c.GetTreeLeftHeight()<<endl;
	cout<<"Tree Right Height:"<<c.GetTreeRightHeight()<<endl;
	cout<<"Tree Level:"<<c.GetLevel()<<endl;
	cout<<"Tree Maxdigit:"<<c.GetMaxDigit()<<endl;
	cout<<endl;

	test2(c);

	return 0;
}


template<typename T> vector<T> RandVect(T a, T b)
{
	vector<T> random;

	for(unsigned i=a;i<=b;++i)
		random.push_back(i);
	shuffle(random.begin(),random.end(),default_random_engine(time(nullptr)));

	return random;
}
template<typename T> void test1(BST_smart_pointer<T> testobj)
{
	vector <vector<T>> random;
	random.push_back(RandVect(static_cast<T>(0),static_cast<T>(9)));
	random.push_back(RandVect(static_cast<T>(10),static_cast<T>(99)));
	random.push_back(RandVect(static_cast<T>(100),static_cast<T>(999)));
	random.push_back(RandVect(static_cast<T>(0),static_cast<T>(999)));
	vector<T> order=RandVect(static_cast<T>(0),static_cast<T>(9));
	try
	{
		cout<<"Now testing default initialization and copy contructor:"<<endl;
		cout<<"There are "<<testobj.size()<<" element(s) in the default initialization object."<<endl;
		cout<<"There are :";
		testobj.PrintTree();
		cout<<"Default initialiazation test passed!"<<endl<<endl;


	for(unsigned char j=0;j<4;++j)
	{
		cout<<"Now testing Insert() function:"<<endl;
		T temp;
		for(unsigned char i=0;i<10;++i)
			{
			temp=random[j][i];
			testobj.Insert(temp);
			cout<<"Generated random number: "<<temp<<". Put it into the BST."<<endl;
			cout<<"Now the Tree is:"<<endl;
			testobj.PrintTree();
			cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
			cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
			cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
			cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
			cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
			cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;
			}

		cout<<"Now testing the Pre Order Walking in the Tree."<<endl;
		testobj.PreOrder_Tree_Print();
		cout<<endl;

		cout<<"Now testing the In Order Walking in the Tree."<<endl;
		testobj.InOrder_Tree_Print();
		cout<<endl;
		cout<<"Now testing the Post Order Walking in the Tree."<<endl;
		testobj.PostOrder_Tree_Print();
		cout<<endl;


		cout<<"Now testing deletion functions:"<<endl;
		for(unsigned char i=0;i<10;++i)
			{
			temp=random[j][order[i]];
			testobj.Delete(temp);
			cout<<"Randome generated the number in BST to be deleted: "<<temp<<". Remove it from the BST."<<endl;
			cout<<"Now the Tree is:"<<endl;
			testobj.PrintTree();
			cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
			cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
			cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
			cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
			cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
			cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;
			}
		cout<<"Now deletion function has passed!"<<endl;

		cout<<"Now testing clear() function:"<<endl;
		testobj.clear();
		cout<<"clear() function testing passed!"<<endl;

	}
		
	}

	catch(runtime_error err)
		{
		cerr<<err.what()<<endl;
		}

}

template<typename T> void test2(BST_smart_pointer<T> testobj)
{
	try
	{
		cout<<"After pass"<<endl;
		cout<<"There are "<<testobj.size()<<" element(s) in the default initialization object."<<endl;
		cout<<"There are :"<<endl;
		testobj.PrintTree();
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;
		cout<<"Initialization list initialiazation and copy contructor test passed!"<<endl<<endl;

		cout<<"Now testing the Pre Order Walking in the Tree."<<endl;
		testobj.PreOrder_Tree_Print();
		cout<<endl;

		cout<<"Now testing the In Order Walking in the Tree."<<endl;
		testobj.InOrder_Tree_Print();
		cout<<endl;
		cout<<"Now testing the Post Order Walking in the Tree."<<endl;
		testobj.PostOrder_Tree_Print();
		cout<<endl;


		cout<<"Now testing delete the node has no left child."<<endl;
		testobj.Delete(static_cast<T>(21));
		cout<<endl;
		cout<<"21 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;


		cout<<"Now testing delete the node has no right child."<<endl;
		testobj.Delete(static_cast<T>(13));
		cout<<endl;
		cout<<"13 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;

		cout<<"Now delete 9"<<endl<<endl;
		testobj.Delete(static_cast<T>(9));
		cout<<endl;
		cout<<"9 is deleted"<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;

		cout<<"Now insert 13 again"<<endl;
		testobj.Insert(static_cast<T>(13));
		cout<<"13 is inserted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;		

		cout<<"Now insert 9 again"<<endl;
		testobj.Insert(static_cast<T>(9));
		cout<<"9 is inserted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;


		cout<<"Now delete 7"<<endl;
		testobj.Delete(static_cast<T>(7));
		cout<<"7 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;

		cout<<"Now delete 18"<<endl;
		testobj.Delete(static_cast<T>(18));
		cout<<"18 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;

		cout<<"Now insert 18 again"<<endl;
		testobj.Insert(static_cast<T>(18));
		cout<<"18 is inserted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;


		cout<<"Now delete 20"<<endl;
		testobj.Delete(static_cast<T>(20));
		cout<<"20 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;


		cout<<"Now testing clear() function:"<<endl;
		testobj.clear();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;
		cout<<"clear() function testing passed!"<<endl;


		cout<<"Now testing insert multiple elements:15,6,7,13,9,3,2,4,18,17,30,31,22,25,24,26,35"<<endl;
		testobj.Insert({15,6,7,13,9,3,2,4,18,17,30,31,22,25,24,26,35});
		cout<<"15,6,7,13,9,3,2,4,18,17,30,31,22,25,24,26,35 is inserted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;
		cout<<"Insert multiple elements testing passed!"<<endl;

		cout<<"Now testing delete the node has two children and its right child is not its sucessor:"<<endl;
		cout<<"Delete 18"<<endl;
		testobj.Delete(static_cast<T>(18));
		cout<<"18 is deleted."<<endl;
		cout<<"Now the tree is like this:"<<endl;
		testobj.PrintTree();
		cout<<"There are "<<testobj.size()<<" element(s) in the object."<<endl;
		cout<<"Tree Height:"<<testobj.GetTreeHeight()<<endl;
		cout<<"Tree Left Height:"<<testobj.GetTreeLeftHeight()<<endl;
		cout<<"Tree Right Height:"<<testobj.GetTreeRightHeight()<<endl;
		cout<<"Tree Level:"<<testobj.GetLevel()<<endl;
		cout<<"Tree Maxdigit:"<<testobj.GetMaxDigit()<<endl;



	}

	catch(runtime_error err)
		{
		cerr<<err.what()<<endl;
		}

}

