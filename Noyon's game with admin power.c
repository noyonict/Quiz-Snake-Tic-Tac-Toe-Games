//HEADER FILES
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<process.h>
//For snake game diractory
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

COORD coord = {0,0};
//For Admin Prototypes
void admin();
void password_admin(int counta);
void help_fun_admin();
void add_question();
void delete_question();
void search_question();
void view_question();
void edit_question();

FILE *fp, *ft;
typedef struct
{
    int q_no;
    char question[100];
    char optiona[50];
    char optionb[50];
    char optionc[50];
    char optiond[50];
    char ans;
}adminstruct;
adminstruct admn;
//FUNCTION PROTOTYPES
void opening();
void delay(unsigned int mseconds);
void gotoxy(int x, int y);
void noyon();
void structure();
void welcome();
void exit_fun();
void help_fun();
void mainmenu();
//  QUIZ GAME FUNCTION PROTOTYPES
void quizgame();
void startquizgame();
void quiz_game_help();
void quiz_game_hi_score();
void writescore(float score);
//SNAKE GAME FUNCTION PROTOTYPES
void snakegame();
void welcome_snake_game();
void snake_game_help();
void record();
int Scoreonly();
int Score();
void load();
void Delay(long double);
void Move();
void Food();
void Print();
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
void snake_game_view();
void snake_game_main();
int length,bend_no,len,life;
char key;

struct coordinate{
    int x;
    int y;
    int direction;
};
typedef struct coordinate coordinate;
coordinate head, bend[500],food,body[30];
//TIC TAC TOI GAME FUNCTION PROTOTYPES
void tictactoigame();
void drawBoard();
void turnPlayerX(int* pCell);
void turnPlayerO(int* pCell);
int validateInput (int cell);
void getRowCol(int cell, int* pX, int* pY);
int showResult(char ch);
void tic_help();
char gameBoard[3][3];
//GLOBAL VARIABLES
int i, c=178, count_f_exit=1, count_f_exit_admin =1;
char name[15];
int main()
{
    system("color 9f");
    opening();
    //password(1);
    //mainmenu();
    gotoxy(4,21);
    exit_fun();
    return 0;
}

void opening()
{
    structure(); gotoxy(31,2); printf("NOYON GAMES WORLD!");
    gotoxy(35,4); printf("- LOGIN -"); fflush(stdin);
    int x = 18, y=6; char cm = 15;
    gotoxy(x+5,y); printf("What are you want to do? ");
    gotoxy(x+10,y+3); printf("1 - User Login");
    gotoxy(x+10,y+6); printf("2 - Administrator Login");
    //gotoxy(x+10,y+6); printf("3 - Exit");
    gotoxy(x-5,y+9); for(i=0;i<53;i++) printf("%c", cm);
    gotoxy(x+5,y+10); printf("Enter your choice : "); fflush(stdin);
    switch(getch())
    {
    case '1':
        welcome();
        break;
    case '2':
        password_admin(1);
        break;
    default:
        gotoxy(x+5,y+12); printf("\aWrong input! Please input again......");
        Sleep(700); opening();
    }
}

