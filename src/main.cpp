#include <format>
#include <cstring>
#include <iostream>
#include <filesystem>

#define SUCCESS 0
#define FAILURE -1

#if defined(_WIN32) || defined(_WIN64)
int (*strcmpi_t)(const char *, const char *) = _stricmp;
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
int (*strcmpi_t)(const char *, const char *) = strcasecmp;
#endif

void help();

int main(int argc, char const *argv[])
{
        if (argc < 2)
        {
                help();
                return FAILURE;
        }

        else if (argc > 2)
        {
                if (strcmpi_t(argv[1], "new") == 0)
                {
                        if (strcmpi_t(argv[2], "") != 0)
                        {
                                try
                                {
                                        std::string root = argv[2];

                                        // for build directory
                                        std::string build = std::format("{}/build", root);
                                        std::filesystem::create_directories(build);

                                        // for header file include
                                        std::string include = std::format("{}/include", root);
                                        std::filesystem::create_directories(include);

                                        // for libraries
                                        std::string lib = std::format("{}/lib", root);
                                        std::filesystem::create_directories(lib);

                                        // for source code
                                        std::string src = std::format("{}/src", root);
                                        std::filesystem::create_directories(src);
                                }
                                catch (const std::exception &e)
                                {
                                        std::cerr << e.what() << std::endl;
                                }
                        }
                        else
                        {
                                std::cerr << "Please provide a project name." << std::endl;
                                return FAILURE;
                        }
                }
                // arguments(argv);
                else if (strcmpi_t(argv[1], "install") == 0)
                {
                        if (strcmpi_t(argv[2], "") == 0)
                        {
                                /* read from libraries.toml */
                        }
                }
        }
        return SUCCESS;
}

void help()
{
        std::cout << std::endl
                  << "bus <command>" << std::endl
                  << std::endl
                  << "Usage:" << std::endl
                  << std::endl;
        std::cout << "bus new <foo>\t\t"
                  << "create a new project named <foo>" << std::endl;
        std::cout << "bus install\t\t"
                  << "install all the dependencies in your project" << std::endl;
        std::cout << "bus install <foo>\t"
                  << "add the <foo> dependency to your project" << std::endl;
        std::cout << "bus test\t\t"
                  << "run this project's tests" << std::endl;
        std::cout << "bus run <foo>\t\t"
                  << "run the script named <foo>" << std::endl;
        std::cout << "bus <command> -h\t"
                  << "quick help on <command>" << std::endl;
        std::cout << "bus -l\t\t\t"
                  << "display usage info for all commands" << std::endl;
        std::cout << "bus help <term>\t\t"
                  << "search for help on <term> (in a browser)" << std::endl;
        std::cout << "bus help bus\t\t"
                  << "more involved overview (in a browser)" << std::endl
                  << std::endl;
        return;
}
