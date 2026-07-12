// SMART WASTE MANAGEMENT SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ─────────────────────────────────────────────
   CONSTANTS
   ───────────────────────────────────────────── */
#define MAX_BINS     50
#define LOG_FILE     "cleaning_log.txt"
#define WARNING_LEVEL 80
#define FULL_LEVEL   100

/* ─────────────────────────────────────────────
            DATA HANDLING
   Structure definition for a Bin
   ───────────────────────────────────────────── */
typedef struct {
    int  id;
    char location[100];
    int  fillLevel;   /* 0 to 100 (percentage) */
} Bin;

/* Global bin array and count */
Bin  bins[MAX_BINS];
int  binCount = 0;

/* ─────────────────────────────────────────────
   UTILITY: clear input buffer
   ───────────────────────────────────────────── */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ─────────────────────────────────────────────
   UTILITY: print a horizontal line
   ───────────────────────────────────────────── */
void printLine(void) {
    printf("------------------------------------------------------------\n");
}

/* ─────────────────────────────────────────────
   UTILITY: find bin index by ID (-1 if not found)
   ───────────────────────────────────────────── */
int findBinIndex(int id) {
    for (int i = 0; i < binCount; i++) {
        if (bins[i].id == id)
            return i;
    }
    return -1;
}

/* ─────────────────────────────────────────────
   UTILITY: get status label for a fill level
   ───────────────────────────────────────────── */
const char* getStatus(int fillLevel) {
    if (fillLevel == FULL_LEVEL)    return "** FULL **";
    if (fillLevel >= WARNING_LEVEL) return "! WARNING !";
    return "OK";
}

/* ==============================================================
                     FUNCTION: Add a new bin
   ============================================================== */
