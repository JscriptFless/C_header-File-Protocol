#ifndef FILE_PROTOCOL
#define FILE_PROTOCOL

    #ifdef _cplusplus
        extern "c" {
    #endif 

    // Include libraries.
    #include <stdio.h>
    #include <string.h>

    // Redefine FILE type as a lowercase standard.
    typedef FILE file;

    // fProto write func ( filename, text ) is a simplified version of the C standard io functions.
    void fProto_write ( char filename_w[100], char text_w[1000] ) {
        // Error message concatenation.
        static char fileError_w[100] = "Could not write to file: ";
        strcat ( fileError_w, filename_w );

        // Main func code.
        static file *f;
        f = fopen ( filename_w, "w+" );

        // File is obtainable.
        if ( f != NULL ) {
            fprintf ( f, text_w );
            fclose ( f );
        }

        // File is unobtainable.
        else if ( f == NULL ) {
            perror ( fileError_w );
        }

        else {
            perror ( "An unknown error has occured." );
        }
    }

    // fProto add func ( filename, text ) is a simplified version of the C standard io functions.
    void fProto_add ( char filename_a[100], char text_a[1000] ) {
        // Error message concatenation.
        static char fileError_a[100] = "Could not add text to file: ";
        strcat ( fileError_a, filename_a );

        // Main func code.
        static file *f;
        f = fopen ( filename_a, "a+" );

        // File is obtainable.
        if ( f != NULL ) {
            fseek ( f, 0, SEEK_END );
            fputs ( text_a, f );
            fclose( f );
        }

        // File is unobtainable.
        else if ( f == NULL ) {
            perror ( fileError_a );
        }

         else {
            perror ( "An unknown error has occured." );
        }
    }

    // fProto read func ( filename ) is a simplified version of the C standard io functions.
    void fProto_read ( char filename_r[100] ) {
        // Error message concatenation.
        static char fileError_r[100] = "Could not read file: ";
        strcat ( fileError_r, filename_r );

        // Main func code.
        static char read_buffer[1000];
        static file *f;
        f = fopen ( filename_r, "r" );

        // File is obtainable.
        if ( f != NULL ) {
            fgets ( read_buffer, 1000, f );
            printf ( "%s", read_buffer );
            fclose ( f );
        }

        // File is unobtainable.
        else if ( f == NULL ) {
            perror ( fileError_r );
        }

         else {
            perror ( "An unknown error has occured." );
        }
    }

    void fProto_delete ( char filename_d[100] ) {
        // Error message concatenation.
        static char fileError_d[100] = "Could no delete file: ";
        strcat ( fileError_d, filename_d );

        // If true.
        if (!0) {
            remove ( filename_d );
        } 
        
        // If the remove function has returned unsuccessful, then display error.
        else if ( remove ( filename_d ) != 0) {
            perror (fileError_d);
        } 
        
        // Unknown error.
        else {
            perror ( "An unknown error has occured." );
        }
    }

    #ifdef _cplusplus
        }
    #endif

#endif // FILE_PROTOCOL
