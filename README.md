# SP-demo
This is my first Git repository

This is a project of digital clock using C programming language. The logic
behind to implement this program, Initialize hour, minute, seconds with
0. Run an infinite loop. Increase second and check if it is equal to 60 then
increase minute and reset second to 0.

Let’s break down the provided C code step by step to understand what it does:

This C program creates a simple digital clock that continuously displays the current time in the format `HH:MM:SS`, updating every second. Here’s a detailed explanation of each part:

1. **Header Files (Implicitly Required)**:
   - The code uses functions like `time()`, `localtime()`, `printf()`, `fflush()`, and `sleep()`. These require the following header files, which are not shown but are necessary:
     ```c
     #include <stdio.h>    // for printf() and fflush()
     #include <time.h>     // for time(), localtime(), and time_t, struct tm
     #include <unistd.h>   // for sleep() (on Unix-like systems)
     ```
   - If you’re running this on a non-Unix system (e.g., Windows), `sleep()` may require a different header or function (e.g., `Sleep()` from `<windows.h>`).

2. **Variable Declarations**:
   - `time_t rawtime;`: Declares a variable `rawtime` of type `time_t`, which is used to store the current time in seconds since the Unix epoch (January 1, 1970, 00:00:00 UTC).
   - `struct tm *timeinfo;`: Declares a pointer to a `struct tm`, which is a structure used to hold a broken-down time (e.g., hours, minutes, seconds).

3. **Infinite Loop (`while(1)`)**:
   - The `while(1)` creates an infinite loop, meaning the program will keep running until manually stopped (e.g., with Ctrl+C in the terminal).

4. **Getting the Current Time**:
   - `time(&rawtime);`: Calls the `time()` function, which retrieves the current system time and stores it in `rawtime`. The `time_t` type typically represents the number of seconds since the Unix epoch.
   - `timeinfo = localtime(&rawtime);`: Converts the raw time (`rawtime`) into a `struct tm` structure, adjusted for the local time zone. The `localtime()` function populates `timeinfo` with fields like `tm_hour`, `tm_min`, and `tm_sec`.

5. **Printing the Time**:
   - `printf("\r%02d:%02d:%02d:", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);`:
     - This prints the current time in the format `HH:MM:SS:`.
     - `\r`: Moves the cursor to the beginning of the current line, so each new time overwrites the previous one, creating the effect of a continuously updating clock.
     - `%02d`: Formats each time component (hours, minutes, seconds) as a two-digit number, padding with zeros if necessary (e.g., `5` becomes `05`).
     - `timeinfo->tm_hour`, `timeinfo->tm_min`, `timeinfo->tm_sec`: Accesses the hour, minute, and second fields from the `struct tm` structure.
     - The trailing `:` in the format string appears unnecessary and may be a typo, as it adds an extra colon at the end of the output (e.g., `12:34:56:`).

6. **Flushing the Output**:
   - `fflush(stdout);`: Forces the output buffer to be written to the console immediately. Without this, the `printf` output might be delayed due to buffering, causing the clock to update irregularly.

7. **Pausing Execution**:
   - `sleep(1);`: Pauses the program for 1 second before the next iteration of the loop. This ensures the time updates approximately once per second.

8. **Return Statement**:
   - `return 0;`: Indicates successful program termination. However, since the program runs in an infinite loop, this line is never reached unless the loop is broken (e.g., by an external signal).

### What the Program Does
- The program continuously fetches the current system time, converts it to the local time zone, and prints it in `HH:MM:SS:` format.
- The `\r` in the `printf` ensures the time is overwritten on the same line, creating a real-time clock effect in the console.
- The loop runs indefinitely, updating the time every second, until the program is manually terminated.

### Example Output
If the current time is 14:35:22, the console will display:
```
14:35:22:
```
One second later, it might update to:
```
14:35:23:
```
This continues, with the time being overwritten on the same line.

