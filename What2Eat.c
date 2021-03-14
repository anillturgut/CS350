#include <stdio.h>
#include "string.h"
int main() {
    //ANIL TURGUT, S015146, CS350 HW1
    int numOfPeople;
    int choice;
    printf("Enter Number Of People: ");scanf("%d",&numOfPeople);
    char preferences[5][10];
    int scores[5];
    int choices[5];
    int i,j;
    for(i=0;i<5;i++){
        scores[i]=0;
    }
    for(i=0;i<5;i++){
        printf("Enter 5 food items to take vote on them: ");scanf("%s",&preferences[i]);
    }
    int k,l;
    for(l=0;l<numOfPeople;l++){
        printf("Player %d: \n\n",l+1);
        for(k=5;k>0;k--){
            printf("Enter Your Preference By Selecting Item From Menu..Highest Preferences first: ");
            for(j=0;j<5;j++){
                printf("\n%d)%s",j,preferences[j]);
            }
            printf("\nEnter Choice: ");scanf("%d",&choice);
            printf("\n\n");
            scores[choice]=scores[choice]+(k);
        }
    }
    //round 2
    int criteria=10;             //predesigned threshold
    int numOfItems=0;
    for(i=0;i<5;i++){
        if(scores[i]>=criteria){
            numOfItems++;
        }
    }
    int finalListScores[numOfItems];
    int p;
    for(p=0;p<numOfItems;p++)
    {
        finalListScores[p]=0;
    }
    char finalList[numOfItems][10];
    int counter=0;
    for(i=0;i<5;i++){
        if(scores[i]>=criteria){
            strcpy(finalList[counter],preferences[i]);
            counter++;
        }
    }
    for(i=0;i<numOfPeople;i++){
        printf("Player %d: ",i+1);
        for(k=numOfItems;k>0;k--){
            printf("Enter Your Preference By Selecting Item From Menu..Highest Preferences first: ");
            for(j=0;j<numOfItems;j++){
                printf("\n%d)%s",j,finalList[j]);
            }
            printf("\nEnter Choice: ");scanf("%d",&choice);
            printf("\n\n");
            finalListScores[choice]=finalListScores[choice]+(k);                //
        }
    }
    int max=0;
    int maxIndex;
    maxIndex=0;
    max=finalListScores[maxIndex];
    for(i=0;i<numOfItems;i++){
        if(finalListScores[i]>max){
            max=finalListScores[i];
            maxIndex=i;
        }
    }
    printf("\n\nThe Food Ordered Will Be: %s with %d Score..",finalList[maxIndex],max);


    return 0;
}
