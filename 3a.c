  #include <stdio.h>

// Define a union named 'Data' that can hold an integer, float, and character
union Data {
    int integer;
    float floating;
    char character;
};

int main() {
    union Data data;

    // Accept input for an integer value
    printf("Enter an integer value: ");
    scanf("%d", &data.integer);

    // Accept input for a float value
    printf("Enter a float value: ");
    scanf("%f", &data.floating);

    // Accept input for a character value
    printf("Enter a character value: ");
    scanf(" %c", &data.character);

    // Display the values stored in the union
    printf("\nValues stored in the union:\n");
    printf("Integer value: %d\n", data.integer);
    printf("Float value: %f\n", data.floating);
    printf("Character value: %c\n", data.character);

    return 0;
}



Result:
This program demonstrates the use of a union by accepting input values for an integer, a float, and a character, storing them in the union, and displaying them. Since a union can only hold one value at a time, storing a new value will overwrite the previous value












Department of Computer Science and Engineering, Rajalakshmi Engineering College
 

Ex. No.:3.b	Date:
Union For Representing Different Shapes (circle, square, rectangle)
Develop a program that defines a union for representing different shapes (circle, square, rectangle) with appropriate fields for each. Implement functions to:
Calculate and display the area of each shape. Determine and print the largest area among the shapes.
Input Format
Enter the number of shapes: 3 Enter type of shape (0 for circle, 1
for square, 2 for rectangle) for shape 1: 0
Enter radius of circle: 33
Enter type of shape (0 for circle, 1 for square, 2 for rectangle) for shape 2: 2
Enter length and width of rectangle: 45 67
Enter type of shape (0 for circle, 1 for square, 2 for rectangle) for shape 3: 1
Enter side length of square: 23
Output Format
Areas of shapes:
Area of circle 1: 3421.19
Area of square 2: 2025.00
Area of rectangle 3: 0.00
Largest area among the shapes: 3421.19

Aim:

To develop a program that defines a union for representing different shapes (circle, square, rectangle) and implements functions to calculate and display the area of each shape, as well as determine and print the largest area among the shapes:

Algorithm:
1.	Start
2.	Define a union named Shape with appropriate fields for representing different shapes:
•	For a circle, include a field for radius.
•	For a square, include a field for side length.
•	For a rectangle, include fields for length and width.
3.	Define a structure named Circle with a field for the radius.
4.	Define a structure named Square with a field for the side length.
5.	Define a structure named Rectangle with fields for the length and width.
6.	Define a function calculateArea that takes a union Shape as input and returns the calculated area based on the type of shape (circle, square, or rectangle).
7.	Define a function displayAreas that takes an array of unions shapes and its size as input, calculates and displays the area of each shape.
8.	Define a function findLargestArea that takes an array of unions shapes and its size as input, determines the largest area among the shapes, and returns it.
9.	In the main function: a.  the user to enter the number of shapes. b. Dynamically allocate memory to store the shapes. c. Read details for each shape: - For a circle, prompt the user to enter the radius. - For a square, prompt the user to enter the side length. - For a rectangle, prompt the user to enter the length and width. d. Calculate and display the area of each shape using the displayAreas function. e. Determine and print the largest area among the shapes using the findLargestArea function. f. Free dynamically allocated memory.
10.	End.

Department of Computer Science and Engineering, Rajalakshmi Engineering College
 


Program:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for shape types
#define CIRCLE 0
#define SQUARE 1
#define RECTANGLE 2

// Define a structure for a circle
struct Circle {
    double radius;
};

// Define a structure for a square
struct Square {
    double sideLength;
};

// Define a structure for a rectangle
struct Rectangle {
    double length;
    double width;
};
// Define a union for representing different shapes
union Shape {
    struct Circle circle;
    struct Square square;
    struct Rectangle rectangle;
};

// Function to calculate the area of a circle
double calculateCircleArea(struct Circle c) {
    return M_PI * c.radius * c.radius;
}

// Function to calculate the area of a square
double calculateSquareArea(struct Square s) {
    return s.sideLength * s.sideLength;
}
// Function to calculate the area of a rectangle
double calculateRectangleArea(struct Rectangle r) {
    return r.length * r.width;
}


Department of Computer Science and Engineering, Rajalakshmi Engineering College
 

Program



// Function to calculate and display the area of each shape
void displayAreas(union Shape shapes[], int numShapes) {
    printf("Areas of shapes:\n");
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                printf("Area of circle %d: %.2f\n", i + 1, area);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                printf("Area of square %d: %.2f\n", i + 1, area);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                printf("Area of rectangle %d: %.2f\n", i + 1, area);
                break;
        }
    }
}

// Function to find the largest area among the shapes
double findLargestArea(union Shape shapes[], int numShapes) {
    double largestArea = 0.0;
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                break;
        }
        if (area > largestArea) {
            largestArea = area;
        }
    }
    return largestArea;
}

  Department of Computer Science and Engineering, Rajalakshmi Engineering College



 

                          int main() {
    int numShapes;

    // the user to enter the number of shapes
    printf("Enter the number of shapes: ");
    scanf("%d", &numShapes);

    // Dynamically allocate memory to store the shapes
    union Shape* shapes = (union Shape*)malloc(numShapes * sizeof(union Shape));
    if (shapes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read details for each shape
    for (int i = 0; i < numShapes; i++) {
        int shapeType;
        printf("Enter type of shape (0 for circle, 1 for square, 2 for rectangle) for shape %d: ", i + 1);
        scanf("%d", &shapeType);
        switch (shapeType) {
            case CIRCLE:
                printf("Enter radius of circle: ");
                scanf("%lf", &shapes[i].circle.radius);
                break;
            case SQUARE:
                printf("Enter side length of square: ");
                scanf("%lf", &shapes[i].square.sideLength);
                break;
            case RECTANGLE:
                printf("Enter length and width of rectangle: ");
                scanf("%lf %lf", &shapes[i].rectangle.length, &shapes[i].rectangle.width);
                break;
            default:
                printf("Invalid shape type\n");
                free(shapes);
                return 1;
        }
    }
    // Display the area of each shape
    displayAreas(shapes, numShapes);

    // Find and print the largest area among the shapes
    double largestArea = findLargestArea(shapes, numShapes);
    printf("\nLargest area among the shapes: %.2f\n", largestArea);

    // Free dynamically allocated memory
    free(shapes);

    return 0;
}
