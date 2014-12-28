/* Write a program to implement a Stack using Linked List
 * Stack should support the following operations
 * void push(int number): Pushes an element on top of the stack
 * int pop(): Removes the last pushed element from the stack
 */
struct node{
  int element;
  struct node *next;
};
//Pushing an element on top of the stack
void push(int number)
{
  struct node* newnode= (struct node*)malloc(sizeof(struct node));
  newnode->number=element;
  if(head==NULL)
  {
    newnode->next=NULL;
    head=newnode;
  }
  else
  {
    newnode->next=head;
    head=newnode;
  }
}
//Removing the last pushed element from the stack
int pop()
{
  if(head==NULL){
    printf("\n Empty list");
    return(0);
  }
  else{
    head=head->next;
    return(0);
}
}
void print(struct node *head)
{
  while(head!=NULL)
  {
    printf("\n %d \n", head->number);
    head=head->next;
  }
  printf("\n Empty list");
}
int main()
{
  printf("\n Adding elements to the stack.\n New list: ");
  push(10);
  push(20);
  push(30);
  push(40);
  print(head);
  printf("\n Popping element in the stack.\n Modified list:")
  pop();
  print(head)
  return 0;;
}
