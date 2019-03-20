#ifndef CONCORDANCE_H
#define CONCORDANCE_H

#include <cstdlib>                 // Provides size_t
#include <iostream>                // Provides ostream
#include <cstring>

const int MAX = 8;
class Concordance
{
	public: 
    	typedef char Word[MAX+1];
    	Concordance( ) { first = NULL; }
    	~Concordance( );
    	void insert ( const Word& entry );
       	int get_count ( const Word& target ) const;
    	bool is_empty( ) const { return first == NULL; }
    	std::size_t length( ) const;
    	bool present ( const Word& target ) const;
    	friend std::ostream& operator << ( std::ostream& out_s, const Concordance& c );
	private:
    	struct Node
    	{
    		Word wd;
        	int count;
        	Node *next;
    	};
    	Node *first;
    	Node* get_node ( const Word& entry, int occurs, Node* link );
};
#endif

