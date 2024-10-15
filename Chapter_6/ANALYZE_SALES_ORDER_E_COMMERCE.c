// Problem: Chapter 6 - Analyze sales order of an e-commerce company
// Description
// Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
//             <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
// in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
// <CustomerID>: string of length from 3 to 10
// <ProductID>: string of length from 3 to 10
// <Price>: a positive integer from 1 to 1000
// <ShopID>: string of length from 3 to 10
// <TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)


// Perform a sequence of queries of following types:
// ?total_number_orders: return the total number of orders
// ?total_revenue: return the total revenue the e-commerce company gets
// ?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
// ?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
// ?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

// Input
// The input consists of two blocks of data:
// The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
// The first block is terminated with a line containing the character #
// The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
// The second block is terminated with a line containing the character #

// Output
// Write in each line, the result of the corresponding query 

// Example
// Input
// C001 P001 10 SHOP001 10:30:10
// C001 P002 30 SHOP001 12:30:10
// C003 P001 40 SHOP002 10:15:20
// C001 P001 80 SHOP002 08:40:10
// C002 P001 130 SHOP001 10:30:10
// C002 P001 160 SHOP003 11:30:20
// #
// ?total_number_orders
// ?total_revenue
// ?revenue_of_shop SHOP001
// ?total_consume_of_customer_shop C001 SHOP001 
// ?total_revenue_in_period 10:00:00 18:40:45
// #


// Output 
// 6
// 450
// 170
// 40
// 370

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id[23]; 
    int price;
    struct Node *left, *right;
} Node;

Node* createNode(char *id, int price) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->id, id);
    newNode->price = price;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, char *id, int price) {
    if (root == NULL) return createNode(id, price);
    if (strcmp(id, root->id) < 0) root->left = insertNode(root->left, id, price);
    else if (strcmp(id, root->id) > 0) root->right = insertNode(root->right, id, price);
    return root;
}

Node* findNode(Node *root, char *id) {
    if (root == NULL) return NULL;
    int cmp = strcmp(id, root->id);
    if (cmp == 0) return root;
    else if (cmp < 0) return findNode(root->left, id);
    else return findNode(root->right, id);
}

int convertTime(char *time){
    int a[3], i=0;
    char *c = strtok(time, ":");
    while (c != NULL) {
        a[i++] = atoi(c);
        c = strtok(NULL, ":");
    }
    return a[0] * 60 * 60 + a[1] * 60 + a[2];
}

int main(int argc, char const *argv[]){
    Node *root = NULL, *root1 = NULL;
    int a[86400] = {0};
    char customer_id[23], product_id[11], shop_id[11], time[9];
    int price;
    int cnt = 0, revenue = 0;

    while (1) {
        scanf("%[^ \n]%*c", customer_id);
        if (!strcmp(customer_id, "#")) break;
        scanf("%[^ ]%*c", product_id);
        scanf("%d%*c", &price);
        scanf("%[^ ]%*c", shop_id);
        scanf("%[^\n]%*c", time);

        Node *t = findNode(root, shop_id);
        if (t == NULL) root = insertNode(root, shop_id, price);
        else t->price += price;

        strcat(customer_id, " ");
        strcat(customer_id, shop_id);
        Node *v = findNode(root1, customer_id);
        if (v == NULL) root1 = insertNode(root1, customer_id, price);
        else v->price += price;

        int index = convertTime(time);
        a[index] += price;

        revenue += price;
        cnt++;
    }

    for(int i = 1; i < 86400; i++){
        a[i] += a[i-1];
    }

    while (1){
        char query[30];
        scanf("%[^ \n]%*c", query);
        if (!strcmp(query, "#")) break;
        if (!strcmp(query, "?total_number_orders")) printf("%d\n", cnt);
        else if (!strcmp(query, "?total_revenue")) printf("%d\n", revenue);
        else if (!strcmp(query, "?revenue_of_shop")){
            char s[11];
            scanf("%[^\n]%*c", s);
            Node *u = findNode(root, s);
            if (u == NULL) printf("0\n");
            else printf("%d\n", u->price);
        } else if (!strcmp(query, "?total_consume_of_customer_shop")){
            char s[23];
            scanf("%[^\n]%*c", s);
            Node *u = findNode(root1, s);
            if (u == NULL) printf("0\n");
            else printf("%d\n", u->price);
        } else {
            char fromTime[9], toTime[9];
            scanf("%[^ ]%*c", fromTime);
            scanf("%[^\n]%*c", toTime);
            int from = convertTime(fromTime);
            int to = convertTime(toTime);
            printf("%d\n", a[to] - a[from - 1]);
        }
    }
    return 0;
}

