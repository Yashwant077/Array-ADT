#include <stdio.h>
#include <stdlib.h>

struct myArr
{
    int total_size;
    int use_size;
    int *ptr;
};

void setArray(struct myArr* a)
{
    int t_size, u_size;
    printf("Enter total size::");
    scanf("%d",&t_size);
    if(t_size<=0)
    {
        printf("Please Enter a valid Size.\n");
        setArray(a);
    }
    a->total_size = t_size;
    printf("Enter use size::");
    scanf("%d",&u_size);
    if(u_size>t_size)
    {
        printf("Please Enter a Use Size less than Total size.\n");
        setArray(a);
    }
    a->use_size = u_size;
    a->ptr = (int*)malloc(t_size*sizeof(int));
    
    printf("Enter the elements in Array::");
    for(int i=0;i<(a->use_size);i++)
    {
        scanf("%d",&(a->ptr[i]));
    }
}

void insertionAtIndex(struct myArr* a)
{
    printf("Total Size of Array:: %d\n",a->total_size);
    printf("Use Size of Array:: %d\n",a->use_size);
    
    int index,num;
    printf("At which index you want to insert::");
    scanf("%d",&index);
    printf("Enter the number you want to insert::");
    scanf("%d",&num);
    
    for(int i=(a->use_size); i>=index; i--)
    {
        a->ptr[i+1] = a->ptr[i];
    }
    a->ptr[index] = num;
    a->use_size +=1;
}

void deletionAtIndex(struct myArr* a)
{
    int num;
    printf("Which Element you want to delete from Array?\n");
    scanf("%d",&num);
    for(int i=0;i<(a->use_size);i++)
    {
        if(a->ptr[i]==num)
        {
            printf("Element found at position %d.\n",i+1);
            for(int j=i;j<(a->use_size-1);j++)
            {
                a->ptr[j] = a->ptr[j+1];
            }
            printf("Element deleted successfully.\n");
            a->use_size -= 1;
            return;
        }
        printf("Hello\n");
    }
    printf("Element Not found.\n");
}

void searchInArray(struct myArr* a)
{
    int num;
    printf("Which Element you want to search in Array::");
    scanf("%d",&num);
    for(int i=0;i<(a->use_size);i++)
    {
        if(a->ptr[i]==num)
        {
            printf("Element found at position %d.\n",i+1);
            return;
        }
    }
    printf("Element Not found.\n");
}

void showArray(struct myArr* a)
{
    printf("Printing Array of size %d\n", a->use_size);
    for(int i=0; i<(a->use_size); i++)
    {
        printf(" %d ",a->ptr[i]);
    }
    printf("\n");
}

int main()
{
    struct myArr arr;
    int ch;
    do
    {
        printf("\nEnter your choice:"
                "\n1. Set Array"
                "\n2. Insertion"
                "\n3. Deletion"
                "\n4. Search an element"
                "\n5. Display Array"
                "\n0. Quit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                setArray(&arr);
                break;
            case 2:
                insertionAtIndex(&arr);
                break;
            case 3:
                deletionAtIndex(&arr);
                break;
            case 4:
                searchInArray(&arr);
                break;
            case 5:
                showArray(&arr);
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("Please Enter a valid choice!");
                break;
        }
    }while(ch!=0);
    return 0;
}
