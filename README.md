# CS1332_CPP

## Description:

This repo will be my attempt to redo GATech's CS1332 in C++ in preparation for Data Structures and Algorithms interview questions.
The purpose of this repo is to make sure that everything that was taught in the course is in my head and can be translated into 
a different langugage and try and see if I can adhere to Test Driven Development (TDD).

### Frameworks and Setup:

To replicate the homeworks from this course, we will be using googletest as a replacement to Java's JUnits.

Setup Steps:
- There is already an entry in the .gitignore for a googletest directory once we clone into the current directory as well as a build directory for cmake. So we need to first clone googletest repo using the command
    ```
    git clone git@github.com:google/googletest.git
    ```
- This should be everything needed atleast to get the main branch started. All other branches will branch from main and will have their own structures depending on the topic of the branch.