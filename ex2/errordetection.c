#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int choice;
 char ch[50];
 do
 {
  printf("\n****************************");
  printf("\n1.1D parity\n2.2D parity\n3.Checksum\n4.CRC\n5.Exit");
  printf("\n****************************\n");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   {
    printf("\n1D Parity\n");
    printf("Enter your data\n");
    scanf("%s",ch);
    int count=0;
    int i;
    int a[50];
    int len=strlen(ch);
    for(i=0;i<len;i++)
     a[i]=ch[i]-48;
    int size=i;
    for(i=0;i<size;i++)
    {
     if(a[i]==1)
      count++;
    }
    if(count%2!=0)
    {
     a[i]=1;
     size++;
     for(i=0;i<size;i++)
      printf("%d",a[i]);
    }
    else
    {
     a[i]=0;
     size++;
     for(i=0;i<size;i++)
      printf("\n%d",a[i]);
    }
    break;
   }
   case 2:
   {
    int i,j,x,y,cnt=0;
    int arr[10][50];
    printf("\nEnter number of codes:");
    scanf("%d",&x);
    printf("Enter lenght of each code:");
    scanf("%d",&y);
    printf("\nEnter %d codes of length %d:\n",x,y);
    int len=strlen(ch);
    for(j=0;j<x;j++)
    {
     scanf("%s",ch);
     for(i=0;i<y;i++)
      arr[j][i]=ch[i]-48;
    }
    for(j=0;j<x;j++)
    {
     for(i=0;i<y;i++)
     {
      if(arr[j][i]==1)
       cnt++;
     }
     if(cnt%2==0)
      arr[j][i]=0;
     else
      arr[j][i]=1;
    }
    cnt=0;
    y++;
    for(i=0;i<y;i++)
    {
     cnt = 0;
     for(j=0;j<x;j++)
     {
      if(arr[j][i]==1)
      cnt++;
     }
     if(cnt%2==0)
      arr[j][i]=0;
     else
      arr[j][i]=1;
    }
    x++;
    for(j=0;j<x;j++)
    {
     for(i=0;i<y;i++)
      printf("\n%d",arr[j][i]);
     printf("\n");
    }
    break;
   }
   case 3:
   {
    int i,j,y,cnt=0;
    int sum[50];
    int arr1[10],arr2[10];
    printf("\nEnter the 2 codes:\n");
    scanf("%s",ch);
    int len=strlen(ch);
    for(i=0;i<len;i++)
     arr1[i]=ch[i]-48;
    scanf("%s",ch);
    for(i=0;i<len;i++)
     arr2[i]=ch[i]-48;
    int rem=0;
    for(i=len-1;i>=0;i--)
    {
     sum[i]=0;
     sum[i]=sum[i]+arr1[i]+arr2[i]+rem;
     rem=0;
     if(sum[i]==2)
     {
      sum[i]=0;
      rem=1;
     }
     else if(sum[i]==3)
     {
      sum[i]=1;
      rem=1;
     }
     else
      rem=0;
    }
    printf("\nChecksum:");
    for(i=0;i<len;i++)
    {
     if(sum[i]==0)
      sum[i]=1;
     else if(sum[i]==1)
      sum[i]=0;
     printf("%d",sum[i]);
    }
    break;
   }
   case 4:
   {
    int i,j,keylen,msglen;
    char input[100], key[30],temp[30],quot[100],rem[30],key1[30];
    printf("Enter Data: ");
    scanf("%s",input);
    printf("Enter Key: ");
    scanf("%s",key);
    keylen=strlen(key);
    msglen=strlen(input);
    strcpy(key1,key);
    for (i=0;i<keylen-1;i++) 
     input[msglen+i]='0';
    for (i=0;i<keylen;i++)
     temp[i]=input[i];
    for (i=0;i<msglen;i++) 
    {
     quot[i]=temp[0];
     if(quot[i]=='0')
      for (j=0;j<keylen;j++)
       key[j]='0'; else
     for (j=0;j<keylen;j++)
      key[j]=key1[j];
     for (j=keylen-1;j>0;j--) 
     {
      if(temp[j]==key[j]) 
       rem[j-1]='0'; else
      rem[j-1]='1';
     }
     rem[keylen-1]=input[i+keylen];
     strcpy(temp,rem);
    }
    strcpy(rem,temp);
    printf("\nQuotient is ");
    for (i=0;i<msglen;i++)
     printf("%c",quot[i]);
    printf("\nRemainder is ");
    for (i=0;i<keylen-1;i++)
     printf("%c",rem[i]);
    printf("\nFinal data is: ");
    for (i=0;i<msglen;i++)
     printf("%c",input[i]);
    for (i=0;i<keylen-1;i++)
     printf("%c",rem[i]);
    break;
   }
   case 5:
   {
    printf("Program Ended\n");
    return 1;
   }
  }
 }while(choice<=5);
}
