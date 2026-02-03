#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int itemId;
    int quantity;
    struct Node* next;
} Node;

typedef struct Item {
    int id;
    char name[30];
} Item;

Item availableItems[] = {
    {1, "Laptop"}, {11, "Laptop-1"}, {12, "Laptop-2"}, {13, "Laptop-3"},
    {2, "Smartphone"}, {21, "Smartphone-1"}, {22, "Smartphone-2"}, {23, "Smartphone-3"},
    {3, "Headphones"}, {31, "Headphones-1"}, {32, "Headphones-2"},
    {4, "Keyboard"}, {41, "Keyboard-1"}, {42, "Keyboard-2"},
    {5, "Mouse"}, {51, "Mouse-1"}, {52, "Mouse-2"}, {53, "Mouse-3"}
};

int itemCount = sizeof(availableItems) / sizeof(availableItems[0]);

void displayAvailableItems() {
    printf("Available Items:\n");
    for (int i = 0; i < itemCount; i++) {
        if (availableItems[i].id < 10) {
            printf("Item ID: %d, Name: %s\n", availableItems[i].id, availableItems[i].name);
        }
    }
}

Node* addItem(Node* head, int itemId, int quantity) {
    Node* current = head;
    while (current != NULL) {
        if (current->itemId == itemId) {
            current->quantity += quantity;
            return head;
        }
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->itemId = itemId;
    newNode->quantity = quantity;
    newNode->next = head;
    return newNode;
}

void viewCart(Node* head) {
    if (head == NULL) {
        printf("Cart is empty.\n");
        return;
    }
    Node* current = head;
    printf("Cart Contents:\n");
    while (current != NULL) {
        const char* name = "Unknown";
        for (int i = 0; i < itemCount; i++) {
            if (availableItems[i].id == current->itemId) {
                name = availableItems[i].name;
                break;
            }
        }
        printf("Item ID: %d, Name: %s, Quantity: %d\n", current->itemId, name, current->quantity);
        current = current->next;
    }
}

void clearCart(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("Cart cleared successfully!\n");
}

void placeOrder(Node** head) {
    if (*head == NULL) {
        printf("Your cart is empty. Nothing to place.\n");
        return;
    }
    printf("Placing your order...\n");
    printf("-----------------------------------------------------\n");
    viewCart(*head);
    printf("-----------------------------------------------------\n");
    printf("Order has been placed successfully!!!\n");
    clearCart(head);
}

Node* removeItem(Node* head, int itemId) {
    Node *current = head, *prev = NULL;
    while (current != NULL) {
        if (current->itemId == itemId) {
            if (prev == NULL)
                head = current->next;
            else
                prev->next = current->next;
            free(current);
            printf("Item with ID %d removed from cart.\n", itemId);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("Item with ID %d not found in cart.\n", itemId);
    return head;
}

int main() {
    Node* cart = NULL;
    int choice, itemId, quantity;

    printf("Welcome to the E-commerce Cart System!\n");
    displayAvailableItems();

    while (1) {
        printf("\n1. Add Item to Cart\n2. View Cart\n3. Clear Cart\n4. Place Order\n5. Remove Item\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the Item ID to add: ");
                scanf("%d", &itemId);

                int isValid = 0;
                for (int i = 0; i < itemCount; i++) {
                    if (itemId == availableItems[i].id && itemId < 10) {
                        isValid = 1;
                        int SubItem;
                        if (itemId == 1) {
                            printf("1. Laptop-1\n2. Laptop-2\n3. Laptop-3\nSelect a Laptop (1/2/3): ");
                            scanf("%d", &SubItem);
                            if (SubItem == 1) itemId = 11;
                            else if (SubItem == 2) itemId = 12;
                            else if (SubItem == 3) itemId = 13;
                            else isValid = 0;
                        } else if (itemId == 2) {
                            printf("1. Smartphone-1\n2. Smartphone-2\n3. Smartphone-3\nSelect a Smartphone (1/2/3): ");
                            scanf("%d", &SubItem);
                            if (SubItem == 1) itemId = 21;
                            else if (SubItem == 2) itemId = 22;
                            else if (SubItem == 3) itemId = 23;
                            else isValid = 0;
                        } else if (itemId == 3) {
                            printf("1. Headphones-1\n2. Headphones-2\nSelect a Headphone (1/2): ");
                            scanf("%d", &SubItem);
                            if (SubItem == 1) itemId = 31;
                            else if (SubItem == 2) itemId = 32;
                            else isValid = 0;
                        } else if (itemId == 4) {
                            printf("1. Keyboard-1\n2. Keyboard-2\nSelect a Keyboard (1/2): ");
                            scanf("%d", &SubItem);
                            if (SubItem == 1) itemId = 41;
                            else if (SubItem == 2) itemId = 42;
                            else isValid = 0;
                        } else if (itemId == 5) {
                            printf("1. Mouse-1\n2. Mouse-2\n3. Mouse-3\nSelect a Mouse (1/2/3): ");
                            scanf("%d", &SubItem);
                            if (SubItem == 1) itemId = 51;
                            else if (SubItem == 2) itemId = 52;
                            else if (SubItem == 3) itemId = 53;
                            else isValid = 0;
                        }
                        break;
                    }
                }

                if (isValid) {
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    cart = addItem(cart, itemId, quantity);
                    printf("Item added successfully!\n");
                } else {
                    printf("Invalid Item ID! Please select a valid item.\n");
                }
                break;

            case 2:
                printf("----------------------------------------------------------\n");
                viewCart(cart);
                printf("----------------------------------------------------------\n");
                break;

            case 3:
                clearCart(&cart);
                break;

            case 4:
                placeOrder(&cart);
                break;

            case 5:
                printf("Enter Item ID to remove: ");
                scanf("%d", &itemId);
                cart = removeItem(cart, itemId);
                break;

            case 6:
                printf("Exited\n");
                clearCart(&cart);
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
