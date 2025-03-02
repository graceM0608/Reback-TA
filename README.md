# AV Technical

### **Submission Date**: 15/03/2025 11:59PM
### **Submission Instructions**: Look at the Submission sub-heading below

An important engineering skill is to be able to fix and resolve issues that pop up through research (i.e googling and experimenting). The AV task will test your ability to read, debug and resolve C++ compile time errors as well as runtime errors. Attached to this project is a broken code base. It's your task to fix each of the bugs in it.

You do not need prior or extensive knowledge of C++ to complete this task. This task will test how well you can figure out issues even if you've never seen them or never worked with them before.

# Problems

There are 4 questions attached each. Each one is more increasingly difficult than the other. Question 3 and 4 are the extended tasks for those particularly keen on pushing and demonstrating their ability. Remember to read each question carefully and understand what is required.

Please use CMake to compile (do not use g++ or any other compilers). Attached are some useful resources which should help you start (but you can figure a lot of this out by just googling).

Each question has a description of the task in its C++ file. Please reach out to the AV team with any questions.

# **Submission**  
As part of this technical assessment, you need to set up Git for the entire AV Technical Assessment and create a **public GitHub repository** where you will submit your work.  

### **Requirements:**  
- Initialize Git in your project directory.  
- Ensure that your **build directory is ignored** using a `.gitignore` file.  
- Commit your work and push it to a **public GitHub repository**.
- Before submitting, run `git status` to check for any local changes and push all updates to ensure your latest work is visible.  
- Submit the repository link once completed.
- Only commits made up to March 15, 2025, 11:59 PM will be considered.  

To help you get started, here are some useful resources:  
- [Git Basics in 10 Minutes](https://www.freecodecamp.org/news/learn-the-basics-of-git-in-under-10-minutes-da548267cc91/)  
- [Setting Up Git](https://docs.github.com/en/get-started/getting-started-with-git/set-up-git)  
- [Creating a GitHub Repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository)  
- [GitHub Quickstart Guide](https://docs.github.com/en/repositories/creating-and-managing-repositories/quickstart-for-repositories)  

## **Submission Link:** [https://forms.office.com/r/gt5xySzQCA](https://forms.office.com/r/gt5xySzQCA)  

# How to Compile

To compile with CMake create a build folder using

`mkdir build`

and then run CMake

`cmake CMakeLists.txt -B build/`

This will generate a bunch of files in the build folder. Just change directory into the build folder using

`cd build`

and then compile using make

`make`

This should generate a bunch of executables `Question-1-out`, `Question-2-out`, `Question-3-out`, and `Question-4-out` upon success. For question 1 specifically it will generate a bunch of compilation errors which you need to fix.


# How to Submit
Zip the file, and upload using the google form above. Please avoid including build files

# Some useful resources

https://www.learncpp.com/ (Use this as a resource for this unfamiliar with C++)

https://en.cppreference.com/w/cpp/language

Intro to git: https://opensource.com/article/18/1/step-step-guide-git

Introduction to CMake: https://cliutils.gitlab.io/modern-cmake/ (there is a section on Googletests as well)

Install google test: https://github.com/google/googletest/tree/main/googletest

Basic Cmake tutorial (This is all you should really need for cmake): https://matgomes.com/cmake-add-executable/
