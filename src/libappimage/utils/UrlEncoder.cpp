// system
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

// local
#include "UrlEncoder.h"

namespace appimage {
    namespace utils {
        std::string UrlEncoder::encode(const std::string& value) {
            std::ostringstream escaped;
            escaped.fill('0');
            escaped << std::hex;

            for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
                std::string::value_type c = (*i);

                // Keep alphanumeric and other accepted characters intact
                if (isalnum((unsigned char) c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/') {
                    escaped << c;
                    continue;
                }

                // Any other characters are percent-encoded
                escaped << std::uppercase;
                escaped << '%' << std::setw(2) << int((unsigned char) c);
                escaped << std::nouppercase;
            }

            return escaped.str();
        }
    }
}
