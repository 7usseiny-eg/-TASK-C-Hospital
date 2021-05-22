#include <stdio.h>
#include <conio.h>

/* PATIENTS_CONFIG.h */
typedef struct{
    int ID;
    char patientName[29];
    float weight;

} patientStruct;

/* GLOBAL VARIABLES */

patientStruct* patientPtrStruct; // A POINTER POINTING TO THE ARRAY OF PATIENTS
int pSize; //PATIENTS SIZE [ARRAY SIZE]

signed int Get_Patient_Index(patientStruct* ptr, int arrSize,unsigned int SearchID);

void Print_Patient_Data(unsigned int index);

void Print_All_Patient_Data();

void user_Interface();

int main(void){
    printf("[SYS] Enter the number of Patients: "); // ASK FOR PATIENT SIZE
    scanf("%d", &pSize); // SCANNING ARRAY SIZE
    patientPtrStruct = /*new*/ ((patientStruct*)malloc(pSize * sizeof(patientStruct)));
    for(int i = 0; i < pSize; i++){
        printf("[SYS] Enter the name of the patient: ");
        scanf("%s", &((patientPtrStruct+i)->patientName));
        printf("[SYS] Enter the ID of this patient: ");
        scanf("%d", &((patientPtrStruct+i)->ID));
        printf("[SYS] Enter the patient weight: ");
        scanf("%d", &((patientPtrStruct+i)->weight));
    }

    user_Interface();
    while(1){ // LOOP TO KEEP PROGRAM GOING
        char c;
        if(kbhit()){ //Checks if a key on the keyboard was pressed
            c = getch(); // Stores that key into C without showing it on the Command Prompt
            switch(c){
            case '1': //GO BACK TO USER INTERFACE FUNCTION TO SEE CASE OF 1
                Print_All_Patient_Data();
                user_Interface();
                continue;
            case '2': // GO BACK TO USER INTERFACE FUNCTION TO SEE CASE OF 1
                printf("Please insert the ID of the Patient: ");
                int x = 0; // temp integer to store the ID for comparison
                scanf("%d", &x);
                x = Get_Patient_Index(patientPtrStruct, pSize, x);
                if(x == -1){
                    printf("[SYS] You have entered an invalid ID");
                    user_Interface();
                }
                else
                    Print_Patient_Data(x);
                    user_Interface();
                continue;
            }
        }
    }
    free(patientPtrStruct);
}

signed int Get_Patient_Index(patientStruct* ptr, int arrSize,unsigned int SearchID){
    for(int i = 0; i < arrSize; i++){
        if((ptr+i)->ID == SearchID)
            return i;
    }
    return -1;
}

void Print_Patient_Data(unsigned int index){
    printf("Patient Name: %s\n", (patientPtrStruct+index)->patientName);
    printf("Patient Weight: %d\n", (patientPtrStruct+index)->weight);
    printf("Patient ID: %d\n", (patientPtrStruct+index)->ID);
}

void Print_All_Patient_Data(){
    for(int i = 0; i < pSize; i++){
        Print_Patient_Data(i);
    }
}

void user_Interface(){
    printf("[SYS] Press 1 to Print All Data of Patients\n");
    //printf("Press 3 to Modify the List of Patients\n"); WILL BE IMPLEMENTED USING LINKED LISTS
    printf("[SYS] Press 2 to Print data of a Single Patient\n");
}
