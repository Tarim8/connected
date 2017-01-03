NAME
====

    connected ---- connect to programs like nc, telnet, ssh, php, with local Bash
style line editing and history


SYNOPSIS
========

    connected [-esc ESCAPE_CHAR] [-hist HISTORY_FILE] [-intr] [-askpass PASSWORD_PROGRAM] [-passfile PASSWORD_FILE] [-password PASSWORD] [-debug] [-notty NOTTY_PROGRAM] CONNECT_CMD


DESCRIPTION
===========

  connected is a program to connect to line based services, computer emulators
(like multics), games (like adventure or mud) or even php in interactive mode,
which don't otherwise provide line editing or history facilities.

  connected can also be used to provide a password to ssh in batch mode
(something that seems to be far harder than it ought to be otherwise).

  Tested with Bash under Linux, Mac (Darwin) and Cygwin (needs procps package
installed).


OPTIONS
=======
    -esc ESCAPE_CHAR
  Set escape character for escape commands:  

    -hist HISTORY_FILE
  Set history file (default is ~/.connected_history).

    -intr
  Allow interrupts {ctrl-C} to be passed through.

    -askpass PASSWORD_PROGRAM
  Sets program for ssh to get a password (ssh-askpass is good for GUI
environments) the default is to use this script.

    -passfile PASSWORD_FILE
  Reads a password from PASSWORD_FILE for ssh.

    -password PASSWORD
  Use PASSWORD as the password for ssh (not recomended as this is visible to
other users).
  
    -debug
  Print debug messages.

    -notty NOTTY_PROGRAM
  Sets a program to disconnect the controlling tty.  Used by ssh to force it to
get passwords and telnet to ignore interrupts in certain modes.  Default is to
use the provided program notty or setsid when this is available.

    -version
  Print version and exit.


ESCAPE COMMANDS
===============
  Can only be sent at the beginning of a line:

    ~e
  Turn off echo and don't record line in history.

    ~r
  Enter raw mode.

    ~{ctrl-J}
  Exit raw mode (sent anywhere in a line).

    ~{uppercase character}
  Send corresponding control character.

    ~~...
  Strip leading ~ and send rest of line.

    ~q
  Quit.

    {ctrl-D}
  Quit.


FILES
=====
  `~/.connected_history` is the default file for the command history.

  `notty` is a program to disconnect the controlling tty before running a
command.


CAVEATS
=======
  The exit from raw mode is somewhat ungainly - it still sends `~{ctrl-J}`
before exiting.


AUTHOR
======
  Written by Tarim.
  Error reports to <connected-cmd@mediaplaygrounds.co.uk>.


SEE ALSO
========
  readline(3), bash(1)

