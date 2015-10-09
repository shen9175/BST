#ifndef BST_H
#define BST_H

#include<stdexcept>
#include<memory>
#include<iostream>
#include<initializer_list>
#include<cmath>
#include<queue>
#include<iomanip>

template <typename T> class BST_smart_pointer
{
	private:
		struct node;
	public:
		using nodeptr=std::shared_ptr<node>;
		using size_type=std::size_t;
	private:
		struct node
		{
			nodeptr left;
			nodeptr right;
			nodeptr parent;
			T key;
		};
		nodeptr root;
		size_type tree_height,left_height,right_height,n_nodes,level,maxdigits;

		void InOrder_Tree_Print(nodeptr p);
		void PreOrder_Tree_Print(nodeptr p);
		void PostOrder_Tree_Print(nodeptr p);
		nodeptr Recursive_Search(nodeptr p, T x);
		nodeptr Iterative_Search(nodeptr p, T x);
		nodeptr Tree_Minimum(nodeptr p);
		nodeptr Tree_Maximum(nodeptr p);	
		void Insert(nodeptr p, T x);
		void Delete(nodeptr p);
		void DeleteTree(nodeptr p);
		void Transplant(nodeptr u, nodeptr v);
		size_type Tree_height(nodeptr p);
		void Left_height(nodeptr p);
		void Right_height(nodeptr p);
		void PrintTree(nodeptr p);
		unsigned int Maxdigit(nodeptr p);
		void Find_MaxDigit(nodeptr p);

		int roundint(double a){if(a-static_cast<int>(a)>=0.5) return (static_cast<int>(a)+1); else return static_cast<int>(a);};
	public:
		BST_smart_pointer(){tree_height=0;left_height=0;right_height=0;n_nodes=0;level=0;maxdigits=0;root=nullptr;}
		BST_smart_pointer(const BST_smart_pointer&)=default;
		BST_smart_pointer& operator=(const BST_smart_pointer&)=default;
		BST_smart_pointer(T x);
		BST_smart_pointer(std::initializer_list<T> il);
		//BST_smart_pointer(T x,...il);
		~BST_smart_pointer();
		void InOrder_Tree_Print(){InOrder_Tree_Print(root);}
		void PreOrder_Tree_Print(){PreOrder_Tree_Print(root);}
		void PostOrder_Tree_Print(){PostOrder_Tree_Print(root);}
		nodeptr Recursive_Search(T x){return Recursive_Search(root,x);}
		nodeptr Iterative_Search(T x){return Iterative_Search(root,x);}
		nodeptr Tree_Minimum(){return Tree_Minimum(root);}
		nodeptr Tree_Maximum(){return Tree_Maximum(root);}
		nodeptr Tree_Successor(nodeptr p);
		nodeptr Tree_Predecessor(nodeptr p);
		void Insert(T x){Insert(root,x);}
		void Insert(std::initializer_list<T> il);
		//void Insert(T x, ...il);
		void Delete(T x){Delete(Iterative_Search(x));}
		void Delete(std::initializer_list<T> il);
		//void Delete(T x,...il);
		void DeleteTree(){DeleteTree(root);}
		size_type Tree_height(){return Tree_height(root);}
		size_type Left_height(){left_height=0;level=0;Left_height(root);return left_height;}
		size_type Right_height(){right_height=0;level=0;Right_height(root);return right_height;}
		void PrintTree(){PrintTree(root);}
		size_type size()const{return n_nodes;}
		void clear(){DeleteTree(root);tree_height=0;left_height=0;right_height=0;/*n_nodes=0;*/level=0;maxdigits=0;}
		size_type GetTreeHeight(){return tree_height=Tree_height();}
		size_type GetTreeLeftHeight(){return left_height=Left_height();}
		size_type GetTreeRightHeight(){return right_height=Right_height();}
		size_type GetLevel()const{return level;}
		size_type GetMaxDigit()const{return maxdigits;}
};


template <typename T> BST_smart_pointer<T>::BST_smart_pointer(T x)
{
	tree_height=0;left_height=0;right_height=0;n_nodes=0;level=0;maxdigits=0;
	Insert(x);
}

template <typename T> BST_smart_pointer<T>::BST_smart_pointer(std::initializer_list<T> il)
{
	tree_height=0;left_height=0;right_height=0;n_nodes=0;level=0;maxdigits=0;
	for(auto beg=il.begin();beg!=il.end();++beg)
		Insert(*beg);
}
/*
template <typename T> BST_smart_pointer<T>::BST_smart_pointer(T x,...il)
{
	Insert(x);
	auto n=sizeof...(il);
	va_list il;
	va_start(il,x);
	for(auto i=0;i<n;++i)
		Insert(va_arg(il,T));
	va_end(il);
}*/

template <typename T> void BST_smart_pointer<T>::InOrder_Tree_Print(nodeptr p)
{
	if(p!=nullptr)
	{
		InOrder_Tree_Print(p->left);
		std::cout<<p->key<<" ";
		InOrder_Tree_Print(p->right);
	}
}

