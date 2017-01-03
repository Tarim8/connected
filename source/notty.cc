// notty
//
// Copyright Tarim 2016
//
// Notty is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Notty is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Notty.  If not, see <http://www.gnu.org/licenses/>.

// Inspired by Konrad Rosenbaum's http://silmor.de/notty.php

#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main( int argc, char** argv ) {
    // give usage if no command given
    if( argc < 2 ) {
        fprintf( stderr, "Usage: %s command [arguments...]\n", argv[0] );
        return 2;
    }

    // open controlling tty
    int fd = open( "/dev/tty", O_RDWR );
    if( fd >= 0 ) {
        // detach controlling tty
        if( ioctl( fd, TIOCNOTTY ) ) {
            perror( "Unable to detach TTY" );
        }

        close( fd );
    }

    // run the command
    execvp( argv[1], argv+1 );

    // Only returns if it can't execute
    perror( argv[1] );
    return 1;
}
