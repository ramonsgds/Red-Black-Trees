#include <iostream>
#include "redblackt.h"

using namespace std;

int main(){
	
 	RedBlackTree<int,double> mytree;
 	mytree.insert(pair<int,double>(20, 1.5));
 	mytree.insert(pair<int,double>(10, 2.5));
 	mytree.insert(pair<int,double>(30, 3.5));
 	mytree.insert(pair<int,double>(31, 4.5));
 	mytree.insert(pair<int,double>(50, 4.5));
 	mytree.insert(pair<int,double>(45, 5.5));
	mytree.insert(pair<int,double>(40, 6.5));
	mytree.insert(pair<int,double>(60, 7.5));
	mytree.insert(pair<int,double>(70, 8.5));
	mytree.insert(pair<int,double>(80, 8.5));
	mytree.insert(pair<int,double>(2, 8.5));
	mytree.insert(pair<int,double>(94, 8.5));
	mytree.insert(pair<int,double>(110, 8.5));
	mytree.insert(pair<int,double>(33, 8.5));
	mytree.insert(pair<int,double>(21, 8.5));
	mytree.insert(pair<int,double>(7, 8.5));
	mytree.insert(pair<int,double>(47, 8.5));
	mytree.insert(pair<int,double>(97, 8.5));
	mytree.insert(pair<int,double>(36, 8.5));
	mytree.insert(pair<int,double>(79, 8.5));
	mytree.insert(pair<int,double>(84, 8.5));
	mytree.insert(pair<int,double>(5, 8.5));
	mytree.insert(pair<int,double>(9, 8.5));
	mytree.insert(pair<int,double>(1, 8.5));
	mytree.insert(pair<int,double>(3, 8.5));
	mytree.insert(pair<int,double>(14, 8.5));
	mytree.insert(pair<int,double>(17, 8.5));
	mytree.insert(pair<int,double>(8, 8.5));
	mytree.insert(pair<int,double>(4, 8.5));
	mytree.insert(pair<int,double>(6, 8.5));
	mytree.insert(pair<int,double>(11, 8.5));
	mytree.insert(pair<int,double>(13, 8.5));
	mytree.insert(pair<int,double>(23, 8.5));
	mytree.insert(pair<int,double>(120, 8.5));
	mytree.insert(pair<int,double>(32, 8.5));
	mytree.insert(pair<int,double>(29, 8.5));
	mytree.insert(pair<int,double>(19, 8.5));
	mytree.insert(pair<int,double>(12, 8.5));
	mytree.insert(pair<int,double>(229, 8.5));
	mytree.insert(pair<int,double>(224, 8.5));
	mytree.insert(pair<int,double>(115, 8.5));
	mytree.insert(pair<int,double>(800, 8.5));
	mytree.insert(pair<int,double>(232, 8.5));
	mytree.insert(pair<int,double>(112, 8.5));
	mytree.insert(pair<int,double>(178, 8.5));
	mytree.insert(pair<int,double>(314, 8.5));
	mytree.insert(pair<int,double>(811, 8.5));
	mytree.insert(pair<int,double>(122, 8.5));
	mytree.insert(pair<int,double>(118, 8.5));
	mytree.insert(pair<int,double>(117, 8.5));
	mytree.insert(pair<int,double>(111, 8.5));
	mytree.insert(pair<int,double>(113, 8.5));
	mytree.insert(pair<int,double>(114, 8.5));
	mytree.insert(pair<int,double>(190, 8.5));
	mytree.insert(pair<int,double>(109, 8.5));
	mytree.insert(pair<int,double>(108, 8.5));
	mytree.insert(pair<int,double>(103, 8.5));
	
 	mytree.print();

 	//for (RedBlackTree<int,double>::iterator it = mytree.begin(); it != mytree.end(); ++it){
 //			cout << *it << endl;
 	//}
return 0;	
}
