#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int qactr = 0;//counting number of questions and answered correctly answered
int ctr = 0;//counter to break the while loop after user is done answering all questions or answers incorrectly
long int money=0;
int expert_lifeline=1;
int fifty_lifeline=1;
int lifeline_ctr=0;
char c;
char* options[] ={"1.Mahatma Gandhi   2.B.R Ambedkar   3.Narendra Modi   4.Rajendra Prasad","1.Sparrow   2.Lovebird   3.Hummingbird   4.Canary","1.Sydney   2.Queensland   3.Brisbane   4.Canberra","1.Samsung   2.Huawei   3.Realme   4.Oppo","1.Phi   2.Omega   3.Epsilon   4.Sigma","1.Alfred Nobel   2.Adolf Hitler   3.Sheldon Cooper   4.Joseph Lister","1.Robinson Crusoe   2.Harry Potter   3.Captain Ahab   4.Captain Nemo"};
void delay(int);
void prize();
void question();
void answer();
void fiftyfifty();

void main()
{
    printf("------------------------------------------------------\n");
    printf("|     WELCOME TO DJSCE ULTIMATE QUIZ COMPETITION     |\n");
    printf("------------------------------------------------------\n\n");
    printf("Let us Start....\n");
    while(ctr==0)
    {
        question();
        lifeline();
        answer();
    }
    if(qactr!=7)
    {
        printf("You walk away from the quiz with Rs.");
        if(qactr==0)
        {
            printf("%ld. Better luck next time :/",money);
        }
        else if(qactr==1)
        {
            printf("%ld. Good attempt.",money);
        }

        else if(qactr==2)
        {
            printf("%ld.Good attempt ",money);
        }
        else if(qactr==3)
        {
            printf("%ld. Good attempt.",money);
        }
        else if(qactr==4)
        {
            printf("%ld. Good attempt.",money);
        }
        else if(qactr==5)
        {
            printf("%ld. Close call, but congratulations.",money);
        }
        printf("\n\n");
    }
}

void delay(int num_of_seconds)
{
    int milli_sec = 1000*num_of_seconds;
    clock_t start_time = clock();
    while(clock() < start_time + milli_sec);
}
void prize()//used to store and display money earned after answering each question
{
    printf("**************************************************\n");
    switch(qactr)
    {
    case 0:
        money=10000;
        printf("You have won Rs.%ld...Good job!\n",money);
        printf("**************************************************\n");
        break;
    case 1:
        money=50000;
        printf("You have won Rs.%ld...Great job!\n",money);
        printf("**************************************************\n");
        break;
    case 2:
        money=100000;
        printf("You have won Rs.%ld...Great job!\n",money);
        printf("**************************************************\n");
        break;
    case 3:
        money=725000;
        printf("You have won Rs.%ld...Amazing!\n",money);
        printf("**************************************************\n");
        break;
    case 4:
        money=2500000;
        printf("You have won Rs.%ld...Fantastic!\n",money);
        printf("**************************************************\n");
        break;
    case 5:
        money=5000000;
        printf("You have won Rs.%ld...Fantastic!Almost there!\n",money);
        printf("**************************************************\n");
        break;
    case 6:
        printf("You have won the grand prize of Rs.1,00,00,000...Congratulations to you!\n You are the winner of the DJSCE ULTIMATE QUIZ competition!\n");
        printf("**************************************************\n");
        break;
    }
}

