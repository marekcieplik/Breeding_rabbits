#include "gmock/gmock.h"
#include <windows.h>
#include <time.h>

int main(int argc, char** argv) {
	srand(time(NULL));
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}

