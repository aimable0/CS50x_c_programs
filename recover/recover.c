#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    size_t size = 512;
    size_t nmemb = 1;
    int succ_read;

    FILE *fp = fopen("card.raw", "r");
    FILE *outfile = fopen("output.raw", "w");
    if (!fp || !outfile)
        return 1;

    BYTE buffer[512];

    while (fread(buffer, sizeof(buffer), nmemb, fp))
    {
        
        fwrite(buffer, sizeof(buffer), nmemb, outfile);
    }

    // close the files.
    fclose(outfile);
    fclose(fp);
    return 0;
}
