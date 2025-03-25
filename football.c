//EECS 348 Lab 7 - Part 1
//Takes score and finds possible scoring combinations for that number
//Inputs: Integer from the user
//Outputs: All possible scoring combinations in a football game for that number
//Myself, ChatGPT
//Joey Ippolito, 3114450
// 3/24/2025
#include <stdio.h>

void scorefinder(int score){ //Creates function to find score
    for (int td_2=0; td_2*8<=score; td_2++){ //for loop for TDs with 2 point conversion. String of for loops starts with biggest scoring play and goes down
        for (int td_1=0; td_1*7+td_2*8<=score; td_1++){ //loop for TDS with extra point.
            for (int td=0; td*6+td_1*7+td_2*8<=score; td++){ //loop for TDs with no extra point
                for (int fg=0; fg*3+td*6+td_1*7+td_2*8<=score; fg++){ //loop for field goals
                    for (int safety=0; safety*2+fg*3+td*6+td_1*7+td_2*8<=score; safety++){  //loop for safeties. All loops have a condition that the score must be less than or equal to the inputted score
                        if (td_2*8+td_1*7+td*6+fg*3+safety*2==score){   //checks if sum of all scoring plays equals inputted score
                            printf("%d TD+2pt, %d TD+1pt, %d TD, %d Field Goal,  %d Safety\n", td_2, td_1, td, fg, safety); //prints out the scoring plays
                        }
                    }
                }
            }
        }
        }
    }


int main(){     //initializes main 
    int score;  //initializes score

    while (1){      //while loop to ask for input until user manually exits or inputs invalid score
        printf("Enter a 1 or 0 to stop.\n"); //instructs how to terminate program
        printf("Enter the NFL score: ");  //asks for input
        scanf("%d", &score);    //scans input
        if (score<=1){  //checks for valid input
            printf("Invalid score\n");  //prints invalid score
            break;  //breaks while loop
        }
        printf("Possible scoring combinations for %d:\n", score); //prints out possible scoring combinations
        scorefinder(score); //calls scorefinder function
    }  
    return 0;   
    }
