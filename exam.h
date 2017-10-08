

void divisor(int n);
int is_perfect(int n);
void show_perfect(int N);	

typedef struct _element
{
	int val;
	_element *next;
}element;

typedef struct _Queue_byList
{
	element *first;		// pop point
	element *last;		// push point
	_Queue_byList()
	{
		this->first = NULL;
		this->last = NULL;
	}
}Queue_byList;

void show_radixSort();

