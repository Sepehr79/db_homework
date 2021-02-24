#include <stdio.h>

/**
 * Enumerations
 */
enum Gender{
    MALE, FEMALE
};

enum ProductType{
    FOOD, CLOTHING, CHEMICALS
};

/**
 * Structs
 */
typedef struct{
    char name[30];
    char lastName[30];
    enum Gender gender;
    int age;
    int id;
}Customer;

typedef struct{
    char name[30];
    int price;
    char brand[50];
    int id;
    enum ProductType type;
}Product;

typedef struct{
    int customerId;
    int productsId[20];
    int maxPrice;
}Sales;


/**
 * Prototype methods
 */
void addNewCustomer();
void addNewProduct();

void setIntValue(int *value, int min, int max);

/**
 * Global values
 */
static Customer customers[100];
static int CUSTOMERS_INDEX = 0;

static Product products[100];
static int PRODUCTS_INDEX = 0;

static Sales sales[100];
static int SALES_INDEX = 0;

/**
 * Main method
 */
int main() {

    printf("Enter your selection:\n");
    printf("1. Add product\n");
    printf("2. Add customer\n");
    printf("3. Sale product\n");
    printf("4. Show products\n");
    printf("5. Show customers\n");
    printf("6. Show sales\n");
    printf("7. Show sales by id\n");
    printf("8. Show sales by day\n");

    printf("Your selection: ");

    int input;
    scanf("%d", &input);

    switch (input) {
        case 1:
            addNewProduct();
            break;
        case 2:
            addNewCustomer();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;

    }

    printf("%s %s %d %d", products[0].name, products[0].brand, products[0].type, products[0].id);
    return 0;
}

/**
 * Functions
 */
void addNewCustomer() {
    if (CUSTOMERS_INDEX < 100){
        Customer customer;

        printf("Enter customer name:");
        scanf("%s", customer.name);

        printf("Enter customer lastName:");
        scanf("%s", customer.lastName);

        printf("Enter customer age: ");
        scanf("%d", &customer.age);

        printf("Enter customer id: ");
        scanf("%d", &customer.id);

        printf("Select customer gender:\n");
        printf("1. Male\n");
        printf("2. Female\n");
        printf("Your selection:");
        
        setIntValue(&customer.gender, 1, 2);

        customers[CUSTOMERS_INDEX++] = customer;
    }

}

void addNewProduct() {
    if (PRODUCTS_INDEX < 100){
        Product product;

        printf("Select product type\n");
        printf("1. Food\n");
        printf("2. Clothing\n");
        printf("3. Chemicals\n");
        printf("Your selection: ");

        setIntValue(&product.type, 1, 3);

        printf("Enter product name: ");
        scanf("%s", product.name);

        printf("Enter product brand: ");
        scanf("%s", product.brand);

        printf("Enter product price: ");
        scanf("%d", &product.price);

        printf("Enter product id: ");
        scanf("%d", &product.id);

        products[PRODUCTS_INDEX++] = product;
    }
}

/**
 * Setter for enumeration values
 * @param value enum type number
 * @param min minimum value of enum type
 * @param max maximum value of enum type
 */
void setIntValue(int *value, int min, int max){
    int input;
    scanf("%d", &input);
    if (input >= min && input <= max){
        *value = input-1;
    } else{
        printf("Wrong input number\n");
        *value = 0;
    }
}
