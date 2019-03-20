#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Concordance.h"
using namespace std;

// Default constructor is inline.
Concordance::~Concordance( )
{
	Node* temp;

    while ( first != NULL )
    {
    	temp = first;
    	first = first -> next;
    	delete temp;
    }
}

void Concordance::insert ( const Word& entry )
{
	Node *prev;

    if( ! present(entry) );
    {
		if ( first == NULL || strcmp(entry, first->wd) < 0 )
    		first = get_node(entry, 1, first);
    	else
    	{
    		prev = first;
    		while ( prev->next != NULL && prev->next->wd < entry )
        		prev = prev->next;
    		prev->next = get_node(entry, 1, prev->next);
    	}
	}
	else if( present(entry))
	{
		prev = first;
		while ( prev->next->wd!=entry)
			prev = prev->next;
		prev->count++
	}
}

size_t Concordance::length( ) const
{
    Node *cursor;
    size_t count;

    count = 0;
    for ( cursor=first; cursor != NULL; cursor=cursor->next )
    	++count;
    return count;
}

bool Concordance::present ( const Word& target ) const
{
    Node *cursor;

    for ( cursor=first;
          cursor!=NULL && cursor->wd!=target;
          cursor=cursor->next )
    	;
    return ( cursor != NULL );
}

ostream& operator << ( ostream& out_s, const Concordance& c )
{
    Concordance::Node *cursor;

    out_s << '(';
    for ( cursor=c.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
    	out_s << cursor->wd << ", ";
    if ( cursor != NULL )
    	out_s << cursor->wd;
    out_s << ')';

    return out_s;
}

Concordance::Node* Concordance::get_node ( const Word& entry, int occurs, Node* link )
{
    Node *temp;

    temp = new Node;
    temp->data = entry;
    temp->next = link;
    count = occurs;
    return temp;
}

