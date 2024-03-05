#include <stdio.h>


//function prototypes
void menu();
void AddACar();
void SellACar();
void ReserveOrUnreserveACar();
void ViewAllCars();
void ViewSpecificCar();
void myTask();
void ExitTheSystem();



int main()
{
    
    void menu();
    
    return 0;
    }

void menu(){
 int ans;
    
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
            void AddACar();
            break;
        case 2:
            void SellACar();
            break;
        case 3:
            void ReserveOrUnreserveACar();
            break;
            case 4:
          void ViewAllCars();
            break;
        case 5:
            void ViewSpecificCar();
            break;
        case 6:
            void myTask();
            break;
            case 7:
            void ExitTheSystem();
            break;
        default:
            printf("Error, please pick an option between 1 and 7\n");
            break;
    }
    return 0;
}
    
    
void AddACar()
{
    // Code for adding a new car to the showroom
}

void SellACar()
{
    // Code for selling a car from the showroom
}

void ReserveOrUnreserveACar()
{
    // Code for reserving/unreserving a car in the showroom
}

void ViewAllCars()
{
    // Code for viewing all cars in the showroom
}

void ViewSpecificCar()
{
    // Code for viewing a specific car in the showroom
}

void myTask()
{
    // Code for my task 
}

void ExitTheSystem()
{
    // Code for exiting the system
}
    
