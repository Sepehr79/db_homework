#include <stdio.h>

enum Gender{
    MALE, FEMALE
};

enum ProductType{
    FOOD, CLOTHING, CHEMICALS
};

struct Customer{
    char *name;
    char *lastName;
    enum Gender gender;
    int age;
    int id;
};

struct Product{
    char *name;
    int price;
    char *brand;
    int id;
    enum ProductType type;
};

struct Sales{
    int customerId;
    int productId[20];
    int maxPrice;
};

static struct Customer customers[100];
static int CUSTOMERS_INDEX = 0;

static struct Product products[100];
static int PRODUCTS_INDEX = 0;

static struct Sales sales[100];
static int SALES_INDEX = 0;

void addNewCustomer();

int main() {

    int input;
    scanf("%d", &input);

    switch (input) {
        case 1:
            addNewCustomer();
            break;
        case 2:
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

    printf("%s", customers[0].name);
    return 0;
}

void addNewCustomer() {

    struct Customer customer;
    customer.name = "";
    customer.lastName = "";
    customer.age = 0;

    scanf("%s", customer.name);

    customers[CUSTOMERS_INDEX++] = customer;


}
