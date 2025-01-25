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

struct Contact contacts[no_of_contacts];//matrice nstockiw fiha les contacts

void printHeader(char* str);//decor fo9ani belkhtot
int printMenu();//باجة تع الصفحة الرئيسية et obtenez la sélection de l'utilisateur
void promptContact(char* qn, char* str);//demande m utilisateur ydkhel les informations
int addNewContact(int lastId);//nzidou contact llmatrice li drnaha
int printContacts();
void printCredits();// creditd tekhrojlek fel menu te3 les developpeurs
int editContact(); // Modifier un contact existant
int deleteContact(); // Supprimer un contact existant

int main() {//Ces variables sont des chaînes qui contiennent des adresses qui seront utilisées à différents endroits du programme.
    char title_1[] = "Menu";
    char title_2[] = "New Contact Form";
    char title_3[] = "All Contacts";

    int lastId = 0;
    int choice = 0;// variable te3 user choice

    system("color 3");

MENU:// naffichiw l menu w neste9blo les donnes te3 lutilisateur
    system("cls");// fonction special llwindows brk trje3 page fargha
    choice = printMenu();
    switch(choice) {
        case 1:
            goto NEW;
            break;
        case 2:
            goto INFO;
            break;
        case 3:
            goto EDIT;
            break;
        case 4:
            goto DELETE;
            break;
        case 5:
            goto CREDITS;
            break;
        case 6:
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

EDIT:
    system("cls");
    choice = editContact();
    goto MENU;

DELETE:
    system("cls");
    choice = deleteContact();
    goto MENU;

CREDITS:
    system("cls");
    printCredits();
    goto MENU;

EXIT:
    printf("\n\n\tDONE!");
    return 0;
}

void printHeader(char* str) {//Il prend du texte comme titre et l'imprime avec des lignes des deux côtés pour le rendre plus organisé dans la sortie.
    int strlength = strlen(str);//     Calcule la longueur du texte (titre)
    int padding = width - strlength;   // lespae li bin text w lkhtot te3 decor
    int leftLimit = floor(padding / 2);
    int rightLimit = width - leftLimit;
    int i = 0, j = 0;
    printf("\n\t");// print the line te3 dicor
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

int printMenu() {//fonction te3 menu w demander m lutilisateur ydkhel mn 1 l 4
    int choice = 0;
    char header[] = "Menu";
    char footer[] = "----";
    printf("\n");
    printHeader(header);
    printf("\n\t1. Add new contact");
    printf("\n\t2. Display all contacts");
    printf("\n\t3. Edit a contact");
    printf("\n\t4. Delete a contact");
    printf("\n\t5. View Credits");
    printf("\n\t6. Exit\n");
    printHeader(footer);
    printf("\n\tEnter menu number: ");
    scanf("%d", &choice);
    return choice;
}

void promptContact(char* qn, char* str) {// fonction te3 window te3 contact
    printf("\n\tEnter %s:\n\t> ", qn);
    scanf("%s", str);
}
//Ajoute un nouveau contact au tableau de contacts en utilisant lastId comme pointeur.Le lastId est mis à jour après chaque ajout de nouveau contact.
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

int printContacts() {// page te3 les contacts
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

int editContact() {
    char header[] = "Edit Contact";
    int id;
    printHeader(header);
    printf("\n\tEnter the ID of the contact to edit: ");
    scanf("%d", &id);
    id -= 1; // Adjust for 0-based index

    if(id >= 0 && id < no_of_contacts && strlen(contacts[id].name) > 0) {
        printf("\n\tEditing Contact: %s", contacts[id].name);
        promptContact("new name", contacts[id].name);
        promptContact("new mobile number", contacts[id].telno);
        promptContact("new email", contacts[id].email);
        printf("\n\tContact updated successfully!");
    } else {
        printf("\n\tInvalid ID or contact does not exist.");
    }
    printf("\n\n\tPress any key to go back: ");
    char dummy[255];
    scanf("%s", dummy);
    return 1;
}

int deleteContact() {
    char header[] = "Delete Contact";
    int id;
    printHeader(header);
    printf("\n\tEnter the ID of the contact to delete: ");
    scanf("%d", &id);
    id -= 1; // Adjust for 0-based index

    if(id >= 0 && id < no_of_contacts && strlen(contacts[id].name) > 0) {
        printf("\n\tDeleting Contact: %s", contacts[id].name);
        memset(&contacts[id], 0, sizeof(struct Contact));
        printf("\n\tContact deleted successfully!");
    } else {
        printf("\n\tInvalid ID or contact does not exist.");
    }
    printf("\n\n\tPress any key to go back: ");
    char dummy[255];
    scanf("%s", dummy);
    return 1;
}

void printCredits() {// page te3 devloppeurs
    char header[] = "Credits";
    printHeader(header);
    printf("\n\tDeveloped by:");
    printf("\n\t- ALI MOHAMMED AMINE ABDERRAOUF");
    printf("\n\t- DADDA YACINE");
    printf("\n\t- ABDELLAH HEBBACHE");
    printf("\n\t- BEN SAID HOUCINE");
    printf("\n\n\tPress any key to go back: ");
    char dummy[255];
    scanf("%s", dummy);
}

