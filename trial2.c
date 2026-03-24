#include<stdio.h>
#include<string.h>

struct node{
	int val;
	struct * prev;
	struct * next;
};
void remove(int val,struct node ** head)
{
	if(*head==NULL)
		return;
	struct node *ptr=*head;

	while(ptr!=NULL)
	{
		if(ptr->val==val)
		{
			if(ptr->prev==NULL)//removing head node
			{
				if(ptr->next!=NULL)//if only 1 node in entire list
				{
					ptr->next->prev=ptr->prev;
				}
				*head=ptr->next;
				free(ptr);
				ptr=*head;
				continue;
			}
			
			else //ptr->prev!=NULL
			{
				ptr->prev->next=ptr->next;
				if(ptr->next!=NULL)//ptr is not last node
					ptr->next->prev=ptr->prev;
				struct node *temp=ptr->next;
				free(ptr);
				ptr=temp;
				continue;
				
			}
			
		}
		ptr=ptr->next;
	}
}	
	
int main()
{
	struct node n1=(struct node*)(malloc)(sizeof(struct node));
		
	struct node n2=(struct node*)(malloc)(sizeof(struct node));
	struct node n3=(struct node*)(malloc)(sizeof(struct node));
	n1->val=1;
	n1->prev=NULL;
	n1->next=n2;
	n2->val=2;
	n2->prev=n1;
	n2->next=n3;
	n3->val=3;
	n3->next=NULL;
	n3->prev=n2;
	

	struct node * head=n1;
	remove(1,&head);
	struct node* ptr=head;
	
}

