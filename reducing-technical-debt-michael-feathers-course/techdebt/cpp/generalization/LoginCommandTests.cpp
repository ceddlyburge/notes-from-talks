

#include "cuultralight.h"
#include <vector>
#include "LoginCommand.h"



struct LoginCommandTests {};


TEST(LoginCommandTests,LoginCommand)
{

		const unsigned char knownGood [] = 
							{ (unsigned char)0xde, (unsigned char)0xad, 20, 0x01,
                                    'b', 'a', 'b', 0x00,
                                    'c', 'a', 'r', 'd', 'i', 'n', 'a', 'l', 's', 0x00,
                                    (unsigned char)0xbe, (unsigned char)0xef };

        LoginCommand cmd("bab", "cardinals");
		std::vector<unsigned char> buffer;

		cmd.write(buffer);

        for(int i = 0; i < sizeof(knownGood); i++) {
			ASSERT_EQUAL(knownGood[i], buffer[i]);
        }

}
