#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SEATS 24
#define NAME 20

struct seat {
    int id;
    int assigned;
    char fname[NAME];
    char lname[NAME];
};

/* Function prototypes */
void initSeats(struct seat s[]);
void flightMenu(struct seat s[]);
int countEmptySeats(struct seat s[]);
void showEmptySeats(struct seat s[]);
void showAlphabeticalSeats(struct seat s[]);
void assignSeat(struct seat s[]);
void deleteSeat(struct seat s[]);

int main(void)
{
    struct seat outbound[SEATS];
    struct seat inbound[SEATS];
    char choice;

    initSeats(outbound);
    initSeats(inbound);

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("a. Outbound Flight\n");
        printf("b. Inbound Flight\n");
        printf("c. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice) {
            case 'a':
                flightMenu(outbound);
                break;
            case 'b':
                flightMenu(inbound);
                break;
            case 'c':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'c');

    return 0;
}

/* Initialize seats */
void initSeats(struct seat s[])
{
    for (int i = 0; i < SEATS; i++) {
        s[i].id = i + 1;
        s[i].assigned = 0;
        strcpy(s[i].fname, "");
        strcpy(s[i].lname, "");
    }
}

/* Second level menu */
void flightMenu(struct seat s[])
{
    char choice;

    do {
        printf("\n--- FLIGHT MENU ---\n");
        printf("a. Show number of empty seats\n");
        printf("b. Show list of empty seats\n");
        printf("c. Show alphabetical list of seats\n");
        printf("d. Assign a seat\n");
        printf("e. Delete a seat assignment\n");
        printf("f. Return to main menu\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice) {
            case 'a':
                printf("Empty seats: %d\n", countEmptySeats(s));
                break;
            case 'b':
                showEmptySeats(s);
                break;
            case 'c':
                showAlphabeticalSeats(s);
                break;
            case 'd':
                assignSeat(s);
                break;
            case 'e':
                deleteSeat(s);
                break;
            case 'f':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'f');
}

int countEmptySeats(struct seat s[])
{
    int count = 0;
    for (int i = 0; i < SEATS; i++)
        if (!s[i].assigned)
            count++;
    return count;
}

void showEmptySeats(struct seat s[])
{
    printf("Empty seat numbers:\n");
    for (int i = 0; i < SEATS; i++)
        if (!s[i].assigned)
            printf("Seat %d\n", s[i].id);
}

void showAlphabeticalSeats(struct seat s[])
{
    struct seat temp[SEATS];
    memcpy(temp, s, sizeof(temp));

    for (int i = 0; i < SEATS - 1; i++) {
        for (int j = i + 1; j < SEATS; j++) {
            if (strcmp(temp[i].lname, temp[j].lname) > 0) {
                struct seat swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    printf("Seat assignments (alphabetical):\n");
    for (int i = 0; i < SEATS; i++) {
        if (temp[i].assigned)
            printf("Seat %d: %s %s\n",
                   temp[i].id,
                   temp[i].fname,
                   temp[i].lname);
    }
}

void assignSeat(struct seat s[])
{
    int seatnum;

    printf("Enter seat number (1-24, 0 to cancel): ");
    scanf("%d", &seatnum);

    if (seatnum == 0)
        return;

    if (seatnum < 1 || seatnum > SEATS || s[seatnum - 1].assigned) {
        printf("Invalid or already assigned seat.\n");
        return;
    }

    printf("Enter first name: ");
    scanf("%s", s[seatnum - 1].fname);
    printf("Enter last name: ");
    scanf("%s", s[seatnum - 1].lname);

    s[seatnum - 1].assigned = 1;
    printf("Seat assigned successfully.\n");
}

void deleteSeat(struct seat s[])
{
    int seatnum;

    printf("Enter seat number to delete (0 to cancel): ");
    scanf("%d", &seatnum);

    if (seatnum == 0)
        return;

    if (seatnum < 1 || seatnum > SEATS || !s[seatnum - 1].assigned) {
        printf("Invalid or empty seat.\n");
        return;
    }

    s[seatnum - 1].assigned = 0;
    strcpy(s[seatnum - 1].fname, "");
    strcpy(s[seatnum - 1].lname, "");

    printf("Seat assignment removed.\n");
}
