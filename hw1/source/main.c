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
typedef struct {
    int day;
    int month;
    int year;
}Date;

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
    Customer customer;
    Product *products[20];
    int SALES_PRODUCTS_INDEX;
    Date date;
    int maxPrice;
    int id;
}Sales;


/**
 * Prototype methods
 */
void addNewCustomer();
void addNewProduct();
void showProducts();
void showMainMenu();
void showCustomers();
void saleProducts();
void createNewCart();
void addNewProductToExitingCart();
void showSales();
void showSalesById();
void showSalesByDay();

// method using to set enumeration values
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
    int input = 0;

    while (input != 9){

        showMainMenu();

        scanf("%d", &input);

        switch (input) {
            case 1:
                addNewProduct();
                break;
            case 2:
                addNewCustomer();
                break;
            case 3:
                saleProducts();
                break;
            case 4:
                showProducts();
                break;
            case 5:
                showCustomers();
                break;
            case 6:
                showSales();
                break;
            case 7:
                showSalesById();
                break;
            case 8:
                showSalesByDay();
                break;
            case 9:
                printf("Bye");
                break;
            default:
                printf("Wrong input!\n");

        }
    }
    return 0;
}



/**
 * Functions
 */
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

void saleProducts() {
    int input = 0;
    while (input != 4){

        printf("1. Create new product cart: \n");
        printf("2. Add new product to the exiting product cart: \n");
        printf("3. Show sales:\n");
        printf("4. Exit\n");

        scanf("%d", &input);
        switch (input) {
            case 1:
                createNewCart();
                break;
            case 2:
                addNewProductToExitingCart();
                break;
            case 3:
                showSales();
                break;
            case 4:
                printf("Bye!\n");
                break;
            default:
                printf("Wrong input!\n");
        }
    }

}

void showProducts() {
    printf("   Type    Name    Brand   Price   Id\n");
    for (int i = 0; i < PRODUCTS_INDEX; ++i) {
        printf("%d: ", i + 1);
        switch (products[i].type) {
            case 0:
                printf("Food    ");
                break;
            case 1:
                printf("Clothing    ");
                break;
            case 2:
                printf("Chemicals   ");
                break;
        }
        printf("%s    %s    %d    %d\n", products[i].name, products[i].brand, products[i].price, products[i].id);
    }

}

void showCustomers() {
    printf("Gender    Name    lastName    Age    Id\n");
    for (int i = 0; i < CUSTOMERS_INDEX; ++i) {
        printf("%d: ", i + 1);
        switch (customers[i].gender) {
            case 0:
                printf("Male    ");
                break;
            case 1:
                printf("Female    ");
                break;
        }
        printf("%s    %s    %d    %d\n", customers[i].name, customers[i].lastName, customers[i].age, customers[i].id);
    }
}

void showSales() {
    for (int i = 0; i < SALES_INDEX; i++) {
        printf("%d: ", i + 1);
        printf("Customer name: %s %s\nCart id: %d\n", sales[i].customer.name,
               sales[i].customer.lastName, sales[i].id);
        printf("list of products: \n");
        for (int j = 0; j < sales[i].SALES_PRODUCTS_INDEX; j++) {
            printf("%s %s\n", sales[i].products[j]->name, sales[i].products[j]->brand);
        }
        printf("Max price: %d\n", sales[i].maxPrice);
        printf("Date: %d / %d / %d\n", sales[i].date.year, sales[i].date.month, sales[i].date.day);
    }
}

void showSalesById() {
    printf("Enter cart id\n");

    int id;
    scanf("%d", &id);

    for (int i = 0; i < SALES_INDEX; i++) {
        if (sales[i].id == id){
            printf("Customer:%s %s\nList of products:\n", sales[i].customer.name, sales[i].customer.lastName);
            for (int j = 0; j < sales[i].SALES_PRODUCTS_INDEX; j++) {
                printf("%s %s", sales[i].products[j]->name, sales[i].products[j]->brand);
            }
            printf("Max price:%d", sales[i].maxPrice);
            return;
        }
    }
    printf("Cart not found");
}

void showSalesByDay() {
    printf("Enter date with [{year} {month} {day}] format: ");
    int day, month, year;

    scanf("%d %d %d", &year, &month, &day);

    for (int i = 0; i < SALES_INDEX; i++) {
        if (sales[i].date.day == day && sales[i].date.month == month && sales[i].date.year == year){
            printf("Customer: %s %s\n", sales[i].customer.name, sales[i].customer.lastName);
            printf("List of products: \n");
            for (int j = 0; j < sales[i].SALES_PRODUCTS_INDEX; j++) {
                printf("name: %s\nbrand: %s\n", sales[i].products[j]->name, sales[i].products[j]->brand);
                printf("max price: %d\n", sales[i].maxPrice);
            }
        }
    }
}

void createNewCart() {
    printf("Select from customers:\n");
    showCustomers();

    int input;
    scanf("%d", &input);

    printf("Enter cart id:");
    int id;
    scanf("%d", &id);

    printf("Enter number of day: ");
    int day;
    scanf("%d", &day);

    printf("Enter number of month: ");
    int month;
    scanf("%d", &month);

    printf("Enter number of year: ");
    int year;
    scanf("%d", &year);

    if (input - 1 < CUSTOMERS_INDEX && input > -1){
        Sales sale = {.SALES_PRODUCTS_INDEX = 0, .maxPrice = 0};
        sale.customer = customers[input - 1];
        sale.id = id;

        sale.date.day = day;
        sale.date.month = month;
        sale.date.year = year;

        sales[SALES_INDEX++] = sale;
    }
}

void addNewProductToExitingCart() {
    printf("Select an exiting cart:\n");
    showSales();
    printf("Your selection: ");

    int sales_index;
    scanf("%d", &sales_index);

    if (sales_index > 0 && sales_index <= SALES_INDEX){
        sales_index--;
    }

    printf("Select an exiting product:\n");
    showProducts();
    printf("Your selection: ");

    int product_index;
    scanf("%d", &product_index);

    if (product_index > 0 && product_index <= PRODUCTS_INDEX){
        product_index--;
    }
    sales[sales_index].products[sales[sales_index].SALES_PRODUCTS_INDEX++] = &products[product_index];
    sales[sales_index].maxPrice += products[product_index].price;
}

void showMainMenu(){
    printf("Enter your selection:\n");
    printf("1. Add product\n");
    printf("2. Add customer\n");
    printf("3. Sale product\n");
    printf("4. Show products\n");
    printf("5. Show customers\n");
    printf("6. Show sales\n");
    printf("7. Show sales by id\n");
    printf("8. Show sales by day\n");
    printf("9. Exit\n");
    printf("Your selection: ");
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
