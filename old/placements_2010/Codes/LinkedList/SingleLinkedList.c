#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;
void print(node *start) {

	node *temp = start;
	if(start==NULL) {
		printf("Empty List\n");
		return;
	}
	while(temp->next!=NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	return;
}
node *insert_front(node *start, int value) {

        node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;

	if(start==NULL)
		return temp;

	node *tmp = start;
	while(tmp->next!=NULL)
		tmp = tmp->next;
	tmp->next=temp;
	
	return start;
}
node *insert_back(node *start, int value) {

	node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = start;
	return temp;
}
node *insert_sorted(node *start, int val) {

	node *start1=start;
	node *temp = (node*)malloc(sizeof(node));
	temp->data = val;
	temp->next = NULL;
	if(!start)
		return temp;

	if( temp->data <= start->data ) {
		temp->next = start;
		return temp;
	}

	node *prev=start;
	while( start->data < temp->data  ) {
		
		if(start->next!=NULL) {
			prev = start;
			start = start->next;
		}
		else {
			start->next = temp;
			return start1;
		}
	}
	prev->next = temp;
	temp->next = start;

	return start1;

}
void deletelist(node *start) {

	if(start==NULL)
		return;
	if(start->next==NULL) {
		free(start);
		return;
	}

	node *tmp;
	while(start->next!=NULL) {
		tmp=start->next;
		free(start);
		start=tmp;
	}
	free(start);
	return;
}

void recursive_deletelist(node *start) {

	if(!start)
		return;
	recursive_deletelist(start->next);
	free(start);
}

node *reverse_recursive2(node *start) {
	
	if(!start || !(start->next))
		return start;
	
	node *NEXT = start->next;
	start->next = NULL;

	node *temp = reverse_recursive2(NEXT);
	
	NEXT->next = start;

	return temp;
	
}

node *reverse_recursive(node *start) {

	if(!start || !(start->next))
		return start;

	node *ret = reverse_recursive(start->next);
	start->next->next = start;
	start->next = NULL;

	return ret;
}

node *reverse(node *start) {

	if(!start || !(start->next))
		return start;

	node *temp=start->next, *temp1=NULL;
	start->next=NULL;
	while(temp->next!=NULL) {
		temp1 = temp->next;
		temp->next=start;

		start=temp;
		temp=temp1;
	}
	temp->next=start;

	return temp;
}
node *find(node *start, int val) {

	node *temp=start;
	while(temp!=NULL) {
		if(temp->data==val)
			return temp;
		else
			temp=temp->next;
	}
	return NULL;
}
int delete(node *start, int *size, int val) {
	
	node *temp = find(start, val);
	if(!temp)
		return 0;
	else {
		(*size)--;
		if(temp->next!=NULL) {
			node *tmp=temp->next;
			temp->data = tmp->data;
			temp->next = tmp->next;
			free(tmp);
		}
		else {
			while(start->next!=temp)
				start=start->next;
			start->next=NULL;
			free(temp);
		}
	}
	return 1;
}
int splitinto2(node *start, node **first, node **second, int count) {

	/* THIS WILL ACTUALLY SPLIT THE LINKED LIST INTO TWO, AND ORIGINAL LIST WILL BE GONE */
	if(count==0 || count==1)
	{
		*(first)=start;
		*(second)=NULL;
		return count;
	}

	*(first) = start;
	node *prev=NULL, *temp=start;
	int i;
	for(i=0; i<count/2; i++) {
		prev = temp;
		temp=temp->next;
	}

	*(second) = temp;
	prev->next=NULL;

	return count/2;
}
node *merge(node *first, int cntF, node *second, int cntS) {
	
	if(!cntF && !cntS)
		return NULL;
	if(!cntF && cntS)
		return second;
	if(cntF && !cntS)
		return first;

	int i;
	node *start=NULL;
	if(first->data > second->data) {
		start=second;
		second=second->next;
	}
	else {
		start=first;
		first=first->next;
	}

	node *temp=start;

	for(i=0; i<cntF+cntS-1; i++) {
		if(second==NULL) {
			temp->next=first;
			break;
		}
		if(first==NULL) {
			temp->next=second;
			break;
		}
		if(first->data > second->data) {
			temp->next=second;
			second=second->next;
		}
		else {
			temp->next=first;
			first=first->next;
		}
		temp=temp->next;
	}
	return start;
}
node *mergesort(node *start, int count) {

	if(count==1 || count==0)
		return start;
	node *first=NULL, *second=NULL;
	int count1 = splitinto2(start, &first, &second, count);
	first = mergesort(first, count1);
	second = mergesort(second, count-count1);
	return merge(first, count1, second, count-count1);
}
void clear(node **start, int count) {

	int i;
	for(i=0; i<count; i++) {
		deletelist(start[i]);
		start[i]=NULL;
	}
	return;
}
int max(node *start) {

	int mx=-INT_MAX;
	while(start!=NULL) {
		if(start->data > mx )
			mx = start->data;
		start=start->next;
	}
	return mx;
}
int NumberOfDigits(int Number) {

	// ONLY FOR POSITIVE INTEGERS
	int digits=0;
	if(!Number)
		digits=1;
	while(Number) {
		digits++;
		Number /= 10;
	}
	return digits;
}
int DigitAt(int Number, int Position) {

	int digit,i;

	for(i=0; i<Position; i++) {
		digit=Number%10;
		Number /= 10;
	}

	return digit;
}
node *radixsort(node *start) {

	if(!start)
		return start;

	int i,j;
	node *temp=NULL;
	node **bin = (node **)malloc(sizeof(node*)*10);

	int mx = max(start);
	if(mx==-INT_MAX)
		return NULL;

	int digits=NumberOfDigits(mx);

	for(i=0; i<digits; i++) {
		temp=start;
		clear(bin, 10);
		while(temp!=NULL) {
			int index=DigitAt(temp->data, i+1);
			bin[index] = insert_front(bin[index], temp->data);
			temp=temp->next;
		}
		
		/*
		// JUST CHECKING 
		for(j=0; j<10; j++) {
			printf("bin[%d] === ",j);
			print(bin[j]);
		}
		printf("\n");
		*/

		temp=start;
		/* Since we used extra space for bins, we will now just copy the data into the original linked list */
		for(j=0; j<10; j++) {
			node *itr=bin[j];
			while(itr!=NULL && temp!=NULL) {
				temp->data=itr->data;
				itr = itr->next;
				temp=temp->next;
			}
		}

	}

	return start;
}
node *remove_duplicates(node *start) {
	//ASSUMING THE LINKED LIST IS SORTED

	int CurData = -1;
	while(start) {
		CurData = start->data;
		node *CurStart = start, *prev = NULL;
		start = start->next;

		while((start) && (start->data == CurData)) {
			prev = start;
			start = start->next;
		}
		if(prev) {
			node *x = CurStart->next;
			prev->next=NULL;
			deletelist(x);
		}
		CurStart->next = start;
	}

	return;
}
int main()
{
	node *start1=NULL,*start2=NULL;
	int N,size,temp;
	scanf("%d",&N);
	size = N;
	while(N--) {
		scanf("%d",&temp);
//		start1 = insert_back(start1,temp);
//		start2 = insert_front(start2,temp);
		start2 = insert_sorted(start2,temp);
	}

	print(start2);

//	int K;
//	scanf("%d",&K);
//	delete(start2, &size, K);
//	print(start2);

//	node *sorted = radixsort(start2);
//	print(sorted);

	remove_duplicates(start2);
	print(start2);

	node *rev = reverse_recursive(start2);
	print(rev);

//	node *sorted = mergesort(start1,size);
//	print(sorted);

	return 0;
}
