#ifndef _INT_DLL_NODE_H_
#define _INT_DLL_NODE_H_

class intDLLNode		//class for DLL nodes
{
	friend class intDLList;
	public:
		intDLLNode(int el=0, intDLLNode *n=nullptr, intDLLNode *p=nullptr) {		//constructor
			info = el;
			next = n;
			prev = p;
		}
	protected:
		int info;
		intDLLNode *next, *prev;

};

#endif // _INT_DLL_NODE_H_

