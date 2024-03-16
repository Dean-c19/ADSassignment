#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Preprocessor Variable
#define MAX_CARS 5


//Stucture for car part of the linked list
struct Car{
    char registration[8];
    char makeAndModel[50];
    char colour[20];
    int previousOwners;
    bool reserved;
    float reservedAmount;
    struct Car* next;


};


//function prototypes
void menu(struct Car** front);
void AddACar(struct Car** front);
void SellACar(struct Car** front);
void ReserveOrUnreserveACar(struct Car** front);
void ViewAllCars(struct Car** front);
void ViewSpecificCar(struct Car** front);
void myTask(struct Car** front);
void ExitTheSystem(struct Car** front);
int carCounter(struct Car* front);
bool isUniqueRegistration(struct Car* front, const char* registration);



int main()
{
    struct Car* front = NULL;
     menu(&front);
    
    return 0;
    }

void menu(struct Car** front){
 int ans;
    
    do {
    printf("Menu:\n");
    printf("1. Add a new car to the showroom\n");
    printf("2. Sell a car from the showroom\n");
    printf("3. Reserve/Unreserve a car in the showroom\n");
    printf("4. View all cars in the showroom ");
    printf("5. View a specific car in the showroom\n");
    printf("6. This should be an appropriate option that you provide\n");
    printf("7. Exit the system\n");
    scanf("%d", &ans);
    
    switch(ans)
    {
        case 1:
            AddACar(front);
            break;
        case 2:
             SellACar(front);
            break;
        case 3:
             ReserveOrUnreserveACar(front);
            break;
            case 4:
           ViewAllCars(front);
            break;
        case 5:
             ViewSpecificCar(front);
            break;
        case 6:
             myTask(front);
            break;
            case 7:
             ExitTheSystem(front);
            break;
        default:
            printf("Error, please pick an option between 1 and 7\n");
            break;
    }
   
}while (ans != 7);// do while to loop through the menuu until the 7 is inputted to exti the porgram
    

}
// Code for adding a new car to the showroom
void AddACar(struct Car** front)
{
    // create space for a new car
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
//checks if the showroom is full
    if (carCounter(*front) >= MAX_CARS) {
        printf("Error Showroom full\n");
        return;
    }
 

    printf("Input the cars registration in the format yyDxnnnn): \n");
    scanf("%s", newCar->registration);
    printf("Input car make and model: \n");
    scanf("%s", newCar->makeAndModel);
    printf("Input car colour: \n");
    scanf("%s", newCar->colour);
    printf("Input the amount of previous owners: \n");
    scanf("%d", &newCar->previousOwners);
    if (newCar->previousOwners > 3) {
        printf("Error the amount of previous owners cant be more than 3\n");
        free(newCar); // gets rid of the memory allocated for that car 
        return;
    }
    printf("Is this car reserved please input 1 for yes 0 for no: \n");
    scanf("%d", &newCar->reserved);
    if (newCar->reserved) {
        printf("Input reserved amount: \n");
        scanf("%f", &newCar->reservedAmount);
    } else {
        newCar->reservedAmount = 0;
    }

    newCar->next = *front;
    *front = newCar;
    

   



}

void SellACar(struct Car** front)
{
    // Code for selling a car from the showroom
}

void ReserveOrUnreserveACar(struct Car** front)
{
    // Code for reserving/unreserving a car in the showroom
}

void ViewAllCars(struct Car** front)
{
    // Code for viewing all cars in the showroom
    printf("\nCars in the showroom:\n");
    struct Car* current = *front; // start at the front of the list
    while (current != NULL) {
        printf("Registration: %s\n", current->registration);
        printf("Make and Model: %s\n", current->makeAndModel);
        printf("Colour: %s\n", current->colour);
        printf("Previous Owners: %d\n", current->previousOwners);
        printf("Reserved: %s\n", current->reserved ? "Yes" : "No");
        if (current->reserved) {
            printf("Reserve Amount: %.2f\n", current->reservedAmount);
        }
        printf("\n");
        current = current->next;
    }
}

void ViewSpecificCar(struct Car** front)
{
    // Code for viewing a specific car in the showroom
}

void myTask(struct Car** front)
{
    // Code for my task 
}

void ExitTheSystem(struct Car** front)
{
    // Code for exiting the system
    printf("Bye!!\n");
    exit(0);
}
    //method to count the cars in the showroom
int carCounter(struct Car* front) {
    int count = 0;
    struct Car* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//methid to check if the registration is unique
bool isUniqueRegistration(struct Car* front, const char* registration) {
    struct Car* current = front;
    while (current != NULL) {
        if (strcmp(current->registration, registration) == 0) {
            return false; // returns false if registration already exists
        }
        current = current->next;
    }
    return true; // returns true if registration is unique
}