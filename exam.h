

void divisor(int n);
int is_perfect(int n);
void show_perfect(int N);	


typedef struct _element
{
	int val;
	_element *next;
}element;

typedef struct _queueHead
{
	element *first;
	element *last;
	_queueHead()
	{
		this->first = NULL;
		this->last = NULL;
	}
}queueHead;

void show_radixSort();

