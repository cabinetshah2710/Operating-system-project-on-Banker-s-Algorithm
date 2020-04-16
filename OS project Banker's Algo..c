#include<stdio.h>
#include<stdlib.h>
int avail[10],maxim[20][20],allo[20][20],m,n,need[20][20];

void accept()
{
    int i,j,val;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           printf("\n PLEASE ENTER THE MAX REQUIRED VALUE for P%d,R%d: ",i,j);
           loop: scanf("%d",&val);
           if(val>avail[j])
           {
               printf("OOPS ERROR IS FOUND!THE ENTERED VALUE IS GREATER THAN THE AVAILABLE VALUE i.e %d .PLZ ENTER THE VALUE AGAIN: ",avail[j]);
               goto loop;

           }
           else
           maxim[i][j]=val;
        }

    }
}

void rollback(int roll[],int pro)
{
     int k;
    for(k=0;k<m;k++)
              {
              avail[k]=avail[k]+roll[k];
              allo[pro][k]=allo[pro][k]-roll[k];
              need[pro][k]=allo[pro][k]+roll[k];
              printf("\nWE ARE ROLLING BACK");
              }
}

int safety()
{
    int i,j,work[10],finish[10],flag=0,k,cnt=0,cn,flag1=0,ans;
    printf("\nTHE ALTERED ALLOCATION TABLE IS:\n");
   printf("PROCESS");
   for(i=0;i<m;i++)
   {
       printf("\tR%d\t",i);
   }
   printf("\n");
   for(i=0;i<n;i++)
   {
       printf("\nP%d\t",i);
       for(j=0;j<m;j++)
       {
           printf("%d\t\t",allo[i][j]);
       }
   }
    j=0;
    for(i=0;i<m;i++)
    {
        work[j]=avail[i];
        j++;
    }

       for(i=0;i<n;i++)
      {
         finish[i]=0;
      }

   while(cnt<=10)
   {
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
        for(j=0;j<m;j++)
        {
            if(need[i][j]<=work[j])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }

         }
         if(flag==1)
         {

             printf("\nTHE PROCESS P%d RAN SUCCESSFULLY",i);
             finish[i]=1;
             for(k=0;k<m;k++)
             {
                 work[k]=work[k]+allo[i][k];

             }

         }
      }
    }
    for(cn=0;cn<n;cn++)
    {
        if(finish[cn]==1)
        {
            flag1=1;
        }
        else
        {
            flag1=0;
            break;
        }
    }

    cnt++;
    if(flag1==1)
    {
       printf("\nTHE SYSTEM IS IN SAFE STATE\n");
       ans=0;
       break;
     }
   }//end of while
    if(flag1==0)
    {
        printf("\nTHE SYSTEM IS NOT IN SAFE STATE\n");
        ans=1;
    }
    return ans;
}
void request()
{
    int pro,val,i,ans1,k,roll[10];
    char ans;
    while(1)
    {
        printf("\nDO YOU HAVE A REQUEST?(y/n)");
        scanf("%c",&ans);
        scanf("%c",&ans);
        k=0;
        if(ans=='y'||ans=='Y')
        {
            printf("ENTER THE PROCESS REQUESTING(0,1,2,3..): ");
            scanf("%d",&pro);
            for(i=0;i<m;i++)
            {
                printf("ENTER THE REQUIRED VALUE OF RESOURCE R%d: ",i);
               loop1: scanf("%d",&val);
                if(val>maxim[pro][i])
           {
               printf("ERROR!!THE ENTERED VALUE IS GREATER THAN THE MAX VALUE REQD. i.e %d .PLZ ENTER THE VALUE AGAIN: ",maxim[pro][i]);
               goto loop1;
           }
           else
               {

                allo[pro][i]=allo[pro][i]+val;
                avail[i]=avail[i]-val;
                need[pro][i]=need[pro][i]-val;
                roll[k]=val;
                k++;
               }
            }
            ans1=safety();
            if(ans1==1)
            {
               rollback(roll,pro);
             }
        }
        else
        {
            exit(0);
        }
    }
}

int main()
{
   int i,val,j;
   printf("Coded By:- Cabinet Kumar Shah\n");
   printf("Registration No.:-11812420\n");
   printf("Roll Call:-B59\n");
   printf("\nWELCOME TO BANKER'S ALGORITHM\n");
   printf("\nENTER THE NUMBER OF RESOURCES: ");
   scanf("%d",&m);
   printf("\nENTER THE NUMBER OF PROCESS(s): ");
   scanf("%d",&n);
   for(i=0;i<m;i++)
   {
       printf("\nENTER THE MAX AVAILABLE VALUE FOR RESOURCE R%d: ",i);
       scanf("%d",&val);
       avail[i]=val;
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           allo[i][j]=0;
       }
   }
   accept();
   printf("\nTHE TABLE ENTERED FOR MAX NEEDED IS:\n");
   printf("PROCESS");
   for(i=0;i<m;i++)
   {
       printf("\tR%d\t",i);
   }
   printf("\n");
   for(i=0;i<n;i++)
   {
       printf("\nP%d\t",i);
       for(j=0;j<m;j++)
       {
           printf("%d\t\t",maxim[i][j]);
       }
   }
     for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           need[i][j]=maxim[i][j]-allo[i][j];
       }
   }

   request();

   return 0;
}
