#include <format>
#include <cstring>
#include <iostream>
#include <filesystem>

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
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		help();
	}
	
	if (argc > 2)
	{
		if (strcmpi(argv[1],"new") == 0)
		{
			if (strcmpi(argv[2], "") != 0)
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
					std::string src =  std::format("{}/src", root);
					std::filesystem::create_directories(src);

				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
		// arguments(argv);
		else if (strcmpi(argv[1], "install") == 0)
		{
			if (strcmpi(argv[2], "") == 0)
			{
				/* read from libraries.toml */
			}
			
		}
		
	}
	return 0;
}
