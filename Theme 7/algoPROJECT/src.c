#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define width 60
#define no_of_contacts 10

struct Contact {
    int id;
    char name[255];
    char telno[255];
    char email[255];
};

struct Contact contacts[no_of_contacts];

void printHeader(char* str);
int printMenu();
void promptContact(char* qn, char* str);
int addNewContact(int lastId);
int printContacts();
void printCredits();

int main() {
    char title_1[] = "Menu";
    char title_2[] = "New Contact Form";
    char title_3[] = "All Contacts";

    int lastId = 0;
    int choice = 0;

    system("color A");
    

MENU:
    system("cls");
    choice = printMenu();
    switch(choice) {
        case 1:
            goto NEW;
            break;
        case 2:
            goto INFO;
            break;
        case 3:
            goto CREDITS;
            break;
        case 4:
            goto EXIT;
            break;
        default:
            goto MENU;
    }

NEW:
    system("cls");
    lastId = addNewContact(lastId);
    goto MENU;

INFO:
    system("cls");
    choice = printContacts();
    if(choice == 1) {
        goto MENU;
    }
    goto EXIT;

CREDITS:
    system("cls");
    printCredits();
    goto MENU;

EXIT:
    printf("\n\n\tDONE!");
    return 0;
}

void printHeader(char* str) {
    int strlength = strlen(str);
    int padding = width - strlength;
    int leftLimit = floor(padding / 2);
    int rightLimit = width - leftLimit;
    int i = 0, j = 0;
    printf("\n\t");
    do {
        if(i >= leftLimit && i < rightLimit) {
            printf("%c", str[j]);
            j++;
        } else {
            printf("%s", "-");
        }
        i++;
    } while(i < width);
    printf("\n");
}

int printMenu() {
    int choice = 0;
    char header[] = "Menu";
    char footer[] = "----";
    printf("\n");
    printHeader(header);
    printf("\n\t1. Add new contact");
    printf("\n\t2. Display all contacts");
    printf("\n\t3. View Credits");
    printf("\n\t4. Exit\n");
    printHeader(footer);
    printf("\n\tEnter menu number: ");
    scanf("%d", &choice);
    return choice;
}

void promptContact(char* qn, char* str) {
    printf("\n\tEnter %s:\n\t> ", qn);
    scanf("%s", str);
}

int addNewContact(int lastId) {
    struct Contact newContact;
    char header[] = "Contact Entry Form";
    char name[] = "name";
    char mobile[] = "mobile number";
    char email[] = "email";
    printHeader(header);
    promptContact(name, newContact.name);
    promptContact(mobile, newContact.telno);
    promptContact(email, newContact.email);
    newContact.id = lastId;
    contacts[lastId] = newContact;
    lastId++;
    return lastId;
}

int printContacts() {
    char header[] = "All Contacts";
    int i = 0;
    char ans[255];
    printf("\n");
    printHeader(header);
    int contactCount = 0;
    for(i = 0; i < no_of_contacts; i++) {
        if(strlen(contacts[i].name) > 0) {
            contactCount++;
        }
    }
    printf("\n\tNumber of Contacts: %d", contactCount);
    if (contactCount < 1) {
        printf("\n\n\t >> No records available");
    } else {
        printf("\n\n\tID\tNAME\t\tMOBILE\t\t\tEMAIL\n");
        for(i = 0; i < no_of_contacts; i++) {
            if(strlen(contacts[i].name) > 0) {
                printf("\n\t%d\t%s\t\t%s\t\t\t%s", contacts[i].id + 1, contacts[i].name, contacts[i].telno, contacts[i].email);
            }
        }
    }
    printf("\n\n\tPress any key to go back : ");
    scanf("%s", ans);
    if(strlen(ans) > 0) {
        return 1;
    } else {
        return 0;
    }
}

void printCredits() {
    char header[] = "Credits";
    printHeader(header);
    printf("\n\tDeveloped by:");
    printf("\n\t- ALI ABDERRAOUF");
    printf("\n\t- DADDA YACINE");
    printf("\n\t- ABDELLAH HEBBACHE");
    printf("\n\t- contact 4");
    printf("\n\n\tPress any key to go back: ");
    char dummy[255];
    scanf("%s", dummy);
}
