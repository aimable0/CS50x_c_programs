#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// Structs
typedef uint8_t BYTE;

// Entry point
int main(int argc, char *argv[])
{
    // Accept exactly 2 command line argument.
    if (argc != 2)
    {
        printf("Usage: ./recover inputfile\n");
        return 1;
    }

    // Open the card file.
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    // buffer creation
    BYTE buffer[512];

    //! TEst
    BYTE *buffer1 = malloc(512);
    // printf("sizeof(buffer1 with malloc): %zu\n", sizeof(buffer1));
    // printf("sizeof(buffer static): %zu\n", sizeof(buffer));

    // image naming
    int i = 0;
    int k = 0;
    char image_name[8]; // image name template
    int count = 0;      // images

    // ptr to image file.
    FILE *outfile = NULL;

    bool first_image_copied = false; // to confirm if the first file was opened.

    int times_run = 0;
    // keep track of images recoverd.
    while (fread(buffer, sizeof(buffer), 1, fp) == 1)
    {
        // check first 4 bytes.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (first_image_copied)
                fclose(outfile); // close previous image.

            // image name
            if (i > 9)
                i = 0;
            if (count != 0 && count % 10 == 0)
                k++;

            sprintf(image_name, "0%i%i.jpg", k, i++);

            // open new file
            outfile = fopen(image_name, "w");

            if (!outfile)
            {
                perror("fopen failed");
                return 1;
            }

            fwrite(buffer, sizeof(buffer), 1, outfile);
            first_image_copied = true;
            count++;
        }
        if (outfile)
            fwrite(buffer, sizeof(buffer), 1, outfile);

        //! Test
        times_run++;
    }


    //! TEst
    printf("Run: %d times\n", times_run);
    // free(buffer1);

    // close the files.
    fclose(outfile);
    fclose(fp);
    return 0;
}
