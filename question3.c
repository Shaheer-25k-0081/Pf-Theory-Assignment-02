#include<stdio.h>
#define powerOn 1
#define Overload 2
#define Maintenance 4

void updateSector(int grid[10][10],int rows,int columns){
    int row, column, flag, action;
    printf("Enter Sector Coordinates(row[0-%d],column[0-%d])", rows-1, columns-1);
    scanf("%d %d", &row, &column);
    if(row<0 || column<0 || row>=rows || column>=columns){
        printf("Invalid Cooradinates");
        return;
    }
    printf("Select Status Flag\n1. Power status\n2. Overload warning\n3. Maintenance required\n");
    scanf("%d", &flag);

    printf("Press: 1.To SET Flag\t2.To CLEAR flag\n");
    scanf("%d", &action);

    int mask=1 << (flag-1);
    if(action==1){
        grid[row][column] |=mask;
    }
    else{
        grid[row][column] &=mask;
    }
    printf("Sector[%d][%d] Updated Succesfully\n", row, column);
}


void querySector(int grid[10][10],int  rows,int columns){
    int row, column;
    printf("Enter Sector Coordinates(row[0-%d],column[0-%d]): ", rows-1, columns-1);
    scanf("%d %d", &row, &column);
     if(row<0 || column<0 || row>=rows || column>=columns){
        printf("Invalid Cooradinates");
        return;
    }
    int status =grid[row][column];
    printf("Sector[%d][%d] Status Report\n",row, column);
    printf("Power: %s\n",(status&powerOn)?"ON":"OFF");
    printf("Overload: %s\n",(status&Overload)?"YES":"NO");
    printf("Maintenance Required: %s\n",(status&Maintenance)?"YES":"NO");
}


void diagnostic(int grid[10][10],int rows,int columns){
    int overloadCount=0,maintenanceCount=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(grid[i][j]&Overload){
                overloadCount++;
            }
            if(grid[i][j]&Maintenance){
                maintenanceCount++;
            }
        }
    }
    printf("Diagnostic Report\n\n");
    printf("Total Overload Sectors: %d\nTotal Sectors Requiring Maintenance: %d\n",overloadCount,maintenanceCount);
}


int main(){
    int grid[10][10]={0};
    int choice;
    printf("--------IESCO POWER GRID MONITORING SYSTEM--------\n\n");
    do{
        printf("1. Update Sector Status\n2. Query Sector Status\n3. Run System Diagnostic\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            updateSector(grid,10,10);
            break;
        case 2:
            querySector(grid, 10, 10);
            break;
        case 3:
            diagnostic(grid, 10, 10);
            break;
        case 4:
            printf("System Exited");
            break;
        default:
            printf("Invalid Choice\n Please Enter Again (1-4)");
            break;
        }
    }while(choice!=4);
    return 0;
}