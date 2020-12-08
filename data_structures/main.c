#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./linked_list.h"
#include "./stack.h"

void handle_input(char);

// make this run all the data structures tests in a CLI
int main(void)
{
  /*char user_choice[2];*/
  char user_choice;

  while(1)
  {
    printf("\nChoose which Data Structure Test to Run: \n"); 
    printf("-----------------------------------\n"); 
    printf("A) Singly Linked List\n");
    printf("B) Doubly Linked List\n");
    printf("C) Stack\n");
    printf("D) Queue\n");

    printf("\nWhat is your choice?(q to quit): ");

    /*fgets(user_choice, sizeof(user_choice), stdin);*/
    scanf("%c", &user_choice);
    /*strtok(user_choice, " ");*/
    /*if(!strcmp(user_choice, "q") || !strcmp(user_choice, "Q"))*/
    if(user_choice == 'q' || user_choice == 'Q')
      break;

    handle_input(user_choice);
  }


  return EXIT_SUCCESS;
}



void handle_input(char user_choice)
{
  if(user_choice == 'A')
  {
    printf("\n------------- Linked List ----------------------");
    linked_list();
    printf("\n--------------------------------------------\n");
  }
  else if(user_choice == 'C')
  {

    printf("\n------------- Stack ---------------------");
    stack();
    printf("\n--------------------------------------------\n");
  }
  else{
    printf("\n\nChoice not valid...\n\n");
  }
}
