#include <stdio.h>

int main() {
    printf("Nasus\n");
    // create a FILE typed pointer
    FILE *file_pointer;
    char str[] ="";
    scanf("%s", str);
    // open the file "name_of_file.txt" for writing
    printf("%s\n",str);
    file_pointer = fopen(str, "w");
//GET SUBSTRING
    // Write to the file
    fprintf(file_pointer, "This will write to a file.");
    // Close the file
    fclose(file_pointer);


    return 0;
}