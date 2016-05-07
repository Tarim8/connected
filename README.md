NAME
====

  connected ---- connect to programs like nc, telnet, ssh, php, with local Bash
style line editing and history


SYNOPSIS
========

  connected [-esc ESCAPE_CHAR] [-hist HISTORY_FILE] [-int] [-debug] CONNECT_CMD


DESCRIPTION
===========

  connected is a program to connect to line based services, computer emulators
(like multics), games (like adventure or mud) or even php in interactive mode,
which don't otherwise provide line editing or history facilities.

  Tested with Bash under Linux, Mac (Darwin) and Cygwin (needs procps package
installed).


OPTIONS
=======
    -esc
  set escape character for escape commands:  

    -hist
  set history file (default is ~/.connected_history)

    -intr
  allow interrupts {ctrl-C} to be passed through

    -debug
  print debug messages

    -version
  print version and exit


ESCAPE COMMANDS
===============
  Can only be sent at the beginning of a line:

    ~e
  turn off echo and don't record line in history

    ~r
  enter raw mode

    ~{ctrl-J}
  exit raw mode (sent anywhere in a line)

    ~{uppercase character}
  send corresponding control character

    ~~...
  strip leading ~ and send rest of line

    ~q
  quit

    {ctrl-D}
  quit


FILES
=====
  `~/.connected_history` is the default file for the command history.


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

