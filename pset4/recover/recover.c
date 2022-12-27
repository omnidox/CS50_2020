#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("please put in a jpeg\n");
        return 1;
    }


    FILE *rfile = fopen(argv[1], "r");

    if (!rfile)
    {
        printf("no file found\n");
        return 1;
    }


    // start of file number
    int file_num = 0;
    
    BYTE buffer[512];
    
    FILE *wfile;
    
    bool is_first_jpeg = true;
    
    while (fread(buffer, 512, 1, rfile))
    {
    
    
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (is_first_jpeg == true)
            {
                is_first_jpeg = false;
                
            }       
            else
            {
                fclose(wfile);
            }
                 
            char files[8];
                 
            sprintf(files, "%03i.jpg", file_num++);
                 
            wfile = fopen(files, "w");
                 
            if (!wfile)
            {
                return 1;
            }
                    
            fwrite(buffer, 512, 1, wfile);
        }   
            
        else if (is_first_jpeg == false)
        {
            fwrite(buffer, 512, 1, wfile);
        }
            
    }
    
    fclose(wfile);
    fclose(rfile);
                 
                
                    
                    
                    
                    
                        
                    
                  
            
}
    
// Filenames: ###.jpg, starting at 000.jpg

// sprintf(filename, "%03i.jpg" , 2);

// FILE *img = fopen(filename, "w");

// fwrite(data, size, number, outptr);

// 1. data: pointer to bytes that will be written to file

// 2. Size: size of each element to write

// 3. number of elements to write

//4. outptr: FILE * to write to

// fread(data, size, number, inptr);

// 1. data: pointer to where to store data you're reading

// 2. Size: size of each element to read

// 3. number of elements to read

//4. inptr: FILE * to read from
    