template <typename T> void BST_smart_pointer<T>::PreOrder_Tree_Print(nodeptr p)
{
	if(p!=nullptr)
	{
		std::cout<<p->key<<" ";
		PreOrder_Tree_Print(p->left);
		PreOrder_Tree_Print(p->right);
	}

}

template <typename T> void BST_smart_pointer<T>::PostOrder_Tree_Print(nodeptr p)
{
	if(p!=nullptr)
	{
		PostOrder_Tree_Print(p->left);
		PostOrder_Tree_Print(p->right);
		std::cout<<p->key<<" ";
	}
}

template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Recursive_Search(nodeptr p, T x)
{
	if(p==nullptr||p->key==x)
		return p;
	if(x<p->key)
		return Recursive_Search(p->left);
	else
		return Recursive_Search(p->right);
}

template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Iterative_Search(nodeptr p, T x)
{
	while(p!=nullptr&&p->key!=x)
	{
		if(x<p->key)
			p=p->left;
		else
			p=p->right;
	}
	return p;
}

template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Tree_Minimum(nodeptr p)
{
	while(p->left!=nullptr)
		p=p->left;
	return p;

	/*recursive version

	if(p->left!=nullptr)
		return Tree_Minimum(p->left);
	else
		return p;
	*/
}

template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Tree_Maximum(nodeptr p)
{
	while(p->right!=nullptr)
		p=p->right;
	return p;
	/*recursive version

	if(p->right!=nullptr)
		return Tree_Minimum(p->right);
	else
		return p;
	*/
}

template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Tree_Successor(nodeptr p)
{
	if(p->right!=nullptr)
		return Tree_Minimum(p->right);
	
	nodeptr y=p->parent;
	while(y!=nullptr && y->right==p)//check y->left!=p
	{
		p=p->parent;//p=y;
		y=p->parent;//y=y->parent;
	}
	return y;
}
template <typename T> typename BST_smart_pointer<T>::nodeptr BST_smart_pointer<T>::Tree_Predecessor(nodeptr p)
{
	if(p->left!=nullptr)
		return Tree_Maximun(p->left);

	nodeptr y=p->parent;
	while(y!=nullptr && y->left==p)
	{
		p=y;
		y=y->parent;
	}
	return y;
}

template <typename T> void BST_smart_pointer<T>::Insert(nodeptr p, T x)
{
	nodeptr y=nullptr;//temp parent node
	while (p!=nullptr)
	{
		y=p;//keep the original p before p become p->next
		if(x<p->key)
			p=p->left;
		else
			p=p->right;
	}

	nodeptr n=std::make_shared<node>();
	n->left=nullptr;
	n->right=nullptr;
	n->parent=y;
	n->key=x;

	if(y==nullptr)//tree is empty
		root=n;
	else if(n->key<y->key)
		y->left=n;
	else
		y->right=n;
	
	++n_nodes;
}

template <typename T> void BST_smart_pointer<T>::Insert(std::initializer_list<T> il)
{
	for(auto beg=il.begin();beg!=il.end();++beg)
		Insert(*beg);
}
/*
template <typename T> BST_smart_pointer<T>::Insert(T x, ...il)
{
	Insert(x);
	auto n=sizeof...(il);
	va_list il;
	va_start(il,x);
	for(auto i=0;i<n;++i)
		Insert(va_arg(il,T));
	va_end(il);
}
*/
template <typename T> void BST_smart_pointer<T>::Transplant(nodeptr u, nodeptr v)
{
	if(u->parent==nullptr)//u is the root of the tree
		root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else u->parent->right=v;

	if(v!=nullptr)
		v->parent=u->parent;
}

template <typename T> void BST_smart_pointer<T>::Delete(nodeptr p)
{
	if(p!=nullptr)
	{
		if(p->left==nullptr)
			{
			Transplant(p,p->right);
			p->parent=nullptr;
			p->right=nullptr;
			p->left=nullptr;
			p->key=0;
			}
		else if(p->right==nullptr)
			{
			Transplant(p,p->left);
			p->parent=nullptr;
			p->right=nullptr;
			p->left=nullptr;
			p->key=0;
			}
		else
		{
			nodeptr y=Tree_Minimum(p->right);//find the successor of p (since p has right child, it's tree-minimum(p->right))
			if(y->parent!=p)//p's sucessor is not p's right child
			{
				Transplant(y,y->right);
				y->right=p->right;
				y->right->parent=y;
			}
			Transplant(p,y);
			y->left=p->left;
			y->left->parent=y;

			p->parent=nullptr;
			p->right=nullptr;
			p->left=nullptr;
			p->key=0;
		}
		--n_nodes;
	}
	else
		throw std::runtime_error("There is no such node to delete!");
}

