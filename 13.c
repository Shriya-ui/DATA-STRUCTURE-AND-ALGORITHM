#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[100];
    int size;
} Snake;

void init_snake(Snake* snake) {
    snake->size = 1;
    snake->points[0].x = WIDTH / 2;
    snake->points[0].y = HEIGHT / 2;
}

void print_board(char board[HEIGHT][WIDTH], Snake snake) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int is_snake = 0;
            for (int k = 0; k < snake.size; k++) {
                if (snake.points[k].x == j && snake.points[k].y == i) {
                    is_snake = 1;
                    break;
                }
            }
            if (is_snake) {
                printf("S ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Snake snake;
    init_snake(&snake);

    char board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '.';
        }
    }

    while (1) {
        print_board(board, snake);
        // Add game logic here to move the snake and check for collisions
        // For now, just exit after printing the board
        break;
    }

    return 0;
}

//sudoku
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0 && j < SIZE - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < SIZE - 1) {
            printf("---------------------\n");
        }
    }
}

int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    // Check the row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check the column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check the 3x3 box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_row + i][start_col + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int board[SIZE][SIZE], int row, int col) {
    if (row == SIZE - 1 && col == SIZE) {
        return 1;
    }

    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (board[row][col] > 0) {
        return solve_sudoku(board, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve_sudoku(board, 0, 0)) {
        print_board(board);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}
//travel planner
#include <stdio.h>
#include <string.h>

#define MAX_DESTINATIONS 10
#define MAX_DAYS 7

typedef struct {
    char name[50];
    int duration; // in days
} Destination;

typedef struct {
    Destination destinations[MAX_DESTINATIONS];
    int num_destinations;
    int days[MAX_DAYS];
} TravelPlan;

void add_destination(TravelPlan* plan, char* name, int duration) {
    if (plan->num_destinations < MAX_DESTINATIONS) {
        strcpy(plan->destinations[plan->num_destinations].name, name);
        plan->destinations[plan->num_destinations].duration = duration;
        plan->num_destinations++;
    } else {
        printf("Maximum destinations reached!\n");
    }
}

void plan_trip(TravelPlan* plan) {
    int total_days = 0;
    for (int i = 0; i < plan->num_destinations; i++) {
        total_days += plan->destinations[i].duration;
    }

    if (total_days <= MAX_DAYS) {
        printf("Travel Plan:\n");
        for (int i = 0; i < plan->num_destinations; i++) {
            printf("Day %d-%d: %s\n", total_days - plan->destinations[i].duration + 1, total_days, plan->destinations[i].name);
            total_days -= plan->destinations[i].duration;
        }
    } else {
        printf("Trip duration exceeds maximum days!\n");
    }
}

int main() {
    TravelPlan plan;
    plan.num_destinations = 0;

    add_destination(&plan, "Paris", 3);
    add_destination(&plan, "Rome", 2);
    add_destination(&plan, "Barcelona", 4);

    plan_trip(&plan);

    return 0;
}
//cash flow minimiser
#include <stdio.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    int amount;
    int day;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    int cash_flow[MAX_TRANSACTIONS];
} CashFlow;

void add_transaction(CashFlow* cash_flow, char* description, int amount, int day) {
    if (cash_flow->num_transactions < MAX_TRANSACTIONS) {
        strcpy(cash_flow->transactions[cash_flow->num_transactions].description, description);
        cash_flow->transactions[cash_flow->num_transactions].amount = amount;
        cash_flow->transactions[cash_flow->num_transactions].day = day;
        cash_flow->num_transactions++;
    } else {
        printf("Maximum transactions reached!\n");
    }
}

void calculate_cash_flow(CashFlow* cash_flow) {
    int total_cash = 0;
    for (int i = 0; i < cash_flow->num_transactions; i++) {
        total_cash += cash_flow->transactions[i].amount;
        cash_flow->cash_flow[i] = total_cash;
    }
}

void minimize_cash_flow(CashFlow* cash_flow) {
    int min_cash_flow = cash_flow->cash_flow[0];
    int min_day = 0;
    for (int i = 1; i < cash_flow->num_transactions; i++) {
        if (cash_flow->cash_flow[i] < min_cash_flow) {
            min_cash_flow = cash_flow->cash_flow[i];
            min_day = i;
        }
    }
    printf("Minimum cash flow: %d on day %d\n", min_cash_flow, cash_flow->transactions[min_day].day);
}

int main() {
    CashFlow cash_flow;
    cash_flow.num_transactions = 0;

    add_transaction(&cash_flow, "Initial deposit", 1000, 1);
    add_transaction(&cash_flow, "Withdrawal", -500, 3);
    add_transaction(&cash_flow, "Deposit", 200, 5);
    add_transaction(&cash_flow, "Withdrawal", -300, 7);

    calculate_cash_flow(&cash_flow);
    minimize_cash_flow(&cash_flow);

    return 0;
}
