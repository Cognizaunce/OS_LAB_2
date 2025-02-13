#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

void testcase_input(char *input){
    execute_command(input);
}

void test1() {
    //tests cd 
    printf("cd with no directory\n");
    testcase_input("cd");

    printf("cd with directory \n");
    testcase_input("cd /");

    printf("cd with directory that does not exist\n");
    testcase_input("cd /invalid_directory");
}

void test2() {
    //tests clear
    printf("clear screen\n");
    testcase_input("clr");
}

void test3() {
    //tests dir
    printf("dir with no directory\n");
    testcase_input("dir");

    printf("dir with a directory\n");
    testcase_input("dir /");
}

void test4() {
    //tests env
    printf("environment variable \n");
    testcase_input("environ");
}

void test5() {
    //tests echo
    printf("echo \n");
    testcase_input("echo "hello world" ");
}

void test6() {
    //tests help
    printf("help \n");
    testcase_input("help");
}

void test7() {
    //tests pause
    printf("pause\n");
    testcase_input("pause");
}

void test8() {
    //tests quit
    printf("quit\n");
    testcase_input("quit");
}

void test9() {
    //test if unknown command in given
    printf("unknown command\n");
    testcase_input("invalid_command");
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