#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int power;
    struct node *next;
};
typedef struct node node;
node *head1=NULL, *head2=NULL, *sum=NULL, *product=NULL;
node* createNode(int c, int p){		// Create a new node
    node *t=(node*)malloc(sizeof(node));
    t->coeff=c;
    t->power=p;
    t->next=NULL;
    return t;
}
node* insertNode(node *head, int c, int p){		// Insert node in descending order of power
    node *t=createNode(c,p);
    if(head==NULL || head->power < p){
        t->next=head;
        return t;
    }
    node *temp=head;
    while(temp->next!=NULL && temp->next->power >= p)
        temp=temp->next;
    if(temp->power==p){
        temp->coeff+=c;
        free(t);
    } else {
        t->next=temp->next;
        temp->next=t;
    }
    return head;
}
void display(node *head){		// Display polynomial
    if(head==NULL){
        printf("0\n");
        return;
    }
    node *t=head;
    while(t!=NULL){
        printf("%dx^%d",t->coeff,t->power);
        if(t->next!=NULL && t->next->coeff>=0) printf(" + ");
        t=t->next;
    }
    printf("\n");
}
node* addPoly(node *h1, node *h2){		// Add two polynomials
    node *res=NULL;
    while(h1!=NULL || h2!=NULL){
        if(h1==NULL){
            res=insertNode(res,h2->coeff,h2->power);
            h2=h2->next;
        } else if(h2==NULL){
            res=insertNode(res,h1->coeff,h1->power);
            h1=h1->next;
        } else if(h1->power > h2->power){
            res=insertNode(res,h1->coeff,h1->power);
            h1=h1->next;
        } else if(h1->power < h2->power){
            res=insertNode(res,h2->coeff,h2->power);
            h2=h2->next;
        } else {
            res=insertNode(res,h1->coeff+h2->coeff,h1->power);
            h1=h1->next;
            h2=h2->next;
        }
    }
    return res;
}
node* multiplyPoly(node *h1, node *h2){		// Multiply two polynomials
    node *res=NULL;
    node *i,*j;
    for(i=h1;i!=NULL;i=i->next){
        for(j=h2;j!=NULL;j=j->next){
            int c=i->coeff*j->coeff;
            int p=i->power+j->power;
            res=insertNode(res,c,p);
        }
    }
    return res;
}
void freePoly(node *head){		// Free memory
    node *t;
    while(head!=NULL){
        t=head;
        head=head->next;
        free(t);
    }
}
int menu(){		// Menu
    int ch;
    printf("\n*MENU*\n1.Input polynomials\n2.Display polynomials\n3.Add polynomials\n4.Multiply polynomials\n5.Exit\nEnter choice: ");
    scanf("%d",&ch);
    return ch;
}
void PolynomialOperation(){		// Menu-driven operations
    int ch,n,c,p,i;
    for(ch=menu();ch!=5;ch=menu()){
        switch(ch){
            case 1:
                freePoly(head1); freePoly(head2);
                head1=head2=NULL;
                printf("Enter number of terms for 1st polynomial: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter coeff and power: ");
                    scanf("%d %d",&c,&p);
                    head1=insertNode(head1,c,p);
                }
                printf("Enter number of terms for 2nd polynomial: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter coeff and power: ");
                    scanf("%d %d",&c,&p);
                    head2=insertNode(head2,c,p);
                }
                break;
            case 2:
                printf("First Polynomial: ");
                display(head1);
                printf("Second Polynomial: ");
                display(head2);
                break;
            case 3:
                freePoly(sum);
                sum=addPoly(head1,head2);
                printf("Sum: ");
                display(sum);
                break;
            case 4:
                freePoly(product);
                product=multiplyPoly(head1,head2);
                printf("Product: ");
                display(product);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    freePoly(head1); freePoly(head2); freePoly(sum); freePoly(product);
    printf("\nMemory freed successfully.\n");
}
int main(){
    PolynomialOperation();
    return 0;
}