void welcome()
{
    structure(); gotoxy(34,4); printf("- WELCOME -");
    char *ch = "Welcome to Noyon games world!";
    char *ch1 = "Press any key to going to mainmenu......";
    gotoxy(24,8);
    for(i=0;i<29;i++)
    {
        delay(60); printf("%c",ch[i]);
    }
    gotoxy(21,11); printf("Please enter your nick name : "); scanf("%s", name);
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    gotoxy(20,16);
    for(i=0;i<39;i++)
    {
        delay(5); printf("%c",ch1[i]);
    }

    switch(getch())
    {
    case 116:
        noyon();
        mainmenu();
        break;
    case 84:
        noyon();
        mainmenu();
        break;
    case 104:
        help_fun();
        break;
    case 72:
        help_fun();
        break;
    case 8:
        opening();
        break;
    case 27:
        exit_fun();
        break;
    default:
        mainmenu();
        break;
    }
}
void mainmenu()
{
    structure(); gotoxy(33,4); printf("- MAIN MENU -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    int x = 18, y=6; char cm = 15; strupr(name);
    gotoxy(x,y); printf("%s, what type of games you want to play? ",name);
    gotoxy(x+10,y+2); printf("1 - Quiz Game");
    gotoxy(x+10,y+4); printf("2 - Snake Game");
    gotoxy(x+10,y+6); printf("3 - Tic Tac Toe Game");
    gotoxy(x+10,y+8); printf("4 - Exit");
    gotoxy(x-5,y+10); for(i=0;i<53;i++) printf("%c", cm);
    gotoxy(x,y+11); printf("Enter your choice : "); fflush(stdin);
    switch(getch())
    {
    case '1':
        quizgame();
        break;
    case '2':
        welcome_snake_game();
        break;
    case '3':
        tictactoigame();
        break;
    case '4':
        exit_fun();
        break;
    case 'h':
        help_fun();
        break;
    case 'H':
        help_fun();
        break;
    case 116:
        noyon();
        mainmenu();
        break;
    case 84:
        noyon();
        mainmenu();
        break;
    case 8:
        opening();
        break;
    case 27:
        exit_fun();
        break;
    default:
        gotoxy(x,y+13); printf("\aWrong input! Please input again......");
        Sleep(700); mainmenu();
    }
}
//************************** QUIZ GAME FUNCTION ********************************//
void quizgame()
{
    structure(); gotoxy(33,4); printf("- QUIZ GAME -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    int x = 18, y=6; char cm = 15;
    gotoxy(x+1,y); printf("%s, WELCOME TO I.Q. TEST QUIZ GAME? ",name);
    gotoxy(x+10,y+2); printf("1 - Start Game");
    gotoxy(x+10,y+4); printf("2 - View High score");
    gotoxy(x+10,y+6); printf("3 - Help");
    //gotoxy(x+10,y+8); printf("4 - For Administrator");
    gotoxy(x+10,y+8); printf("4 - Exit");
    gotoxy(x-5,y+10); for(i=0;i<53;i++) printf("%c", cm);
    gotoxy(x,y+11); printf("Enter your choice : ");
    switch(getch())
    {
    case '1':
        startquizgame();
        break;
    case '2':
        quiz_game_hi_score();
        break;
    case '3':
        quiz_game_help();
        break;
    case '4':
        mainmenu();
        break;
    case 'h':
        quiz_game_help();
        break;
    case 'H':
        quiz_game_help();
        break;
    case 116:
        noyon();
        quizgame();
        break;
    case 84:
        noyon();
        quizgame();
        break;
    case 8:
        mainmenu();
        break;
    case 27:
        exit_fun();
        break;
    default:
        gotoxy(x,y+13); printf("\aWrong input! Please input again......");
        Sleep(700); quizgame();
    }
}
void password_admin(int counta)
{
    if(counta<=3)
    {
        if(count_f_exit_admin<=6)
        {
            structure();gotoxy(29,4); printf("- PASSWORD PROTECTED -");
            char pass[15],ch, chp[10] = "12345";
            char password[25] = "NewTechSoftwareLtd.noyon"; strcpy(chp + 0, password+19);
            strrev(chp); fflush(stdin);
            gotoxy(18,8); printf("Enter Administrator Password : "); strcat(chp, "535");
            i=0;
            while(ch != 13)
            {
                ch = getch();
                if(ch != 8 && ch != 13)
                {
                    putch('*');
                    pass[i] = ch;
                    i++;
                }
                pass[i] = '\0';
            }
            if(strcmp(pass,chp) == 0)
                    {
                        admin();
                    }
                    else
                    {
                        counta++; count_f_exit_admin++;
                        gotoxy(18,14); printf("\aWarning!! Incorrect Password! Try again.......");
                        Sleep(700);
                        system("cls");
                        password_admin(counta);
                    }
        }
        else
        {
            structure(); gotoxy(34,4); printf("- WORNING -");
            gotoxy(20,10); printf("You have no wright to open Administrator!!");
            gotoxy(29,12); printf("You can enjoy the game!!");
            gotoxy(20,14); printf("Press any key to going to mainmenu.....");
            getch();
            welcome();
        }
    }
    else
    {
        gotoxy(13,6);
        printf("\a\aYou can call to creator for Administrator password!!");
        gotoxy(27,8);
        printf("NOYON  -  01681246187");
        gotoxy(18,15);
        printf("Press any key for giving password again...");
        getch();
        system("cls");
        password_admin(3);
    }
}

void admin()
{
    int ac = 175;
    system("cls"); fflush(stdin);
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");
    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<60;i++)
        printf("%c",ac);
    gotoxy(31,3); printf(" ADMINISTRATOR ");
    gotoxy(gotox,20);
    for(i=0;i<60;i++)
        printf("%c",ac);
    //****************************//
    gotoxy(gotox,2);
    printf("Help(H)");
    gotoxy(gotox,21); printf("Back(BS)");
    gotoxy(56,2);
    printf("AboutNoyon(T)");
    gotoxy(60,21);
    printf("Exit(Esc)");
    int x=23;
    static int y=5;
    gotoxy(x,y);
    printf("What are you want to do? ");
    gotoxy(14,y+1);
    for(i=0;i<50;i++)
        printf("*");
    gotoxy(x,y+3);
    printf("     1 - Add Question");
    gotoxy(x,y+5);
    printf("     2 - Delete Question");
    gotoxy(x,y+7);
    printf("     3 - Search Question");
    gotoxy(x,y+9);
    printf("     4 - View all Question");
    gotoxy(x,y+11);
    printf("     5 - Edit Question");
    gotoxy(x,y+13);
    printf("     6 - Exit");
    again:
    gotoxy(x,y+16);
    printf("Enter your choice: ");
    switch(getch())
    {
    case 49:
        add_question();
        break;
    case 50:
        delete_question();
        break;
    case 51:
        search_question();
        break;
    case 52:
        view_question();
        break;
    case 53:
        edit_question();
        break;
    case 54:
        opening();
        break;
    case 116:
        noyon();
        admin();
        break;
    case 84:
        noyon();
        admin();
        break;
    case 104:
        help_fun_admin();
        break;
    case 72:
        help_fun_admin();
        break;
    case 8:
        opening();
        break;
    case 27:
        exit_fun();
        exit(0);
        break;
    default:
        gotoxy(16,y+18);
        printf("\aWrong input! Press any key for input again .....");
        getch();
        goto again;
        break;
    }
}
void add_question()
{
    system("cls"); fflush(stdin);
    fp = fopen("Question.dat", "ab+");
    if(getquestion() == 1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&admn, sizeof(admn), 1, fp);
        fflush(fp);
        fclose(fp);
        printf("\n\nThe Question is successfully saved.");
        printf("\n\nAre there any Question?(y/n)");
        fflush(stdin);
        if(getch() == 'y')
        {
            system("cls");
            add_question();
        }
        admin();
     }


}
int getquestion()
{
    int qno;
    againenterquestion:
        fflush(stdin);
        printf("Question No: "); scanf("%i", &qno);
        if(checkqno(qno) == 0)
        {
            gotoxy(25,0); printf("\aQuestion No Already Exist!!"); Sleep(800); system("cls");
            goto againenterquestion;
        }
    admn.q_no = qno;
    fflush(fp);
    fflush(stdin);
    printf("\nQuestion   : "); gets(admn.question);
    printf("\nOption A   : "); gets(admn.optiona);
    printf("\nOption B   : "); gets(admn.optionb);
    printf("\nOption C   : "); gets(admn.optionc);
    printf("\nOption D   : "); gets(admn.optiond);
    printf("\nAnswer     : "); scanf("%c",&admn.ans);
    fflush(stdin);
    printf("\nDo you want to save it.(y/n)");
    if(getch() == 'n')
    {
        admin();
    }
    return 1;
}
int checkqno(int t)
{
    rewind(fp);fflush(stdin);
    while(fread(&admn, sizeof(admn), 1, fp) == 1)
    {
        if( admn.q_no == t)
            {
                return 0;
            }
    }
    fflush(stdin);
    return 1;

}