template <typename T> void BST_smart_pointer<T>::Delete(std::initializer_list<T> il)
{
	for(auto beg=il.begin();beg!=il.end();++beg)
		Delete(*beg);
}
/*
template <typename T> void BST_smart_pointer<T>::Delete(T ...il)
{
	auto n=sizeof...(il);
	va_list il;
	va_start(,il);
	for(auto i=0;i<n;++i)
		Delete(va_arg(il,T));
	va_end(il);
}*/

template <typename T> typename BST_smart_pointer<T>::size_type BST_smart_pointer<T>::Tree_height(nodeptr p)
{
	if(p==nullptr)
	{
		return 0;
	}

	size_type left=Tree_height(p->left);
	size_type right=Tree_height(p->right);

	if(left>right)
		return left+1;
	else
		return right+1;
}

template <typename T> void BST_smart_pointer<T>::Left_height(nodeptr p)
{
	if(p!=nullptr)
	{
		++level;


		if(p->left==nullptr && p->right==nullptr && p->parent!=nullptr && p->parent->left==p)
		{
			if(level>left_height)
				left_height=level;
			--level;
			return;
		}
		else
		{
		Left_height(p->left);
		Left_height(p->right);
		--level;
		return;
		}
	}
	else
		return;
}

template <typename T> void BST_smart_pointer<T>::Right_height(nodeptr p)
{
	if(p!=nullptr)
	{
		++level;
		if(p->right==nullptr && p->left==nullptr && p->parent!=nullptr &&  p->parent->right==p)
		{
			if(level>right_height)
				right_height=level;
			--level;
			return;
		}
		else
		{
		Right_height(p->right);
		Right_height(p->left);
		--level;
		return;
		}
	}
	else
		return;
}
template <typename T> void BST_smart_pointer<T>::DeleteTree(nodeptr p)
{
	if(p!=nullptr)
	{
		DeleteTree(p->left);
		DeleteTree(p->right);
		Delete(p);
		//std::cout<<n_nodes<<std::endl;
		//--n_nodes;
	}	
}
template <typename T> BST_smart_pointer<T>::~BST_smart_pointer()
{
	DeleteTree(root);
}

template <typename T> unsigned int BST_smart_pointer<T>::Maxdigit(nodeptr p)
{
	maxdigits=0;
	Find_MaxDigit(p);
	return maxdigits;
	
}

template <typename T> void BST_smart_pointer<T>::Find_MaxDigit(nodeptr p)
{
	if(p!=nullptr)
	{
		if(std::to_string(p->key).size()>maxdigits)
			maxdigits=std::to_string(p->key).size();
		Find_MaxDigit(p->left);
		Find_MaxDigit(p->right);
	}
}
template <typename T> void BST_smart_pointer<T>::PrintTree(nodeptr p)
{
	unsigned int height=Tree_height(p);
	unsigned int d=Maxdigit(p);

	//in level n: there are 2^(n-1) nodes, each node has at most d digits(length),total nodes length 2^(n-1)*d
	//in the loweset level n=height, if we leave 1 space between each node in the lowest level, then
	//the lowest level length is nodes length + spaces length
	//there 2^(n-1)-1,n=height spaces in the lowest level
	//so total lowest level length=2^(height-1)*d+2^(height-1)-1=2^(height-1)(d+1)-1

	unsigned int position=(pow(2,height-1)*(d+1));

	std::queue <nodeptr> q1,q2;
	q1.push(p);

	//print first to last-1 row of tree//
	for(unsigned int i=1;i<height;++i)
	{
		bool firsttime=true;
		while(q1.size()!=0)
		{
			nodeptr temp=q1.front();
			q1.pop();
			if(temp==nullptr)
			{
			q2.push(nullptr);
			q2.push(nullptr);
			}
			else
			{
			q2.push(temp->left);
			q2.push(temp->right);
			}
			unsigned int pos=position/pow(2,i);
			if(firsttime)
			{
			if(temp==nullptr)
				std::cout<</*std::setfill('$')<<*/std::setw(pos-roundint(d/2.0)+d)<<" ";
			else
				std::cout<</*std::setfill('$')<<*/std::setw(pos-roundint(d/2.0)+d)<<temp->key;
			firsttime=false;
			}
			else
			{
			if(temp==nullptr)
				std::cout<<std::setw(2*pos)<<" ";
			else
				std::cout<<std::setw(2*pos)<<temp->key;
			}
		}
		std::cout<<std::endl;
		q1.swap(q2);
	}

	//print last row of tree
	while(q1.size()!=0)
	{
	nodeptr temp=q1.front();
	q1.pop();
	if(temp==nullptr)
		std::cout<<std::setw(d)<<" "<<std::setw(1)<<" ";
	else
		std::cout<<std::setw(d)<<temp->key<<std::setw(1)<<" ";
	}
	//std::cout<<std::endl;
	//std::cout<<std::setw(5)<<" "<<std::endl;
	//std::cout<<std::setw(5)<<rint(d/2.0)<<std::endl;
	std::cout<<std::setfill(' ')<<std::endl;

}


#endif
