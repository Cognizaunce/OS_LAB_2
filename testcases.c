#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static char buffer[1024];

void testcase_input(char *input){
    snprintf(buffer, sizeof(buffer), "%s", "");
    execute_command(input);
}

void testcase_check(char *output){
    assert(strcmp(buffer,output) == 0);
}

void test1() {
    //tests cd 
    printf("cd with no directory\n");
    testcase_input("cd");
    testcase_check("output_string"); //replace with expected output

    printf("cd with directory \n");
    testcase_input("cd /");
    testcase_check("output_string"); //replace with expected output

    printf("cd with directory that does not exist\n");
    testcase_input("cd /invalid_directory");
    testcase_check("No such file or directory"); //replace with expected output
}

void test2() {
    //tests clear
    printf("clear screen\n");
    testcase_input("clr");
    testcase_check("\033[H\033[J"); 
}

void test3() {
    //tests dir
    printf("dir with no directory\n");
    testcase_input("dir");
    testcase_check("output_string"); //replace with expected output

    printf("dir with a directory\n");
    testcase_input("dir /");
    testcase_check("output_string"); //replace with expected output
}

void test4() {
    //tests env
    printf("environment variable \n");
    testcase_input("environ");
    testcase_check("output_string"); //replace with expected output
}

void test5() {
    //tests echo
    printf("echo \n");
    testcase_input("echo "hello world" ");
    testcase_check("hello world \n"); 
}

void test6() {
    //tests help
    printf("help \n");
    testcase_input("help");
    testcase_check("output_string"); //replace with expected output
}

void test7() {
    //tests pause
    printf("pause\n");
    testcase_input("pause");
    testcase_check("output_string"); //replace with expected output
}

void test8() {
    //tests quit
    printf("quit\n");
    testcase_input("quit");
    testcase_check("exiting myShell \n"); 
}

void test9() {
    //test if unknown command in given
    printf("unknown command\n");
    testcase_input("invalid_command");
    testcase_check("Command not recognized \n"); 
}


int main() {
    // Runs all test functions
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}