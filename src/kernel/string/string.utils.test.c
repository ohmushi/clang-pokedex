#include <assert.h>
#include "string.utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../../test/test.h"
#include "split/split.h"

void testValue();
void testLength();
void testStringsAreEquals();
void itShouldCreateEmptyString();
void itShouldCreateEmptyStringWhenValueIsNull();
void isShouldCheckIfEmptyString();
void isShouldCreateFormattedString();
void itShouldPushInArray();
void itShouldGetNullForIndexOutOfBoundInStringArray();
void itShouldSplitString();

int main() {
    testLength();
    testValue();
    testStringsAreEquals();
    itShouldCreateEmptyString();
    itShouldCreateEmptyStringWhenValueIsNull();
    isShouldCheckIfEmptyString();
    isShouldCreateFormattedString();
    itShouldPushInArray();
    itShouldGetNullForIndexOutOfBoundInStringArray();
    itShouldSplitString();

    return EXIT_SUCCESS;
}

void testValue(){
    String str = newString("abcd");
    assert(assertExpectedStringEqualsActual(stringValue(str), "abcd"));
    freeString(str);
}

void testLength(){
    String str = newString("12345");
    assert(assertExpectedIntEqualsActual(stringLength(str), 5));
    freeString(str);
}

void testStringsAreEquals() {
    String str1 = newString("abcd");
    String str2 = newString("abcd");
    assert(stringAreEquals(str1, str2));
    freeString(str1);
    freeString(str2);
}

void itShouldCreateEmptyString() {
    String str = newString("");
    assert(assertExpectedStringEqualsActual(
            "",
            stringValue(str)
    ));
    freeString(str);
}

void itShouldCreateEmptyStringWhenValueIsNull() {
    String str = newString(NULL);
    assert(assertExpectedStringEqualsActual(
            "",
            stringValue(str)
            ));
    freeString(str);
}

void isShouldCheckIfEmptyString() {
    String s = newString("");
    assert(isStringEmpty(s));
    freeString(s);
}

void isShouldCreateFormattedString() {
    string test = "test";
    String formatted = newFormattedString("%d %s %d", 1, test, 2);
    assert(assertExpectedStringEqualsActual(
            "1 test 2",
            stringValue(formatted)
            ));
    freeString(formatted);
}

void itShouldPushInArray() {
    StringArray array = newEmptyStringArray();
    pushStringInArray(newString("I"), array);

    assert(assertExpectedIntEqualsActual(1, getStringArraySize(array)));
    assert(assertExpectedStringEqualsActual("I", stringValue(getStringInArrayAtIndex(array, 0))));

    freeStringArray(array);
}

void itShouldGetNullForIndexOutOfBoundInStringArray() {
    StringArray array = newEmptyStringArray();
    pushStringInArray(newString("I"), array);

    assert(assertIsNull(getStringInArrayAtIndex(array, -1)));
    assert(assertIsNull(getStringInArrayAtIndex(array, 1)));

    freeStringArray(array);
}

void itShouldSplitString() {
    String str = newString("I Want to Break Free");
    StringArray array = split(str, ' ');

    assert(assertExpectedStringEqualsActual("I", stringValue(getStringInArrayAtIndex(array, 0))));
    assert(assertExpectedStringEqualsActual("Want", stringValue(getStringInArrayAtIndex(array, 1))));
    assert(assertExpectedStringEqualsActual("to", stringValue(getStringInArrayAtIndex(array, 2))));
    assert(assertExpectedStringEqualsActual("Break", stringValue(getStringInArrayAtIndex(array, 3))));
    assert(assertExpectedStringEqualsActual("Free", stringValue(getStringInArrayAtIndex(array, 4))));

    freeString(str);
    freeStringArray(array);
}

// TODO test index of getStringInArrayAtIndex => return NULL if index < 0 or index >= array size