// testFileOps.cpp
// Rev. 1 - 15/07/24 Original by D.O.J.J Software Development

//*******************************************************//
// This module is designed to test the writing and reading of binary records
// for ChangeItem objects to the file named "ChangeItems.data".
// The testBinaryFileIO function creates a ChangeItem object, writes it to disk,
// then reads it back from disk, and compares the retrieved object with the expected object.
// The program will notify the user of failed test cases through the assertChangeItem function.
//*******************************************************//

#include <iostream>
#include <cstring>
#include "ChangeItem.h"

using namespace std;
void assertChangeItem(string testName, ChangeItem &expected, ChangeItem &actual);

//*******************************************************//

// Name of test: Testing writing and reading binary records of ChangeItem class
// Type: Functional Test
// Preconditions: No other ChangeItem record exists, no ChangeItems.data exists, must be from a clean start
// Steps: run the program
// Expected results: Program says "Testing writing and reading of ChangeItem class passed."

void testBinaryFileIO()
{
  //// Step 1. Write class to file ////
  // start ChangeItemFile
  ChangeItemFile file = strtItem();

  // Create ChangeItem object
  ChangeItem item("Excel", "V1", "Issue with Spreadsheets", "Assessed", 1);

  // Write to disk
  file.createChangeItem(item);

  // Close file
  file.closeChangeItemFile();
  // file.close();

  /// Step 2. Read class to memory and compare ///
  //  Open ChangeItems.data file
  ChangeItemFile file2 = strtItem();
  //  Go to top of file
  file2.seekToBeginningOfFile();

  // Read created record into object
  ChangeItem item2;
  file2.findChangeItem(item.getChangeID(), item2);

  //  Compare results
  assertChangeItem("Testing writing and reading of ChangeItem class", item, item2);

  //  Close file
  file2.closeChangeItemFile();
}

//*******************************************************//

int main()
{
  testBinaryFileIO();
}

//*******************************************************//

void assertChangeItem(string testName, ChangeItem &expected, ChangeItem &actual)
{
  bool pass = true;

  if (actual.getChangeID() != expected.getChangeID())
  {
    std::cout << testName << " failed. Change ID mismatch. Expected: " << expected.getChangeID() << ", Actual: " << actual.getChangeID() << std::endl;
    pass = false;
  }

  char actualProductName[11];
  char expectedProductName[11];
  actual.getProductName(actualProductName);
  expected.getProductName(expectedProductName);

  if (strcmp(actualProductName, expectedProductName) != 0)
  {
    cout << testName << " failed. Product Name mismatch. Expected: " << expectedProductName << ", Actual: " << actualProductName << std::endl;
    pass = false;
  }

  char actualReleaseID[9];
  char expectedReleaseID[9];
  actual.getReleaseID(actualReleaseID);
  expected.getReleaseID(expectedReleaseID);

  if (strcmp(actualReleaseID, expectedReleaseID) != 0)
  {
    cout << testName << " failed: Release ID mismatch. Expected: " << expectedReleaseID << ", Actual: " << actualReleaseID << std::endl;
    pass = false;
  }

  char actualDescription[31];
  char expectedDescription[31];
  actual.getDescription(actualDescription);
  expected.getDescription(expectedDescription);

  if (strcmp(actualDescription, expectedDescription) != 0)
  {
    cout << testName << " failed: Description mismatch. Expected: " << expectedDescription << ", Actual: " << actualDescription << std::endl;
    pass = false;
  }

  char actualState[11];
  char expectedState[11];
  actual.getStatus(actualState);
  expected.getStatus(expectedState);

  if (strcmp(actualState, expectedState) != 0)
  {
    cout << testName << " failed: Status mismatch. Expected: " << expectedState << ", Actual: " << actualState << std::endl;
    pass = false;
  }

  if (actual.getPriority() != expected.getPriority())
  {
    std::cout << testName << " failed: Priority mismatch. Expected: " << expected.getPriority() << ", Actual: " << actual.getPriority() << std::endl;
    pass = false;
  }

  if (pass)
  {
    cout << testName << " passed." << endl;
  }
}

//*******************************************************//