void question()//used to print questions as per required order decided by qactr
{
   if(qactr==0)
   {
       printf("Question %d:",qactr+1);
       printf("Who is known as Father of The Indian Constitution?\n");
       printf("%s\n",options[0]);
   }
   if(qactr==1)
   {
       printf("Question %d:",qactr+1);
       printf("What is the world's smallest bird??\n");
       printf("%s\n",options[1]);
   }
   if(qactr==2)
   {
       printf("Question %d:",qactr+1);
       printf("What is the capital of Australia?\n");
       printf("%s\n",options[2]);
   }
   if(qactr==3)
   {
       printf("Question %d:",qactr+1);
       printf("What is the name of the biggest technology company in South Korea?\n");
       printf("%s\n",options[3]);
   }
   if(qactr==4)
   {
       printf("Question %d:",qactr+1);
       printf("What is the last letter of the Greek Alphabet?\n");
       printf("%s\n",options[4]);
   }
   if(qactr==5)
   {
       printf("Question %d:",qactr+1);
       printf("Who is the Father of Dynamite?\n");
       printf("%s\n",options[5]);
   }
   if(qactr==6)
   {
       printf("Question %d:",qactr+1);
       printf("The point on Earth that is farthest from land is named after which fictional character?\n");
       printf("%s\n",options[6]);
   }
}

void lifeline()
{
    printf("\n");
    if(qactr==0)
    {
        delay(2);
        printf("--> You can use a lifeline if you wish or you can quit the game if you want to\n");
    }
    printf("Lifelines left\n");
    printf("> Ask The Expert (%d) left\t> 50-50 (%d) left\n",expert_lifeline,fifty_lifeline);
    for(;;)
    {
        printf("Enter 'e' for ask the expert, 'f' for fifty-fifty, 'q' to quit the game or simply enter 'a' if you do not wish to use a lifeline\n");
        scanf("%c",&c);
        if(c=='e' && expert_lifeline!=0)
    {
        lifeline_ctr = 1;
        expert_lifeline = 0;
        break;
    }
    else if(c=='f' && fifty_lifeline!=0)
    {
        lifeline_ctr = 2;
        fifty_lifeline = 0;
        break;
    }

    else if(c=='q')
    {
        lifeline_ctr=-1;
        ctr = 1;
        printf("\n");
        break;
    }
    else if((c=='e' && expert_lifeline==0) || (c=='f' && fifty_lifeline==0))
    {
        printf("Sorry,you're out of lifelines.\nSimply choose an option.\n");
    }
    else if(c=='a')
            {
                break;
            }
    }

}

void answer()//checking whether answer is correct and taking choice of further action
{
    int ans[]={2,3,4,1,2,1,4};
    if(lifeline_ctr==0)
    {
        int ch;
        printf("@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@ Enter your answer @\n");
        printf("@@@@@@@@@@@@@@@@@@@@@\n--> ");
        scanf("%d",&ch);
        if(ch==ans[qactr])
        {
           if(qactr==5)
           {
               prize();
               printf("Congrats on reaching the final question for the grand prize of 1 Crore.\nAre you ready? Then here we go!!\n");
               delay(3);
               system("cls");
               printf("\n\n");
           }
           else if(qactr==6)
           {
               printf("Correct answer!\n");
               prize();
               ctr=1;
           }
           else
           {
               prize();
               printf("Well done! Now onto the next question\n");
               printf("\n");
               delay(2);
               system("cls");
               printf("\n\n");
           }
       qactr++;
      }
      else
      {
        printf("Sorry! Your journey ends here...\n");
        printf("The correct answer is option %d\n\n\n\n",ans[qactr]);
        ctr=1;
      }
    }
    else if(lifeline_ctr==1)
    {
        printf("\n\nAll right then, let us Ask the Expert....\n");
        delay(3);
        printf("The answer according to the Expert is %d\n",ans[qactr]);
        printf("Now you may choose your option\n");
        lifeline_ctr=0;
        answer();
    }
    else if(lifeline_ctr==2)
    {
        fiftyfifty(ans);
    }

}

void fiftyfifty(int ans[])
{
    int i,op1,op2;
    int a=1;

    while(a==1)
    {
        op1 = rand()%10;
        op2 = rand()%10;
        if((op1==1 || op1==2 || op1==3 || op1==4) && (op2==1 || op2==2 || op2==3 || op2==4))
        {
            if(op1==ans[qactr] || op2==ans[qactr])
            {
                printf("Alright then. The two options left are - \n");
                printf("%d. and %d.\n\n",op1,op2);
                lifeline_ctr = 0;
                answer();
                break;
            }
        }
    }
}
