#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int *arr;
int size;



void initializeArray();
void sorting();
void options();
int partition(int [],int,int);
void quicksort(int [],int,int);
void insertionSort(int[], int);


void main(){

    char validate[2];
    
   while(1){
 
    options();             
  
    do{
        sorting();
        printf("\nEnter string with y/Y to sort one more time...");
        scanf("%s",validate);
     }while(strstr(validate,"y") || strstr(validate,"Y"));
 
    }
    
}


void initializeArray(){
        //int size;
        if(arr==NULL){       
        printf("\nEnter the size of array ");
        scanf("%d",&size);

        arr = malloc(sizeof(int)*size);
        }else{
           free(arr);
           printf("\nEnter the size of array ");
        scanf("%d",&size);

        arr = malloc(sizeof(int)*size);
       }


}

void sorting(){
int choice;
int i;
double time;
clock_t start,end;

system("clear");
printf("\nWhich Sorting option would you like me to run \n");
printf("\n1.QuickSort");
printf("\n2.InsertionSort");
printf("\n3.exit");
printf("\nYour choice ");

scanf("%d",&choice);

    switch(choice){
      case 1:

    start = clock();
    quicksort(arr,0,size-1);
    end = clock();

    time = (double) (end-start);

    for(i=0;i<size;i++)
          printf("\n%d",arr[i]);


    printf("\nTime taken by quick_sort is %.2f sec\n",time);
    break;

    case 2:
         start = clock();
         insertionSort(arr,size);
         end = clock();

         time = (double)(end-start);

         for(i = 0;i<size;i++)
             printf("\n%d",arr[i]);

         printf("\nThe time taken by insertion sort is %.2f sec",time);
           
         break;

    case 3:
          exit(0);
          

     default:
             sorting();
     }

}


void options(){
int user_init;
int i;
system("clear");
printf("\n1.Generate number by computer");
printf("\n2.Enter number by user");
//printf("\n3.Enter number by file");
printf("\n3.Terminate the program");
printf("\nEnter your choice ");

scanf("%d",&user_init);

    switch(user_init){
          case 1:
               initializeArray();
               for(i=0;i<size;i++)
                       arr[i] = rand();

               printf("\nyour array is initialized");
               break;

          case 2:
                initializeArray();
                for(i = 0;i<size;i++)
                         scanf("%d",&arr[i]);
          
                break;

           /*case 3:
                 printf("\nPlease enter the file name or it's proper directory");
                 scanf("%199[^\n]",file_name);
               
                 in = fopen(file_name,"r");

                 while(fscanf(in,"%[^\n]\n",arr   */

          case 3:
               exit(0);

               default:
                     printf("\nPlease enter the choise wisely");
                     main();
          }
}

int partition(int arr[],int l,int u){

    int v = arr[l];
    int i = l;
    int j = u+1;
    int temp;
    //double time;
    //clock_t start,end;

    do{

        do{

            i = i+1;
        }while(arr[i]<v && i<=u);

        do{
            j = j-1;

         }while(v<arr[j]);

        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

   arr[l] = arr[j];
   arr[j] = v;

   return j;
}
void quicksort(int arr[],int l,int u){

     int j;

      if(l<u){
         j = partition(arr,l,u);

         quicksort(arr,l,j-1);
         quicksort(arr,j+1,u);
      }
}

void insertionSort(int arr[],int size){
      int i,j;
      int temp;

       for(i=1 ;i<size;i++){
            for(j=0;j<i;j++){
                if(arr[i]<arr[j]){
                     temp = arr[i];
                     arr[i] = arr[j];
                     arr[j] = temp;
                 }
            }
       }
}


