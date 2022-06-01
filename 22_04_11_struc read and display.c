 #include<stdio.h>
 struct cric_player
 {
     char player_name[100];
     int score;
 };
 struct cric_player read(struct cric_player p1)
 {
     printf("enetr player name\n");
     scanf("%s",p1.player_name);
     printf("enter score\n");
     scanf("%d",&p1.score);
     return p1;
 }
 void display(struct cric_player p1)
 {
  printf("%s\n",p1.player_name) ;
  printf("%d\n",p1.score) ;
 }
 main()
 {
     struct cric_player p1;
     p1=read(p1);
     display(p1);
 }
