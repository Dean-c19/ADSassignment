#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//preprocessor Variable
#define MAX_CARS 5


//stucture for car part of the linked list
typedef struct Car{
    char registration[9];
    char makeAndModel[50];
    char colour[20];
    int previousOwners;
    bool reserved;
    float reservedAmount;
}Car;

typedef struct Node{
    struct Car* car;
    struct Node* next;
}Node;


//function prototypes
void menu(Node* front);
void AddACar(Node* front);
void SellACar(Node* front);
void ReserveOrUnreserveACar(Node* front);
void ViewAllCars(Node* front);
void ViewSpecificCar(Node* front);
void myTask(Node* front);
void ExitTheSystem(Node* front);
int carCounter(Node* front);
bool isUniqueRegistration(Node* front, const char* registration);



int main()
{
    Node* front = malloc(sizeof(Node));
    front->car = NULL;
    front->next = NULL;

    fflush(stdin);
     menu(front); // call menu method
    
    return 0;
    }

void menu(Node* front){
 int ans;
    
    do {
        printf("Menu:\n");
        printf("1. Add a new car to the showroom\n");
        printf("2. Sell a car from the showroom\n");
        printf("3. Reserve/Unreserve a car in the showroom\n");
        printf("4. View all cars in the showroom\n");
        printf("5. View a specific car in the showroom\n");
        printf("6. Respray a car\n");
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

void addNode(Node* front, Car* newCar) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->car = newCar;
    newNode->next = front;

    front = newNode;
}

// code for adding a new car to the showroom
void AddACar(Node* front)
{
    // create space for a new car
    Car* newCar = (Car*)malloc(sizeof(Car));
    addNode(front, newCar);
//checks if the showroom is full
    if (carCounter(front) >= MAX_CARS) {
        printf("Error, showroom full\n");
        return;
    }
 

    printf("Input the cars registration in the format yyDxnnnn : \n");
    scanf("%8s", newCar->registration);

    //use ctype.h to check if the registration is in the right format
    if (strlen(newCar->registration) != 8 // if statement that uses string length to check if the registration is 8 characters long
        || !isdigit(newCar->registration[0]) || !isdigit(newCar->registration[1])
        || (newCar->registration[0] - '0') * 10 + (newCar->registration[1] - '0') < 14
        || (newCar->registration[0] - '0') * 10 + (newCar->registration[1] - '0') > 24
        || newCar->registration[2] != 'D'
        || (newCar->registration[3] != '1' && newCar->registration[3] != '2')
        || !isdigit(newCar->registration[4]) || !isdigit(newCar->registration[5])
        || !isdigit(newCar->registration[6]) || !isdigit(newCar->registration[7])) {
        printf("Error, the registration format is not yyDxnnnn\n");
        free(newCar); // delete allocated memory since the registration is not in the right format
        return;
    }

    
    
    
    if (!isUniqueRegistration(front, newCar->registration)) {// implements the isUniqueRegistration method to check if the registration is unique or not 
        printf("Error, this registration already exists\n");
        free(newCar); // gets rid of the memory allocated for that car 
        return;
    }
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
    printf("Is this car reserved please input 1 for yes 0 for no: \n"); // boolean to check if the car is reserved or not
    scanf("%d", &newCar->reserved);
    if (newCar->reserved) { // if 1 is inputted then the user will be able to input the reserved amount
        printf("Input reserved amount: \n");
        scanf("%f", &newCar->reservedAmount);
    } else {
        newCar->reservedAmount = 0; // reserved amount is set to 0 if the car is not reserved
    }   
}

void SellACar(Node* front)
{
    
    // Check if the showroom is empty
    if (front == NULL) {
        printf("Error, showroom is empty\n");
        return;
    }   
      
      

    Node* current = front;
    Node* previous = NULL;
    char registration[9]; // this stores the registration of the car that the user wants to sell
    printf ("Input the registration of the car you want to sell: \n");
    scanf("%s", registration);
      

    // search throught the list to find the car with that registration
    while (current != NULL && strcmp(current->car->registration, registration) != 0) { // sting compare to check if the registration is the same as the one put in by the user
        previous = current; 
        current = current->next; 
    }

    // iff the car is not found 
    if (current == NULL) {
        printf("Error, Car with the registration %s was not found in the showroom\n", registration);
        return;
    }

    // if the car is reserved find and delete it from the list 
    if (current->car->reserved) { // check if the car is reserved or not 
       
        if (previous == NULL) { // if the car that has to be sold and it is the first one in the list
            front = current->next;
        } else { 
            previous->next = current->next; // if the car that has to be sold is not the first one in the list
        }
        printf("Car with the registration %s has been sold.\n", registration);
        free(current); // get rid of the memory allocated for that car
    } else { // if the car is not reserved error message comes up 
        printf("Error, car with registration %s hasnt been reserved so it cant be sold \n", registration);
    }
}

    


void ReserveOrUnreserveACar(Node* front)
{
    // Code for reserving or unreserving a car in the showroom
    // Check if the showroom is empty
    if (front == NULL) {
        printf("Error, Showroom is empty \n");
        return;
    }

    Node* current = front;
    char registration[9]; // this stores the registration of the car that the user wants to reserve or unreserve
    
    
    int resOrUnres; // variable so that the user can input 1 to reserve a car and 2 to unreserve a car
    printf("Do you want to reserve or unreserve a car? input 1 to reserve a car and 2 to unreserve: ");
    scanf("%d", &resOrUnres);
   
   
    printf("Input the registration of the car you want to reserve or unreserve: \n");
    scanf("%s", registration);

    
    while (current->next != NULL && strcmp(current->car->registration, registration) != 0) { //use string compare to check if the registration inputted is the same as one in the list
        current = current->next;
    }

    if (current == NULL) {
        printf("Error, Car with registration %s not found in the showroom\n", registration);
        return;
    }

    if (resOrUnres == 1) { // reserve a car
        if (current->car->reserved) {// error message if the car is already reserved
            printf("Error,  Car with registration %s is already reserved\n", registration);
        } else { // if the car is not reserved then the user will be able to reserve it
            float deposit; 
            printf("Input the deposit amount it must be between 500 and 1500 : ");
            scanf("%f", &deposit);
            if (deposit >= 500 && deposit <= 1500) { // checks if the deposit is between 500 and 1500
                current->car->reserved = true; // if the deposit is between 500 and 1500 the car will be reserved
                current->car->reservedAmount = deposit; // store the deposit amount in reservedAmount 
                printf("Car with registration %s has been reserved and the deposit amount is %.2f\n", registration, deposit);
            } else {
                printf("Error, the amount you must deposit has to be between 500 and 1500.\n");
            }
        }
    } else if (resOrUnres == 2) { // unreserve a car
        if (!current->car->reserved) { // error message if the car is not reserved
            printf("Error, Car with registration %s is not reserved so it cant be unreserved.\n", registration); 
        } else {
            current->car->reserved = false; // if the car is reserved then the user will be able to unreserve it
            current->car->reservedAmount = 0; // set the reservedAmount to 0
            printf("Car with registration %s has been unreserved.\n", registration);
        }
    } else { // error message if the user inputs a number that is not 1 or 2
        printf("Error, you have to input 1 or 2 to reserve or unreserve a car.\n");
    }
}
    

void ViewAllCars(Node* front)
{
    // Check if the showroom is empty
    if (front == NULL) {
        printf("Error, Showroom is empty.\n");
        return;
    }
    // Code for viewing all cars in the showroom
    printf("\nCars in the showroom:\n");
    struct Node* current = front; // start at the front of the list
    while (current != NULL) {
        printf("Registration: %s\n", current->car->registration);
        printf("Make and Model: %s\n", current->car->makeAndModel);
        printf("Colour: %s\n", current->car->colour);
        printf("Previous Owners: %d\n", current->car->previousOwners);
        printf("Reserved: %s\n", current->car->reserved ? "Yes" : "No");
        if (current->car->reserved) {
            printf("Reserve Amount: %.2f\n", current->car->reservedAmount);
        }
        printf("\n");
        current = current->next;
    }
   
}

void ViewSpecificCar(Node* front)
{
    // Code for viewing a specific car in the showroom

    // Check if the showroom is empty
    if (front == NULL) {
        printf("Error, Showroom is empty.\n");
        return;
    }

    Node* current = front;
    char registration[9]; // this stores the registration of the specfifc car that the user wants to view
    printf("Input the registration of the specific car you want to view: \n");
    scanf("%s", registration); 

    while(current != NULL) { // use string compare to check if the registration inputted is the same as one in the list
        if (strcmp(current->car->registration, registration) == 0) { // if the registration is the same as the one in the list then print the details of that car
            
        
        printf("Registration: %s\n", current->car->registration);
        printf("Make and Model: %s\n", current->car->makeAndModel);
        printf("Colour: %s\n", current->car->colour);
        printf("Previous Owners: %d\n", current->car->previousOwners);
        printf("Reserved: %s\n", current->car->reserved ? "Yes" : "No");
        if (current->car->reserved) {
            printf("Reserve Amount: %.2f\n", current->car->reservedAmount);

        
        }
        printf("\n");
         return;
    }
        current = current->next; 
    
}
  printf("Error, Specific car with registration %s not found in the showroom\n", registration);
    
}

void myTask(Node* front)
{
    // Code for my task 
    // Check if the showroom is empty
    if (front == NULL) {
        printf("Error, Showroom is empty.\n");
        return;
    }

    // code to respray a car 
    Node* current = front;
    char registration[9]; // this stores the registration of the car that the user wants to respray
    printf("Input the registration of the car you want to respray: \n");
    scanf("%s", registration);

    while (current != NULL) 
    {
        if (strcmp(current->car->registration, registration) == 0) { // use string compare to check if the registration inputted is the same as one in the list
            printf("Input the new colour you wish to respray the car: \n");
            scanf("%s", current->car->colour); 
            printf("Car with registration %s has been resprayed to %s\n", registration, current->car->colour); //changes the colour of the car and prints the new colour
            return;
        }
        current = current->next;
    }
    
    printf("Error, Car with registration %s not found in the showroom\n", registration);

    
}

void ExitTheSystem(Node* front)
{

    //TODO: save to file


    // Code for exiting the system
    printf("Bye!!\n");
    exit(0);
}
    
    //method to count the cars in the showroom


int carCounter(Node* front) {
    int count = 0;
    Node* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//methid to check if the registration is unique
bool isUniqueRegistration(Node* front, const char* registration) {
    Node* current = front;
    while (current != NULL) { // loop through the list to check if the registration is unique  
        if (strcmp(current->car->registration, registration) == 0) {
            return false; // returns false if registration already exists
        }
        current = current->next;
    }
    return true; // returns true if registration is unique
}