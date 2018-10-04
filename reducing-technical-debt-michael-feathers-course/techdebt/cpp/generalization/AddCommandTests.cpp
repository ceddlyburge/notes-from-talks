#include "cuultralight.h"
#include <vector>
#include "AddEmployeeCommand.h"

struct AddEmployeeCommandTests {};

TEST(AddEmployeeCommandTests,AddEmployeeCommand)
{

		const unsigned char knownGood [] = 
							{ (unsigned char)0xde, (unsigned char)0xad, 52, 0x02,
                                    'F', 'r', 'e', 'd', ' ', 'B', 'r', 'o', 'o', 'k', 's', 0x00,
                                    '1', '2', '3', ' ', 'M', 'y', ' ', 'H', 'o', 'u', 's', 'e', 0x00,
                                    'S', 'p', 'r', 'i', 'n', 'g', 'f', 'i', 'e', 'l', 'd', 0x00,
                                    'I', 'L', 0x00,
                                    '7', '2', '0', '0', '0', 0x00,
                                    (unsigned char)0xbe, (unsigned char)0xef };

        AddEmployeeCommand cmd("Fred Brooks", "123 My House", "Springfield", "IL", "72000");
		std::vector<unsigned char> buffer;

		cmd.write(buffer);

        for(int i = 0; i < sizeof(knownGood); i++) {
			ASSERT_EQUAL(knownGood[i], buffer[i]);
        }
}
