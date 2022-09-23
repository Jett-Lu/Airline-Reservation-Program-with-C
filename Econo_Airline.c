/*
    program: Econ-Flight Airline Reservation Program (PRG255)
    author: Jett Lu
    date: 11-27-2021
    purpose: program that allows for seat selection and modification that saves on external file 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

struct seats {
    int seat_Number;
    char seat_avail;
    char first_name[22];
    char last_name[22];
};

void startMenu();
void ecoMenu();
void seatArrange();
void save_to_file(struct seats seating_data[]);
void read_from_file(struct seats seating_data[]);

int main() {
    struct seats s[12];
    char choice = 'z';
    char deleteInpt;
    int emptySeats = 12;
    int full = 0;
    int num = 0;
    int seatNum;
    int selectSeat;
    char firstName[20];
    char lastName[20];
    char backupFilePath[100];
    int file_flag = 0;

    startMenu();
    for (seatNum = 0; seatNum < 12; seatNum++) {
        s[seatNum].seat_avail = 'y';
        s[seatNum].first_name[0] = '\0';
        s[seatNum].last_name[0] = '\0';
        s[seatNum].seat_Number = seatNum + 1;
    }
    do {
        if (file_flag == 1) {
            read_from_file(s);
        }
        ecoMenu();
        scanf("%c", &choice);
        system("cls");
        switch (choice) {

        case 'a':
        case 'A':
            seatArrange();
            for (seatNum = 0; seatNum < 12; seatNum++) {
                printf("\n\t%d", s[seatNum].seat_Number);
                if (s[seatNum].seat_avail == 'y' || s[seatNum].seat_avail == 'Y')
                    printf("\t\tEmpty");

                else {

                    printf("\t\tOccupied");
                    printf("\t %s", s[seatNum].last_name);
                    printf("\t%s", s[seatNum].first_name);
                }
            }
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 'b':
        case 'B':
            seatArrange();
            emptySeats = 0;
            for (seatNum = 0; seatNum < 12; seatNum++) {

                if (s[seatNum].seat_avail == 'y' || s[seatNum].seat_avail == 'Y') {
                    printf("\n\tseat %d", s[seatNum].seat_Number);
                    emptySeats++;
                }
            }
            printf("\n\n\nThere are %d Empty Seats\n", emptySeats);
            system("\npause");
            break;
        case 'c':
        case 'C':
            seatArrange();
            full = 0;
            for (seatNum = 0; seatNum < 12; seatNum++) {
                if (s[seatNum].seat_avail == 'n' || s[seatNum].seat_avail == 'N') {
                    printf("\n\tseat %d", s[seatNum].seat_Number);
                    printf("\t\t%s", s[seatNum].first_name);
                    printf("\t\t%s", s[seatNum].last_name);
                    full += 1;
                }
            }
            printf("\n\nThere are %d ASSIGNED Seats\n", full);
            system("pause");
            break;

        case 'd':
        case 'D':
            printf("\tThe following seats are available -\n\n");
            printf("There are %d Filled Seats\n", full);
            printf("Which Seat would you like (0 to exit)?\n");
            scanf("%d", &selectSeat);
            printf("Seat selected: %d", selectSeat);

            if (selectSeat == 0) {
                break;
            }
            else {
                selectSeat--;
                printf("\nInput Last Name:\n");
                scanf("%s", &lastName);
                printf("\nInput First Name:\n");
                scanf("%s", &firstName);
                system("\npause");
            }

            if (s[selectSeat].seat_avail == 'y' || s[selectSeat].seat_avail == 'Y') {
                printf("\nAssigned seat number: %d", s[selectSeat].seat_Number);
                strcpy(s[selectSeat].first_name, firstName);
                strcpy(s[selectSeat].last_name, lastName);
                s[selectSeat].seat_avail = 'n';
            }
            else {
                printf("\nAssigned seat number: %d is not available, select another!", s[selectSeat].seat_Number);
            }

            save_to_file(s);
            file_flag = 1;
            printf("\n");
            system("\npause");
            break;

        case 'e':
        case 'E':
            printf("\tHere are the seats you can delete\n");

            emptySeats = 0;

            for (seatNum = 0; seatNum < 12; seatNum++) {

                if (s[seatNum].seat_avail == 'n' || s[seatNum].seat_avail == 'N') {
                    printf("\n\tseat %d", s[seatNum].seat_Number);
                    emptySeats++;
                }
            }

            printf("\nWhich Seat would you like to delete (0 to exit)?\n");
            scanf("%d", &selectSeat);
            selectSeat--;
            if (s[selectSeat].seat_avail == 'n' || s[selectSeat].seat_avail == 'N') {
                printf("\n assigned seat number: %d", s[selectSeat].seat_Number);
                strcpy(s[selectSeat].first_name, "\0");
                strcpy(s[selectSeat].last_name, "\0");
                s[selectSeat].seat_avail = 'y';
                printf("Deleted entry on seat: %d", selectSeat);
            }
            else {
                printf("\n selected seat number: %d is already empty, select another!", s[selectSeat].seat_Number);
            }

            save_to_file(s);
            file_flag = 1;
            printf("\n");
            system("\npause");
            break;

        case 'f':
        case 'F':

            printf("Are you sure you want to RESET the DATA (y/n)\n");
            scanf("%s", &deleteInpt);

            if (deleteInpt == 'y' || deleteInpt == 'Y') {
                for (seatNum = 0; seatNum < 12; seatNum++) {
                    s[seatNum].seat_avail = 'y';
                    s[seatNum].first_name[0] = '\0';
                    s[seatNum].last_name[0] = '\0';
                    s[seatNum].seat_Number = seatNum + 1;
                }
                save_to_file(s);
                file_flag = 1;
            }
            else
                system("pause");

            break;
        case 'g':
        case 'G':
            goto exit_loop;
            break;

        case 'h':
        case 'H':
            printf("Loading data from previous save");
            read_from_file(s);
            file_flag = 1;
            break;
        };
    } while (choice != 'g' || choice != 'G');
exit_loop:;
}

void startMenu() {
    printf("This is a flight seat reservation program, Hit any key to see the "
        "Menu\n\n");
    system("pause");
    system("cls");
}

void ecoMenu() {
    printf("\tEcono-Flgiht Airline Resevation Program\n");
    printf("\na. Display ALL seat assignments (Including Empty).\nb. Show ONLY a "
        "list of empty seats and show total of empty seats.\nc. Show ONLY the "
        "assigned seats with name of person and total assigned.\nd. Assign "
        "the customer to an empty seat.\ne. Delete ONE seat assignments.\nf. "
        "Delete ALL seat assignments.\ng. Quit program.\nh. Load File.\n");
    printf("\nEnter your selection : ");
}

void seatArrange() {
    printf("\t\t\tSeating Arragement\n\n");
    printf("\tSeat#:\t\tStatus:\t\tClient Name:\n");
}

void save_to_file(struct seats seating_data[]) {
    FILE* fptr;

    fopen("airlineSeating.txt", "w");

    if ((fptr = fopen("airlineSeating.txt", "w")) == NULL) {
        printf("Error opening file!\n\n");
        exit(1);
    }

    for (int seatNum = 0; seatNum < 12; seatNum++) {
        if (seating_data[seatNum].seat_avail == 'n' || seating_data[seatNum].seat_avail == 'N') {
            fwrite(&seating_data[seatNum], sizeof(struct seats), 1, fptr);
        }
    }

    fclose(fptr);
}

void read_from_file(struct seats seating_data[]) {
    FILE* fptr;
    struct seats input_data;
    int seat_no;

    fopen("airlineSeating.txt", "r");

    if ((fptr = fopen("airlineSeating.txt", "r")) == NULL) {
        printf("Error Reading File...");
    }
    while (fread(&input_data, sizeof(struct seats), 1, fptr)) {
        seat_no = input_data.seat_Number;
        seat_no--;
        seating_data[seat_no].seat_avail = 'n';
        strcpy(seating_data[seat_no].first_name, input_data.first_name);
        strcpy(seating_data[seat_no].last_name, input_data.last_name);
    }

    printf("File Loadded...\n\n");
}