void delete_question()
{
    int dqn,dcheck = 0;
    system("cls");
    printf("For Delete Enter Question No: "); scanf("%i", &dqn);
    fp = fopen("Question.dat", "rb");
    rewind(fp);
    while(fread(&admn, sizeof(admn), 1, fp) == 1)
    {
        if(admn.q_no == dqn)
        {
            printf("%i. ",admn.q_no); printf("%s", admn.question);
            printf("\n\n\tA. %s", admn.optiona); printf("\tB. %s", admn.optionb);
            printf("\n\tC. %s", admn.optionc); printf("\tD. %s", admn.optiond);
            printf("\n\n\tAns.  %c\n\n", admn.ans);
            dcheck++;
            break;
        }
    }
    if(dcheck != 0)
    {
        printf("\n\nDo you want to delete it?(y/n)");
        if(getch() == 'y')
        {
            ft = fopen("noyon.dat", "wb");
            rewind(fp);
            while(fread(&admn, sizeof(admn), 1, fp)== 1)
            {
                if(admn.q_no != dqn)
                {
                    fseek(ft, 0, SEEK_CUR);
                    fwrite(&admn, sizeof(admn), 1, ft);
                }
            }
            fflush(fp);
            fflush(ft);
            fclose(fp); fclose(ft);
            fflush(stdin);
            int a = 1;
            a = remove("Question.dat");
            rename("noyon.dat", "Question.dat");
            if(a == 0)
            {
                printf("\n\nQuestion No: %i is successfully delete.",dqn);
            }
            else
                printf("\n\nQuestion No: %i is not delete.",dqn);
        }
        fflush(stdin);
    }
    else
    {
        printf("\n\nQuestion No %i is not found.", dqn);
    }
    fflush(stdin);
    printf("\n\nDo you want to delete another? (y/n)");
    if(getch()=='y')
        delete_question();
    else
        admin();
}
void search_question()
{
    int srcq,check = 0;
    system("cls"); fflush(stdin);
    printf("Please enter Question No: "); scanf("%i", &srcq);
    fp = fopen("Question.dat", "rb");
    rewind(fp);
    while(fread(&admn, sizeof(admn), 1, fp) == 1)
    {
        if(admn.q_no == srcq)
        {
            printf("%i. ",admn.q_no); printf("%s", admn.question);
            printf("\n\n\tA. %s", admn.optiona); printf("\tB. %s", admn.optionb);
            printf("\n\tC. %s", admn.optionc); printf("\tD. %s", admn.optiond);
            printf("\n\n\tAns.  %c\n\n", admn.ans);
            check++;
            break;
        }
    }
    fflush(fp);
    fclose(fp);
    if(check == 0)
    {
        printf("\n\nQuestion No %i is not found", srcq);
    }
    fflush(stdin);
    printf("\n\nDo you want to another search.(y/n)");
    if(getch()=='y')
        search_question();
    else
        admin();
}
void view_question()
{
    int totalquestion = 0;
    system("cls"); fflush(stdin);
    fp = fopen("Question.dat", "rb");
    rewind(fp);
    while(fread(&admn, sizeof(admn), 1, fp) == 1)
    {
        printf("%i. ",admn.q_no); printf("%s", admn.question);
        printf("\n\n\tA. %s", admn.optiona); printf("\tB. %s", admn.optionb);
        printf("\n\tC. %s", admn.optionc); printf("\tD. %s", admn.optiond);
        printf("\n\n\tAns.  %c\n\n", admn.ans);
        totalquestion++;
    }
    printf("\n\nTotal Question = %i\n", totalquestion);
    printf("\nPress any key to continue.....");
    fflush(fp);
    fclose(fp);
    getch(); admin();
}
void edit_question()
{
    int eqn, echeck =0;
    system("cls"); fflush(stdin);
    printf("For Edit Please Enter Question No: "); scanf("%i", &eqn);
    fp = fopen("Question.dat", "rb+");
    rewind(fp);
    while(fread(&admn, sizeof(admn), 1, fp) == 1)
    {
        if(admn.q_no == eqn)
        {
            echeck++;
            printf("%i. ",admn.q_no); printf("%s", admn.question);
            printf("\n\n\tA. %s", admn.optiona); printf("\tB. %s", admn.optionb);
            printf("\n\tC. %s", admn.optionc); printf("\tD. %s", admn.optiond);
            printf("\n\n\tAns.  %c\n\n", admn.ans);
            printf("\n\nDo you want to edit it?(y/n)");
            if(getch()=='y')
            {
                system("cls");
                printf("Question No: %i", eqn);fflush(stdin);
                printf("\n\nQuestion   : "); gets(admn.question);
                printf("\nOption A   : "); gets(admn.optiona);
                printf("\nOption B   : "); gets(admn.optionb);fflush(stdin);
                printf("\nOption C   : "); gets(admn.optionc);
                printf("\nOption D   : "); gets(admn.optiond);fflush(stdin);
                printf("\nAnswer     : "); scanf("%c",&admn.ans);fflush(stdin);
                printf("\n\nDo you want to save it?(y/n)");
                if(getch() == 'n')
                    admin();
                else
                {
                    fflush(stdin);
                    //rewind(fp);
                    printf("\n\nQuestion No %i is modified.",eqn);
                    fseek(fp, (ftell(fp) - sizeof(admn)), 0);
                    fwrite(&admn, sizeof(admn), 1, fp);
                    fflush(fp); fclose(fp);
                }
                break;
            }
            fflush(stdin);
        }
    }
    if(echeck == 0)
            printf("\n\nQuestion No %i is not found.", eqn);
    fflush(fp);
    fclose(fp);
    printf("\n\nDo you want to edit another Question? (y/n)");
    if(getch() == 'y')
        edit_question();
    else
        admin();
}
void help_fun_admin()
{
    structure(); gotoxy(30,4); printf("- ADMINISTRATOR HELP -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(65,21); printf("Exit(Esc)");
    gotoxy(25,6); printf("ADMINISTRATOR INSTRUCTIONS & HELP");
    gotoxy(7,8); printf("You are the  administrator in this game. You can add  question for");
    gotoxy(7,10); printf("quiz  game, you  can  delete  question,  also  can  edit  question");
    gotoxy(7,12); printf("everything. You can also set \"how many question are display when a");
    gotoxy(7,14); printf("user play\".  Almost  everything  you can do here  for  controlling");
    fflush(stdin);
    gotoxy(7,16); printf("quiz game.");
    switch(getch())
    {
    case 'h':
        help_fun_admin();
        break;
    case 'H':
        help_fun_admin();
        break;
    case 116:
        noyon();
        help_fun_admin();
        break;
    case 84:
        noyon();
        help_fun_admin();
        break;
    case 8:
        admin();
        break;
    case 27:
        exit_fun();
        break;
    default:
        admin();
        break;
    }
}

//****************** End admin Function *************************************//
int qnext = 0;
void startquizgame()
{
     int countq, countr, nquestion, rnumber, i=0, nq[6], no, sleep = 700,num_of_qus=0,anser,lower;
     float score;
     char ans;
     time_t initialtime,finaltime;
     system("cls"); fflush(stdin);
     fp = fopen("Question.dat", "rb");
     while(fread(&admn, sizeof(admn), 1, fp)==1)
     {
         num_of_qus++;
     }
     fclose(fp);
     fflush(stdin);
         initialtime=time(NULL);
         countq=countr=0;
         nquestion=no=1;
         start:
             srand ( time(NULL) );
             rnumber=rand()%num_of_qus+1;
             nq[nquestion]=rnumber;
             for (i=0;i<nquestion;i++)
                if (nq[i]==rnumber) goto start;
                    fp = fopen("Question.dat", "rb");
                    rewind(fp);
                    while(fread(&admn,  sizeof(admn), 1, fp)==1)
                    {
                        if(rnumber == admn.q_no)
                        {
                            structure(); gotoxy(33,4); printf("- QUESTION -");fflush(stdin);
                            countq++;
                            int qlenth = strlen(admn.question); fflush(stdin);
                            if(qlenth <= 64)
                            {
                                gotoxy(7,6); printf("%i. %s", no, admn.question); no++; fflush(stdin);
                                gotoxy(14,9); printf("A. %s  \t B. %s",admn.optiona,admn.optionb); fflush(stdin);
                                gotoxy(14,11); printf("C. %s  \t D. %s",admn.optionc,admn.optiond); fflush(stdin);
                                up:
                                    gotoxy(14,14); printf("Ans. "); anser = getchar();//scanf("%c", &ans);
                                    lower = tolower(anser);
                                    if(lower == 'a' || lower == 'b' || lower == 'c' || lower == 'd')
                                    {
                                        if(lower == admn.ans)
                                            {
                                                 gotoxy(14,16); printf("Correct!!!"); countr++; Sleep(sleep); break;
                                            }
                                            else
                                            {
                                                 gotoxy(14,16); printf("Wrong!!! The correct answer is %c", admn.ans); Sleep(sleep); break;
                                            }
                                    }
                                    else
                                    {
                                        gotoxy(14,18); printf("\aInvalid input! Please input again....."); goto up;
                                    }
                             }
                             else
                             {
                                  gotoxy(7,6); printf("%i. ",no);
                                   for(i=0; i<64; i++){
                                       printf("%c", admn.question[i]);
                                  } fflush(stdin);
                                  gotoxy(10,7); for(i=64; i<qlenth; i++){
                                       printf("%c", admn.question[i]);
                                  } fflush(stdin);
                                  gotoxy(7,9); printf("\tA. %s  \t B. %s",admn.optiona,admn.optionb); no++; fflush(stdin);
                                  gotoxy(7,11); printf("\tC. %s  \t D. %s",admn.optionc,admn.optiond); fflush(stdin);
                                  uplong:
                                      gotoxy(7,14); printf("\tAns. "); anser = getchar();//scanf("%c", &ans);
                                      lower = tolower(anser);
                                      if(lower == 'a' || lower == 'b' || lower == 'c' || lower == 'd')
                                      {
                                          if(lower == admn.ans)
                                              {
                                                   gotoxy(7,16); printf("\tCorrect!!!"); countr++; Sleep(sleep); break;
                                              }
                                              else
                                              {
                                                   gotoxy(7,16); printf("\tWrong!!! The correct answer is %c", admn.ans); Sleep(sleep); break;
                                              }
                                      }
                                      else
                                      {
                                          gotoxy(7,18); printf("\a\tInvalid input! Please input again....."); goto uplong;
                                      }
                               }


                        }
                    }
                    //****************************** End Question ***************************************//
        nquestion++;
        fflush(stdin);
        fclose(fp);
        if (nquestion<=5+qnext) goto start;
        finaltime=time(NULL);
        score=(float)countr/countq*100-difftime(finaltime,initialtime)/40;
        if (score<0) score=0;
        else if(score>100) score =100;
        structure(); gotoxy(33,4); printf("- QUIZ GAME -");
        int x = 23;
        gotoxy(x+3,8); printf("HI %s, YOUR SCORE: %.2f",name, score);
        if (score>=95) {gotoxy(x-5,11); printf("EXCELLENT! %s YOUR ARE SO SMART!! KEEP IT UP",name);}
        else if (score>=80 && score<100) {gotoxy(x+11,11); printf("VERY GOOD!!");}
        else if (score>=60 &&score<80) {gotoxy(x,11); printf("GOOD! BUT YOU NEED TO KNOW MORE.");}
        else if (score>=40 && score<60) {gotoxy(x-7,11);printf("SATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");}
        else {gotoxy(x,11); printf("YOU ARE VERY POOR IN G.K.,WORK HARD");}
        gotoxy(5,3); printf("Help(H)");
        gotoxy(62,3); printf("AboutNoyon(T)");
        gotoxy(5,21); printf("Back(BackSpace)");
        gotoxy(66,21); printf("Exit(Esc)"); fflush(stdin);
        qgagain:
            gotoxy(x,17); printf("Do you want to play next level?(Y/N) ");
            switch(getch())
            {
            case 'y':
                writescore(score);qnext++;
                startquizgame();
                break;
            case 'Y':
                writescore(score);qnext++;
                startquizgame();
                break;
            case 'n':
                writescore(score);
                quizgame();
                break;
            case 'N':
                writescore(score);
                quizgame();
            case 116:
                writescore(score);
                noyon();
                quizgame();
                break;
            case 84:
                writescore(score);
                noyon();
                quizgame();
                break;
            case 8:
                writescore(score);
                quizgame();
                break;
            case 'h':
                writescore(score);
                quiz_game_help();
                break;
            case 'H':
                writescore(score);
                quiz_game_help();
                break;
            case 27:
                writescore(score);
                mainmenu();
                break;
            default:
                gotoxy(x,19); printf("\aInvalid input! Please input again.....");
                goto qgagain;
                break;
        }
}
void quiz_game_help()
{
    structure(); gotoxy(31,4); printf("- QUIZ GAME HELP -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(65,21); printf("Exit(Esc)");
    gotoxy(28,6); printf("GAME INSTRUCTIONS & HELP");
    gotoxy(7,8); printf("This game is  very easy  to  play.  You'll  be asked  some general");
    gotoxy(7,9); printf("knowledge  questions and  the right  answer is to be  chosen among");
    gotoxy(7,10); printf("the  four options  provided. Your score  will be calculated at the");
    gotoxy(7,11); printf("end.  Remember  that the  more  quicker  you give  answer the more");
    gotoxy(7,12); printf("score you will secure. Your score will be calculated and displayed");
    gotoxy(7,13); printf("at the end and displayed. If you secure highest score,  your score");
    gotoxy(7,17); printf("There are a administrator power for controlling this game. But you");
    gotoxy(7,18); printf("need to log in for  using  administrator  power by  using  another");
    gotoxy(7,19); printf("password."); fflush(stdin);
    gotoxy(7,14); printf("will be recorded.        SO BEST OF LUCK. ");
    switch(getch())
    {
    case 'h':
        quiz_game_help();
        break;
    case 'H':
        quiz_game_help();
        break;
    case 116:
        noyon();
        quizgame();
        break;
    case 84:
        noyon();
        quizgame();
        break;
    case 8:
        quizgame();
        break;
    case 27:
        mainmenu();
        break;
    default:
        quizgame();
        break;
    }
}
void quiz_game_hi_score()
{
    char name[15];
    float s;
    FILE *f;
    structure(); gotoxy(33,4); printf("- QUIZ GAME -");
    f=fopen("Quiz_game_score.txt","r");
    fscanf(f,"%s%f",&name,&s);
    gotoxy(21,9); printf("%s has secured the Highest Score %.2f",name,s);
    fclose(f); fflush(stdin);
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)"); fflush(stdin);
    gotoxy(65,21); printf("Exit(Esc)");

            switch(getch())
            {
            case 116:
                noyon();
                quizgame();
                break;
            case 84:
                noyon();
                quizgame();
                break;
            case 8:
                quizgame();
                break;
            case 'h':
                quiz_game_help();
                break;
            case 'H':
                quiz_game_help();
                break;
            case 27:
                mainmenu();
                break;
            default:
                quizgame();
                break;
            }
}
void writescore(float score)
{
    float sc;
    char nm[20];
    FILE *f;
    system("cls"); fflush(stdin);
    f=fopen("Quiz_game_score.txt","r");
    fscanf(f,"%s%f",&nm,&sc);
    if (score>=sc)
     { sc=score;
       fclose(f);
       f=fopen("Quiz_game_score.txt","w");
       fprintf(f,"%s %.2f",name,sc);
       fflush(stdin);
       fclose(f);
     }
     fflush(stdin);
}

//************************* END QUIZ GAME FUNCTION ******************************//
//************************** SNAKE GAME FUNCTION ********************************//
void snakegame()
{
    structure(); gotoxy(32,4); printf("- SNAKE GAME -"); fflush(stdin);
    int row,col,r,c,q;
    gotoxy(35,12);
    printf("loading...");
    gotoxy(26,13); fflush(stdin);
    for(r=1;r<=26;r++){
        delay(30);
        //for(q=0;q<=100000000;q++);//to display the character slowly
        printf("%c",177);fflush(stdin);}
    //********************************** Loading.......... End ****************************//
    char key;
    length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;
    Boarder();
    Food(); //to generate food coordinates initially
    life=3; //number of extra lives
    bend[0]=head;
    Move();   //initialing initial bend coordinate
}
void snake_game_main()
{
    structure(); gotoxy(32,4); printf("- SNAKE GAME -");
    int x = 18, y=6; char cm = 15; fflush(stdin);
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    gotoxy(x,y); printf("%s, what are you want to do? ",name);
    gotoxy(x+10,y+2); printf("1 - Start Snake Game");
    gotoxy(x+10,y+4); printf("2 - View All Score");
    gotoxy(x+10,y+6); printf("3 - Help");
    gotoxy(x+10,y+8); printf("4 - Exit");
    gotoxy(x-5,y+10); for(i=0;i<53;i++) printf("%c", cm); fflush(stdin);
    gotoxy(x,y+11); printf("Enter your choice : ");
    fflush(stdin);
    switch(getch())
    {
    case '1':
        snakegame();
        break;
    case '2':
        snake_game_view();
        break;
    case '3':
        snake_game_help();
        break;
    case '4':
        mainmenu();
        break;
    case 'h':
        snake_game_help();
        break;
    case 'H':
        snake_game_help();
        break;
    case 116:
        noyon();
        snake_game_main();
        break;
    case 84:
        noyon();
        snake_game_main();
        break;
    case 8:
        mainmenu();
        break;
    case 27:
        exit_fun();
        break;
    default:
        gotoxy(x,y+13); printf("\aWrong input! Please input again......");
        Sleep(700); snake_game_main();
    }
}

void Move()
{
    int a,i;
    do{
        Food();
        fflush(stdin);
        len=0;
        for(i=0;i<30;i++)
        {
            body[i].x=0;
            body[i].y=0;
            if(i==length)
            break;
        }
        Delay(length); fflush(stdin);
        Boarder();
        if(head.direction==RIGHT)
            Right();
        else if(head.direction==LEFT)
            Left();
        else if(head.direction==DOWN)
            Down();
        else if(head.direction==UP)
            Up();
        ExitGame();
    }while(!kbhit());
    a=getch(); fflush(stdin);
    if(a==27)
    {
        system("cls");

        exit(0);

    }
    key=getch();
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {
        fflush(stdin);
        bend_no++;
        bend[bend_no]=head;
        head.direction=key;
        if(key==UP)
            head.y--;
        if(key==DOWN)
            head.y++;
        if(key==RIGHT)
            head.x++;
        if(key==LEFT)
            head.x--;
        Move();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
        Move();
    }
}
void GotoXY(int x, int y)
{
    HANDLE a; fflush(stdin);
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b); fflush(stdin);
 }
