#include <stdio.h>
#include <string.h>

struct Dish
{
    int id;
    char name[100];
    float price;
};
typedef struct Dish Dish;
int main()
{
    Dish menu[100] = {
        {1, "Com Ga", 50.0},
        {2, "Thit Cho", 30.0},
        {3, "Banh Cuon", 40.0},
        {4, "Pho", 25.0},
        {5, "Banh Xeo", 35.0}};
    int size = 5;
    int choice, position;
    char search[100];

    while (1)
    {
        printf("\n\t\tMENU:\n");
        printf("1. In ra gia tri cac phan tu trong menu\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo name\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                printf("%d. name: %s, price: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
            }
        }
        else if (choice == 2)
        {
            printf("Nhap vi tri can chen (0 - %d): ", size);
            scanf("%d", &position);
            if (position < 0 || position > size)
            {
                printf("Vi tri chen khong hop le.\n");
                continue;
            }

            Dish newDish;
            newDish.id = size + 1;
            printf("Nhap ten mon an: ");
            getchar();
            fgets(newDish.name, sizeof(newDish.name), stdin);
            newDish.name[strcspn(newDish.name, "\n")] = '\0';
            printf("Nhap gia mon an: ");
            scanf("%f", &newDish.price);

            for (int i = size; i > position; --i)
            {
                menu[i] = menu[i - 1];
            }
            menu[position] = newDish;
            size++;
        }
        else if (choice == 3)
        {
            printf("Nhap vi tri can sua (0 - %d): ", size - 1);
            scanf("%d", &position);
            if (position < 0 || position >= size)
            {
                printf("Vi tri khong hop le.\n");
                continue;
            }

            printf("Nhap ten mon an moi: ");
            getchar();
            fgets(menu[position].name, sizeof(menu[position].name), stdin);
            menu[position].name[strcspn(menu[position].name, "\n")] = '\0';

            printf("Nhap gia mon an moi: ");
            scanf("%f", &menu[position].price);
        }
        else if (choice == 4)
        {
            printf("Nhap vi tri can xoa (0 - %d): ", size - 1);
            scanf("%d", &position);
            if (position < 0 || position >= size)
            {
                printf("Vi tri khong hop le.\n");
                continue;
            }

            for (int i = position; i < size - 1; i++)
            {
                menu[i] = menu[i + 1];
            }
            size--;
        }
        else if (choice == 5)
        {
            printf("Chon cach sap xep:\n");
            printf("a. Giam dan theo gia\n");
            printf("b. Tang dan theo gia\n");
            getchar();
            char sortChoice;
            scanf("%c", &sortChoice);

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if ((sortChoice == 'a' && menu[i].price < menu[j].price) ||
                        (sortChoice == 'b' && menu[i].price > menu[j].price))
                    {
                        Dish temp = menu[i];
                        menu[i] = menu[j];
                        menu[j] = temp;
                    }
                }
            }
        }
        else if (choice == 6)
        {
            printf("Nhap ten mon an can tim: ");
            getchar();
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0';

            printf("Chon cach tim kiem:\n");
            printf("a. Tim kiem tuyen tinh\n");
            printf("b. Tim kiem nhi phan\n");
            char searchChoice;
            scanf("%c", &searchChoice);

            if (searchChoice == 'a')
            {
                int found = 0;
                for (int i = 0; i < size; i++)
                {
                    if (strcmp(menu[i].name, search) == 0)
                    {
                        printf("Mon an tim duoc: ID: %d, Name: %s, Price: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Mon an khong ton tai.\n");
            }
            else if (searchChoice == 'b')
            {
                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        if (strcmp(menu[i].name, menu[j].name) > 0)
                        {
                            Dish temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }

                int l = 0, r = size - 1, found = 0;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    int cmp = strcmp(menu[mid].name, search);
                    if (cmp == 0)
                    {
                        printf("Mon an tim duoc: ID: %d, Name: %s, Price: %.2f\n", menu[mid].id, menu[mid].name, menu[mid].price);
                        found = 1;
                        break;
                    }
                    else if (cmp < 0)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                if (!found)
                    printf("Mon an khong ton tai.\n");
            }
            else
                printf("Lua chon khong hop le.\n");
        }
        else if (choice == 7)
        {
            printf("Thoat!\n");
            break;
        }
        else
        {
            printf("Lua chon khong hop le. Chon lai\n");
        }
    }
}
