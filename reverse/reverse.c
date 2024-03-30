#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    else if (strcmp(argv[1] + strlen(argv[1]) - 4, ".wav") != 0)
    {
        printf("Input is not a WAV file.");
        return 1;
    }
    else if (strcmp(argv[2] + strlen(argv[2]) - 4, ".wav") != 0)
    {
        printf("Output is not a WAV file.");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Error opening the file %s.", argv[1]);
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, 1, sizeof(WAVHEADER), input);
    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Input is not a WAV file.");
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Error creating the file %s.", argv[2]);
        return 1;
    }
    // Write header to file
    // TODO #6
    fwrite(&header, 1, sizeof(WAVHEADER), output);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    // Write reversed audio to file
    // TODO #8
    BYTE block[block_size];
    int block_quantity = header.subchunk2Size / block_size;
    for (int i = 1; i <= block_quantity; i++)
    {
        fseek( input, -block_size * i, SEEK_END );
        fread( block, 1, block_size, input);
        fwrite( block, 1, block_size, output);
    }
    //Close
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if(header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * header.bitsPerSample / 8;
}