void Down()
{
    int i; fflush(stdin);
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++; fflush(stdin);
    }
    Bend(); fflush(stdin);
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    fflush(stdin);
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
    fflush(stdin);
}

void ExitGame()
{
    int i,check=0;
    fflush(stdin);
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;   //check's value increases as the coordinates of head is equal to any other body coordinate
            fflush(stdin);
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        fflush(stdin);
        life--;
        if(life>=0)
        {
            fflush(stdin);
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            structure(); gotoxy(32,4); printf("- SNAKE GAME -"); fflush(stdin);
            gotoxy(22,6);printf("Hi  %s,  All  lives  completed",name);
            gotoxy(29,8); printf("%s YOUR SCORE = %d",name, (length-5));
            gotoxy(22,10); printf("Better    Luck    Next    Time!!!");
            gotoxy(5,3); printf("Help(H)");
            gotoxy(62,3); printf("AboutNoyon(T)");
            gotoxy(5,21); printf("Back(BackSpace)");
            gotoxy(66,21); printf("Exit(Esc)");
            record(); fflush(stdin);
            upsnakexit:
            gotoxy(24,18); printf("Do you want to play again?(y/n)");
            fflush(stdin);
            switch(getch())
            {
            case 'y':
                snakegame();
                break;
            case 'Y':
                snakegame();
                break;
            case 'n':
                snake_game_main();
                break;
            case 'N':
                snake_game_main();
                break;
            case 'h':
                snake_game_help();
                break;
            case 'H':
                snake_game_help();
                break;
            case 116:
                noyon();
                ExitGame();
                break;
            case 84:
                noyon();
                ExitGame();
                break;
            case 8:
                snake_game_main();
                break;
            case 27:
                mainmenu();
                break;
            default:
                goto upsnakexit;
                break;
            }
        }
    }
}
void Food()
{
    fflush(stdin);
    if(head.x==food.x&&head.y==food.y)
    {
        fflush(stdin);
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        fflush(stdin);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i; fflush(stdin);
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
                fflush(stdin);
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend(); fflush(stdin);
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i; fflush(stdin);
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
            fflush(stdin);
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++; fflush(stdin);
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff; fflush(stdin);
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++; fflush(stdin);
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++; fflush(stdin);
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++; fflush(stdin);
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls"); fflush(stdin);
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
       printf("*");
   for(i=10;i<71;i++)
   {
       fflush(stdin);
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!" );
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!" );
       GotoXY(70,i);
       printf("!");
       fflush(stdin);
   }
}
void record()
{
   char plname[20],nplname[20]; fflush(stdin);
   int j,px;
   FILE *info;
   info=fopen("snake_game_record.txt","a+");
   strcpy(nplname, name);
   fprintf(info,"Player Name : %s\n",nplname);
    //for date and time
   time_t mytime;
   mytime = time(NULL);
   fprintf(info,"Played Date: %s",ctime(&mytime));
     //**************************
   fprintf(info,"Score: %d\n",(length-5));//call score to display score
   for(i=0;i<=50;i++)
        fprintf(info,"_");
   fprintf(info,"\n");
   fflush(info);
   fclose(info);
   fflush(stdin);
}
int Score()
{
   int score; fflush(stdin);
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life); fflush(stdin);
   return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls"); fflush(stdin);
    return score;
}
void snake_game_view()
{
    system("cls"); fflush(stdin);
    FILE *info;
    info=fopen("snake_game_record.txt","r");
    do{
            putchar(c=getc(info));
        }while(c!=EOF);
    fflush(info);
    fclose(info);
    fflush(stdin);
    getch();
    snake_game_main();
}

