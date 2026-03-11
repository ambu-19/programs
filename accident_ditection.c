#include <stdio.h>
#include <string.h>

// Structure to store accident data
struct AccidentReport {
    float impactForce;     // Impact measured by sensor
    char location[50];     // GPS location
    char alertMessage[100];
};

// Function to detect accident
int detectAccident(float impact) {
    if (impact > 50.0) {   // Threshold value
        return 1;          // Accident detected
    }
    return 0;
}

// Function to generate GPS location (demo purpose)
void getGPSLocation(char loc[]) {
    strcpy(loc, "Latitude: 18.5204, Longitude: 73.8567"); // Pune sample location
}

// Function to create alert message
void sendAlert(struct AccidentReport report) {
    printf("\n=== EMERGENCY ALERT SENT ===\n");
    printf("Impact Force: %.2f\n", report.impactForce);
    printf("Location: %s\n", report.location);
    printf("Message: %s\n", report.alertMessage);
    printf("===================================\n");
}

int main() {
    struct AccidentReport report;
    float force;

    printf("Enter Impact Force Detected by Sensor: ");
    scanf("%f", &force);

    report.impactForce = force;

    if (detectAccident(force)) {
        getGPSLocation(report.location);

        strcpy(report.alertMessage,
               "Accident detected! Send ambulance immediately!");

        sendAlert(report);
    } else {
        printf("\nNo accident detected. System running normally.\n");
    }

    return 0;
}
