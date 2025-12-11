#include <stdio.h>
#include <string.h>
#include <stdlib.h> // REQUIRED for exit(0)

#define PASS_FILE "password.txt"
#define USER_FILE "users.txt"

typedef struct {
    char username[50];
    char password[50];
    char phone[15];      // ✅ added phone field
    char role[20];       // "admin" or "agent"
} User;

// New function for user sign-up
void userSignup() {
    User newUser;
    FILE *fp = fopen(USER_FILE, "a");
    
    printf("\n=== USER SIGN UP ===\n");
    
    // Default role for new users is "agent"
    strcpy(newUser.role, "agent"); 

    printf("Enter Name (Username): ");
    scanf("%s", newUser.username);

    printf("Enter Phone Number: ");
    scanf("%s", newUser.phone);  // ✅ now actually reads phone

    printf("Enter Password: ");
    scanf("%s", newUser.password);
    
    // Simple check to prevent duplicate usernames
    if (strcmp(newUser.username, "admin") == 0) {
        printf("Username 'admin' is reserved. Please choose another.\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%s,%s,%s,%s\n", newUser.username, newUser.password, newUser.phone, newUser.role);
    fclose(fp);
    
    printf("Sign Up successful! You can now log in.\n");
}

// Modified function to return the role of the logged-in user
char* secureLogin(char* role) {
    char username[50], password[50];
    User currentUser;
    FILE *fp;
    
    printf("\n=== LOGIN ===\n");
    
    // First run - create admin if no users exist
    fp = fopen(USER_FILE, "r");
    if(fp == NULL) {
        fp = fopen(USER_FILE, "w");
        fprintf(fp, "admin,admin123,0000000000,admin\n"); // ✅ 4-field format
        fclose(fp);
        printf("Default admin created (admin/admin123)\n");
    } else {
        fclose(fp);
    }
    
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    
    fp = fopen(USER_FILE, "r");
    int authenticated = 0;
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%s\n", 
                currentUser.username, 
                currentUser.password,
                currentUser.phone,    // ✅ reads 4 fields
                currentUser.role) != EOF) {
        if(strcmp(username, currentUser.username) == 0 && 
           strcmp(password, currentUser.password) == 0) {
            authenticated = 1;
            strcpy(role, currentUser.role);
            printf("\nWelcome, %s! (%s)\n", username, currentUser.role);
            break;
        }
    }
    fclose(fp);
    
    if(!authenticated) {
        printf("Invalid credentials! Exiting...\n");
        exit(0);
    }
    
    return authenticated ? "Success" : "Failure";
}

void changePassword() {
    char username[50], oldPass[50], newPass[50];
    FILE *fp = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp_users.txt", "w");
    User u;
    int found = 0;
    
    printf("Change Password\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter old password: ");
    scanf("%s", oldPass);
    printf("Enter new password: ");
    scanf("%s", newPass);
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%s\n", u.username, u.password, u.phone, u.role) != EOF) {
        if(strcmp(username, u.username) == 0 && strcmp(oldPass, u.password) == 0) {
            strcpy(u.password, newPass);
            found = 1;
            printf("Password updated successfully!\n");
        }
        fprintf(temp, "%s,%s,%s,%s\n", u.username, u.password, u.phone, u.role);
    }
    
    fclose(fp);
    fclose(temp);
    
    if(found) {
        remove(USER_FILE);
        rename("temp_users.txt", USER_FILE);
    } else {
        remove("temp_users.txt");
        printf("Invalid username or password!\n");
    }
}