void addBin(void) {
    printLine();
    printf("          ADD NEW BIN\n");
    printLine();

    if (binCount >= MAX_BINS) {
        printf("[ERROR] Maximum bin limit (%d) reached.\n", MAX_BINS);
        return;
    }

    int newId;
    printf("Enter Bin ID       : ");
    if (scanf("%d", &newId) != 1) {
        printf("[ERROR] Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    /* Check for duplicate ID */
    if (findBinIndex(newId) != -1) {
        printf("[ERROR] Bin with ID %d already exists.\n", newId);
        return;
    }

    printf("Enter Location     : ");
    fgets(bins[binCount].location, sizeof(bins[binCount].location), stdin);
    /* Strip trailing newline */
    bins[binCount].location[strcspn(bins[binCount].location, "\n")] = '\0';

    bins[binCount].id        = newId;
    bins[binCount].fillLevel = 0;     /* New bin starts empty */
    binCount++;

    printf("\n[SUCCESS] Bin %d at '%s' added successfully.\n",
           newId, bins[binCount - 1].location);
}

/* ==============================================================
                 FUNCTION: Display all bins
   ============================================================== */
void displayAllBins(void) {
    printLine();
    printf("          ALL BINS STATUS\n");
    printLine();

    if (binCount == 0) {
        printf("No bins registered yet.\n");
        return;
    }

    printf("%-8s %-25s %-12s %-12s\n",
           "Bin ID", "Location", "Fill Level", "Status");
    printLine();

    for (int i = 0; i < binCount; i++) {
        printf("%-8d %-25s %3d%%        %s\n",
               bins[i].id,
               bins[i].location,
               bins[i].fillLevel,
               getStatus(bins[i].fillLevel));
    }
    printLine();
}

/* ==============================================================
             FUNCTION: Update fill level of a bin
   ============================================================== */
void updateFillLevel(void) {
    printLine();
    printf("          UPDATE FILL LEVEL\n");
    printLine();

    if (binCount == 0) {
        printf("No bins registered. Please add bins first.\n");
        return;
    }

    int id;
    printf("Enter Bin ID to update : ");
    if (scanf("%d", &id) != 1) {
        printf("[ERROR] Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBinIndex(id);
    if (idx == -1) {
        printf("[ERROR] Bin with ID %d not found.\n", id);
        return;
    }

    int level;
    printf("Enter new fill level (0-100) : ");
    if (scanf("%d", &level) != 1 || level < 0 || level > 100) {
        printf("[ERROR] Invalid fill level. Must be between 0 and 100.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    bins[idx].fillLevel = level;
    printf("\n[SUCCESS] Bin %d fill level updated to %d%%.\n", id, level);

    /* Immediately show alert if threshold crossed */
    if (level == FULL_LEVEL) {
        printf("[ALERT]  Bin %d (%s) is COMPLETELY FULL! Immediate collection required.\n",
               bins[idx].id, bins[idx].location);
    } else if (level >= WARNING_LEVEL) {
        printf("[WARNING] Bin %d (%s) is nearly full (%d%%). Schedule collection soon.\n",
               bins[idx].id, bins[idx].location, level);
    }
}

/* ==============================================================
             FUNCTION: Check and display all alerts
   ============================================================== */
void checkAlerts(void) {
    printLine();
    printf("          ALERT SYSTEM\n");
    printLine();

    if (binCount == 0) {
        printf("No bins registered.\n");
        return;
    }

    int alertCount = 0;

    for (int i = 0; i < binCount; i++) {
        if (bins[i].fillLevel == FULL_LEVEL) {
            printf("[FULL]    Bin %-4d | %-25s | %3d%% | Immediate collection required!\n",
                   bins[i].id, bins[i].location, bins[i].fillLevel);
            alertCount++;
        } else if (bins[i].fillLevel >= WARNING_LEVEL) {
            printf("[WARNING] Bin %-4d | %-25s | %3d%% | Schedule collection soon.\n",
                   bins[i].id, bins[i].location, bins[i].fillLevel);
            alertCount++;
        }
    }

    if (alertCount == 0) {
        printf("All bins are within safe fill levels. No alerts.\n");
    } else {
        printf("\nTotal alerts : %d\n", alertCount);
    }
    printLine();
}

/* ==============================================================
                 FUNCTION: Generate report
   ============================================================== */
void generateReport(void) {
    printLine();
    printf("          BIN REPORT\n");
    printLine();

    if (binCount == 0) {
        printf("No bins registered.\n");
        return;
    }

    int   totalFill  = 0;
    int   maxFill    = -1;
    int   maxIdx     = 0;
    int   fullCount  = 0;
    int   warnCount  = 0;

    for (int i = 0; i < binCount; i++) {
        totalFill += bins[i].fillLevel;

        if (bins[i].fillLevel > maxFill) {
            maxFill = bins[i].fillLevel;
            maxIdx  = i;
        }
        if (bins[i].fillLevel == FULL_LEVEL)    fullCount++;
        else if (bins[i].fillLevel >= WARNING_LEVEL) warnCount++;
    }

    float avgFill = (float)totalFill / binCount;

    printf("Total Bins         : %d\n",   binCount);
    printf("Average Fill Level : %.1f%%\n", avgFill);
    printf("Bins at FULL       : %d\n",   fullCount);
    printf("Bins at WARNING    : %d\n",   warnCount);
    printf("Bins OK            : %d\n",   binCount - fullCount - warnCount);
    printLine();
    printf("Most Filled Bin    : ID %d | %s | %d%%\n",
           bins[maxIdx].id, bins[maxIdx].location, bins[maxIdx].fillLevel);
    printLine();
}

/* ==============================================================
             FUNCTION: Log a cleaning event to file
   ============================================================== */
void logCleaning(void) {
    printLine();
    printf("          LOG CLEANING EVENT\n");
    printLine();

    if (binCount == 0) {
        printf("No bins registered.\n");
        return;
    }

    int id;
    printf("Enter Bin ID that was cleaned : ");
    if (scanf("%d", &id) != 1) {
        printf("[ERROR] Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBinIndex(id);
    if (idx == -1) {
        printf("[ERROR] Bin with ID %d not found.\n", id);
        return;
    }

    /* Get current date and time */
    time_t now     = time(NULL);
    char   timeBuf[64];
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&now));

    /* Write to log file */
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        printf("[ERROR] Could not open log file.\n");
        return;
    }

    fprintf(fp, "[%s] Bin ID: %-4d | Location: %-25s | Fill before clean: %d%%\n",
            timeBuf, bins[idx].id, bins[idx].location, bins[idx].fillLevel);
    fclose(fp);

    /* Reset fill level after cleaning */
    bins[idx].fillLevel = 0;

    printf("[SUCCESS] Cleaning logged for Bin %d (%s). Fill level reset to 0%%.\n",
           bins[idx].id, bins[idx].location);
}

/* ==============================================================
            FUNCTION: View cleaning logs from file
   ============================================================== */
void viewLogs(void) {
    printLine();
    printf("          CLEANING LOG HISTORY\n");
    printLine();

    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("No cleaning logs found. Log file does not exist yet.\n");
        return;
    }

    char line[300];
    int  count = 0;

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("Log file is empty.\n");
    } else {
        printLine();
        printf("Total log entries : %d\n", count);
    }
    printLine();
}

/* ==============================================================
                FUNCTION: Display main menu
   ============================================================== */
void displayMenu(void) {
    printf("\n");
    printLine();
    printf("      SMART WASTE MANAGEMENT SYSTEM\n");
    printLine();
    printf("  1. Add Bin\n");
    printf("  2. Update Fill Level\n");
    printf("  3. View All Bins\n");
    printf("  4. Check Alerts\n");
    printf("  5. Generate Report\n");
    printf("  6. Log Cleaning Event\n");
    printf("  7. View Cleaning Logs\n");
    printf("  8. Exit\n");
    printLine();
    printf("  Enter your choice : ");
}

/* ==============================================================
            MAIN: Program entry point and menu loop
   ============================================================== */
int main(void) {
    int choice;

    printf("\n  Welcome to the Smart Waste Management System\n");

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("[ERROR] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        printf("\n");

        switch (choice) {
            case 1: addBin();          break;
            case 2: updateFillLevel(); break;
            case 3: displayAllBins();  break;
            case 4: checkAlerts();     break;
            case 5: generateReport();  break;
            case 6: logCleaning();     break;
            case 7: viewLogs();        break;
            case 8:
                printf("  Exiting... Goodbye!\n\n");
                return 0;
            default:
                printf("[ERROR] Invalid choice. Please select 1-8.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}