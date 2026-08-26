#include "library_miri6_1.h"

int main() {
    FILE *file_read, *out, *bin, *bin_out, *bin_out2;
    char group[20];
    printf("Enter name of the group: \n");
    scanf("%s", group);

    file_read = fopen("read6_1.txt", "r");
    if (!file_read) {printf("Error! File read6_1.txt not found\n");}
    bin = fopen("read_bin_6_1.bin", "wb");
    if (!bin) {printf("Error! File read_bin_6_1.bin not found\n");}
    out = fopen("out6_1.txt", "w");
    if (!out) {printf("Error! File out6_1.txt not found\n");}

    to_bin(file_read, bin);
    fclose(bin);

    bin = fopen("read_bin_6_1.bin", "rb");
    if (!bin) {printf("Error! File read_bin_6_1.bin not found\n");}
    bin_out = fopen("out_bin_6_1.bin", "wb");
    if (!bin_out) {printf("Error! File out_bin_6_1.bin not found\n");}

    int count = check(group, bin, bin_out);
    fclose(bin_out);

    bin_out = fopen("out_bin_6_1.bin", "rb");
    if (!bin_out) {printf("Error! File out_bin_6_1.bin not found\n");}
    
    fprintf(out, "GROUP: %s\n", group);
    if (count) {
        fprintf(out, "Students who have at least one grade of 3:\n");
        file_out(bin_out, out);
    }
    else {fprintf(out, "\nIn group %s all students without grade 3 and less\n", group);}

    fclose(bin_out);

    //удалить всех троечников
    fseek(bin, 0, SEEK_SET);
    bin_out2 = fopen("out_bin_6_1pr.bin", "r+b");
    if (!bin_out2) {printf("Error! File out_bin_6_1pr.bin not found\n");}

    int count_del = del_student(bin, bin_out2);
    fclose(bin_out2);

    bin_out2 = fopen("out_bin_6_1pr.bin", "rb");
    if (!bin_out2) {printf("Error! File out_bin_6_1pr.bin not found\n");}
    printf("%i", count_del);
    if (count_del) {
        fprintf(out, "\n\nStudents who haven't at least one grade of 3:\n");
        out_out(bin_out2, out);
    }
    else {fprintf(out, "\n\nThe all students with grade 3 and less\n");}

    fclose(bin_out2);
    fclose(out);
    fclose(bin);
    return 0;
}