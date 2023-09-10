// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************

//Include necessary libraries
#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <math.h>

//Picopad specific libraries
#include "picopad_fonts.h"
#include "picopad_init.h"
#include "picopad_key.h"
#include "sdk_watchdog.h"
#include "main.h"

//Graphics and display libraries
#include "lib_drawtft.h"
#include "st7789.h"

//Sound libraries
#include "lib_pwmsnd.h"

//Structure to hold the node (each point) of the snake
typedef struct Node{
short x;
short y;
struct Node *next;
}
Node;

//The head of the snake
Node *head = NULL;

//The arry to hold x/y-coordinates of the food
short food[2];
static char direction = KEY_RIGHT;
char alive = 1;
volatile char reset = 1;

//Function to generate a random number between min and max
inline int randomRange(int min, int max){
    return (rand() % (max - min)) + min;
}

// Draw a rectangle for food
void drawRect(short x, short y, short width, short height, uint16_t color) {
    for (short i = y; i < y + height; i++) {
        for (short j = x; j < x + width; j++) {
            DrawPoint(j, i, color);
        }
    }
}

//Function to swap two shorts
void swap(short *x, short *y){
    if(*x != *y){
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

 //The function to generate the food
void genFood(){
genAgain:
    //Generate food for the x-axis
    food[0] = randomRange(0, WIDTH_SNAKE);
    //Generate food for the y-axis
    food[1] = randomRange(5, HEIGHT_SNAKE);
    Node *current = head;
    current = current->next;
    while(current != NULL){ 
        if(food[0] == current->x && food[1] == current->y){
            goto genAgain;
        }
        current = current->next;
    }
    //Draw rectangle for food
    drawRect(food[0] << 2, food[1] << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BLACK);
}

//Function to add a new node for the snake
void addNode(short x, short y){
    if(head == NULL){
        head = (Node *)malloc(sizeof(Node));
        head->x = x;
        head->y = y;
        head->next = NULL;
        drawRect(x << 2, y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BLACK);
    }
    else{
        Node *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (Node *)malloc(sizeof(Node));
        current->next->x = x;
        current->next->y = y;
        current->next->next = NULL;
        //Draw a green rectangle for the list
        drawRect(x << 2, y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BODY);
    }
}

//Function for Pause display
void drawPause(int pause) {
    if (pause) {
        SelFont6x8();
        DrawText2("Pause", 235, 3, COL_BLACK);
    } else {
        DrawText2("Pause", 235, 3, COL_BACKGROUND);
    }
}

//Function for score display
void drawScore(int score) {
    SelFont6x8();
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    DrawText2(scoreText, 30, 3, COL_BLACK);
}

//Function to move the snake such that the new coordinates of the head are x, y
void move(short x, short y){
    drawRect(x << 2, y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BLACK);
    Node *current = head;
    while(current != NULL){
        //Draw the new snake body
        drawRect(current->x << 2, current->y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BODY);
        //Swap the coordinates and the current node coordinates
        swap(&(current->x), &x);
        swap(&(current->y), &y);
        current = current->next;
        if(current != NULL){
            if(current->x == head->x && current->y == head->y){
                alive = 0;
                //Draw the head one last time
                drawRect(head->x << 2, head->y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BLACK);
                break;
            }
        }
    }
    //Clear the oldest element
    drawRect(x << 2, y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BACKGROUND);
}

//Function to eat the food and still move by increasing the length of the snake
void eatAndMove(short x, short y){
    //Play sound
    PLAYSOUND(eatSnd);
    VolumeSound(3);
    //Draw the new head
    drawRect(x << 2, y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BLACK);
    Node *current = head;
    while(current->next != NULL){
        //Draw the new snake body
        drawRect(current->x << 2, current->y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BODY);
        //Swap the coordinates and the current node coordinates
        swap(&(current->x), &x);
        swap(&(current->y), &y);
        current = current->next;
    }
     //Allocate new memory for the next node
    current->next = (Node *)malloc(sizeof(Node));
    //Draw the new snake body
    drawRect(current->x << 2, current->y << 2, SNAKE_SIZE, SNAKE_SIZE, COL_BODY);
    //Swap the coordinates and the current node coordinates
    swap(&(current->x), &x);
    swap(&(current->y), &y);
    current = current->next;
    current->x = x;
    current->y = y;
    current->next = NULL;
}

//The function to move UP
void moveUp(){
    if(head->x == food[0] && head->y == food[1]){
        //Increases the score by one point and updates it
        score++;
        DrawClear(COL_BACKGROUND);
        DrawLine (20, 22, 305, 22, COL_BLACK);
        DrawLine (20, 23, 305, 23, COL_BLACK); 
        drawScore(score);
        if(head->y == SCORE_AREA){
            //The snake hit the edge
            alive = 0;
            return;
        }
        eatAndMove(head->x, head->y - 1);
        genFood();
    }
    else{
        if(head->y == SCORE_AREA){
            //The snake hit the edge
            alive = 0;
            return;
        }
        move(head->x, head->y - 1);
    }
}

//The function to move DOWN
void moveDown(){
    if(head->x == food[0] && head->y == food[1]){
        //Increases the score by one point and updates it
        score++;
        DrawClear(COL_BACKGROUND);
        DrawLine (20, 22, 305, 22, COL_BLACK);
        DrawLine (20, 23, 305, 23, COL_BLACK); 
        drawScore(score);
        if(head->y == HEIGHT_SNAKE - 1){
            //The snake hit the edge
            alive = 0;
            return;
        }
        eatAndMove(head->x, head->y + 1);
        genFood();
    }
    else{
        if(head->y == HEIGHT_SNAKE - 1){
            //The snake hit the edge            
            alive = 0;
            return;
        }
        move(head->x, head->y + 1);
    }
}

//The function to move LEFT
void moveLeft(){
    if(head->x == food[0] && head->y == food[1]){
        //Increases the score by one point and updates it
        score++;
        DrawClear(COL_BACKGROUND);
        DrawLine (20, 22, 305, 22, COL_BLACK);
        DrawLine (20, 23, 305, 23, COL_BLACK); 
        drawScore(score);
        if(head->x == 0){
            //The snake hit the edge            
            alive = 0;
            return;
        }
        eatAndMove(head->x - 1, head->y);
        genFood();
    }
    else{
        if(head->x == 0){
            //The snake hit the edge            
            alive = 0;
            return;
        }
        move(head->x - 1, head->y);
    }
}

//The function to move RIGHT
void moveRight(){ 
    if(head->x == food[0] && head->y == food[1]){
        //Increases the score by one point and updates it
        score++;
        DrawClear(COL_BACKGROUND);
        DrawLine (20, 22, 305, 22, COL_BLACK);
        DrawLine (20, 23, 305, 23, COL_BLACK); 
        drawScore(score);
        if(head->x == WIDTH_SNAKE - 1){
            //The snake hit the edge            
            alive = 0;
            return;
        }
        eatAndMove(head->x + 1, head->y);
        genFood();
    }
    else{
        if(head->x == WIDTH_SNAKE - 1){
            //The snake hit the edge            
            alive = 0;
            return;
        }
        move(head->x + 1, head->y);
    }
}

//The change direction interrupt handler
void changeDir(char key) {
    if(alive){
        switch(key){
            case KEY_UP: direction = (direction == KEY_DOWN ? KEY_DOWN : KEY_UP);
                         break;
            case KEY_DOWN: direction = (direction == KEY_UP ? KEY_UP : KEY_DOWN);
                           break;
            case KEY_LEFT: direction = (direction == KEY_RIGHT ? KEY_RIGHT : KEY_LEFT);
                           break;
            case KEY_RIGHT: direction = (direction == KEY_LEFT ? KEY_LEFT : KEY_RIGHT);
                            break;
            default: break;
        }
    }
    else{
        reset = 1;
    }
}

int main() {
    DeviceInit();
    char ch = KEY_RIGHT;
    
    //An interator
    short i;
    
    //Random seed
    srand(1);
	
    while(True){
        if(reset){
            //Clear the display and draw score line (the upper limit of the snake's movement)
    		DrawClear(COL_BACKGROUND);
            DrawLine (20, 22, 305, 22, COL_BLACK);
            DrawLine (20, 23, 305, 23, COL_BLACK); 
            
            //Set the score to 0 when the game start
            score = 0;
            
            //Resurrect the snake
            alive = 1;

            //Clear the linked list
            Node *tmp;
            while(head != NULL){
                tmp = head;
                head = head->next;
                free(tmp);
            }
            //Create the snake
            for(i = 0; i < 8; i++){
                addNode((WIDTH_SNAKE / 2) - i, HEIGHT_SNAKE / 2);
            }
            
            //Set default direction to be RIGHT
            direction = KEY_RIGHT;
            
            //Generate food
            genFood();
            
            //Clear the reset flag
            reset = 0;
        }
        while(alive){
            absolute_time_t current_time = get_absolute_time();
            uint64_t current_time_ms = to_us_since_boot(current_time) / 1000;
            unsigned long begin_time = (unsigned long)current_time_ms;
			
            //Prints the score
            drawScore(score);
            
            ch = KeyGet();
			if (ch == KEY_Y) {
				ResetToBootLoader();
			}
			changeDir(ch);
            
            if (!pause) {
                 switch(direction){
                    case KEY_UP: moveUp();
                                break;
                    case KEY_DOWN: moveDown();
                                break;
                    case KEY_LEFT: moveLeft();
                                break;
                    case KEY_RIGHT: moveRight();
                                break;
                    default: break;
                }
            }
            if (ch == KEY_A) {
                pause = !pause;
                drawPause(pause);
            }

			DispUpdate();
			sleep_ms(55 - ((unsigned long)current_time_ms - begin_time));
            
            // Check if the head of the snake hits the screen edge
            if (head->x < 0 || head->x >= WIDTH_SNAKE || head->y < SCORE_AREA) {
                //Game over
                alive = 0;
            }
        }
			
        // Clear the display
        DrawClear(COL_BACKGROUND);
        
        //Play dead sound
        PLAYSOUND(deadSnd);
        VolumeSound(3);
        
        // Draw the message to restart or quit
        DrawImgRle(DeadpictImg_RLE, DeadpictImg_Pal, 0, 0, 320, 240);
        DispUpdate();
        
        // Wait for user input to restart or quit
        while (1) {
            ch = KeyGet();
            if (ch == KEY_X) {
                StopSound();
                // Game reset
                reset = 1;
                break;
            } else if (ch == KEY_Y) {
                ResetToBootLoader();
                // Exit game
                alive = 0;
                break;
            }
        }
        DispUpdate();
    }
}