void Up()
{
   int i; fflush(stdin);
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend(); fflush(stdin);
   if(!kbhit())
       head.y--;
}

void welcome_snake_game()
{
    structure(); gotoxy(31,4); printf("- SNAKE GAME -"); fflush(stdin);
    char *ch = "WELCOME TO THE MINI SNAKE GAME!!";
    char *ch1 = "Press any key to continue.....";
    int lenth = strlen(ch);
    int lenth1 = strlen(ch1);
    gotoxy(34,8); printf("HI %s",name);
    gotoxy(22,10);
    for(i=0;i<lenth;i++)
    {
        delay(30); printf("%c",ch[i]);
    }
    gotoxy(23,16);
    for(i=0;i<lenth1;i++)
    {
        delay(5); printf("%c",ch1[i]);
    }
    getch(); fflush(stdin);
    snake_game_main();
}
void snake_game_help()
{
    fflush(stdin);
    structure(); gotoxy(30,4); printf("- SNAKE GAME HELP -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    gotoxy(27,6); printf("GAME INSTRUCTIONS & HELP");
    gotoxy(7,8); printf("-> Use arrow keys to move the snake.");
    gotoxy(7,10); printf("-> You will be  provided foods at the several coordinates of the");
    gotoxy(7,11); printf("   screen which you have to eat.");
    gotoxy(7,13); printf("-> Every-time you eat  a  food the  length of the  snake will be");
    gotoxy(7,14); printf("   increased by 1 element and thus the score."); fflush(stdin);
    gotoxy(24,17); printf("Press any key to play the game.....");
    switch(getch())
    {
    case 116:
        noyon();
        snakegame();
        break;
    case 84:
        noyon();
        snakegame();
        break;
    case 104:
        snake_game_help();
        break;
    case 72:
        snake_game_help();
        break;
    case 8:
        snake_game_main();
        break;
    case 27:
        mainmenu();
        break;
    default:
        snakegame();
        break;
    }
}

//************************* END SNAKE GAME **************************************//
//************************* TIC TAC TOI GAME *************************************//
int x=21,y=5;
void tictactoigame()
{
    structure(); gotoxy(30,4); printf("- TIC TAC TOE GAME -"); fflush(stdin);
    int x =0,y = 0,row = 0,col = 0,selectedCell = 0,availableCell = 9;
            char startChar = '1';
            for(row=0;row<3;row++)
            {
                for(col=0;col<3;col++)
                {
                    gameBoard[row][col] = startChar++;

                }
            }
        drawBoard();
        //Loop untill we've played all the cell
        while( availableCell>=0 )
        {
            //Player 1 is X //
            turnPlayerX(&selectedCell);
            // get row and col from the selected cell  //
            getRowCol (selectedCell, &x, &y);
            // Update gameBoard array //
            gameBoard[x][y] = 'X';
            availableCell -= 1;   //decrease available cell //
            //clrscr();
            system("cls");
            drawBoard();
            //check whether player one is winner of not //
            if( showResult('X') == 1)
            {
                break;
            }
            else if( availableCell == 0 )
            {
                gotoxy(35,18); printf("\aGame Drawn");
                break;
            }
            turnPlayerO(&selectedCell);  // Player two turn
            // get row and col from the selected cell
            getRowCol(selectedCell, &x,&y);
            //update gameBoard array //
            gameBoard[x][y] = 'O';
            //decrease available cell //
            availableCell -= 1;
            system("cls");
            drawBoard();
            // Check whether player two is winner or not //
            if(showResult('O') == 1)
            {
                break;
            }
            else if(availableCell == 0)
            {
                gotoxy(35,18); printf("\aGame Drawn");
                break;
            }
        }
        fflush(stdin);
        gotoxy(5,3); printf("Help(H)");
        gotoxy(61,3); printf("AboutNoyon(SB)");
        gotoxy(5,21); printf("Back(BackSpace)");
        gotoxy(66,21); printf("Exit(Esc)");
        ticgagain:
            gotoxy(21,19); printf("Are you want to play again?(Y/N) ");
            switch(getch())
            {
            case 'y':
                tictactoigame();
                break;
            case 'Y':
                tictactoigame();
                break;
            case 'n':
                mainmenu();
                break;
            case 'N':
                mainmenu();
            case 32:
                noyon();
                tictactoigame();
                break;
            case 8:
                mainmenu();
            case 'h':
                tic_help();
                break;
            case 'H':
                tic_help();
                break;
            case 27:
                exit_fun();
                break;
            default:
                gotoxy(20,20); printf("\a Invalid input! Please input again.....");
                goto ticgagain;
                break;
            }
}
void drawBoard()
{
    structure(); gotoxy(30,4); printf("- TIC TAC TOI GAME -"); fflush(stdin);
    int i,j;
    gotoxy(x,y); printf("Made by Md. Mohaymenul Islam (NOYON)");
    gotoxy(x,y+1); printf("Digits (1-9) indicates VALID cell number\n");
    gotoxy(37,y+3); printf("NOYON");
    gotoxy(x+12,y+5); printf("  %c | %c | %c  ",gameBoard[0][0],gameBoard[0][1],gameBoard[0][2]);
    gotoxy(x+12,y+6); printf(" ---|---|---");
    gotoxy(x+12,y+7); printf("  %c | %c | %c  ",gameBoard[1][0],gameBoard[1][1],gameBoard[1][2]);
    gotoxy(x+12,y+8); printf(" ---|---|---");
    gotoxy(x+12,y+9); printf("  %c | %c | %c  ",gameBoard[2][0],gameBoard[2][1],gameBoard[2][2]);
    gotoxy(37,y+11); printf("NOYON");
}
void turnPlayerX(int* pCell)
{
    int cell; fflush(stdin);
    do
    {
        gotoxy(x,y+12); printf(" Player X ");
        gotoxy(x,y+13); printf(" Select VALID cell number: ");
        scanf("%d", &cell);
    }while( 0 == validateInput(cell) );

    *pCell = cell;
}

void turnPlayerO(int* pCell)
{
    int cell; fflush(stdin);
    do
    {
        gotoxy(x,y+12); printf(" Player O ");
        gotoxy(x,y+13); printf(" Select VALID cell number: ");
        scanf("%d", &cell);
    }while( 0 == validateInput(cell) );

    *pCell = cell;
}
int validateInput (int cell)
{
    int row,col; fflush(stdin);
    if( (cell<1) || (cell>9) )  //if cell lass than 1 or gather than 9 then false //
    {
        gotoxy(x+35,y+13); printf("\aWrong Cell!!");
        return 0;
    }
    getRowCol(cell, &row, &col);
    if( ('O' == gameBoard[row][col]) || ('X' == gameBoard[row][col]) )
    {
        return 0;
    }
    return 1;
}

void getRowCol(int cell, int* pX, int* pY)
{
    fflush(stdin);
    *pX = (cell-1) / 3;
    *pY = (cell-1) % 3;
}

int showResult(char ch)                         //For show the winner //
{
    int status = 0; fflush(stdin);
    if(gameBoard[0][0] == ch && gameBoard[1][1] == ch & gameBoard[2][2] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[0][2] == ch && gameBoard[1][1] == ch & gameBoard[2][0] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[0][0] == ch && gameBoard[1][0] == ch & gameBoard[2][0] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[0][0] == ch && gameBoard[0][1] == ch & gameBoard[0][2] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[2][0] == ch && gameBoard[2][1] == ch & gameBoard[2][2] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[1][0] == ch && gameBoard[1][1] == ch & gameBoard[1][2] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[0][1] == ch && gameBoard[1][1] == ch & gameBoard[2][1] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }
    else if(gameBoard[0][2] == ch && gameBoard[1][2] == ch & gameBoard[2][2] == ch)
    {
        gotoxy(x,y+13); printf("\a\t Player %c is winner!!", ch);
        status = 1;
    }

    return status;
}

void tic_help()
{
    structure(); gotoxy(30,4); printf("- TIC TAC TOI GAME -"); fflush(stdin);
    fflush(stdin);
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    gotoxy(27,6); printf("How to win at Tic Tac Toe");
    gotoxy(7,8); printf("Tic Tac Toe, also known as  \"Noughts  and  Crosses\" or \"X's and");
    gotoxy(7,9); printf("O's\", is  a  solved   game.  This   means  there  is  a  known,");
    gotoxy(7,10); printf("mathematically  proven  strategy to  follow for the best result");
    gotoxy(7,11); printf("each game.  In Tic Tac Toe,  two players who  follow the  right");
    gotoxy(7,12); printf("strategy will always tie, with neither player winning.  Against");
    gotoxy(7,13); printf("an  opponent who doesn't know this  strategy, however,  you can");
    gotoxy(7,14); printf("still  win  whenever they  make a  mistake.  Once your  friends");
    gotoxy(7,15); printf("pick up on  your strategy, try a more  difficult version of the");
    gotoxy(7,16); printf("rules.");
    gotoxy(24,18); printf("Press any key to play the game.....");
    switch(getch())
    {
    case 116:
        noyon();
        tictactoigame();
        break;
    case 84:
        noyon();
        tictactoigame();
        break;
    case 104:
        help_fun();
        break;
    case 72:
        help_fun();
        break;
    case 8:
        mainmenu();
        break;
    case 27:
        mainmenu();
        break;
    default:
        tictactoigame();
        break;
    }
}
//**************************** end tic tac toi game *****************************//
//************************** Basic All Function ********************************//

void help_fun()
{
    fflush(stdin);
    structure(); gotoxy(30,4); printf("- MAIN MENU HELP -");
    gotoxy(5,3); printf("Help(H)");
    gotoxy(62,3); printf("AboutNoyon(T)");
    gotoxy(5,21); printf("Back(BackSpace)");
    gotoxy(66,21); printf("Exit(Esc)");
    gotoxy(27,6); printf("GAME INSTRUCTIONS & HELP");
    gotoxy(7,8); printf("In  this  game you can  play  three  types of  different  games.");
    gotoxy(7,9); printf("One of  the Quiz game another one is  the Snake game and another");
    gotoxy(7,10); printf("one is the TIC TOC TOE game.");
    gotoxy(7,12); printf("-> In  this  gaming  software  you can back every time by using");
    gotoxy(7,13); printf("   BackSpace");
    gotoxy(7,14); printf("-> You can get help by using H or h.");
    gotoxy(7,15); printf("-> You can get creator information by using SpaceBar.");
    gotoxy(7,16); printf("-> You can also Exit every-time by using Esc.");
    gotoxy(24,18); printf("Press any key to continue.....");
    switch(getch())
    {
    case 116:
        noyon();
        mainmenu();
        break;
    case 84:
        noyon();
        mainmenu();
        break;
    case 104:
        help_fun();
        break;
    case 72:
        help_fun();
        break;
    case 8:
        mainmenu();
        break;
    case 27:
        mainmenu();
        break;
    default:
        mainmenu();
        break;
    }
}
void structure()
{
    system("cls");fflush(stdin);
    int y=5; gotoxy(37,2); printf("NOYON");
    gotoxy(5,4); for(i=0;i<70;i++) printf("%c", c);
    for(i=0;i<15;i++){ gotoxy(5,y+i); printf("%c", c);}
    for(i=0;i<15;i++){ gotoxy(74,y+i); printf("%c", c);}
    gotoxy(5,20); for(i=0;i<70;i++) printf("%c", c);
    fflush(stdin);
}

void noyon()
{
    system("cls"); fflush(stdin);
    int x =22;
    gotoxy(x,5);
    printf("Md. Mohaymenul Islam (NOYON)");
    gotoxy(x,7);
    printf("Id \t : 133-35-535");
    gotoxy(x,9);
    printf("Batch \t : 12");
    gotoxy(x,11);
    printf("Department : SWE");
    gotoxy(x,13);
    printf("Mobile \t : 01681-246187");
    gotoxy(x,15);
    printf("HomeTown   : Rajshahi");
    getch();
}

void exit_fun()
{
    structure(); gotoxy(35,4); printf("- EXIT -"); fflush(stdin);
    gotoxy(30,11); printf("THANK YOU %s!!!", name);
    getch();
    system("cls");
    gotoxy(0,0);
    printf("Product by Md. Mohaymenul Islam (NOYON)");exit(0);
}
void delay(unsigned int mseconds)
{
    fflush(stdin);
    clock_t goal = mseconds + clock();
    while (goal > clock());
    fflush(stdin);
}
void gotoxy(int x, int y)
{
    fflush(stdin);
    coord.X=x;  coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


